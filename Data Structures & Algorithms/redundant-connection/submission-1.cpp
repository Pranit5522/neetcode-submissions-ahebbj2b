class DSU {
    vector<int> rank, parent;
    public:
    DSU(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int val){
        if(parent[val] == val){
            return val;
        }

        return parent[val] = findParent(parent[val]);
    }
    void doUnion(int v1, int v2){
        int pV1 = findParent(v1);
        int pV2 = findParent(v2);
        
        if(pV1 == pV2) return;

        if(rank[pV1] > rank[pV2]){
            parent[pV2] = pV1;
        } else if(rank[pV1] < rank[pV2]){
            parent[pV1] = pV2;
        } else {
            parent[pV2] = pV1;
            rank[pV1] += 1;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto edge: edges){
            if(dsu.findParent(edge[0]-1) != dsu.findParent(edge[1]-1)){
                dsu.doUnion(edge[0]-1, edge[1]-1);
            }
            else{
                return edge;
            }
        }
        return {-1, -1};
    }
};
