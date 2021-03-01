#include<iostream>
#include<conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

void instructions() {
    system("cls");
    cout << endl << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << " RULES OF THE GAME" << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << " 1. Choose any number between 1 to 5" << endl;
    cout << " 2. If you win you will get 10 times of money you bet" << endl;
    cout << " 3. If you bet on wrong number you will lose your betting totalMoney" << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << "Press any key to start...";
    getch();
}

void play() {
    system("cls");
    instructions();
    system("cls");

    string personName;
    int totalMoney;
    int betMoney;
    int guess;
    int dice;
    char option;

    srand(time(0));

    cout << " -------------------------------------" << endl;
    cout << "|           CASINO GAME             |" << endl;
    cout << " -------------------------------------" << endl << endl;

    cout << "Enter Your Name : ";
    getline(cin, personName);

    cout << endl << endl;
    cout << "Enter Deposit Money to start game : $";
    cin >> totalMoney;

    do {
        system("cls");
        
	    cout << " -------------------------------------" << endl;
	    cout << "|           CASINO GAME             |" << endl;
	    cout << " -------------------------------------" << endl << endl<<endl;
        
		cout << "\nCurrent balance is $ " << totalMoney << endl;

        do {
            cout << personName << ", Please Enter amount to bet : $";
            cin >> betMoney;
            if (betMoney > totalMoney)
                cout << "Betting Amount is more than current balance" << endl << "Re-enter data" << endl;

        } while (betMoney > totalMoney);

        do {
            cout << "Enter Guess number to bet between 1 to 5 :";
            cin >> guess;
            if (guess < 1 || guess > 5)
                cout << "Number should be between 1 to 5" << endl << "Re-enter data " << endl;

        } while (guess < 1 || guess > 5);

        dice = rand() % 5 + 1;

        if (dice != guess) {
            totalMoney -= betMoney;
            cout << endl << endl << "You lost $ " << betMoney << endl;
        } else {
            totalMoney += (betMoney * 10);
            cout << endl << endl << "Congratulations!! You won Rs." << betMoney * 10;
        }

        cout << "\nThe winning number was : " << dice << endl;
        cout << "\n" << personName << ", You have $ " << totalMoney << endl;
        if (totalMoney == 0) {
            cout << "You have no money to play ";
            break;
        }
        cout << endl << endl << " Do you want to play again (y/n)? ";
        cin >> option;
    } while (option == 'Y' || option == 'y');

    cout << " ----------------------------------------------------------------------------" << endl;
    cout << " Thanks for playing. Your Current Money is $ " << totalMoney << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    getch();
}

int main() {
    srand((unsigned) time(NULL));

    do {
        system("cls");
        cout << " -------------------------- " << endl;
        cout << " |    CASINO NO GUESS     | " << endl;
        cout << " --------------------------" << endl << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Quit" << endl;
        cout << "Select option: ";
        char op = getche();

        if (op == '1') play();
        else if (op == '2') instructions();
        else if (op == '3') exit(0);

    } while (1);

    return 0;
}
