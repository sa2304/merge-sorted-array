#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int> &a, int m, vector<int> &b, int n) {
    vector<int> a_data(m);
    uninitialized_move_n(a.begin(), m, a_data.begin());
    auto ap = a_data.begin();
    auto bp = b.begin();
    auto pout = a.begin();
    while (a_data.end() != ap && b.end() != bp) {
      if (*ap < *bp) {
        *pout++ = *ap++;
      } else {
        *pout++ = *bp++;
      }
    }
    while (a_data.end() != ap) {
      *pout++ = *ap++;
    }
    while (b.end() != bp) {
      *pout++ = *bp++;
    }
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
