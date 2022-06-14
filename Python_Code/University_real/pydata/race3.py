import turtle
import random
import time

screen = turtle.Screen()
image1 = "d:\\pydata\\rabbit.gif"
image2 = "d:\\pydata\\turtle.gif"
screen.addshape(image1)
screen.addshape(image2)

def counter():
    i=0
    def count():
        nonlocal i
        i += 1
        return i
    return count

num1 = counter()
num2 = counter()
num3 = counter()
num4 = counter()

t1 = turtle.Turtle()
t1.shape(image1)
t1.pensize(5)
t1.penup()
t1.goto(-300, -200)

t2 = turtle.Turtle()
t2.shape(image1)
t2.pensize(5)
t2.penup()
t2.goto(-300, -50)

t3 = turtle.Turtle()
t3.shape(image2)
t3.pensize(5)
t3.penup()
t3.goto(-300, 100)

t4 = turtle.Turtle()
t4.shape(image2)
t4.pensize(5)
t4.penup()
t4.goto(-300, 250)

t1.pendown()
t2.pendown()
t3.pendown()
t4.pendown()
t1.speed(1)
t2.speed(1)
t3.speed(1)
t4.speed(1)

for i in range(100):
    player = random.randint(1, 4)
    if player == 1:
        t1.fd(10)
        time.sleep(0.2)
        if num1() > 25:
            t1.color("red")
            t1.write(str("1등"), font=("Times New Roman", 20, "bold"))
            time.sleep(3)
            break
    elif player == 2:
        t2.fd(10)
        time.sleep(0.2)
        if num2() > 25:
            t1.color("red")
            t1.write(str("1등"), font=("Times New Roman", 20, "bold"))
            time.sleep(3)
            break
    elif player == 3:
        t3.fd(10)
        time.sleep(0.2)
        if num3() > 25:
            t1.color("red")
            t1.write(str("1등"), font=("Times New Roman", 20, "bold"))
            time.sleep(3)
            break
    else:
        t4.fd(10)
        time.sleep(0.2)
        if num4() > 25:
            t1.color("red")
            t1.write(str("1등"), font=("Times New Roman", 20, "bold"))
            time.sleep(3)
            break









