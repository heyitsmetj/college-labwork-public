import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.cluster import hierarchy as sch
from sklearn.cluster import AgglomerativeClustering
from sklearn.impute import SimpleImputer

# This selects specific columns (3rd and 4th columns) from the DataFrame.
# You may need to change the file path to match your system.
dataset = pd.read_csv("Ecommerce_Customers.csv")
X = dataset.iloc[:, [3, 4]].values

# Use an imputer to handle any missing values. This is crucial for the `linkage` function to work.
imputer = SimpleImputer(missing_values=np.nan, strategy='mean')
X = imputer.fit_transform(X)

# A library from scipy used for performing hierarchical clustering.
# The linkage function is used to define how the distance between clusters is calculated.
# The 'ward' method minimizes the variance within clusters.
dendrogram = sch.dendrogram(sch.linkage(X, method='ward'))
plt.title('Dendrogram')
plt.xlabel('Customer')
plt.ylabel('Euclendian Distance')
plt.show()

# Agglomerative approach, where each observation starts as its own cluster,
# and pairs of clusters are merged step by step.
hc = AgglomerativeClustering(n_clusters=5, metric='euclidean', linkage='ward')
y_hc = hc.fit_predict(X)

# Plots the data points on a scatter plot
# Each color represents one of the 5 clusters,
# and the points are plotted based on the selected columns from the dataset
plt.scatter(X[y_hc == 0, 0], X[y_hc == 0, 1], s=100, c='red', label='Cluster1')
plt.scatter(X[y_hc == 1, 0], X[y_hc == 1, 1], s=100, c='blue', label='Cluster2')
plt.scatter(X[y_hc == 2, 0], X[y_hc == 2, 1], s=100, c='green', label='Cluster3')
plt.scatter(X[y_hc == 3, 0], X[y_hc == 3, 1], s=100, c='cyan', label='Cluster4')
plt.scatter(X[y_hc == 4, 0], X[y_hc == 4, 1], s=100, c='magenta', label='Cluster5')

plt.title('Cluster of Customer')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()