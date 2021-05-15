#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define true 1
#define false 0
#define bool int
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BOARD_X 4
#define BOARD_Y 2
#define DELAY 100
enum ControlKeys{
    UP        =    72,
    DOWN    =    80,
    LEFT    =    75,
    RIGHT    =    77,
    SPACE    =    32
};
static int score = 0; //gameScore
static int level = 1; //gameLevel
static int speed = 180;
int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2] = {0, };
int blocks[28][4][4] = { //block shape set
                { // I mino
                        {0, 1, 0, 0},
                        {0, 1, 0, 0},
                        {0, 1, 0, 0},
                        {0, 1, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 1, 1, 1},
                        {0, 0, 0, 0}
                },{
                        {0, 1, 0, 0},
                        {0, 1, 0, 0},
                        {0, 1, 0, 0},
                        {0, 1, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 1, 1, 1},
                        {0, 0, 0, 0}
                },{ // O mino
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{ // T mino
                        {0, 0, 0, 0},
                        {0, 1, 0, 0},
                        {1, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 1, 0, 0},
                        {1, 1, 0, 0},
                        {0, 1, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {1, 1, 1, 0},
                        {0, 1, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 1, 0, 0}
                },{ // L mino
                        {0, 0, 0, 0},
                        {0, 0, 1, 0},
                        {1, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 1, 0},
                        {1, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0}
                },{ // J mino
                        {0, 0, 0, 0},
                        {1, 0, 0, 0},
                        {1, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 1, 0},
                        {0, 0, 1, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {1, 1, 0, 0},
                        {1, 0, 0, 0},
                        {1, 0, 0, 0},
                        {0, 0, 0, 0}
                },{ // S mino
                        {0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {0, 1, 1, 0},
                        {1, 1, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 0}
                },{ // Z mino
                        {0, 0, 0, 0},
                        {1, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 1, 0},
                        {0, 1, 1, 0},
                        {0, 1, 0, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 0, 0},
                        {1, 1, 0, 0},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0}
                },{
                        {0, 0, 1, 0},
                        {0, 1, 1, 0},
                        {0, 1, 0, 0},
                        {0, 0, 0, 0}
                },
        }; // shape set end
void CursorVisible(bool blnCursorVisible){
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = blnCursorVisible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void SetCursorPosition(int cursorLeft, int cursorTop){
    int posX = cursorLeft;
    int posY = cursorTop;
    COORD pos = {posX, posY};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD GetCursorPosition(void){
    COORD cursor;
    CONSOLE_SCREEN_BUFFER_INFO cursorInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursor.X = cursorInfo.dwCursorPosition.X;
    cursor.Y = cursorInfo.dwCursorPosition.Y;
    return cursor;
}
//start consol
void ConsoleInit(){
    printf("C consol tetris\n\n");
    printf(""
           "===================================        \n"
           "how to move:                                        \n"
           "[right]     block right move              \n"
           "[left]     block left move                \n"
           "[up]     block turn left           \n"
           "[down]     block 1 down             \n"
           "[Space]  full down                    \n"
           "                                            \n"
           "press any key to start                 \n"
           "===================================           \n");
    _getch();
    system("cls");
    CursorVisible(false);
    SetCursorPosition(0, 0);
}

void DrawField(void){
    int x, y;

    for (x = 1; x <= BOARD_WIDTH + 1; x++){
        board[BOARD_HEIGHT][x]=1;
        SetCursorPosition((BOARD_X) + x * 2, BOARD_Y + BOARD_HEIGHT);
        printf("0");
    }
    for (y = 0; y < BOARD_HEIGHT + 1; y++){
        board[y][0] = 1;
        SetCursorPosition(BOARD_X, BOARD_Y+y);
        if(y == BOARD_HEIGHT)
            printf("0");
        else
            printf("0");
    }
    for (y = 0; y < BOARD_HEIGHT + 1; y++){
        board[y][BOARD_WIDTH + 1]=1;
        SetCursorPosition(BOARD_X + (BOARD_WIDTH + 2) * 2, BOARD_Y + y);
        if(y == BOARD_HEIGHT) {
            printf("0");
        }
        else{
            printf("0");
        }
    }
    board[20][0]=1;
    board[20][11]=1;
    puts(" ");
}

void ShowPoint(void){
    SetCursorPosition(40, 3);
    printf("C consol tetris ");
    SetCursorPosition(40, 5);
    printf("level: %d\n",level);
    SetCursorPosition(40, 7);
    printf("score: %d\n",score);
}

bool CanPositionedAt(int rotation, int move1, int move2){
    int x, y;
    int arrX, arrY;
    COORD pos = GetCursorPosition();
    arrX = pos.X + move1;
    arrY = pos.Y + move2;
    arrX = (arrX / 2) - 2;
    arrY = arrY - BOARD_Y;
    for(y = 0; y < 4; y++){
        for(x = 0; x < 4; x++) {
            if ((blocks[rotation][y][x] == 1) && board[arrY + y][arrX + x] == 1) {
                return false;
            }
        }
    }
    return true;
}

void WriteBlock(int rotation){
    int i, j;
    COORD cursor = GetCursorPosition();
    if (CanPositionedAt(rotation, 0, 0) == true){
        for (i = 0; i < 4; i++){
            for (j = 0; j < 4; j++){
                SetCursorPosition(cursor.X + (j * 2), cursor.Y + i);
                if (blocks[rotation][i][j] == 1){
                    printf("8");
                }
            }
        }
        SetCursorPosition(cursor.X, cursor.Y);
    }
}
void BoardInit(int n,int move1, int move2)
{
    COORD pos = GetCursorPosition();

    int arrX = pos.X + move1;
    int arrY = pos.Y + move2;
    int x, y;
    arrX = arrX / 2 - 2;
    arrY = arrY - 2;
    for(y = 0; y < 4; y++){
        for(x = 0; x < 4; x++){
            if(blocks[n][y][x] == 1){
                board[arrY + y][arrX + x] =1;
            }
        }
    }
}

void Stepper(int column){
    int y, x;
    for (y = column; y >= 0; y--){
        for (x = 1; x <= 10; x++){
            board[y][x] = board[y - 1][x];
        }
    }
    for(x = 1; x <= 10; x++) {
        board[0][x] = 0;
    }

    for(y = 1; y <= 19; y++){
        for(x = 1; x <= 10; x++){
            SetCursorPosition((BOARD_X) + x * 2 + 1, y + BOARD_Y);
            if(board[y][x] == 1) {
                printf("8");
            }
            else {
                printf("  ");
            }
        }
    }
}
void CountScore(void){
    score += 10;
    if(score % 30 == 0){
        level += 1;
        speed -= 30;
    }
    ShowPoint();
}

void RemoveLine(void){
    int i;
    int x, y;
    int z=0;
    for (y = 19; y >= 1; y--){
        for (z = 0; z < 4; z++){
            i = 0;
            for (x = 1; x < 11; x++){
                if (board[y][x] == 1){
                    i++;
                    if (i == 10){
                        for (x = 1; x < 11; x++){
                            SetCursorPosition((x + 2) * 2, y + 2);
                            printf("  ");
                        }
                        CountScore();
                        Stepper(y);
                    }
                }
            }
        }
    }
}

void ClearBlock(int rotation, int move1, int move2){
    int x, y;
    COORD cursor = GetCursorPosition();
    if(CanPositionedAt(rotation, move1, move2) == true){
        for(y = 0; y < 4; y++){
            for(x = 0; x < 4; x++){
                SetCursorPosition(cursor.X + (x * 2), cursor.Y + y);
                if(blocks[rotation][y][x] == 1) {
                    printf(" ");
                }
            }
        }
        SetCursorPosition(cursor.X + move1, cursor.Y + move2);
    }
}

void StartGame(void){
    int n;
    int kb;
    int c=2;
    srand((unsigned)time(0));

    while (1){

        SetCursorPosition(13, 2);
        n = rand() % 7;
        n = n * 4;
        if (level == 10){
            SetCursorPosition(40, 15);
            printf("game clear");
            getchar();
            exit(1);
        }
        if(CanPositionedAt(n, 0, 0) == false)
            break;

        while (1){
            int ww = 0;
            int k = 0;
            while(!_kbhit()){
                WriteBlock(n);
                Sleep(DELAY + speed);
                if(CanPositionedAt(n, 0, 1) == false){
                    ww = 1;
                    BoardInit(n, 0, 0);
                    RemoveLine();
                    break;
                }
                ClearBlock(n, 0, 1);
            }
            if(ww==1) {
                break;
            }
            kb = _getch();
            switch(kb){
                case LEFT:
                    ClearBlock(n, -2, 0);
                    WriteBlock(n);
                    break;
                case RIGHT:
                    ClearBlock(n, 2, 0);
                    WriteBlock(n);
                    break;
                case UP:
                    k = n / 4;
                    k *= 4;
                    if((n + 1) <= (k + 3)){
                        k = n + 1;
                    }
                    if(CanPositionedAt(k, 0, 0) == true){
                        ClearBlock(n, 0, 0);
                        n = k;
                        WriteBlock(n);
                        break;
                    }
                    break;
                case DOWN:
                    ClearBlock(n, 0, 2);
                    break;
                case SPACE:
                    while (1){
                        ClearBlock(n,0,1);
                        if(CanPositionedAt(n,0,1) == false){
                            WriteBlock(n);
                            BoardInit(n,0,0);
                            break;
                        }
                    }
                default: break;
            }
        }
    }
}

void EndGame(){
    SetCursorPosition(40, 15);
    printf("end game");
    getchar();
    system("cls");
}

int main(){
    ConsoleInit();
    DrawField();
    ShowPoint();
    StartGame();
    EndGame();
}