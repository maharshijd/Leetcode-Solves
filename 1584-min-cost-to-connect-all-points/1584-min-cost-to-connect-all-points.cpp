class Solution {
public:
    int V;
    vector<vector<int>> adjmat;
    
    void setup(int v){
        V = v;
        adjmat.resize(V);
        for(int i=0;i<v;i++) adjmat[i].resize(V,0);
    }
    // void addEdge(int v,int u, int w){
    //     adjmat[v][u] = w;
    //     adjmat[u][v] = w;
    // }
    int kruskals(){
        int totalW=0;
        vector<vector<int>> edges;
        vector<int> parent(V);
        int count = 0;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                edges.push_back({adjmat[i][j],i,j});
            }
        }
        for(int i=0;i<V;i++) parent[i] = i;
        sort(edges.begin(),edges.end());
        for(vector<int> edge: edges){
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];
            int pu = u;
            int pv = v;
            while(pu != parent[pu]) pu = parent[pu];
            while(pv != parent[pv]) pv = parent[pv];
            if(pv != pu){
                parent[pu] = pv;
                totalW+=w;
                count++;
            }
            if(count == V-1) break;
        }
        return totalW;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        setup(points.size());
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x2-x1) + abs(y2-y1);
                adjmat[i][j] = dist;
                adjmat[j][i] = dist;        
            }
        }
        return kruskals();
    }
};