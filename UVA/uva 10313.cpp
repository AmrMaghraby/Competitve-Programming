   ///IN THE NAME OF ALLAH
   #include<bits/stdc++.h>
   using namespace std;
   vector< pair<int,int> > X;
   int n;
   long long mem[2000][2000];
 int L1=0,L2=0,Target=0;
  long long dp(int T,int idx){
    if(T==0) return 1;
    if(T<0||idx<=0)return 0;
    if(mem[T][idx]!=-1)
        return mem[T][idx];
    long long ans=0;
    ans+=dp(T-idx,idx)+dp(T,idx-1);
    return mem[T][idx]=ans;
  }
  vector<int> parse(string &s){
    s += ' ';
    int n = 0;
    vector<int> ret;
    for(char c : s)
        if(c == ' ') ret.push_back(n), n = 0;
        else n = 10*n + c - '0';
    return ret;
}
  int main(){
    memset(mem,-1,sizeof mem);
    while(true){
    string str;
    getline(cin,str);
    if(str.size() < 1) return 0;
    vector<int>Y = parse(str);
    if(Y.size()==1){
        Target = Y[0];
        L1=1;
        L2=Y[0];
    } else if(Y.size()==2){
        Target = Y[0];
        L1=1;
        L2=Y[1];
    } else if(Y.size()==3){
        Target = Y[0];
        L1=Y[1];
        L2=Y[2];
    }
    if(Y.size()==1)
       cout<<dp(Target,Target)<<endl;
    else if(Y.size()==2)
       cout<<dp(Target,L2)<<endl;
    else if(Y.size()==3)
    {
       if (Y[0]==0 && Y[1]==0 && Y[2]<=1)
					cout<<1<<endl;
					//System.out.println(1);
        else if (Y[1]>Y[0] && Y[2]>Y[0])
					cout<<0<<endl;
					//System.out.println(0);
        else if (Y[1]>Y[2])
                     cout<<0<<endl;
                     //System.out.println(0);
        else
                    cout<<dp(Target,L2)-dp(Target,L1-1)<<endl;
    }
   }
  }
