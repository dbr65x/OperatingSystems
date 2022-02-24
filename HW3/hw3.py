from numpy import random
import matplotlib.pyplot as plt

k = 1000  # a set of k processes
thislist = []  # will hold the 3-tuples

# distribution for required cpu cycles
CPUcycles = [((random.normal(6000, 3000) + 1000) % 11000) + 1 for a in range(k)]
# distribution for memory footprint
memorySize = [((random.normal(20, 10) + 1) % 100) + 1 for b in range(k)]

# tuple storing loop
for i in range(k):
    x = (i, CPUcycles[i], memorySize[i])  # PID, number of cycles, size of memory footprint
    thislist.append(tuple(x))  # tuple creator
    print(thislist[i])

# this displays the arrays
plt.hist(CPUcycles)
plt.title("Cycles Histogram")
plt.xlabel("Cycles")
plt.ylabel("Frequency")
plt.show()
plt.clf()

plt.hist(memorySize)
plt.title("Memory Footprint Histogram")
plt.xlabel("Memory")
plt.ylabel("Frequency")
plt.show()
plt.clf()
