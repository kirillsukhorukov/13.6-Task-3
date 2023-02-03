#include <iostream>
#include <vector>

using namespace std;

void print_vec (const vector <int> &vec, const int &count)
{
    for (int i=0; i<count; i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    int bufferSize = 10;
    int number = 0;
    vector <int> dataBase (bufferSize);
    //Инициализация переменной индекса в кольцевом буфере
    int countRead = 0;

    //Организуем цикл записи в вектор пока не будет введено "-2" (условие завершения программы)
    while (number != -2)
    {
        bool bufferFull= countRead > bufferSize ? true : false;
        //Запрос очередного числа
        cout << "Please, enter number: ";
        cin >> number;

        //Выввод содержимого вектора с данными
        if (number == -1)
        {
            if (bufferFull) print_vec(dataBase, bufferSize);
            else print_vec(dataBase, countRead);
        }
        //Запись введенного числа в кольцевой буфер
        else
        {
            if (bufferFull)
            {
                for (int i=0; i<bufferSize-1; i++) dataBase[i] = dataBase[i+1];
                dataBase[bufferSize-1]=number;
            }
            else dataBase[countRead]=number;
            countRead++;
        }
    }
    return 0;
}
