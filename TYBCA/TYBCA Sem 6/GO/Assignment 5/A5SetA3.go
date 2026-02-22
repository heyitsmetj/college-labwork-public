package main

import "fmt"

func evenNum(ch chan int, done chan bool) {
	for n := range ch {
		fmt.Println("Even:", n)
	}
	done <- true
}

func oddNum(ch chan int, done chan bool) {
	for n := range ch {
		fmt.Println("Odd:", n)
	}
	done <- true
}

func main() {

	nums := []int{10, 15, 22, 7, 8, 13, 4, 9}

	evenCh := make(chan int)
	oddCh := make(chan int)
	done := make(chan bool)

	go evenNum(evenCh, done)
	go oddNum(oddCh, done)

	for _, n := range nums {
		if n%2 == 0 {
			evenCh <- n
		} else {
			oddCh <- n
		}
	}

	close(evenCh)
	close(oddCh)

	<-done
	<-done
}
