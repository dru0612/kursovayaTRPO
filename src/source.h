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

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h> // for usleep
#endif

using namespace std;

void fileIn(string IrregularVerbs[4][100]);
void fileOut(string IrregularVerbs[4][100]);
void mainMenu(string IrregularVerbs[4][100]);
void Table_of_Record_Input(int score);
void Table_of_Record_Input();
void Table_of_Record_Input(string IrregularVerbs[4][100]);
int testCheck(int sc);
int verbCheck(string user, string verb);
int yesCheck(char ch);
void sleep_ms(int milliseconds);

#endif
