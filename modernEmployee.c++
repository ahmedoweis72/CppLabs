#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#include "conio.h"
#define BLUE "\[\033[0;34m\]"
#define RESET "\[\033[0m\]"
#define clear() printf("\033[H\033[J")
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define EXTENDKEY 27
#define EXTRAEXTENDKEY 91
#define ENTERKEY 10
#define BACKSPACE 127
#define ESC 27
#define HOME 72
#define END 70
#define ONE 49
#define ZERO 48
#define TERMINATOR '\0'

typedef struct Employee
{
    char name[10];
    int code;
    int netSalary;
} Employee;

class Stack
{
private:
    int size;
    int top;
    Employee *items;

public:
    Stack() {}
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new Employee[size];
    }
    ~Stack()
    {
        delete[] items;
    }
    int push(Employee element)
    {
        if (top != size - 1)
        {
            top++;
            items[top] = element;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int pop(Employee *data)
    {
        if (top != -1)
        {
            *data = items[top];
            top--;
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack s(SIZE);
    Employee employeeData;
    char ch, flag = 1, option = 0, back = 1, exit = 0;
    int id, ids[SIZE] = {0};
    while (flag == 1)
    {

        switch (option)
        {
        case 1:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t%s1-Push Employee%s\n\n\n", BLUE, RESET);
            printf("\t\t\t2-POP Employee\n\n\n");
            printf("\t\t\t3-Print Employees\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 2:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Push Employee\n\n\n");
            printf("\t\t\t%s2-POP Employee%s\n\n\n", BLUE, RESET);
            printf("\t\t\t3-Print Employees\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 3:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Push Employee\n\n\n");
            printf("\t\t\t2-POP Employee\n\n\n");
            printf("\t\t\t%s3-Print Employees%s\n\n\n", BLUE, RESET);
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 4:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Push Employee\n\n\n");
            printf("\t\t\t2-POP Employee\n\n\n");
            printf("\t\t\t3-Print Employees\n\n\n");
            printf("\t\t\t%s4-exit\n\n\n%s", BLUE, RESET);
            break;
        }
        case 5: // push Employee
        {
            Employee e;

            clear();
            cout << "%sPush Employee%s" << BLUE << RESET << endl;
            cout << "Enter Employee unique code please" << endl;
            cin >> id;
            for (int i = 0; i < SIZE; i++)
            {
                if (id != ids[i] && id > 0)
                {
                    ids[i] = id;
                    e.code = id;
                    i = SIZE;
                }
                else
                {
                    cout << "Enter Valid Id" << endl;
                    cin >> id;
                }
            }

            cout << "Enter Employee Name" << endl;
            cin >> e.name;
            cout << "Enter Employee Salary" << endl;
            cin >> e.netSalary;
            s.push(e) ? cout << "Success push Employee" << endl : cout << "Failure push Employee" << endl;
            cout << "Add new one press 1 else press 0" << endl;
            cin >> &back;
            if (back == 0)
            {
                option = 1;
            }
            break;
        }
        case 6: // Pop Employee
        {
            Employee e;
            clear();
            if (s.pop(&e))
            {
                cout << "Employee Id : " << e.code << endl;
                cout << "Employee Name : " << e.name << endl;
                cout << "Employee Salary : " << e.netSalary << endl;
            }
            else
            {
                cout << "Failure pop Stack empty" << endl;
                
            }
            break;
        }
        default:
        {
            clear();
            printf("\t\t%schoise option up&down %s\n\n\n", BLUE, RESET);
            printf("\t\t\t1-Push Employee\n\n\n");
            printf("\t\t\t2-POP Employee\n\n\n");
            printf("\t\t\t3-Print Employees\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        }

        ch = getch();

        if (ch == EXTENDKEY)
        {
            ch = getch();
            ch = getch();

            if (ch == DOWN || ch == RIGHT)
            {
                option += 1;
                ch = EXTRAEXTENDKEY;
                if (option > 4)
                {
                    option = 1;
                }
            }

            else if (ch == UP || ch == LEFT)
            {
                option -= 1;
                ch = EXTRAEXTENDKEY;
                if (option == 0)
                {
                    option = 4;
                }
            }
            else if (ch == HOME)
            {
                option = 1;
            }
            else if (ch == END)
            {
                option = 4;
            }
        }
        else if (option == 1 && ch==ENTERKEY)
        {
            option = 5;
        }
        else if (option == 2 && ch==ENTERKEY)
        {
            option = 6;
        }
        
    }

    return 0;
}
