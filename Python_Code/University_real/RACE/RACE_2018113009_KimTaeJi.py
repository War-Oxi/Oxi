import turtle
import random
import time

def counter():
    i=0
    def count():
        nonlocal i
        i += 1
        return i
    return count

screen = turtle.Screen()
# image1 = "/Users/kimtaeji/Code/Python_Code/University_real/RACE/rabbit.GIF"
# image2 = "/Users/kimtaeji/Code/Python_Code/University_real/RACE/turtle.GIF"
image1 = "rabbit.GIF"
image2 = "turtle.GIF"
screen.addshape(image1)
screen.addshape(image2)

t1 = turtle.Turtle()
t1.shape(image1)
t1.pensize(5)
t1.penup()
t1.goto(-300, 250)

t2 = turtle.Turtle()
t2.shape(image2)
t2.pensize(5)
t2.penup()
t2.goto(-300, 100)

t3 = turtle.Turtle()
t3.shape(image1)
t3.pensize(5)
t3.penup()
t3.goto(-300, -50)

t4 = turtle.Turtle()
t4.shape(image2)
t4.pensize(5)
t4.penup()
t4.goto(-300, -200)

t1.pendown()
t2.pendown()
t3.pendown()
t4.pendown()

t1.speed(1)
t2.speed(1)
t3.speed(1)
t4.speed(1)

distance1=0
distance2=0
distance3=0
distance4=0
maxDistance=550
for i in range(1000):
    rand1 = random.randint(1, 4)
    if rand1 == 1:
        d1 = random.randint(1, 40)
        t1.forward(d1)
        distance1 += d1
        print("player1 이동거리 : ", distance1)
    elif rand1 == 2:
        d2 = random.randint(1, 40)
        t2.forward(d2)
        distance2 += d2
        print("player2 이동거리 : ", distance2)
    elif rand1 == 3:
        d3 = random.randint(1, 40)
        t3.forward(d3)
        distance3 += d3
        print("player3 이동거리 : ", distance3)
    else:
        d4 = random.randint(1, 40)
        t4.forward(d4)
        distance4 += d4
        print("player4 이동거리 : ", distance4)
    if distance1 >= maxDistance:
        t1.color("red")
        t1.write(str("1등"), font=("times New Roman", 20, "bold"))
        print("player1이 승리 했습니다")
        break
    elif distance2 >= maxDistance:
        t2.color("red")
        t2.write(str("1등"), font=("times New Roman", 20, "bold"))
        print("player2가 승리 했습니다")
        break
    elif distance3 >= maxDistance:
        t3.color("red")
        t3.write(str("1등"), font=("times New Roman", 20, "bold"))
        print("player3이 승리 했습니다")
        break
    elif distance4 >= maxDistance:
        t4.color("red")
        t4.write(str("1등"), font=("times New Roman", 20, "bold"))
        print("player4가 승리 했습니다")
        break
    else:
        continue
time.sleep(2)