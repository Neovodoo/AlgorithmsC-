// Реализация расчётов заданного арифмитического выражения, с объектами класса Float (а также его создание)


#include <iostream>

using namespace std;

class Float
{
private:
    float number;
public:
    Float (const Float & object):number (object.number)
    {
    }
    Float (float n = 0.0):number (n)
    {
    }
    Float & operator= (const Float & object) //копирующее присваивание
    {
        number = object.number;
        return *this;
    }
    Float operator+ (Float);
    Float operator- (Float);
    Float operator* (Float);
    Float operator/ (Float);

    friend istream & operator>> (istream &, Float &);
    friend ostream & operator<< (ostream &, Float &);
};

Float Float::operator+ (Float n)
{
    Float temporary (*this);
    temporary.number += n.number;
    return temporary;
}

Float Float::operator- (Float n)
{
    Float temporary (*this);
    temporary.number -= n.number;
    return temporary;
}

Float Float::operator* (Float n)
{
    Float temporary (*this);
    temporary.number *= n.number;
    return temporary;
}

Float Float::operator/ (Float n) {
    if (n.number == 0) {
        cout << "Error. You can't divide to null ";
    } else {
        Float temporary(*this);
        temporary.number /= n.number;
        return temporary;
    }
}

ostream & operator<< (ostream & stream, Float & n)
{
    return stream << n.number;
}

istream & operator>> (istream & stream, Float & n)
{
    float temporary (0);
    stream >> temporary;
    if (stream.fail ())
        stream.clear ();
    while (stream.get () != '\n');
    n.number = temporary;
    return stream;
}



int main ()
{
    Float
            a,
            b,
            c,
            d,
            e;
    cout << "Your expression is: (a+b-c)*d/e" << endl;
    do
    {
        cout << "Enter value (a): ";
        cin >> a;
        if (cin.good ()) //Превращение букв в 0
            break;
      /*  else
        {
            cout << "Invalid data!\n";
            cin.clear ();
            while (cin.get () != '\n');
        } */
      // Сверху пытался поймать случаи "dskjdks" и подобные ему, но они просто зануляются, предполагаю, что нужно отдельно в классе прописывать и адаптировать
    }
    while (1);
    do
    {
        cout << "Enter value (b): ";
        cin >> b;
        if (cin.good ())
            break;

    }
    while (1);
    do
    {
        cout << "Enter value (c): ";
        cin >> c;
        if (cin.good ())
            break;

    }
    while (1);
    do
    {
        cout << "Enter value (d): ";
        cin >> d;
        if (cin.good ())
            break;
    }
    while (1);
    do
    {
        cout << "Enter value (e): ";
        cin >> e;
        if (cin.good ())
            break;
    }
    while (1);

    Float m;
    m = (a + b -c ) * d / e;
    cout << "\n";
    cout << "(a + b - с) * d / e = ";
    cout << m << endl;

    return 0;
}
