#include "TSet.h"
#include <iostream>

TSet::TSet(const TSet& s) : bitField(s.bitField)
{
	maxPower = s.GetMaxPower();
}

// �������������� ���� � �������� ����
TSet::operator TBitField()
{
	TBitField tmp(bitField);
	return tmp;
}
std::istream& operator>>(std::istream& istr, TSet& bf)
{
	size_t i, n, val;
	//����� ���������
	n = bf.GetMaxPower();
	for (i = 0; i < n; i++)
	{
		istr >> val;
		bf.InsElem(val);
		
	}
	return istr;
}
//operator
//out
std::ostream& operator<<(std::ostream& ostr, const TSet& s)
{

	size_t i, n;
	//����� ���������
	n = s.GetMaxPower();
	for (i = 0; i < n; i++)
	{
		ostr << s.IsMember(i) << " ";
	}
	return ostr;
}


TSet& TSet::operator=(const TSet& s) // ������������
{
	maxPower = s.GetMaxPower();
	bitField = TBitField(maxPower);
	bitField = bitField | s.bitField;
	return *this;
}

TSet TSet::operator+(const TSet& s) // �����������
{
	TSet tmp(std::max(maxPower,s.GetMaxPower()));
	tmp.bitField = bitField | s.bitField;
	return tmp;
}

TSet TSet::operator*(const TSet& s) // �����������
{
	TSet tmp(std::max(maxPower, s.GetMaxPower()));
	tmp.bitField = bitField & s.bitField;
	return tmp;
}

TSet TSet::operator~(void) // ����������
{
	TSet tmp(maxPower);
	tmp.bitField = ~bitField;
	return tmp;
}

//����������� � ���������
TSet TSet::operator+(size_t elem)
{
	TSet tmp(bitField);
	tmp.InsElem(elem);
	return tmp;
}

// �������� � ���������
TSet TSet::operator-(size_t elem)
{
	TSet tmp(bitField);
	tmp.DelElem(elem);
	return tmp;
}

//functions
void TSet::InsElem(size_t elem) // �������� ������� � ���������
{
	if (elem >= maxPower)
		throw out_of_range("elem is out of universe");
	bitField.set(elem);
}

void TSet::DelElem(size_t elem) //
{
	if (elem >= maxPower)
		throw out_of_range("elem is out of universe");
	bitField.reset(elem);
}
