start = int(input("Enter the starting number: "))
end = int(input("Enter the ending number: "))

mylist = [(num, num * num) for num in range(start, end + 1)]

print(f"Your list of tuples: {mylist}")