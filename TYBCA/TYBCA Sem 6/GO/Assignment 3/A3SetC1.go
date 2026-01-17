package main

import "fmt"

func main() {
	var r1, c1, r2, c2 int

	fmt.Print("Enter rows and columns of first matrix: ")
	fmt.Scan(&r1, &c1)

	fmt.Print("Enter rows and columns of second matrix: ")
	fmt.Scan(&r2, &c2)

	if c1 != r2 {
		fmt.Println("Matrix multiplication not possible!")
		return
	}

	var a [10][10]int
	var b [10][10]int
	var mul [10][10]int

	fmt.Println("Enter elements of first matrix:")
	for i := 0; i < r1; i++ {
		for j := 0; j < c1; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	fmt.Println("Enter elements of second matrix:")
	for i := 0; i < r2; i++ {
		for j := 0; j < c2; j++ {
			fmt.Scan(&b[i][j])
		}
	}

	for i := 0; i < r1; i++ {
		for j := 0; j < c2; j++ {
			mul[i][j] = 0
			for k := 0; k < c1; k++ {
				mul[i][j] += a[i][k] * b[k][j]
			}
		}
	}

	fmt.Println("Resultant Matrix:")
	for i := 0; i < r1; i++ {
		for j := 0; j < c2; j++ {
			fmt.Print(mul[i][j], "\t")
		}
		fmt.Println()
	}
}

