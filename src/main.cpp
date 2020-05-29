#include "source.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string IrregularVerbs[LotOfForms][LotOfIrregularVerbs];
    hello();
    fileIn(IrregularVerbs);
    mainMenu(IrregularVerbs);
    return 0;
}
