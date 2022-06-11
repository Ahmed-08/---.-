#include <iostream>
#include <cstring>

// шаблонная функция сортировки вставками
template<typename T>
void insertSort(T* arr, int size)
{
    int i{0};
    int j;
    T temp;
    while (i < size - 1)
    {
        j = i;
        while(j >= 0 && arr[j + 1] < arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            --j;
        }
        ++i;
    }
}

// пегрузка функции для char**
void insertSort(char* arr[], int size)
{
    int i{0};
    int j;
    char* temp = new char[50];

    while (i < size - 1)
    {
        j = i;
        while(j >= 0 && strcmp(arr[j + 1], arr[j]) < 0)
        {
            strcpy(temp, arr[j]);
            strcpy(arr[j], arr[j + 1]);
            strcpy(arr[j + 1], temp);
            --j;
        }
        ++i;
    }

    delete[] temp;
}

// пегрузка функции для const char**
void insertSort(const char* arr[], int size)
{
    int i{0};
    int j;
    const char* temp{nullptr};

    while (i < size - 1)
    {
        j = i;
        while(j >= 0 && strcmp(arr[j + 1], arr[j]) < 0)
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            --j;
        }
        ++i;
    }
}

// объявление функции печати массива на экран
template<typename T>
void print(T* arr, int size);

int main()
{

    // тест для int
    int intArray[]{10, 5, 7, 12, 25, 33, 14, 17, 11, 9};
    int n = sizeof(intArray) / sizeof(intArray[0]);
    insertSort<int>(intArray, n);
    std::cout << "Результат сортировки массива типа int: \n";
    print(intArray, n);
    std::cout << std::endl;

    // тест для double
    double doubleArray[]{3.1, 5.5, 0.1, 12.12, 9.7, 8.8, 11.27, 0.0, 21.05};
    n = sizeof(doubleArray) / sizeof(doubleArray[0]);
    insertSort<double>(doubleArray, n);
    std::cout << "Результат сортировки массива типа double: \n";
    print(doubleArray, n);
    std::cout << std::endl;

    //тест для массива char
    char sss[]{'b', 'a', 'c', 'e', 'd'};
    insertSort(sss, 5);
    std::cout << "Результат сортировки массива типа char: \n";
    print(sss, 5);
    std::cout << std::endl;

    // тест для const char**
    const char* s[]{"ccc", "aaa", "bbb", "eee"};
    insertSort(s, 4);
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
    insertSort(str, 3);
    print(str, 3);

    for(int i{0}; i<3; ++i)
    {
        delete[] str[i];
    }
    delete[] str;




    return 0;
}

// реализация функции печати массива на экран
template<typename T>
void print(T* arr, int size)
{
    for(int i{0}; i<size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}