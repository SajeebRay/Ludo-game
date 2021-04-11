#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void exitCon(string str); //checking exit
int generate();
int playerSelection();
void gameBoard(int player);
void friendsMode();
void computerMode();
void funDoubleSix();
void turnCom();
void result(int n);
int main()
{
    int player = playerSelection();
    cout << "*** DON'T PRESS (-1) ***"<< endl;
    cout << "****************LET'S PLAY*****************"<< endl;
    gameBoard(player);

    return 0;
}
void gameBoard(int player)
{
    if (player == 2 || player == 3 || player == 4)
        player = 2;
    switch(player)
    {
    case 1:
        {
            computerMode();
            break;
        }
    case 2:
        {
            friendsMode();
            break;
        }
    }
}
int generate()
{
    srand(time(NULL));
    int num = rand();
    num = num % 7;
    return num;
}
void friendsMode()
{
    int doubleSix = 0;
    string str;
reCall:
    cout << "Pres any key: ";
    cin >> str;
    exitCon(str); //checking exit
    int num = generate();
    if (num == 6)
    {
        cout <<  " -|---|-" << endl;
        cout <<  " -| 6 |-" << endl;
        cout <<  " -|---|-" << endl;
        cout << "Congrats! Again ";
        doubleSix++;
        if (doubleSix == 6)
        {
            doubleSix = 0;
            funDoubleSix();
            goto reCall;
        }
        else
            goto reCall;
    }
    else
    {
        result(num); // update with switch
        cout << "Turn Next! ";
        goto reCall;
    }

}
void funDoubleSix()
{
    int dhoka, dhoka2;
    static int tripleSix = 0;
    cout << "Pres any key: ";
    cin >> dhoka;
    cout <<  " -|---|-" << endl;
    cout <<  " -| 6 |-" << endl;
    cout <<  " -|---|-" << endl;
    cout << "Congrats! Again ";
    tripleSix++;
    if (tripleSix == 3)
    {
        tripleSix = 0;
        cout << "Pres any key: ";
        cin >> dhoka2;
        cout <<  " -|---|-" << endl;
        cout <<  " -| 6 |-" << endl;
        cout <<  " -|---|-" << endl;
        cout << "Oh no! Waste your turn!" << endl;

        cout << "Turn Next! ";
    }
}
void computerMode()
{
    int doubleSix = 0;
    string str;
reCall:
    cout << "Press any key to permit computer turn: ";
    string s;
    cin >> s;
    turnCom();
    cout << "Pres any key: ";
    cin >> str;
    exitCon(str); //checking exit
    int num = generate();
    if (num == 6)
    {
        cout <<  " -|---|-" << endl;
        cout <<  " -| 6 |-" << endl;
        cout <<  " -|---|-" << endl;
        doubleSix++;
        if (doubleSix == 6)
        {
            doubleSix = 0;
            funDoubleSix();
            goto reCall;
        }
        else
            goto reCall;
    }
    else
    {
        result(num); // update with switch
        cout << "Turn Next! ";
        goto reCall;
    }
}
int playerSelection()
{
    cout << "\t\t\t YOU'RE PLAYING LUDO SAJ" << endl;
reChoice:
    cout << "\t\tSelect Player" << endl;
    cout << "\tPress (1) to 1 player" << endl;
    cout << "\tPress (2) to 2 player" << endl;
    cout << "\tPress (3) to 3 player" << endl;
    cout << "\tPress (4) to 4 player" << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            cout << "Playing With computer" << endl;
            return 1;
        }
        case 2:
        {
            cout << "Playing with your friend" << endl;
            return 2;
        }
        case 3:
        {
            cout << "Playing three Players" << endl;
            return 3;
        }
        case 4:
        {
            cout << "Playing four Players" << endl;
            return 4;
        }
        default:
        {
            goto reChoice;
        }
    }
}
void turnCom()
{
    int doubleSix = 0, num = generate();
    cout << "Computer auto turn turn result is: " << endl;
    if (num == 6)
    {
        cout <<  " -|---|-" << endl;
        cout <<  " -| 6 |-" << endl;
        cout <<  " -|---|-" << endl;
        doubleSix++;
        if (doubleSix == 6)
        {
            doubleSix = 0;
            cout << "Again! Computer auto turn turn result is: " << endl;
            generate();
            result(num);
            cout << "Your turn. ";
        }
        else
            cout << "Your turn. ";
    }
    else
    {
        result(num); // update with switch
        cout << "Your turn. ";
    }
}
void exitCon(string str)
{
    if (str == "-1")
        exit(0);
}
void result(int n)
{
    switch(n)
    {
    case 1:
        cout <<  "  ---" << endl;
        cout <<  " | 1 |" << endl;
        cout <<  "  ---" << endl;
        break;
    case 2:
        cout <<  "  ---" << endl;
        cout <<  " | 2 |" << endl;
        cout <<  "  ---" << endl;
        break;
    case 3:
        cout <<  "  ---" << endl;
        cout <<  " | 3 |" << endl;
        cout <<  "  ---" << endl;
        break;
    case 5:
        cout <<  "  ---" << endl;
        cout <<  " | 5 |" << endl;
        cout <<  "  ---" << endl;
        break;
    case 4:
        cout <<  "  ---" << endl;
        cout <<  " | 4 |" << endl;
        cout <<  "  ---" << endl;
        break;
    }
}
