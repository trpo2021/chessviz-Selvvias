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

    if (!input) {
        cout << "\nFILE CAN'T BE READED\n";
        exit(-1);
    }

    while (!input.eof()) {
        cout << "\n";

        input >> action[0] >> action[1] >> action[2] >> action[3] >> action[4]
                >> action[5];
        if (input.eof())
            break;

        int check = input_checkout(board, action);

        if (check == 0)
            move(board, status, action);
    }

    input.close();

    return 0;
}