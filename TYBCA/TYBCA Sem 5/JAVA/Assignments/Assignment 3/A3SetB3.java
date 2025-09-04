import java.io.*;
import java.util.Scanner;

public class A3SetB3 {
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        String filename = "customers.dat";

        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(filename))) 
        {
            System.out.print("Enter number of customers: ");
            int n = sc.nextInt();
            sc.nextLine();

            for (int i = 1; i <= n; i++)
            {
                System.out.println("\nEnter details for customer " + i);

                System.out.print("Customer ID: ");
                int c_id = sc.nextInt();
                sc.nextLine();

                System.out.print("Customer Name: ");
                String cname = sc.nextLine();

                System.out.print("Address: ");
                String address = sc.nextLine();

                System.out.print("Mobile No: ");
                String mobile_no = sc.nextLine();

                dos.writeInt(c_id);
                dos.writeUTF(cname);
                dos.writeUTF(address);
                dos.writeUTF(mobile_no);
            }
            System.out.println("\nCustomer details saved successfully!");
        } catch (IOException e) 
        {
            System.out.println("Error while writing: " + e.getMessage());
        }

        System.out.println("\nReading customer details from file:");
        try (DataInputStream dis = new DataInputStream(new FileInputStream(filename))) 
        {
            while (true) 
            { 
                int c_id = dis.readInt();
                String cname = dis.readUTF();
                String address = dis.readUTF();
                String mobile_no = dis.readUTF();

                System.out.println("\nCustomer ID: " + c_id);
                System.out.println("Name: " + cname);
                System.out.println("Address: " + address);
                System.out.println("Mobile No: " + mobile_no);
            }
        } 
        catch (EOFException e) 
        {
            System.out.println("\nAll customer details displayed.");
        } 
        catch (IOException e) 
        {
            System.out.println("Error while reading: " + e.getMessage());
        }

        sc.close();
    }
}
