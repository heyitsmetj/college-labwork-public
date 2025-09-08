#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  8 15:26:12 2025

@author: mitacsc
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error

Stock_Market = {
    'Year': [2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017, 2017],
    'Month': [12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
    'Interest_Rate': [2.75, 2.5, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25, 2.25],
    'Unemployment_Rate': [5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5],
    'Stock_Index_Price': [1464, 1394, 1357, 1256, 1254, 1234, 1199, 1159, 1167, 1130, 1075, 1047]
}

df = pd.DataFrame(Stock_Market)

X = df[['Year', 'Month', 'Interest_Rate', 'Unemployment_Rate']]
y = df['Stock_Index_Price']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


model = LinearRegression()
model.fit(X_train, y_train)


y_pred = model.predict(X_test)

mae = mean_absolute_error(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)
rmse = np.sqrt(mse)


print("Mean Absolute Error (MAE):", mae)
print("Mean Squared Error (MSE):", mse)
print("Root Mean Squared Error (RMSE):", rmse)

plt.figure(figsize=(10, 6))
plt.scatter(df['Interest_Rate'], df['Stock_Index_Price'], color='blue', label='Actual Data')
plt.plot(df['Interest_Rate'], model.predict(X), color='red', linewidth=2, label='Fitted Line')
plt.xlabel('Interest Rate')
plt.ylabel('Stock Index Price')
plt.title('Stock Index Price vs Interest Rate')
plt.legend()
plt.show()
