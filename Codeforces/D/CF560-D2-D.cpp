#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
string x, y;
string f(string s){
    if (s.size() % 2) return s;
    else {
        string a = s.substr(0, s.size() / 2);
        a = f(a);
        string b = s.substr(s.size() / 2, s.size() / 2);
        b = f(b);
        return a > b ? b + a : a + b;
    }
}
int main(){
    while (cin >> x >> y){
        if (f(x)==f(y)) cout << "YES\n";
        else cout << "NO\n";
    }
}
