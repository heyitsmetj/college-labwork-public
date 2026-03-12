package main

import (
	"A6SetA2/calculator"
	"fmt"
)

func main() {

	var a, b, choice int

	fmt.Println("Enter two numbers:")
	fmt.Scan(&a, &b)

	fmt.Println("1.Add  2.Subtract  3.Multiply  4.Divide")
	fmt.Print("Enter your choice: ")
	fmt.Scan(&choice)

	switch choice {

	case 1:
		fmt.Println("Result:", calculator.Add(a, b))

	case 2:
		fmt.Println("Result:", calculator.Sub(a, b))

	case 3:
		fmt.Println("Result:", calculator.Mul(a, b))

	case 4:
		fmt.Println("Result:", calculator.Div(a, b))

	default:
		fmt.Println("Invalid Choice")
	}
}
