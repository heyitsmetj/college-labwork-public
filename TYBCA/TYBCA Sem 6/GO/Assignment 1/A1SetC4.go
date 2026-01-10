package main

import "fmt"

func main() {
	var num int

	fmt.Print("Enter Number: ")
	fmt.Scan(&num)

	if num < 10 && num > -10 {
		fmt.Println("Number is a Single Digit Number")
	} else {
		fmt.Println("Number is not a Single Digit Number")
	}
}

