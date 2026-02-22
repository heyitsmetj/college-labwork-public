package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func generate(id int, wg *sync.WaitGroup) {
	defer wg.Done()

	for i := 0; i <= 10; i++ {
		fmt.Printf("Goroutine %d : %d\n", id, i)
		delay := rand.Intn(251)
		time.Sleep(time.Duration(delay) * time.Millisecond)
	}
}

func main() {
	rand.Seed(time.Now().UnixNano())

	var wg sync.WaitGroup

	for i := 1; i <= 5; i++ {
		wg.Add(1)
		go generate(i, &wg)
	}

	wg.Wait()
	fmt.Println("All goroutines completed")
}
