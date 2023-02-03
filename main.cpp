#include <iostream>
#include <vector>

using namespace std;
//Функция вывода вектора с заданного индекса кругового буфера
void print_vec (const vector <int> &vec, const int &begin, const int &end)
{
    for (int i=0; i<end; i++)
    {
        int index = begin + i;
        if (index >= vec.size()) index-=vec.size();
        cout << vec[index] << " ";
    }
    cout << endl;
}

int main() {
    //Инициализация размера буфера
    int bufferSize = 10;
    //Инициализация вектора с данными
    vector <int> dataBase (bufferSize);
    //Инициализация счетчика записи в буфер
    int countRead = 0;
    //Инициализация переменной начального индекса в кольцевом буфере
    int beginIndex = 0;
    //Организуем цикл записи в вектор пока не будет введено "-2" (условие завершения программы)
    int number = 0;
    while (number != -2)
    {
        //Инициализация флага заполнения буфера
        bool bufferFull= countRead > bufferSize ? true : false;
        //Запрос очередного числа
        cout << "Please, enter number: ";
        cin >> number;

        //Выввод содержимого вектора (буфера) с данными
        if (number == -1)
        {
            if (bufferFull) print_vec(dataBase, beginIndex, bufferSize);
            else print_vec(dataBase, 0,countRead);
        }
        //Запись введенного числа в кольцевой буфер
        else
        {
            if (beginIndex == bufferSize) beginIndex=0;
            dataBase[beginIndex]=number;
            countRead++;
            beginIndex++;
        }
    }
    return 0;
}