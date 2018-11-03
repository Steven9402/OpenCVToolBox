#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import matplotlib.pyplot as plt
import Image

im = Image.open("door_2.jpg")
plt.imshow(im, cmap = plt.get_cmap("gray"))
pos=plt.ginput(1)
print(pos)


