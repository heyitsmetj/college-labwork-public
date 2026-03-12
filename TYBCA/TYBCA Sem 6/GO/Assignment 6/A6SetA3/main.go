package main

import (
	"A6SetA3/rectangle"
	"fmt"
)

func main() {

	var length, width float64

	fmt.Println("Enter length and width:")
	fmt.Scan(&length, &width)

	area := rectangle.Area(length, width)

	fmt.Println("Area of Rectangle:", area)
}
