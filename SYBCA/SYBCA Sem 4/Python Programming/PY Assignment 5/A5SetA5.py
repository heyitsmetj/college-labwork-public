myDict = {'a': 1, 'b': 2, 'c': 3, 'd': 4}

print("Original Dictionary:")
print(myDict)

removed_value = myDict.pop('b', None)

print("\nDictionary after removing key 'b':")
print(myDict)

myDict.pop('a', None)  

print("\nFinal Dictionary after removing key 'a':")
print(myDict)