#ifndef SOURCE_H
#define SOURCE_H

#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define n 100

using namespace std;

void hello();
void support(string v[4][n]);
void KoE(string v[4][n]);
void fileIn(string v[4][n]);
void fileOut(string v[4][n]);
void dictionary(string v[4][n]);
void mainMenu(string v[4][n]);
void ToRIn(int score);
void ToRSort();
void ToROut(string v[4][n]);
int testCheck(int sc);
int verbCheck(string user, string verb);
int yesCheck(char ch);
void choiceTest(string v[4][n]);
void TestRussian(string v[4][n]);
void TestToTime(string v[4][n]);

#endif
