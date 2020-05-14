#include "source.h"

using namespace std;

void hello()
{
    cout << "Здравствуй, дорогой пользователь! У вас проблемы с "
            "английским и хотите выучить неправильные глаголы?"
         << endl;
    cout << "Добро пожаловать в команду A. A. A.!" << endl;
    cout << "Мы, Агеев Анатолий, Твердохлеб Антон и Цикунов Андрей, "
            "студенты "
            "СИБГУТИ группа ИП-913."
         << endl;
    cout << "Мы вызвались помочь вам скрасить вечерние занятия английским"
            "языком!"
         << endl;
    cout << endl
         << "Эта программа предназначена для оттачивания ваших знаний "
            "неправильных глаголов."
         << endl;
    cout << endl
         << "Желаем вам удачи в изучении глаголов! Нажмите любую кнопку, чтобы "
            "продолжить."
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
    cout << endl;
    cout << "Test for knowledge of all forms goes until you score 100 points"
         << endl;
    cout << "15 points are given for the correct answer, and 5 points are "
            "taken for the wrong answer"
         << endl
         << endl;
    cout << "In the test for time, the task is to score the maximum number of "
            "points in 60 seconds, the user must enter 3 forms of the word."
         << endl;
    cout << "For the correct answer is given 20 points." << endl;
    cout << endl;
    cout << "In the translation knowledge test, 4 translations are proposed, "
            "one of which is correct."
         << endl;
    cout << "For the right choise +10 points, for the wrong - 5 points" << endl;
    cout << endl
         << "We wish you good luck in learning verbs! Click any button to "
            "resume."
         << endl
         << endl;
    system("pause");
    system("CLS");
    mainMenu(v);
}
