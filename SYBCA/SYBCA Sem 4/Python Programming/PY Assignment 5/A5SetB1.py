color_dict = {'red':'#FF0000','green':'#008000','black':'#000000','white':'#FFFFFF'}

print("Normal Dictionary:")
for key, value in color_dict.items():
    print(f"{key}: {value}")

color_dict = dict(sorted(color_dict.items()))

print("\nSorted Dictionary:")
for key, value in color_dict.items():
    print(f"{key}: {value}")