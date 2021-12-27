#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // FIXME
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
