package kkamji

import (
	"fmt"
)

func Pointer() {
	var a int = 10
	var p = &a

	fmt.Println(*p)
}

