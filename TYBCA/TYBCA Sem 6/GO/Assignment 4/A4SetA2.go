package main

import "fmt"

type Multiply struct {
	a int
	b int
}

func (m Multiply) Product() int {
	return m.a * m.b
}

func main() {

	m := Multiply{a: 5, b: 4}

	result := m.Product()

	fmt.Println("Multiplication is:", result)
}
