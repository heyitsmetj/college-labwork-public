package main

import "fmt"

func main() {
	var x int = 10
	var p *int = &x
	var pp **int = &p
	
	fmt.Printf("x: %v\nPointer(p) to x: %v\nPointer to pointer(pp) of x: %v", x, p, pp)
	
}

