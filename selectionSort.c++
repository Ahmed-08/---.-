#include <iostream>
#include <cstring>


// шаблонная функция сортировки выбором 
template<typename T>
void selectSort(T* arr, int size)
{
    T minElement;
    int index;

    for(int i{0}; i<size; ++i)
    {
        minElement = arr[i];
        index = i;
        for(int j{i + 1}; j < size; ++j)
        {
            if(arr[j] < minElement)
            {
                minElement = arr[j];
                index = j;
            }
        }

        if(index != i)
        {
            arr[index] = arr[i];
            arr[i] = minElement;
        }

    }
}

// перегрузка функции сортировки для const char**
void selectSort(const char** arr, int size)
{
    const char* minElement = nullptr;
    int index;

    for(int i{0}; i<size; ++i)
    {
        minElement = arr[i];
        index = i;
        for(int j{i + 1}; j < size; ++j)
        {
            if(strcmp(arr[j], minElement) < 0)
            {
                minElement = arr[j];
                index = j;
            }
        }

        if(index != i)
        {
            arr[index] = arr[i];
            arr[i] = minElement;
        }

    }
}

// перегрузка функции сортировки для char**
void selectSort(char** arr, int size)
{
    char* minElement = new char[50];
    int index;

    for(int i{0}; i<size; ++i)
    {
        strcpy(minElement, arr[i]);
        index = i;
        for(int j{i + 1}; j < size; ++j)
        {
            if(strcmp(arr[j], minElement) < 0)
            {
                strcpy(minElement, arr[j]);
                index = j;
            }
        }                            

        if(index != i)
        {
            strcpy(arr[index], arr[i]);
            strcpy(arr[i], minElement);
        }

    }

    delete[] minElement;
}

// объявление функции вывода массива на экран
template<typename T>
void print(T* arr, int size);

int main()
{
    
    // тест для int
    int intArray[]{10, 5, 7, 12, 25, 33, 14, 17, 11, 9};
    int n = sizeof(intArray) / sizeof(intArray[0]);
    selectSort<int>(intArray, n);
    std::cout << "Результат сортировки массива типа int: \n";
    print(intArray, n);
    std::cout << std::endl;

    // тест для double
    double doubleArray[]{3.1, 5.5, 0.1, 12.12, 9.7, 8.8, 11.27, 0.0, 21.05};
    n = sizeof(doubleArray) / sizeof(doubleArray[0]);
    selectSort<double>(doubleArray, n);
    std::cout << "Результат сортировки массива типа double: \n";
    print(doubleArray, n);
    std::cout << std::endl;

    //тест для массива char
    char sss[]{'b', 'a', 'c', 'e', 'd'};
    selectSort(sss, 5);
    std::cout << "Результат сортировки массива типа char: \n";
    print(sss, 5);
    std::cout << std::endl;

    // тест для const char*
    const char* s[]{"ccc", "aaa", "bbb", "eee"};
    selectSort(s, 4);
    std::cout << "Результат сортировки строк: \n";
    print(s, 4);
    std::cout << std::endl;

    // тест для char**
    char** str = new char*[3];
    for(int i = 0; i < 3; ++i)
    {
        std::cout << "enter string " << i << ": ";
        str[i] = new char[10];
        std::cin >> str[i];
    }
    selectSort(str, 3);
    print(str, 3);

    for(int i{0}; i<3; ++i)
    {
        delete[] str[i];
    }
    delete[] str;

    return 0;
}

// реализация функции вывода массива на экран
template<typename T>
void print(T* arr, int size)
{
    for(int i{0}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}