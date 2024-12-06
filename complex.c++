#include <iostream>
using namespace std;

class complex
{
private:
    int real;
    int imge;

public:
    complex()
    {
    }
    complex(int real, int imge)
    {
        this->real = real;
        this->imge = imge;
    }
    ~complex()
    {
        cout << "good bye";
    }
    void setReal(int real)
    {
        if (real > 0)
        {
            this->real = real;
        }
        else
        {
            cout << "unvalid value" << endl;
        }
    }
    void setImage(int imge)
    {

        if (imge > 0)
        {
            this->imge = imge;
        }
        else
        {
            cout << "unvalid value" << endl;
        }
    }
    int getReal()
    {
        return real;
    }
    int getImage()
    {
        return imge;
    }
    complex addComplex(complex c1)
    {
        complex c2;
        c2.real = this->real + c1.real;
        c2.imge = this->imge + c1.imge;
        return c2;
    }
    complex SubComplex(complex c1)

    {
        complex c2;
        c2.real = this->real - c1.real;
        c2.imge = this->imge - c1.imge;
        return c2;
    }
    void disComplex()
    {
        cout << this->real << "+" << this->imge << "i" << endl;
    }
    complex operator+(complex c)
    {
        this->real = this->real + c.real;
        this->imge = this->imge + c.imge;
        return *this;
    }
    complex operator-(complex c)
    {
        this->real = this->real - c.real;
        this->imge = this->imge - c.imge;
        return *this;
    }
    complex operator++()
    {
        this->real = this->real + 1;
        this->imge = this->imge + 1;
        return *this;
    }
    complex operator++(int x)
    {
        complex c;
        c.real = this->real;
        c.imge = this->imge;
        this->real = this->real + 1;
        this->imge = this->imge + 1;
        return c;
    }
    friend complex operator+(int x,complex c)
    {
        c.real += 5;
        c.imge += 5;
        return c;
    }
    friend complex operator-(int x,complex c)
    {
        c.real -= 5;
        c.imge -= 5;
        return c;
    }
        friend complex operator+(complex c,int x)
    {
        c.real += 5;
        c.imge += 5;
        return c;
    }
    friend complex operator-(complex c,int x)
    {
        c.real -= 5;
        c.imge -= 5;
        return c;
    }
};

int main()
{
    complex c1;
    c1.setImage(5);
    c1.setReal(10);
    complex c2;
    c2.setImage(5);
    c2.setReal(30);
    c2.disComplex();

    complex c3, c4;
    c3 = c2.addComplex(c1);
    c3.disComplex();
    c4 = c3.SubComplex(c1);
    c4.disComplex();
    /*
    c3.disComplex();
    c4.disComplex();
    c3 = c1 + c2;
    c3.disComplex();
    c3 = 5 + c3;
    c3.disComplex();
    */

    return 0;
}