#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

enum let_digit {

    A = 97, H = 104, ONE = 49, EIGHT = 56

};

void init(char board[][8], bool status[][8]);
void display_board(char board[][8], bool status[][8]);
void move(char board[][8], bool status[][8], char *action);
void remove (char *action, char board[][8]);

struct Figure {
    char Kw = 'K', Kb = 'k', Qw = 'Q', Qb = 'q', Rw = 'R', Rb = 'r', Nw = 'N', Nb = 'n', Bw = 'B', Bb = 'b', Pw = 'P', Pb = 'p';
};

void init(char board[][8], bool status[][8]);

int main () {

    setlocale(LC_ALL, "ru");

    char board[8][8];
    bool status[8][8];
    char action[6];                                                                          

    ifstream input;
    input.open("mv.txt");

    init(board, status);

    while (!input.eof())
    {
        cout << "\n";

        input >> action[0] >> action[1] >> action[2] >> action[3] >> action[4] >> action[5];
        if (input.eof())                                                                       
        break;

        if ((action[2] < ONE || action[5] < ONE) || (action[2] > EIGHT || action[5] > EIGHT) || (action[1] < A || action[4] < A) || (action[1] > H || action[4] > H)) 
        {                                                                                     
            cout << "ERROR!" << "\n";
            false;
            break;
        }
        if (action[0] != board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)])     
        {
            cout << "ERROR!" << "\n";
            false;
            break; 
        }
        move(board, status, action);
    }

    system("pause");
	input.close();

    return 0;
}

void init(char board[][8], bool status[][8]) {

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

    display_board(board, status);
}

void display_board(char board[][8], bool status[][8]) {
    
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

void move (char board[][8], bool status[][8], char *action) {

    char temp;

    cout << " ";

    if (status[(int)(EIGHT - action[2])][8 - (int)(H - action[1] + 1)] == 1 ) {
        temp = board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)];          

            remove(action, board);                                                          

        status[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)] = 0;

        board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))] = temp;            
        status[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))] = 1;

    } 
    display_board(board, status);


}

void remove (char *action, char board[][8]) {

    board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)] = '*';
    
}
