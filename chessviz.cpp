#include <iostream>
#include <string>

using namespace std;

struct Figure {
    char Kw = 'K', Kb = 'k', Qw = 'Q', Qb = 'q', Rw = 'R', Rb = 'r', Nw = 'N', Nb = 'n', Bw = 'B', Bb = 'b', Pw = 'P', Pb = 'p';
};

char board[8][8];
bool status[8][8];
int move_counter = 0;

void display_board();
void init_pos();
void move();
void remove();

int main () {

    char lett;
    int digit;
    init_pos();

    // while (cin >> lett >> digit)
    // {
    //     move(lett, digit);
    // }    


    return 0;
}

void move () {

}

void display_board () {

    char letter = 'A';
    cout << "\n";

    for (int i = 0; i < 8; i++) {
        cout << 8 - i;

        for (int j = 0; j < 8; j++)
        {
            cout << "|" << board[i][j] << "|";
        }

        cout << endl;
    }

    cout << "  ";

    for (int i = 0; i < 8; i++) {
        cout << letter << "  ";
        letter++;
    }

}

void init_pos () {

    Figure f;

    for (int i = 2; i < 7; i++) {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = '*';
            status[i][j] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        board[1][i] = f.Pb;
        status[1][i] = 1;

        board[6][i] = f.Pw;
        status[6][i] = 1;
    }

    board[0][0] = board[0][7] = f.Rb;
    status[0][0] = status[0][7] = 1;
    board[0][1] = board[0][6] = f.Nb;
    status[0][1] = status[0][6] = 1;
    board[0][2] = board[0][5] = f.Bb;
    status[0][2] = status[0][5] = 1;
    board[0][3] = f.Qb;
    status[0][3] = 1;
    board[0][4] = f.Kb;
    status[0][4] = 1;

    board[7][0] = board[7][7] = f.Rw;
    status[7][0] = status[7][7] = 1;
    board[7][1] = board[7][6] = f.Nw;
    status[7][1] = status[7][6] = 1;
    board[7][2] = board[7][5] = f.Bw;
    status[7][2] = status[7][5] = 1;
    board[7][3] = f.Qw;
    status[7][3] = 1;
    board[7][4] = f.Kw;
    status[7][4] = 1;

    display_board();
}