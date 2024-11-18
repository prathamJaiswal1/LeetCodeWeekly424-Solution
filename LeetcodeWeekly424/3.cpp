#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool valid(int k,vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<ll>d(n+1,0);
        // for(auto i:q){
        //     d[i[0]]--;
        //     d[i[1]+1]++;
        // }
        for(int i=0;i<k;i++){
            int l=q[i][0],r=q[i][1];
            int val=q[i][2];
            d[l]-=val;
            d[r+1]=d[r+1]+val;
        }
        for(int i=1;i<=n;i++){
            d[i]+=d[i-1];
        }
        for(int i=0;i<n;i++){
            d[i]=d[i]+v[i];
        }
        for(int i=0;i<n;i++){
            if(d[i]>0) return false;
        }
        return true;
        
    }
    int minZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int ans=-1;
        int low=0,high=q.size();
        while(low <= high){
            int mid=(low+high)>>1;
            if(valid(mid,v,q)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
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
    cout<<obj.minZeroArray(v,q)<<endl;
    return 0;
}