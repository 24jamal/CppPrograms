#include <iostream>
#include <limits>
using namespace std;

char board[3][3];
char player = 'X';
char ai = 'O';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

int evaluate() {
    // Check rows, columns and diagonals
    for (int row = 0; row < 3; row++)
        if (board[row][0] == board[row][1] &&
            board[row][1] == board[row][2]) {
            if (board[row][0] == ai) return +10;
            else if (board[row][0] == player) return -10;
        }

    for (int col = 0; col < 3; col++)
        if (board[0][col] == board[1][col] &&
            board[1][col] == board[2][col]) {
            if (board[0][col] == ai) return +10;
            else if (board[0][col] == player) return -10;
        }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == ai) return +10;
        else if (board[0][0] == player) return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == ai) return +10;
        else if (board[0][2] == player) return -10;
    }

    return 0;
}

int minimax(bool isMax) {
    int score = evaluate();

    if (score == 10 || score == -10)
        return score;

    if (!isMovesLeft())
        return 0;

    if (isMax) {
        int best = numeric_limits<int>::min();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    best = max(best, minimax(false));
                    board[i][j] = ' ';
                }
        return best;
    } else {
        int best = numeric_limits<int>::max();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    best = min(best, minimax(true));
                    board[i][j] = ' ';
                }
        return best;
    }
}

void aiMove() {
    int bestVal = numeric_limits<int>::min();
    int bestRow = -1, bestCol = -1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int moveVal = minimax(false);
                board[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }

    board[bestRow][bestCol] = ai;
    cout << "AI placed O.\n";
}

bool isWin(char sym) {
    return evaluate() == (sym == ai ? 10 : -10);
}

bool isDraw() {
    return !isMovesLeft() && evaluate() == 0;
}

void playerMove() {
    int move;
    cout << "Your move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9) {
        cout << "Invalid input. Try again.\n";
        playerMove();
        return;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != ' ') {
        cout << "Cell already taken. Try again.\n";
        playerMove();
        return;
    }

    board[row][col] = player;
}

int main() {
    initializeBoard();
    displayBoard();

    while (true) {
        playerMove();
        displayBoard();

        if (isWin(player)) {
            cout << "🎉 You win!\n";
            break;
        }
        if (isDraw()) {
            cout << "🤝 It's a draw!\n";
            break;
        }

        aiMove();
        displayBoard();

        if (isWin(ai)) {
            cout << "😈 AI wins!\n";
            break;
        }
        if (isDraw()) {
            cout << "🤝 It's a draw!\n";
            break;
        }
    }

    return 0;
}
