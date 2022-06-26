def FtoC(F):
    temp_c = (5.0 * (F - 32.0)) / 9.0
    return temp_c

F = float(input("화씨온도를 입력하시오: "))

print(FtoC(F))