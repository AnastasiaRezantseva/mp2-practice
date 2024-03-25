#ifndef __TLIST_H__
#define __TLIST_H__
//������� ������� virtual � � ringlist �������������� insrtFirst and insertLast

#include <iostream>
#include "tnode.h"

using namespace std;
template<class TData>
class TList {
protected:
    TNode<TData>* pFirst = nullptr;
    TNode<TData>* pLast = nullptr;
    TNode<TData>* pStop = nullptr; //�������� ��������� ����� ������ =null
    TNode<TData>* pCurr = nullptr;  //pCurrent �������
    TNode<TData>* pPrev = nullptr;
    int ListLen = 0;   //����� ������ (���-�� �������)
public:
    TList();
    TList(const TNode<TData>* pFirst_); //�����������  � ����������
    TList(const TList& pList);   //����������� �����������

    friend std::ostream& operator<<(std::ostream& out, const TList<TData>& list) {
        TNode<TData>* tmp = list.GetPFirst();
        int num = 1;
        while (tmp != nullptr) {
            out << num << " node "<<tmp->data << std::endl;
            tmp = tmp->pNext;
            num++;
        }
        return out;
    }

    virtual void Clear();
     ~TList();

    virtual void Next();
    virtual virtual void Sort();
     bool is_Full() const;
     bool is_Empty() const;

    virtual TNode<TData>* Search(const TData& data_);
    //INSERT 
    virtual void InsertFirst(const TData& data_);
    virtual void InsertLast(const TData& data_);
    virtual void InsertBefore(const TData& data_, const TData& NextData);
    virtual void InsertAfter(const TData& data_, const TData& PrevData);

    const int GetLength() const; //
    virtual void Reset(); //���������� �� ������ ������

     TNode<TData>* GetCurrent() const; //���������� ������� �����
     TData getCurrData() const;
     void setCurrData(const TData& _data);

    virtual TList<TData>& operator=(const TList<TData>& pList);

    virtual TNode<TData>* GetPStop()const;
    virtual TNode<TData>* GetPFirst()const;
    
    virtual void SetPStop(TNode<TData>* _pStop);
    virtual void SetPLast(TNode<TData>* _pLast);
    virtual void SetPFirst(TNode<TData>* _pFirst);

    //insert(2)
    virtual void InsertBeforeCurrent(const TData& data_); //�������� ����� �������
    virtual void InsertAfterCurrent(const TData& data_); //�������� ����� ��������

    //functions
    virtual void Remove(const TData& data_); //�������� �� ����� 
    virtual void RemoveFirst();
    virtual void RemoveCurrent();
    bool is_End() const; //������ ��������?

};

//constructors
template <class TData> TList<TData> ::TList() {
    pFirst = pLast = pCurr = pStop = pPrev = nullptr;
    ListLen = 0;
    Reset();
}

