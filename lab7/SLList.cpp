#include "SLList.h"

SLList* SLList::next() { return m_nextElem; };

bool SLList::hasNext() { return (m_nextElem != nullptr); };

SLList* SLList::beginList(int data)
{
    return new SLList(data);
};

SLList* SLList::addElement(int data)
{
    if (!m_nextElem)
    {
        m_nextElem = new SLList(data);
        return m_nextElem;
    };
    return nullptr;
};

void SLList::removeNext()
{
    if (this->hasNext())
    {
        SLList* tmp = m_nextElem->next();
        delete m_nextElem;
        m_nextElem = tmp;
    }
};

void printSLList(const SLList* list)
{
    SLList list_ = *list;
    cout << list_.getData();
    while (list_.hasNext())
    {
        list_ = *list_.next();
        cout << list_.getData();
    }
    cout << endl;
}

void del_twins_SLList(SLList* list)
{
    SLList* i_elem = list;
    SLList* j_elem = list;
    while (i_elem != nullptr && i_elem->hasNext())
    {
        while (j_elem != nullptr && j_elem->hasNext())
        {
            if (i_elem->getData() == j_elem->next()->getData())
            {
                j_elem->removeNext();
            }
            else
                j_elem = j_elem->next();
        }
        i_elem = i_elem->next();
        j_elem = i_elem;
    }
}

int elem_from_tail(int k, const SLList* list)
{
    if (list == nullptr)
        return NULL;

    SLList list_ = *list;
    int length = 1;

    while (list_.hasNext())
    {
        length++;
        list_ = *list_.next();
    }

    if (length - (k - 1) <= 0)
        return NULL;


    k--;
    int id = length - k;
    list_ = *list;
    for (int i = 1; i < id; i++)
    {
        list_ = *list_.next();
    }
    return list_.getData();

}