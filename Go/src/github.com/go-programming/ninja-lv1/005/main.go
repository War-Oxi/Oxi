package main

import "fmt"

type kkam int

var x int

func main() {
	var y kkam = 123
	x = int(y)

	fmt.Printf("%v\t%v\t%T\t%T\t", y, x, y, x)

}
