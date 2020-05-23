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

int yesCheck(char ch)
{
    if ((ch == 'Y') || (ch == 'y'))
        return 1;
    else
        return 0;
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

void fileIn(string IrregularVerbs[4][100])
{
    ifstream file("verb+.txt");
    if (!file) {
        cout << "При открытии файла произошла ошибка.\n";
        cout << "Программа может быть установлена неправильно\n";
        exit(0);
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            file >> IrregularVerbs[j][i];
        }
    }
}

void fileOut(string IrregularVerbs[4][100])
{
    for (int i = 0; i < 100; i++) {
        cout << i + 1 << ") ";
        cout.width(10);
        cout << IrregularVerbs[0][i];
        cout.width(20);
        cout << IrregularVerbs[1][i];
        cout.width(20);
        cout << IrregularVerbs[2][i];
        cout.width(20);
        cout << IrregularVerbs[3][i] << endl;
    }
}

void dictionary(string IrregularVerbs[4][100])
{
    fileOut(IrregularVerbs);
    cout << endl << "Нажмите любую кнопку, чтобы продолжить." << endl;
    system("pause");
    system("CLS");
    mainMenu(IrregularVerbs);
}

void choiceTest(string IrregularVerbs[4][100])
{
    cout << "1 - Тест на знание всех глаголов из справочника" << endl;
    cout << "2 - Тест на знание перевода" << endl;
    cout << "3 - Тест на скорость" << endl << endl;
    cout << "0 - Вернуться в главное меню" << endl;

    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        switch (sym[0]) {
        case '1': {
            system("CLS");
            KoE(IrregularVerbs);
            break;
        }
        case '2': {
            system("CLS");
            TestRussian(IrregularVerbs);
            break;
        }
        case '3': {
            system("CLS");
            TestToTime(IrregularVerbs);
            break;
        }
        case '0': {
            system("CLS");
            mainMenu(IrregularVerbs);
            break;
        }
        default: {
            cout << endl << "Неверный режим! Пожалуйста, повторите выбор";
            cout << endl;
            sleep_ms(2000);
            system("CLS");
            choiceTest(IrregularVerbs);
        }
        }
    else {
        cout << endl << "Неверный режим! Пожалуйста, повторите выбор";
        cout << endl;
        sleep_ms(2000);
        system("CLS");
        choiceTest(IrregularVerbs);
    }
}

void Table_of_Record_Input(int score)
{
    FILE* tf;
    struct record {
        char name[50];
        int speed;
        char output[20];
    } man;
    man.speed = score;
    tf = fopen("Table of Records", "ab");
    cout << endl << "Введите ваше имя: ";
    cin >> man.name;

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    strcpy(man.output, " Date:  ");
    strcpy(man.output, asctime(timeinfo));

    fwrite(&man, sizeof(man), 1, tf);
    fclose(tf);
}

void Table_of_Record_Sort()
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

void Table_of_Record_Output(string v[4][100])
{
    FILE* tf;
    system("CLS");
    cout << "Результаты:" << endl << endl;
    struct record {
        char name[50];
        int speed;
        char output[20];
    } man;
    int i = 1;
    Table_of_Record_Sort();
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

void mainMenu(string IrregularVerbs[4][100])
{
    while (1) {
        cout << "1 - Выбор теста" << endl;
        cout << "2 - Результаты" << endl;
        cout << "3 - Показать словарь глаголов" << endl;
        cout << "4 - Помощь" << endl << endl;
        cout << "0 - Выход" << endl;

        char sym[50];
        cin >> sym;
        if (strlen(sym) == 1)
            switch (sym[0]) {
            case '1': {
                system("CLS");
                choiceTest(IrregularVerbs);
                break;
            }
            case '2': {
                system("CLS");
                Table_of_Record_Output(IrregularVerbs);
                break;
            }
            case '3': {
                system("CLS");
                dictionary(IrregularVerbs);
                break;
            }
            case '4': {
                system("CLS");
                support(IrregularVerbs);
                break;
            }
            case '0': {
                exit(0);
            }
            default: {
                cout << endl << "Неверный режим! Пожалуйста, повторите выбор";
                cout << endl;
                sleep_ms(2000);
                system("CLS");
            }
            }
        else {
            cout << endl << "Неверный режим! Пожалуйста, повторите выбор";
            cout << endl;
            sleep_ms(2000);
            system("CLS");
        }
    }
}

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}
