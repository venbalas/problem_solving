#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//https://practice.geeksforgeeks.org/problems/relative-sorting/0
void relativeSorting(vector<int> &a1, vector<int> &a2)
{

    vector<int> aux_a1;
    int swap_index = a1.size() - 1, non_overlapping_elements = 0;

    // Build the a2_map
    std::unordered_map<int, int> a2_map;
    for (int i = 0; i < a2.size(); i++)
    {
        a2_map[a2[i]] = i;
    }

    // Determine partition and group non existing elements
    for (int i = 0; i < a1.size(); i++)
    {

        // Swap to swap_index if it is not in a2
        while (a2_map.find(a1[i]) == a2_map.end() &&
               i <= swap_index)
        {
            int temp = a1[i];
            a1[i] = a1[swap_index];
            a1[swap_index] = temp;
            swap_index--;
            non_overlapping_elements++;
        }
    }
    int overlapping_elements = a1.size() - non_overlapping_elements;

    // Get the aux indicies
    for (int i = 0; i < overlapping_elements; i++)
    {
        aux_a1.push_back(a2_map.at(a1[i]));
    }

    // Sort the aux indices
    std::sort(aux_a1.begin(), aux_a1.end());

    // Reorganize the first partition
    for (int i = 0; i < overlapping_elements; i++)
    {
        a1[i] = a2[aux_a1[i]];
    }

    // Sort the second partition
    std::sort(a1.begin() + overlapping_elements, a1.end());
}

int main()
{
    //code

    int test_cases, n, m, element;

    std::cin >> test_cases;

    while (test_cases-- > 0)
    {
        std::vector<int> a1, a2;
        std::cin >> n >> m;

        // Get a1 array
        for (int i = 0; i < n; i++)
        {
            cin >> element;
            a1.push_back(element);
        }

        // Get a2 array
        for (int i = 0; i < m; i++)
        {
            cin >> element;
            a2.push_back(element);
        }

        relativeSorting(a1, a2);

        // Print a1
        for (int i = 0; i < n; i++)
        {
            cout << a1[i] << " ";
        }
        cout << endl;
    }

    return 0;
}