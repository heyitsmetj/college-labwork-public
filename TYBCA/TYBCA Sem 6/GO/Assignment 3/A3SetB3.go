package main
import "fmt"

type Students struct {
	roll_no   int
	stud_name string
	mark1     int
	mark2     int
	mark3     int
	total     int
	mrkAvg    float32
}

func main() {
	var n int

	fmt.Print("Enter number of students: ")
	fmt.Scan(&n)

	stud := make([]Students, n)

	for i := 0; i < n; i++ {
		fmt.Printf("\nEnter details of student %d\n", i+1)

		fmt.Print("Roll No: ")
		fmt.Scan(&stud[i].roll_no)

		fmt.Print("Student Name: ")
		fmt.Scan(&stud[i].stud_name)

		fmt.Print("Mark 1: ")
		fmt.Scan(&stud[i].mark1)

		fmt.Print("Mark 2: ")
		fmt.Scan(&stud[i].mark2)

		fmt.Print("Mark 3: ")
		fmt.Scan(&stud[i].mark3)

		stud[i].total = stud[i].mark1 + stud[i].mark2 + stud[i].mark3
		stud[i].mrkAvg = float32(stud[i].total) / 3
	}

	fmt.Println("\nStudent Details")
	for i := 0; i < n; i++ {
		fmt.Println("---------------------------")
		fmt.Printf("Roll No: %d\n", stud[i].roll_no)
		fmt.Printf("Name: %s\n", stud[i].stud_name)
		fmt.Printf("Total Marks: %d\n", stud[i].total)
		fmt.Printf("Average Marks: %.2f\n", stud[i].mrkAvg)
	}
}

