// Detect Capital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool detectCapitalUse(std::string word) {

    int length = 0;
    int upper = 0;
    int lower = 0;

    for (int i = 0; word[i]; i++)
    {
        length++;
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            upper++;
        }
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            lower++;
        }
    }
    
    if (upper == length || lower == length || (isupper(word[0]) && lower == length - 1))
    {
        return true;
    }
    
    return false;
}


int main()
{
    std::cout << "A program for detecting if word has Correct Capital Usage\n\n";
    bool renewCondition = false;
    try
    {
        do
        {
            std::string input = "";
            std::cout << "Enter the word: ";
            std::cin >> input;

            if (detectCapitalUse(input))
            {
                std::cout << "Correct Capital Usage\n";
            }
            else
            {
                std::cout << "Capital Usage is not Correct\n";
            }

            std::cout << "\nWould Like to Check again? (Y|N) : ";
            std::cin >> input;
            if (input == "y" || input == "Y")
            {
                renewCondition = true;
            }
            else
            {
                renewCondition = false;
            }
        } while (renewCondition);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }

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
