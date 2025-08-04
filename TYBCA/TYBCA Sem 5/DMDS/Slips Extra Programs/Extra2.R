a <- 0
b <- 1

cat(a, b)

for (i in 3:10) {
  c <- a + b
  cat(" ", c)
  a <- b         
  b <- c        
}

