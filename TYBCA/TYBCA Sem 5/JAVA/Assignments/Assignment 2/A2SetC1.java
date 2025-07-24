import java.util.*;

interface CreditCardInterface {
    void viewCreditAmount();
    void useCard(double amount);
    void payCredit(double amount);
    void increaseLimit(double amount);
    String getCardType(); 
}

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

class A2SetC1
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CreditCardInterface[] customers;

        System.out.print("Enter number of customers: ");
        int n = sc.nextInt();
        customers = new CreditCardInterface[n];

        for (int i = 0; i < n; i++) {
            System.out.print("\n1. Silver Card or 2. Gold Card? ");
            int choice = sc.nextInt();
            sc.nextLine(); 

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
