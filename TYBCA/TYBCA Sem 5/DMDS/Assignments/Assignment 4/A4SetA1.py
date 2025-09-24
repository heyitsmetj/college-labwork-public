import pandas as pd
from apyori import apriori

# Load the data
data = pd.read_csv("iris.csv", header=None)

# Discretize the first 4 numeric columns
data_binned = data.copy()
for col in range(4):
    data_binned[col] = pd.cut(data[col], bins=3, labels=['low', 'medium', 'high'])

# Convert each row into a list (transaction)
records = []
for i in range(len(data_binned)):
    records.append([str(x) for x in data_binned.iloc[i]])

# Run Apriori
association_rules = apriori(records, min_support=0.04, min_confidence=0.3, min_lift=1.2, min_length=2)
association_result = list(association_rules)

print(f"Total rules found: {len(association_result)}\n")

# Print the rules
for item in association_result:
    for rule in item.ordered_statistics:
        lhs = ', '.join(rule.items_base) if rule.items_base else "None"
        rhs = ', '.join(rule.items_add) if rule.items_add else "None"
        print(f"Rule: {lhs} -> {rhs}")
        print(f"Support: {item.support:.4f}")
        print(f"Confidence: {rule.confidence:.4f}")
        print(f"Lift: {rule.lift:.4f}")
        print("----------------------------------------")

