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

for i in range(20):
    d1 = random.randint(1, 50)
    d2 = random.randint(1, 50)
    t1.forward(d1)
    t2.forward(d2)
time.sleep(3)
