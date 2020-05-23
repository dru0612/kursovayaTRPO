#include "source.h"

using namespace std;

void KoE(string v[4][100])
{
    int score = 0, sc = 0, k, mistakes = 0;
    int t = clock();
    int timer = clock() - t;
    int timeAll = 0;
    string vUser[3];
    int i, testStatus = 0;
    while ((score < 100) || (testStatus == 0)) {
        k = rand() % 100;
        cout << "Введите все формы слова " << v[3][k] << " (" << v[0][k] << ") "
             << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            int q = verbCheck(vUser[i], v[i][k]);
            if (q == 2) {
                system("cls");
                testStatus = 1;
                cout << "Общее время прохождения: " << timeAll / 1000
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
                mainMenu(v);
            } else if (q == 1) {
                sc++;
            }
        }
        if (testCheck(sc)) {
            score += 15;
            cout << "Правильно! Продолжайте в том же духе";
        } else {
            cout << "Ошибка! Правильный ответ: ";
            for (i = 0; i < 3; i++) {
                cout << v[i][k] << " ";
            }
            mistakes++;
            if (score >= 5)
                score -= 5;
        }
        sc = 0;
        if (score >= 100)
            break;
        cout << endl;

        timer = clock() - t;
        t = clock();
        timeAll += timer;
        cout << "Время, потраченное на глагол: " << timer / 1000 << " секунд"
             << endl;
        cout << "Ваш счет: " << score
             << "\t Количетсво допущенных ошибок: " << mistakes << endl
             << endl;
    }

    system("CLS");
    cout << "Общее время прохождения: " << timeAll / 1000 << " секунд";
    cout << endl << "Тестирвоание завершено. Ваш счет: " << score << endl;
    cout << "Нажмите Y ,если хотите добавить результат в таблицу." << endl;
    cout << "Нажмите любую другую клавишу для выхода в главное меню." << endl;
    char sym[50];
    cin >> sym;
    if (strlen(sym) == 1)
        if (yesCheck(sym[0]))
            Table_of_Record_Input(score);
    system("CLS");
    mainMenu(v);
}

void TestToTime(string v[4][100])
{
    long timeLimit = 60000, timeStart = clock(), timeNow = clock();
    int score = 0, sc = 0, k, i;
    string vUser[3];
    cout << "У вас есть " << timeLimit / 1000
         << " секунд чтобы пройти тест, удачи!." << endl
         << endl;
    while (timeNow - timeStart < timeLimit) {
        k = rand() % 100;
        cout << "Введите все формы слова " << v[3][k] << " (" << v[0][k] << ") "
             << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            int q = verbCheck(vUser[i], v[i][k]);
            if (q == 2) {
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
                mainMenu(v);
                break;
            }
            if (q == 1) {
                sc++;
            }
        }
        bool t = testCheck(sc);
        if (t == true) {
            score += 20;
        }
        sc = 0;
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
    mainMenu(v);
}

void TestRussian(string v[4][100])
{
    int score = 0, k, mistakes = 0;
    int ti = clock();
    int timer = clock() - ti;
    int timeAll = 0, u, f, j, i;
    string t[4];
    while (1) {
        k = rand() % 100;
        f = rand() % 3;
        j = rand() % 4;
        t[j] = v[3][k];
        cout << "Выберите перевод слова: " << v[f][k] << " (это " << f + 1
             << " форма глагола)" << endl;
        for (i = 0; i < 4; i++) {
            int q = rand() % 100;
            while (q == k) {
                q = rand() % 100;
            }

            if (i != j) {
                t[i] = v[3][q];
            }
        }
        for (i = 0; i < 4; i++) {
            cout << i + 1 << " - " << t[i] << endl;
        }
        cout << endl << "0 - Закончить тест" << endl;
        int flag = 1;
        while (flag == 1) {
            char a;
            cin >> a;
            switch (a) {
            case '1': {
                u = 0;
                flag = 0;
                break;
            }
            case '2': {
                u = 1;
                flag = 0;
                break;
            }
            case '3': {
                u = 2;
                flag = 0;
                break;
            }
            case '4': {
                u = 3;
                flag = 0;
                break;
            }
            case '0': {
                flag = 0;
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
                mainMenu(v);
            }
            default: {
                cout << endl << "Некорректно! Повторите пожалуйста" << endl;
                sleep_ms(2000);
                flag = 1;
            }
            }
        }
        int q = verbCheck(t[u], v[3][k]);
        if (q) {
            cout << "Правильно!" << endl;
            score += 10;
        } else {
            cout << "Ошибка!" << endl;
            mistakes++;
            if (score >= 5)
                score -= 5;
        }
        timer = clock() - ti;
        ti = clock();
        timeAll += timer;
        cout << "Время, потраченное на на глагол: " << timer / 1000 << " секунд"
             << endl;
        cout << "Ваш счет: " << score
             << "\t Количество допущенных ошибок: " << mistakes << endl
             << endl;
        sleep_ms(2000);
        system("CLS");
    }
    cout << "Тестирвоание завершено";
}
