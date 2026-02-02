package main

import "fmt"

func main() {
    var a, b int

    fmt.Print("Enter first number: ")
    fmt.Scanln(&a)

    fmt.Print("Enter second number: ")
    fmt.Scanln(&b)

    a = a + b
    b = a - b
    a = a - b

    fmt.Println("\nAfter Swapping:")
    fmt.Println("a =", a)
    fmt.Println("b =", b)
}
