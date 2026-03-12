package main

import "testing"

func TestAdd(t *testing.T) {

	result := Add(10, 5)
	expected := 15

	if result != expected {
		t.Errorf("Expected %d but got %d", expected, result)
	}
}
