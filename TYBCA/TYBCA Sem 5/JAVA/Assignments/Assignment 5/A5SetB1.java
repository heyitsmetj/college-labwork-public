import java.sql.*;

public class A5SetB1 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, pass);

            // 1. Search all persons born in 1986
            String query1 = "SELECT * FROM Person WHERE birth_year = 1986";
            Statement stmt1 = con.createStatement();
            ResultSet rs1 = stmt1.executeQuery(query1);
            ResultSetMetaData rsmd1 = rs1.getMetaData();
            int col1 = rsmd1.getColumnCount();

            System.out.println("Persons born in 1986:");
            for (int i = 1; i <= col1; i++) System.out.print(rsmd1.getColumnName(i) + "\t");
            System.out.println();

            while (rs1.next()) {
                for (int i = 1; i <= col1; i++) {
                    System.out.print(rs1.getString(i) + "\t");
                }
                System.out.println();
            }

            // 2. Search all females born between 2000-2005
            String query2 = "SELECT * FROM Person WHERE gender = 'Female' AND birth_year BETWEEN 2000 AND 2005";
            Statement stmt2 = con.createStatement();
            ResultSet rs2 = stmt2.executeQuery(query2);
            ResultSetMetaData rsmd2 = rs2.getMetaData();
            int col2 = rsmd2.getColumnCount();

            System.out.println("\nFemales born between 2000 and 2005:");
            for (int i = 1; i <= col2; i++) System.out.print(rsmd2.getColumnName(i) + "\t");
            System.out.println();

            while (rs2.next()) {
                for (int i = 1; i <= col2; i++) {
                    System.out.print(rs2.getString(i) + "\t");
                }
                System.out.println();
            }

            rs1.close();
            rs2.close();
            stmt1.close();
            stmt2.close();
            con.close();

        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
