#include <vector>
int getSingleElement(vector<int> &arr) {
  int n = arr.size();
  int a = 0;
  for (int i = 0; i < n; i++) {
 a = a ^ arr[i];
  }
  return a;
}
// TC->O(arr.size())  SC O(1)
