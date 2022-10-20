class People:
    c_Number = 0
    def __init__(self, age=0, name=None):
        People.c_Number += 1
        self.__age = age
        self.__name = name

    def greeting(self):
        print("안녕하세요 저는 사람입니다.")

    def getInfo(self):
        print("저는 {}번째 생성된 클래스 입니다.".format(People.c_Number))
        print("나이 : {}".format(self.__age))
        print("이름 : {}".format(self.__name))


class Student(People):
    def __init__(self, age=0, name=None, grade=None):
        super().__init__(age, name)
        self.__grade = grade

    def greeting(self):
        print("안녕하세요 저는 학생입니다.")

    def getInfo(self):
        super().getInfo()
        print("학년 : {}".format(self.__grade))


class Me(Student):
    def __init__(self, age=0, name=None, grade=None, job=None):
        super().__init__(age, name, grade)
        self.__job = job

    def greeting(self):
        print("안녕하세요 저는 저입니다.")

    def getInfo(self):
        super().getInfo()
        print("직업 : {}".format(self.__job))

def sayHello(who):
    who.greeting()

people1_ = People(12, "사람1")
people1_.getInfo()
sayHello(people1_)
print("=============================")
student1_ = Student(19, "최고수", "고등학교 3학년")
student1_.getInfo()
sayHello(student1_)
print("=============================")
me1 = Me(25, "김태지", "대학교 3학년", "백수")
me1.getInfo()
sayHello(me1)