def Primecheck(num):
    for i in range(2, num):
        if num % i == 0:
            return False
    return True
    
num = 10

if(Primecheck(num)):
    print(f"{num} is Prime.")
else:
    print(f"{num} is NOT Prime.")