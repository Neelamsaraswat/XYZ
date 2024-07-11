#include<bits/stdc++.h>
using namespace  std;
vector<int>NextS(vector<int>V){ 
  int n=V.size();
vector<int>ans(n,-1);
stack<int>st;
st.push(0);
for(int i=1;i<n;i++){
while(!st.empty()&& V[i]<V[st.top()]){
  ans[st.top()]=i;
  st.pop();
}
st.push(i);
}
return ans;
}
vector<int>PrevS(vector<int>V){ 
  int n=V.size();
reverse(V.begin(),V.end());
vector<int>ans1(n,-1);
stack<int>stt;
stt.push(0);
for(int i=1;i<n;i++){
while(!stt.empty()&& V[i]<V[stt.top()]){
  ans1[stt.top()]=n-i-1;
  stt.pop();
}
stt.push(i);
}
reverse(ans1.begin(),ans1.end());
return ans1;
}
int main(){
  int n;
  cin>>n;
  vector<int>V(n);
  for(int i=0;i<n;i++){
    cin>>V[i];
  }
 // vector<int>next(n);
 // next=NextS(V);
vector<int>next=NextS(V);
  vector<int>prev=PrevS(V);
 // prev=PrevS(V);
int area=0;
for(int i=0;i<n;i++){
 int l=V[i];
 
 if(next[i]==-1 ){
  next[i]=n;
 }
 int b=next[i]-prev[i]-1;
int newarea=l*b;
 
 area=max(area,newarea);
}
 cout<<"Histogram ans"<<area<<endl;
return 0;
}
