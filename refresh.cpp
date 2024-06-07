#include <bits/stdc++.h>
using namespace std;

void moveTo(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}

void clearPosition(int x, int y) {
    moveTo(x, y);
    cout << " ";
}

void printBall(int x, int y) {
    moveTo(x, y);
    cout << "O";
    cout.flush();
}

int main() {
    int width = 20, height = 10;
    int ballX = 2, ballY = 2;
    int dx = 1, dy = 1;

    cout << "\033[2J";
    for (int y = 1; y <= height; ++y) {
        for (int x = 1; x <= width; ++x) {
            moveTo(x, y);
            if (y == 1 || y == height || x == 1 || x == width) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
    }

    while (true) {
        clearPosition(ballX, ballY);
        ballX += dx;
        ballY += dy;
        if (ballX == 1 || ballX == width) dx = -dx;
        if (ballY == 1 || ballY == height) dy = -dy;
        printBall(ballX, ballY);
        //delay
        for(long long int i = 0; i < 10000000; i++){
            for(long long int j = 0; j < 10; j++){
                i = i;
            }
        }
    }
}
