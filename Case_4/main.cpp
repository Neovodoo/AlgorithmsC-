/*программы для вычисления значения арифметического выражения, операнды которого объявлялись с помощью шестнадцатеричных литералов,
операнды вводятся с консоли.
Операнды арифметического выражения - целые двузначные шестнадцатеричные числа типа char.
Формат представления - прямой код для неотрицательных и дополнительный код для отрицательных чисел.*/

#include <iostream>

int main() {
    using namespace std;

    char x1;
    char x2;
    char x3;
    char result;
    int enter;

    do
    {
        cout << "Enter x1: " << endl;
        cin >> hex >> enter;
        while (cin.fail())  //Проверка циклом на корректный ввод
        {
            cin.clear();
            while(cin.get() != '\n');
            cout << "Incorrect input. Try again: " << endl;
            cin >> hex >> enter;
            if (!(cin.fail())) break;
        }
        if (enter & 0200) // Проверка на дополнительный код
            enter ^= 037777777400; //Перевод числа из дополнительного кода в отрицательное

    }
    while(!(enter >= -128 && enter <= 127)); //Проверка на трёхзначные числа
    cout << "Decimal: " << enter << endl << '\n'; //Вывод десятичного значения
    x1 = enter;

    do
    {
        cout << "Enter x2: " << endl;
        cin >> hex >> enter;
        while (cin.fail())
        {
            cin.clear();
            while(cin.get() != '\n');
            cout << "Incorrect input. Try again: " << endl;
            cin >> hex >> enter;
            if (!(cin.fail())) break;
        }
        if (enter & 0200)
            enter ^= 037777777400;
    }
    while(!(enter >= -128 && enter <= 127));
    cout << "Decimal: " << enter << endl << '\n';
    x2 = enter;

    do
    {
        cout << "Enter x3: " << endl;
        cin >> hex >> enter;
        while (cin.fail())
        {
            cin.clear();
            while(cin.get() != '\n');
            cout << "Incorrect input. Try again: " << endl;
            cin >> hex >> enter;
            if (!(cin.fail())) break;
        }
        if (enter & 0200)
            enter ^= 037777777400;
    }
    while(!(enter >= -128 && enter <= 127));
    cout << "Decimal: " << enter << endl << '\n';
    x3 = enter;

    result = (x1 - x2) * x3;
    cout << "Your expression is (x1 - x2) * x3:" << endl << '\n';
    cout << "Decimal result : ";
    cout << dec << int(result) << endl;
    cout << "Hexadecimal result : ";
    cout << hex << int(result & 0377) << endl;

    return 0;
}


