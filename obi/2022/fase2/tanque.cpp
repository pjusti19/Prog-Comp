#include <cstddef>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    double c, d, t;
    cin >> c >> d >> t;
    std::printf("%.1f\n", max(0.0, (d / c)-t));
    return 0;
}