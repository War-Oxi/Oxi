def Prime_Num_Discriminator(num):
    for i in range(2, int(num/2+1)):
        if num % i == 0:
            return
    return num

for i in range(2, 2000):
    if(Prime_Num_Discriminator(i) != None):
        print(Prime_Num_Discriminator(i))
