import java.io.*;

class Hello
{
	public static void main(String args[])
	{
		System.out.println("Hello, Welcome to Java!");
	}
}

import java.util.*;

// Abstract Staff class
abstract class Staff {
    String name, address;

    Staff(String name, String address) {
        this.name = name;
        this.address = address;
    }

    abstract double calculateSalary();
    abstract void display();
    abstract String getType(); // NEW: to avoid instanceof
}

// FullTimeStaff class
class FullTimeStaff extends Staff {
    String department;
    double salary, hra, da;

    FullTimeStaff(String name, String address, String department, double salary) {
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

// PartTimeStaff class
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

// Main class
public class StaffMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Staff[] staffList;
        System.out.print("Enter number of staff: ");
        int n = sc.nextInt();
        staffList = new Staff[n];

        for (int i = 0; i < n; i++) {
            System.out.print("1. FullTime or 2. PartTime? ");
            int type = sc.nextInt();
            sc.nextLine(); // consume newline

            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Address: ");
            String address = sc.nextLine();

            if (type == 1) {
                System.out.print("Department: ");
                String dept = sc.nextLine();
                System.out.print("Salary: ");
                double sal = sc.nextDouble();
                staffList[i] = new FullTimeStaff(name, address, dept, sal);
            } else {
                System.out.print("Hours: ");
                int hrs = sc.nextInt();
                System.out.print("Rate per hour: ");
                double rate = sc.nextDouble();
                staffList[i] = new PartTimeStaff(name, address, hrs, rate);
            }
        }

        System.out.println("\n--- FullTime Staff ---");
        for (Staff s : staffList) {
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

import java.util.*;

// Abstract Staff class
abstract class Staff {
    String name, address;

    Staff(String name, String address) {
        this.name = name;
        this.address = address;
    }

    abstract double calculateSalary();
    abstract void display();
    abstract String getType(); // NEW: to avoid instanceof
}

// FullTimeStaff class
class FullTimeStaff extends Staff {
    String department;
    double salary, hra, da;

    FullTimeStaff(String name, String address, String department, double salary) {
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

// PartTimeStaff class
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

// Main class
public class StaffMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Staff[] staffList;
        System.out.print("Enter number of staff: ");
        int n = sc.nextInt();
        staffList = new Staff[n];

        for (int i = 0; i < n; i++) {
            System.out.print("1. FullTime or 2. PartTime? ");
            int type = sc.nextInt();
            sc.nextLine(); // consume newline

            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Address: ");
            String address = sc.nextLine();

            if (type == 1) {
                System.out.print("Department: ");
                String dept = sc.nextLine();
                System.out.print("Salary: ");
                double sal = sc.nextDouble();
                staffList[i] = new FullTimeStaff(name, address, dept, sal);
            } else {
                System.out.print("Hours: ");
                int hrs = sc.nextInt();
                System.out.print("Rate per hour: ");
                double rate = sc.nextDouble();
                staffList[i] = new PartTimeStaff(name, address, hrs, rate);
            }
        }

        System.out.println("\n--- FullTime Staff ---");
        for (Staff s : staffList) {
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

import java.util.*;

// Interface
interface CreditCardInterface {
    void viewCreditAmount();
    void useCard(double amount);
    void payCredit(double amount);
    void increaseLimit(double amount);
    String getCardType(); // Replaces instanceof
}

// SilverCardCustomer class
class SilverCardCustomer implements CreditCardInterface {
    String name;
    String cardNumber;
    double creditAmount = 0;
    double creditLimit = 50000;

    SilverCardCustomer(String name, String cardNumber) {
        this.name = name;
        this.cardNumber = cardNumber;
    }

    public void viewCreditAmount() {
        System.out.println(name + " (" + getCardType() + "): Used ₹" + creditAmount + " / ₹" + creditLimit);
    }

    public void useCard(double amount) {
        if (creditAmount + amount <= creditLimit) {
            creditAmount += amount;
            System.out.println("Used ₹" + amount + " successfully.");
        } else {
            System.out.println("Use failed: Limit exceeded.");
        }
    }

    public void payCredit(double amount) {
        if (amount <= creditAmount) {
            creditAmount -= amount;
            System.out.println("Paid ₹" + amount + " successfully.");
        } else {
            System.out.println("Payment failed: More than used amount.");
        }
    }

    public void increaseLimit(double amount) {
        System.out.println("Limit increase not allowed for Silver Card.");
    }

    public String getCardType() {
        return "Silver";
    }
}

// GoldCardCustomer class
class GoldCardCustomer extends SilverCardCustomer {
    int increaseCount = 0;

    GoldCardCustomer(String name, String cardNumber) {
        super(name, cardNumber);
        this.creditLimit = 100000;
    }

    @Override
    public void increaseLimit(double amount) {
        if (increaseCount < 3 && amount <= 5000) {
            creditLimit += amount;
            increaseCount++;
            System.out.println("Limit increased by ₹" + amount + ". New limit: ₹" + creditLimit);
        } else {
            System.out.println("Limit increase failed (max 3 times, ₹5000 each).");
        }
    }

    @Override
    public String getCardType() {
        return "Gold";
    }
}

// Main class
public class CreditCardProgram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CreditCardInterface[] customers;

        System.out.print("Enter number of customers: ");
        int n = sc.nextInt();
        customers = new CreditCardInterface[n];

        for (int i = 0; i < n; i++) {
            System.out.print("\n1. Silver Card or 2. Gold Card? ");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            System.out.print("Enter name: ");
            String name = sc.nextLine();
            System.out.print("Enter 16-digit card number: ");
            String cardNumber = sc.nextLine();

            if (choice == 1)
                customers[i] = new SilverCardCustomer(name, cardNumber);
            else
                customers[i] = new GoldCardCustomer(name, cardNumber);

            System.out.print("Use card for ₹: ");
            double useAmt = sc.nextDouble();
            customers[i].useCard(useAmt);

            System.out.print("Pay ₹: ");
            double payAmt = sc.nextDouble();
            customers[i].payCredit(payAmt);

            System.out.print("Want to increase limit? (₹): ");
            double incAmt = sc.nextDouble();
            customers[i].increaseLimit(incAmt);
        }

        // Display Silver and Gold cardholders separately
        System.out.println("\n--- Silver Card Customers ---");
        for (CreditCardInterface c : customers) {
            if (c.getCardType().equals("Silver")) c.viewCreditAmount();
        }

        System.out.println("\n--- Gold Card Customers ---");
        for (CreditCardInterface c : customers) {
            if (c.getCardType().equals("Gold")) c.viewCreditAmount();
        }

        sc.close();
    }
}