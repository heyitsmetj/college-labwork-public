package Series;

public class FibSeries 
{
    public void display(int n)
    {
        int a = 0, b = 1, c;
        
        System.out.println("Fibonacci Series:");
        
        for (int i = 0; i < n; i++) 
        {
            System.out.print(a + " ");
            c = a + b;
            a = b;
            b = c;
        }
    }
}
