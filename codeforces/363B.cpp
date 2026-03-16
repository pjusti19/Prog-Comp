#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fences_number, space_required;
    cin >> fences_number >> space_required;

    vector<int> heights(fences_number);
    for(int &heigth : heights) cin >> heigth;

    int i = 1; 
    int j = 0;
    int sum = 0;
    int min_height = 0;
    int best_begining = 0;

    for(; j < space_required; j++){
        sum+= heights[j];
    }

    min_height = sum;

    for(; j < fences_number; j++, i++){
        sum += heights[j];
        sum -= heights[i-1];
        if(sum <= min_height){
            min_height = sum;
            best_begining = i;
        }
    }

    cout << best_begining+1 << "\n";
    
    return 0;
}