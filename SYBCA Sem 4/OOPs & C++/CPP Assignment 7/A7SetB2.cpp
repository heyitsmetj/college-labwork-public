#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Train
{
protected:
    string trainNo;
    string trainName;

public:
    void getTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNo;

        cout << "Enter Train Name: ";
        cin >> trainName;
    }
    void displayTrainDetails() const
    {
        cout << setw(12) << trainNo << setw(20) << trainName;
    }
};

class Route : public Train
{
protected:
    int routeId;
    string source;
    string destination;

public:
    void getRouteDetails()
    {
        cout << "Enter Route ID: ";
        cin >> routeId;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
    }
    void displayRouteDetails() const
    {
        cout << setw(8) << routeId << setw(15) << source << setw(15) << destination;
    }
};

class Reservation : public Route
{
private:
    int numberOfSeats;
    string trainClass;
    double fare;
    string travelDate;

public:
    void getReservationDetails()
    {
        getTrainDetails();
        getRouteDetails();
        cout << "Enter Number of Seats: ";
        cin >> numberOfSeats;
        cout << "Enter Train Class (e.g., AC, Sleeper, General): ";
        cin >> trainClass;
        cout << "Enter Fare: ";
        cin >> fare;
        cout << "Enter Travel Date (DD-MM-YYYY): ";
        cin >> travelDate;
    }
    void displayReservationDetails() const
    {
        displayTrainDetails();
        displayRouteDetails();
        cout << setw(8) << numberOfSeats << setw(12) << trainClass << setw(10) << fare << setw(15) << travelDate << endl;
    }
    string getTrainClass() const
    {
        return trainClass;
    }
};

void displayTableHeader()
{
    cout << setw(12) << "TrainNo" << setw(20) << "TrainName"
         << setw(8) << "RouteID" << setw(15) << "Source" << setw(15) << "Destination"
         << setw(8) << "Seats" << setw(12) << "Class" << setw(10) << "Fare" << setw(15) << "TravelDate" << endl;
    cout << string(110, '-') << endl;
}

int main()
{
    int n = 0;
    Reservation *reservations = nullptr;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enter Reservation Details\n";
        cout << "2. Display All Reservations\n";
        cout << "3. Display Reservations for a Specific Train Class\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of reservations: ";
            cin >> n;
            if (reservations)
            {
                delete[] reservations;
            }
            reservations = new Reservation[n];
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter details for Reservation " << i + 1 << ":\n";
                reservations[i].getReservationDetails();
            }
            break;

        case 2:
            if (n == 0)
            {
                cout << "No reservations available.\n";
            }
            else
            {
                cout << "\nAll Reservation Details:\n";
                displayTableHeader();
                for (int i = 0; i < n; i++)
                {
                    reservations[i].displayReservationDetails();
                }
            }
            break;

        case 3:
            if (n == 0)
            {
                cout << "No reservations available.\n";
            }
            else
            {
                string searchClass;

                cout << "Enter Train Class to display reservations: ";
                cin >> searchClass;

                cout << "\nReservations for Train Class: " << searchClass << "\n";
                displayTableHeader();

                bool found = false;

                for (int i = 0; i < n; i++)
                {
                    if (reservations[i].getTrainClass() == searchClass)
                    {
                        reservations[i].displayReservationDetails();
                        found = true;
                    }
                }
                if (!found)
                {
                    cout << "No reservations found for Train Class: " << searchClass << endl;
                }
            }
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    if (reservations)
    {
        delete[] reservations;
    }

    return 0;
}
