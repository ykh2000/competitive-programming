/*

Number of Maximum Paths in a Complete DAG = 2^(N-2)
N = Number of nodes
N-2 =  Number of nodes in the middle

PSEUDO-CODE

function findAllPaths(graph){
nodeCount = number of nodes in the graph   #n
targetNode = nodeCount-1;  # the last node

answer = empty list of list.       #All Paths Found
currentPath =                      # The Path I'am Walking
EXPLORE(0)                         # Begin at the source
RETURN ANSWER
}


function EXPLORE(node): dfs
    APPEND NODE to currentPath
    IF (NODE !== TARGET_NODE):
        APPEND A COPY OF CURRENT PATH TO ANSWER
    ELSE:
        FOR EACH neighbour IN graph[Node]:
        EXPLORE(neighbour)
    REMOVE LAST ELEMENT FROM CURRENT PATH
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodeCount = graph.size();
        int targetNode = nodeCount - 1;
        vector<vector<int>> allPaths; //CollectFinished Routes
        //One route currently being walked - 
        vector<int> currentPath;
        //Start DFS from the source, node 0
        explore(0,graph,targetNode,currentPath, allPaths);
        return allPaths;  
      }
private:
      /*
        DFS + Backtracking
        1.int node  : Node -> The Current node this function call is standing on
        2. graph : const&  -> readonly, avoids copying the whole graph
        3. targetNode : destination index (n-1)
        4. currentPath : &  --> WE MUTATE IT (PUSH ON ENTRY, POP ON EXIST)
        5. allPaths    : &  --> We append to it,
        WE WILL APPEND THE currentPath TO allPaths after reaching the targetNode from node(source)
       */
      void explore(int node, const vector<vector<int>> &graph, int targetNode, vector<int>& currentPath,
            vector<vector<int>> &allPaths){
                //STEP-1 : ENTER
                // Arrive at the Node
                currentPath.push_back(node);
                //step-2 check for destination
                if(node  == targetNode){
                    //step-2a
                    //Success
                    //Push_back the copy of currentPath into allPaths
                    allPaths.push_back(currentPath);
                }
                else{
                    //STEP-3 EXPLORE
                    for(int neighbour : graph[node]){
                        explore(neighbour,graph,targetNode,currentPath, allPaths);
                    }
                }

                //STEP - 4 LEAVE (BACKTRACK)
                currentPath.pop_back();
            }
};