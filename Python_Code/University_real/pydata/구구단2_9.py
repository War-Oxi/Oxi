#for 구구단
for dan in range(2,10,1):
    print("## %d단 ##" %dan)
    for su in range(1,10,1):
        print("%d X %d = %d" %(dan, su, dan*su))
    print("")