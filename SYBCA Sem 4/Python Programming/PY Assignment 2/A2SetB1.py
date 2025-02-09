mystring = input("Enter a String: ")
print("Your String:", mystring)

revstr = mystring[::-1]

print(revstr)

if(mystring.lower() == revstr.lower()):
    print(f"{mystring} is a Palindrome.")
else:
    print(f"{mystring} is NOT a Palindrome.")