import java.io.*;
import java.util.Scanner;

class A1SetC1 {

	public static void main(String args[]) throws IOException {

		int size;

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of objects: ");
		size = sc.nextInt();

		Person[] peeps = new Person[size];

		for (int i = 0; i < peeps.length; i++) 
		{
			peeps[i] = new Person();
			peeps[i].accept(sc);
		}

		System.out.println("\nEntered Person Details:");
		for (int i = 0; i < peeps.length; i++) {
			peeps[i].display();
		}

		sc.close();
	}
}

class MyDate {
	int dd, mm, yyyy;

	public MyDate() {
		this.dd = 1;
		this.mm = 1;
		this.yyyy = 2000;
	}

	public void accept(Scanner sc) {
		System.out.print("Enter Date (dd): ");
		this.dd = sc.nextInt();

		System.out.print("Enter Month (mm): ");
		this.mm = sc.nextInt();

		System.out.print("Enter Year (yyyy): ");
		this.yyyy = sc.nextInt();
	}

	public void display() {
		System.out.println("Date of Birth: " + dd + "-" + mm + "-" + yyyy);
	}
}

class Person {
	int id;
	String name;
	MyDate dob;
	static int cnt = 1;

	public Person() {
		this.id = cnt++;
		this.name = "NewPerson";
		this.dob = new MyDate();
	}

	public void accept(Scanner sc) {
		sc.nextLine();

		System.out.print("\nEnter Name: ");
		this.name = sc.nextLine();

		System.out.println("Enter Date of Birth:");
		this.dob.accept(sc);
	}

	public void display() {
		System.out.println("\nId: " + id);
		System.out.println("Name: " + name);
		dob.display();
	}
}

