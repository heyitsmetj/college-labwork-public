package Series;

public class CubeSeries 
{
    public void display(int n)
    {
        System.out.print("\nCube Series: ");

        for (int i = 1; i <= n; i++) 
        {
            System.out.print((i * i * i) + " ");
        }
    }
}
