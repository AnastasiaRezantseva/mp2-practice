#ifndef _BITFIELD_H_
#define _BITFIELD_H_
#include <bit>
#include <bitset>
#include <iostream>
#include <limits>

#include <ostream>
#include <istream>


using elem_t = unsigned char;
using std::out_of_range;
using std::length_error;

class TBitField {
private:
	size_t bitLen; //����� �������� ����, ���-�� ��� � ��������
	size_t memLen; //���-�� ��������� pMem ��� �������� �������� ����
	elem_t* pMem;

	size_t bitsInElem = std::numeric_limits<elem_t>::digits; //�������� ������� �������� �����, ����� ��������� �������� ������� ����
	size_t shiftSize = std::bit_width(bitsInElem - 1); //����� ���������� ���������� �����, ����������� ��� ������������� ��������. Find the smallest number of bits needed to represent a value.
	size_t GetMemIndex(size_t pos) const noexcept //������ � pMem ��� ���� pos
	{
		return pos >> shiftSize; //����� ���������� ������� �� bitsInElem
	}

	elem_t GetMemMask(size_t pos) const noexcept //������� ����� ��� ���� pos
	{
		//����� ������� �� ������� �� (bitsInElem - 1) � ��������
		return 1 << (pos & ((bitsInElem - 1)));
	}
public:
	TBitField();
	TBitField(size_t len);
	TBitField(const TBitField& bf);
	TBitField(TBitField&& bf) noexcept;
	TBitField& operator=(const TBitField& bf);
	TBitField& operator=(TBitField&& bf) noexcept;
	~TBitField();

	size_t size() const noexcept
	{
		return bitLen;
	}
	friend void swap(TBitField& lhs, TBitField& rhs) noexcept;
	
	//���������
	bool operator==(const TBitField& bf) const noexcept;
	bool operator!=(const TBitField& bf) const noexcept;

	//������ � ����
	void set(size_t pos); // ���������� ��� �� ������� pos  � 1
	void reset(size_t pos);//���������� ��� �� ������� pos  � 0
	bool test(size_t pos) const; //������ ��������� ���� �� ������� pos

	//��������� �������� ��� �����
	TBitField operator|(const TBitField& bf); // ���
	TBitField operator&(const TBitField& bf); //�
	TBitField operator~(void);//���������

	
	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf); //������ ����� �������� ���
	friend std::istream& operator>>(std::istream& istr, TBitField& bf);

};


#endif