#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int> &a, int m, vector<int> &b, int n) {
    int i = m - 1;
    int k = n - 1;
    int out = m + n - 1;
    while (0 <= i && 0 <= k) {
      if (a[i] < b[k]) {
        a[out--] = b[k--];
      } else {
        a[out--] = a[i--];
      }
    }
    while (0 <= i) { a[out--] = a[i--]; }
    while (0 <= k) { a[out--] = b[k--]; }
  }
};

void TestMerge() {
  Solution s;
  {
    vector<int> lhs{1, 2, 3, 0, 0, 0};
    vector<int> rhs{2, 5, 6};
    s.merge(lhs, 3, rhs, 3);
    assert((vector<int>{1, 2, 2, 3, 5, 6}) == lhs);
  }
  {
    vector<int> lhs{1};
    vector<int> rhs{};
    s.merge(lhs, 1, rhs, 0);
    assert((vector<int>{1}) == lhs);
  }
  {
    vector<int> lhs{0};
    vector<int> rhs{1};
    s.merge(lhs, 0, rhs, 1);
    assert((vector<int>{1}) == lhs);
  }
}

int main() {
  TestMerge();
  std::cout << "Ok!" << std::endl;
  return 0;
}
