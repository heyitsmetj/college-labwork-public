package main
import "fmt"

func main(){
	arr := [10]int{10, 50, 40, 20, 60, 30, 100, 80, 70, 90}
	
	max := arr[0]
	min := arr[0]
	
	for i := 0; i < 10; i++ {
		if max < arr[i] {
			max = arr[i]
		}
		
		if min > arr[i] {
			min = arr[i]
		}
	}
	
	fmt.Println("Array:", arr)
	fmt.Println("Minimum:", min)
	fmt.Println("Maximum:", max)
}
