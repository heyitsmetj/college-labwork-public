import java.io.*;
import java.util.*;

abstract class Staff {
    String name, address;

    Staff(String name, String address) {
        this.name = name;
        this.address = address;
    }

    abstract double calculateSalary();
    abstract void display();
    abstract String getType();
}

class FullTimeStaff extends Staff 
{
    String department;
    double salary, hra, da;

    FullTimeStaff(String name, String address, String department, double salary) 
    {
        super(name, address);
        this.department = department;
        this.salary = salary;
        this.hra = 0.08 * salary;
        this.da = 0.05 * salary;
    }

    double calculateSalary() {
        return salary + hra + da;
    }

    void display() {
        System.out.println("FullTimeStaff: " + name + ", " + address + ", Dept: " + department);
        System.out.println("Salary: " + calculateSalary());
        System.out.println();
    }

    String getType() {
        return "FullTime";
    }
}

class PartTimeStaff extends Staff {
    int hours;
    double rate;

    PartTimeStaff(String name, String address, int hours, double rate) {
        super(name, address);
        this.hours = hours;
        this.rate = rate;
    }

    double calculateSalary() {
        return hours * rate;
    }

    void display() {
        System.out.println("PartTimeStaff: " + name + ", " + address);
        System.out.println("Salary: " + calculateSalary());
        System.out.println();
    }

    String getType() {
        return "PartTime";
    }
}

class A2SetB3 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Staff[] staffList;
        
        System.out.print("Enter number of staff: ");
        int n = sc.nextInt();
        
        staffList = new Staff[n];

        for (int i = 0; i < n; i++) 
        {
            System.out.print("1. FullTime or 2. PartTime? ");
            int type = sc.nextInt();
            sc.nextLine();

            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Address: ");
            String address = sc.nextLine();

            if (type == 1) 
            {
                System.out.print("Department: ");
                String dept = sc.nextLine();
                System.out.print("Salary: ");
                double sal = sc.nextDouble();
                staffList[i] = new FullTimeStaff(name, address, dept, sal);
            } 
            else 
            {
                System.out.print("Hours: ");
                int hrs = sc.nextInt();
                System.out.print("Rate per hour: ");
                double rate = sc.nextDouble();
                staffList[i] = new PartTimeStaff(name, address, hrs, rate);
            }
        }

        System.out.println("\n--- FullTime Staff ---");
        for (Staff s : staffList) 
        {
            if (s.getType().equals("FullTime")) {
                s.display();
            }
        }

        System.out.println("--- PartTime Staff ---");
        for (Staff s : staffList) {
            if (s.getType().equals("PartTime")) {
                s.display();
            }
        }

        sc.close();
    }
}

