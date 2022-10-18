def Exam1(): #10mile ~ 200mile까지 10mile 간격으로 해당하는 mile이 몇 km인지 출력 (1mile => 1.6km)
    for i in range(10, 201, 10):
        print("{}mile => {}km".format(i, i*1.6))

def Exam2(num_n):
    result = 1
    for i in range(1, num_n+1):
        result *= i
    print("{}!의 결과 => {}".format(num_n ,result))

def Exam3(num_n): #임의의 자연수 n이 입력되면 2부터 n까지의 모든 소수를 출력하는 프로그램
    for i in range(2, num_n+1):
        flag = True
        for j in range(2, int(i/2+1)):
            if i == 2:
                continue
            if i % j == 0:
                flag = False
                break
        if flag:
            print("{}는 소수입니다.".format(i))
## 미완
def Exam4(money_n): #임의의 금액 n이 입력되면 그 금액을 만족하는 모든 경우를 출력하는 프로그램(중첩 반복문 사용), 지폐는 50000,10000,5000,1000원 권만 있음
    num_50000 = 0
    num_10000 = 0
    num_5000 = 0
    num_1000 = 0
    tmp_money = money_n
    while num_50000 * 50000 < tmp_money:
        tmp_money -= 50000 * num_50000
        while num_10000 * 10000 < tmp_money:
            tmp_money -= 10000 * num_10000
            while num_5000 * 5000 < tmp_money:
                tmp_money -= 5000 * num_5000
                num_1000 = tmp_money // 1000
                print(num_50000)
                print(num_10000)
                print(num_5000)
                print(num_1000)
                if 50000 * (num_50000 + 1) < tmp_money:
                    num_50000 += 1
                elif 10000 * (num_10000 + 1) < tmp_money:
                    num_10000 += 1
                elif 5000 * (num_5000 + 1) < tmp_money:
                    num_5000 += 1


                # print("50000원 짜리 =>{}개".format(list_money[0]))
                # print("10000원 짜리 =>{}개".format(list_money[1]))
                # print("5000원 짜리 =>{}개".format(list_money[2]))
                # print("1000원 짜리 =>{}개".format(list_money[3]))
                print("==============================")

# Exam1()
# Exam2(10)
# Exam3(100)
Exam4(50000)