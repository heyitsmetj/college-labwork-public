def showEmployee(name, sal = 9000):
    print(f"Employee Name: {name}")
    print(f"Employee Salary: Rs.{sal}")
    
name = "Rajesh Kumar"

print("Details of Employee with passed salary:")
showEmployee(name, 5000)

print("\nDetails of Employee without passed salary:")
showEmployee(name)