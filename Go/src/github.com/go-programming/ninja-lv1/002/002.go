package main

import (
	"fmt"
)

var x int
var y string
var z bool

func main() {
	fmt.Printf("%v, %v, %v\n", x, y, z)
	fmt.Printf("%T, %T, %T", x, y, z)
}
