package main

import "fmt"

type kkam int

func main() {
	var x kkam

	fmt.Printf("%v\t%T\n", x, x)

	x = 42

	fmt.Printf("%d", x)
}
