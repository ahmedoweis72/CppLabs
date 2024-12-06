#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *items;

public:
    Stack(int size=0)
    {
        this->size = size;
        top = -1;
        items = new int[size];
    }
     Stack(Stack &s)
    {
        // this->size = size;
        // top = -1;
        // items = new int[size];
        this->size=s.size;
        this->top=s.top;
        this->items=new int[s.size];
        for (int i = 0; i < size; i++)
        {
            this->items[i]=s.items[i];
        }
        
    }
    ~Stack()
    {
        delete[] items;
    }
    int push(int element)
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
    int pop(int *data)
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
    void viewContent(){
        for (int i = 0; i < size; i++)
        {
            cout<<this->items[i]<<endl;
        }
    }

};

int main()
{
    Stack s(5);
    Stack s1(s);
    int data;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.push(5) ? cout << "Success push" << endl : cout << "Failure push" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    cout << data << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s.pop(&data) ? cout << "Success pop" << endl : cout << "Failure pop" << endl;
    s1.viewContent();
    s.viewContent();

    return 0;
}