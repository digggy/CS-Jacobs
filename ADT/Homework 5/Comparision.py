import hoare
import lomuto
import median
import random
import time
import matplotlib.pyplot as plt


def generateRandom(n):
    array = [None]*n
    for i in range(n):
        array[i] = random.randint(0, 1000)
    return array

lomutoCase=[]
hoareCase=[]
medianCase=[]
index=[]

for i in range(1,100001,2):
    
    print(i)
    array1=generateRandom(1000)
    array2=array1
    array3=array1


    start = time.time()
    lomuto.lomuto_QuickSort(array1,0,len(array1)-1)
    end=time.time()
    lomutoCase.append((end-start))

    start = time.time()
    hoare.Hoare_QuickSort(array2,0,len(array2)-1)
    end=time.time()
    hoareCase.append((end-start))

    start = time.time()
    median.Median_QuickSort(array3,0,len(array3)-1)
    end=time.time()
    medianCase.append((end-start))
    
    index.append(i)


lo=sum(lomutoCase)/100000
ho=sum(hoareCase) /100000
me=sum(medianCase)/100000

axes = plt.gca()
# axes.set_ylim([0, 0.05])
plt.plot(index, lomutoCase, label="Lomuto Case", linewidth=0.5)
plt.plot(index, hoareCase, label="Hoare Case", linewidth=0.5)
plt.plot(index, medianCase, label="Median Case", linewidth=0.5)

plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.05),
            fancybox=True, shadow=True, ncol=5)

plt.ylabel('Time ')
# plt.show()
plt.savefig('./Plot/data1/Heapsort_comparision'+str(i)+'.png', dpi=300)
plt.clf()

print("Lomuto Case :",lo)
print("Hoare Case :",ho)
print("Median Case :",me)
