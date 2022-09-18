/*
 * Ввести целочисленный массив из N целых чисел.
 * Отсортировать этот массив по возрастанию/убыванию методом пузырька
*/
#include <iostream>
#include <string>

using namespace std;
using std :: string;

//Сравнение
bool compare(int first, int second) {
    if (first > second) {
        return 1;
    }
    else return 0;
}

//Замена
int change (int& first, int& second){
    int temp;
    temp = first;
    first = second;
    second = temp;
}

//Сортировка
int sort (int *arr, int size, int choice){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (choice == 1) {
                if (compare(arr[j], arr[j + 1])) {
                    change(arr[j], arr[j+1]);
                }
            }
            else
                if (!compare(arr[j], arr[j + 1])) {
                change(arr[j], arr[j+1]);
            }
        }
    }
}

// Вывод отсортированного массива на экран
void print (int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Проверка на целочисленные значения
bool checkingInt(string check){
    for (int i =0; i < check.length(); i++)
        if(isdigit(check[i]) == 0 && check[0]!='-')
            return 0;
        return 1;
}


int main()
{
    int *arr; // указатель для выделения памяти под массив
    int size; // размер массива
    int choice; //выбор сортировки

    restart:
    cout << "Введите размер массива: ";
    string size1;
    cin >> size1;

//Проверка ввода размера массива
    if (!checkingInt(size1)) {
        cout << "Размер массива указан некорректно!" << endl;
        goto restart; // не хорошо
    }
    else size = stoi(size1); // из строки в целое число

    arr = new int[size]; // выделение памяти под массив

    // заполнение массива
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        string check ;
        cin >> check;
        if (checkingInt(check))
        arr[i] = stoi(check);
        else {
            cout << "Неккоректный ввод, повторите" << endl;
            i = i-1;
        }
    }

    cout << "Нажмите 1 для сортировки по возрастанию, 0 для сортировки по убыванию" << endl;
    cin >> choice;

    //сортировка и вывод массива на экран
    sort(arr, size, choice);
   print(arr, size);

    delete [] arr; // освобождение памяти;

    return 0;
}
