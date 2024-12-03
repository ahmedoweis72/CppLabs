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
    void printAll()
    {
        if (top != -1)
        {
            for (int i = top; i >= 0; i--)
            {
                printf("The Employee ID is = %d \n", items[i].code);
                printf("The Employee Name is = %s \n", items[i].name);
                printf("The Employee NetSalary is = %d \n", items[i].netSalary);
            }
        }
        else
        {
            cout << "Stack Is Empty" << endl;
        }
    }
     bool isIDUnique(int id) {
        for (int i = 0; i <= top; ++i) {
            if (items[i].code == id) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Stack s(SIZE);
    Employee employeeData;
    char ch, flag = 1, option = 0, posi = 0, chkKEy = 0, exit = 0, backa;
    int id, ids[SIZE] = {0};

    while (flag == 1)
    {
        int id = 0;
        switch (option)
        {
        case 0:
        {
            clear();
            printf("\t\t%schoise option up&down %s\n\n\n", BLUE, RESET);
            printf(" \t\t\t1-Display Employee\n\n\n");
            printf("\t\t\t2-Push Employee\n\n\n");
            printf("\t\t\t3-POP Employee\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 1:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t%s1-Display Employee%s\n\n\n", BLUE, RESET);
            printf("\t\t\t2-Push Employee\n\n\n");
            printf("\t\t\t3-POP Employee\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 2:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Display Employee\n\n\n");
            printf("\t\t\t%s2-Push Employee%s\n\n\n", BLUE, RESET);
            printf("\t\t\t3-POP Employee\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 3:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Display Employee\n\n\n");
            printf("\t\t\t2-Push Employee\n\n\n");
            printf("\t\t\t%s3-POP Employee%s\n\n\n", BLUE, RESET);
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        case 4:
        {
            clear();
            printf("\t\tchoise option up&down \n\n\n");
            printf("\t\t\t1-Display Employee\n\n\n");
            printf("\t\t\t2-Push Employee\n\n\n");
            printf("\t\t\t3-POP Employee\n\n\n");
            printf("\t\t\t%s4-exit%s\n\n\n", BLUE, RESET);
            break;
        }
        case 5:
        { // push employee
            Employee e;

            clear();
            cout << "%sPush Employee%s" << BLUE << RESET << endl;
            cout << "Enter Employee unique code please" << endl;
            cin >> id;


                if (s.isIDUnique(id) && id > 0)
                {

                    e.code = id;

                }
                else
                {
                    cout << "Enter Valid Id" << endl;
                    cin >> id;
                }


            cout << "Enter Employee Name" << endl;
            cin >> e.name;
            cout << "Enter Employee Salary" << endl;
            cin >> e.netSalary;
            if (s.push(e))
            {
                cout << "Success push Employee" << endl;
                cout << "Add new one press 1 else press 0" << endl;
                ch = getch();
            }

            break;
        }
        case 6: // Display Elements
        {
            clear();
            s.printAll();
            break;
        }
        case 7:
        {
            clear();

            if (posi == 1)
            {
                printf("click backspace to back\n");
                printf(" \t\t\n\n\n\t%sDisplay Employee%s\n\n\n ", BLUE, RESET);
            }
            else if (posi == 2)
            {
                printf("click backspace or Esc to back\n");
                printf(" \t\t\n\n\n\t%sPush Employee%s\n\n\n ", BLUE, RESET);
                exit = 0;
            }
            else if (posi == 4)
            {
                printf("click enter to exit\n");
                printf("\t\t\t exit \n\n\n");
                printf("See you");
                flag = 0;
            }
            else if (posi == 3)
            {
                printf("chose option Record to edit\n");
                printf("%s\t\t\t Pop Employee \n\n\n%s", BLUE, RESET);
            }

            break;
        }
        case 8: // pop
        {
            clear();
            Employee e2;
            if (s.pop(&e2))
            {
                printf("The Employee ID is = %d \n", e2.code);
                printf("The Employee Name is = %s \n", e2.name);
                printf("The Employee NetSalary is = %d \n", e2.netSalary);
            }
            else
            {
                cout << "Stack IS Empty" << endl;
            }

            break;
        }
        default:
        {
            clear();
            printf("%schoise option  up&down %s\n", BLUE, RESET);
            printf("\t\t\t1-Display Employee\n\n\n");
            printf("\t\t\t2-Push Employee\n\n\n");
            printf("\t\t\t3-Modifay\n\n\n");
            printf("\t\t\t4-exit\n\n\n");
            break;
        }
        }
        ch = getch();
        if (ch == EXTENDKEY)
        {
            if (kbhit() == 0 && ch == ESC)
            {
                option = posi;
                posi = 0;
            }
            else
            {

                ch = getch();
                ch = getch();

                if (posi == 0)
                {
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
            }
        }
        else if (ch == ENTERKEY && posi == 0)
        {
            posi = option;
            option = 7;
        }
        else if (ch == ENTERKEY && posi == 1)
        {
            option = 6;
        }
        else if (ch == ENTERKEY && posi == 2 && option == 7)
        {
            if (exit == 0)
            {
                option = 5;
            }
        }
        else if (ch == ZERO && option == 5)
        {
            option = 7;
            posi = 2;
        }
        else if (ch == ONE && option == 5)
        {

            option = 5;
        }
        else if (ch == BACKSPACE)
        {
            option = posi;
            posi = 0;
        }

        else if (ch == ENTERKEY && posi == 3)
        {
            posi = option;
            option = 8;
        }
        else if (ch == ENTERKEY)
        {
            option == option;
        }
    }

    return 0;
}
