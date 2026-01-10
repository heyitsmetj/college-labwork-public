package main

import "fmt"

func main() {
	var str1, str2 string
	
	fmt.Print("Enter string 1: ")
	fmt.Scan(&str1)
	
	fmt.Print("Enter string 2: ")
	fmt.Scan(&str2)
	
	if str1 == str2 {
		fmt.Println("Strings are Equal!")
	} else {
		fmt.Println("Strings are NOT Equal!")
	}

}

