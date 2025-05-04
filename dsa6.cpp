#include<iostream>
#include<string.h>
using namespace std;
class flight
{
public:
    int am[10][10];
    char city_index[10][10];
    flight();
    int create();
    void display(int city_count);
};
flight::flight()
{
    int i, j;
    for(i = 0; i < 10; i++)
    {
        strcpy(city_index[i], "xx"); // Initialize city names to "xx"
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            am[i][j] = 0; // Initialize adjacency matrix to 0
        }
    }
}
int flight::create()
{
    int city_count = 0, j, si, di, wt; // si, di store index of source and destination
    char s[10], d[10], c; // stores names of city
    do
    {
        cout << "\n\tEnter Source City : ";
        cin >> s;
        cout << "\n\tEnter Destination City : ";
        cin >> d;
        // Finding Source City already exist
        si = -1;
        for (j = 0; j < city_count; j++)
        {
            if (strcmp(city_index[j], s) == 0)
            {
                si = j;
                break;
            }
        }

        if (si == -1) //city not found increase city index and city count
        {
            strcpy(city_index[city_count], s);
            si = city_count;
            city_count++;
        }

        // Finding Destination City
        di = -1;
        for (j = 0; j < city_count; j++)
        {
            if (strcmp(city_index[j], d) == 0)
            {
                di = j;
                break;
            }
        }

        if (di == -1)
        {
            strcpy(city_index[city_count], d);
            di = city_count;
            city_count++;
        }

        cout << "\n\t Enter Distance From " << s << " And " << d << ": ";
        cin >> wt;
        am[si][di] = wt;
        cout << "\n\t Do you want to add more cities.....(y/n) : ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return city_count;
}

void flight::display(int city_count)
{
    cout << "\n\tDisplaying Adjacency Matrix:\n\t";
    // Step 1: Print column headers
    cout << " "; //space for top left corner
    for (int i = 0; i < city_count; i++)
    {
        cout << city_index[i] << "\t"; // a b c d
    }
    cout << "\n";

    // Step 2: Display rows with city names and corresponding distances
    for (int i = 0; i < city_count; i++)
    {
        cout << city_index[i] << "\t"; // Display row headers (city names) // a
        for (int j = 0; j < city_count; j++)
        {
            cout << am[i][j] << "\t"; // Display matrix values // 0 10 0 5
        } // a 0 10 0 5
        cout << "\n";
    }
}

int main()
{
    flight f;
    int n, city_count;
    char c;
    do
    {
        cout << "\n\t***** Flight Main Menu *****";
        cout << "\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Exit";
        cout << "\n\t.....Enter your choice : ";
        cin >> n;

        switch(n)
        {
            case 1:
                city_count = f.create();
                break;
            case 2:
                f.display(city_count);
                break;
            case 3:
                return 0;
        }

        cout << "\n\t Do you Want to Continue in Main Menu....(y/n) : ";
        cin >> c;
    } while(c == 'y' || c == 'Y');
    return 0;
}

