def revstr(s):
    i = len(s) - 1
    while(i >= 0):
        yield s[i]
        i -= 1

    
string = "Hello"
print(f"Normal String: {string}")

revstring = revstr(string);

print(f"Reversed String:","".join(revstring))
