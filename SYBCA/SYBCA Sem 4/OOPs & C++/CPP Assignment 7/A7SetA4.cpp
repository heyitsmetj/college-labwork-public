#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Flight
{
protected:
    string flightNo;
    string flightName;

public:
    void getFlightDetails()
    {
        cout << "Enter Flight Number: ";
        cin >> flightNo;

        cout << "Enter Flight Name: ";
        cin >> flightName;
    }
    void displayFlightDetails() const
    {
        cout << setw(12) << flightNo << setw(20) << flightName;
    }
};

class Route : public Flight
{
protected:

    string source;
    string destination;

public:

    void getRouteDetails()
    {
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
    }

    void displayRouteDetails() const
    {
        cout << setw(15) << source << setw(15) << destination;
    }
};

class Reservation : public Route
{
    int numberOfSeats;
    string travelClass;
    double fare;
    string travelDate;

public:

    void getReservationDetails()
    {
        getFlightDetails();
        getRouteDetails();
        cout << "Enter Number of Seats: ";
        cin >> numberOfSeats;
        cout << "Enter Travel Class (e.g., Business, Economy): ";
        cin >> travelClass;
        cout << "Enter Fare: ";
        cin >> fare;
        cout << "Enter Travel Date (DD-MM-YYYY): ";
        cin >> travelDate;
    }

    void displayReservationDetails() const
    {
        displayFlightDetails();
        displayRouteDetails();
        cout << setw(8) << numberOfSeats << setw(12) << travelClass << setw(10) << fare << setw(15) << travelDate << endl;
    }

    string getTravelClass() const
    {
        return travelClass;
    }
};

int main()
{
    int n;

    cout << "Enter number of reservations: ";
    cin >> n;

    Reservation *reservations = new Reservation[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Reservation " << i + 1 << ":\n";
        reservations[i].getReservationDetails();
    }

    cout << "\nAll Reservation Details:\n";
    cout << setw(12) << "FlightNo" << setw(20) << "FlightName"
         << setw(15) << "Source" << setw(15) << "Destination"
         << setw(8) << "Seats" << setw(12) << "Class"
         << setw(10) << "Fare" << setw(15) << "TravelDate" << endl;
    cout << string(110, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        reservations[i].displayReservationDetails();
    }

    cout << "\nBusiness Class Reservation Details:\n";
    cout << setw(12) << "FlightNo" << setw(20) << "FlightName"
         << setw(15) << "Source" << setw(15) << "Destination"
         << setw(8) << "Seats" << setw(12) << "Class"
         << setw(10) << "Fare" << setw(15) << "TravelDate" << endl;
    cout << string(110, '-') << endl;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        string tc = reservations[i].getTravelClass();

        if (tc == "Business" || tc == "business")
        {
            reservations[i].displayReservationDetails();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Business class reservations found.\n";
    }

    delete[] reservations;

    return 0;

}
