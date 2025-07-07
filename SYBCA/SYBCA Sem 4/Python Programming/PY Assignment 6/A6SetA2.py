def lprod(mylist):
    result = 1
    for num in mylist:
        result *= num
    return result
    
mylist = [8, 2, 3, -1, 7]
print(f"Product of elements of list: {mylist} is {lprod(mylist)}")