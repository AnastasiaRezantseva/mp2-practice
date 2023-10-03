#include <iomanip>
#ifndef USE_SET 
#define USE_SET // Использовать класс TSet,
                // закоментировать, чтобы использовать битовое поле

// Использовать класс TBitField

#include "Bitfield.h"
/*
int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование программ поддержки битового поля" << std::endl;
    std::cout << "             Решето Эратосфена" << std::endl;
    std::cout << "Введите верхнюю границу целых значений - ";
    std::cin >> n;
    TBitField s(n + 1);
    // заполнение множества
    for (m = 2; m <= n; m++)
        s.set(m);
    // проверка до sqrt(n) и удаление кратных
    for (m = 2; m * m <= n; m++)
        // если m в s, удаление кратных
        if (s.test(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.test(k))
                    s.reset(k);
    // оставшиеся в s элементы - простые числа
    std::cout << std::endl << "Печать множества некратных чисел" << std::endl << s << std::endl;
    std::cout << std::endl << "Печать простых чисел" << std::endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.test(m))
        {
            count++;
            std::cout << std::setw(3) << m << " ";
            if (k++ % 10 == 0)
                std::cout << std::endl;
        }
    std::cout << std::endl;
    std::cout << "В первых " << n << " числах " << count << " простых" << std::endl;
}
//#else
*/
#include "TSet.h"

int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование программ поддержки множества" << std::endl;
    std::cout << "              Решето Эратосфена" << std::endl;
    std::cout << "Введите верхнюю границу целых значений - ";
    std::cin >> n;
    TSet s(n + 1);
    // заполнение множества
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    // проверка до sqrt(n) и удаление кратных
    for (m = 2; m * m <= n; m++)
        // если м в s, удаление кратных
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    // оставшиеся в s элементы - простые числа
    std::cout << std::endl << "Печать множества некратных чисел" << std::endl << s << std::endl;
    std::cout << std::endl << "Печать простых чисел" << std::endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.IsMember(m))
        {
            count++;
            std::cout << std::setw(3) << m << " ";
            if (k++ % 10 == 0)
                std::cout << std::endl;
        }
    std::cout << std::endl;
    std::cout << "В первых " << n << " числах " << count << " простых" << std::endl;
}

#endif