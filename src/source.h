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
#include <unistd.h>
#endif

using namespace std;

void fileIn(string IrregularVerbs[4][100]);
void fileOut(string IrregularVerbs[4][100]);
void fileNotFound();

void choiceTest(string IrregularVerbs[4][100]);
void choiceTestInterface();

void mainMenu(string IrregularVerbs[4][100]);
void mainMenuInterface();

void IncorrectInput();

void Table_of_Record_Input(int score);
void Table_of_Record_Sort();
void Table_of_Record_Output(string IrregularVerbs[4][100]);

int testCheck(int correct);
int verbCheck(string user, string verb);
int yesCheck(char sym);

void sleep_ms(int milliseconds);

#endif
