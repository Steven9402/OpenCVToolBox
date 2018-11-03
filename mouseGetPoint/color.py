#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import matplotlib.pyplot as plt
import Image
import cv2

#im = Image.open("/home/cuizhou/data/AdasData/TrainIJCNN2013/00263.ppm")
im = cv2.imread("/home/cuizhou/codes/AdasProject/Lane/CarND-Advanced-Lane-Lines/test_images/straight_lines1.jpg")
im = cv2.cvtColor(im,cv2.COLOR_BGR2HSV)
plt.imshow(im)
#plt.imshow(im, cmap = plt.get_cmap("gray"))
pos=plt.ginput(1)
x=int(pos[0][0])
y=int(pos[0][1])
rows=im.shape[0]
cols=im.shape[1]
#print(im.shape)
print(im[y][x])
print(x,y)


