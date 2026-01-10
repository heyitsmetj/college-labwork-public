package main
import "fmt"

func numpal(n int) {

	var rev int = 0
	var rem int
	var temp int= n
	
	for i:= 0; temp != 0;  i++ {
		rem = temp % 10
		rev = (rev * 10) + rem
		temp = temp / 10
	}
	
	if rev == n {
		fmt.Printf("%v is a Palindrome.", n)
	} else {
		fmt.Printf("%v is NOT a Palindrome.", n)
	}
}

func main(){
	var num int 	
	
	fmt.Print("Enter num: ")
	fmt.Scan(&num)
	
	numpal(num)
}
