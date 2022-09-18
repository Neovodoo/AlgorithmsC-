#include <iostream>
#include <cmath>

using namespace std;

class BinarySystem{
private:
    int *arr; //выделила память под динамический массив (число в двоичной системе)
    int numberDec; // десятичное число на вход
    int size; // кол-во битов для хранения десятичного числа

public:
    BinarySystem (int decToConv, int sizeOfArray) {
        numberDec = decToConv; //Присваиваю полям класса значения
        size = sizeOfArray;
        arr = new int[sizeOfArray];
        int i;
        if (-pow(2, size-1) <= decToConv && decToConv <= pow(2, size-1) - 1) { //Проверка для перевода
            if (decToConv < 0) {
                decToConv = pow(2, size) + decToConv;  // 2 в степени - верхняя числовая граница для системы исчисления
            }
            for (i = 0; decToConv > 0; i++) {
                arr[i] = decToConv % 2;
                decToConv = decToConv / 2; // перевожу десятичное число в двоичное
            }
        } else {
            cout << "Overload. Incorrect input" << endl;
            exit(0); // резко обраваем программу, не по-человечески
        }

    }
// 127 + 32    1111111 +  10100101        -128 < 11111111 + 100101010 < 127

    BinarySystem operator+(BinarySystem object) { //число, которое прибавляем

        BinarySystem variable(*this); // число, к которому прибавляем (ссылка на объект класса)
        BinarySystem result(0, object.size);

        if (-1*pow(2,size-1) <= (variable.numberDec) + (object.numberDec) && (variable.numberDec) + (object.numberDec) <= pow(2, size - 1)-1) {

            int remainder = 0;

            for (int i = 0; i < object.size; i++) {
                int x1 = variable.arr[i];        //  sum = 0 + 0 + 0    0 1 2 3
                int x2 = object.arr[i];
                int sum = x1 + x2 + remainder;
                if (sum == 0)
                    result.arr[i] = 0;
                else if (sum == 1) {
                    result.arr[i] = 1;
                    remainder = 0;
                } else if (sum == 2) {
                    result.arr[i] = 0;
                    remainder = 1;
                } else if (sum == 3) {
                    result.arr[i] = 1;
                    remainder = 1;
                }
            }
            return result;
        } else {
            cout << "Overload. Incorrect input" << endl;
            exit(0);
        }
    }


    BinarySystem operator-(BinarySystem object){

        BinarySystem variable(*this);
        BinarySystem result(0, object.size);
        BinarySystem minus(-1 * object.numberDec, object.size);

            result = variable + minus;
            return result;
    }

    BinarySystem operator*(BinarySystem object){

        int number;

        BinarySystem variable(*this);
        BinarySystem result(0, object.size);
        number = object.numberDec;


        if (-1*pow(2,size-1) <= (variable.numberDec) * (object.numberDec) && (variable.numberDec) * (object.numberDec) <= pow(2, size - 1)-1){

            for (int i = 0; i < abs(number); i++) {
                result = variable + result;
            }
            return result;
        }
        else{
            cout << "Overload. Incorrect input" << endl;
            exit(0);
        }
    }






    void printBin (){ // вывод в бинарном виде
        cout<<"Binary representation of a number = ";
        for( int i=this->size-1; i>=0; i--)
        {
            cout << this->arr[i];
        }
        cout << endl;
    }

    int binToDecimal () // перевод в десятичное число
    {
        int value = 0;

        for (int i = size - 1; i >= 0; i--) {
            if (arr[i] == 1)
                value = value + pow(2,i);
        }

        if(value>pow(2,size-1)-1)
            value = value - pow(2,size);

        return value;
    }


};

int main() {

    int arrSize = 8;

    int first;
    cout << "Enter the first number: ";
    cin >> first;
    cout << endl;
    BinarySystem a (first,arrSize) ;
    a.printBin();
    cout << endl;

    int second;
    cout << "Enter the second number: ";
    cin >> second;
    cout << endl;
    BinarySystem b (second, arrSize);
    b.printBin();
    cout << endl;

    cout << "Press 1 to add, 2 to subtract, 3 to multiplication: ";
    int choice;
    cin >> choice;
    cout << endl;

    BinarySystem c (0, arrSize);

    if (choice==1){
        c = a + b;
        cout << "Your answer is: " << endl;
        c.printBin();
        cout << "Decimal: " << c.binToDecimal() << endl;
    }

    if (choice==2){
        c = a - b;
        cout << "Your answer is: " << endl;
        c.printBin();
        cout << "Decimal: " << c.binToDecimal() << endl;
    }

    if (choice==3){
        c = a * b;
        cout << "Your answer is: " << endl;
        c.printBin();
        cout << "Decimal: " << c.binToDecimal() << endl;
    }


}

