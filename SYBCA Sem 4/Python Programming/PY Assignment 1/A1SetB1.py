n = int(input("Enter a number for prime number list: "))

print("Prime number till", n, ": ", end = " ")

i = 2

while(i < n + 1):
    j = 2
    is_prime = True
    while(j < i):
        if(i % j == 0):
            is_prime = False
            break
        j = j+1
    if is_prime:
        print(j, end = " ")
    i = i+1
