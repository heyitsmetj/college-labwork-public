#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  1 14:56:33 2025

@author: mitacsc
"""

import numpy as np
from sklearn.linear_model import LinearRegression

# Input Data
x = np.array([1, 2, 3, 4, 5, 6, 7, 8]).reshape((-1, 1))
print(x)

y = np.array([7, 14, 15, 18, 19, 21, 26, 23])
print(y)

# Create model and fit it
model = LinearRegression()
model.fit(x, y)

# Predict a new value (for x=9)
x_new = np.array(9).reshape((-1, 1))
y_new_pred = model.predict(x_new)

# Output the prediction
print(y_new_pred)
print('slope : ', model.coef_)
