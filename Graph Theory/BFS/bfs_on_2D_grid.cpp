#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
// {x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}
vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; 

bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= N || y >= M) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
    return true;
}

void DFS(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<directions.size(); i++) {
        int new_row = x + directions[i].first;
        int new_col = y + directions[i].second;
        if(isValid(new_row, new_col)) {
            DFS(new_row, new_col);
        }
    }
}

int main() {
    cin >> N >> M;
    grid.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visited[i][j]) {
                DFS(i, j);
            }
        }
    }

    return 0;
}
