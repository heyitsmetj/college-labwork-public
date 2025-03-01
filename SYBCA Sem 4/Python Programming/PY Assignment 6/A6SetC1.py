def outer_func(a, b):
    def inner_func(a, b):
        return a + b
    
    addition = inner_func(a, b)
    
    return addition + 5

result = outer_func(3, 4)
print(result)
