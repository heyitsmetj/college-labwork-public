mystring = str(input("Enter a String: "))
print("Your String:", mystring)

if(len(mystring) < 2):
    print("Empty String")
    
else:
    result = mystring[:2] + mystring[-2:]
    print(f"Result String: {result}")