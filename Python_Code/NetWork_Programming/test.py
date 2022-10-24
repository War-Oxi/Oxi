class Square:
    square_num = 0
    def __init__(self, width, height):
        Square.square_num += 1
        self.number = Square.square_num
        self.__width = width
        self.__height = height

    def getWidth(self):
        return self.__width

    def getHeight(self):
        return self.__height

    def setWidth(self, width):
        self.__width = width

    def setHeight(self, height):
        self.__height = height

    def getSquareRound(self):
        round = (self.__width + self.__height) * 2
        return round

    def getSquareArea(self):
        area = self.__width * self.__height
        return area
    def getSquareInfo(self):
        print("{}번째로 만들어진 직사각형 입니다.".format(self.square_num))
        print("이 직사각형의 너비 => {}".format(self.__width))
        print("이 직사각형의 높이 => {}".format(self.__height))
        # print("===========출력 끝=============")

# class
# sq1 = Square(10, 20)
# sq1.setWidth(50)
# sq1.setHeight(60)
# sq1.getSquareInfo()
# print(sq1.getSquareArea())
# print(sq1.getSquareRound())
#
# sq2 = Square(30, 40)
# sq2.setWidth(70)
# sq2.setHeight(80)
# sq2.getSquareInfo()
# print(sq2.getSquareArea())
# print(sq2.getSquareRound())
# a = [1,2,3,4,5]
# b = a.reverse()
# print(b)
#
# import random
# with open("numcount.txt", "w") as file:
#     for i in range(30):
#         file.write(str(random.randint(1,10)) + " ")
#
# with open("numcount.txt", "r") as file:
#     load_data = []
#     load_data = file.read().rstrip().split(" ")
#     for i in range(1, 11):
#         print("{}의 개수 => {}개".format(i, load_data.count(str(i))))

a = input()
print(type(a))
print(a.isspace())
