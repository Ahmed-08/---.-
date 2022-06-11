#include <iostream>


// шаблонная функция быстрой сортировки
template<typename T>
void quickSort(T* arr, int size)
{
    int left = 0, right = size;
    T support = arr[size/2];
    T temp;
    do{
        while(arr[left] < support) ++left;
        while(arr[right] > support) --right;
        if(left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            ++left;
            --right;
        }
    }while(left <= right);

    if(right > 0)   quickSort(arr, right);
    if(size > left) quickSort(arr + left, size - left); 
    
}

// перегрузка функции для char**
void quickSort(char** arr, int size)
{
    int left = 0, right = size;
    char support[50];
    strcpy(support, arr[size/2]);
    char temp[50];
    do{
        while(strcmp(arr[left], support) < 0) ++left;
        while(strcmp(arr[right], support) > 0) --right;
        if(left <= right)
        {
            strcpy(temp, arr[left]);
            strcpy(arr[left], arr[right]);
            strcpy(arr[right], temp);
            ++left;
            --right;
        }
    }while(left <= right);

    if(right > 0)   quickSort(arr, right);
    if(size > left) quickSort(arr + left, size - left);

}

// перегрузка функции для const char**
void quickSort(const char* arr[], int size)
{
    int left = 0, right = size;
    const char* support = arr[size/2];

    const char* temp = nullptr;
    do{
        while(strcmp(arr[left], support) < 0) ++left;
        while(strcmp(arr[right], support) > 0) --right;
        if(left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            ++left;
            --right;
        }
    }while(left <= right);

    if(right > 0)   quickSort(arr, right);
    if(size > left) quickSort(arr + left, size - left); 
}

// объявление функции печати массива на экран
template<typename T>
void print(T* arr, int size);

int main()
{

    // тест для int
    int intArray[]{10, 5, 7, 12, 25, 33, 14, 17, 11, 9};
    int n = sizeof(intArray) / sizeof(intArray[0]);
    quickSort<int>(intArray, n - 1);
    std::cout << "Результат сортировки массива типа int: \n";
    print(intArray, n);
    std::cout << std::endl;

    // тест для double
    double doubleArray[]{3.1, 5.5, 0.1, 12.12, 9.7, 8.8, 11.27, 0.0, 21.05};
    n = sizeof(doubleArray) / sizeof(doubleArray[0]);
    quickSort<double>(doubleArray, n - 1);
    std::cout << "Результат сортировки массива типа double: \n";
    print(doubleArray, n);
    std::cout << std::endl;
    
    // тест для const char**
    const char* s[]{"ccc", "bbb", "aaa"};
    quickSort(s, 2);
    std::cout << "Результат сортировки строк: \n";
    print(s, 3);
    std::cout << std::endl;

    // тест для char**
    char** str = new char*[5];
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "enter string " << i << ": ";
        str[i] = new char[10];
        std::cin >> str[i];
    }
    quickSort(str, 4);
    print(str, 5);

    for(int i{0}; i<5; ++i)
    {
        delete[] str[i];
    }
    delete[] str;


    return 0;
}

// реализация функции печати на экран
template<typename T>
void print(T* arr, int size)
{
    for(int i{0}; i<size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}