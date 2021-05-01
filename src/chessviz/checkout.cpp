#include <chessvizlib/libraries.hpp>

int input_checkout(char board[][8], char* action)
{
    if ((action[2] < ONE || action[5] < ONE)
        || (action[2] > EIGHT || action[5] > EIGHT)
        || (action[1] < A || action[4] < A)
        || (action[1] > H || action[4] > H)) {
        return -1;
    }
    if (action[0]
        != board[(int)(EIGHT - action[2])][(int)(8 - (H - action[1]) - 1)]) {
        return -1;
    }
    //Проверка хода на взятие своей же фигуры
    if (action[0] > BIG_LOWER && action[0] < BIG_UPPER)
        if (board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))]
                    > BIG_LOWER
            && board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))]
                    < BIG_UPPER)
            return -1;

    if (action[0] > SMALL_LOWER && action[0] < SMALL_UPPER)
        if (board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))]
                    > SMALL_LOWER
            && board[(int)(EIGHT - action[5])][(int)(8 - (H - action[4] + 1))]
                    < SMALL_UPPER)
            return -1;

    return 0;
}