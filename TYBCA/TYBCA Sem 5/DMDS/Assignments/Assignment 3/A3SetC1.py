#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  1 15:12:51 2025

@author: mitacsc
"""

import numpy as np
import pandas as pd
#import matplotlib.pyplot as plt
dataset=pd.read_csv("Social_Network_Ads.csv")
x= dataset.iloc[:,[0,1]].values  # Contains the feature variables, which are the columns at indices 2 and 3
y= dataset.iloc[:,2].values  # Contains the target variable, which is the column at index 4

# Splitting the Dataset into Training and Test Sets
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.25,random_state=0)
# x_train, y_train: These are the training data i.e. 75% of total data
# x_test, y_test: These are the test data i.e. 25% of the total data

from sklearn.preprocessing import StandardScaler
sc=StandardScaler()  # StandardScaler(): Scales the features by removing the mean and scaling to unit variance
x_train=sc.fit_transform(x_train)
x_test=sc.fit_transform(x_test)

#SVC(): Initializes the Support Vector Classifier with a linear kernel
from sklearn.svm import SVC
classifier=SVC(kernel='linear',random_state=0)
classifier.fit(x_train,y_train)

#Making a Prediction
y_pred=classifier.predict([[20,84000]])
print("Predicted Value:",y_pred)
