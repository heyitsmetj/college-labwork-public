#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 21 16:20:14 2025

@author: mitacsc
"""

import numpy as np
import pandas as pd 
from sklearn.preprocessing import LabelEncoder,OneHotEncoder
from sklearn.compose import ColumnTransformer

dataset=pd.read_csv('Data.csv')

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

