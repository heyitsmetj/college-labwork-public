import Series.CubeSeries;
import Series.SquareSeries;
import Series.FibSeries;
import java.util.*;

public class A2SetA2 {
    public static void main(String[] args) 
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number(n): ");
		n = sc.nextInt();
		
        FibSeries fib = new FibSeries();
        CubeSeries cube = new CubeSeries();
        SquareSeries square = new SquareSeries();

        fib.display(n);
        cube.display(n);
        square.display(n);
    }
}

