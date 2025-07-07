import sys
num = int(sys.argv[1])
if(num >= 1 and num <= 50):
    print("Entered number:", num, "is inside range(0 - 51).")
else:
    print("Number:", num, "out of range(1 - 50), Try Again!")

# Use this in Jupyter Notebook

# import sys

# sys.argv = ["test.py"]
# sys.argv[1] = int(input("Enter number to check: "))

# num = sys.argv[1]
# if(num >= 1 and num <= 50):
#     print("Entered number:", num, "is inside range(0 - 51).")
# else:
#     print("Number:", num, "out of range(1 - 50), Try Again!")