#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define x_max 30
#define y_max 100

void dbg(int i){
    cout << i << endl;
}

struct bar{
    int length;
    int speed;
    int position;
    int left;
    int right;
};

void initiate_bar(bar &b, int l, int s, int p, int lft, int rgt){
        b.length = l;
        b.speed = s;
        b.position = p;
        b.left = lft;
        b.right = rgt;
}

class arena{
    char Arena[x_max][y_max];
    bar bar_1;
    bar bar_2;
public:
    arena(bar b1, bar b2){
        bar_1 = b1;
        bar_2 = b2;
    }

    void reset_arena(){
        for(int i = 0; i < x_max; i++){
            for(int j = 0; j < y_max; j++){
                Arena[i][j] = ' ';
            }
        }
    }

    void put_bars(){
        for(int i = bar_1.position; i < bar_1.position + bar_1.length; i++){
            Arena[i][1] = ']';
        }
        for(int i = bar_2.position; i < bar_2.position + bar_2.length; i++){
            Arena[i][y_max - 2] = '[';
        }
    }

    void print_arena(){
        cout << '+';
        for(int i = 0; i < y_max; i++){
            cout << '-';
        }
        cout << '+' <<endl;
        for(int i = 0; i < x_max; i++){
            cout << '|';
            for(int j = 0; j < y_max; j++){
                cout << Arena[i][j];
            }
            cout << '|';
            cout << endl;
        }
        cout << '+';
        for(int i = 0; i < y_max; i++){
            cout << '-';
        }
        cout << '+' <<endl;
    }

    void show_arena(){
        reset_arena();
        put_bars();
        print_arena();
    }

    void move_bars(){
        if(_kbhit()){
            int hit_char = _getch();
            if()
        }
    }
};





int main(){
    bar b1, b2;
    initiate_bar(b1, 5, 1, 4, 43, 44);
    initiate_bar(b2, 5, 1, 4, 54, 55);
    arena A(b1, b2);
    A.show_arena();
}