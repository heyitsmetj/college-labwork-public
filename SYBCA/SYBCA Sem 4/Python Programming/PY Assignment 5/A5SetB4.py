sample_string = 'W3resource'

char_count = {}

for char in sample_string:
    char = char.lower()
    if char in char_count:
        char_count[char] += 1
    else:
        char_count[char] = 1

print("String:", sample_string)
print("Result:", char_count)
