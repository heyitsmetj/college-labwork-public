def search_list(mylist, key):
    
    for i in range(n):
        if(mylist[i] == key):
            return i
            break
    
    return -1
    
n = int(input("How many elements do you want in the list?: "))
mylist = []
for i in range(n):
    mylist.append(int(input("Enter element: ")))
    
mylist.sort()

print("Your List: ", mylist)

key = int(input("Enter the value of element to be searched in the list: "))

index = search_list(mylist, key)

if(index != -1):
    print("Element", key, "found at Index:", index)
else:
    print("Element", key, "NOT found in the List.")