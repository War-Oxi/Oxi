price_coffee = {"아메리카노": 4100,"카페라떼": 4600,"카라멜 마끼아또": 5100}

order = {}

total_price = 0

Num = 4

Num = int(input())

while Num >= 1:
    order = input()
    if order == "아메리카노":
        total_price += 4100
        Num = Num - 1
    elif order == "카페라떼":
        total_price += 4600
        Num = Num - 1
    elif order == "카라멜마끼아또":
        total_price += 5100
        Num = Num - 1


print(total_price)

