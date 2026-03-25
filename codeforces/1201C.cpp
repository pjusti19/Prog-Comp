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
    sort(numbers.begin(), numbers.end());

    if (array_size == 1)
    {
        cout << numbers[0] + operations_num << "\n";
        return 0;
    }

    while (operations_num > 0)
    {
        int index = upper_bound(numbers.begin() + mid, numbers.end(), numbers[mid]) - numbers.begin();
        long long width = index - mid;

        if(index == array_size){
            numbers[mid] += operations_num / width;
            break;
        }

        long long need = width * (numbers[index] - numbers[mid]);

        if(need <= operations_num){
            numbers[mid] = numbers[index];
            operations_num -= need;
        }
        else{
            numbers[mid] += operations_num / width;
            operations_num = 0;
        }
        
    }

    cout << numbers[mid] << "\n";
    return 0;
}
