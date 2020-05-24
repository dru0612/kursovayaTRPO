#include "source.h"

using namespace std;

void KnowOfEveryTest(string IrregularVerbs[4][100])
{
    int score = 0, correct = 0, current = 0, mistakes = 0;
    int timeNow;
    int timeDelta;
    int timeStart;
    string userVerb[3];
    int i, testStatus = 0;
    while ((score < 100) || (testStatus == 0)) {
        current = rand() % 100;
        cout << "Введите все формы слова " << IrregularVerbs[3][current]
             << endl;
        timeNow = clock();
        timeDelta = clock() - timeNow;
        timeStart = 0;
        for (i = 0; i < 3; i++) {
            cin >> userVerb[i];
            int ResultOfCheck
                    = verbCheck(userVerb[i], IrregularVerbs[i][current]);
            if (ResultOfCheck == 2) {
                system("cls");
                testStatus = 1;
                cout << "Общее время прохождения: " << timeStart / 1000
                     << "секунд";
                cout << endl
                     << "Тестирование завершено. Ваш счет: " << score << endl;
                cout << "Нажмите Y ,если хотите добавить результат в таблицу."
                     << endl;
                cout << "Нажмите любую другую клавишу для выхода в главное "
                        "меню."
                     << endl;
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                system("CLS");
                mainMenu(IrregularVerbs);
            } else if (ResultOfCheck == 1) {
                correct++;
            }
        }
        if (testCheck(correct) == 1) {
            score += 15;
            cout << "Правильно! Продолжайте в том же духе";
        } else {
            cout << "Ошибка! Правильный ответ: ";
            for (i = 0; i < 3; i++) {
                cout << IrregularVerbs[i][current] << " ";
            }
            mistakes++;
            if (score >= 5)
                score -= 5;
        }
        correct = 0;
        if (score >= 100)
            break;
        cout << endl;

        timeDelta = clock() - timeNow;
        timeNow = clock();
        timeStart += timeDelta;
        cout << "Время, потраченное на глагол: " << timeDelta / 1000
             << " секунд" << endl;
        cout << "Ваш счет: " << score
             << "\t Количетсво допущенных ошибок: " << mistakes << endl
             << endl;
    }

    system("CLS");
    cout << "Общее время прохождения: " << timeStart / 1000 << " секунд";
    cout << endl << "Тестирвоание завершено. Ваш счет: " << score << endl;
    cout << "Нажмите Y ,если хотите добавить результат в таблицу." << endl;
    cout << "Нажмите любую другую клавишу для выхода в главное меню." << endl;
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    system("CLS");
    mainMenu(IrregularVerbs);
}

void TestToTime(string IrregularVerbs[4][100])
{
    long timeLimit = 60000, timeStart = clock(), timeNow = clock();
    int score = 0, correct = 0, current, i;
    string userVerb[3];
    cout << "У вас есть " << timeLimit / 1000
         << " секунд чтобы пройти тест, удачи!." << endl
         << endl;
    while (timeNow - timeStart < timeLimit) {
        current = rand() % 100;
        cout << "Введите все формы слова " << IrregularVerbs[3][current]
             << endl;
        for (i = 0; i < 3; i++) {
            cin >> userVerb[i];
            int ResultOfCheck
                    = verbCheck(userVerb[i], IrregularVerbs[i][current]);
            if (ResultOfCheck == 2) {
                system("CLS");
                cout << "Тестирвоание завершено. Ваш счет: " << score << endl;
                cout << "Нажмите Y ,если хотите добавить результат в таблицу."
                     << endl;
                cout << "Нажмите любую другую клавишу для выхода в главное "
                        "меню."
                     << endl;
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                system("CLS");
                mainMenu(IrregularVerbs);
                break;
            }
            if (ResultOfCheck == 1) {
                correct++;
            }
        }
        bool ResultOfCheck = testCheck(correct);
        if (ResultOfCheck == true) {
            score += 20;
        }
        correct = 0;
        timeNow = clock();
        if ((timeLimit - (timeNow - timeStart)) / 1000 > 0)
            cout << "У вас осталось "
                 << (timeLimit - (timeNow - timeStart)) / 1000 << " секунд"
                 << endl;
        else
            break;
    }
    system("CLS");
    cout << "Тестирвоание завершено. Ваш счет: " << score << endl;
    cout << "Нажмите Y ,если хотите добавить результат в таблицу." << endl;
    cout << "Нажмите любую другую клавишу для выхода в главное меню." << endl;
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    system("CLS");
    mainMenu(IrregularVerbs);
}

void TestRussian(string IrregularVerbs[4][100])
{
    int score = 0, RandomVerbTrue, mistakes = 0;
    int timeNow = clock();
    int timeDelta = clock() - timeNow;
    int timeAll = 0, VerbsChoice, VerbForm, j, i;
    string ResponseOption[4];
    while (1) {
        RandomVerbTrue = rand() % 100;
        VerbForm = rand() % 3;
        j = rand() % 4;
        ResponseOption[j] = IrregularVerbs[3][RandomVerbTrue];
        cout << "Выберите перевод слова: "
             << IrregularVerbs[VerbForm][RandomVerbTrue] << " (это "
             << VerbForm + 1 << " форма глагола)" << endl;
        for (i = 0; i < 4; i++) {
            int RandomVerbFalse = rand() % 100;
            while (RandomVerbFalse == RandomVerbTrue) {
                RandomVerbFalse = rand() % 100;
            }

            if (i != j) {
                ResponseOption[i] = IrregularVerbs[3][RandomVerbFalse];
            }
        }
        for (i = 0; i < 4; i++) {
            cout << i + 1 << " - " << ResponseOption[i] << endl;
        }
        cout << endl << "0 - Закончить тест" << endl;
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
                system("CLS");
                cout << "Тестированеи завершено. Ваш счет: " << score << endl;
                cout << "Нажмите Y ,если хотите добавить результат в таблицу."
                     << endl;
                cout << "Нажмите любую другую клавишу для выхода в главное "
                        "меню."
                     << endl;
                char sym[50];
                cin >> sym;
                if (strlen(sym) == 1)
                    if (yesCheck(sym[0]))
                        Table_of_Record_Input(score);
                system("CLS");
                mainMenu(IrregularVerbs);
            }
            default: {
                cout << endl << "Некорректно! Повторите пожалуйста" << endl;
                sleep_ms(2000);
                InvalidInput = 1;
            }
            }
        }
        int ResultOfCheck = verbCheck(
                ResponseOption[VerbsChoice], IrregularVerbs[3][RandomVerbTrue]);
        if (ResultOfCheck) {
            cout << "Правильно!" << endl;
            score += 10;
        } else {
            cout << "Ошибка!" << endl;
            mistakes++;
            if (score >= 5)
                score -= 5;
        }
        timeDelta = clock() - timeNow;
        timeNow = clock();
        timeAll += timeDelta;
        cout << "Время, потраченное на глагол: " << timeDelta / 1000
             << " секунд" << endl;
        cout << "Ваш счет: " << score
             << "\t Количество допущенных ошибок: " << mistakes << endl
             << endl;
        sleep_ms(2000);
        system("CLS");
    }
    cout << "Тестирование завершено";
}
