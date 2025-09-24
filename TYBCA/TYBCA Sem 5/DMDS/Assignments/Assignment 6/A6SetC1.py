import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.cluster import AgglomerativeClustering
from scipy.cluster.hierarchy import dendrogram, linkage

iris = load_iris()
X = iris.data[:, :2]
y = iris.target

agg_clustering = AgglomerativeClustering(n_clusters=3, metric='euclidean', linkage='ward')

y_predicted = agg_clustering.fit_predict(X)

plt.figure(figsize=(10, 7))
plt.scatter(X[y_predicted == 0, 0], X[y_predicted == 0, 1], s=100, c='red', label='Cluster 1')
plt.scatter(X[y_predicted == 1, 0], X[y_predicted == 1, 1], s=100, c='blue', label='Cluster 2')
plt.scatter(X[y_predicted == 2, 0], X[y_predicted == 2, 1], s=100, c='green', label='Cluster 3')

centroids = np.array([X[y_predicted == i].mean(axis=0) for i in range(3)])
plt.scatter(centroids[:, 0], centroids[:, 1], s=300, c='black', marker='*', label='Centroids')

plt.title('Agglomerative Clustering on Iris Dataset')
plt.xlabel('Sepal Length (cm)')
plt.ylabel('Sepal Width (cm)')
plt.legend()
plt.grid(True)
plt.show()

linked = linkage(X, method='ward')

plt.figure(figsize=(10, 7))
dendrogram(linked,
           orientation='top',
           distance_sort='descending',
           show_leaf_counts=True)
plt.title('Dendrogram for Agglomerative Clustering')
plt.xlabel('Data Points')
plt.ylabel('Euclidean Distance')
plt.show()
