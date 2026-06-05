package main

import (
	"context"
	"errors"
	"log"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"
)

// func main() {
// 	http.HandleFunc("/ping", func(rsp http.ResponseWriter, req *http.Request) {
// 		rsp.WriteHeader(http.StatusOK)
// 		rsp.Write([]byte("pong hello world!"))
// 	})

// 	http.ListenAndServe(":8888", nil)
// }

func main() {
	// 1. 创建路由
	mux := http.NewServeMux()
	mux.HandleFunc("/ping", pingHandler)
	mux.HandleFunc("/api/user", userHandler)

	// 2. 包装中间件
	handler := recoverMiddleware(loggingMiddleware(mux))

	// 3. 配置 Server（关键！）
	srv := &http.Server{
		Addr:         ":8888",
		Handler:      handler,
		ReadTimeout:  5 * time.Second,   // 读取请求的超时
		WriteTimeout: 10 * time.Second,  // 写入响应的超时
		IdleTimeout:  120 * time.Second, // Keep-Alive 超时
		// MaxHeaderBytes: 1 << 20,      // 最大请求头 1MB
	}

	// 4. 优雅关闭
	go func() {
		log.Println("Server starting on :8888")
		if err := srv.ListenAndServe(); err != nil && !errors.Is(err, http.ErrServerClosed) {
			log.Fatalf("listen: %s\n", err)
		}
	}()

	// 等待中断信号
	quit := make(chan os.Signal, 1)
	signal.Notify(quit, syscall.SIGINT, syscall.SIGTERM)
	<-quit
	log.Println("Shutting down server...")

	ctx, cancel := context.WithTimeout(context.Background(), 30*time.Second)
	defer cancel()
	if err := srv.Shutdown(ctx); err != nil {
		log.Fatalf("Server forced to shutdown: %v", err)
	}
	log.Println("Server exited")
}

// 业务 Handler
func pingHandler(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	w.Write([]byte("pong"))
}

func userHandler(w http.ResponseWriter, r *http.Request) {
	// 根据 method 处理不同逻辑
	switch r.Method {
	case http.MethodGet:
		// 处理 GET
	case http.MethodPost:
		// 处理 POST
	default:
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

// 中间件：日志
func loggingMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		start := time.Now()
		next.ServeHTTP(w, r)
		log.Printf("%s %s %v", r.Method, r.URL.Path, time.Since(start))
	})
}

// 中间件：recover panic
func recoverMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		defer func() {
			if err := recover(); err != nil {
				log.Printf("panic: %v", err)
				http.Error(w, "Internal Server Error", http.StatusInternalServerError)
			}
		}()
		next.ServeHTTP(w, r)
	})
}
