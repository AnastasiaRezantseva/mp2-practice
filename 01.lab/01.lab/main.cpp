#include <iomanip>
#ifndef USE_SET 
#define USE_SET // ������������ ����� TSet,
                // ���������������, ����� ������������ ������� ����

// ������������ ����� TBitField

#include "Bitfield.h"
/*
int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    std::cout << "������������ �������� ��������� �������� ����" << std::endl;
    std::cout << "             ������ ����������" << std::endl;
    std::cout << "������� ������� ������� ����� �������� - ";
    std::cin >> n;
    TBitField s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.set(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� m � s, �������� �������
        if (s.test(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.test(k))
                    s.reset(k);
    // ���������� � s �������� - ������� �����
    std::cout << std::endl << "������ ��������� ��������� �����" << std::endl << s << std::endl;
    std::cout << std::endl << "������ ������� �����" << std::endl;
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
    std::cout << "� ������ " << n << " ������ " << count << " �������" << std::endl;
}
//#else
*/
#include "TSet.h"

int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    std::cout << "������������ �������� ��������� ���������" << std::endl;
    std::cout << "              ������ ����������" << std::endl;
    std::cout << "������� ������� ������� ����� �������� - ";
    std::cin >> n;
    TSet s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� � � s, �������� �������
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    // ���������� � s �������� - ������� �����
    std::cout << std::endl << "������ ��������� ��������� �����" << std::endl << s << std::endl;
    std::cout << std::endl << "������ ������� �����" << std::endl;
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
    std::cout << "� ������ " << n << " ������ " << count << " �������" << std::endl;
}

#endif