#ifndef SOURCE_H
#define SOURCE_H

#include "hello.h"
#include "test.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

void fileIn(string v[4][100]);
void fileOut(string v[4][100]);
void mainMenu(string v[4][100]);
void ToRIn(int score);
void ToRSort();
void ToROut(string v[4][100]);
int testCheck(int sc);
int verbCheck(string user, string verb);
int yesCheck(char ch);

#endif
