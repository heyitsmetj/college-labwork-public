package main

import (
	"fmt"
	"os"
)

func main() {

	fileInfo, err := os.Stat("test.txt")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	fmt.Println("File Name:", fileInfo.Name())
	fmt.Println("File Size:", fileInfo.Size(), "bytes")
	fmt.Println("File Permissions:", fileInfo.Mode())
	fmt.Println("Last Modified:", fileInfo.ModTime())
	fmt.Println("Is Directory:", fileInfo.IsDir())
}
