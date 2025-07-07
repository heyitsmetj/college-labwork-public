tuple1 = (1, 2, 3, 4, 5, 5, 7, 1, 9, 2)
print("Your tuple:",tuple1)

key = int(input("Enter the element to be searched: "))

if key in tuple1:
    print(f"Item {key} is present in the tuple.")
else:
    print(f"Item {key} is NOT present in the tuple.")