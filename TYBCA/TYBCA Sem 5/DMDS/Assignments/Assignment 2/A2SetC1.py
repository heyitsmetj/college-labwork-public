#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 28 15:56:58 2025

@author: mitacsc
"""

import numpy as np
import pandas as pd 
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.datasets import load_iris
from sklearn import preprocessing

dataset=pd.read_csv('Data.csv')

print("Finding the NULL Values: \n\n")

miss_values = dataset.isnull()
print(miss_values)

miss_values_sum = dataset.isnull().sum()
print("\nPrint the missing values:\n", miss_values_sum)

modified_dataset = dataset.fillna("##")
print("\nTotal Missing values sum:\n", modified_dataset)

missing_dataset_sum_after_modified = modified_dataset.isnull()
print("\nMissing values data after modification:\n", missing_dataset_sum_after_modified)

clean_data_dataset = dataset.dropna()
print("\nShow dataset without missing values:\n", clean_data_dataset)

print("\n\nConverting the Categorical Values into Numeric Format: \n\n")

x = dataset.iloc[:, :-1].values
y = dataset.iloc[:,3].values

Label_X = LabelEncoder()
x[:,0] = Label_X.fit_transform(x[:,0])
rg = ColumnTransformer([("Region",OneHotEncoder(),[0])],remainder="passthrough")
x = rg.fit_transform(x)

label_Y = LabelEncoder()
y=label_Y.fit_transform(y)

print(x)
print(y)

print("\n\nRescaling the Data: \n\n")

iris=load_iris()

x=iris.data
print(x.shape)
y=iris.target

normalize_x=preprocessing.normalize(x)

print(normalize_x[:5])

print("\n\nSplitting the Dataset: \n\n")

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

