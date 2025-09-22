#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 22 15:57:04 2025

@author: mitacsc
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from apyori import apriori

df=pd.read_csv('Groceries_dataset.csv')
record=[]

for i in range(0,1000):
    record.append([str(df.values[i,j]) for j in range(0,3)])
rules = apriori(record, min_support=0.002, min_confidence=0.20, min_lift=3, min_length=4)

rules=list(rules)
results_list=[]

for i in range(0,len(rules)):
    results_list.append('Rules:\t'+str(rules[i][0])+'\n Support:\t'+str(rules[i][1]))

results_length=len(results_list)
for i in range(0,results_length):
    print(results_list[i])
#print(results_list[0])