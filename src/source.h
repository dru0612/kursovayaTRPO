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

void fileIn(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void fileOut(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void choiceTest(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void mainMenu(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void Table_of_Record_Input(int score);
void Table_of_Record_Sort();
void Table_of_Record_Output(
        string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
int testCheck(int correct);
int verbCheck(string user, string verb);
int yesCheck(char sym);

#endif
