package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"time"
)

type ReaderWriter_A interface {
	io.Reader
	io.Writer
}

type ReaderWriter_B interface {
	Read(p []byte) (n int, err error)
	Write(p []byte) (n int, err error)
}

type ReaderWriter_C interface {
	Read(p []byte) (n int, err error)
	io.Writer
}

type ByteCounter int

func (c *ByteCounter) Write(p []byte) (int, error) {
	*c += ByteCounter(len(p))
	return len(p), nil
}

func main() {
	var c ByteCounter
	c.Write([]byte("hello"))
	fmt.Println(c)
	c = 0

	var name = "Dolly"
	fmt.Fprintf(&c, "Hello, %s", name)
	fmt.Println(c)

	var w io.Writer
	w = os.Stdout
	w = new(bytes.Buffer)
	// w = time.Second
	w.Write([]byte("hello"))

	var rwc io.ReadWriteCloser
	w = rwc
	// rwc = w

	test_2()
}

func test_2() {
	var w io.Writer
	fmt.Printf("w: %T, %v\n", w, w)
	// w.Write([]byte("hello")) // panic
	w = os.Stdout //具体类型到接口类型的隐式转换, 等价于显示转换 io.Writer(os.Stdout)
	fmt.Printf("w: %T, %v\n", w, w)
	w.Write([]byte("hello\n"))

	var buf bytes.Buffer
	fmt.Print("len:", buf.Len(), " ", buf.String(), "\n")
	w = &buf
	fmt.Printf("w: %T, %v\n", w, w)
	w.Write([]byte("hello\n"))
	fmt.Print("len:", buf.Len(), " ", buf.String(), "\n")
	fmt.Println(w == nil)

	w = nil
	fmt.Printf("w: %T, %v\n", w, w)
	fmt.Println(w == nil)

	var x interface{} = time.Now()
	fmt.Printf("x: %T, %v\n", x, x)

	//如果两个接口值的动态类型相同， 但是这个动态类型是不可比较的（ 比如切片） ， 将它们进行比较就会失败并且panic:
	// var y interface{} = []int{1, 2, 3}
	// fmt.Println(y == y) //panic: runtime error: comparing uncomparable type []int
}

// func main() {
// 	var p *int = nil
// 	var i interface{} = p
// 	fmt.Println(i == nil)
// 	_ = i.(*int)
// 	fmt.Printf("p: %T %v\n", p, p)
// 	fmt.Printf("i: %T %v\n", i, i)

// 	var j interface{}
// 	fmt.Println(j == nil)
// 	fmt.Printf("j: %T %v\n", j, j)

// 	var k interface{} = test
// 	fmt.Printf("k: %T %v\n", k, k)
// }

// func test(n int) {
// 	fmt.Println(n)
// }

// func main() {
// 	defer fmt.Print(1)
// 	defer fmt.Print(2)
// 	defer fmt.Print(3)
// }

// func main() {
// 	for i := 0; i < 20; i++ {
// 		go func() {
// 			fmt.Println(i)
// 		}()
// 	}

// 	time.Sleep(time.Second)
// }

// func main() {
// 	fns := make([]func(), 3)
// 	for i := 0; i < 3; i++ {
// 		fns[i] = func() {
// 			fmt.Println(i)
// 		}
// 	}

// 	for _, fn := range fns {
// 		fn()
// 	}
// }

// func main() {
// 	for i := 0; i < 100; i++ {
// 		var x, y int
// 		go func() {
// 			x = 1                   //A1
// 			fmt.Print("y:", y, " ") //A2
// 		}()

// 		go func() {
// 			y = 1                   //B1
// 			fmt.Print("x:", x, " ") //B2
// 		}()
// 	}

// 	time.Sleep(time.Second)
// }
