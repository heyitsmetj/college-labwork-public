num = int(input("Enter number to be reversed: "))

temp = num
rev_num = 0

while(temp != 0):
    rem = temp % 10
    rev_num = (rev_num * 10) + rem
    temp = temp // 10

print(num, "in reverse is:", rev_num)