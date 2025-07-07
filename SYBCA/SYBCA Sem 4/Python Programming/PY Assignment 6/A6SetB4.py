numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

evens = filter(lambda x: x % 2 == 0, numbers)
odds = filter(lambda x: x % 2 != 0, numbers)

even_numbers = list(evens)
odd_numbers = list(odds)

print("List:", numbers)
print("Even numbers:", even_numbers)
print("odd numbers:", odd_numbers)
