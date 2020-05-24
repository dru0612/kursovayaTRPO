#include "source.h"

using namespace std;

int testCheck(int correct)
{
    if (correct == 3) {
        return 1;
    } else {
        return 0;
    }
}

int yesCheck(char sym)
{
    if ((sym == 'Y') || (sym == 'y'))
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

void fileNotFound()
{
    cout << "При открытии файла произошла ошибка.\n\n";
    cout << "Проверьте, пожалуйста, правильность установки программы.\n";
    cout << "Для корректной работы программы необходимо поместить файл "
            "verb+.txt в корневую папку программы.\n\n";
    exit(0);
}

void fileIn(string IrregularVerbs[4][100])
{
    ifstream file("verb+.txt");
    if (!file) {
        fileNotFound();
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

void choiceTestInterface()
{
    cout << "1 - Тест на знание всех глаголов из справочника" << endl;
    cout << "2 - Тест на знание перевода" << endl;
    cout << "3 - Тест на скорость" << endl << endl;
    cout << "0 - Вернуться в главное меню" << endl;
}

void choiceTest(string IrregularVerbs[4][100])
{
    choiceTestInterface();
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        switch (sym[0]) {
        case '1': {
            system("CLS");
            KnownOfEveryTest(IrregularVerbs);
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
    FILE* FileWithRecords;
    struct record {
        char name[50];
        int result;
        char output[20];
    } man;
    man.result = score;
    FileWithRecords = fopen("Table of Records", "ab");
    cout << endl << "Введите ваше имя: ";
    cin >> man.name;

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    strcpy(man.output, " Date:  ");
    strcpy(man.output, asctime(timeinfo));

    fwrite(&man, sizeof(man), 1, FileWithRecords);
    fclose(FileWithRecords);
}

void Table_of_Record_Sort()
{
    FILE* FileWithRecords;
    int quantily = 0, i = 0;
    system("CLS");
    struct record {
        char name[50];
        int result;
        char output[20];
    } man;
    FileWithRecords = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, FileWithRecords)) {
        quantily++;
    }
    struct record people[quantily], temp;
    fclose(FileWithRecords);
    FileWithRecords = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, FileWithRecords)) {
        people[i] = man;
        i++;
    }

    int k, j;
    for (i = 0; i < quantily - 1; i++) {
        k = i;
        for (j = i + 1; j < quantily; j++) {
            if (people[j].result < people[i].result)
                k = j;
        }
        if (people[k].result != people[i].result) {
            temp = people[i];
            people[i] = people[k];
            people[k] = temp;
        }
    }
    fclose(FileWithRecords);
    FileWithRecords = fopen("Table of Records", "wb");
    for (i = 0; i < quantily; i++) {
        if (i < 10)
            fwrite(&people[i], sizeof(people[i]), 1, FileWithRecords);
    }
    fclose(FileWithRecords);
}

void Table_of_Record_Output(string IrregularVerbs[4][100])
{
    FILE* FileWithRecords;
    system("CLS");
    cout << "Результаты:" << endl << endl;
    struct record {
        char name[50];
        int result;
        char output[20];
    } man;
    int NumberVerb = 1;
    Table_of_Record_Sort();
    FileWithRecords = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, FileWithRecords)) {
        cout << NumberVerb << ") " << man.name << " " << man.result << " "
             << man.output << endl;
        NumberVerb++;
    }
    system("pause");
    system("CLS");
    fclose(FileWithRecords);
    mainMenu(IrregularVerbs);
}

void mainMenuInterface()
{
    cout << "1 - Выбор теста" << endl;
    cout << "2 - Результаты" << endl;
    cout << "3 - Показать словарь глаголов" << endl;
    cout << "4 - Помощь" << endl << endl;
    cout << "0 - Выход" << endl;
}

void mainMenu(string IrregularVerbs[4][100])
{
    while (1) {
        mainMenuInterface();
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

void sleep_ms(int milliseconds)
{
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}
