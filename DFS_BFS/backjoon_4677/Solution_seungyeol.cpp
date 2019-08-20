//
//  main.cpp
//  baek4677oil
//
//  Created by ShinSeungYeol on 2019. 8. 20..
//  Copyright © 2019년 ShinSeungYeol. All rights reserved.
//

#include <cstdio>

// 맵의 최대크기 1<=m<=100, 1<=n<=100
bool map[100][100];
// 전체 regions의 정보를 담을 배열 1일 경우 pocket,
bool already_checked_regions[100][100];
// 이미 경유가 된 (확인이 된) region인지 정보를 담을 배열
int m = 0, n = 0;
// 전체 맵의 row, col 크기 변수

void get_input();
bool is_unchecked_pocket (int row, int col );
bool is_grid(int row, int col);
void check_adjacent_regions (int start_row, int start_col);
int calc_oil_deposits();
void init_data();

int main(int argc, const char * argv[]) {
    while (true) {
        get_input();
        if (m==0) {
            break;
        }
        printf("%d\n", calc_oil_deposits());
        init_data();
    }
    return 0;
}

void get_input() {
    scanf("%d %d", &m, &n);
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            char temp_char;
            scanf(" %c", &temp_char); //공백을 주어 \n 무시
            if (temp_char == '@') {
                map[i][j] = true;
                
            }
        }
    }
}

int calc_oil_deposits() {
    int number_of_oil_pockets = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (is_unchecked_pocket(i, j)) {
                number_of_oil_pockets++;
                check_adjacent_regions(i, j);
                
            }
        }
    }
    
    return number_of_oil_pockets;
}

bool is_unchecked_pocket (int row, int col ) {
    return map[row][col] && !already_checked_regions[row][col];
}

void check_adjacent_regions (int start_row, int start_col) {
    already_checked_regions[start_row][start_col] = true;
    
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            int row = start_row+i;
            int col = start_col+j;
            if(is_grid(row, col) && is_unchecked_pocket(row, col)) {
                check_adjacent_regions(row, col);
            }
            
        }
    }
}

bool is_grid(int row, int col) {
    return 0<=row && row<=m && 0<=col && col<=n;
}

void init_data() {
    for ( int i=0; i<m; i++) {
        for ( int j=0; j<n; j++) {
            map[i][j] = false;
            already_checked_regions[i][j] = false;
        }
    }
}





