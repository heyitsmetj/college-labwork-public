import pandas as pd
from apyori import apriori

# Load the dataset.
# The `header=None` argument is used because the first row contains labels
# that are not standard column names, but a header with empty cells.
df = pd.read_csv('Shopping.csv', header=None)

# Build a list of transactions from the DataFrame.
# This iterates through each row and creates a list of all non-empty items.
transactions = []
# Start from the second row to skip the header.
for i in range(1, len(df)):
    transaction = [str(df.values[i, j]) for j in range(len(df.columns)) if pd.notna(df.values[i, j])]
    if transaction:
        transactions.append(transaction)

# Apply the Apriori algorithm to find association rules.
# Adjust the `min_support`, `min_confidence`, and `min_lift` parameters
# to fine-tune the results.
rules = apriori(
    transactions,
    min_support=0.2,
    min_confidence=0.5,
    min_lift=1.2,
    min_length=2
)

# Convert the generator of rules into a list for easier processing.
results = list(rules)

# Print the association rules in a readable format.
print("--- Association Rules Found ---")
if not results:
    print("No rules found. Try lowering your min_support or min_confidence values.")
else:
    for item in results:
        # Extract the items in the itemset
        items_list = [x for x in item.items]
        
        # Extract the support value
        support = item.support
        
        # Extract the ordered statistics (rules)
        for ordered_stat in item.ordered_statistics:
            base = [x for x in ordered_stat.items_base]
            add = [x for x in ordered_stat.items_add]
            confidence = ordered_stat.confidence
            lift = ordered_stat.lift
            
            # Print the rule and its metrics
            print(f"Rule: {base} -> {add}")
            print(f"Support: {support:.4f}")
            print(f"Confidence: {confidence:.4f}")
            print(f"Lift: {lift:.4f}")
            print("-----------------------------")
