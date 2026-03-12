package main

import (
	"encoding/xml"
	"fmt"
	"os"
)

type Student struct {
	Name  string `xml:"Name"`
	Marks int    `xml:"Marks"`
}

func main() {

	xmlFile, err := os.ReadFile("student.xml")
	if err != nil {
		fmt.Println(err)
		return
	}

	var s Student

	err = xml.Unmarshal(xmlFile, &s)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Student Name:", s.Name)
	fmt.Println("Student Marks:", s.Marks)
}
