#include <iostream>
#include <cstdlib>

using namespace std;

struct List {
    int x;
    struct List *next;
    struct List *prev;
    List (int newX, List *newNext, List *newPrev) {
        x = newX;
        next = newNext;
        prev = newPrev;
    }
};

struct List *base;

void newIn()
{
    int temp;
    bool repeat = true;
    List *newOne, *p;

    while (repeat)
    {
        newOne = new struct List(0, (struct List *) nullptr,
                (struct List *) nullptr);

        cout << "\nInput X: ";
        cin  >> temp;

        if (temp > 0)
        {
            if (base == (struct List *) nullptr)
            {
                newOne = new List(temp, base, base);
                newOne->next = nullptr;
                newOne->prev = nullptr;
                base = newOne;
            }
            else {
                p = base;
                newOne->x = temp;
                if(newOne->x > p->x)
                {
                    newOne->next = base;
                    newOne->prev = nullptr;
                    base->prev = newOne;
                    base = newOne;
                }
                else {
                    while (p->next != (struct List *) nullptr && p->next->x >= newOne->x)
                    {
                        p = p->next;
                    }
                    newOne->prev = p;
                    newOne->next = p->next;
                    p->next = newOne;
                }
            }
        }
        else {
            repeat = false;
        }
    }
}

void deleteOne()
{
    struct List *p = base;
    int temp;

    cout << "\nEnter a number to be deleted: ";
    cin  >> temp;
    if (base == (struct List *) nullptr)
    {
        cout << "\nNo number in the list...";
    }
    else
    {
        if (p->x == temp)
        {
            if (p->next == nullptr && p->prev == nullptr)
            {
                base = nullptr;
                return;
            }
            p->next->prev = nullptr;
            base = p->next;
            cout << "\n\t" << temp << " is deleted from the list";
        }
        else {
            while (p->next != (struct List *) nullptr && p->next->x != temp)
            {
                p = p->next;
            }

            if (p->next == (struct List *) nullptr)
            {
                cout << "\n\t" << temp << " is NOT in the list, try again...";
            }
            else {
                p->next = p->next->next;
                cout << "\n\t" << temp << " is deleted from the list";
            }
        }
    }

}

void listThem()
{
    struct List *thisOne = base;

    if (base == (struct List *) nullptr)
    {
        cout << "\nNo number in the list";
    }
    else {
        cout << "\nThe following numbers are in backward order (LIFO) :\n";
        while (thisOne != (struct List *) nullptr) {
            cout << thisOne->x << ", ";
            thisOne = thisOne->next;
        }

        cout << "\nThe following numbers are in forward order (FIFO) :\n";
        thisOne = base;
        while (thisOne->next != (struct List *) nullptr) {
            thisOne = thisOne->next;
        }

        while (thisOne != base) {
            cout << thisOne->x << ", ";
            thisOne = thisOne->prev;
        }
        cout << thisOne->x;
    }
}


int main() {
    char ch;

    while (true)
    {
        cout << "\n\nType 'E/e to enter a new number";
        cout << "\n     'D/d' to delete a number from the list";
        cout << "\n     'L/l' to list all numbers";
        cout << "\n     'Q/q' to quit";
        cin  >> ch;

        switch (ch)
        {
            case 'E':
            case 'e':
                newIn();
                break;
            case 'D':
            case 'd':
                deleteOne();
                break;
            case 'L':
            case 'l':
                listThem();
                break;
            case 'Q':
            case 'q':
                exit(0);
            default: cout << "\nEnter only selections listed above!\n";
        }
    }

    //return 0;
}