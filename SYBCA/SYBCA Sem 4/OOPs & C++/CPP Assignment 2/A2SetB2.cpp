#include <iostream>
#include <string>
using namespace std;

class Bus {
    int bus_no;
    string bus_name;
    int no_of_seats;
    string starting_point;
    string destination;

public:
    void accept(int i) 
    {
        cout << "\nEnter details of Bus " << i + 1 << ":\n";
        cout << "Enter Bus No: ";
        cin >> bus_no;
        cout << "Enter Bus Name: ";
        cin >> bus_name;
        cout << "Enter Number of Seats: ";
        cin >> no_of_seats;
        cout << "Enter Starting Point: ";
        cin >> starting_point;
        cout << "Enter Destination: ";
        cin >> destination;
    }

    void display() 
    {
        cout << "\nBus No: " << bus_no << endl;
        cout << "Bus Name: " << bus_name << endl;
        cout << "Number of Seats: " << no_of_seats << endl;
        cout << "Starting Point: " << starting_point << endl;
        cout << "Destination: " << destination << endl;
    }

    bool Dest_match(string start,string end) 
    {
        return (starting_point == start && destination == end);
    }
};

int main() 
{
    Bus buses[20];
    int choice, size;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Accept details of buses.\n";
        cout << "2. Display all bus details.\n";
        cout << "3. Display details of bus from specified starting and ending destination.\n";
        cout << "4. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "How many buses do you want to enter? ";
                cin >> size;
                for (int i = 0; i < size; i++) 
                {
                    buses[i].accept(i);
                }
                break;

            case 2:
                cout << "\nDetails of all buses:\n";
                for (int i = 0; i < size; i++) 
                {
                    buses[i].display();
                }
                break;

            case 3: {
                string start, end;
                cout << "Enter Starting Point: ";
                cin >> start;
                cout << "Enter Destination: ";
                cin >> end;

                bool found = false;
                for (int i = 0; i < size; i++) {
                    if (buses[i].Dest_match(start, end)) 
                    {
                        buses[i].display();
                        found = true;
                    }
                }
                if (!found) 
                {
                    cout << "No bus found from " << start << " to " << end << "." << endl;
                }
                break;
            }

            case 4:
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
