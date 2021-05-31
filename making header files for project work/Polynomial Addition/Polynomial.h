#include<iostream>
#include<climits>
using namespace std;
class Polynomial
{
private:
    int *degCoeff; 
    int capacity; 
public:
     
    Polynomial()
    {
        //Initializing array with some initial size (here initial size=10)
        this->degCoeff = new int[10];
        this->capacity = 10;
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }

    //copy constructor
    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    //overloading copy assignment operator
    void operator=(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    //print function
    void print() const
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout<<endl;
    }
    
    //setCoeff function
    void setCoefficient(int degree, int coefficient)
    {
        if (degree < capacity)
        {
            degCoeff[degree] = coefficient;
        }
        else
        {
            int ts = capacity;
            while (degree >= ts)
            {
                ts *= 2;
            }
            int *newDegCoeff = new int[ts];
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            for (int i = capacity; i < ts; i++)
            {
                newDegCoeff[i] = 0;
            }
            capacity = ts;
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            degCoeff[degree] = coefficient;
        }
    }
    
    //overload +
    Polynomial operator+(Polynomial const &p) const
    {
        Polynomial pnew;
        pnew.capacity = max(this->capacity, p.capacity);
        pnew.degCoeff = new int[pnew.capacity];
        for (int i = 0; i < pnew.capacity; i++)
        {
            pnew.degCoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            pnew.degCoeff[i] += this->degCoeff[i];
        }
        for (int i = 0; i < p.capacity; i++)
        {
            pnew.degCoeff[i] += p.degCoeff[i];
        }
        return pnew;
    }

    //overload -
    Polynomial operator-(Polynomial const &p) const
    {
        Polynomial pnew;
        pnew.capacity = max(this->capacity, p.capacity);
        pnew.degCoeff = new int[pnew.capacity];
        for (int i = 0; i < pnew.capacity; i++)
        {
            pnew.degCoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            pnew.degCoeff[i] += this->degCoeff[i];
        }
        for (int i = 0; i < p.capacity; i++)
        {
            pnew.degCoeff[i] -= p.degCoeff[i];
        }
        return pnew;
    }

    // overload *
    Polynomial operator*(Polynomial const &p) const
    {
        Polynomial pnew;
        pnew.capacity = this->capacity + p.capacity;
        pnew.degCoeff = new int[pnew.capacity];
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->degCoeff[i] != 0)
            {
                for (int j = 0; j < p.capacity; j++)
                {
                    if (p.degCoeff[j] != 0)
                    {
                        int product = this->degCoeff[i] * p.degCoeff[j];
                        int degree = i + j;
                        pnew.degCoeff[i + j] += product;
                    }
                }
            }
        }
        return pnew;
    }
};
