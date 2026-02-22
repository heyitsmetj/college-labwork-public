package main

import (
	"fmt"
)

func calcSquares(num int, ch chan int) {
	sum := 0

	for num != 0 {
		digit := num % 10
		sum += digit * digit
		num = num / 10
	}

	ch <- sum
}

func calcCubes(num int, ch chan int) {
	sum := 0

	for num != 0 {
		digit := num % 10
		sum += digit * digit * digit
		num = num / 10
	}

	ch <- sum
}

func main() {

	number := 123

	squareChan := make(chan int)
	cubeChan := make(chan int)

	go calcSquares(number, squareChan)
	go calcCubes(number, cubeChan)

	squares := <-squareChan
	cubes := <-cubeChan

	fmt.Println("Sum of squares =", squares)
	fmt.Println("Sum of cubes =", cubes)
	fmt.Println("Final sum of squares and cubes =", squares+cubes)
}
