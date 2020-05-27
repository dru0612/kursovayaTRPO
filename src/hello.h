#ifndef HEL_H
#define Hel_H

#include <iostream>

#define LotOfIrregularVerbs 100
#define LotOfForms 4

using namespace std;

void hello();
void support(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs]);
void fileNotFound();
void choiceTestInterface();
void mainMenuInterface();
void testBeEnded(int timeStart, int score);
void Subtotal(int timeDelta, int score, int mistakes);
void IncorrectInput();

#endif
