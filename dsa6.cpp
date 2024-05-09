#include <iostream>
#include <iomanip> // For setw()
using namespace std;

string city[10];
int a[10][10], c, t;

void cityname()
{
    cout << "Enter the number of cities : ";
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cout << "Enter Name of cites : " << i + 1 << " : ";
        cin >> city[i];
    }
}

void time()
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i != j && a[i][j] == 0)
            {
                cout << "Enter time required between " << city[i] << " to " << city[j] << " in hours : ";
                cin >> t;
                a[i][j] = a[j][i] = t;
            }
        }
    }
}

void add()
{
    cout << "Enter Name of city : ";
    cin >> city[c];
    c++;
    time();
}

void display()
{
    cout << setw(15) << " ";
    for (int i = 0; i < c; i++)
    {
        cout << setw(15) << city[i];
    }
    cout << endl;

    for (int i = 0; i < c; i++)
    {
        cout << setw(15) << city[i];
        for (int j = 0; j < c; j++)
        {
            cout << setw(15) << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cityname();
    time();
    int ch;
    while (true)
    {
        cout << "1. Add a city " << endl;
        cout << "2. Adjacency Matrix : " << endl;
        cout << "3. Exit" << endl;
        cout << "enter choice : ";
        cin >> ch;
        if (ch == 1)
        {
            add();
        }
        else if (ch == 2)
        {
            display();
        }
        else if (ch == 3)
        {
            break;
        }
    }
    return 0;
}
