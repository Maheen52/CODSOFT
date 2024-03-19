#include <iostream>
using namespace std;

class TicTacToe{
private:
    char board[3][3];
    int currentplayer;

public:
    TicTacToe() 
	{
        currentplayer = 1;
        initializingboard();
    }

    void initializingboard() 
	{
        for (int i=0; i<3; ++i) 
		{
            for (int j=0; j<3; ++j) 
			{
                board[i][j] = '-';
            }
        }
    }

    void displayBoard() {
        cout << "     |     |     " << endl;
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
        cout << "     |     |     " << endl;
        cout << "You are assigned: " << (currentplayer == 1 ? "X" : "O") << endl;
    }


    bool validatemove(int row, int col) 
	{
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-');
    }

    void move() 
	{
        int row, col;
        cout << "Player " << currentplayer << "'s turn." << endl;
		cout << "Enter row and column (0-2) to mark your move on the board: ";
        cin >> row >> col;

        if (validatemove(row, col)) 
		{
            board[row][col] = (currentplayer == 1 ? 'X' : 'O');
            switchplayers();
        } 
		else 
		{
            cout << "Invalid move. Try again." << endl;
            move();
        }
    }

    bool checkForWin() {
        for (int i = 0; i < 3; ++i) 
		{
            if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
			{
                return true;
            }
            if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
			{
                return true;
            }
        }
        
        if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
		{
            return true;
        }
        if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
		{
            return true;
        }
        return false;
    }

    bool checkForDraw() 
	{
        for (int i=0; i<3; ++i) 
		{
            for (int j=0; j<3; ++j) 
			{
                if (board[i][j] == '-') 
				{
                    return false;
                }
            }
        }
        return true;
    }

    void switchplayers() 
	{
        currentplayer = (currentplayer == 1) ? 2 : 1;
    }

    void displayResult() 
	{
        displayBoard();
        if (checkForWin()) 
		{
            cout << "Player " << ((currentplayer == 1) ? 2 : 1) << " wins!" << endl;
        } 
		else if (checkForDraw()) 
		{
            cout << "It's a draw!" << endl;
        } 
		else 
		{
            cout << "Game is still ongoing." << endl;
        }
    }

    bool playAgain() 
	{
        char choice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        return (choice == 'Y' || choice == 'y');
    }

    void play() 
	{
        while (true) 
		{
            while (!checkForWin() && !checkForDraw()) 
			{
                displayBoard();
                move();
            }
            displayResult();
            if (!playAgain()) 
			{
                cout << "Thanks for playing!" << endl;
                break;
            } 
			else 
			{
                initializingboard();
                currentplayer = 1;
            }
        }
    }
};

int main() 
{
    TicTacToe game;
    game.play();
    return 0;
}
