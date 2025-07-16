import Series.CubeSeries;
import Series.SquareSeries;
import Series.FibSeries;

public class A2SetA2 {
    public static void main(String[] args) 
    {
        int n = 10;

        FibSeries fib = new FibSeries();
        CubeSeries cube = new CubeSeries();
        SquareSeries square = new SquareSeries();

        fib.display(n);
        cube.display(n);
        square.display(n);
    }
}

