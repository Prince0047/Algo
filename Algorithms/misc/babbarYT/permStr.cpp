#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a, i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2, MOD = 1e9+7;


// Permutation
void seqperm(string s, int index){
  if(index== s.length()){
    cout<<s<<endl;
    return;
  }

  for(int i=index;i<s.length();i++){
    swap(s[index],s[i]);
    seqperm(s,index+1);
    
    // BackTrack
    swap(s[index],s[i]);
  }
}


void subseq(string s, string output, int index){
  if(index>=s.length()){
    if(output.length() == 0){
      cout<<"/n"<<endl;
    }
    else{
      cout<<output<<endl;
    }
    return;
  }
  subseq(s,output,index+1);
  output = output + s[index];
  subseq(s,output,index+1);
}

int main(){
    string s = "abc";
    string output = "";
    subseq(s,output,0);
    seqperm(s,0);
    
    return 0;
}