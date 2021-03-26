// #include "libraries.hpp"
#include <chessvizlib/libraries.hpp>

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
