#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

#define x_max 30
#define y_max 100

void dbg(int i){
    cout << i << endl;
}

void moveTo(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

void clearPosition(int x, int y) {
    moveTo(x, y);
    cout << " ";
}

class ball{
    int vel_x;
    int vel_y;
    int pos_x;
    int pos_y;
public:
    ball(){
        vel_x = 1;
        vel_y = 1;
        pos_x = 5;
        pos_y = 5;
    }
    ball(int v_x, int v_y, int p_x, int p_y){
        vel_x = v_x;
        vel_y = v_y;
        pos_x = p_x;
        pos_y = p_y;
    }
    bool collide_ends(){
        if(pos_y >= y_max || pos_y <= 0){
            return true;
        }
        return false;
    }
    
    void move_ball(){
        clearPosition(pos_x + 2, pos_y + 2);
        moveTo(pos_x + 2 + vel_x, pos_y + 2 + vel_y);
        cout << 'o';
        pos_x = pos_x + vel_x;
        pos_y = pos_y + vel_y;
        cout.flush();
    }
    friend class arena;
};


class bar{
protected:
    int length;
    int speed;
    int position;
    int up;
    int down;
public:
    bar(){
        length = 5;
        speed = 1;
        position = 1;
        up = 43;
        down = 44;
    }
    bar(int l, int s, int p, int lft, int rgt){
        length = l;
        speed = s;
        position = p;
        up = lft;
        down = rgt;
    }

    char move_bar(){
        if(_kbhit()){
            int hit_char = _getch();
            if(hit_char == up){
                if(position == 0){
                    return 's';
                }else{
                    return 'u';
                }
            }else if(hit_char == down){
                if(position == x_max - length){
                    return 's';
                }else{
                    return 'd';
                }
            }else{
                return's';    
            }
        }
    }

    friend class arena;
};

class arena{
    char Arena[x_max][y_max];
    bar bar_1;
    bar bar_2;
    ball ball_1;
public:
    arena(bar b1, bar b2, ball b){
        bar_1 = b1;
        bar_2 = b2;
        ball_1 = b;
        cout << bar_1.position <<endl;
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

    void play(){
        show_arena();
        while(1){
            sleep(1);

            if(bar_1.move_bar() == 'u'){
                clearPosition(3 , bar_1.position + bar_1.length + 1);
                moveTo(3, bar_1.position + 1);
                bar_1.position--;
                cout << ']';
                cout.flush();
            }
            if(bar_1.move_bar() == 'd'){
                clearPosition(3, bar_1.position + 2);
                moveTo(3, bar_1.position + bar_1.length + 2);
                bar_1.position++;
                cout << ']';
                cout.flush();
            }
            if(bar_2.move_bar() == 'u'){
                clearPosition(y_max , bar_2.position + bar_2.length + 1);
                moveTo(y_max, bar_2.position + 1);
                bar_2.position--;
                cout << '[';
                cout.flush();
            }
            if(bar_2.move_bar() == 'd'){
                clearPosition(y_max, bar_2.position + 2);
                moveTo(y_max, bar_2.position + bar_2.length + 2);
                bar_2.position++;
                cout << '[';
                cout.flush();
            }
            ball_1.move_ball();
        }
    }
};





int main(){
    bar b1(5, 1, 4, 119, 115);
    bar b2(5, 1, 5, 72, 80);
    ball b(1, 1, 5, 5);
    arena A(b1, b2, b);
    A.play();
}