#pragma once
#include "queue.h"
// создание дочерних классов разных модификаторов доступа
class List_private : private List
{
public:
    void Push_Back(int value);
    int& operator[](const int index);
    void Pop_Front();
    int  SearchMax(List_private& obj);
    int  GetSize() { return size; }
    void Copying(List_private& obj);
    void Merger(List_private& obj, List_private& obj2);
};

class List_protected : protected List
{
public:
    void Push_Back(int value);
    int& operator[](const int index);
    void Pop_Front();
    int  SearchMax(List_protected& obj);
    int  GetSize() { return size; }
    void Copying(List_protected& obj);
    void Merger(List_protected& obj, List_protected& obj2);
};

class List_public : public List
{
};
