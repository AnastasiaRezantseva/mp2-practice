#ifndef _TSET_H_
#define _TSET_H_

#include "BitField.h"

class TSet
{
private:
    size_t maxPower;       // ������������ �������� ��������� - �������� ��������
    TBitField bitField; // ������� ���� ��� �������� ������������������� �������
public:
    TSet(int mp) : maxPower(mp), bitField(mp) {};
    TSet(const TSet& s);       // ����������� �����������
    TSet(const TBitField& bf) : maxPower(bf.size()), bitField(bf) {}; // ����������� �������������� ����
    operator TBitField();      // �������������� ���� � �������� ����
 
    // ������ � �����
    size_t GetMaxPower(void) const    // ������������ �������� ���������
    {
        return maxPower;
    }
    void InsElem(size_t elem);       // �������� ������� � ���������
    void DelElem(size_t elem);       // ������� ������� �� ���������
    bool IsMember(const int elem) const // ��������� ������� �������� � ���������
    {
        return bitField.test(elem);
    }
   
    bool operator== (const TSet& s) const // �����
    {
        return bitField ==s.bitField;
    }

    int operator!= (const TSet& s) const // �� �����
    {
        return !(*this == s);
    }
    TSet& operator=(const TSet& s);  // ������������
 
    // ���������-������������� ��������
    // ������� ������ ���� �� ���� �� ��������
    TSet operator+ (size_t elem); // ����������� � ���������
    TSet operator- (size_t elem); // �������� � ���������
    
   
    // ������� ������ ���� �� ���� �� ��������
    TSet operator+ (const TSet& s);  // �����������
    TSet operator* (const TSet& s);  // �����������
    TSet operator~ ();           // ����������

    friend std::istream& operator>>(std::istream& istr, TSet& bf);
    friend std::ostream& operator<<(std::ostream& ostr, const TSet& s);
};
#endif