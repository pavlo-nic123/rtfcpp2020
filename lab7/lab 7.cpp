#include "SLList.h"

int main()
{
    SLList* full_list = nullptr;
    full_list = SLList::beginList(rand()% 5+ 0); // инициализируем список
    SLList* list = full_list; //запоминаем начальный указатель
    int a[5] = { 1, 4, 2, 4, 2};
    for (int i = 0; i < 9; i++)
    {
        list = list->addElement(rand() % 5 + 0);
    }
    cout << "List:";
    printSLList(full_list);
    del_twins_SLList(full_list);
    cout << "Without twins:";
    printSLList(full_list);
    int k = 2;
    cout << k << " element from tail: ";
    cout << elem_from_tail(k, full_list);
}