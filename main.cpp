#include <iostream>
#include "IA.h"

int main()
{
    setlocale(LC_ALL, "");
    // ���������� ������� � ������ ��������� 10
    // ��� �������� ������� ������ 10 ��������� ���������� Bad Length !
    IntArray array(10);

    // ��������� ������ ������� �� 1 �� 10 ������ ������� �������� � ������ ��������� ������
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;

    // ��������� ���������� ��������� � ������� �� 8
    array.resize(8);

    // ������� ����� 50 � �� ����� � �������� � �������� ����� ������� � 8, ��� ��� ������ ��� �������  �� 8
    // ��� ���������� ������� ��������� ���������� Bad Range !
    array.insertBefore(50, 8);

    // �������� �������� � ��������  3
    //��� �������� �������� ������� �� ��������� ������� ������� �������� ���������� Bad Range !
    array.remove(3);

    // ���������� ��������� � ����� � ������ �������
    array.insertAtEnd(80);
    array.insertAtBeginning(10);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }

    // ����� �� ������ ��� ��������� �������
    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}