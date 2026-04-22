#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int total_cubinhos = n * n * n;
  int zero, um, dois, tres;
  zero = um = dois = 0;
  tres = 8;

  if (total_cubinhos - tres > 0){
    dois = (n-2)*12;
    um = (n-2)*(n-2)*6;
    zero = total_cubinhos - dois - um - tres;
  }

  cout << zero << "\n" << um << "\n" << dois << "\n" << tres << "\n";
    return 0;
}