import java.sql.*;

public class A5SetA1 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        try {
            
            Class.forName("org.postgresql.Driver");

            
            Connection con = DriverManager.getConnection(url, user, pass);

            
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM Person");

            
            ResultSetMetaData md = rs.getMetaData();
            int cols = md.getColumnCount();

          
            for (int i = 1; i <= cols; i++) {
                System.out.print(md.getColumnName(i) + "\t");
            }
            System.out.println();

           
            while (rs.next()) {
                for (int i = 1; i <= cols; i++) {
                    System.out.print(rs.getString(i) + "\t");
                }
                System.out.println();
            }

            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
