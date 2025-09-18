import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class A4SetB1 
{
    public static void main(String args[]) 
    {
        final JFrame frame = new JFrame("Login");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(350, 200);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3, 2, 10, 10));

        final JLabel usernameLabel = new JLabel("Username:", JLabel.RIGHT);
        final JTextField usernameField = new JTextField(15);

        final JLabel passwordLabel = new JLabel("Password:", JLabel.RIGHT);
        final JPasswordField passwordField = new JPasswordField(15);

        final JButton loginButton = new JButton("Login");
        final JButton resetButton = new JButton("Reset");

        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(loginButton);
        panel.add(resetButton);

        frame.add(panel, BorderLayout.CENTER);

       
        final int[] attempts = {0};  
        final String correctUsername = "admin";   
        final String correctPassword = "1234";    

        loginButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                if (username.equals(correctUsername) && password.equals(correctPassword)) {
                    JOptionPane.showMessageDialog(frame, "Login Successful!");
                    attempts[0] = 0; 
                } else {
                    attempts[0]++;
                    if (attempts[0] < 3) {
                        JOptionPane.showMessageDialog(frame,
                                "Username or Password is incorrect!\nAttempts left: " + (3 - attempts[0]));
                    } else {
                        JOptionPane.showMessageDialog(frame, "Login Failed! You have exceeded 3 attempts.");
                        loginButton.setEnabled(false);
                    }
                }
            }
        });

        resetButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                usernameField.setText("");
                passwordField.setText("");
            }
        });

        frame.setVisible(true);
    }
}
