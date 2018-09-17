 ///IN THE NAME OF ALLAH
 #include<bits/stdc++.h>
 using namespace std;
 struct Range{
  long long l,r;
 };
 vector<Range>Ranges;
 vector<double>index;
 double mem[1001][1001];
 int n,k;
// double prop(int i,int j){
//  if(i==n)
//    return (j*100 >= k*n);
//
//  if(mem[i][j] == mem[i][j])
//    return mem[i][j];
//  double p = index[i]*prop(i+1,j+1);
//  double q = (1-index[i])*prop(i+1,j);
//  return mem[i][j]=p+q;
// }
 double prop(int i, int withOne) {
	if(i == n)
		return (100 * withOne >= n * k);

	double &ret = mem[i][withOne];

	if(ret == ret)
		return ret;

	double p1 = index[i] * prop(i+1, withOne+1);
	double p2 = (1 - index[i]) * prop(i+1, withOne);

	return ret = p1 + p2;
}
 long long cnt(long long  st, long long en){
	if(st == 0)	st = 1;
	if(st > en) return 0;
	vector<int> stD;
	long long stTemp = st;
	while(stTemp)	stD.push_back(stTemp%10), stTemp /= 10;
	long long nxt = (long long)pow(10.0, stD.size());
	if(stD.size() == 19)
		nxt = (long long)pow(10.0, stD.size()-1) + 1;
	if(stD.back() != 1)
		return cnt(nxt, en);
	else {
		long long nxt2 = (long long)( 2 * pow(10.0, stD.size()-1) - 1 );
		return min(nxt2, en) - st + 1 + cnt(nxt, en);
	}
}
 int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    long long l,r;
    cin >> l >> r;
    double T = 1.0*cnt(l,r)/(r-l+1);
    index.push_back(T);
  }
  cin >> k;
  memset(mem,-1,sizeof(mem));
  printf("%.10f",prop(0,0));
 }
