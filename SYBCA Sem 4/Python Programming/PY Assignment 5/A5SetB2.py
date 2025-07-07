d1={'a':100,'b':200,'c':300}
d2={'a':300,'b':200,'d':400}
result = {}

for key, value in d1.items():
    result[key] = value
    
for key, value in d2.items():
    if key in result:
        result[key] += value
    else:
        result[key] = value
                
print("d1:", d1)
print("d2:", d2)
print("Final Result:", result)