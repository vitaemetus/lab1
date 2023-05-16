import matplotlib.pyplot as plt
import numpy as np

y = []
x = []
y1 = []
x1 = []
y2 = []
x2 = []

with open('section3/C/exh_search_C1.txt') as f:
    for i, line in enumerate(f):
        y.append(int(line))
        x.append(100 + i*50)

with open('section3/C/exh_search_C2.txt') as f:
    for i, line in enumerate(f):
        y1.append(int(line))
        x1.append(100 + i*50)

with open('section1 (done)/exh.txt') as f:
    for i, line in enumerate(f):
        y2.append(int(line))
        x2.append(100 + i*50)

fig = plt.figure()
fig1 = plt.figure()
fig2 = plt.figure()

ax = fig.add_subplot(1,1,1)
ax.scatter(x, y, s = 5, color = 'b')
ax.scatter(x2, y2, s = 5, color = 'r')

ax1 = fig1.add_subplot(1,1,1)
ax1.scatter(x1, y1, s = 5, color = 'g')
ax1.scatter(x2, y2, s = 5, color = 'r')

ax2 = fig2.add_subplot(1,1,1)
ax2.scatter(x1, y1, s = 5, color = 'g')
ax2.scatter(x, y, s = 5, color = 'b')

plt.show()
