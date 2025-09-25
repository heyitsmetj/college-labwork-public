import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;

public class A5SetC1 {
    public static void main(String[] args) {
        String url = "jdbc:postgresql://localhost:5432/te2202"; 
        String user = "postgres"; 
        String pass = "12345"; 

        JFrame frame = new JFrame("Student Details");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 300);

        DefaultTableModel model = new DefaultTableModel();
        JTable table = new JTable(model);
        JScrollPane scroll = new JScrollPane(table);
        frame.add(scroll);

        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(url, user, pass);

            String query = "SELECT * FROM Student";
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            ResultSetMetaData rsmd = rs.getMetaData();
            int columnCount = rsmd.getColumnCount();

            // Add columns dynamically
            for (int i = 1; i <= columnCount; i++) {
                model.addColumn(rsmd.getColumnName(i));
            }

            // Add rows dynamically
            while (rs.next()) {
                Object[] row = new Object[columnCount];
                for (int i = 1; i <= columnCount; i++) {
                    row[i - 1] = rs.getObject(i);
                }
                model.addRow(row);
            }

            rs.close();
            stmt.close();
            con.close();

        } catch (ClassNotFoundException e) {
            JOptionPane.showMessageDialog(frame, "PostgreSQL Driver not found!");
        } catch (SQLException e) {
            e.printStackTrace();
        }

        frame.setVisible(true);
    }
}
