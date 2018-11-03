#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import matplotlib.pyplot as plt
import Image
import os
import cv2

datapath='/home/cuizhou/codes/OpencvToolBox/mouseCutImage/rotated'
savepath='/home/cuizhou/codes/OpencvToolBox/mouseCutImage/cut'

i=100
for file in os.listdir(datapath):
    im = Image.open(os.path.join(datapath,file))
    plt.imshow(im, cmap = plt.get_cmap("gray"))

    pos=plt.ginput(2)
    print(pos)

    srcImage = cv2.imread(os.path.join(datapath,file))
    roiImage = srcImage[int(pos[0][1]):int(pos[1][1]),int(pos[0][0]):int(pos[1][0]),:]

    cv2.imwrite(os.path.join(savepath,str(i)+'.jpg'),roiImage)
    i+=1
