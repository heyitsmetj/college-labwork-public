import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans

# The program reads a CSV file and loads the data.
dataset = pd.read_csv("CC_GENERAL.csv")
X = dataset.iloc[:,1:].values

# It handles any missing values in the dataset by filling them with the most frequent values.
imputer = SimpleImputer(missing_values=np.nan, strategy='most_frequent')
imputer.fit(X)
X = imputer.transform(X)

# The data is then standardized.
sc_X = StandardScaler()
X = sc_X.fit_transform(X)

# A K-Means clustering algorithm is applied to group the data into 8 clusters.
kmeans = KMeans(n_clusters=8, init='k-means++', max_iter=300, n_init=10, random_state=0)
y_kmeans = kmeans.fit_predict(X)

# Add cluster labels to the original dataset
dataset['Cluster'] = y_kmeans
dataset.head()