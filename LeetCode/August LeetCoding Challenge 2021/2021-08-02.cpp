class Solution {
public:
    // map으로 나중에 바꾸기
    int result[250000] = {0, };
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // 
    int bfs(vector<vector<int>>& grid, int row, int col, int id){
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        
        int area = 0;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(grid[x][y] == 1)
            {
                grid[x][y] = id;
                area++;
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size()) continue;

                    if(grid[nx][ny] == 1){
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        return area;
    }
    
    // 인접한 영역 개수 더하기
    int neighbor(vector<vector<int>>& grid, int x, int y){
        int area = 1;
        
        int L = ((x-1) >= 0)? grid[x-1][y]: 0;
        int R = ((x+1) < grid.size())? grid[x+1][y]: 0;
        int U = ((y-1) >= 0)? grid[x][y-1]: 0;
        int T = ((y+1) < grid.size())? grid[x][y+1]: 0;
        
        area += result[L];
        if(L != R) area += result[R];
        if(U != L && U != R) area += result[U];
        if(T != L && T != R && T!= U) area += result[T];
        
        return area;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        stack<pair<int, int>> zero_stack;
        int n = grid.size();
        int id = 2;
        
        // 1. 바꾸지 않았을 때 영역 개수 세기 -> 세면서 0인 영역은 stack에 넣고
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    result[id] = bfs(grid, i, j, id);
                    ++id;
                }
                else if(grid[i][j] == 0){
                    zero_stack.push(make_pair(i, j));
                }
            }
        }
        
        // 2. 0 -> 1로 바꿔가면서 영역 개수 세기
        while(!zero_stack.empty()){
            int x = zero_stack.top().first;
            int y = zero_stack.top().second;
            zero_stack.pop();
            max_area = max(max_area, neighbor(grid, x, y));
        }
        
        // while문 통과하지 못했을 시
        int val = *max_element(result, result+500);
        max_area = max(max_area, val);
        
        // 가장 큰 사이즈 리턴
        return max_area;
    }
};
