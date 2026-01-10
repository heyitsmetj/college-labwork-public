package main
import "fmt"

func add(a, b int) int {
	return a+b
}

func main(){
	var a, b int 	
	
	fmt.Print("Enter a: ")
	fmt.Scan(&a)

	fmt.Print("Enter b: ")
	fmt.Scan(&b)
	
	fmt.Println(a, "+", b, "=", add(a, b))
}
