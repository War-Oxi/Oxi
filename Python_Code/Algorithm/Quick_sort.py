
import random
import time

def qSort(array, start, end):
    if end <= start:
        return
    low = start
    high = end

    pivot = array[(low+high)//2]
    while low < high:
        while array[low] < pivot:
            low += 1
        while array[high] > pivot:
            high -= 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
            low, high = low+1, high-1
    mid = low
    qSort(array, start, mid-1)
    qSort(array, mid, end)

def quickSort(ary):
    qSort(ary, 0, len(ary)-1)


def interativeQsort(arr):
    stack=[]
    stack.append(0)
    stack.append(len(arr)-1)

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

            stack.append(p+1)
            stack.append(end)
            stack.append(begin)
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


print("total result => ", resulttime)
print("mintime => ", mintime)
print("maxtime => ", maxtime)
