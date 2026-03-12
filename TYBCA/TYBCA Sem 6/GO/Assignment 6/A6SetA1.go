package main

import (
	"fmt"
	"sort"
)

type Student struct {
	Name  string
	Marks int
}

func main() {

	students := []Student{
		{"Tejas", 78},
		{"Rahul", 90},
		{"Amit", 65},
		{"Sneha", 85},
	}

	sort.Slice(students, func(i, j int) bool {
		return students[i].Marks < students[j].Marks
	})

	fmt.Println("Students sorted by marks:")

	for _, s := range students {
		fmt.Println(s.Name, s.Marks)
	}
}
