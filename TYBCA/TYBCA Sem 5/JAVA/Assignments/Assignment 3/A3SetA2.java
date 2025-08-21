import java.util.*;
import java.io.*;

class A3SetA2 
{
    public static void main(String args[]) 
    {
        Hashtable<String, Float> emps = new Hashtable<>();

        int n;
        String name;
        float salary;

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the number of employees: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            System.out.println("\nEnter Employee[" + i + "]:");
            sc.nextLine();

            System.out.print("Enter Employee[" + i + "] Name: ");
            name = sc.nextLine();

            System.out.print("Enter Employee[" + i + "] Salary: ");
            salary = sc.nextFloat();

            emps.put(name, salary); 
        }

        System.out.println("\nEmployee Details:");
        System.out.println("\nName\tSalary\n");

        for (Map.Entry<String, Float> entry : emps.entrySet()) 
        {
            System.out.println(entry.getKey() + "\t" + entry.getValue());
        }

        System.out.println("\nEmployee Details:\n" + emps);

        sc.nextLine();
        System.out.print("\nYour Search Key: ");
        String key = sc.nextLine();

        if (emps.containsKey(key)) 
        {
            System.out.println("Employee Name: " + key);
            System.out.println("Employee Salary: " + emps.get(key));
        } 
        else 
        {
            System.out.println(key + " is NOT present in the Hash Table.");
        }
    }
}

