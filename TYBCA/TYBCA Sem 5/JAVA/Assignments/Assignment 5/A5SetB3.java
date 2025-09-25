import java.sql.*;
import java.util.Scanner;

public class A5SetB3 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        try (Scanner sc = new Scanner(System.in)) {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, pass);

            int choice;
            do {
                System.out.println("\n--- District Menu ---");
                System.out.println("1. Insert");
                System.out.println("2. Modify");
                System.out.println("3. Delete");
                System.out.println("4. Search");
                System.out.println("5. View All");
                System.out.println("6. Exit");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();
                sc.nextLine();

                switch (choice) {
                    case 1: // Insert
                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();
                        System.out.print("Enter Area: ");
                        double area = sc.nextDouble();
                        System.out.print("Enter Population: ");
                        int population = sc.nextInt();
                        sc.nextLine();

                        String insertQuery = "INSERT INTO District(Name, Area, Population) VALUES (?, ?, ?)";
                        try (PreparedStatement pstmt = con.prepareStatement(insertQuery)) {
                            pstmt.setString(1, name);
                            pstmt.setDouble(2, area);
                            pstmt.setInt(3, population);
                            pstmt.executeUpdate();
                            System.out.println("Record inserted successfully!");
                        }
                        break;

                    case 2: // Modify
                        System.out.print("Enter Name of district to modify: ");
                        String modName = sc.nextLine();
                        System.out.print("Enter new Area: ");
                        double newArea = sc.nextDouble();
                        System.out.print("Enter new Population: ");
                        int newPop = sc.nextInt();
                        sc.nextLine();

                        String updateQuery = "UPDATE District SET Area=?, Population=? WHERE Name=?";
                        try (PreparedStatement pstmt = con.prepareStatement(updateQuery)) {
                            pstmt.setDouble(1, newArea);
                            pstmt.setInt(2, newPop);
                            pstmt.setString(3, modName);
                            int rows = pstmt.executeUpdate();
                            if (rows > 0) System.out.println("Record updated successfully!");
                            else System.out.println("District not found.");
                        }
                        break;

                    case 3: // Delete
                        System.out.print("Enter Name of district to delete: ");
                        String delName = sc.nextLine();
                        String deleteQuery = "DELETE FROM District WHERE Name=?";
                        try (PreparedStatement pstmt = con.prepareStatement(deleteQuery)) {
                            pstmt.setString(1, delName);
                            int rows = pstmt.executeUpdate();
                            if (rows > 0) System.out.println("Record deleted successfully!");
                            else System.out.println("District not found.");
                        }
                        break;

                    case 4: // Search
                        System.out.print("Enter Name of district to search: ");
                        String searchName = sc.nextLine();
                        String searchQuery = "SELECT * FROM District WHERE Name=?";
                        try (PreparedStatement pstmt = con.prepareStatement(searchQuery)) {
                            pstmt.setString(1, searchName);
                            ResultSet rs = pstmt.executeQuery();
                            ResultSetMetaData rsmd = rs.getMetaData();
                            int col = rsmd.getColumnCount();

                            if (!rs.isBeforeFirst()) System.out.println("District not found.");
                            else {
                                for (int i = 1; i <= col; i++) System.out.print(rsmd.getColumnName(i) + "\t");
                                System.out.println();
                                while (rs.next()) {
                                    for (int i = 1; i <= col; i++) System.out.print(rs.getString(i) + "\t");
                                    System.out.println();
                                }
                            }
                        }
                        break;

                    case 5: // View All
                        String viewQuery = "SELECT * FROM District";
                        try (Statement stmt = con.createStatement()) {
                            ResultSet rs = stmt.executeQuery(viewQuery);
                            ResultSetMetaData rsmd = rs.getMetaData();
                            int col = rsmd.getColumnCount();
                            for (int i = 1; i <= col; i++) System.out.print(rsmd.getColumnName(i) + "\t");
                            System.out.println();
                            while (rs.next()) {
                                for (int i = 1; i <= col; i++) System.out.print(rs.getString(i) + "\t");
                                System.out.println();
                            }
                        }
                        break;

                    case 6: // Exit
                        System.out.println("Exiting program...");
                        break;

                    default:
                        System.out.println("Invalid choice. Try again.");
                }

            } while (choice != 6);

            con.close();

        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
