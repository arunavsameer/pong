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

void moveTo(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

void clearPosition(int x, int y) {
    moveTo(x, y);
    cout << " ";
}

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
public:
    arena(bar b1, bar b2){
        bar_1 = b1;
        bar_2 = b2;
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
        }
    }
};





int main(){
    bar b1(5, 1, 4, 119, 115);
    bar b2(5, 1, 5, 72, 80);
    arena A(b1, b2);
    A.play();
}