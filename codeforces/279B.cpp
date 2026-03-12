#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number_books, minutes_limit;
    cin >> number_books >> minutes_limit;
    vector<int> reading_times(number_books);
    for (int &time : reading_times)
        cin >> time;

    int max_books = 0;
    int sum = 0;
    int i = 0;
    for (int j = 0; j < number_books; j++)
    {
        sum += reading_times[j];

        while (sum > minutes_limit)
        {
            sum -= reading_times[i];
            i++;
        }
        max_books = max(max_books, j - i + 1);
    }

    cout << max_books << "\n";

    return 0;
}