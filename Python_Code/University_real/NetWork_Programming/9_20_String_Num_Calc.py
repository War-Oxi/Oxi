def String_Num_Calc(str):
    sum = 0
    for i in range(0, len(str)):
        sum += int(str[i])
    return sum
input_str=input()
print(String_Num_Calc(input_str))