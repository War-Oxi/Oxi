package main

import "fmt"

const (
	a = iota + 2
	b
	c
)

func main() {
	fmt.Printf("%T\t%v\n", a, a)
	fmt.Printf("%T\t%v\n", b, b)
	fmt.Printf("%T\t%v\n", c, c)
}
