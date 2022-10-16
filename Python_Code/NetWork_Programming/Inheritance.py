class Rectangle:
    def __init__(self, width, height):
        self.__width = width
        self.__height = height

    def Set_Rectangle(self, width, height):
        self.__width = width
        self.__height = height

    def Get_Info(self):
        print("width = {}, height = {}".format(self.__width, self.__height))

    def Get_Area(self):
        print("Area => {}".format(self.__width * self.__height))

    def Get_Round(self):
        print("Round => {}".format(self.__width * 2 + self.__height * 2))

class Square(Rectangle):
    def __init__(self, width):
        super().__init__(width, width)

    def Set_Square(self, width):
        super().Set_Rectangle(width, width)

    def Get_Info(self):
        print("width = {}".format(self.__width))



Rectangle1_ = Rectangle(3, 5)
Rectangle1_.Get_Area()
Rectangle1_.Get_Round()
print("=============================")
Square1_ = Square(4)
Square1_.Set_Square(5)
Square1_.Get_Area()
Square1_.Get_Round()