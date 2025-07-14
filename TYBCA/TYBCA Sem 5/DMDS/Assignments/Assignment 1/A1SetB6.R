data(mtcars)
print(mtcars)

mpg20 = subset(mtcars, mpg > 20)
mpg15 = subset(mtcars, mpg > 15.0)
g4 = subset(mtcars, gear == 4)

mpg20
mpg15
g4