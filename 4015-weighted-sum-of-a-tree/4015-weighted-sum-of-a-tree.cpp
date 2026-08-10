class Solution {
public:
    int n;
    vector<long long> depths;
    long long height(vector<vector<int>>& adj, vector<int>& nums){
        long long ht = 0;
        queue<int> q;
        q.push(0);
        vector<bool> seen(n,false);
        long long d = 1;
        seen[0] = true;
        depths[0]=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front();
                q.pop();
                for(int neigh: adj[front]){
                if(!seen[neigh]){
                    q.push(neigh);
                    seen[neigh] = true;
                    depths[neigh] = d+1;
                }
            }   
            }
            ht++;
            d++;
        }
        return ht;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        n = parent.size();
        depths.resize(n,0);
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        long long h = height(adj,nums);
        long long tot = 0;
        for(int i=0;i<n;i++){
            tot+=(nums[i]* (h-depths[i]+1));
        }
        return tot;
    }
};