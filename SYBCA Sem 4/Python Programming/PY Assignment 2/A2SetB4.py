mystring = str(input("Enter a String: "))
print("Your String:", mystring)

frequency = {}

for x in mystring.split():
    if x in frequency:
        frequency[x] += 1
    else:
        frequency[x] = 1

print(f"Frequency of each word: {frequency}")
