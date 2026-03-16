#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases_number;
  cin >> test_cases_number;
  for (int i = 0; i < test_cases_number; i++) {
    int lenght;
    cin >> lenght;
    vector<int> numbers(lenght);
    map<int, pair<int, int>> found_numbers;
    for (int &num : numbers)
      cin >> num;
    for (int j = 0; j < lenght; j++) {
      if (found_numbers.count(numbers[j]) == 0)
        found_numbers[numbers[j]] = {1, j};
      else
        found_numbers[numbers[j]].first++;
    };
    int alvo;
    for (auto &duo : found_numbers) {
      if (duo.second.first == 1) {
        cout << duo.second.second + 1 << "\n";
        break;
      }
    }
  }
  return 0;
}