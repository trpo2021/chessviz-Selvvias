#include "../src/chessvizlib/libraries.hpp"
#include "../thirdparty/ctest.h"

// TEST #1
CTEST(status_arr, true_status)
{
    CTEST_LOG("STATUS_MOVE_CHECK");
    char act[7] = "Pe2-e4";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const bool rez = stat_arr[4][4];

    ASSERT_EQUAL(rez, 1);
}
// TEST #2
CTEST(status_arr, remove_bool_status)
{
    CTEST_LOG("STATUS_REMOVE_CHECK");
    char act[7] = "Pe2-e4";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const bool rez = stat_arr[6][4];

    ASSERT_EQUAL(rez, 0);
}
// TEST #3
CTEST(board_arr, remove_board_figure)
{
    CTEST_LOG("BOARD_REMOVE_CHECK");
    char act[7] = "Pe2-e4";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = '*';
    const char rez = test_arr[6][4];

    ASSERT_EQUAL(rez, comp);
}
// TEST #4
CTEST(board_arr, move_board_figure)
{
    CTEST_LOG("BOARD_MOVE_CHECK");
    char act[7] = "Pe2-e4";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'P';
    const char rez = test_arr[4][4];

    ASSERT_EQUAL(rez, comp);
}
// TEST #5
CTEST(board_arr, move_board_Rook_left_and_right)
{
    CTEST_LOG("WHITE_ROOK_LEFT&RIGHT_CHECK");

    char act[7] = "Ra1-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'R';
    const char rez = test_arr[5][0];
    const int after_move_from = stat_arr[7][0];
    const int after_move_to = stat_arr[5][0];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "Rh1-h3";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'R';
    const char rez_2 = test_arr[5][7];
    const int after_move_from_2 = stat_arr[7][7];
    const int after_move_to_2 = stat_arr[5][7];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
// TEST #6
CTEST(board_arr, move_board_Knight_left_and_right)
{
    CTEST_LOG("WHITE_Knight_LEFT&RIGHT_CHECK");

    char act[7] = "Nb1-c3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'N';
    const char rez = test_arr[5][2];
    const int after_move_from = stat_arr[7][1];
    const int after_move_to = stat_arr[5][2];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "Ng1-f3";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'N';
    const char rez_2 = test_arr[5][5];
    const int after_move_from_2 = stat_arr[7][6];
    const int after_move_to_2 = stat_arr[5][5];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
// TEST #7
CTEST(board_arr, move_board_Bishop_left_and_right)
{
    CTEST_LOG("WHITE_Bishop_LEFT&RIGHT_CHECK");

    char act[7] = "Bc1-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'B';
    const char rez = test_arr[5][0];
    const int after_move_from = stat_arr[7][2];
    const int after_move_to = stat_arr[5][0];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "Bf1-h3";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'B';
    const char rez_2 = test_arr[5][7];
    const int after_move_from_2 = stat_arr[7][5];
    const int after_move_to_2 = stat_arr[5][7];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
// TEST #8
CTEST(board_arr, move_board_Queen)
{
    CTEST_LOG("WHITE_Queen_CHECK");

    char act[7] = "Qd1-d6";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'Q';
    const char rez = test_arr[2][3];
    const int after_move_from = stat_arr[7][3];
    const int after_move_to = stat_arr[2][3];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);
}
// TEST #9
CTEST(board_arr, move_board_King)
{
    CTEST_LOG("WHITE_King_CHECK");

    char act[7] = "Ke1-e3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'K';
    const char rez = test_arr[5][4];
    const int after_move_from = stat_arr[7][4];
    const int after_move_to = stat_arr[5][4];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);
}