import java.io.*;
import java.util.*;

public class A3SetC1 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Set<Integer> numbers = new LinkedHashSet<>();
        Random rand = new Random();

        while (true) 
        {
            System.out.println("\n---- MENU ----");
            System.out.println("1. Load (Generate 10 random 2-digit numbers)");
            System.out.println("2. Save (Save numbers to file)");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) 
            {
                case 1:
                    numbers.clear();
                    while (numbers.size() < 10) 
                    {
                        int num = rand.nextInt(90) + 10;
                        numbers.add(num);
                    }
                    System.out.println("Generated Numbers: " + numbers);
                    break;

                case 2:
                    try {
                        FileWriter writer = new FileWriter("number.txt");
                        for (int num : numbers) 
                        {
                            writer.write(num + "\n");
                        }
                        writer.close();
                        System.out.println("Numbers saved to number.txt successfully!");
                    } 
                    catch (IOException e)
                    {
                        System.out.println("Error saving file: " + e.getMessage());
                    }
                    break;

                case 3:
                    System.out.println("Exiting program...");
                    sc.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice, please try again!");
            }
        }
    }
}
