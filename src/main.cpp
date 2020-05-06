#include "source.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    string v[4][n];
    if (fileIn(v)) {
        hello();
        while (1) {
            if (!mainMenu(v))
                return 0;
        }
    }
    return 0;
}
