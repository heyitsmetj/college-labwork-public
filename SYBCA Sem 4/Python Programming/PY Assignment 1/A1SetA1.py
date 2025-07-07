mylist = []

size = int(input("How many inputs do you want to enter?: "))

for i in range(size):
    mylist.append(int(input("Enter element: ")))

count = len(mylist)

total = 0

for x in mylist:
    total += int(x)

avg = total // len(mylist)

print(mylist)
print("Average is: ",avg)