#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 22 15:57:02 2025

@author: mitacsc
"""
from ucimlrepo import fetch_ucirepo 
  
# fetch dataset 
iris = fetch_ucirepo(id=53) 

# Load the dataset (assuming IRIS.csv is in the same directory or provide the correct path)
df = pd.read_csv(iris)

# Check the dataset
print(df.head()) # Print first few rows for verification

# Discretize numerical features into categorical features using pd.cut
df['sepal_length'] = pd.cut(df['sepal_length'], bins=3, labels=["short", "medium", "long"])
df['sepal_width'] = pd.cut(df['sepal_width'], bins=3, labels=["narrow", "medium", "wide"])
df['petal_length'] = pd.cut(df['petal_length'], bins=3, labels=["short", "medium", "long"])
df['petal_width'] = pd.cut(df['petal_width'], bins=3, labels=["narrow", "medium", "wide"])

# Now each feature is categorical (binned), and we can prepare the dataset for Apriori
records = []
for i in range(0, len(df)):
    records.append([str(df.values[i, j]) for j in range(0, len(df.columns))])

# Apply the Apriori algorithm
rules = apriori(records, min_support=0.1, min_confidence=0.5, min_lift=1.5, min_length=2)

# Convert the rules into a list
rules_list = list(rules)

# Prepare to store results in a human-readable format
results_list = []

# Extracting the rules along with their support, confidence, and lift
for rule in rules_list:
    support = rule.support
    for ordered_stat in rule.ordered_statistics:
        base_items = ', '.join(list(ordered_stat.items_base))
        add_items = ', '.join(list(ordered_stat.items_add))
        confidence = ordered_stat.confidence
        lift = ordered_stat.lift
    
    # Store the rule in a readable format
    results_list.append(f"Rule: ({base_items}) -> ({add_items}) \nSupport: {support} \nConfidence: {confidence} \n Lift: {lift}\n")

# Display number of rules found
print(f"Number of rules found: {len(results_list)}\n")

# Display the first rule (for testing, you can print more if needed)
if len(results_list) > 0:
    print(f"First Rule: {results_list[0]}")
else:
    print("No rules found.")