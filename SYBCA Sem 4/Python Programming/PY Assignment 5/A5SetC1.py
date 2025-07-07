from collections import defaultdict

keys = ['Class-V', 'Class-VI', 'Class-VII', 'Class-VIII']
values = [1, 2, 2, 3]

dict_result = defaultdict(set)

for key, value in zip(keys, values):
    dict_result[key].add(value)

print(dict_result)
