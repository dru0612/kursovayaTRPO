#include "source.h"

using namespace std;

int testCheck(int sc)
{
    if (sc == 3) {
        return 1;
    } else {
        return 0;
    }
}

int verbCheck(string user, string verb)
{
    if (user == verb)
        return 1;
    else if (user == "exit")
        return 2;
    else
        return 0;
}

void fileIn(string v[4][n])
{
    ifstream file("verb+.txt");
    if (!file) {
        cout << "При открытии файла произошла ошибка.\n";
        cout << "Программа может быть установлена неправильно\n";
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            file >> v[j][i];
        }
    }
}

void fileOut(string v[4][n])
{
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        cout.width(10);
        cout << v[0][i];
        cout.width(20);
        cout << v[1][i];
        cout.width(20);
        cout << v[2][i];
        cout.width(20);
        cout << v[3][i] << endl;
    }
}

void dictionary(string v[4][n])
{
    fileOut(v);
    cout << endl << "Нажмите любую кнопку, чтобы продолжить." << endl;
    system("pause");
    system("CLS");
    mainMenu(v);
}

void choiceTest(string v[4][n])
{
    cout << "1 - Test for knowledge of all verbs from the reference book"
         << endl;
    cout << "2 - Translation Test" << endl;
    cout << "3 - Speed test" << endl << endl;
    cout << "0 - Return to main menu" << endl;

    char a;
    cin >> a;
    switch (a) {
    case '1': {
        system("CLS");
        KoE(v);
        break;
    }
    case '2': {
        system("CLS");
        TestRussian(v);
        break;
    }
    case '3': {
        system("CLS");
        TestToTime(v);
        break;
    }
    case '0': {
        system("CLS");
        mainMenu(v);
        break;
    }
    default: {
        cout << endl << "Invalid mode! Please retype";
        for (int i = 0; i < 10000000; i++)
            ;
        system("CLS");
        choiceTest(v);
    }
    }
}

void ToRIn(int score)
{
    FILE* tf;
    struct record {
        char name[50];
        int speed;
        char output[20];
    } man;
    man.speed = score;
    tf = fopen("Table of Records", "ab+");
    cout << endl << "Enter your name: ";
    cin >> man.name;

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    strcpy(man.output, " Date:  ");
    strcpy(man.output, asctime(timeinfo));

    fwrite(&man, sizeof(man), 1, tf);
    fclose(tf);
}

void ToRSort()
{
    FILE* tf;
    int k = 0, i = 0;
    system("CLS");
    struct record {
        char name[50];
        int speed;
        char output[20];
    } man;
    tf = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, tf)) {
        k++;
    }
    struct record people[k], temp;
    fclose(tf);
    tf = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, tf)) {
        people[i] = man;
        i++;
    }
    int p, q;
    for (p = 0; p < k; p++) {
        for (q = 0; q < k - 1; q++) {
            if (people[q].speed < people[q + 1].speed) {
                temp = people[q];
                people[q] = people[q + 1];
                people[q + 1] = temp;
            }
        }
    }
    fclose(tf);
    tf = fopen("Table of Records", "wb");
    for (i = 0; i < k; i++) {
        if (i < 10)
            fwrite(&people[i], sizeof(people[i]), 1, tf);
    }
    fclose(tf);
}

void ToROut(string v[4][n])
{
    FILE* tf;
    system("CLS");
    cout << "Records:" << endl << endl;
    struct record {
        char name[50];
        int speed;
        char output[20];
    } man;
    int i = 1;
    ToRSort();
    tf = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, tf)) {
        cout << i << ") " << man.name << " " << man.speed << " " << man.output
             << endl;
        i++;
    }
    system("pause");
    system("CLS");
    fclose(tf);
    mainMenu(v);
}

void mainMenu(string v[4][n])
{
    cout << "1 - Choise a test" << endl;
    cout << "2 - Rating" << endl;
    cout << "3 - View directory" << endl;
    cout << "4 - Help" << endl << endl;
    cout << "0 - Exit" << endl;

    char uCom;
    cin >> uCom;
    switch (uCom) {
    case '1': {
        system("CLS");
        choiceTest(v);
        break;
    }
    case '2': {
        system("CLS");
        ToROut(v);
        break;
    }
    case '3': {
        system("CLS");
        dictionary(v);
        break;
    }
    case '4': {
        system("CLS");
        support(v);
        break;
    }
    case '0': {
        exit(0);
    }
    default: {
        cout << endl << "Invalid mode! Please repeat input";
        for (int i = 0; i < 10000000; i++)
            ;
        system("CLS");
    }
    }
}
