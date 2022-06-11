#include <iostream>
#include <cstring>


// шаблонная функция сортировки
template<typename T>
void bubbleSort(T* arr, int size)
{
    T temp;
    for(int i{0}; i < size; ++i)
    {
        for(int j{size-1}; j>i; --j)
        {
            if(arr[j-1] > arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


// перегрузка функции сортировки для const char**
void bubbleSort(const char* arr[], int size)
{
    const char* temp = nullptr;
    for (int i{ 0 }; i < size; ++i)
    {   
        for (int j{ size - 1 }; j > i; --j)
        {
            if (strcmp(arr[j - 1], arr[j]) > 0)
            {    
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;                
            }
        }
    }
}

void bubbleSort(char* arr[], int size)
{
    char* temp = new char[50];
    for (int i{ 0 }; i < size; ++i)
    {   
        for (int j{ size - 1 }; j > i; --j)
        {
            if (strcmp(arr[j - 1], arr[j]) > 0)
            {
                strcpy(temp, arr[j - 1]);
                strcpy(arr[j - 1], arr[j]);
                strcpy(arr[j], temp); 
            }
        }
    }

    delete[] temp;
}


// объявление функции вывода массива на экран
template<typename T>
void print(T* arr, int size);


int main()
{


    // тест для int
    int intArray[]{10, 5, 7, 12, 25, 33, 14, 17, 11, 9};
    int n = sizeof(intArray) / sizeof(intArray[0]);
    bubbleSort<int>(intArray, n);
    std::cout << "Результат сортировки массива типа int: \n";
    print(intArray, n);
    std::cout << std::endl;

    // тест для double
    double doubleArray[]{3.1, 5.5, 0.1, 12.12, 9.7, 8.8, 11.27, 0.0, 21.05};
    n = sizeof(doubleArray) / sizeof(doubleArray[0]);
    bubbleSort<double>(doubleArray, n);
    std::cout << "Результат сортировки массива типа double: \n";
    print(doubleArray, n);
    std::cout << std::endl;
    
    // тест для const char**
    const char* s[]{"ccc", "bbb", "aaa"};
    bubbleSort(s, 3);
    std::cout << "Результат сортировки строк: \n";
    print(s, 3);
    std::cout << std::endl;

    // тест для char**
    char** str = new char*[3];
    for(int i = 0; i < 3; ++i)
    {
        std::cout << "enter string " << i << ": ";
        str[i] = new char[10];
        std::cin >> str[i];
    }
    bubbleSort(str, 3);
    print(str, 3);

    for(int i{0}; i<3; ++i)
    {
        delete[] str[i];
    }
    delete[] str;
    

    return 0;
}

// реалиция функции вывода массива на экран
template<typename T>
void print(T* arr, int size)
{
    for(int i{0}; i<size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}