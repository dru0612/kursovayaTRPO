#include "source.h"

using namespace std;

void KnownOfEveryTest(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    int score = 0, correct = 0, current = 0, mistakes = 0;
    int RusFormIndex = 3;
    int timeNow, timeDelta, timeStart;
    string userVerb[3];
    int i, testStatus = 0, ResultOfCheck, LotOfEngForms = 3;
    int scorePlus = 15, scoreMinus = 5, scoreLimit = 100;

    while ((score < scoreLimit) || (testStatus == 0)) {
        current = rand() % LotOfIrregularVerbs;
        cout << "Введите все формы слова "
             << IrregularVerbs[RusFormIndex][current] << "\n";
        timeNow = clock();
        timeDelta = clock() - timeNow;
        timeStart = 0;
        for (i = 0; i < LotOfEngForms; i++) {
            cin >> userVerb[i];
            ResultOfCheck = verbCheck(userVerb[i], IrregularVerbs[i][current]);
            if (ResultOfCheck == 2) {
                testStatus = 1;
                timeDelta = clock() - timeNow;
                timeNow = clock();
                timeStart += timeDelta;
                testBeEnded(timeStart, score);
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                mainMenu(IrregularVerbs);
            } else if (ResultOfCheck == 1) {
                correct++;
            }
        }
        ResultOfCheck = testCheck(correct);
        if (ResultOfCheck == 1) {
            cout << "Правильно! Продолжайте в том же духе";
        } else {
            cout << "Ошибка! Правильный ответ: ";
            for (i = 0; i < LotOfEngForms; i++) {
                cout << IrregularVerbs[i][current] << " ";
            }
            mistakes++;
        }
        score = ScoreBalance(score, scorePlus, scoreMinus, ResultOfCheck);
        correct = 0;
        if (score >= scoreLimit)
            break;
        cout << "\n";

        timeDelta = clock() - timeNow;
        timeNow = clock();
        timeStart += timeDelta;
        Subtotal(timeDelta, score, mistakes);
    }

    testBeEnded(timeStart, score);
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    mainMenu(IrregularVerbs);
}

void TestToTime(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    long timeLimit = 60000, timeStart = clock(), timeNow = clock();
    int score = 0, correct = 0, current, i;
    int scorePlus = 20, scoreMinus = 0;
    int LotOfEngForms = 3, RusFormIndex = 3;
    string userVerb[LotOfEngForms];
    cout << "У вас есть " << timeLimit / 1000
         << " секунд чтобы пройти тест, удачи!.\n\n";
    while (timeNow - timeStart < timeLimit) {
        current = rand() % LotOfIrregularVerbs;
        cout << "Введите все формы слова "
             << IrregularVerbs[RusFormIndex][current] << "\n";
        for (i = 0; i < LotOfEngForms; i++) {
            cin >> userVerb[i];
            int ResultOfCheck
                    = verbCheck(userVerb[i], IrregularVerbs[i][current]);
            if (ResultOfCheck == 2) {
                timeNow = clock();
                testBeEnded(timeStart - timeNow, score);
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                mainMenu(IrregularVerbs);
                break;
            }
            if (ResultOfCheck == 1) {
                correct++;
            }
        }
        bool ResultOfCheck = testCheck(correct);
        score = ScoreBalance(score, scorePlus, scoreMinus, ResultOfCheck);
        correct = 0;
        timeNow = clock();
        if ((timeLimit - (timeNow - timeStart)) / 1000 > 0)
            cout << "У вас осталось "
                 << (timeLimit - (timeNow - timeStart)) / 1000 << " секунд\n";
        else
            break;
    }
    testBeEnded(timeLimit, score);
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    mainMenu(IrregularVerbs);
}

void TestRussian(string IrregularVerbs[LotOfForms][LotOfIrregularVerbs])
{
    int score = 0, RandomVerbTrue, mistakes = 0, LotOfAnswers = 4;
    int timeNow = clock(), timeDelta = clock() - timeNow;
    int timeAll = 0, VerbsChoice, VerbForm, TrueAnswer, i;
    int scorePlus = 10, scoreMinus = 5, scoreLimit = 100;
    int LotOfEngForms = 3, RusFormIndex = 3;
    string ResponseOption[LotOfAnswers];
    while (score < scoreLimit) {
        RandomVerbTrue = rand() % LotOfIrregularVerbs;
        VerbForm = rand() % LotOfEngForms;
        TrueAnswer = rand() % LotOfAnswers;
        ResponseOption[TrueAnswer]
                = IrregularVerbs[RusFormIndex][RandomVerbTrue];
        cout << "Выберите перевод слова: "
             << IrregularVerbs[VerbForm][RandomVerbTrue] << " (это "
             << VerbForm + 1 << " форма глагола)\n";
        for (i = 0; i < LotOfAnswers; i++) {
            int RandomVerbFalse = rand() % LotOfIrregularVerbs;
            for (int count = 0; count < i; count++)
                while ((ResponseOption[count]
                        == IrregularVerbs[RusFormIndex][RandomVerbFalse])
                       || (RandomVerbFalse == RandomVerbTrue)) {
                    RandomVerbFalse = rand() % LotOfIrregularVerbs;
                    count = 0;
                }
            if (i != TrueAnswer) {
                ResponseOption[i]
                        = IrregularVerbs[RusFormIndex][RandomVerbFalse];
            }
        }
        for (i = 0; i < LotOfAnswers; i++) {
            cout << i + 1 << " - " << ResponseOption[i] << "\n";
        }
        cout << "\n0 - Закончить тест\n";
        int InvalidInput = 1;
        while (InvalidInput == 1) {
            char EnterSymbols;
            cin >> EnterSymbols;
            switch (EnterSymbols) {
            case '1': {
                VerbsChoice = 0;
                InvalidInput = 0;
                break;
            }
            case '2': {
                VerbsChoice = 1;
                InvalidInput = 0;
                break;
            }
            case '3': {
                VerbsChoice = 2;
                InvalidInput = 0;
                break;
            }
            case '4': {
                VerbsChoice = 3;
                InvalidInput = 0;
                break;
            }
            case '0': {
                InvalidInput = 0;
                timeDelta = clock() - timeNow;
                timeNow = clock();
                timeAll += timeDelta;
                testBeEnded(timeAll, score);
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                mainMenu(IrregularVerbs);
            }
            default: {
                IncorrectInput();
                InvalidInput = 1;
            }
            }
        }
        int ResultOfCheck = verbCheck(
                ResponseOption[VerbsChoice], IrregularVerbs[3][RandomVerbTrue]);
        if (ResultOfCheck) {
            cout << "Правильно!\n";
        } else {
            cout << "Ошибка!\n";
            mistakes++;
        }
        score = ScoreBalance(score, scorePlus, scoreMinus, ResultOfCheck);
        timeDelta = clock() - timeNow;
        timeNow = clock();
        timeAll += timeDelta;
        Subtotal(timeDelta, score, mistakes);
    }

    testBeEnded(timeAll, score);
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    mainMenu(IrregularVerbs);
}

int ScoreBalance(int score, int scorePlus, int scoreMinus, bool correct)
{
    if (correct == true) {
        score += scorePlus;
    } else {
        if (score >= scoreMinus)
            score -= scoreMinus;
    }
    return score;
}
