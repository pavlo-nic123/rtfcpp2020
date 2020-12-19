#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class SLList
{
    SLList* m_nextElem;
    int m_data;
    SLList() = delete;
    SLList(int data) { m_data = data; m_nextElem = nullptr; };
    //~SLList() { delete m_nextElem; };
public:
    int getData() { return m_data; };
    void setData(int data) { m_data = data; };
    SLList* next();
    bool hasNext();
    static SLList* beginList(int data);
    SLList* addElement(int data);
    void removeNext();
};

void printSLList(const SLList* list);
void del_twins_SLList(SLList* list);
int elem_from_tail(int k, const SLList* list);