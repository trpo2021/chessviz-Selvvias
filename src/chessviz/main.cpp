// #include "libraries.hpp"
#include <chessvizlib/libraries.hpp>

int main()
{

    setlocale(LC_ALL, "ru");

    char board[8][8];
    bool status[8][8];
    char action[6];

    ifstream input;
    input.open("mv.txt");

    init(board, status);

    while (!input.eof()) {
        cout << "\n";

        input >> action[0] >> action[1] >> action[2] >> action[3] >> action[4] >> action[5];
        if (input.eof())
            break;

        if ((action[2] < ONE || action[5] < ONE) || (action[2] > EIGHT || action[5] > EIGHT) || (action[1] < A || action[4] < A) || (action[1] > H || action[4] > H)) {
            cout << "ERROR!"
                 << "\n";
            break;
        }
        if (action[0] != board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)]) {
            cout << "ERROR!"
                 << "\n";
            break;
        }
        move(board, status, action);
    }

    input.close();

    return 0;
}
