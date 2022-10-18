#exam1 임의의 파일에 글자를 기록하여 저장하는 프로그램을 작성하라
import random
def Exam1():
    input_str = str()
    input_list = list()
    for i in range(0, 100):
        input_str += (str(random.randrange(1,46))) + " "
        input_list.append(random.randrange(1,46))
    file = open("test.txt", "w", encoding='utf-8')
    print(str(input_list))
    # file.writelines(input_str)
    file.write(input_str)
    # file.writelines(input_list)
    file.close()

def Exam2():
    file = open("test.txt", 'r', encoding='utf-8')
    output_str = file.read().rstrip().split(' ')
    # output_str = file.readlines()
    count = 0
    for i in range(1,46):
        print("{}의 개수 => {}개".format(i, output_str.count(str(i))))
        count += output_str.count(str(i))
    print(count)
    file.close()

Exam1()
Exam2()