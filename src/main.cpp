#include "source.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    string v[4][100];
    hello();
    fileIn(v);
    mainMenu(v);
    return 0;
}
