package main

import "fmt"

type ArrayCopy struct {
	source [5]int
	dest   [5]int
}

func (a *ArrayCopy) copyArray() {
	for i := 0; i < len(a.source); i++ {
		a.dest[i] = a.source[i]
	}
}

func main() {

	a := ArrayCopy{
		source: [5]int{10, 20, 30, 40, 50},
	}

	a.copyArray()

	fmt.Println("Source Array:", a.source)
	fmt.Println("Destination Array:", a.dest)
}
