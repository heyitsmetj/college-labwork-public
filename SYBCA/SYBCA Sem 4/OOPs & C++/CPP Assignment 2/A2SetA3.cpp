#include <iostream>
#include <iomanip>
using namespace std;

class District
{

    int district_code;
    char district_name[20];
    float area_sqft;
    int population;
    float literacy_rate;
    static int count;

public:
    void accept(int i)
    {
        cout << "\nEnter Details of District " << i + 1 << " : " << endl;

        cout << "Enter District Code: ";
        cin >> district_code;
        cout << "Enter District Name: ";
        cin >> district_name;
        cout << "Enter area in sqft: ";
        cin >> area_sqft;
        cout << "Enter the population: ";
        cin >> population;
        cout << "Enter the literacy rate(%): ";
        cin >> literacy_rate;
        count++;
    }

    void display()
    {
        cout << left << setw(20) << "\nDistrict Code: " << district_code << endl;
        cout << left << setw(20) << "District Name: " << district_name << endl;
        cout << left << setw(20) << "Area in sqft: " << area_sqft << endl;
        cout << left << setw(20) << "Population: " << population << endl;
        cout << left << setw(20) << "Literacy rate(%): " << literacy_rate << "%" << endl;
    }

    static void findmax(District d[])
    {
        int i;
        District max;

        if (count == 0)
        {
            i = 0;
            max = d[i];
        }
        else
        {
            for (i = 0; i < count; i++)
            {
                if (d[i].literacy_rate > max.literacy_rate)
                {
                    max = d[i];
                }
            }
        }

        cout << "\nDetails of District with highest literacy rate: " << endl;
        max.display();
    }

    static void l_pop(District d[])
    {
        int i;
        District least_pop;

        if (count == 0)
        {
            i = 0;
            least_pop = d[i];
        }
        else
        {
            for (i = 0; i < count; i++)
            {
                if (d[i].population < least_pop.population)
                {
                    least_pop = d[i];
                }
            }
        }

        cout << "\nDetails of District with least population: " << endl;
        least_pop.display();
    }

    void avail_districts(int i)
    {
        cout << i + 1 << " " << district_name << endl;
    }
};

int District::count;

int main()
{
    District d[20];

    int i, choice, size;

    while (true)
    {
        cout << "\n1. Accept details of district(s)." << endl;
        cout << "2. Display details of a district." << endl;
        cout << "3. Display details of district with highest literacy." << endl;
        cout << "4. Display details of district with least population." << endl;
        cout << "5. Exit. " << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "How many districts do you want to enter?: ";
            cin >> size;

            for (i = 0; i < size; i++)
            {
                d[i].accept(i);
            }
            break;

        case 2:
            cout << "\nAvailable Districts:" << endl;

            for (int i = 0; i < size; i++)
                d[i].avail_districts(i);

            int dist_choice;

            cout << "\nChoose corresponding index value: ";
            cin >> dist_choice;

            cout << "\nDetails of District " << i << " : " << endl;
            d[i-1].display();
            break;
        
        case 3:
            District::findmax(d);
            break;

        case 4:
            District::l_pop(d);
            break;

        case 5:
            exit(0);
            break;
            
        default:
            cout << "\nWrong Choice! Try Again!" << endl;
            break;
        }
    }

    return 0;
}