#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class BinarySystem
{
private:
    int* binArr;
    long long int number, exeption;
    int size = 8;
    long long power(int base, int exp)
    {
        long long result(1);
        for (int i = 0; i < exp; i++)
            result = result * base;
        return result;
    }
public:
    BinarySystem()
    {
        number = 0;
    }
    BinarySystem(long long int n)
    {
        binArr = new int[size];
        exeption = n;
        if (exeption == 0) number = 0;
        else {
            do
            {
                if ((exeption <= (-1 * power(2, size - 1) - 1)) || (exeption >= power(2, size - 1))) {
                    cout << "\n Variable " << exeption << " is overloaded. Try again." << endl;
                    cin >> exeption;
                    continue;
                }
                break;
            } while (true);

            if (exeption < 0) number = power(2, size) + exeption;
            else {
                number = exeption;
            }

        }
        long long int count = number;

        long long int iterator = 0;
        while (count > 0) {
            binArr[iterator] = count % 2;
            count = count / 2;
            iterator++;
        }
        for (int i = 1; i <= size - iterator; i++)	binArr[size - i] = 0;
    }
    void print()
    {
        cout<<"Binary representation of a number = ";
        for( int i=this->size-1; i>=0; i--)
        {
            cout << this->binArr[i];
        }
        cout << endl;
    }

    int toDecimal()
    {
        int dec_value = 0;

        for (int i = size - 1; i >= 0; i--) {
            if (binArr[i] == 1)
                dec_value = dec_value + power(2, i);
        }
        if (binArr[size - 1] == 1) dec_value = dec_value - power(2, size);
        return dec_value;
    }
    int* sumForMult(int* temporary, int* obj, int multSize)
    {
        int* result = new int[multSize];

        int carry = 0;

        for (int i = 0; i < multSize; i++) {
            int x1 = temporary[i];
            int x2 = obj[i];
            int sum = x1 + x2 + carry;
            if (sum == 0)
                result[i] = 0;
            else if (sum == 1) {
                result[i] = 1;
                carry = 0;
            }
            else if (sum == 2) {
                result[i] = 0;
                carry = 1;
            }
            else if (sum == 3) {
                result[i] = 1;
                carry = 1;
            }
        }
        return result;
    }
    BinarySystem operator+(BinarySystem obj)
    {
        BinarySystem temporary(*this);

        if ((obj.exeption + temporary.exeption > (power(2, size - 1) - 1)) || (obj.exeption + temporary.exeption < (-1 * power(2, size - 1))))
        {
            cout << "\nCalculation contains variable out of bounds." << endl;
            exit(0);
        }
        BinarySystem result(0);

        int carry = 0;

        for (int i = 0; i < obj.size; i++) {
            int x1 = temporary.binArr[i];
            int x2 = obj.binArr[i];
            int sum = x1 + x2 + carry;
            if (sum == 0)
                result.binArr[i] = 0;
            else if (sum == 1) {
                result.binArr[i] = 1;
                carry = 0;
            }
            else if (sum == 2) {
                result.binArr[i] = 0;
                carry = 1;
            }
            else if (sum == 3) {
                result.binArr[i] = 1;
                carry = 1;
            }
        }
        result.exeption = result.toDecimal();
        result.number = result.toDecimal();
        return result;
    }
    BinarySystem operator-(BinarySystem obj)
    {
        BinarySystem temporary(*this);
        BinarySystem result(0);
        BinarySystem minus(-obj.exeption);

        result = temporary + minus;
        result.exeption = result.toDecimal();
        result.number = result.toDecimal();
        return result;
    }
    BinarySystem operator*(BinarySystem obj)
    {
        BinarySystem temporary(*this);
        if ((temporary.exeption * obj.exeption > (power(2, size - 1) - 1)) || (temporary.exeption * obj.exeption < (-1 * power(2, size - 1))))
        {
            cout << "\nCalculation overloaded" << endl;
            exit(0);
        }
        BinarySystem result(0);

        int* firstElOfSum = new int[2 * size - 1];
        int* secondElOfSum = new int[2 * size - 1];

        for (int i = 0; i < obj.size; i++)
        {
            if ((obj.binArr[i] == 1) && (i == 0))
            {
                for (int t1 = i; t1 < obj.size + i; t1++) firstElOfSum[t1] = temporary.binArr[t1 - i];
                for (int t2 = 0; t2 < i; t2++) firstElOfSum[t2] = 0;
                for (int t3 = obj.size + i; t3 < 2 * size - 1; t3++) firstElOfSum[t3] = 0;
                i++;
            }
            if ((obj.binArr[i] == 0) && (i == 0))
            {
                for (int t1 = 0; t1 < 2 * size - 1; t1++) firstElOfSum[t1] = 0;
                i++;
            }

            if ((obj.binArr[i] == 1) && (i != 0))
            {
                for (int t1 = i; t1 < obj.size + i; t1++) secondElOfSum[t1] = temporary.binArr[t1 - i];
                for (int t2 = 0; t2 < i; t2++) secondElOfSum[t2] = 0;
                for (int t3 = obj.size + i; t3 < 2 * size - 1; t3++) secondElOfSum[t3] = 0;
            }
            if ((obj.binArr[i] == 0) && (i != 0))
            {
                for (int t1 = 0; t1 < 2 * size - 1; t1++) secondElOfSum[t1] = 0;
            }
            firstElOfSum = sumForMult(firstElOfSum, secondElOfSum, 2 * size - 1);
        }
        for (int i = 0; i < obj.size; i++) result.binArr[i] = firstElOfSum[i];

        result.exeption = result.toDecimal();
        result.number = result.toDecimal();
        return result;
    }
};



