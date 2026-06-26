class Solution {
public:
    bool isCycle(int i , vector<int> &vis ,vector<int>&pathVis, vector<vector<int>> & graph){
        vis[i]=1;
        pathVis[i]=1;

        for(int adj : graph[i]){
            if(!vis[adj]){
                if(isCycle(adj,vis,pathVis,graph)){
                    return true;
                }
            }
            else if(pathVis[adj]){
                return true;
            }
                    
            
        }
        pathVis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto & p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int> vis(numCourses,0) ,pathVis(numCourses,0);

        for(int i = 0 ; i< numCourses ; i++){
            if(!vis[i]){
                if(isCycle(i,vis,pathVis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};