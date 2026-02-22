package main

import "fmt"

func main() {

	ch := make(chan int)

	go func() {
		a, b := 0, 1
		for i := 0; i < 10; i++ {
			ch <- a
			a, b = b, a+b
		}
		close(ch)
	}()

	for num := range ch {
		fmt.Println(num)
	}
}
