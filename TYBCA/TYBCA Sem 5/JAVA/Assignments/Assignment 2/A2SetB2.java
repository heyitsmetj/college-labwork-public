import java.io.*;
import java.util.Scanner;

class Employee 
{
    protected String name;
    protected float salary;

    Employee() 
    {
        this.name = "NewEmployee";
        this.salary = 00;
    }
    
    Employee(String name, float sal)
    {
    	this.name = name;
        this.salary = sal;
    }
	
    public void display() 
    {
        System.out.println("\nEmployee Name: " + this.name);
        System.out.println("\nEmployee Salary: " + this.salary);   
    }
}

class Developer extends Employee
{
	protected String projname;
	
	Developer()
	{
		super();
		this.projname = "NewProject";
	}
	
	Developer(String pname, String name, float sal)
	{
		super(name, sal);
		this.projname = pname;
	}
}

class Programmer extends Developer
{
	String proglang;
	
	Programmer()
	{
		super();
		this.proglang = "ProgLanguage";
	}
	
	Programmer(String plang, String pname, String name, float sal)
	{
		super(pname, name, sal);
		this.proglang = plang;
	}
	
	@Override
	public void display() 
    {
        System.out.println("\nEmployee Name: " + this.name);
        System.out.println("Employee Project Name: " + this.projname);
        System.out.println("Employee Programming Language: " + this.proglang);   
        System.out.println("Employee Salary: " + this.salary);
    }
}

public class A2SetB2
{
    public static void main(String[] args) 
    {
        Programmer p1 = new Programmer("C", "CPU Scheduling", "Rakesh", 40000);
        Programmer p2 = new Programmer("Python", "AI/ML", "Sujata", 80000);

        System.out.println("Displaying Details:");
    
        p1.display();
        p2.display();
    }
}
