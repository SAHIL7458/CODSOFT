#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the game board
void InitializeBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 3; i++) {
        vector<char> row;
        for (int j = 0; j < 3; j++) {
            row.push_back(' ');
        }
        board.push_back(row);
    }
}

// Function to display the game board
void DisplayBoard(const vector<vector<char> > &board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool CheckWin(const vector<vector<char> > &board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char> > board;
    InitializeBoard(board);
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (true) {
        DisplayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (CheckWin(board, currentPlayer)) {
            DisplayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        } else if (CheckDraw(board)) {
            DisplayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Do you want to play again? (yes/no): ";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "no") {
        cout << "Thanks for playing! Goodbye!" << endl;
    } else if (playAgain == "yes") {
        InitializeBoard(board);
        main(); // Restart the game
    } else {
        cout << "Invalid input. Thanks for playing! Goodbye!" << endl;
    }

    return 0;
}
