package kkamji

import "fmt"

func LoopBasic() {
	sum := 0
	for i := 1; i <= 100; i++ {
		sum += i
	}
	fmt.Println(sum)
}

func LoopCondition() {
	n := 1
	for n < 100 {
		n *= 2
	}
	fmt.Println(n)
}

func LoopInfinite() {
	kkamNum := 1
	for {
		fmt.Println("Infinite loop")
		kkamNum*=2
		if kkamNum >= 128 {
			fmt.Println(kkamNum);
			break
		}
	}
}

func LoopForRange() {
	names := []string{"홍길동", "이순신", "강감찬"}

	for index, name := range names {
		fmt.Println(index, name)
	}
}