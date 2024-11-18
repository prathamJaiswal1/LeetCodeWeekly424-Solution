#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(int curr,int d,vector<int>v){
          while(curr>=0 && curr<v.size()){
              if(v[curr]==0){
                  
              }else{
                  v[curr]--;
                  d=!d;
              }
              curr+=(d==1?1:-1);
          }
          int maxi=-1e9,mini=1e9;
          for(int i=0;i<v.size();i++){
              maxi=max(maxi,v[i]);
              mini=min(mini,v[i]);
          }
        return maxi==0 && mini==0;
    }
    int countValidSelections(vector<int>& v) {
         int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                if(valid(i,0,v)) ans++;
                if(valid(i,1,v))ans++;
            }
        }
        return ans;
    }
};
int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    Solution obj;
    cout<<obj.countValidSelections(v)<<endl;
    return 0;
}