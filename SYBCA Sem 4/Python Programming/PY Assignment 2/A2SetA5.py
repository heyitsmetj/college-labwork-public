mystring1 = input("Enter a String 1: ")
print("Your String 1:", mystring1)

mystring2 = input("Enter a String 2: ")
print("Your String 2:", mystring2)

result = mystring1.replace(mystring1[0:1],mystring2[0:1]) + " " + mystring2.replace(mystring2[0:1],mystring1[0:1]) 

print(f"Result String: {result}")

