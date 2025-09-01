#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  1 15:10:38 2025

@author: mitacsc
"""

import numpy as np
import matplotlib.pyplot as plt

# Function to estimate the coefficients of x and y
def estimate(x, y):
    # Number of observations
    a = np.size(x)

    # Mean of x and y
    mean_x = np.mean(x)
    mean_y = np.mean(y)

    # Calculating sum of square errors (corrected)
    ss_xy = np.sum((x - mean_x) * (y - mean_y))  # Sum of cross deviations
    ss_xx = np.sum((x - mean_x) ** 2)  # Sum of squared deviations

    # Calculating regression coefficients
    b1 = ss_xy / ss_xx  # Slope (b1)
    b0 = mean_y - b1 * mean_x  # Intercept (b0)

    return b0, b1

# Function to plot the regression line
def plot_reg(x, y, b):
    plt.scatter(x, y, color='red', marker='*')  # Scatter plot
    y_predicted = b[0] + b[1] * x  # Predicted y values
    plt.plot(x, y_predicted, color='green')  # Plotting the regression line
    plt.xlabel('Size')
    plt.ylabel('Cost')
    plt.show()

# Now we will create our dataset and call these functions
x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13])
y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12, 16, 18])

# Estimate the coefficients
b = estimate(x, y)
print('Estimated Coefficients: \n b0={} \nb1={}'.format(b[0], b[1]))

# Plot the regression line
plot_reg(x, y, b)
