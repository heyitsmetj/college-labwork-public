def numcheck(num):
    if num in range(1, 10):
        return True
    else:
        return False
    
num = 5

if(numcheck(num)):
    print(f"{num} is in range 1 - 10.")
else:
    print(f"{num} is NOT in range 1 - 10.")