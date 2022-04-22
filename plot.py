import numpy as np
import matplotlib.pyplot as plt
A = np.loadtxt('opinions.dat')
fig = plt.figure()
x = A[:,0] #Tous les x d' lagent 0
#x = [i for i in range(0,len(y0))]
for i in range(1,20):
    y=A[:,i]
    plt.plot(x,y)
plt.title("$\epsilon=0.4$")
#fig.savefig('Opinions_x=f(t)_N=20_M=76_eps=0.4_k=3_T=10s.png', transparent=True)
fig.savefig('coucou.png', transparent=True)
plt.close()
fig.clf()
#plt.plot(x,y0,y1)
#plt.show()
