package main
import "fmt"

func sod(n int) int {
	if n == 0 {
		return 0
	}
	return n % 10 + sod(n / 10)
}

func main(){
	var num int 	
	
	fmt.Print("Enter num: ")
	fmt.Scan(&num)
	
	fmt.Println("Sum of digits is", sod(num))
}
