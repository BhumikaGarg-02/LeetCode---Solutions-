class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        vector<bool>suspicious(n,false);

        for(auto &edge : invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //bfs
        queue<int>que;
        que.push(k);
        suspicious[k]=true;
        while(!que.empty()){
            int current=que.front();
            que.pop();

            for(int &ngbr : adj[current]){
                inDegree[ngbr]--;
                if(!suspicious[ngbr]){
                    que.push(ngbr);
                    suspicious[ngbr]=true;
                }
            }
        }
        vector<int>res;
        bool cantremove=false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && inDegree[i]!=0){
                cantremove=true;
                break;
            }
            if(!suspicious[i])res.push_back(i);
        }
        if(cantremove){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return res;
    }
};