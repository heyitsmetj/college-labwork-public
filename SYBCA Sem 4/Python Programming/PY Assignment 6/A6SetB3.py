def nsum(num):
    if num == 0:
        return num
    return num + nsum(num - 1)
    
    
print(f"Sum of numbers from 0 to 10 is {nsum(10)}")