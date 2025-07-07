my_dict = {
    'x': list(range(11, 20)),
    'y': list(range(21, 30)),
    'z': list(range(31, 40))
}

fifth_x = my_dict['x'][4]
fifth_y = my_dict['y'][4]
fifth_z = my_dict['z'][4]

for key, value in my_dict.items():
    print(f"'{key}': {value}")
    
print(fifth_x)
print(fifth_y)
print(fifth_z)

for key, value in my_dict.items():
    print(f"{key} has value {value}")
