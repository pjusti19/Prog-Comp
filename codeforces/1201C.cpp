#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int array_size, operations_num;
    cin >> array_size >> operations_num;
    vector<long long> numbers(array_size);
    for (long long &number : numbers)
        cin >> number;

    int mid = array_size / 2;
    sort(numbers.begin() + mid, numbers.end());

    while (operations_num > 0)
    {
        auto it = upper_bound(numbers.begin() + mid, numbers.end(), numbers[mid]);
        int index = it - numbers.begin();
        if (index == numbers.size())
            index--;
        long long dif = numbers[index] - numbers[mid];
        cout << "indexado: " << numbers[index] << "\n";
        cout << "mid:" << numbers[mid] << " index: " << index << " dif: " << dif << "\n";
        for (int i = index - 1; i >= mid; i--)
        {
            if (operations_num == 0)
                break;
            numbers[i] += dif;
            operations_num -= dif;
        }
    }

    cout << numbers[mid] << "\n";
    return 0;
}

/* 5 5
1 2 1 1 1
3 

3 2
1 3 5
5

7 7
4 1 2 4 3 4 4
5 */