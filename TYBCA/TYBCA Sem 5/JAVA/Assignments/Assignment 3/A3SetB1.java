import java.io.*;
import java.util.*;

class A3SetB1
{
	public static void main(String args[])
	{
		LinkedList <String> colors = new LinkedList <> ();
		colors.add("Red");
		colors.add("Blue");
		colors.add("Yellow");
		colors.add("Orange");
		
		List <String> newColors = new LinkedList <> ();
		newColors.add("Pink");
		newColors.add("Green");
		
		Iterator <String> it = colors.iterator();
		
		System.out.println("\nLinked List using Iterator: ");
		while(it.hasNext())
		{
			System.out.println(it.next());
		}
		
		System.out.println("\nReverse Linked List using ListIterator: ");
		ListIterator <String> lit = colors.listIterator(colors.size());
		while(lit.hasPrevious())
		{
			System.out.println(lit.previous());
		}
		
		int index = colors.indexOf("Blue") + 1;
		colors.addAll(index, newColors);
		
		System.out.println("\nNew Linked List after addition: " + colors);
	}
}
