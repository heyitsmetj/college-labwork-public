#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 21 16:16:30 2025

@author: mitacsc
"""

import pandas as pd
import numpy as np

dataset = pd.read_csv('Data.csv')
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