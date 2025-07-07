#include <iostream>
using namespace std;
class Time
{
    int hours, minutes, seconds;

public:
    friend istream &operator>>(istream &in, Time &t)
    {
        cout << "Enter Hours: ";
        in >> t.hours;
        cout << "Enter Minutes: ";
        in >> t.minutes;
        cout << "Enter Seconds: ";
        in >> t.seconds;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Time &t)
    {
        out << t.hours << "h : " << t.minutes << "m : " << t.seconds << "s";
        return out;
    }
    // Function to Convert Time to Total Seconds
    int toSeconds()
    {
        return (hours * 3600) + (minutes * 60) + seconds;
    }

    void normalize()
    {
        if(seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }

        if(minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }

        cout << hours << " hr(s) : " << minutes << " min(s) : " << seconds << " sec(s) " << endl; 
    }
};
int main()
{
    Time t1;
    // Accept Time
    cout << "Enter Time Details:\n";
    cin >> t1;

    t1.normalize();

    cout << t1 << endl;
    cout << "Total Time in Seconds: " << t1.toSeconds() << " seconds\n";
}