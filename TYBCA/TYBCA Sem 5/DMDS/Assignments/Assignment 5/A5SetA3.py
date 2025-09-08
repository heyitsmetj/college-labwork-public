#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  8 16:00:15 2025

@author: mitacsc
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  8 15:57:49 2025

@author: mitacsc
"""
# author: Jyoti

import pandas
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error
from math import sqrt

df = pandas.read_csv("student_scores.csv")

x = df[['Hours']]
y = df['Scores']

# Apply Simple Linear Regression
model = LinearRegression()
model.fit(x, y)

# Predict the values
y_pred = model.predict(x)

# Calculate errors
mae = mean_absolute_error(y, y_pred)
mse = mean_squared_error(y, y_pred)
rmse = sqrt(mse)

# Print the results
print(f"Mean Absolute Error (MAE): {mae}")
print(f"Mean Squared Error (MSE): {mse}")
print(f"Root Mean Squared Error (RMSE): {rmse}")
