// Q 207. Course Schedule (https://leetcode.com/problems/course-schedule/description/)

class Solution {
public:

    bool DFSrec (vector <int> adj[] , int s , bool visited[] , bool recSt[]){

    visited[s] = true;
    recSt[s] = true;
    
    for(int a : adj[s]){

        if(visited[a] == false && DFSrec(adj,a,visited,recSt)){
            return true;

        }else if( recSt[a] == true){
            return true;
        }
    }
    recSt[s] = false;
    return false;
}

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj [numCourses];
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        int v = numCourses;
        bool visited[v];
        bool recSt[v];
        for(int i=0 ; i<v ; i++){
            visited[i] = false;
            recSt[i] = false;
        }
    
        for(int i=0 ; i<v ; i++){
            if(visited[i] == false){
                if(DFSrec(adj , i , visited , recSt) == true)
                    return false;
            }
        }
        return true ;
    
        }
};    


/*

  The time complexity of this code is O(V+E) where V is the number of courses and E is the number of prerequisites. 
  This is because the algorithm performs a depth first search on the graph represented by the prerequisites, which takes O(V+E) time in the worst case.

  The space complexity of this code is O(V) where V is the number of courses. 
  This is because the algorithm uses O(V) space to store the visited and recursion stack arrays.
  
*/
