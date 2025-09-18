import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class A4SetB2 {
    public static void main(String[] args) {

        JFrame frame = new JFrame("Vaccination Details");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

        JLabel title = new JLabel("Vaccination Details", JLabel.CENTER);
        mainPanel.add(title);

        JPanel formPanel = new JPanel(new GridLayout(2, 1, 10, 10));

        JPanel topPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JLabel nameLabel = new JLabel("Name:", JLabel.RIGHT);
        JTextField nameField = new JTextField(20);
        nameField.setPreferredSize(new Dimension(120, 40));
        nameField.setMinimumSize(new Dimension(120, 40));
        nameField.setMaximumSize(new Dimension(120, 40));

        topPanel.add(nameLabel);
        topPanel.add(nameField);

        mainPanel.add(topPanel);

        JPanel dosePanel = new JPanel(new GridLayout(2, 1));
        JCheckBox dose1 = new JCheckBox("1st Dose");
        JCheckBox dose2 = new JCheckBox("2nd Dose");
        dosePanel.add(dose1);
        dosePanel.add(dose2);

        JPanel vaccinePanel = new JPanel();
        vaccinePanel.setLayout(new BoxLayout(vaccinePanel, BoxLayout.Y_AXIS));
        JRadioButton covishield = new JRadioButton("Covishield");
        JRadioButton covaxin = new JRadioButton("Covaxin");
        JRadioButton sputnik = new JRadioButton("Sputnik V");

        ButtonGroup vaccineGroup = new ButtonGroup();
        vaccineGroup.add(covishield);
        vaccineGroup.add(covaxin);
        vaccineGroup.add(sputnik);

        vaccinePanel.add(covishield);
        vaccinePanel.add(covaxin);
        vaccinePanel.add(sputnik);

        formPanel.add(new JLabel("Dose", JLabel.CENTER));
        formPanel.add(new JLabel("Vaccine", JLabel.CENTER));
        formPanel.add(dosePanel);
        formPanel.add(vaccinePanel);

        mainPanel.add(formPanel);

        JPanel resultPanel = new JPanel(new GridLayout(2, 1));

        JLabel result1 = new JLabel("Name : __________________   1st Dose: ______   2nd Dose: ______");
        JLabel result2 = new JLabel("Vaccine: __________________");

        resultPanel.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        resultPanel.add(result1);
        resultPanel.add(result2);

        mainPanel.add(resultPanel);

        JButton submitButton = new JButton("Submit");
        mainPanel.add(submitButton);

        submitButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) 
            {
                String name = nameField.getText().trim();
                String d1 = dose1.isSelected() ? "Yes" : "No";
                String d2 = dose2.isSelected() ? "Yes" : "No";

                String vaccine = "None";
                if (covishield.isSelected()) vaccine = "Covishield";
                else if (covaxin.isSelected()) vaccine = "Covaxin";
                else if (sputnik.isSelected()) vaccine = "Sputnik V";

                result1.setText("Name : " + name + "   1st Dose: " + d1 + "   2nd Dose: " + d2);
                result2.setText("Vaccine: " + vaccine);
            }
        });

        frame.add(mainPanel);
        frame.setVisible(true);
    }
}
