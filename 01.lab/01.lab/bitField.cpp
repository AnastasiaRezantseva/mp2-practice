#include "BitField.h"

//конструкторы и диструктор

TBitField::TBitField()
{
	bitLen = 0;
	memLen = 0;
	pMem = 0;
}

TBitField::TBitField(size_t len) : bitLen(len)
{
	memLen = (len + bitsInElem - 1) >> shiftSize;
	pMem = new elem_t[memLen];
	memset(pMem, 0, memLen * sizeof(elem_t));
}

TBitField::TBitField(const TBitField& bf)
{
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = new elem_t[memLen];
	memcpy(pMem, bf.pMem, memLen * sizeof(elem_t));
}

TBitField::TBitField(TBitField&& bf) noexcept
{
	bitLen = 0;//delete
	memLen = 0;//delete
	pMem = nullptr;
	swap(*this, bf);
}

TBitField::~TBitField()
{
	delete[] pMem;
}

//operators

//=
TBitField& TBitField::operator=(const TBitField& bf)
{
	if (this == &bf)
		return *this;
	TBitField tmp(bf);
	swap(*this, tmp);
	return *this;
	/*
	bitLen = bf.bitLen;
	if (memLen != bf.memLen)
	{
		elem_t *p = new elem_t[bf.memLen];
		memLen = bf.memLen;
		delete [] pMem;
		pMem = p;
	}
	memcpy(pMem, bf.pMem, memLen);
	return *this;
	*/
}

TBitField& TBitField::operator=(TBitField&& bf) noexcept
{
	swap(*this, bf);
	return *this;
}

//out
std::ostream& operator<<(std::ostream& ostr, const TBitField& bf)
{
	//формат данных: последовательность из 0 и 1
	size_t len = bf.size();
	for (size_t i = 0; i < len; i++)
	{
		if (bf.test(i))
			ostr << '1';
		else
			ostr << '0';
	}
	return ostr;
}

std::istream& operator>>(std::istream& istr, TBitField& bf) //?????
{
	size_t len = bf.size();
	for (size_t i = 0; i < len; i++)
	{
		if (bf.test(i))
			istr >> bf.pMem[i];
	}
	return istr;
}

//== !=
bool TBitField::operator==(const TBitField& bf) const noexcept
{
	if (bitLen != bf.bitLen)
		return false;
	for (size_t i = 0; i < memLen; i++)
		if (pMem[i] != bf.pMem[i])
			return false;
	return true;
}

bool TBitField::operator!=(const TBitField& bf) const noexcept
{
	return !(*this == bf);
}

//побитовые операции над полем
TBitField TBitField::operator|(const TBitField& bf) //or
{
	if (bitLen != bf.bitLen)
		throw length_error("TBitField objects have different size");

	TBitField tmp(*this);
	for (size_t i = 0; i < bf.memLen; i++)
	{
		tmp.pMem[i] |= bf.pMem[i];
	}
	return tmp;
}

TBitField TBitField::operator&(const TBitField& bf) // and
{
	if (bitLen != bf.bitLen)
		throw length_error("TBitField objects have different size");

	TBitField tmp(*this);
	for (size_t i = 0; i < bf.memLen; i++)
	{
		tmp.pMem[i] &= bf.pMem[i];
	}
	return tmp;
}

TBitField TBitField::operator~(void)
{
	TBitField temp(bitLen);
	for (size_t i = 0; i < memLen; i++)
		temp.pMem[i] = ~pMem[i];
	return temp;
}


//functions
void swap(TBitField& lhs, TBitField& rhs) noexcept
{
	std::swap(lhs.bitLen, rhs.bitLen);
	std::swap(lhs.memLen, rhs.memLen);
	std::swap(lhs.pMem, rhs.pMem);
}

//доступ к биту

void TBitField::set(size_t pos) //установить бит на позиции pos  в 1
{
	if (pos >= bitLen)
		throw out_of_range("bit pos is our of range");
	pMem[GetMemIndex(pos)] |= GetMemMask(pos);
}

void TBitField::reset(size_t pos) //установить бит на позиции pos  в 0
{
	if (pos >= bitLen)
		throw out_of_range("bit pos is our of range");
	pMem[GetMemIndex(pos)] &= ~GetMemMask(pos);
}

bool TBitField::test(size_t pos) const //узнать состояние бита на позиции pos
{
	if (pos >= bitLen)
		throw out_of_range("bit pos is our of range");
	return pMem[GetMemIndex(pos)] & GetMemMask(pos);
}
