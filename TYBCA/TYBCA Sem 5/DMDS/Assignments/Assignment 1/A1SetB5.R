data(women)
w20 = subset(women,weight>120)
wasc = women[order(women$weight),]
print(w20)
print(wasc)