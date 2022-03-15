#include "queue.h"
#include "queue1.h"
#include <iostream>
#include <string>;
using namespace std;

template <class T>
void Merger(T* Que)
{
    int number1, number2, number3;
    cout << "Выберите очереди которые обьединятся" << endl;
    cin >> number1; cin >> number2; cout << endl;
    cout << "Выберите куда произойдет слияние двух очередей" << endl;
    cin >> number3;
    Que[number3].Merger(Que[number1], Que[number2]);
}

template <class T>
void CopyingQueue(T* Que, T& obj)
{
    int number;
    cout << "Куда скопировать" << endl;
    cin >> number;
    Que[number].Copying(obj);

}


int EnterQueue()
{
    cout << "Введите номер очереди" << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

template <class T>
void SearchMaxItem(T& obj, const int number)
{
    cout << "Максимальный элемент очереди" << " #" + to_string(number) << endl;
    cout << obj.SearchMax(obj) << endl;


}

template <class T>
void DeleteItem(T& obj)
{
    obj.Pop_Front();
}

template <class T>
void ShowQueue(T& obj, const int number)
{
    cout << "Состояние очереди" << "#" + to_string(number) << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < obj.GetSize(); i++)
    {
        cout << obj[i] << "  ";
    }
    cout << endl;
    cout << "-------------------------" << endl;

}

template <class T>
void AddingItem(T& obj, const int number)
{
    cout << "Добавить элемент в текущую очередь" << " #" + to_string(number) << endl;
    int value;
    cout << "Введите значение: ";
    cin >> value;
    obj.Push_Back(value);

}

void Error()
{
    cout << "Выберите существущий пункт меню (1-8)" << endl;
}

template <class T>
void MainMenu(T* QueList)
{
    int choice = 0;
    int c;
    int work = 1;
    while (work)
    {
        cout << "<----------Главное меню---------->" << endl;
        cout << "1 – Добавление элемента очереди" << endl;
        cout << "2 – Извлечение элемента очереди" << endl;
        cout << "3 – Вывод очереди на экран" << endl;
        cout << "4 – Нахождение максимального элемента очереди" << endl;
        cout << "5 - Выбор очереди для работы" << endl;
        cout << "6 – Создание копии очереди" << endl;        cout << "7 – Слияние двух очередей" << endl;        cout << "8 – Выбор дочернего класса" << endl;        cout << "9 – Выход из программы" << endl;        cout << endl;
        cout << "Выберите пункт меню ---->"; cin >> c;
        system("cls");

        switch (c)
        {
        case 1:  AddingItem(QueList[choice], choice);
            break;

        case 2: DeleteItem(QueList[choice]);
            break;

        case 3:ShowQueue(QueList[choice], choice);
            break;

        case 4: SearchMaxItem(QueList[choice], choice);
            break;

        case 5: choice = EnterQueue();
            break;

        case 6: CopyingQueue(QueList, QueList[choice]);
            break;

        case 7: Merger(QueList);
            break;

        case 8:
            work = 0;
            break;

        case 9: exit(0);
            break;

        default: Error();
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List_private* Queue_private = NULL; // создаем указатели на объекты дочерних классов
    List_protected* Queue_protected = NULL;
    List_public* Queue_public = NULL;
    int work = 1;
    while (work) {
        cout << "Выберите дочерний класс" << endl; cout << "1 - Private" << endl; cout << "2 - Protected" << endl; cout << "3 - Public" << endl; int select = 0; cin >> select;
        cout << "Задайте количество очередей" << endl; int num = 1; cin >> num;

        system("cls");

        switch (select)
        {
        case 1:
            Queue_private = new List_private[num]; // создаем динамический массив очередей
            MainMenu(Queue_private); // передаем массив в функцию меню
            delete[] Queue_private;
            break;
        case 2:
            Queue_protected = new List_protected[num];
            MainMenu(Queue_protected);
            delete[] Queue_protected;
            break;
        case 3:
            Queue_public = new List_public[num];
            MainMenu(Queue_public);
            delete[] Queue_public;
            break;

        default:cout << "error";
            break;
        }
    }

    return 0;
}