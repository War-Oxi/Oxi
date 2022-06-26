sum = 0
number = 100

while number <= 200 :
    if number %2 == 0 :
        sum = sum + number
    number = number + 1
print("100부터 200 사이의 모든 2의 배수의 합은 %d입니다." % sum)