import matplotlib.pyplot as plt

def maketable(tabledata):
        font = {'weight' : 'bold',
        'size'   : 25}
        plt.rc('font', **font)
        table = plt.table(cellText=tabledata, colLabels=['N', 'Recursive', 'Bottom Up', 'Closed Form','Matrix'], loc='center', 
                  cellLoc='center', colColours=['#FFFFFF', '#F3CC32', '#2769BD', '#DC3735','#FFFFFF'])
        plt.axis('off')
        plt.savefig('Table Data.png', dpi=300)