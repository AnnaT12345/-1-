#include "queue.h"
#include <iostream>
using namespace std;


List::List()
{

    head = nullptr;
    size = 0;

}

List::~List()
{
    while (size != 0)
    {
        Node* temp = head;
        head = temp->pNext;
        delete temp;
        size--;
    }
}

void List::Push_Back(int value)
{
    if (head == nullptr) // если очередь пуста
    {
        head = new Node(value); // выделяется область памяти под новый объект и его адрес записывается в хэд
    }

    else
    {
        Node* current = this->head; // создаем копию головы

        while (current->pNext != nullptr) // если у текущего эдемента есть указатель на следующий
        {
            current = current->pNext; // переходим на следующий элемент очереди
        }
        current->pNext = new Node(value); // создаем новый конец очереди
    }
    size++;
}

int& List::operator[](const int index) // перегрузка оператора для обращения к конкретному элементу очереди
{
    int counter = 0;
    Node* current = this->head;

    while (current->pNext != nullptr)
    {
        if (counter == index) return current->data;

        current = current->pNext;
        counter++;
    }
}
void List::Pop_Front()
{
    Node* temp = head; // создаем временную переменную для головы
    head = head->pNext; // делаем следующий элемент головой
    delete temp; // удаляем адрес исходной головы

    size--;
}

int List::SearchMax(List& obj) // метод принимает ссылку на объект класса
{
    Node* current = this->head; // создаем временную голову очереди через адрес текущей
    int MAX = this->head->data; // присваиваем переменной макс значение головного узла
    
    while (current != nullptr)
    {
        if (current->data > MAX)
        {
            MAX = current->data;

        }

        current = current->pNext;
    }

    return MAX;
}

void List::Copying(List& obj)
{
    int temp[100]; // создаем массив
    Node* current = obj.head; 
    for (int i = 0; i < obj.size; i++)
    {
        temp[i] = current->data; // в каждый элемент массива копируем значение из очереди
        current = current->pNext; // переходим на следующий элемент
    }

    for (int i = 0; i < obj.size; i++)
    {
        Push_Back(temp[i]); // через функцию добавления заносим все элементы массива в новую очередь
    }
}

void List::Merger(List& obj, const List& obj2) // копируем все элементы двух очередей в один массив 
//и через добавление заносим в новую очередь
{
    int temp[100], temp2[100];

    Node* current = obj.head;
    for (int i = 0; i < obj.size; i++)
    {
        temp[i] = current->data;
        current = current->pNext;
    }
    int lenght = obj2.size + obj.size;
    Node* current2 = obj2.head;
    for (int i = obj.size; i < lenght; i++)
    {
        temp[i] = current2->data;
        current2 = current2->pNext;
    }

    for (int i = 0; i < lenght; i++)
    {
        Push_Back(temp[i]);
    }
}
