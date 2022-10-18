def exam1(mile, gallon): #자동차의 연료 효율을 미국식에서 한국식으로 바꾸는 프로그램 (1mile = 1.6km, 1gallon = 3.7854L)
    km = mile * 1.6
    liter = gallon * 3.7854
    print("mile/gallon => {}".format(mile/gallon))
    print("km/l => {}".format(round(km/liter,2)))

def exam2(second): #주어진 임의의 초를 분으로
    print("{}초는 {}분".format(second, second//60))

def exam3(minute): #주어진 임이의 분을 일, 시간, 분으로 출력해라
    print("{}분은 {}일 {}시간 {}분 입니다.".format(minute, minute//(60*24), minute % (60*24)//60, minute % 60))

def exam4():
    input_money = 500
    print(input_money + input_money*0.05)

def exam5():
    # exam = int(input("exam => "))
    # report = int(input("report => "))
    exam, report = map(int, input().split(" "))

    if exam >= 90 or report >= 90:
        print("A학점")

def exam6():
    print(100*(100+1)/2)

def exam7():
    grapes = 75
    strawberry = 113.5
    num_of_grapes = int(input("num of grapes => "))
    num_of_strawberry = int(input("num of strawberry => "))
    print(grapes * num_of_grapes + strawberry * num_of_strawberry)

# exam1(15,0.5)
# exam2(180)
# exam3(1550)
# exam4()
# exam5()
# exam6()
exam7()