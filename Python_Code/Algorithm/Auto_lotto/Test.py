import random

num = 0

print("**로또 번호 생성을 시작합니다**")

num = input("몇번을 뽑을까요? : ")
print("            ")  # 줄공백처리
print("결과 : ")
print("            ")  # 줄공백처리
for i in range(0, int(num)):  # 뽑은 횟수
    lotto = list()
    for j in range(0,6):
        lotto.append(random.randint(1,46))
        lotto.sort()                      #오름차순 정렬
    print('자동번호 --> ', lotto)