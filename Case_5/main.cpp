#include <iostream>

using namespace std;

template<typename T>
void pack(T n, char* p)
{
    T mask;
    int size((8 * sizeof(T)) / 3);
    switch (sizeof(T))
    {
    case 1: 
        mask = 070;
        p[size] = char(((n >> 6) & 03) + 48);
        break;

    case 2: 
        mask = 070000;
        p[size] = char(n < 0 ? '1' : '0');
        break;

    case 4: 
        mask = 07000000000;
        p[size] = char(((n >> 30) & 03) + 48);
        break;
    }
    int base(3 * ((8 * sizeof(T) / 3) - 1));
    for (int i = 0; i < size; ++i, mask >>= 3)
        p[size - i - 1] = char(((n & mask) >> base - i * 3) + 48);
}

long long power(int base, int powValue)
{
    long long result = 1;
    for (int i = 0; i < powValue; i++)
        result = result * base;
    return result;
}

int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, p = 0, last;
    while (octalNumber != 0)
    {
        last = octalNumber % 10;
        octalNumber = octalNumber / 10;
        decimalNumber = decimalNumber + last * power(8, p);
        ++p;
    }
    return decimalNumber;
}

template<typename T>
void unpack(char* p, bool sign)
{
    int size(1 + (8 * sizeof(T)) / 3);
    long long n(0);
    for (int i = 0; i < (size); ++i)
        n = n + (p[size - i - 1] - 48) * power(10, (size - i - 1));
    cout << "Source number in oct: " << n << endl;
    if (sign == 0) cout << "Unpacked source number in dec:  " << octalToDecimal(n) << endl;
    else
    {
        long long subtrahend;
        switch (sizeof(T))
        {
        case 1:
            subtrahend = 378;
            break;

        case 2:
            subtrahend = 177778;
            break;

        case 3:
            subtrahend = 37777777778;
            break;
        }
        n = (n - subtrahend) * (-1);
        cout << "Unpacked source number in dec:  " << (-1) * octalToDecimal(n) << endl;
    }
}
template<typename T>
void print( char* p)
{
    int size(1 + (8 * sizeof(T)) / 3);
    cout << " <<  ";
    for (int i = 0; i < size; ++i)
        cout << p[size - i - 1] << "  ";
    cout << ">> " << endl;
}

int main() {
    int n;
    do
    {
        cout << "Enter the value: " << endl;
        cin >> n;
        if (cin.good())
            break;
        else
        {
            cout << "Invalid data!\n";
            cin.clear();
            while (cin.get() != '\n');
        }
    } while (1);
    char* p;
    bool sign = 0;

    p = new char[11];
    pack<int>(n, p);
    print<int>(p);
    if ((p[10] - 48) == 3) sign = !sign;
    unpack<int>(p, sign);
    delete[] p;

    if ((n > -32769) && (n < 32768))
    {
        p = new char[6];
        pack<short int>(n, p);
        print<short int>(p);
        if ((p[10] - 48) == 3) sign = !sign;
        unpack<short int>(p, sign);
        delete[] p;
    }

    if ((n > -129) && (n < 128))
    {
        p = new char[3];
        pack<char>(n, p);
        print<char>(p);
        if ((p[10] - 48) == 3) sign = !sign;
        unpack<char>(p, sign);
        delete[] p;
    }
    return 0;
}
