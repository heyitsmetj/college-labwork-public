#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 28 15:25:00 2025

@author: mitacsc
"""

from sklearn.datasets import load_iris
from sklearn import preprocessing

iris=load_iris()

x=iris.data
print(x.shape)
y=iris.target

normalize_x=preprocessing.normalize(x)

print(normalize_x[:5])