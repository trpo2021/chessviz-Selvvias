#include <chessvizlib/libraries.hpp>

void move(char board[][8], bool status[][8], char* action)
{
    char temp;

    cout << " ";

    if (status[(int)(EIGHT - action[2])][8 - (int)(H - action[1] + 1)] == 1) {
        temp = board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)];

        remove(action, board);

        status[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)] = 0;

        board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))] = temp;
        status[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))] = 1;
    }
    display_board(board, status);
}

void remove(char* action, char board[][8])
{
    board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)] = '*';
}