package main

import "fmt"

func main() {
	s := fmt.Sprint("Hello")
	s += " 1234"

	fmt.Print(s)
}
