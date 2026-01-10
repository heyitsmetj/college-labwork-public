package main
import "fmt"

func main() {
    var num int
    
  fmt.Print("Enter number: ")
  fmt.Scan(&num)

  for i:=1; i < 11; i++ {
  	fmt.Println(num, "x", i, "=", (num*i))
  }
}
