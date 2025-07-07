dic1 = {1: 10, 2: 20}
dic2 = {3: 30, 4: 40}
dic3 = {5: 50, 6: 60}

result = dic1.copy()
result.update(dic2) 
result.update(dic3)   

print(result)
