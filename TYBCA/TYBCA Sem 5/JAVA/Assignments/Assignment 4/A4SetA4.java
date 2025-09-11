import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class A4SetA4 
{
    public static void main(String[] args) {
        
        JFrame frame = new JFrame("ComboBox Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        String languages[] = {"C", "C++", "C#", "Java", "PHP"};
        JComboBox<String> comboBox = new JComboBox<>(languages);
		comboBox.setPreferredSize(new Dimension(120, 40));
		comboBox.setMinimumSize(new Dimension(120, 40));
		comboBox.setMaximumSize(new Dimension(120, 40));
        
        JButton showButton = new JButton("Show");
		showButton.setPreferredSize(new Dimension(120, 40));
        showButton.setMinimumSize(new Dimension(120, 40));
		showButton.setMaximumSize(new Dimension(120, 40));
        
        JLabel resultLabel = new JLabel("Programming language Selected: ");

        
        showButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected = (String) comboBox.getSelectedItem();
                resultLabel.setText("Programming language Selected: " + selected);
            }
        });
        
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());
		
        
        frame.add(resultLabel);
        panel.add(comboBox);
        panel.add(showButton);
        frame.add(panel);

        frame.setVisible(true);
    }
}