class SignStack {
private:
    class Node
    {
    public:
        Node* pNext;
        string data;

        Node(string data, Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;

        }
    };
    int Size;
    Node* head;

public:
    SignStack()
    {
        Size = 0;
        head = nullptr;
    }

    ~SignStack()
    {
        clear();
    }



    void push(string data)
    {
        head = new Node(data, head);
        Size++;
    }

    int GetSize() { return Size; }

    void pop()
    {
        Node* temp = head;

        head = head->pNext;

        delete temp;

        Size--;
    }
    void clear()
    {
        while (Size)
        {
            pop();
        }
    }

    string GetLast()
    {
        Node* current = this->head;
        return current->data;
    }
};

class BinaryStack
{
private:
    class Node
    {
    public:
        Node* pNext;
        BinarySystem data;

        Node(BinarySystem data, Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;

        }
    };
    int Size;
    Node* head;

public:
    BinaryStack()
    {
        Size = 0;
        head = nullptr;
    }

    ~BinaryStack()
    {
        clear();
    }
    void push(BinarySystem data)
    {
        head = new Node(data, head);
        Size++;
    }

    int GetSize() { return Size; }

    void pop()
    {
        Node* temp = head;

        head = head->pNext;

        delete temp;

        Size--;
    }
    void clear()
    {
        while (Size)
        {
            pop();
        }
    }
    BinarySystem GetLast()
    {
        Node* current = this->head;
        return current->data;
    }
};

class Calculator
{
private:
    string expression;
    BinaryStack binLst;
    SignStack signLst;





public:
    Calculator(string expr)
    {
        expression = checkInput(expr);
    }
    string checkInput(string expr) // проверка строки
    {
        string result;

        for (int i = 0; i < expr.length(); i++) {
            if ((isdigit(expr[i]) == false) && (expr[i] != '+') && (expr[i] != '-') && (expr[i] != '*') && (expr[i] != ' ')) // булевая функция на целочисленный тип данных
            {
                cout << "Error, try again " << endl;
                getline(cin, expr);
                continue;
            }
        }

        string delete_space; // удаляем пробелы
        for (int i = 0; i < expr.length(); ) {
            if (expr[i] == ' ') {
                if (i == 0 || i == expr.length() - 1) {
                    i++;
                    continue;
                }
                while (expr[i + 1] == ' ')
                    i++;
            }
            delete_space += expr[i++];
        }
        expr = delete_space;
        if (expr[0] == ' ') expr.erase(0, 1);
        if (expr[expr.length()-1] == ' ') expr.erase(expr.length()-1, 1);

        result = expr;
        return result;
    }

    BinarySystem calculateRPN() // функция калькулирования (калькулируем)))
    {




        bool oneNumber = true; // идем до пробела
        for (int i = 0; i < expression.length(); i++)
        {
            if(expression[i] == ' ')
            {
                oneNumber = false;
                break;
            }
        }
        if (oneNumber == true) return BinarySystem(stoi(expression)); // преобразование элемента строки в число

        int left = 0;
        for (int i = 0; i < expression.length(); i++)
        {
            if ((expression[i] == ' ') || (i == expression.length() - 1))
            {
                string temp = "";
                int right = i;
                if (i == expression.length() - 1)
                {
                    temp = expression[i];
                }
                else {
                    for (int j = left; j < right; j++)
                    {
                        temp += expression[j];
                    }
                }
                if (temp == "+" || temp == "-" || temp == "*")
                {
                    cout <<" " << temp << " ";
                    signLst.push(temp);

                    if (signLst.GetSize() == 1 && binLst.GetSize() > 1)
                    {
                        string current = "";
                        current = signLst.GetLast();

                        if (current == "-")
                        {
                            BinarySystem a = binLst.GetLast();
                            binLst.pop();
                            BinarySystem b = binLst.GetLast();
                            binLst.pop();
                            binLst.push(b - a);
                            signLst.pop();

                            current = "";
                        }
                        if (current == "+")
                        {
                            BinarySystem a = binLst.GetLast();
                            binLst.pop();
                            BinarySystem b = binLst.GetLast();
                            binLst.pop();

                            binLst.push(a + b);
                            signLst.pop();

                            current = "";
                        }
                        if (current == "*")
                        {
                            BinarySystem a = binLst.GetLast();
                            binLst.pop();
                            BinarySystem b = binLst.GetLast();
                            binLst.pop();

                            binLst.push(a * b);
                            signLst.pop();

                            current = "";
                        }
                    }
                }
                else {
                    BinarySystem b(stoi(temp));
                    b.print();
                    binLst.push(b);
                }
                left = right + 1; // меняем счетчики
            }
        }

        if ((binLst.GetSize() == 1) && (signLst.GetSize() == 0)) // проверочка на результат
        {
            return binLst.GetLast();
        }
        else {
            cout << "\nIncorrect notation" << endl;
        }
    }
};

int main() {
    string input;
    cout << "Enter your expression: " << endl;
    getline(cin, input); // ф-ция, которая присваивает строке значение с пользовательского ввода
    Calculator value(input);
    BinarySystem result = value.calculateRPN();
    cout << "\nYour answer is: " << result.toDecimal() << endl;
    result.print();

    return 0;

}
