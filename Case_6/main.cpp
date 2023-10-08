/*Реализация операций по упаковке шестнадцатеричного дампа вещественного числа (float)
 в символьный одномерный массив и распаковке этого массива
для получения исходного вещественного числа в рамках 32-разрядной архитектуры.*/

#include <iostream>
using namespace std;

// Packing of hexadecimal dump
template <typename T>
void pack(int *kInt, char *k)
{
    int size = 2 * sizeof(T);   // size of an array
    int mask = 0xf000000;       // a mask for hexadecimal digit

    // seventh digit(main)
    int digit = (*kInt >> 28) & 0xf;
    k[size - 1] = (digit > 9 ? char(digit - 10 + 'A')
                             : char(digit + '0'));
    // 6-th - 0-th digits
    for (int i = 0; i < size - 1; i++, mask >>= 4)
    {
        digit = (*kInt & mask) >> 24 - i * 4;
        k[size - 2 - i] = (digit > 9 ? char(digit - 10 + 'A')
                                     : char(digit + '0'));
    }
}

// print of an array with dump
template <typename T>
void print(const char *k)
{
    int size = 2 * sizeof(T);
    for (int i = 0; i < size; i++)
        cout << k[size - i - 1];
    cout << endl;
}

// Unpacking of an array to get a float number
template <typename T>
void unpack(const char *k, int *kInt)
{
    int size = 2 * sizeof(T);
    *kInt = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        char ch = k[i];
        int digit = (ch >= 'A' && ch <= 'F') ? ch - 'A' + 10
                                             : ch - '0';
        *kInt <<= 4;
        *kInt |= digit;
    }
}

int main()
{
    float a, b;
    do
    {
        cout << "Enter number: ";
        cin >> a;
        if (cin.good())
            break;
        else
        {
            cout << "Invalid data. Try again!\n";
            cin.clear();
            while(cin.get() != '\n');
        }
    }
    while (1);
    char *k = new char[2 * sizeof(float)];
    pack<float>((int*)&a, k);

    cout <<"Hexadecimal dump: ";
    print<float>(k);

    unpack<float>(k, (int*)&b);
    cout <<"Source number: " << scientific << b << endl;

    delete[] k;
    return 0;
}

