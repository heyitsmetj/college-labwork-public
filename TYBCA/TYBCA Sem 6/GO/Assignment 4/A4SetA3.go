package main

import "fmt"

type Author struct {
	name string
	age  int
	book string
}

func (a Author) show() {
	fmt.Println("Author Name:", a.name)
	fmt.Println("Author Age:", a.age)
	fmt.Println("Book Name:", a.book)
}

func main() {

	a1 := Author{
		name: "R.K. Narayan",
		age:  50,
		book: "Malgudi Days",
	}

	a1.show()
}
