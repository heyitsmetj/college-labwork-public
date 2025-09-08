#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep  8 15:23:20 2025

@author: mitacsc
"""

import pandas
from sklearn import linear_model

df = pandas.read_csv("data.csv")

# Features & target
x = df[['Weight', 'Volume']]
y = df['CO2']

# Train model
regr = linear_model.LinearRegression()
regr.fit(x, y)


predictedCO2 = regr.predict(pandas.DataFrame([[2100, 1300]], columns=['Weight', 'Volume']))

print("Prediction: ", predictedCO2)
