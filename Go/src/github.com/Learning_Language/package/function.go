package kkamji

import (
    "fmt"
    "strings"
)

func ChangeValue(message *string) {
    *message = fmt.Sprintf("your name is %s", *message)
}

func AddTen(value int) int {
    return value + 10
}

// ... 은 slice 로 값을 받음
func Sum(values ...int) int {
    result := 0
    for _, value := range values {
        result = result + value
    }

    return result
}

func DivideStrings(value string) (string, string) {
    values := strings.Split(value, "_")
    return values[0], values[1]
}

func Calc(f func(int, int) int, a int, b int) int {
    result := f(a, b)
    return result
}

func Function() {
    // 함수 호출
    fmt.Println(AddTen(100))

    // slice 변수 호출
    fmt.Println(Sum(1, 2, 3, 4, 5))

    // 다중 변수 반환
    prefix, suffix := DivideStrings("Your_Name")
    fmt.Println(prefix, suffix)

    // 포인터 전달
    message := "Ronaldo"
    ChangeValue(&message)
    fmt.Println(message)

    // 익명 함수
    sum := func(x int, y int) int {
        return x + y
    }
    fmt.Println(sum(5, 10))

    // 일급 함수
    add := func(i int, j int) int {
        return i + j
    }

    minus := func(i int, j int) int {
        return i - j
    }

    fmt.Println(Calc(add, 10, 5))
    fmt.Println(Calc(minus, 10, 5))
}

func PassByReference(msg *string) {
    *msg = "Changed World"
}

func FunctionPassByReference(){
    var str string = "Hello World"
    fmt.Println(str)
    PassByReference(&str)
    fmt.Println(str)
}

func VariadicFunction(msg ...string){
    for _, s := range msg {
        fmt.Println(s)
    }
}

func MyVariadic(msg ...string) {
    var mystr string;
    for _, s := range msg {
        mystr += s + " "
    }

    fmt.Println(mystr)
}

func NamedReturnParameter(nums ...int) (int, int) {
    s := 0
    count := 0
    for _, n := range nums {
        s += n
        count++
    }
    return s, count
}

func AnonymousFunction() {
    sum := func(n ...int) int {
        s:=0
        for _, i := range n {
            s += i
        }
        return s
    }

    result := sum(1,2,3,4,5,6,7,8,9,10)
    fmt.Println(result)
}