class People:
    def __init__(self, age=0, name=None):
        self.__age = age
        self.__name = name

    def IntroMe(self):
        print("Name : ", self.__name, "age : ", str(self.__age))

class Teacher (People):
    def __init__(self, age = 0, name = None, school = None):
        super().__init__(age, name)
        self.__school = school

    def IntroMe(self):
        super().IntroMe()
        print("School : ", self.__school)

class Student (Teacher):
    def __init__(self, age=0, name=None, school = None, grade=None):
        super().__init__(age, name, school)
        self.__grade = grade

    def IntroMe(self):
        super().IntroMe()
        print("Grade : ", self.__grade)

p1 = People(29, "Lee")
p1.IntroMe()

t1 = Teacher(48, "Kim", "HighSchool")
t1.IntroMe()

s1 = Student(17, "Park", "HighSchool", 2)
s1.IntroMe()