import java.io.*;
import java.util.Scanner;

class Employee 
{
    protected int id;
    protected String name;
    protected float salary;

    Employee() 
    {
        this.id = 00;
        this.name = "NewEmployee";
        this.salary = 00;
    }

    public void accept(Scanner sc) 
    {
        System.out.print("\nEnter Employee Id: ");
        this.id = sc.nextInt();
        
        sc.nextLine();
        
        System.out.print("\nEnter Employee Name: ");
        this.name = sc.nextLine();
        
        System.out.print("\nEnter Employee Salary: ");
        this.salary = sc.nextFloat();
    }
	
	
    public void display() 
    {
        System.out.println("\nEmployee Id: " + this.id);
        System.out.println("\nEmployee Name: " + this.name);
        System.out.println("\nEmployee Salary: " + this.salary);
    }
}

class Manager extends Employee
{
    private int bonus = 2000;
    private float totalsalary;

    Manager() 
    {
		super();
		this.totalsalary = (float) this.salary + this.bonus;
    }

    @Override
    public void accept(Scanner sc) 
    {
        System.out.print("\nEnter Employee Id: ");
        this.id = sc.nextInt();
        
        sc.nextLine();
        
        System.out.print("Enter Employee Name: ");
        this.name = sc.nextLine();
        
        System.out.print("Enter Employee Salary: ");
        this.salary = sc.nextFloat();
        
        this.totalsalary = (float) this.salary + this.bonus;
    }
	
	@Override
    public void display() 
    {
        System.out.println(this.id + "\t" + this.name + "\t"+ this.salary +"\t" + this.totalsalary);
    }
    
    static public void maxdisplay(Manager ms[], int n) 
    {
    	Manager max = new Manager();
    	
    	max = ms[0];
    	
    	for(int i = 0; i < n; i++)
    	{
    		if(ms[i].totalsalary > max.totalsalary)
    			max = ms[i];
    	}
    	
        /*System.out.println("\nEmployee with max total salary:");
        System.out.println("\nEmployee Id: " + max.id);
        System.out.println("Employee Name: " + max.name);
        System.out.println("Employee Salary: " + max.salary);
        System.out.println("Employee Total Salary (Salary + Bonus): " + (max.totalsalary));
        */
        
        System.out.println("\nEmployee with max total salary:");
        System.out.println("\nId\t" + "Name\t" + "Salary\t" + "Total Salary (Salary + Bonus)");
        System.out.println(max.id + "\t" + max.name + "\t"+ max.salary +"\t" + max.totalsalary);
        
        
    }
    
}


public class A2SetA3 
{
    public static void main(String[] args) 
    {
        int n = 3;
        Scanner sc = new Scanner(System.in);
        Manager[] ms = new Manager[n];
        
        for(int i = 0; i< n; i++)
        {
        	ms[i] = new Manager();
        	ms[i].accept(sc);
        }
        
        System.out.println("\nEmployee Details:\n\nId\t" + "Name\t" + "Salary\t" + "Total Salary (Salary + Bonus)");
        for(int i = 0; i< n; i++)
        {
        	ms[i].display();
        }
        
        Manager.maxdisplay(ms, n);
    }
}
