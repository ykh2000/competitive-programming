class Solution {
public:
      //Directional Arrays
    /**
      row-1,col
      row+1,col
      row,col-1
      row,col+1
     * */
    int rows;
    int cols;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int startRow, int startCol){
        stack<pair<int,int>>st;
        st.push({startRow,startCol});
        while(!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();
            //If Already processed
            if(visited[row][col]) continue;
            // Mark the visited element as - true
            visited[row][col] = true;
            // Explore all 4 neighbours
            for(int i = 0;i<4;i++){
                int newRow = row+dr[i];
                int newCol = col+dc[i];

                //Check for boundary - Outside of the grid
                if(newRow < 0 || newRow >=rows ||
                    newCol < 0 || newCol >= cols
                    ) continue;
                    //Already Visited
                if(visited[newRow][newCol]) continue;
                if(heights[newRow][newCol] < heights[row][col]) continue;
                st.push({newRow,newCol});
            }
        }
    }
    // Heights is the Input Grid
    /**
     * Heights look something like this - 
     1 2 2
     3 2 3
     2 4 5

    The Problem asks for Co-ordinates 
    We return something like this - 
    {
    {0,4},
    {1,3},
    {2,2}
    }  -> return type is vector<vector<int>>  

     * */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
     /**
      * We have to store the grid 
      **/
   rows = heights.size();
   cols = heights[0].size();
    /**
     * F F F F
       F F F F
       F F F F
     **/

    vector<vector<bool>> pacific(rows, vector<bool>(cols,false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols,false));

/**
 * PACIFIC DFS
 * 1. TOP ROW 
 * 2. LEFT COLUMN
 * 
 * 
 * */
 for(int col = 0; col<cols;col++){
    dfs(heights, pacific, 0, col);
 }
 for(int row = 0;row<rows;row++){
    dfs(heights, pacific , row,0);
 }


/***
 * ATLANTIC
 * 1. BOTTOM ROW 
 * 2. RIGHT COLUMN
 * */

 for(int col = 0; col<cols;col++){
    dfs(heights,atlantic,rows-1,col);
 }

for(int row = 0;row<rows;row++){
    dfs(heights, atlantic, row,cols-1);
}

/***
 * 
 * FIND CELLS THAT ARE REACHABLE TO BOTH THE OCEANS
 * 
 * */

vector<vector<int>> answer;
for (int i = 0; i < rows; i++)
{
    for (int j=0;j<cols; j++)
    {
        if(pacific[i][j] && atlantic[i][j]){
            answer.push_back({i,j});
        }
    }
}
return answer;

    }
};
