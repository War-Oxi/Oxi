import random
with open("test.csv", "w") as f:
    f.write("배열의 크기, 수행시간 \n")
    b = []
    for i in range(0, 1000, 100):
        tmp = random.sample(range(i, i + 100), 100)
        b.append(tmp)
    aOrgData = sum(b, [])
    print(aOrgData)
    print(len(aOrgData))
    for i in aOrgData:
        f.write(f"{i}\n")
    # print(f"배열의 크기 => {1000} 평균 시간 => {avgTime * 1000:.5f}ms ")