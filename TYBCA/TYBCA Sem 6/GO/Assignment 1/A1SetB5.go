package main

import "fmt"

func main() {
	
	p := new(int)

	fmt.Println(*p) 

	*p = 5
	fmt.Println(*p) 
}