template <class TData> TList<TData> ::TList(const TNode<TData>* pFirst_) {
    pFirst = (TNode<TData>*)pFirst_;
    pCurr = pFirst;
    while (pCurr->pNext != nullptr)
    {
        Next();
    }
    pLast = pCurr;
    pCurr = pFirst;
    pStop = pPrev = nullptr;
}
template <class TData> TList<TData> ::TList(const TList& pList) {
    if (pList.pFirst == nullptr)
    {
        return;
    }
    TNode<TData>* oldCurrent = pList.pFirst;
    pFirst = new TNode<TData>(*pList.pFirst);
    TNode<TData>* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode<TData>(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pStop = pLast->pNext;
    pCurr = pFirst;
    pStop = nullptr;
}

template <class TData>  TList<TData>& TList<TData>::operator=(const TList<TData>& pList) {
    if (pList.pFirst == nullptr)
    {
        throw "Error";
    }
    TNode<TData>* oldCurrent = pList.pFirst;
    pFirst = new TNode<TData>(*pList.pFirst);
    TNode<TData>* newCurrent = pFirst;
    oldCurrent = oldCurrent->pNext;
    while (oldCurrent != pList.pStop)
    {
        newCurrent->pNext = new TNode<TData>(oldCurrent->data);
        newCurrent = newCurrent->pNext;
        oldCurrent = oldCurrent->pNext;
    }
    pLast = newCurrent;
    pStop = pLast->pNext;
    pCurr = pFirst;
    pStop = nullptr;

    return *this;
}
template <class TData> void TList<TData>::Clear() {
    if (pFirst == nullptr)
    {
        return;
    }
    pCurr = pFirst;
    TNode<TData>* tmp = pCurr;
    while (pCurr != pStop) {
        pCurr = pCurr->pNext;
        delete tmp;
        tmp = pCurr;
    }
    pCurr = pStop;
    pLast = pStop;
    pFirst = pStop;
}

template <class TData> TList<TData> ::~TList() {
    Clear();
}

//functions

//sort �� ��������
template <class TData> void TList<TData>::Sort() {
    TNode<TData>* elem1 = pFirst;
    while (elem1->pNext != nullptr)
    {
        TNode<TData>* elem2 = elem1->pNext;
        while (elem2 != nullptr)
        {
            if (elem1->data < elem2->data)
            {
                TData tmp = elem1->data;
                elem1->data = elem2->data;
                elem2->data = tmp;
            }
            elem2 = elem2->pNext;
        }
        elem1 = elem1->pNext;
    }
}
template <class TData> void TList<TData> ::Next() {
    if (pCurr == pStop)
    {
        return;
    }
    pPrev = pCurr;
    pCurr = pCurr->pNext;
}

template <class TData> void TList<TData> ::Reset() {
    if (is_Empty()) {
        pCurr = pStop;
    }
    else {
        pCurr = pFirst;
        pPrev = pStop;
    }
    return;
}

template <class TData> bool TList<TData> ::is_Full() const {
    try
    {
        TNode<TData>* tmp = new TNode<TData>();
        if (tmp == 0)
            return 1;
        else
        {
            delete tmp;
            return 0;
        }
    }
    catch (...)
    {
        return 0;
    }
    return true;
}

template <class TData> bool TList<TData> ::is_Empty() const {
    if (pFirst == pStop || ListLen == 0)
        return true;
    else
        return false;
}

template <class TData> bool TList<TData> ::is_End() const {
    if (pCurr == pStop)
        return true;
    else
        return false;
}

template <class TData> TNode<TData>* TList<TData> ::Search(const TData& data_) {
    TNode<TData>* tmp = pFirst;
    while ((tmp != pStop) && (tmp->data != data_)) {
        tmp = tmp->pNext; 
    }
    if (tmp == pStop) {
       throw "Error. Data not found";
    }
    return tmp;
}

template <class TData> void TList<TData>::Remove(const TData& data_) {
    // ����� ����� � ������� ��� ��������
    pCurr = Search(data_);
    if (pCurr == nullptr) {
        throw "Error. List does't have node with this data"; // ����� �� �������, ������� �� �������
    }
    // ���������� ������ �� ����� ����� ��������
    if (pCurr == pFirst) {
        pFirst = pFirst->pNext;
    }
    else {
        pPrev->pNext = pCurr->pNext;
    }
    if (pCurr == pLast) {
        pLast = pPrev;
    }
    // ������������ ������, ���������� ��� �����
    delete pCurr;
    // ���������� ����� ������
    ListLen--;

}

template <class TData> void TList<TData>::RemoveFirst()
{
    if (pFirst != pStop) {
        TNode<TData>* tmp = pFirst;
        pFirst = pFirst->pNext;
        pCurr = pFirst;
        delete tmp;
        ListLen--;
        if (ListLen == 0) {
            pLast = pStop;
        }
    }
}

template <class TData> void TList<TData>::RemoveCurrent() {
    if(pCurr != pStop)
        if (pCurr == pFirst) {
            RemoveFirst();
        }
        else {
            TNode<TData>* tmp = pCurr;
           // pPrev = pPrev->pNext;
            pPrev->pNext = pCurr->pNext;
            pCurr = pCurr->pNext;
            if (pPrev->pNext == pStop)
                pLast = pPrev;
            pPrev->pNext = pCurr;
            delete tmp;
            ListLen--;
        }
}
template <class TData> const int TList<TData>::GetLength() const
{
    return ListLen;
}

//INSERT 
template <class TData> void TList<TData>::InsertFirst(const TData& data_) {
    if (is_Full()) {
        throw "Error. Memory is not enough";
    }
    TNode<TData>* newNode = new TNode<TData>(data_, nullptr);

    if (pFirst != pStop)
    {
        TNode<TData>* oldPFirst = pFirst;
        pFirst = newNode;
        pFirst->pNext = oldPFirst;

    }
    else {
        pFirst = newNode;
    }
    pCurr = pFirst;
    if (pLast == pStop) {
        pLast = pFirst;
    };
    ListLen++;
}

template <class TData> void TList<TData>::InsertLast(const TData& data_) {
    if (is_Empty())
    {
        InsertFirst(data_);
        pLast = pFirst;
        return;
    }
    TNode<TData>* newNode = new TNode<TData>(data_, nullptr);
    pLast->pNext = newNode;
    pLast = newNode;
    ListLen++;
}
template <class TData> void TList<TData>::InsertBefore(const TData& data_, const TData& NextData) {
    if (is_Empty()) {
        throw "Error. List is empty.";
    }
    pCurr = pFirst;
    while ((pCurr != pStop) && (pCurr->data != NextData))
    {
        pPrev = pCurr;
        Next();
    }
    if ((pCurr == pStop) && (pCurr->data != NextData))
    {
        throw "Error. Key not found.";
    }
    TNode<TData>* newNode = new TNode<TData>(data_, pCurr);

    // list have only 1 node
    if (pPrev == pStop) {
        pFirst = newNode;
    }
    else {
        newNode->pNext = pPrev->pNext;
        pPrev->pNext = newNode;
    }
    pCurr = pFirst;
    ListLen++;
}

template <class TData> void TList<TData>::InsertAfter(const TData& data_, const TData& PrevData) {
    if (is_Empty())
        throw "Error. List is empty";
    TNode<TData>* prNode = Search(PrevData);
    if (prNode == pStop)
    {
        return;
    }
    TNode<TData>* tmp = new TNode<TData>(data_, prNode->pNext);
    tmp->pNext = prNode->pNext;
    prNode->pNext = tmp;
    ListLen++;
}

// Set & Get
template <class TData> TNode<TData>* TList<TData>::GetCurrent() const //���������� ������� ����� 
{
    return pCurr;
}
template <class TData> TData TList<TData>::getCurrData() const {
    if (pCurr != pStop)
        return pCurr->data;
    else
        return NULL;
}

template <class TData> void TList<TData>::setCurrData(const TData& _data)
{
    pCurr->data = _data;
}

template <class TData> TNode<TData>* TList<TData>::GetPStop()const {
    return pStop;
}

template <class TData> TNode<TData>* TList<TData>::GetPFirst()const {
    return pFirst;
}

template <class TData> void TList<TData>::SetPStop(TNode<TData>* _pStop) {  //����� ��
    pStop = _pStop;
}

template <class TData> void TList<TData>::SetPLast(TNode<TData>* _pLast) {
    pLast = _pLast;
}
template <class TData> void TList<TData>::SetPFirst(TNode<TData>* _pFirst) {
    pFirst = _pFirst;
}

//insert(2)
//pCur �� ����������� �������
template <class TData> void TList<TData>::InsertBeforeCurrent(const TData& data_) //�������� ����� �������
{
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode<TData>* newNode = new TNode<TData>(data_, pCurr); //pCur->pNext;
        if (newNode == NULL) {
            throw "Error. List doesn't have memory";
        }
        else {
            pCurr = newNode;
            pPrev->pNext = newNode;
            ListLen++;
        }
    }
    //pCurr = pFirst;
}
//pCur �� ����������� �������
template <class TData> void TList<TData>::InsertAfterCurrent(const TData& data_) //�������� ����� ��������
{
    if (is_Empty()) {
        InsertFirst(data_);
    }
    else if (is_End()) {
        InsertLast(data_);
    }
    else {
        TNode<TData>* newNode = new TNode<TData>(data_); 
        if (newNode == NULL) {
            throw "Error. List doesn't have memory";
        }
        else {
            newNode->pNext = pCurr->pNext;
            pCurr->pNext = newNode; 
            pCurr = newNode;
            pPrev = pPrev->pNext;
            ListLen++;
        }
    }
}
#endif