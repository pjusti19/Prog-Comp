#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number_elements, aimed_size;
    cin >> number_elements >> aimed_size;
    vector<int> elements(number_elements);
    unordered_map<int, int> is_in_segment;
    for (int &element : elements)
        cin >> element;

    int left, right, max_left, max_right, max_size;
    left = right = max_left = max_right = max_size = 0;
    int number_of_distinct_elements = 0;
    while (right < number_elements)
    {
        is_in_segment[elements[right]]++;
        if (is_in_segment[elements[right]] == 1)
            number_of_distinct_elements++;
        while (number_of_distinct_elements > aimed_size)
        {
            is_in_segment[elements[left]]--;
            if (is_in_segment[elements[left]] == 0)
                number_of_distinct_elements--;
            left++;
        }
        if ((right - left + 1) > max_size)
        {
            max_left = left;
            max_right = right;
            max_size = right - left + 1;
        }
        right++;
    }
    cout << max_left + 1 << " " << max_right + 1 << "\n";

    return 0;
}