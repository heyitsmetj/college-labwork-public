#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 22 15:59:23 2025

@author: mitacsc
"""

# Import required libraries
import pandas as pd

# Load the dataset (change the file path as per your file location)
df = pd.read_csv('StudentsPerformance.csv')

# 1. Display the shape of the dataset
print("Shape of the dataset (rows, columns):", df.shape)

# 2. Display the top rows of the dataset
print("\nTop 5 rows of the dataset:")
print(df.head())

# 3. Display a random sample of rows from the dataset
num_rows = int(input("\nEnter the number of random rows to display: "))
print("\nDisplaying, {num_rows}, random rows:")
print(df.sample(n=num_rows))

# 4. Display the number of columns and the names of the columns
print("\nNumber of columns:", len(df.columns))
print("Names of the columns:", df.columns.tolist())