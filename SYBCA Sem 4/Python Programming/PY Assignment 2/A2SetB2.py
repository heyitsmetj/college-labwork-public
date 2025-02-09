mystring = input("Enter a String: ")
print("Your String:", mystring)

Digits = 0
Letters = 0

for x in mystring:
    if x.isalpha():
        Letters += 1
    
    if x.isdigit():
        Digits += 1
        
print(f"Result: Digits: {Digits}, Letters: {Letters}")