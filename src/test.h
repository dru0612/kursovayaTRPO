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

void KnownOfEveryTest(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void TestRussian(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void TestToTime(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
int ScoreBalance(int score, int scorePlus, int scoreMinus, bool correct);

#endif
