package kkamji

import (
	"fmt"
	"os"
	"math/rand"
	"time"
)

func PrintCondition() {
	rand.Seed(time.Now().Unix())
	i:=rand.Intn(15)

	fmt.Println(i)

	var str string
	if i < 10 {
		str = "A"
		fmt.Println(str)
	} else if i == 10 {
		str = "B"
		fmt.Println(str)
	} else {
		str := "C"
		fmt.Println(str)
	}

	// str := "Hello World"
	if err := os.WriteFile("hello.txt", []byte(str + " Hello World"), 0644); err != nil {
		fmt.Println(err)
	}
}

