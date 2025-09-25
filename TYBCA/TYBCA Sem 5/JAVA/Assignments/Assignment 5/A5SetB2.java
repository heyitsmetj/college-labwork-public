import java.sql.*;

public class A5SetB2 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, pass);

            String updateQuery = "UPDATE Course SET Number_of_students = ? WHERE Name = ?";
            PreparedStatement pstmt = con.prepareStatement(updateQuery);

            pstmt.setInt(1, 1000);
            pstmt.setString(2, "BCA Science");

            int rows = pstmt.executeUpdate();
            System.out.println("Rows updated: " + rows);

            // Display updated table
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM Course");
            ResultSetMetaData rsmd = rs.getMetaData();
            int col = rsmd.getColumnCount();

            for (int i = 1; i <= col; i++) System.out.print(rsmd.getColumnName(i) + "\t");
            System.out.println();

            while (rs.next()) {
                for (int i = 1; i <= col; i++) {
                    System.out.print(rs.getString(i) + "\t");
                }
                System.out.println();
            }

            rs.close();
            stmt.close();
            pstmt.close();
            con.close();

        } catch (ClassNotFoundException e) {
            System.out.println("PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
