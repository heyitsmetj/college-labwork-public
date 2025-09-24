
import pandas as pd
from apyori import apriori

# Load dataset
dataset = pd.read_csv("Groceries_dataset.csv")

# Group items by Member_number + Date to form transactions
transactions = dataset.groupby(['Member_number', 'Date'])['itemDescription'].apply(list).values.tolist()

# Apply Apriori algorithm
rules = apriori(transactions, min_support=0.004, min_confidence=0.2, min_lift=3, min_length=2)

# Convert generator to list
results = list(rules)

# Print total number of rules
print("Total Rules Found:", len(results))

# Print rules (first 10 for readability)
for item in results[:10]:
    pair = item[0]
    items = [x for x in pair]
    print("Rule: " + str(item[0]))
    print("Support: " + str(item[1]))
    print("Confidence: " + str(item[2][0][2]))
    print("Lift: " + str(item[2][0][3]))
    print("=====================================")