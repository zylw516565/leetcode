package main

import "fmt"

// var ch1 = make(chan struct{})
// var ch2 = make(chan struct{})
// var ch3 = make(chan struct{})
// var count int = 0

// var done = make(chan struct{})

// func main() {

// 	go func1()
// 	go func2()
// 	go func3()
// 	ch1 <- struct{}{}

// 	<-done
// }

// func func1() {
// 	for {
// 		<-ch1
// 		fmt.Println("A")
// 		ch2 <- struct{}{}
// 	}
// }

// func func2() {
// 	for {
// 		<-ch2
// 		fmt.Println("B")
// 		ch3 <- struct{}{}
// 	}
// }

// func func3() {
// 	for {
// 		<-ch3
// 		fmt.Println("C")
// 		count++
// 		if count == 50 {
// 			done <- struct{}{}
// 			break
// 		}

// 		ch1 <- struct{}{}
// 	}
// }

//*************方案1-推荐写法***************
// func main() {
// 	var chA = make(chan struct{})
// 	var chB = make(chan struct{})
// 	var chC = make(chan struct{})

// 	var wg sync.WaitGroup
// 	wg.Add(3)
// 	go func() {
// 		defer wg.Done()
// 		for i := 0; i < 50; i++ {
// 			<-chA
// 			fmt.Println("A")
// 			chB <- struct{}{}
// 		}
// 	}()

// 	go func() {
// 		defer wg.Done()
// 		for i := 0; i < 50; i++ {
// 			<-chB
// 			fmt.Println("B")
// 			chC <- struct{}{}
// 		}
// 	}()

// 	go func() {
// 		wg.Done()
// 		for i := 0; i < 50; i++ {
// 			<-chC
// 			fmt.Println("C")
// 			if i < 49 {
// 				chA <- struct{}{}
// 			}
// 		}
// 	}()

// 	chA <- struct{}{}

// 	wg.Wait()
// }

//************方案2, 会死锁****************
// func main() {
// 	var ch = make(chan int)
// 	var wg sync.WaitGroup
// 	wg.Add(3)

// 	go func() {
// 		defer wg.Done()

// 		for {
// 			val := <-ch
// 			if val != 'A' {
// 				ch <- val
// 				continue
// 			}
// 			fmt.Println("A")
// 			ch <- 'B'
// 		}
// 	}()

// 	go func() {
// 		defer wg.Done()

// 		for {
// 			val := <-ch
// 			if val != 'B' {
// 				ch <- val
// 				continue
// 			}
// 			fmt.Println("B")
// 			ch <- 'C'
// 		}
// 	}()

// 	go func() {
// 		defer wg.Done()
// 		count := 0

// 		for {
// 			val := <-ch
// 			if val != 'C' {
// 				ch <- val
// 				continue
// 			}
// 			fmt.Println("C")
// 			count++
// 			if count == 50 {
// 				return
// 			}
// 			ch <- 'A'
// 		}
// 	}()

// 	ch <- 'A'
// 	wg.Wait()
// }

//************复制AI的方案2, 会死锁****************
// import (
// 	"fmt"
// 	"sync"
// )

// func main() {
// 	ch := make(chan rune)
// 	var wg sync.WaitGroup
// 	wg.Add(3)

// 	// 协程A
// 	go func() {
// 		defer wg.Done()
// 		count := 0
// 		for {
// 			c := <-ch
// 			if c != 'A' {
// 				ch <- c // 不是自己的，放回去让其他人处理
// 				continue
// 			}
// 			fmt.Print("A")
// 			count++
// 			if count == 50 {
// 				return
// 			}
// 			ch <- 'B'
// 		}
// 	}()

// 	// 协程B
// 	go func() {
// 		defer wg.Done()
// 		count := 0
// 		for {
// 			c := <-ch
// 			if c != 'B' {
// 				ch <- c
// 				continue
// 			}
// 			fmt.Print("B")
// 			count++
// 			if count == 50 {
// 				return
// 			}
// 			ch <- 'C'
// 		}
// 	}()

