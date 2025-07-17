import Utility.CapitalString;
import java.util.Scanner;

class Person
{
	String name, city;
	
	Person()
	{
		this.name = "john";
		this.city = "Paris";
	}
	
	Person(String name, String city)
	{
		this.name = name;
		this.city = city;
	}
	
	public void display()
	{
		System.out.println("\nYour Name: " + this.name);
		
		CapitalString obj = new CapitalString();
		this.name = obj.convert(this.name);
		
		System.out.println("Your Converted Name: " + this.name);
		
		System.out.println("Your City: " + this.city);
	}
}

public class A2SetA4 
{
    public static void main(String[] args) 
    {
		Person p1 = new Person();
		Person p2 = new Person("ramesh", "Mumbai");
		
		p1.display();
		p2.display();
    }
}

