mystring = str(input("Enter a String: "))
print("Your String:", mystring)

newstr = ""

for i in range(len(mystring)):
    if(i % 2 == 0):
        newstr += mystring[i]

print(f"Converted String: {newstr}")