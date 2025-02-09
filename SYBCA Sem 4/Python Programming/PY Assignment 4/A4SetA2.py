sets = {1,2,3,4,4}
print(f"Your Set: {sets}")

print("Removed element:", sets.pop())

print(f"Your New Set: {sets}")


print("\nError for empty set.")

sets = {}
print(f"\nYour Set: {sets}\n")
sets.pop()