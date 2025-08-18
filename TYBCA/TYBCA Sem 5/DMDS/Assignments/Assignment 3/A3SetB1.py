from sklearn.preprocessing import LabelEncoder

weather = ['Sunny', 'Sunny', 'Overcast', 'Rainy', 'Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Rainy', 'Sunny', 'Overcast', 'Overcast', 'Rainy']
temp = ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild']
play = ['No','No','Yes','Yes','Yes','No','Yes','No','Yes','Yes','Yes','Yes','Yes','No']

LE = LabelEncoder()
w = LE.fit_transform(weather)
t = LE.fit_transform(temp)
p = LE.fit_transform(play)

X = list(zip(w, t))
Y = p

from sklearn.naive_bayes import GaussianNB

classifier = GaussianNB()
classifier.fit(X, Y)

y_pred = classifier.predict([[0, 2]])

print("Prediction Value: ", y_pred)