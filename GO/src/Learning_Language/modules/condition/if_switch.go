package kkam

import (
	"fmt"
	"os"
	"math/rand"
	"time"
)

func If_switch() {
	rand.Seed(time.Now().Unix())
	i:=rand.Intn(15)

	fmt.Println(i)

	if i < 10 {
		fmt.Println("A")
	} else if i == 10 {
		fmt.Println("B")
	} else {
		fmt.Println("C")
	}

	str := "Hello World"
	if err := os.WriteFile("hello.txt", []byte(str), 0644); err != nil {
		fmt.Println(err)
	}
}

