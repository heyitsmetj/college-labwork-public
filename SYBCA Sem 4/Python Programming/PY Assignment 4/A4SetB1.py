vowels = {'a', 'e', 'i', 'o', 'u'}

mystr = input("Enter a string: ")

string_set = set(mystr.lower())

if (vowels.issubset(string_set)):
    print("String contains all the vowels.")
else:
    print("String does not contain all the vowels.")