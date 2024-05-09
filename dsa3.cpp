#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct node
{
    string name;
    node *next;
    node *down;
    int flag;
};

class Book
{
    string ch;
    int n, i;
    node *head = nullptr, *temp = nullptr, *t1 = nullptr, *t2 = nullptr;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *Book::create()
{
    node *p = new node;
    p->next = nullptr;
    p->down = nullptr;
    p->flag = 0;
    cout << "\n enter the name: ";
    cin >> p->name;
    return p;
}

void Book::insertb()
{
    if (head == nullptr)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "\n Book exists";
    }
}

void Book::insertc()
{
    if (head == nullptr)
    {
        cout << "\n There is no book.";
    }
    else
    {
        cout << "\n How many chapters do you want to insert? ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();
            if (head->flag == 0)
            {
                head->down = t1;
                head->flag = 1;
            }
            else
            {
                temp = head->down;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Book::inserts()
{
    if (head == nullptr)
    {
        cout << "\n There is no book.";
    }
    else
    {
        cout << "\n Enter the name of the chapter in which you want to enter the section: ";
        cin >> ch;
        temp = head->down;
        while (temp != nullptr)
        {
            if (ch == temp->name)
            {
                cout << "\n How many sections do you want to enter? ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    t1 = create();
                    if (temp->flag == 0)
                    {
                        temp->down = t1;
                        temp->flag = 1;
                    }
                    else
                    {
                        t2 = temp->down;
                        while (t2->next != nullptr)
                        {
                            t2 = t2->next;
                        }
                        t2->next = t1;
                    }
                }
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\n Chapter not found.";
    }
}

void Book::insertss()
{
    if (head == nullptr)
    {
        cout << "\n There is no book.";
    }
    else
    {
        cout << "\n Enter the name of the chapter: ";
        cin >> ch;
        temp = head->down;
        while (temp != nullptr)
        {
            if (ch == temp->name)
            {
                cout << "\n Enter the name of the section in which you want to enter the subsection: ";
                cin >> ch;
                t2 = temp->down;
                while (t2 != nullptr)
                {
                    if (ch == t2->name)
                    {
                        cout << "\n How many subsections do you want to enter? ";
                        cin >> n;
                        for (i = 0; i < n; i++)
                        {
                            t1 = create();
                            if (t2->flag == 0)
                            {
                                t2->down = t1;
                                t2->flag = 1;
                            }
                            else
                            {
                                node *t3 = t2->down;
                                while (t3->next != nullptr)
                                {
                                    t3 = t3->next;
                                }
                                t3->next = t1;
                            }
                        }
                        break;
                    }
                    t2 = t2->next;
                }
                if (t2 == nullptr)
                    cout << "\n Section not found.";
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\n Chapter not found.";
    }
}

void Book::displayb()
{
    if (head == nullptr)
    {
        cout << "\n Book does not exist.";
    }
    else
    {
        temp = head;
        cout << "\n NAME OF BOOK: " << temp->name;
        temp = temp->down;
        while (temp != nullptr)
        {
            cout << "\n\t\tNAME OF CHAPTER: " << temp->name;
            if (temp->flag == 1)
            {
                t1 = temp->down;
                while (t1 != nullptr)
                {
                    cout << "\n\t\t\t\tNAME OF SECTION: " << t1->name;
                    if (t1->flag == 1)
                    {
                        t2 = t1->down;
                        while (t2 != nullptr)
                        {
                            cout << "\n\t\t\t\t\t\tNAME OF SUBSECTION: " << t2->name;
                            t2 = t2->next;
                        }
                    }
                    t1 = t1->next;
                }
            }
            temp = temp->next;
        }
    }
}

int main()
{
    Book bk;
    int x;
    while (true)
    {
        cout << "\n Menu";
        cout << "\n 1. Insert book";
        cout << "\n 2. Insert chapter";
        cout << "\n 3. Insert section";
        cout << "\n 4. Insert subsection";
        cout << "\n 5. Display book";
        cout << "\n 6. Exit";
        cout << "\n\n Enter your choice: ";

        cin >> x;
        switch (x)
        {
        case 1:
            bk.insertb();
            break;
        case 2:
            bk.insertc();
            break;
        case 3:
            bk.inserts();
            break;
        case 4:
            bk.insertss();
            break;
        case 5:
            bk.displayb();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n Invalid choice.";
        }
    }
    return 0;
}
