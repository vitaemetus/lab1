import matplotlib.pyplot as plt
import numpy as np

y = []
x = []

with open('section1.txt') as f:
    for i, line in enumerate(f):
        y.append(int(line))
        x.append(100 + i*10000)

fig = plt.figure()
# ax0 = fig.add_subplot(1,2,1)
# ax1 = fig.add_subplot(1,2,2)
ax1 = fig.add_subplot(1,1,1)
# ax0.plot(x, y)
ax1.scatter(x, y, s = 10)
plt.show()
