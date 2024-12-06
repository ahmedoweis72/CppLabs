#include <iostream>
using namespace std;

class List
{
private:
    int end;
    int size;
    int *items;

public:
    List(int size = 0)
    {
        this->size = size;
        end = -1;
        items = new int[size];
    }
    int add(int element)
    {
        List l;
        if (this->end == -1)
        {
            this->end++;
            this->items[end] = element;
        }
        else
        {
            this->end++;
            for (int i = 0; i < this->end; i++)
            {
                l.items[i] = this->items[i];
            }
            delete[] this->items;
            l.items[end] = element;
            this->items = new int[this->end];
            for (int i = 0; i <= this->end; i++)
            {
                this->items[i] = l.items[i];
            }
            delete[] l.items;
        }

        return this->end;
    }
    int getSize()
    {
        return this->end;
    }
    int remove()
    {
        if (end == -1)
        {

            return 0;
        }
        else
        {
            List l(this->end);
            for (int i = 0; i < this->end; i++)
            {
                l.items[i] = this->items[i];
            }
            int poped = this->items[this->end];
            delete[] this->items;
            end--;
            this->items = new int[this->end];
            for (int i = 0; i <= this->end; i++)
            {
                this->items[i] = l.items[i];
            }
            return poped;
        }
    }
    void display()
    {
        for (int i = 0; i <= this->end; i++)
        {
            cout << this->items[i] << endl;
        }
    }
};

int main()
{
    List l(0);
    l.add(5);
    l.add(10);
    l.add(11);
    l.add(12);
    l.display();
    int x = l.remove();
    cout << x << endl;

    return 0;
}