import java.io.*;
import java.util.Scanner;

class Employee {
	String name;
	float salary;

	public Employee() 
	{
		this.name = "NewEmployee";
		this.salary = 0;
	}

	public Employee(String n, float sal) 
	{
		this.name = n;
		this.salary = sal;
	}


	public void display() 
	{
		System.out.println("\nEmployee Name: " + name);
		System.out.println("Employee Salary: " + salary);
	}
}

class A1SetB2 {

	public static void main(String args[]) throws IOException {

		int size;
		String n;
		float sal;

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter size of array: ");
		size = sc.nextInt();

		Employee[] emp = new Employee[size];

		for (int i = 0; i < size; i++) 
		{
			sc.nextLine();
			System.out.print("\nEnter [" + (i+1) + "] Employee Name: ");
			n = sc.next();
			System.out.print("Enter [" + (i+1) + "] Employee Salary: ");
			sal = sc.nextFloat();

			emp[i] = new Employee(n, sal); 
		}

		System.out.println("\nEmployee Details:");

		for (int i = 0; i < size; i++) {
			emp[i].display();
		}

	}
}


