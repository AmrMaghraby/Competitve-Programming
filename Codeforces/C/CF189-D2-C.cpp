 #include<bits/stdc++.h>
 using namespace std;
 int A[300000],B[300000];
 int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> A[i];
  for(int i=0;i<n;i++)
    cin >> B[i];
  int l=0,cnt=0;
  for(int i=0;i<n && l<n;i++)
    if(A[l]==B[i])
      l++;
    else cnt++;
  cout<<cnt;

 }
