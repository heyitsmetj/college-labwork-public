import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class A4SetA1
{
	public static void main(String args[])
	{
		final JFrame frame = new JFrame("Login");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(350, 200);
		frame.setLayout(new BorderLayout());
		
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(3,2, 10, 10));
		
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
		
		loginButton.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String username = usernameField.getText();
				String password = new  String(passwordField.getPassword());
				
				JOptionPane.showMessageDialog(frame, "Login Clicked!\nUsername: " + username + "\nPassword: " + password);
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
