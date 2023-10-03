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
	size_t bitLen; //длина битового поля, кол-во бит в униферсе
	size_t memLen; //кол-во элементов pMem для хранения битового поля
	elem_t* pMem;

	size_t bitsInElem = std::numeric_limits<elem_t>::digits; //получить сколько разрядов нужно, чтобы сохранить значение данного типа
	size_t shiftSize = std::bit_width(bitsInElem - 1); //Найти наименьшее количество битов, необходимое для представления значения. Find the smallest number of bits needed to represent a value.
	size_t GetMemIndex(size_t pos) const noexcept //индекс в pMem для бита pos
	{
		return pos >> shiftSize; //сдвиг равносилен делению на bitsInElem
	}

	elem_t GetMemMask(size_t pos) const noexcept //битовая маска для бита pos
	{
		//найти остаток от деления на (bitsInElem - 1) и сдвинуть
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
	
	//сравнение
	bool operator==(const TBitField& bf) const noexcept;
	bool operator!=(const TBitField& bf) const noexcept;

	//доступ к биту
	void set(size_t pos); // установить бит на позиции pos  в 1
	void reset(size_t pos);//установить бит на позиции pos  в 0
	bool test(size_t pos) const; //узнать состояние бита на позиции pos

	//побитовые операции над полем
	TBitField operator|(const TBitField& bf); // или
	TBitField operator&(const TBitField& bf); //и
	TBitField operator~(void);//отрицание

	
	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf); //скорее всего проблема тут
	friend std::istream& operator>>(std::istream& istr, TBitField& bf);

};


#endif