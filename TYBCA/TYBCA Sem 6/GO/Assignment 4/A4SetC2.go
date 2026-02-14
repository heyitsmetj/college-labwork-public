package main

import "fmt"

type Student struct {
	rollno     int
	name       string
	percentage float64
}

func displayDesc(s []Student, n int) {

	var temp Student

	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if s[j].percentage < s[j+1].percentage {
				temp = s[j]
				s[j] = s[j+1]
				s[j+1] = temp
			}
		}
	}

	fmt.Println("\nStudents in Descending Order of Percentage:")
	for i := 0; i < n; i++ {
		fmt.Println(s[i].rollno, s[i].name, s[i].percentage)
	}
}

func main() {

	var n int
	fmt.Print("Enter number of students: ")
	fmt.Scan(&n)

	students := make([]Student, n)

	for i := 0; i < n; i++ {
		fmt.Print("Enter Rollno: ")
		fmt.Scan(&students[i].rollno)
		fmt.Print("Enter Name: ")
		fmt.Scan(&students[i].name)
		fmt.Print("Enter Percentage: ")
		fmt.Scan(&students[i].percentage)
	}

	displayDesc(students, n)

}
