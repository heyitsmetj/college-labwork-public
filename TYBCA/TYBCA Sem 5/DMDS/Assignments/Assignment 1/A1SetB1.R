revnum = function(num)
{
  temp = num
  rev = 0
  sum_digits = 0
  
  while (temp != 0) 
  {
    rem = temp %% 10
    rev = (rev * 10) + rem
    sum_digits = sum_digits + rem
    temp = floor(temp / 10)
  }
  
  cat("Original number:", num, "\n")
  cat("Reversed number:", rev, "\n")
  cat("Sum of digits:", sum_digits, "\n")
}

revnum(102)
