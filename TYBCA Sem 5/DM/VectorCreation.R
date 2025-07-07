v1 = c(1,2,3,4)
cat('Using c fucntion',v1,'\n')

v2 = 1:5
cat('Using colon',v2,'\n')

Seq_v = seq(1,4,length.out = 6)
cat("Using seq() function",Seq_v,'\n')

Seq_v2 = seq(1,4,by = 0.5)
cat("Using seq() function",Seq_v2,'\n')
 
X = c(1,5,10,1,12)
cat('Using subscript operator',X[2],'\n')

Y = c(14,18,12,11,17)
cat('Using combine() function',Y[c(4,1)],'\n')

Z = c(5,2,1,4,4,3)
cat('Using Logical Indexing',Z[Z>4],'\n')                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

char_vec = c("shubham" = 101,"ram" = 102, "varsha" = 103)
cat('Using character vecor',char_vec["ram"],'\n')

a = c(1,2,3,4,5,6)
a[c(TRUE,FALSE,TRUE,TRUE,FALSE,TRUE)]