package main

import "testing"

func TestSubtract(t *testing.T) {

	tests := []struct {
		a, b     int
		expected int
	}{
		{10, 5, 5},
		{20, 10, 10},
		{7, 3, 4},
		{5, 8, -3},
	}

	for _, test := range tests {
		result := Subtract(test.a, test.b)

		if result != test.expected {
			t.Errorf("Subtract(%d,%d) = %d; expected %d",
				test.a, test.b, result, test.expected)
		}
	}
}
