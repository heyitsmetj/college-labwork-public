package main

import (
	"fmt"
	"sync"
	"time"
)

func worker(id int, wg *sync.WaitGroup) {
	defer wg.Done()

	fmt.Printf("Worker %d: Assembling part...\n", id)

	time.Sleep(time.Duration(id) * time.Second)

	fmt.Printf("Worker %d: Finished work and waiting at checkpoint.\n", id)
}

func main() {
	var wg sync.WaitGroup
	numWorkers := 4

	fmt.Println("Workshop started...\n")

	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go worker(i, &wg)
	}

	wg.Wait()

	fmt.Println("\nAll workers reached the checkpoint.")
	fmt.Println("Putting all parts together...")

	time.Sleep(2 * time.Second)

	fmt.Println("Assembly complete. Workers can start next task.")
}
