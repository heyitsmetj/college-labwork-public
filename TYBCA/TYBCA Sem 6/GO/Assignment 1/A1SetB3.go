package main

import "fmt"

func main() {
	a, b, c := 0, 1, 0
	var n int

	fmt.Print("Enter n: ")
	fmt.Scan(&n)

	fmt.Print(a, " ", b)

	for i := 0; i < n; i++ {
		c = a + b
		a = b
		b = c
		fmt.Print(" ", c)
	}
}

