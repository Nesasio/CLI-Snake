// Simple CLI Snake game made in c++

// Author: Light

// =================================


#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// =================================


bool gameOver;
const int height = 20;
const int width = 20;
int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100], LTail;

enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir;


// --------------------


void Setup();
void Draw();
void Input();
void Logic();

// --------------------


int main() {

    Setup();
    while(!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(40);
    }

    return 0;
}

// --------------------


void Setup() {

    gameOver = false;
    dir = STOP;

    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

// --------------------


void Draw() {

    system("CLS");

    for(int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0 || j == width - 1) {
                cout << "#";
            }

            else if(i == y && j == x) {
                cout << "O";
            }

            else if(i == fruitY && j == fruitX) {
                cout << "F";
            } 

            else {

                bool blank = false;

                for(int k = 0; k < LTail - 1; k++) {
                    if(i == tailY[k] && j == tailX[k]) {
                        cout << "O";
                        blank = true;
                    }
                }

                if(!blank) 
                    cout << " ";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << "\n\nSCORE: " << score << endl;;
}

// --------------------


void Input() {

    if(_kbhit()) {
        switch(_getch()) {
            case 'w':
                dir = UP;
                break;

            case 's':
                dir = DOWN;
                break;

            case 'a':
                dir = LEFT;
                break;

            case 'd':
                dir = RIGHT;
                break;

            default:
                break;
        }
    }
}

// --------------------


void Logic() {

    int lastX = tailX[0];
    int lastY = tailY[0];

    tailX[0] = x;
    tailY[0] = y;

    int last2X, last2Y;

    for(int i = 0; i < LTail; i++) {
        last2X = tailX[i];
        last2Y = tailY[i];
        tailX[i] = lastX;
        tailY[i] = lastY;
        lastX = last2X;
        lastY = last2Y;
    }

    switch(dir) {
        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;

        default:
            break;
    }

    // ----------------

    if(x < 0 || x > width || y < 0 || y > height) {
        gameOver = true;
    }

    for(int i = 0; i < LTail; i++)
    {
        if(x == tailX[i] && y == tailY[i]) {
            gameOver = true;
        }
    }

    if(x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        LTail++;
    }
}

// =========== END OF PROGRAM ============
