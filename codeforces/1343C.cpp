#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases_number;
    cin >> test_cases_number;
    for(int k = 0; k < test_cases_number; k++){
        int elements_number;
        cin >> elements_number;
        vector<long long> sequence(elements_number);
        for(long long &element : sequence) cin >> element;
        
        long long max_sum = 0;
        long long best_option;
        bool currently_on_positive;

        currently_on_positive = sequence[0] > 0;
        best_option = sequence[0];
        for(int i = 1; i < elements_number; i++){
            if(currently_on_positive && (sequence[i] < 0)){
                currently_on_positive = false;
                max_sum += best_option;
                best_option = sequence[i];
            }
            else if(!currently_on_positive && (sequence[i] > 0)){
                currently_on_positive = true;
                max_sum += best_option;
                best_option = sequence[i]; 
            }
            else if(sequence[i] > best_option) best_option = sequence[i];
        }

        cout << max_sum+best_option << "\n";
    }
    return 0;

}