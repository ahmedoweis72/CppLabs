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
    c4 = c2.SubComplex(c1);
    c3.disComplex();
    c4.disComplex();
    return 0;
}