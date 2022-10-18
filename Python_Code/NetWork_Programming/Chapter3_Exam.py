#exam1 => 임의의 정수가 짝수인지 홀수인지 판별하는 프로그램
def exam1(num):
    if num%2 == 0:
        print("\"{}\"은 짝수입니다.".format(num))
    else:
        print("\"{}\"은 홀수입니다.".format(num))

#exam2 => 이차방정식 ax^2+bx+c=0의 계수 a, b, c를 입력받아 판별식(D=b^2-4ac)을 이용해 근의 종류를 출력하는 프로그램
def exam2(a, b, c):
    if b**2 - 4*a*c > 0:
        print("실근")
    elif b**2 - 4*a*c == 0:
        print("중근")
    else:
        print("허근")

#exam3 => 좆밥 문제(단순 노동)

#exam4 => 사용자로부터 cm 단위의 길이를 입력받음. 입력값이 음수이면 "잘못 입력했습니다", 입력값이 양수이면 cm 단위 길이를 inch로 변환후 출력
def exam4(num_cm):
    if num_cm < 0:
        print("잘못 입력했습니다.")
    else:
        print("{}cm => {}inch".format(num_cm, num_cm*2.54))

# exam1(128)
# exam2(1,3,1)
exam4(10)