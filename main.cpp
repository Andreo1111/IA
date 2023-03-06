#include <iostream>
#include "IA.h"

int main()
{
    setlocale(LC_ALL, "");
    // Объявление массиса с числом элементов 10
    // при указании массива меньше 10 возникнет исключение Bad Length !
    IntArray array(10);

    // Заполняем массив числами от 1 до 10 Размер массива задается в вызове предущего метода
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;

    // Изменение количества элементов в массиве до 8
    array.resize(8);

    // Вставка числа 50 с на место с индексом в пределах длины массива с 8, так как размер был изменен  до 8
    // При превышении размера возникнет исключение Bad Range !
    array.insertBefore(50, 8);

    // Удаление элемента с индексом  3
    //При удалении элемента массива за пределами размера массива вернется исключение Bad Range !
    array.remove(3);

    // Добавление элементов в конец и начало массива
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

    // Вывод на печать все элементов массива
    for (int i{ 0 }; i < array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}