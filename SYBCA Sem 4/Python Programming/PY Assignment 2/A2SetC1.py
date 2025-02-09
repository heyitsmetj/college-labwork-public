mystring = str(input("Enter a String: "))
print("Your String:", mystring)

newstr = ""

for word in mystring:
    if word.isalnum() or word.isspace():
        newstr += word

print(f"Converted String: {newstr}")
