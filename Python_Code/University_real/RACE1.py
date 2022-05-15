import turtle
import random
import time

screen = turtle.Screen()
image1 = "/Users/kimtaeji/Code/Python_Code/University_real/RACE/rabbit.GIF"
image2 = "/Users/kimtaeji/Code/Python_Code/University_real/RACE/turtle.GIF"
screen.addshape(image1)
screen.addshape(image2)

t1 = turtle.Turtle()
t1.shape(image1)
t1.pensize(5)
t1.penup()
t1.goto(-300, -200)

t2 = turtle.Turtle()
t2.shape(image2)
t2.pensize(5)
t2.penup()
t2.goto(-300, 200)

t1.pendown()
t2.pendown()
t1.speed(1)
t2.speed(1)

distance1=0
distance2=0
for i in range(100):
    rand1 = random.randint(1, 2)
    if rand1 == 1:
        d1 = random.randint(1, 40)
        t1.forward(d1)
        distance1 += d1
        print("토끼 이동거리 : ", distance1)
    else:
        d2 = random.randint(1, 40)
        t2.forward(d2)
        distance2 += d2
        print("거북이의 이동거리 : ", distance2)
    if distance1 >= 600:
        print("토끼가 승리 했습니다")
        break
    elif distance2 >= 600:
        print("거북이가 승리 했습니다")
        break
    else:
        continue
time.sleep(3)