// 	// 协程C
// 	go func() {
// 		defer wg.Done()
// 		count := 0
// 		for {
// 			c := <-ch
// 			if c != 'C' {
// 				ch <- c
// 				continue
// 			}
// 			fmt.Print("C")
// 			count++
// 			if count == 50 {
// 				return
// 			}
// 			ch <- 'A'
// 		}
// 	}()

// 	ch <- 'A'
// 	wg.Wait()
// }

//************复制AI的方案3-功能正确-不过代码逻辑复杂****************

// import (
// 	"fmt"
// 	"sync"
// )

// func main() {
// 	var mu sync.Mutex
// 	cond := sync.NewCond(&mu)
// 	turn := 0 // 0:A, 1:B, 2:C
// 	count := 0

// 	var wg sync.WaitGroup
// 	wg.Add(3)

// 	// 协程A
// 	go func() {
// 		defer wg.Done()
// 		for {
// 			mu.Lock()
// 			for turn != 0 && count < 150 {
// 				cond.Wait()
// 			}
// 			if count >= 150 {
// 				mu.Unlock()
// 				return
// 			}
// 			fmt.Print("A")
// 			turn = 1
// 			count++
// 			cond.Broadcast()
// 			mu.Unlock()
// 		}
// 	}()

// 	// 协程B
// 	go func() {
// 		defer wg.Done()
// 		for {
// 			mu.Lock()
// 			for turn != 1 && count < 150 {
// 				cond.Wait()
// 			}
// 			if count >= 150 {
// 				mu.Unlock()
// 				return
// 			}
// 			fmt.Print("B")
// 			turn = 2
// 			count++
// 			cond.Broadcast()
// 			mu.Unlock()
// 		}
// 	}()

// 	// 协程C
// 	go func() {
// 		defer wg.Done()
// 		for {
// 			mu.Lock()
// 			for turn != 2 && count < 150 {
// 				cond.Wait()
// 			}
// 			if count >= 150 {
// 				mu.Unlock()
// 				return
// 			}
// 			fmt.Print("C")
// 			turn = 0
// 			count++
// 			cond.Broadcast()
// 			mu.Unlock()
// 		}
// 	}()

// 	cond.Signal()
// 	wg.Wait()
// }

// ***********************************
// func main() {
// 	naturals := make(chan int)
// 	squares := make(chan int)

// 	//Counter
// 	go func() {
// 		for x := 0; x <= 50; x++ {
// 			naturals <- x
// 		}

// 		close(naturals)
// 	}()

// 	//Square
// 	go func() {
// 		for {
// 			x, ok := <-naturals
// 			if !ok {
// 				break
// 			}
// 			squares <- x * x
// 		}

// 		close(squares)
// 	}()

// 	for {
// 		x, ok := <-squares
// 		if !ok {
// 			break
// 		}
// 		fmt.Println(x)
// 	}
// }

// func main() {
// 	naturals := make(chan int)
// 	squares := make(chan int)

// 	// // close(naturals)
// 	// // close(naturals)

// 	// var test_chan chan int
// 	// close(test_chan)

// 	//Counter
// 	go func() {
// 		defer close(naturals)
// 		for x := 0; x <= 50; x++ {
// 			naturals <- x
// 		}

// 	}()

// 	//Square
// 	go func() {
// 		defer close(squares)

// 		for x := range naturals {
// 			squares <- x * x
// 		}
// 	}()

// 	for x := range squares {
// 		fmt.Println(x)
// 	}
// }

func main() {
	naturals := make(chan int)
	squares := make(chan int)

	//Counter
	// go counter(chan<- int(naturals))  //小测试, chan int显示转换到 chan<- int
	go counter(naturals) //隐式转换
	//Square
	go squarer(squares, naturals)
	printer(squares)
}

func counter(out chan<- int) {
	defer close(out)
	for x := 0; x <= 50; x++ {
		out <- x
	}
}

func squarer(out chan<- int, in <-chan int) {
	defer close(out)

	for x := range in {
		out <- x * x
	}
}

func printer(in <-chan int) {
	for x := range in {
		fmt.Println(x)
	}

	// close(in) //对一个只接收的channel调用close将是一个编译错误
}

// ***********************************
