package main

import "fmt"

func main() {
	var str1, str2 string

	fmt.Print("Enter First String: ")
	fmt.Scan(&str1)

	fmt.Print("Enter Second String: ")
	fmt.Scan(&str2)

	var ptr1 *string = &str1
	var ptr2 *string = &str2

	result := *ptr1 + *ptr2

	fmt.Println("Result:", result)
}

