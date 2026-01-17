package main

import "fmt"

func main() {

	nums := []int{10, 20, 30, 40}
	fmt.Println("Original Slice:", nums)

	nums = append(nums, 50)
	fmt.Println("After append:", nums)

	nums = append(nums, 60, 70)
	fmt.Println("After appending multiple elements:", nums)

	index := 2
	nums = append(nums[:index], nums[index+1:]...)
	fmt.Println("After removing element at index 2:", nums)

	newSlice := make([]int, len(nums))

	copy(newSlice, nums)
	fmt.Println("Copied Slice:", newSlice)
}

