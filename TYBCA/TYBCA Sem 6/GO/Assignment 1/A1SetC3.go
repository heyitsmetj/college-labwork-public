package main

import "fmt"

func main() {
	var choice string
	var num1, num2, result int
	var flag bool = true
	
	fmt.Print("Enter first number: ")
	fmt.Scan(&num1)
	fmt.Print("Enter second number: ")
	fmt.Scan(&num2)
	
	fmt.Print("\n--Menu--\n\nAddition(+)\nSubtraction(-)\nMultiplication(*)\nDivision(/)\n\nEnter Choice: ")
	fmt.Scan(&choice)
	
	switch choice {
		case "+":
			result = num1 + num2
			break
		case "-":
			result = num1 - num2
			break
		case "*":
			result = num1 * num2
			break
		case "/":
			if num2 == 0 {
				fmt.Printf("\nError: Division by Zero! %v / %v\n", num1, num2)
				flag = false
				break
			}
			result = num1 - num2
			break
		default: 
			fmt.Println("\nInvalid Choice! Exiting...")
			flag = false
			break
	}
	
	if flag {
		fmt.Println("Result: ", num1, choice, num2, "=", result)
	}
}

