import java.io.*;

interface Operation
{
	double PI = 3.142;
	
	public void area();
	public void volume();
}

class Circle implements Operation
{
	double radius;
	
	Circle()
	{
		this.radius = 0;
	}
	
	Circle(double r)
	{
		this.radius = r;
	}
	
	@Override
	public void area()
	{
		System.out.println("\nArea of Circle (r = " + this.radius + ") = " + (PI * (this.radius * this.radius)));
	}
	
	@Override
	public void volume()
	{
		System.out.println("A Circle does not have volume.");
	}	
}

class Cylinder implements Operation
{
	double radius, height;
	
	Cylinder()
	{
		this.radius = 0;
	}
	
	Cylinder(double r, double h)
	{
		this.radius = r;
		this.height = h;
	}
	
	@Override
	public void area()
	{
		System.out.println("\nArea of Cylinder (r = " + this.radius + ", h = " + this.height + ") = " + (2 * (PI * (this.radius * this.height)))+ (2 + (PI * (this.radius * this.radius))));
	}
	
	@Override
	public void volume()
	{
		System.out.println("Volume of Cylinder (r = " + this.radius + ", h = " + this.height + ") = " + (2 + (PI * (this.radius * this.radius) * this.height)));
	}	
}

public class A2SetB1 
{
    public static void main(String[] args) 
    {
        Circle C = new Circle(6);
        Cylinder C1 = new Cylinder(4, 5);

        System.out.println("Displaying Details:");
        C.area();
        C.volume();
        C1.area();
        C1.volume();
    }
}
