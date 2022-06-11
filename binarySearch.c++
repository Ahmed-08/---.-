#include <iostream>


template<typename T>
T binarySearch(T* arr, int size, T key)
{
    int left = 0, right = size - 1;
    int index;
    while(left <= right)
    {
        index = (left + right) / 2;
        if(arr[index] == key)
        {
            return index;
        }
        else if(arr[index] > key)
        {
            right = index - 1;
        }
        else{
            left = index + 1;
        }
    }

    return -1;
}

int main()
{
    //выделяем память под массив
    int* arr = new int[50];
    for(int i{0}; i < 50; ++i)
    {
        // заполняем массив от 1 до 50
        arr[i] = i + 1;
    }

    // вывод на экран элементы массива
    for(int i{0}; i < 50; ++i)
    {
        std::cout << arr[i] << " ";
        if(i == 25)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // тестируем функцию поиска
    // массив должен быть отсортированным
    for(int i{0}; i < 55; ++i)
    {
        // функция возвращает индексы найденных элементов
        // начиная от i = 50 функция должна вернуть -1
        if(i < 50)
        {
            std::cout << "element " << arr[49 - i] \
            << ", index = " << binarySearch(arr, 50, 50 - i) << std::endl;
        }
        else
        {
            std::cout << "the element does not exist " << \
            ", index = " << binarySearch(arr, 50, 50 - i) << std::endl;            
        }
    }

    delete[] arr;
    
    


    return 0;
}