import numpy as np
import matplotlib.pyplot as plt

csv = np.genfromtxt ('list_pop.csv', delimiter=",")
N_list = csv[:100,0]
t_list = csv[:100,1]

fig, ax = plt.subplots()

ax.errorbar(x=N_list, y=t_list, fmt='o', markersize=3, linestyle='None', color='green', linewidth=0.5, capsize=1, label= 'List stack')

ax.legend(loc='upper right')
plt.title('График N(t) для функции pop')
plt.grid(axis='both')
plt.xlabel('$ N $')
plt.ylabel('$ t, мкс$')
plt.show()
fig.savefig('graph2.pdf')