package main

import "fmt"

type Printer interface {
	print()
}

type Scanner interface {
	scan()
}

type Machine interface {
	Printer
	Scanner
}

type Device struct{}

func (d Device) print() {
	fmt.Println("Printing Document...")
}

func (d Device) scan() {
	fmt.Println("Scanning Document...")
}

func main() {
	var m Machine

	d := Device{}
	m = d
	m.scan()
	m.print()
}
