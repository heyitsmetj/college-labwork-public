set1 =  {1, 2, 3, 4, 5}
set2 = {3, 4, 5, 6, 7, 8}

print(f"Your Set1: {set1}")
print(f"Your Set2: {set2}")


print(f"Set Difference: {set1.difference(set2)}")
print(f"Set Symmetric Difference: {set1.symmetric_difference(set2)}")
print(f"Set Intersection: {set1.intersection(set2)}")
print(f"Set Union: {set1.union(set2)}")
print(f"Set Disjoint: {set1.isdisjoint(set2)}")
print(f"Set Subset: {set1.issubset(set2)}")
print(f"Set Superset: {set1.issuperset(set2)}")
