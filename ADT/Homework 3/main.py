import time
import matplotlib.pyplot as plt

import f_bottomUp
import f_recursive
import f_formula
import f_matrix
import table

frecursive=[]
fbottomUp=[]
fformula=[]
fmatrix=[]
index=[]
tabledata=[]

file = open("testfile.txt","w") 
for j in range(1,22):
    i=int(j+j**1.03)
    # The gap between samples increases n gets the larger
    print(" N : ",i)
    start=time.time()
    f_recursive.frecursive(i)
    end=time.time()
    fr=(end-start)
    frecursive.append(fr)

    start=time.time()
    f_bottomUp.fbottomUp(i)
    end=time.time()
    fb=(end-start)
    fbottomUp.append(fb)

    start=time.time()
    f_formula.fformula(i)
    end=time.time()
    ff=(end-start)
    fformula.append(ff)

    start=time.time()
    f_matrix.fmatrix(i)
    end=time.time()
    fm=(end-start)
    fmatrix.append(fm)

    tabledata.append([i,fr,fb,ff,fm])
    index.append(i)
    text=str(i)+"   "+str(fr)+" "+str(fb)+" "+str(ff)+" "+str(fm)+"\n"
    file.write(text) 

file.close()

###################### TO PLOT GRAPH #####################################

axes = plt.gca()
# axes.set_ylim([0, 0.05])
plt.plot(index, frecursive, label="Recursive", linewidth=1)
plt.plot(index, fbottomUp, label="Bottom Up", linewidth=1)
plt.plot(index, fformula, label="Formula", linewidth=1)
plt.plot(index, fmatrix, label="Matrix", linewidth=1)

plt.legend(loc='upper center', bbox_to_anchor=(0.5, -0.05),
            fancybox=True, shadow=True, ncol=5)
plt.ylabel('Time ')
plt.savefig('./plot_all.png', dpi=300)
plt.show()

plt.plot(index, frecursive, label="Recursive", linewidth=1)
plt.savefig('./plots/Recursive.png', dpi=300)
plt.clf()

plt.plot(index, fbottomUp, label="Bottom Up", linewidth=1)
plt.savefig('./plots/Bottom.png', dpi=300)
plt.clf()

plt.plot(index, fformula, label="Formula", linewidth=1)
plt.savefig('./plots/Formula.png', dpi=300)
plt.clf()

plt.plot(index, fmatrix, label="Matrix", linewidth=1)
plt.savefig('./plots/Matrix.png', dpi=300)
plt.clf()

# To make a table of data
table.maketable(tabledata)