import math
##Exam1
def Get_Radian(degree):
    return math.radians(degree)

def Get_Degree(radian):
    return math.degrees(radian)

##Exam2
def Get_Sin_Plus_Cos(degree):
    radian = math.radians(degree)
    return math.cos(radian) + math.sin(radian)

##Exam3
def Add_Number():
    import sys
    sum = 0
    # print(sys.argv)
    # print(len(sys.argv))
    for i in range(1, len(sys.argv)):
        sum += int(sys.argv[i])
    return sum
# print(Get_Radian(57.333))
# print(Get_Degree(2))

# print(Get_Sin_Plus_Cos(30))

print(Add_Number())