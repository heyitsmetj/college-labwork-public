import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn import tree

dataset = pd.read_csv('diabetes.csv')

for col in dataset.columns:
    dataset[col] = LabelEncoder().fit_transform(dataset[col])

x = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 8].values

clf = tree.DecisionTreeClassifier(criterion="entropy")
clf.fit(x, y)

plt.figure(figsize=(12, 8))

tree.plot_tree(clf,
               feature_names=dataset.columns[:-1],
               class_names=['No', 'Yes'],
               filled=True,
               rounded=True,
               fontsize=10)
plt.show()
