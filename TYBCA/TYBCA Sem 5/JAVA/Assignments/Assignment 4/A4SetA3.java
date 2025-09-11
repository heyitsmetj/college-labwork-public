import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class A4SetA3 {
    public static void main(String[] args) {
        
        JFrame frame = new JFrame("Count words and characters");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));

        
        JPanel topPanel = new JPanel(new FlowLayout());
        
        JLabel wordLabel = new JLabel("Words: 0");
        JLabel charLabel = new JLabel("Characters: 0");
        topPanel.add(wordLabel);
        topPanel.add(charLabel);

        
        JTextArea textArea = new JTextArea(8, 30);
        JScrollPane scrollPane = new JScrollPane(textArea,
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

     	scrollPane.setPreferredSize(new Dimension(300, 200));
		scrollPane.setMinimumSize(new Dimension(300, 200));
		scrollPane.setMaximumSize(new Dimension(300, 200));
		
        JButton countButton = new JButton("Count Words");
		countButton.setPreferredSize(new Dimension(200, 40));
		countButton.setMinimumSize(new Dimension(200, 40));
		countButton.setMaximumSize(new Dimension(200, 40));
        
        countButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String text = textArea.getText().trim();

                
                int charCount = text.length();

                
                int wordCount = 0;
                if (!text.isEmpty()) {
                    String[] words = text.split("\\s+");
                    wordCount = words.length;
                }

                
                wordLabel.setText("Words: " + wordCount);
                charLabel.setText("Characters: " + charCount);
            }
        });

        
        frame.add(topPanel);
        frame.add(scrollPane);
        frame.add(countButton);

        frame.setVisible(true);
        frame.setResizable(true);
    }
}
