import pandas as pd
from sklearn import tree
from sklearn.tree import DecisionTreeClassifier

dataset = pd.read_csv('shows.csv')

d = {'UK':0,'USA':1,'N':2}
dataset['Nationality'] = dataset['Nationality'].map(d)
d = {'YES':1,'NO':0}
dataset['Go'] = dataset['Go'].map(d)

x = dataset.iloc[:,:-1].values
y = dataset.iloc[:,4].values

dtree = DecisionTreeClassifier()
dtree = dtree.fit(x, y)

prediction = dtree.predict([[1,40,10,7]])
print(f"Prediction : {'Yes' if prediction[0] == 1 else 'No'}")

prediction = dtree.predict([[36,10,9,0]])
print(f"Prediction : {'Yes' if prediction[0] == 1 else 'No'}")
