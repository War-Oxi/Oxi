##1~45까지의 숫자를 6개 가진 로또 번호 6개 만들기
import random
def Lotto():
    a = []
    while(True):
        temp_num = random.randrange(1, 46)
        if temp_num not in a:
            a.append(temp_num)
        if len(a) == 6:
            break
    print("로또 번호 => {}".format(a))

for num in range(0,6):
    Lotto()

