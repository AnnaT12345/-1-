#pragma once
#include <iostream>

class Node // класс отвечающий за узлы
{
public:
    int data;
    Node* pNext;

public:
    Node(int value, Node* pNext = nullptr) // конструктор начальной инициализации
    {
        this->data = value;
        this->pNext = pNext;
    }

};

class List // родительский класс
{

public:
    List(); 
    ~List();

public: // методы
    void Push_Back(int value); 
    int& operator[](const int index);
    void Pop_Front();
    int  SearchMax(List& obj);
    int  GetSize() { return size; }
    void Copying(List& obj);
    void Merger(List& obj, const List& obj2);

private:
    Node* head;
protected:
    int size;
};
