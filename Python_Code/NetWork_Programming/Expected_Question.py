'''
        Chapter2 Start
'''

def Ce2Fa(): ##섭씨-화씨온도 변환
    C = float(input("섭씨 온도 입력. "))
    F = C*9/5 + 32
    print("섭씨 온도: {} => 화씨 온도 {}".format(C, F))

def leapYearCheck(): ##입력된 값이 윤년인지 아닌지 확인하는 프로그램
    year = int(input("Type a year :"))
    if (year%4 == 0 and year%100 !=0) or year%400 == 0:
        print(year, "is leap year")
    else:
        print(year, "is not a leap year")
    '''
    윤년의 조건
    1. 년도 수가 4로 나뉘어지면서 100으로 나누어지지 않아야 하고(and연산), 400으로 나누어 떨어지면 윤년이다.(or연산)
    '''

'''
        Chapter3 Start
'''
def quadraticEquation(): #이차방정식 ax^2+bx+c=0의 계수를 a, b, c로 입력받고 판별식(D=b^2-4ac)을 이용해 근의 종류를 출력하는 프로그램
    a, b, c = map(int, input().split(', '))
    D = (b**2) - 4*a*c
    if D > 0:
        print("서로 다른 두 실근을 갖습니다")
    elif D == 0:
        print("서로 같은 두 실근을 갖습니다(=중근)")
    else:
        print("서로 다른 두 허근을 갖습니다")

def factorial(): #임의의 크지 않은 자연수 n을 입력받아 n!(factorial)을 계산해 출력하는 프로그램을 반복문을 이용해 작성
    input_num = int(input("임의의 크지 않은 자연수 n을 입력하세요 : "))
    factorial_result_value = 1
    for i in range(input_num, 0, -1):
        factorial_result_value *= i
    print("{}factorial의 결과값은 => {} 입니다".format(input_num, factorial_result_value))

def swapCase1(): #산술연산자를 사용해 임의의 소문자는 대문자로, 대문자는 소문자로 변환해 출력하는 프로그램
    input_char = input("임의의 문자를 입력하세요 => ")
    if ord('a') <= ord(input_char) and ord(input_char) <= ord('z'):
        print(chr(ord(input_char) - 32))
    elif ord('A') <= ord(input_char) and ord(input_char) <= ord('Z'):
        print(chr(ord(input_char) + 32))
    else:
        print("error")

def swapCase2(): #비트연산자를 사용해 임의의 소문자는 대문자로, 대문자는 소문자로 변환해 출력하는 프로그램
    input_char = input("임의의 문자를 입력하세요 => ")
    print(chr(ord(input_char) ^ 32))

def leapYearPrint(start_year=2000, end_year=2500): #윤년계산 방법을 이용해 2000년부터 2500년까지 윤년인 해를 출력하는 프로그램
    for cur_year in range(start_year, end_year+1):
        if (cur_year % 4 == 0 and cur_year % 100 != 0) or cur_year % 400 == 0:
            print(cur_year)
        # else:
        #     print(cur_year, "is not a leap year")

def getGreatestCommonDivisor(num1, num2): #두 수의 최대 공약수를 구하는 프로그램
    big_num = num1
    small_num = num2
    while True:
        if (big_num < small_num):
            tmp_num = big_num
            big_num = small_num
            small_num = tmp_num
        remainder = big_num % small_num
        big_num = small_num
        small_num = remainder
        if small_num == 0:
            print(big_num)
            break
'''
        Chapter4 Start
'''
def p62_exam3(): #크기가 같은 두 개의 리스트 L, M을 생성하고 두 리스트의 각 요소 합으로 구성되는 새로운 리스트를 생성하라.
    L = [1,2,3]
    M = [4,5,6]
    NewList = list()
    for i in range(0, len(L)):
        NewList.append(L[i] + M[i])
    print(NewList)

'''
        Chapter5 Start
'''
def findDivisor(): #숫자를 전달받아 그 수의 약수를 반환하는 함수 작성
    input_num = int(input("숫자를 입력하세요 => "))
    print(input_num, "의 약수 => ", end="")
    for i in range(1, input_num+1):
        if input_num % i == 0:
            print(i, end=' ')

def findIndex(): #문자열과 하나의 문자를 전달받아 문자열에서 문자의 위치를 모두 찾아 리스트로 반환하는 함수를 작성
    str_input = input("문자열을 입력하세요: ")
    char_input = input("문자열에서 위치를 찾을 문자를 입력하세요: ")
    index_list = list()
    index = 0
    print("{}에서 문자 {}가 위치한 인덱스 => ".format(str_input, char_input),end="")
    for i in str_input:
        if i == char_input:
            index_list.append(index)
        index += 1
    print(index_list)

'''
        Chapter6 Pass
'''
'''
        Chapter7 Start
'''
def radianToDegree(): #라디안을 각도로 변환
    import math
    radian = int(input("각도로 변환할 라디안을 입력하세요 => "))
    degree = math.degrees(radian)
    print("{}라디안은 {}도 입니다.".format(radian, degree))

def radianToDegree(): #각도를 라디안으로 변환
    import math
    degree = int(input("라디안으로 변환할 각도를 입력하세요 => "))
    radian = math.radians(degree)
    print("{}도는 {}라디안 입니다.".format(degree, radian))

def trigonometricFunctionsCalculator(): #math 모듈의 함수를 이용하여 sin(30도) + cos(30도)의 값을 계산하라
    import math
    sin_radian = math.radians(30)
    cos_radian = math.radians(30)
    calc_result = math.sin(sin_radian) + math.cos(cos_radian)
    print("sin(30도) + cos(30도) = {}입니다.".format(calc_result))

'''
        Chapter8 Start
'''
def Exam1(): #임의의 파일에 글자를 기록하여 저장하는 프로그램을 작성하라
    with open("test.txt", 'w', encoding='utf-8') as file:
        input_string = input("파일에 기록할 문자열을 입력하세요 : ")
        file.write(input_string)

def Exam2(): #임의의 주어진 텍스트 파일의 내용을 화면에 출력하는 프로그램을 작성하라
    with open("test.txt", 'r', encoding='utf-8') as file:
        output_string = file.read()
        print(output_string)

