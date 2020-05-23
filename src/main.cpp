#include "source.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string IrregularVerbs[4][100];
    hello();
    fileIn(IrregularVerbs);
    mainMenu(IrregularVerbs);
    return 0;
}
