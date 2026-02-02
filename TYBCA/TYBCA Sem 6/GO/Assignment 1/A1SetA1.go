package main

import "fmt"

func main() {
    var name, division, college string
    var rollno int

    fmt.Print("Enter Student Name: ")
    fmt.Scanln(&name)

    fmt.Print("Enter Roll Number: ")
    fmt.Scanln(&rollno)

    fmt.Print("Enter Division: ")
    fmt.Scanln(&division)

    fmt.Print("Enter College Name: ")
    fmt.Scanln(&college)

    fmt.Println("\n--- Student Details ---")
    fmt.Println("Name      :", name)
    fmt.Println("Roll No   :", rollno)
    fmt.Println("Division  :", division)
    fmt.Println("College   :", college)
}
