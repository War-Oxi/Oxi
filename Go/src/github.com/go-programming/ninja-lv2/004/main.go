package main

import (
	"fmt"
)

func main() {
	var x int = 8
	y := x << 1

	fmt.Printf("%d\t %b\t %#x\n", x, x, x)
	fmt.Printf("%d\t %b\t %#x\n", y, y, y)
}
