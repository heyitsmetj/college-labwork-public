import numpy as np

# Step 1: Generate 200 samples from N(100, 5)
data = np.random.normal(loc=100, scale=5, size=200)

# Step 2: Compute Q1 (25th percentile) and Q3 (75th percentile)
Q1 = np.percentile(data, 25)
Q3 = np.percentile(data, 75)

# Step 3: Compute IQR
IQR = Q3 - Q1

# Step 4: Define bounds for outliers
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR

# Step 5: Identify outliers
outliers = data[(data < lower_bound) | (data > upper_bound)]

# Step 6: Print number of outliers
print("Number of outliers:", len(outliers))
