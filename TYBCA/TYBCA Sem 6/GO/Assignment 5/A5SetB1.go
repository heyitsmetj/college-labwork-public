package main

import "fmt"

func main() {

	ch := make(chan int, 5)

	ch <- 10
	ch <- 20
	ch <- 30

	fmt.Println("Capacity of channel =", cap(ch))
	fmt.Println("Length of channel =", len(ch))

	fmt.Println("Reading:", <-ch)
	fmt.Println("Reading:", <-ch)

	fmt.Println("Modified length of channel =", len(ch))
}
