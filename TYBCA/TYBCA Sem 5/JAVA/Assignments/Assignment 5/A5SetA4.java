import java.sql.*;
import java.util.Scanner;

public class A5SetA4 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/your_database";
        String user = "your_username";
        String password = "your_password";

        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, password);

            String sql = "INSERT INTO Employee(ID, Name, Salary) VALUES (?, ?, ?)";
            PreparedStatement pstmt = con.prepareStatement(sql);

            System.out.print("Enter number of employees to insert: ");
            int n = sc.nextInt();

            for (int i = 0; i < n; i++) {
                System.out.println("Enter details for employee " + (i + 1));

                System.out.print("ID: ");
                int id = sc.nextInt();
                sc.nextLine();

                System.out.print("Name: ");
                String name = sc.nextLine();

                System.out.print("Salary: ");
                double salary = sc.nextDouble();

                pstmt.setInt(1, id);
                pstmt.setString(2, name);
                pstmt.setDouble(3, salary);

                pstmt.executeUpdate();
                System.out.println("Employee inserted successfully!\n");
            }

            pstmt.close();
            con.close();
            sc.close();

        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
