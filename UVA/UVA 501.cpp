#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int M, N, num[30000];
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
      scanf("%d", &num[i]);
    }
    vector<int> box;
    int done = 0, need = 0;
    while (N--) {
      int index;
      scanf("%d", &index);
      while (box.size() < index) {
        vector<int>::iterator it = lower_bound(box.begin(), box.end(), num[done]);
        box.insert(it, num[done++]);
      }
      printf("%d\n", box[need++]);
    }
    if (T) {
      puts("");
    }
  }
  return 0;
}
