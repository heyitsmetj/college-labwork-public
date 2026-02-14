package main

import "fmt"

func main() {

	var i interface{}
	i = 100

	value, ok := i.(int)

	if ok {
		fmt.Println("Value:", value)
		fmt.Println("Type is int")
	} else {
		fmt.Println("Type Assertion Failed!")
	}
}
