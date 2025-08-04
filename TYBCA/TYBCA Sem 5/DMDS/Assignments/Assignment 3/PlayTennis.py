#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 21 16:16:30 2025

@author: mitacsc
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn import tree

dataset = pd.read_csv('Tennis.csv')

Le = LabelEncoder()
dataset['Outlook'] = Le.fit_transform(dataset['Outlook'])
dataset['Temperature'] = Le.fit_transform(dataset['Temperature'])
dataset['Humidity'] = Le.fit_transform(dataset['Humidity'])
dataset['Wind'] = Le.fit_transform(dataset['Wind'])
dataset['PlayTennis'] = Le.fit_transform(dataset['PlayTennis'])

x = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 4].values

clf = tree.DecisionTreeClassifier(criterion="entropy")
clf = clf.fit(x, y)

plt.figure(figsize=(12, 8))
tree.plot_tree(clf,
               feature_names=dataset.columns[:-1],
               class_names=['No', 'Yes'],
               filled=True, 
               fontsize=10)
plt.show()

x_pred = clf.predict(x)

accuracy = np.sum(x_pred == y) / len(y)
print(f"Accuracy: {accuracy * 100:.2f}%")
