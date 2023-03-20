// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Vector
{
    int* array;
    int size;
public:    
    Vector(int* array, int size)
    {
        this->array = new int[size];
        this->size = size;
        for (size_t i = 0; i < size; i++)
        {
            this->array[i] = array[i];
        }
    }

    void Print()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << array[i] << " , ";
        }
        std::cout << std::endl;
    }

    bool Append(int element)
    {
        bool done = false;
        size = size + 1; 
        int* temp = new int[size]; 
   
        for (int i = 0; i < size; i++) 
        {
            if (i == size - 1)
            {
                temp[i] = element;   
                done = true;
            }
            else
            {
                temp[i] = array[i];
                done = false;
            }                     
        }

        delete[] array;
        array = temp;
        
        return done;
    }

    ~Vector()
    {
        delete[] array;
    }
};


int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    Vector* vec = new Vector(arr, 10);

    vec->Append(11);
    vec->Print();

    vec->Append(114);
    vec->Print();

    vec->Append(1634);
    vec->Print();

    delete vec;

    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
