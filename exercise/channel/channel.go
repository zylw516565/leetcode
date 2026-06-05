package main

import "fmt"

func main() {
	ch := make(chan string, 3)
	fmt.Println(len(ch), cap(ch))
	ch <- "A"
	ch <- "B"
	ch <- "C"
	fmt.Println(len(ch), cap(ch))
	fmt.Println(<-ch)
	fmt.Println(len(ch), cap(ch))
}
