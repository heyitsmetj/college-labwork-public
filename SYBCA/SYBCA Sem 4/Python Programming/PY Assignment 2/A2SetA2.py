mystring = str(input("Enter a String: "))
print("Your String:", mystring)

visited = ""

print(f"Frequency of each character:")
for x in mystring:
    count = 0
    if x not in visited:
        for y in mystring:
            if (x == y):
                count += 1
        visited += x
        print(f"[{x}]: {count}")
