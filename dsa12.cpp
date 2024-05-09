#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void addEmployee()
{
    ofstream fout("db.txt", ios::app);
    string id, name, designation, salary;
    cout << "--- ADD Employee IN DATABASE ---" << endl;
    cout << "Enter Employee ID : ";
    cin >> id;
    cout << "\nEnter Employee Name : ";
    cin >> name;
    cout << "\nEnter Employee Designation : ";
    cin >> designation;
    cout << "\nEnter Employee Salary : ";
    cin >> salary;
    cout << endl;
    fout << left << setw(20) << id << setw(20) << name << setw(20) << designation << setw(20) << salary << endl;
    cout << "Employee Added Successfully.\n";
    fout.close();
}

void deleteEmployee()
{
    ifstream fin("db.txt");
    string line;
    string id;
    cout << "Enter Employee ID To Delete: ";
    cin >> id;
    vector<string> filelines;
    while (getline(fin, line))
    {
        if (line.substr(0, line.find(' ')) != id)
        {
            filelines.push_back(line);
        }
    }
    fin.close();
    ofstream fout("db.txt", ios::out | ios::trunc);
    for (size_t i = 0; i < filelines.size(); ++i)
    {
        fout << filelines[i] << endl;
    }
    fout.close();
}

void searchEmployee()
{
    ifstream fin("db.txt");
    string line;
    string id;
    cout << "Enter Employee ID To Search : ";
    cin >> id;
    bool found = false;
    while (getline(fin, line))
    {
        if (line.find(id) != string::npos)
        {
            cout << "Employee Details: " << endl;
            cout << "\n"
                 << line << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Sorry, Not found" << endl;
    }
    fin.close();
}

void displayData()
{
    ifstream fin("db.txt");
    string line;
    cout << "\nDisplaying Data :- " << endl;
    while (getline(fin, line))
    {
        cout << "\n"<< line << endl;
    }
    fin.close();
}

int main()
{
    ofstream fout("db.txt", ios::out);
    fout << left << setw(20) << "Employee ID" << setw(20) << "Name" << setw(20) << "designation" << setw(20) << "salary" << endl;
    fout.close();
    int ch;
    do
    {
        cout << "\n--------- M E N U -----------" << endl;
        cout << "1. Add Employee.";
        cout << "\n2. Delete Employee.";
        cout << "\n3. Search Employee. ";
        cout << "\n4. Display Data.";
        cout << "\n5. Exit. " << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            displayData();
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Please ReEnter Your Choice: ";
            break;
        }
    } while (ch != -1);
    return 0;
}