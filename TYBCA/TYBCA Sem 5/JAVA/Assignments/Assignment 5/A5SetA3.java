import java.sql.*;

public class A5SetA3 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        String query = "SELECT * FROM Country WHERE Region = 'West'";

        try {
        
            Class.forName("org.postgresql.Driver");

           
            Connection con = DriverManager.getConnection(url, user, pass);

           
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);

          
            ResultSetMetaData rsmd = rs.getMetaData();
            int columnCount = rsmd.getColumnCount();

           
            for (int i = 1; i <= columnCount; i++) {
                System.out.print(rsmd.getColumnName(i) + "\t");
            }
            System.out.println();

         
            while (rs.next()) {
                for (int i = 1; i <= columnCount; i++) {
                    System.out.print(rs.getString(i) + "\t");
                }
                System.out.println();
            }

            rs.close();
            stmt.close();
            con.close();

        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
