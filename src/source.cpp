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
        cout << "Enter all forms of the word " << v[3][k] << " (" << v[0][k]
             << ") " << endl;
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
            cout << "Right! Keep up the good wor";
            score++;
            sc = 0;
        }

        else {
            cout << "Error! Correct answer: ";
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
        cout << "Time spent on this verb: " << timer / 1000 << " second"
             << endl;
        cout << "Your account: " << score
             << "\t Number of errors made: " << Oshibki << endl
             << endl;
    }

    cout << endl
         << "Total task completion time: " << timeAll / 1000 << " second";
    //  ToRIn()
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

void dictionary(string v[4][n]) {
	fileOut(v);
	cout<<endl<<"Click any button to resume."<<endl;
    _getch();
    system("CLS");
}

void TestRussian(string v[4][n]) {
	int score=0,sc=0,k,Oshibki=0;
    int ti=clock();
    int timer=clock()-ti;
    int timeAll=0,u,f,j,i;
	string t[4];
    while(1) {
    	k=rand()%n;
    	f=rand()%3;
    	j=rand()%4;
    	t[j]=v[3][k];
    	cout<<"Select a word translation: "<<v[f][k]<<" (this is "<< f+1 <<" formof the verb)"<<endl;
    	for (i=0;i<4;i++){
    		int q = rand() % n;
    		while (q == k) {
    			q = rand() % n;
			}

    		if (i!=j) {
    			t[i]=v[3][q];
			}

		}
		for (i=0;i<4;i++){
    		cout<<i+1<<" - "<<t[i]<<endl;
		}
		int flag=1;
		while(flag==1){

			char a=_getch();
			switch(a){
				case '1': {
					u=0;
					flag=0;
					break;
				}
				case '2':{
					u=1;
					flag=0;
					break;
				}
				case '3':{
					u=2;
					flag=0;
					break;
				}
				case '4':{
					u=3;
					flag=0;
					break;
				}
				default: {
					cout<<endl<<"Incorrect! Repeat please"<<endl;
					Sleep(1000);
					flag = 1;
				}
			}
		}
    	if(t[u]==v[3][k]) {
			cout<<"Success!"<<endl;
			score+=10;
		}
		else{
			cout<<"Error!"<<endl;
			Oshibki++;
		}
        timer=clock()-ti;
        ti=clock();
        timeAll+=timer;
        cout << "Time spent on this verb: " << timer / 1000 << " second"
             << endl;
        cout << "Your account: " << score
             << "\t Number of errors made: " << Oshibki << endl
             << endl;
        Sleep(2000);
        system("CLS");
	}
	cout<<"Test is over";
}
