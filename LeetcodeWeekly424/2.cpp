#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int>d(n+1,0);
        for(auto i:q){
            d[i[0]]--;
            d[i[1]+1]++;
        }
        for(int i=1;i<=n;i++){
            d[i]+=d[i-1];
        }
        for(int i=0;i<n;i++){
            d[i]+=v[i];
        }
        for(int i=0;i<n;i++){
            if(d[i]>0) return false;
        }
        return true;
        
    }
};
int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int m;cin>>m;
    vector<vector<int>>q;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        q.push_back({a});
        q.push_back({b});
    }
    Solution obj;
    cout<<obj.isZeroArray(v,q)<<endl;
    return 0;
}