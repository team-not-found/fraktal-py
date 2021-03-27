import fraktal_py as fp

filename = "plot.bin"
fern = fp.Fern()
fern.generateFractal(300,-4,0,4,10,200000000)
fern.saveFractal(filename)

import numpy as np
import matplotlib.pyplot as plt
from pylab import *


nX = fern.nX
nY = fern.nY
a = fromfile(filename, dtype=float64).reshape((nX, nY))

print(np.sum(a))
print(np.min(a))
a+=1
a=np.log(a)
plt.matshow(a)
plt.show()
