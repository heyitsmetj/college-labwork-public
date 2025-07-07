sets = {1,2,3,4,4}
print(f"Your Set: {sets}")

element = 6

print("Added element:", element)
sets.add(element)
print(f"Your New Set: {sets}")

print("Remove element:", element)
sets.discard(element)
print(f"Your New Set: {sets}")
