class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        //{stops, {node, dist}}
        q.push({0,{src,0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue; //can found better solution to reach same dest point.

            for(auto nbr: adj[node]){
                int adjNode = nbr.first;
                int wt = nbr.second;

                if(cost + wt < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode, cost+wt}});
                }
            }
        }

        if(dist[dst]==1e9) return -1; //not reachable.
        return dist[dst];
    }
};