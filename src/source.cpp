#include "source.h"

using namespace std;

void hello()
{
    cout << "Hello, dear user! You have problems with "
            "English and want to learn irregular verbs?"
         << endl;
    cout << "Welcome to the A. A. A. team!" << endl;
    cout << "We, Ageev Anatoly, Tverdokhleb Anton and tsikunov Andrey, "
            "students "
            "Sibguti group IP-913."
         << endl;
    cout << "We have volunteered to help you brighten up your evening studying "
            "English "
            "language!"
         << endl;
    cout << endl
         << "This program is designed to hone your knowledge "
            "irregular verb."
         << endl;
    cout << endl
         << "We wish you good luck in learning verbs! Click any button to "
            "resume."
         << endl
         << endl;
    _getch();
    system("CLS");
}

void support()
{
    cout << "1) Enter words in lowercase." << endl;
    cout << "2) You must use only Latin letters to enter words "
            "alphabet's."
         << endl;
    cout << "3) If you encounter a verb that contains one of the following "
            "forms "
            "multiple word options"
         << endl;
    cout << "they must be separated by commas without spaces. These words "
            "will be marked (*)"
         << endl;
    cout << "\t Example: the verb to Be. Its 2 form is was/were. In response "
            "you must write - be was, were been - "
         << endl;
    cout << "To pass this test, you need to score 10 points" << endl;
    cout << endl
         << "We wish you good luck in learning verbs! Click any button to "
            "resume."
         << endl
         << endl;
    _getch();
    system("CLS");
}

void KoE(string v[4][n])
{
    int score = 0, sc = 0, k, Oshibki = 0;
    int t = clock();
    int timer = clock() - t;
    int timeAll = 0;
    string vUser[3];
    for (int i = 0; score < 10; i++) {
        k = rand() % n;
        cout << "Введите все формы слова " << v[3][k] << " (" << v[0][k] << ") "
             << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            if (vUser[i] == "exit") {
                system("cls");
                t = 0;
                timer = 0;
                timeAll = 0;
                mainMenu(v);
                break;
            }
        }
        for (i = 0; i < 3; i++) {
            if (v[i][k] == vUser[i]) {
                sc++;
            }
        }
        if (sc == 3) {
            cout << "Верно! Продолжайте в том же духе!";
            score++;
            sc = 0;
        }

        else {
            cout << "Ошибка! Правильный ответ: ";
            sc = 0;
            for (i = 0; i < 3; i++) {
                cout << v[i][k] << " ";
            }
            Oshibki++;
        }
        cout << endl;

        timer = clock() - t;
        t = clock();
        timeAll += timer;
        cout << "Время, которое ушло на этот глагол: " << timer / 1000
             << " секунд" << endl;
        cout << "Ваш счёт: " << score
             << "\t Количество допущенных ошибок: " << Oshibki << endl
             << endl;
    }

    cout << endl
         << "Общее время выполнения задания: " << timeAll / 1000 << " секунд";
    //  ToRIn()
}
