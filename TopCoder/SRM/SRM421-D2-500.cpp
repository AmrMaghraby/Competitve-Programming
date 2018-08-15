#include<ctime> 
#include<cstdlib> 
#include<iostream> 
#include<algorithm> 
#include<sstream> 
#include<string> 
#include<vector> 
#include<cmath> 
using namespace std; 

#define FOR(i,a,b) for(int i = (a); i < (b); ++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it) 
#define pb push_back 
#define all(x) (x).begin(),(x).end() 
#define CLEAR(x,with) memset(x,with,sizeof(x)) 
#define sz size() 
typedef long long ll; 

struct EquilibriumPoints  
{ 
  double f(double m1, double d) 
  { 
    return m1 / d / d; 
  } 
  vector <double> getPoints(vector <int> x, vector <int> m)  
  { 
    int n = x.sz; 
    vector<double> ret; 
    REP(i,x.sz-1) 
    { 
      double lo = x[i], hi = x[i+1]; 
      REP(iter,500) 
      { 
        double mid = (lo+hi) / 2; 
        double force = 0; 
        REP(j,i+1) force -= f(m[j], mid - x[j]); 
        FOR(j,i+1,n) force += f(m[j], x[j] - mid); 
        if(force < 0) 
          lo = mid; 
        else 
          hi = mid; 
      } 
      ret.pb((lo+hi) / 2); 
    } 
    return ret; 
  } 
}; 
