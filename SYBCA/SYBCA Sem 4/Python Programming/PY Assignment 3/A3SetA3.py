start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))

mylist = [(num) for num in range(start, end + 1)]

mytup = tuple(mylist)

print(f"Your Tuple: {mytup}")
print(f"One item of your Tuple: {mytup[1]}")