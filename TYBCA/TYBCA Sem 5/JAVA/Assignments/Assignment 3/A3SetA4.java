import java.io.*;

class A3SetA4 {
    public static void main(String args[])  
    {
        try 
        {
            FileReader reader = new FileReader("test.txt");
            int ch;
            int lcount = 0, wcount = 0, ccount = 0;

            System.out.println("Content of File: ");
            while ((ch = reader.read()) != -1) 
            {
                char character = (char) ch;
                System.out.print(character);
                
                ccount++;

                if (character == '\n') 
                {
                    lcount++;
                }

                if (character == '\n' || character == ' ')
                        wcount++;
            }
            
            reader.close();

            if (ccount > 0 && (char) ch != '\n') 
            {
                lcount++;
            }
			
			lcount--;
            System.out.println("\n\nNumber of lines: " + lcount);
            System.out.println("Number of words: " + wcount);
            System.out.println("Number of characters: " + ccount);

        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("File not found.");
        } 
        catch (IOException e) 
        {
            System.out.println("Error reading file.");
        }
    }
}

