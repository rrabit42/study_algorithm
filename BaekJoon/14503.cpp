#include <iostream>
using namespace std;
 
// U, R, D, L        (0, 1, 2, 3)
int N, M , robot_x, robot_y, robot_direction, moved_area = 0;
int next_x, next_y;
int** map;
int round_val[4][2] = { { -1, 0 },{ 0, 1 },{ 1 , 0 },{ 0, -1 } };
 
// 뒤쪽으로 이동이 가능한지 확인하는 함수 
int isBackPossible() {
    // 뒤쪽 값 
    next_x = robot_x + round_val[(robot_direction + 2) % 4][0];
    next_y = robot_y + round_val[(robot_direction + 2) % 4][1];
 
    // 뒤쪽이 없다. 
    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) return 0; 
    // 뒤쪽이 벽이다. 
    else if (map[next_x][next_y] == 1) return 0; 
    else {
        return 1;
    }
}
 
// 주변이 비었는지 확인하는 함수 
int isRoundEmpty() {
    int roundFull = 0 ;
    for (int i = 0; i < 4; i++) {
        // 왼쪽 값 
        next_x = robot_x + round_val[(robot_direction + i + 3) % 4][0];
        next_y = robot_y + round_val[(robot_direction + i + 3) % 4][1];
 
        // 왼쪽이 없다. 
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) roundFull++;
        // 왼쪽이 이미 청소되어있다.
        else if (map[next_x][next_y] == 7) roundFull++;
        // 왼쪽이 벽이다. 
        else if (map[next_x][next_y] == 1) roundFull++;
        // 왼쪽이 청소되어있지 않다.
        else if (map[next_x][next_y] == 0) return i;
    }
 
    if (roundFull == 4) return 0;
}
 
int howStatusLeft() {
    // 왼쪽 값 
    next_x = robot_x + round_val[(robot_direction + 3) % 4][0];
    next_y = robot_y + round_val[(robot_direction + 3) % 4][1];
 
    // 왼쪽이 없다. 
    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) return 2;
    // 왼쪽이 이미 청소되어있다.
    else if (map[next_x][next_y] == 7) return -1;
    // 왼쪽이 벽이다. 
    else if (map[next_x][next_y] == 1) return 1;
    // 왼쪽이 청소되어있지 않다.
    else if (map[next_x][next_y] == 0) return 0;
}
 
int move() {
    // 1. 현재 위치를 청소한다. 
    if (map[robot_x][robot_y] == 0) { 
        map[robot_x][robot_y] = 7;
        moved_area++;
    }
 
    // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다. 
    // - 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
    int left_status = howStatusLeft();
    int is_round_empty = isRoundEmpty();
    if (left_status == 0) {
        // 왼쪽으로 회전 
        robot_direction = (robot_direction + 3) % 4;
        robot_x = next_x;
        robot_y = next_y;
    }
    // 네 방향 모두가 청소 되있거나 벽인 경우에는 
    else if (!is_round_empty) {
        //    - 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        if (isBackPossible()) {
            robot_x = robot_x + round_val[(robot_direction + 2) % 4][0];
            robot_y = robot_y + round_val[(robot_direction + 2) % 4][1];
        }
        //    - 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
        else {
            return 0;
        }
    } 
    // - 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    else if(left_status == 1 || left_status == -1) {
        // 왼쪽으로 회전 
        robot_direction = (robot_direction + 3) % 4;
    }
 
    return 1;
}
 
int main() {
    cin >> N >> M;
    cin >> robot_x >> robot_y >> robot_direction;
 
    // 맵 구성
    map = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++) {
        map[i] = (int*)malloc(sizeof(int)*M);
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
 
    while (move()) { 
    }
     
    cout << moved_area;
 
    return 0; 
}
