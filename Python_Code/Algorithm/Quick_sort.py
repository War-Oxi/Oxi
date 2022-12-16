import random
import time
<<<<<<< HEAD
import sys

def selectSort(ary):
    n = len(ary)
    for i in range(0, n-1):
        minIdx = i
        for k in range(i+1, n):
            if(ary[minIdx] > ary[k]):
                minIdx = k
        tmp = ary[i]
        ary[i] = ary[minIdx]
        ary[minIdx] = tmp

def insertSort(ary):
    n = len(ary)
    for end in range(1, n):
        for cur in range(end, 0, -1):
            if(ary[cur-1] > ary[cur]):
                ary[cur-1], ary[cur] = ary[cur], ary[cur-1]

def bubbleSort(ary):
    n = len(ary)
    for end in range(n-1, 0, -1):
        for cur in range(0, end):
            if(ary[cur] > ary[cur+1]):
                ary[cur], ary[cur+1] = ary[cur+1], ary[cur]

=======
>>>>>>> 96ca999c54bc3381ad975292e55b4f3f812a03b9

def qSort(array, start, end):
    if end <= start:
        return
    low = start
    high = end

    pivot = array[(low + high) // 2]
    while low < high:
        while array[low] < pivot:
            low += 1
        while array[high] > pivot:
            high -= 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
            low, high = low + 1, high - 1
    mid = low
    qSort(array, start, mid - 1)
    qSort(array, mid, end)


def quickSort(ary):
    qSort(ary, 0, len(ary) - 1)


def interativeQsort(arr):
    stack = []
    stack.append(0)
    stack.append(len(arr) - 1)

    while (len(stack) != 0):
        end = stack.pop()
        begin = stack.pop()

        if begin < end:
            pivot = arr[end]
            p = begin - 1
            for j in range(begin, end):
                if arr[j] <= pivot:
                    p += 1
                    arr[p], arr[j] = arr[j], arr[p]

            p += 1
            arr[p], arr[end] = arr[end], arr[p]

            stack.append(p + 1)
            stack.append(end)
            stack.append(begin)
<<<<<<< HEAD
            stack.append(p - 1)


# arr = [500, 1000, 3000, 5000, 7000, 9000, 11000]
with open("B_QuickSort.csv", "w") as f:
    f.write("반복횟수, 수행시간 \n")
    arr = []
    tmp = 0
    while tmp <= 10000:

        arr.append(tmp)
        tmp += 100

    # print(arr)
    # print(len(arr))

    iter = 10

    for N in arr:
        # shortistTime = sys.maxsize
        # longestTime = 0
        resultTime = 0
        for j in range(iter):
            i = 0
            # aOrgData = []
            aOrgData = random.sample(range(1, N * 10), N)

            # while i < N:
            #     data = random.randrange(1, N * 10)
            #     if not (data in aOrgData):
            #         aOrgData.append(data)
            #         i += 1
            starttime = time.time()
            # quickSort(aOrgData)
            # interativeQsort(aOrgData)
            quickSort(aOrgData)
            endtime = time.time()
            runningTime = endtime - starttime

            # if longestTime < runningTime:
            #     longestTime = runningTime
            #
            # if shortistTime > runningTime:
            #     shortistTime = runningTime

            resultTime += (endtime - starttime)
        avgTime = resultTime/iter
        f.write(f"{N}, {avgTime*100:.5f} \n")
        print(f"배열의 크기 => {N} 평균 시간 => {avgTime*100:.5f}ms ")
              # f"\n최소 수행 시간 => {shortistTime:.5f}ms 최대 수행 시간 => {longestTime:.5f}ms")
        print("=============================================================================")

# print(longestTime)
# print(shortistTime)
=======
            stack.append(p-1)



N = 10000
iter = 100
i = 0
mintime = 1000000000000
maxtime = 0
resulttime = 0

for i in range(iter):
    aOrgData = []
    while i < N:
        data = random.randrange(1, N*10)
        if not (data in aOrgData):
            aOrgData.append(data)
            i += 1

    aData = aOrgData
    starttime = time.time()
    quickSort(aData)
    endtime = time.time()
    if endtime-starttime < mintime:
        mintime = endtime-starttime
    elif endtime-starttime > maxtime:
        maxtime = endtime-starttime

    print((endtime-starttime))
    resulttime += endtime - starttime

>>>>>>> 96ca999c54bc3381ad975292e55b4f3f812a03b9

print("total result => ", resulttime)
print("mintime => ", mintime)
print("maxtime => ", maxtime)
