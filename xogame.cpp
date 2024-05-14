#include <iostream>
#include <ctime>
using namespace std;

class xo
{
protected:
    //The design
    char game[10] = { 'o','1','2','3','4','5','6','7','8','9' };
    int player = 1;
    int choice;
    char mark;
    int i;
public:
    void board()
    {
        system("cls");//to clear the screen
        cout << "\t     --->XO<--- \n\n";
        cout << "player 1 <X>\t --\t player 2 <O>\n\n";
        cout << "     |     |     \n";
        cout << "  " << game[1] << "  |  " << game[2] << "  |  " << game[3] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << game[4] << "  |  " << game[5] << "  |  " << game[6] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << game[7] << "  |  " << game[8] << "  |  " << game[9] << "  \n";
        cout << "     |     |     \n\n";
    }

    virtual int checkwin() final
    {
        if (game[1] == game[2] && game[2] == game[3])
            return 1;

        else if (game[4] == game[5] && game[5] == game[6])
            return 1;

        else if (game[7] == game[8] && game[8] == game[9])
            return 1;

        else if (game[1] == game[4] && game[4] == game[7])
            return 1;

        else if (game[2] == game[5] && game[5] == game[8])
            return 1;

        else if (game[3] == game[6] && game[6] == game[9])
            return 1;

        else if (game[1] == game[5] && game[5] == game[9])
            return 1;

        else if (game[3] == game[5] && game[5] == game[7])
            return 1;

        //In case of no one winning
        else if (game[1] != '1' && game[2] != '2' && game[3] != '3' && game[4] != '4' && game[5] != '5'
            && game[6] != '6' && game[7] != '7' && game[8] != '8' && game[9] != '9')
            return 0;
        else
            return -1;
    }
    void switch_player()
    {
        player = (player % 2) ? 1 : 2;
    }

    virtual void check_empty() final
    {
        //Check if the spot is empty
        if (choice == 1 && game[1] == '1')
            game[1] = mark;

        else if (choice == 2 && game[2] == '2')
            game[2] = mark;

        else if (choice == 3 && game[3] == '3')
            game[3] = mark;

        else if (choice == 4 && game[4] == '4')
            game[4] = mark;

        else if (choice == 5 && game[5] == '5')
            game[5] = mark;

        else if (choice == 6 && game[6] == '6')
            game[6] = mark;

        else if (choice == 7 && game[7] == '7')
            game[7] = mark;

        else if (choice == 8 && game[8] == '8')
            game[8] = mark;

        else if (choice == 9 && game[9] == '9')
            game[9] = mark;

        else
        {
            //If an invalid number is entered
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkwin();
        player++;
    }
};

class play_comp : public xo
{
public:
    void play()
    {
        do
        {
            xo::board();
            xo::switch_player();

            if (player == 2)
            {
                random();
            }

            else
            {
                cout << " enter a number : " << endl;
                cin >> choice;
            }
            //Set the player as X and the computer as O.
            mark = (player == 1) ? 'X' : 'O';
            xo::check_empty();
        } while (i == -1);

        xo::board();

        if (i == 1)
        {
            if (player == 2)
                cout << "\a\t\t*******-->Congratulations you have won<--*******";

            else
                cout << "\a\t\t*******-->Better luck next time!<--*******" << endl;


        }
        else
        {
            cout << "==>\aGame draw";
            cin.ignore();
            cin.get();

        }
    }

    void random()
    {
        //Generating random numbers from 1 to 9
        int low = 1, high = 9;
        srand(time(0));
        int temp = rand();
        int num = temp % (high - low + 1) + low;
        if (game[num] == 'X' || game[num] == 'O')
        {
            // Repeat the random number generation until an unmarked spot is found
            while (game[num] == 'X' || game[num] == 'O')
            {
                temp = rand();
                num = temp % (high - low + 1) + low;
            }
        }
        choice = num;
    }
};

class play_fr : public xo
{
public:
    void play()
    {
        do {
            xo::board();
            xo::switch_player();
            cout << "player" << player << ", enter a number: " << endl;
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';
            xo::check_empty();
        } while (i == -1);
        {
            xo::board();

            if (i == 1)
            {
                cout << "==>\aPlayer " << --player << " win ";

            }
            else
            {
                cout << "==>\aGame draw";
                cin.ignore();
                cin.get();
            }


        }
    }
};


int main()
{
    int choice;
    do {
        cout << "\n";
        cout << "\t\t\t     ___   ___   ___\n";
        cout << "\t\t\t    |   | |   | |   |\n";
        cout << "\t\t\t    | X | | O | | X |\n";
        cout << "\t\t\t    |___| |___| |___|\n";

        cout << "\n ==>_______________ Who do you want to play against?_______________<==\n";
        cout << "\n\t 1-press 1 to play against the computer \n";
        cout << "\n\t 2-press 2 to play against your friend\n ";
        cout << "\n\t 3-press 3 to exit\n";
        cout << "\n_____________________________________________________________________\n";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            play_comp game1;
            game1.play();
            break;
        }
        case 2:
        {
            play_fr game2;
            game2.play();
            break;
        }
        case 3:
            cout << "\a\n\tBY:\n";
            cout << "\t   Mahmoud Hany Elsaied\n";
            break;
        default:
            cout << "\n ENTER A VALID NUMBER! \n";
        }
    } while (choice != 3);

    return 0;
}
