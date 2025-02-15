#include"MyVector.h"
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
class MyMatrix: public MyVector<MyVector<T>>
{
public:
    
    MyMatrix(int size = 5): MyVector<MyVector<T>>(size)
    {
        for (int i = 0; i < size; i++) 
        {
            this->vector[i].resize(size);
        }
    }
    MyMatrix(MyMatrix &other):MyVector<MyVector<T>>(other.get_size())
    {
        for (int i = 0; i < this->size; i++)
        {
            this->vector[i] = other[i];   
        }
    }

    const MyVector<T> operator * (MyVector<T>& other)
    {
        MyVector<T> res(this->size);
        for (int i = 0; i < this->size; i++)
        {
                res[i] = this->vector[i] * other;
        }
        return res;
    }
    MyVector<T>& operator [](int index)
    {
        return this->vector[index];
    }
};  

template<class T>
istream& operator >> (istream& in, MyMatrix<T>& Matrix)
{
    for (int i = 0; i < Matrix.get_size(); i++)
    {
        for (int j = 0; j < Matrix.get_size(); j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> Matrix[i][j];
        }
    }
    return in;
}

template<class T>
ostream& operator << (ostream& out, MyMatrix<T>& Matrix)
{
    cout << fixed;
    for (int i = 0; i < Matrix.get_size(); i++)
    {
        cout << "|";
        for (int j = 0; j < Matrix.get_size(); j++)
        {
            cout.width(10);
            cout << setprecision(5)
                << Matrix[i][j] << ' ';
        }
        cout << " |";
        cout.width(10);
        cout << setprecision(5) << "\n";
            
    }
    cout << "\n\n";
    return out;
}

