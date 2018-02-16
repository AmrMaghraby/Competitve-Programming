

#include <cstdio>
#include <stack>

using namespace std;

const int MAX_N = 100010;
const int INF = 1000000;

int n;
int values[MAX_N], life[MAX_N];
stack<int> killers;

int main() {

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &values[i]);
  }

  life[0] = INF;
  killers.push(0);
  for (int i = 1; i <= n; ++i) {
    life[i] = 1;
    while (killers.size() && values[i] > values[killers.top()]) {
      life[i] = max(life[i], life[killers.top()] + 1);
      killers.pop();
    }
    killers.push(i);
  }

  int sol = 0;
  for (int i = 1; i <= n; ++i) {
    if (life[i] < INF) {
      sol = max(sol, life[i]);
    }
  }

  printf("%d\n", sol);

  return 0;
}




