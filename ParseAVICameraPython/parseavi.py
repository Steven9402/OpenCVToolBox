# -*- coding:UTF-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import pylab
import imageio
import skimage.io
import numpy as np  
import cv2  
import os
videopathdir='/home/cuizhou/Documents/弈人视频样例/样例2/'

i = 0
for videopath in os.listdir(videopathdir):
    print videopath
    cap = cv2.VideoCapture(os.path.join(videopathdir,videopath))

    while(cap.isOpened()):
        ret, frame = cap.read()
        if ret:
            interval=120 #600 stands for 25s per image capture
            print i%interval
            if(i%interval==0):
                cv2.imwrite('/home/cuizhou/projects/ADAS/trainingdata/b_'+str(i)+'.jpg',frame)
            i+=1
        else:
            break

    cap.release()