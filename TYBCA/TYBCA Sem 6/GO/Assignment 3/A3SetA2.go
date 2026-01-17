package main
import "fmt"

type Books struct{
	title string
	author string
	subject string
	book_id int
}


func main(){
	var Book1 Books
	var Book2 Books
	
	Book1.title = "GO Programming"
	Book1.author = "ABC"
	Book1.subject = "GO Programming Tutorial"
	Book1.book_id = 101
	
	Book2.title = "JAVA Programming"
	Book2.author = "DEF"
	Book2.subject = "JAVA Programming Tutorial"
	Book2.book_id = 102

	fmt.Printf("Book 1 Title: %s\n", Book1.title)
	fmt.Printf("Book 1 Author: %s\n", Book1.author)
	fmt.Printf("Book 1 Subject: %s\n", Book1.subject)
	fmt.Printf("Book 1 Id: %d\n", Book1.book_id)

	fmt.Printf("\nBook 2 Title: %s\n", Book2.title)
	fmt.Printf("Book 2 Author: %s\n", Book2.author)
	fmt.Printf("Book 2 Subject: %s\n", Book2.subject)
	fmt.Printf("Book 2 Id: %d\n", Book2.book_id)
}
