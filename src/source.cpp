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
    system("pause");
    system("CLS");
}

void support(string v[4][n])
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
    cout << "Test for knowledge of all forms goes until you score 100 points" << endl;
    cout << "15 points are given for the correct answer, and 5 points are taken for the wrong answer"<<endl;
    cout << endl
         << "We wish you good luck in learning verbs! Click any button to "
            "resume."
         << endl
         << endl;
    system("pause");
    system("CLS");
    mainMenu(v);
}

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
        cout << "Enter all forms of the word " << v[3][k] << " (" << v[0][k]
             << ") " << endl;
        for (i = 0; i < 3; i++) {
            cin >> vUser[i];
            int q = verbCheck(vUser[i], v[i][k]);
            if (q == 2) {
                system("cls");
                testStatus = 1;
                cout << endl
                     << "Total task completion time: " << timeAll / 1000
                     << " second";
                cout << endl
                     << "Testing is finish. Your account: " << score << endl;
                cout << "Want to add your result to the table? Press y ";
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
            cout << "Right! Keep up the good work";
        } else {
            cout << "Error! Correct answer: ";
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
        cout << "Time spent on this verb: " << timer / 1000 << " second"
             << endl;
        cout << "Your account: " << score
             << "\t Number of errors made: " << Oshibki << endl
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

void fileIn(string v[4][n])
{
    ifstream file("verb+.txt");
    if (!file) {
        cout << "There was an error opening the file.\n";
        cout << "The program may not be installed correctly\n";
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
    cout << endl << "Click any button to resume." << endl;
    system("pause");
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
