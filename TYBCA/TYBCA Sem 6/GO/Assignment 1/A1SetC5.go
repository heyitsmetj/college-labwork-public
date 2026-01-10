package main

import (
	"fmt"
	"strings"
)

func main() {

	var str1, str2 string

	fmt.Print("Enter First string: ")
	fmt.Scan(&str1)

	fmt.Print("Enter Second string: ")
	fmt.Scan(&str2)

	if strings.Contains(str1, str2) {
		fmt.Println(str2, "is a Substring of", str1)
	} else {
		fmt.Println(str2, "is Not a Substring of", str1)
	}
}

