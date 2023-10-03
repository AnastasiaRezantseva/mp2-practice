#ifndef _TSET_H_
#define _TSET_H_

#include "BitField.h"

class TSet
{
private:
    size_t maxPower;       // максимальная мощность множества - мощность универса
    TBitField bitField; // битовое поле для хранения характеристического вектора
public:
    TSet(int mp) : maxPower(mp), bitField(mp) {};
    TSet(const TSet& s);       // конструктор копирования
    TSet(const TBitField& bf) : maxPower(bf.size()), bitField(bf) {}; // конструктор преобразования типа
    operator TBitField();      // преобразование типа к битовому полю
 
    // доступ к битам
    size_t GetMaxPower(void) const    // максимальная мощность множества
    {
        return maxPower;
    }
    void InsElem(size_t elem);       // включить элемент в множество
    void DelElem(size_t elem);       // удалить элемент из множества
    bool IsMember(const int elem) const // проверить наличие элемента в множестве
    {
        return bitField.test(elem);
    }
   
    bool operator== (const TSet& s) const // равно
    {
        return bitField ==s.bitField;
    }

    int operator!= (const TSet& s) const // не равно
    {
        return !(*this == s);
    }
    TSet& operator=(const TSet& s);  // присваивание
 
    // теоретико-множественные операции
    // элемент должен быть из того же универса
    TSet operator+ (size_t elem); // объединение с элементом
    TSet operator- (size_t elem); // разность с элементом
    
   
    // элемент должен быть из того же универса
    TSet operator+ (const TSet& s);  // объединение
    TSet operator* (const TSet& s);  // пересечение
    TSet operator~ ();           // дополнение

    friend std::istream& operator>>(std::istream& istr, TSet& bf);
    friend std::ostream& operator<<(std::ostream& ostr, const TSet& s);
};
#endif