import java.sql.*;

class A5SetA2 {
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

            System.out.println("Number of columns: " + cols);
            System.out.println("------------------------------------------------");

            for (int i = 1; i <= cols; i++) {
                String colName = md.getColumnName(i);
                String colType = md.getColumnTypeName(i);
                System.out.println("Column " + i + ": " + colName + " (" + colType + ")");
            }

            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
