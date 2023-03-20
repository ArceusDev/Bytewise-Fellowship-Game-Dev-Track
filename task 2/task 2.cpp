// task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::sort;

bool checkGivenOddNumberInSortedVector(int target, vector<int>& container, bool isSorted = true);

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    bool renew = false;
    cout << "Welcome to the Program that will Check odd number in Specific Vector\n\n";
    
    do
    {
        int target = 0;
        char renewLetter = 'n';

        cout << "\nEnter the number you want to check: ";
        cin >> target;

        if (checkGivenOddNumberInSortedVector(target, vec))
        {
            cout << "Target " << target << " found!\n";
        }
        else
        {
            std::cout << "Target " << target << " not found!\n";
        }

        cout << "\nWould you like you restart the program (Y|N): ";
        cin >> renewLetter;

        if (renewLetter == 'y' || renewLetter == 'Y')
        {
            renew = true;
        }
        else
        {
            renew = false;
        }
    } while (renew);
 


    return EXIT_SUCCESS;
}

bool checkGivenOddNumberInSortedVector(int target, vector<int>& container, bool isSorted)
{
    bool found = false;

    if (!isSorted)
    {
        sort(container.begin(), container.end());
    }
    for (auto& val : container) 
    {
        if (val % 2 == 0)
        {
            continue;
        }
        if (val == target) 
        {
            found = true;
            break; 
        }     
    }

    return found;
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
