#include <stdio.h>
#include <string>
#include <iostream>

bool removeDupllicates(std::string &input)
{
    bool string_modified = false;

    if (input.size() <= 1)
        return false;

    std::string reduced_string = "";
    char repeating_char = '\0';

    int index = 0;

    while (index < input.size() - 1)
    {
        // Check current and next char
        if (input[index] != input[index + 1])
        {
            // Check if this was not the last repeating char
            if (input[index] != repeating_char)
            {
                repeating_char = '\0';
                reduced_string += input[index];
            }
            else
            {
                string_modified = true;
            }
            index += 1;
        }
        else
        { // current and next are same so increment twice
            string_modified = true;
            repeating_char = input[index];
            index += 2;
        }
    }

    // Check if last char can be added
    if (input[input.size() - 1] != input[input.size() - 2])
    {
        reduced_string += input[input.size() - 1];
    }

    if (string_modified)
    {
        removeDupllicates(reduced_string);
        input = reduced_string;
    }

    return string_modified;
}

int main()
{
    //code
    int test_cases;
    std::string input;
    std::cin >> test_cases;
    while (test_cases-- > 0)
    {
        std::cin >> input;
        removeDupllicates(input);
        std::cout << input << std::endl;
    }
    return 0;
}