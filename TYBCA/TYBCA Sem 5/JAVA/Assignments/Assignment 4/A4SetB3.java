import javax.swing.*;
import java.awt.*;

public class A4SetB3 
{
    public static void main(String[] args) 
    {
        
        JFrame frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);
        frame.setLayout(new BorderLayout(10, 10));

        
        JTextField display = new JTextField();
        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);
        frame.add(display, BorderLayout.NORTH);

        
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4, 10, 10));

        
        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "+",
            "1", "2", "3", "-",
            "", "0", ".", "*"
        };

        for (String txt : buttons) 
        {
            if (txt.equals("")) 
            {
                buttonPanel.add(new JLabel()); 
            } 
            else 
            {
                buttonPanel.add(new JButton(txt));
            }
        }

        frame.add(buttonPanel, BorderLayout.CENTER);

        
        JButton clearButton = new JButton("Clear");
        JPanel bottomPanel = new JPanel();
        bottomPanel.add(clearButton);
        frame.add(bottomPanel, BorderLayout.SOUTH);

        
        frame.setVisible(true);
    }
}
