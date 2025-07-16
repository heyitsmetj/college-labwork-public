class Point 
{
    protected int x, y;

    Point() 
    {
        x = 0;
        y = 0;
    }

    Point(int x, int y) 
    {
        this.x = x;
        this.y = y;
    }

    void display() 
    {
        System.out.println("Point Coordinates: (" + x + ", " + y + ")");
    }
}

class ColorPoint extends Point 
{
    private String color;

    ColorPoint(int x, int y, String color) 
    {
        super(x, y);
        this.color = color;
    }

    @Override
    void display() 
    {
        System.out.println("ColorPoint: (" + x + ", " + y + "), Color: " + color);
    }
}

class Point3D extends Point 
{
    private int z;

    Point3D(int x, int y, int z) 
    {
        super(x, y);
        this.z = z;
    }

    @Override
    void display() 
    {
        System.out.println("Point3D Coordinates: (" + x + ", " + y + ", " + z + ")");
    }
}

public class A2SetA1 
{
    public static void main(String[] args) 
    {
        Point p1 = new Point();
        Point p2 = new Point(4, 5);
        ColorPoint cp = new ColorPoint(1, 2, "Red");
        Point3D p3d = new Point3D(7, 8, 9);

        System.out.println("Displaying points:");
        p1.display();
        p2.display();
        cp.display();
        p3d.display();
    }
}
