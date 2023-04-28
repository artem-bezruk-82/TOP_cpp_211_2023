#include <iostream>
#include <vector>

template <typename T>
void PrintVectorConsole(std::vector<T> &vec);

template <typename T>
void InsertVectorElement(std::vector<T> &vec, int index, T element);

template <typename T>
void DeleteVectorElement(std::vector<T> &vec, int index);

int main()
{
    std::vector<int> myVector = std::vector<int>();
    int size = 10;
    for (int i = 0; i < size; ++i)
    {
        myVector.push_back(rand() % (10 - 0 + 1));
    }
    std::cout << "Initial vector:" << std::endl;
    PrintVectorConsole(myVector);
    int index = 3;
    int newElement = 300;
    try
    {
        InsertVectorElement(myVector, index, newElement);
        std::cout << "Element " << newElement << " inserted:" << std::endl;
        PrintVectorConsole(myVector);
    }
    catch (const std::invalid_argument& exc)
    {
        std::cout << exc.what() << std::endl;
    }

    try
    {
        DeleteVectorElement(myVector, index);
        std::cout << "Element " << newElement << " deleted:" << std::endl;
        PrintVectorConsole(myVector);
    }
    catch (const std::invalid_argument& exc)
    {
        std::cout << exc.what() << std::endl;
    }


    std::cout << "Final vector:" << std::endl;
    PrintVectorConsole(myVector);

    return 0;
}

template <typename T>
void PrintVectorConsole(std::vector<T> &vec)
{
    for (T item: vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void InsertVectorElement(std::vector<T> &vec, int index, T element)
{
    if (index < 0 || index >= vec.size())
    {
        throw std::invalid_argument("index is out of 0..." + std::to_string(vec.size()) + " range");
    }
    vec.insert(vec.cbegin() + index, element);
}

template <typename T>
void DeleteVectorElement(std::vector<T> &vec, int index)
{
    if (index < 0 || index >= vec.size())
    {
        throw std::invalid_argument("index is out of 0..." + std::to_string(vec.size()) + " range");
    }
    vec.erase(vec.cbegin() + index);
}