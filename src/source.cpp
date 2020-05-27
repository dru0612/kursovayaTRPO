#include "source.h"

using namespace std;

int testCheck(int correct)
{
    bool checkStatus = 0;
    if (correct == 3) {
        checkStatus = 1;
    }
    return checkStatus;
}

int yesCheck(char sym)
{
    bool checkStatus = 0;
    if ((sym == 'Y') || (sym == 'y')) {
        checkStatus = 1;
    }
    return checkStatus;
}

int verbCheck(string user, string verb)
{
    int checkStatus = 0;
    string exitCommand = "exit";
    if (user == exitCommand) {
        checkStatus = 2;
    } else if (user == verb) {
        checkStatus = 1;
    } else
        checkStatus = 0;
    return checkStatus;
}

void fileIn(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    ifstream file("verb+.txt");
    if (!file) {
        fileNotFound();
    }
    for (int i = 0; i < LotOfIrregularVerbs; i++) {
        for (int j = 0; j < LotOfForms; j++) {
            file >> IrregularVerbs[j][i];
        }
    }
}

void fileOut(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    for (int i = 0; i < LotOfIrregularVerbs; i++) {
        cout << i + 1 << ") ";
        cout.width(10);
        cout << IrregularVerbs[0][i];
        cout.width(20);
        cout << IrregularVerbs[1][i];
        cout.width(20);
        cout << IrregularVerbs[2][i];
        cout.width(20);
        cout << IrregularVerbs[3][i] << "\n";
    }
}

void dictionary(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    fileOut(IrregularVerbs);
    cout << "\nНажмите любую кнопку, чтобы продолжить.\n";
    mainMenu(IrregularVerbs);
}

void choiceTest(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    choiceTestInterface();
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        switch (sym[0]) {
        case '1': {
            KnownOfEveryTest(IrregularVerbs);
            break;
        }
        case '2': {
            TestRussian(IrregularVerbs);
            break;
        }
        case '3': {
            TestToTime(IrregularVerbs);
            break;
        }
        case '0': {
            mainMenu(IrregularVerbs);
            break;
        }
        default: {
            IncorrectInput();
            choiceTest(IrregularVerbs);
        }
        }
    else {
        IncorrectInput();
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
    cout << "\nВведите ваше имя: ";
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
    int quantily = 0, i = 0, limitOfRecords = 10;
    struct record {
        char name[50];
        int result;
        char output[20];
    } man;
    FileWithRecords = fopen("Table of Records", "rb");
    while (fread(&man, sizeof(man), 1, FileWithRecords)) {
        quantily++;
    }
    struct record people[quantily], moving;
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
            if (people[j].result > people[i].result)
                k = j;
        }
        if (people[k].result != people[i].result) {
            moving = people[i];
            people[i] = people[k];
            people[k] = moving;
        }
    }
    fclose(FileWithRecords);
    FileWithRecords = fopen("Table of Records", "wb");
    for (i = 0; i < quantily; i++) {
        if (i < limitOfRecords)
            fwrite(&people[i], sizeof(people[i]), 1, FileWithRecords);
    }
    fclose(FileWithRecords);
}

void Table_of_Record_Output(
        string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    FILE* FileWithRecords;
    cout << "Результаты:\n\n";
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
             << man.output << "\n";
        NumberVerb++;
    }
    fclose(FileWithRecords);
    mainMenu(IrregularVerbs);
}

void mainMenu(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    while (1) {
        mainMenuInterface();
        char sym[50];
        cin >> sym;
        if (strlen(sym) == 1)
            switch (sym[0]) {
            case '1': {
                choiceTest(IrregularVerbs);
                break;
            }
            case '2': {
                Table_of_Record_Output(IrregularVerbs);
                break;
            }
            case '3': {
                dictionary(IrregularVerbs);
                break;
            }
            case '4': {
                support(IrregularVerbs);
                break;
            }
            case '0': {
                exit(0);
            }
            default: {
                IncorrectInput();
            }
            }
        else {
            IncorrectInput();
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
