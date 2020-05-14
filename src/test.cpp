#include "source.h"

using namespace std;

void KoE(string v[4][n])
{
    int score = 0, sc = 0, k, Oshibki = 0;
    int t = clock();
    int timer = clock() - t;
    int timeAll = 0;
    string vUser[3];
    int i, testStatus = 0;
    while ((score < 100) || (testStatus == 0)) {
        k = rand() % n;
        cout << "Введите все формы слова " << v[3][k] << " (" << v[0][k] << ") "
             << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            int q = verbCheck(vUser[i], v[i][k]);
            if (q == 2) {
                system("cls");
                testStatus = 1;
                cout << endl
                     << "Общее время прохождения: " << timeAll / 1000
                     << "секунд";
                cout << endl
                     << "Тестирование завершено. Ваш счет: " << score << endl;
                cout << "Хотите добавить результат в таблицу? Нажмите y ";
                char ch;
                cin >> ch;
                if ((ch == 'Y') || (ch == 'y')) {
                    ToRIn(score);
                }
                system("CLS");
                mainMenu(v);
            } else if (q == 1) {
                sc++;
            }
        }
        bool t = testCheck(sc);
        if (t == true) {
            score += 15;
            cout << "Правильно! Продолжайте в том же духе";
        } else {
            cout << "Ошибка! Правильный ответ: ";
            for (i = 0; i < 3; i++) {
                cout << v[i][k] << " ";
            }
            Oshibki++;
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
             << "\t Количетсво допущенных ошибок: " << Oshibki << endl
             << endl;
    }

    system("CLS");
    cout << "Total task completion time: " << timeAll / 1000 << " second";
    cout << endl << "Testing is finish. Your account: " << score << endl;
    cout << "Want to add your result to the table? Press y ";
    char ch;
    cin >> ch;
    if ((ch == 'Y') || (ch == 'y')) {
        ToRIn(score);
    }
    system("CLS");
    mainMenu(v);
}

void TestToTime(string v[4][n])
{
    long timeLimit = 60000, timeStart = clock(), timeNow = clock();
    int score = 0, sc = 0, k, i;
    string vUser[3];
    cout << "You have " << timeLimit / 1000
         << " seconds to pass the test, good luck!." << endl
         << endl;
    while (timeNow - timeStart < timeLimit) {
        k = rand() % n;
        cout << "Enter all forms of the word " << v[3][k] << " (" << v[0][k]
             << ") " << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            int q = verbCheck(vUser[i], v[i][k]);
            if (q == 2) {
                system("CLS");
                cout << "Testing is finish. Your account: " << score << endl;
                cout << "Want to add your result to the table? Press y ";
                char ch;
                cin >> ch;
                if ((ch == 'Y') || (ch == 'y')) {
                    ToRIn(score);
                }
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
            cout << "You have left "
                 << (timeLimit - (timeNow - timeStart)) / 1000 << " seconds"
                 << endl;
        else
            break;
    }
    system("CLS");
    cout << "Testing is finish. Your account: " << score << endl;
    cout << "Want to add your result to the table? Press y ";
    char ch;
    cin >> ch;
    if ((ch == 'Y') || (ch == 'y')) {
        ToRIn(score);
    }
    system("CLS");
    mainMenu(v);
}

void TestRussian(string v[4][n])
{
    int score = 0, k, Oshibki = 0;
    int ti = clock();
    int timer = clock() - ti;
    int timeAll = 0, u, f, j, i;
    string t[4];
    while (1) {
        k = rand() % n;
        f = rand() % 3;
        j = rand() % 4;
        t[j] = v[3][k];
        cout << "Select a word translation: " << v[f][k] << " (this is "
             << f + 1 << " form of the verb)" << endl;
        for (i = 0; i < 4; i++) {
            int q = rand() % n;
            while (q == k) {
                q = rand() % n;
            }

            if (i != j) {
                t[i] = v[3][q];
            }
        }
        for (i = 0; i < 4; i++) {
            cout << i + 1 << " - " << t[i] << endl;
        }
        cout << endl << "0 - Finish testing" << endl;
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
                cout << "Testing is finish. Your account: " << score << endl;
                cout << "Want to add your result to the table? Press y ";
                char ch;
                cin >> ch;
                if ((ch == 'Y') || (ch == 'y')) {
                    ToRIn(score);
                }
                system("CLS");
                mainMenu(v);
            }
            default: {
                cout << endl << "Incorrect! Repeat please" << endl;
                for (int i = 0; i < 90000000; i++)
                    ;
                flag = 1;
            }
            }
        }
        int q = verbCheck(t[u], v[3][k]);
        if (q) {
            cout << "Success!" << endl;
            score += 10;
        } else {
            cout << "Error!" << endl;
            Oshibki++;
            if (score >= 5)
                score -= 5;
        }
        timer = clock() - ti;
        ti = clock();
        timeAll += timer;
        cout << "Time spent on this verb: " << timer / 1000 << " second"
             << endl;
        cout << "Your account: " << score
             << "\t Number of errors made: " << Oshibki << endl
             << endl;
        for (i = 0; i < 10000000; i++)
            ;
        system("CLS");
    }
    cout << "Test is over";
}
