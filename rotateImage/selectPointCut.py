#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import matplotlib.pyplot as plt
import Image
import os
import cv2

datapath='/home/cuizhou/codes/OpencvToolBox/rotateImage/f11n'
savepath='/home/cuizhou/codes/OpencvToolBox/rotateImage/rotated'


# 定义旋转rotate函数
def rotate(image, angle, center=None, scale=1.0):
    # 获取图像尺寸
    (h, w) = image.shape[:2]

    # 若未指定旋转中心，则将图像中心设为旋转中心
    if center is None:
        center = (w / 2, h / 2)

    # 执行旋转
    M = cv2.getRotationMatrix2D(center, angle, scale)
    rotated = cv2.warpAffine(image, M, (w, h))

    # 返回旋转后的图像
    return rotated
i=0
for file in os.listdir(datapath):


    srcImage = cv2.imread(os.path.join(datapath,file))

    rotated = rotate(srcImage, -90)

    cv2.imwrite(os.path.join(savepath,str(i)+'.jpg'),rotated)
    i+=1
    print(i)
