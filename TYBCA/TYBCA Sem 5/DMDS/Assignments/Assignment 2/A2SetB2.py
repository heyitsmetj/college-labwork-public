#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 28 15:30:37 2025

@author: mitacsc
"""

import pandas as pd 
import numpy as np

dataset = pd.read_csv("Data.csv")
print ("Original Dataset:\n" , dataset)
print ("_" * 50)

x = dataset.iloc[:, :1].values
y = dataset.iloc[: , -1].values
print("Input feactures (x):\n" , x)
print("Target Output (y):\n" , y)

from sklearn.model_selection import train_test_split

x_train, x_test, y_train, y_test= train_test_split(x, y, test_size=0.2, random_state=0)

print("\nTraning Input (x_train):\n", x_train)

print("\nTesting Input (x_test):\n", x_test)

print("\nTraning Output (y_train):\n", y_train)

print("\nTraning Onput (y_train):\n", y_test)