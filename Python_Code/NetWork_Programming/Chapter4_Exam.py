##Exam1 두 개의 매개변수 n, m을 전달받아 m x n개의 * 상자를 출력하는 프로그램을 작성.
def Exam1(n, m):
    a = str()
    for i in range(n):
        for j in range(m):
            a += '*'
        a += '\n'
    print(a)

##Exam2 하나의 숫자를 전달받아 숫자의 자리 합을 구하는 함수를 작성. (예:123 -> 1+2+3 = 6)
def Exam2():
    str_num = input("숫자를 입력하세요")
    sum = 0
    for i in range(0, len(str_num)):
        sum += int(str_num[i])
    print(sum)

##Exam3 두 개의 문자열이 서로 다른 처음 위치를 반환하는 함수를 작성. 두 개의 문자열이 같으면 -1을 반환
def Exam3(str1, str2):
    if str1 is str2:
        return -1

    max_str_length = 0
    if len(str1) > len(str2):
        max_str_length = len(str1)
    else:
        max_str_length = len(str2)

    for i in range(0, max_str_length):
        if str1[i] is not str2[i]:
            return i

##Exam4 숫자를 전달받아 그 수의 약수를 반환하는 함수를 작성
def Exam4(num):
    divisor = list()
    for i in range(1, num+1):
        if num % i == 0:
            divisor.append(i)
    print(divisor)

##Exam5 문자열과 하나의 문자를 전달받아 문자열에서 문자의 위치를 모두 찾아 리스트로 반환하는 함수를 작성
def Exam5(input_str, char):
    index_list = list()
    for i in range(0, len(input_str)):
        if input_str[i] is char:
            index_list.append(i)
    print(index_list)

def Exam6(radius):
    import math
    area = 0
    pi = math.pi
    area = (radius**2) * pi
    print(area)

## Exam7 구의 반지름을 주면 구의 부피를 계산하는 함수 sphereVolume()
def Exam7(radius):
    import math
    pi = math.pi
    area = (4 / 3 * pi) * (radius**3)
    print(area)

## Exam8 크지 않은 자연수 n을 매개변수로 받아 n!을 계산해 반환하는 함수
def Exam8(num):
    factorial_result = 1
    for i in range(num, 0, -1):
        factorial_result *= i
    return factorial_result

## Exam9 두 개의 정수가 주어지면 두 수 중에서 더 큰 수를 찾아서 이것을 반환하는 함수
def Exam9(num1, num2):
    if num1 > num2:
        return num1
    else:
        return num2

## Exam10 섭씨온도를 화씨온도로 변환하여 반환하는 함수
def Exam10(celscius):
    result = celscius*(9/5) + 32
    print(result)

# Exam11 3장의 x^n을 계산하는 반복문 예제 프로그램은 n이 양의 정수라는 제약사항이 있다.
# 이것을 확장해 n이 양, 음, 0일 경우에도 동작하는 함수를 만들고 이것을 시험해 보라
def Exam11(x, n):
    result = 1.0
    if n > 0:
        for i in range(n):
            result *= x
    elif n < 0:
        for i in range((abs(n))):
            result *= 1 / x
    print(result)

def Exam12(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    else:
        for i in range(2, int(n/2+1)):
            if n % i == 0:
                return False
    return True

def Exam13(width, height):
    rect_area = width * height
    rect_round = (width + height) * 2
    rect_info = (rect_area, rect_round)
    return rect_info


# print(2**0)
# Exam1(4,5)
# Exam2()
# print(Exam3("I am happy", "I am happy"))
# Exam4(20)
# Exam5('AAAABBBBAAAACCCCAAAAEEEEAAAA', 'A')
# Exam6(2)
# Exam7(2)
# print(Exam8(10))
# print(Exam9(129, 125))
# Exam10(2)
# Exam11(2, -2)
# for i in range(1,501):
#     if Exam12(i):
#         print(i)
# print(Exam13(5, 5))