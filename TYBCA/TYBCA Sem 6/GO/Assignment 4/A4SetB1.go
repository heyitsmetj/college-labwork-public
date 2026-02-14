package main

import "fmt"

type Student struct {
	name  string
	roll  int
	marks int
}

func (s *Student) show() {
	fmt.Println("Student Name:", s.name)
	fmt.Println("Roll Number:", s.roll)
	fmt.Println("Marks:", s.marks)
}

func main() {

	s1 := Student{
		name:  "Rahul",
		roll:  101,
		marks: 85,
	}

	s1.show()
}
