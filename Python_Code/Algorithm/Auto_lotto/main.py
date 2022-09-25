import random
# 2018113009 김태지


def Lotto_Generator(lotto_num):
    for i in range(0, lotto_num):
        list_lotto = list()
        print("자동번호 --> ", end=' ')
        for num in range(0, 6):
            temp_num = random.randrange(1, 46)
            while temp_num in list_lotto:
                temp_num = random.randrange(1, 46)
            list_lotto.append(temp_num)
            print(list_lotto[num], end=' ')
        print()

# a = int()
print("** 로또 번호 생성을 시작합니다 **")
input_lotto_num = int(input("몇 번을 뽑을까요? "))
Lotto_Generator(input_lotto_num)