#ifndef T_H
#define t_H

#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

void KnownOfEveryTest(string IrregularVerbs[4][100]);
void TestRussian(string IrregularVerbs[4][100]);
void TestToTime(string IrregularVerbs[4][100]);

void testBeEnded(int timeStart, int score);

#endif
