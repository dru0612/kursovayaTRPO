#ifndef SOURCE_H
#define SOURCE_H

#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include <stdio.h>
#ifndef __linux
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
int getch()

{
    int ch;

    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

#define n 100

using namespace std;

void hello();
void support();
void KoE(string v[4][n]);
void fileIn(string v[4][n]);
void fileOut(string v[4][n]);
void dictionary(string v[4][n]);
void ToRIn(int score);
void ToRSort();
void ToROut();
void choiceTest(string v[4][n]);
void mainMenu(string v[4][n]);
void TestRussian(string v[4][n]);
void TestToTime(string v[4][n]);

#endif
