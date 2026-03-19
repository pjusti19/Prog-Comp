#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num_dormitories, num_letters;
    cin >> num_dormitories >> num_letters;
    vector<long long> dormitories(num_dormitories);
    vector<long long> destiny_room(num_letters);
    for (long long &dormitory : dormitories)
        cin >> dormitory;
    for (long long &room : destiny_room)
        cin >> room;

    vector<long long> dormitories_rooms_range(num_dormitories);
    dormitories_rooms_range[0] = dormitories[0];
    for (int i = 1; i < num_dormitories; i++)
        dormitories_rooms_range[i] = dormitories[i] + dormitories_rooms_range[i - 1];

    for (int i = 0; i < num_letters; i++)
    {
        auto pos = lower_bound(dormitories_rooms_range.begin(), dormitories_rooms_range.end(), destiny_room[i]);
        int index = pos - dormitories_rooms_range.begin();
        long long room_number;
        if (index == 0)
            room_number = destiny_room[i];
        else
            room_number = destiny_room[i] - dormitories_rooms_range[index - 1];
        cout << index + 1 << " " << room_number << "\n";
    }
    return 0;
}