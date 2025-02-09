tuple1 = (1, 2, 3, 4, 5, 5, 7, 1, 9, 2)
print("Your tuple:",tuple1)

mylist = []

for x in tuple1:
    if tuple1.count(x) > 1:
        if x not in mylist:
            mylist.append(x)

print("Repeated items of the tuple: ", mylist)