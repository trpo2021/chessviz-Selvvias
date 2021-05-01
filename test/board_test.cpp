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
// TEST #10
CTEST(board_arr, move_board_black_rook_left_and_right)
{
    CTEST_LOG("BLACK_ROOK_LEFT&RIGHT_CHECK");

    char act[7] = "ra8-a6";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'r';
    const char rez = test_arr[2][0];
    const int after_move_from = stat_arr[0][0];
    const int after_move_to = stat_arr[2][0];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "rh8-h6";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'r';
    const char rez_2 = test_arr[2][7];
    const int after_move_from_2 = stat_arr[0][7];
    const int after_move_to_2 = stat_arr[2][7];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
//TEST #11
CTEST(board_arr, move_board_black_knight_left_and_right)
{
    CTEST_LOG("Black_Knight_LEFT&RIGHT_CHECK");

    char act[7] = "nb8-c6";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'n';
    const char rez = test_arr[2][2];
    const int after_move_from = stat_arr[0][1];
    const int after_move_to = stat_arr[2][2];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "ng8-f6";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'n';
    const char rez_2 = test_arr[2][5];
    const int after_move_from_2 = stat_arr[0][6];
    const int after_move_to_2 = stat_arr[2][5];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
// TEST #12
CTEST(board_arr, move_board_black_bishop_left_and_right)
{
    CTEST_LOG("Black_Bishop_LEFT&RIGHT_CHECK");

    char act[7] = "bc8-a6";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'b';
    const char rez = test_arr[2][0];
    const int after_move_from = stat_arr[0][2];
    const int after_move_to = stat_arr[2][0];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);

    char act_2[7] = "bf8-h6";
    move(test_arr, stat_arr, act_2);

    const char comp_2 = 'b';
    const char rez_2 = test_arr[2][7];
    const int after_move_from_2 = stat_arr[0][5];
    const int after_move_to_2 = stat_arr[2][7];

    ASSERT_EQUAL(rez_2, comp_2);
    ASSERT_EQUAL(after_move_from_2, 0);
    ASSERT_EQUAL(after_move_to_2, 1);
}
// TEST #13
CTEST(board_arr, move_board_black_queen)
{
    CTEST_LOG("Black_Queen_CHECK");

    char act[7] = "qd8-d5";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'q';
    const char rez = test_arr[3][3];
    const int after_move_from = stat_arr[0][3];
    const int after_move_to = stat_arr[3][3];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);
}
// TEST #14
CTEST(board_arr, move_board_black_king)
{
    CTEST_LOG("Black_King_CHECK");

    char act[7] = "ke8-e6";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);
    move(test_arr, stat_arr, act);

    const char comp = 'k';
    const char rez = test_arr[2][4];
    const int after_move_from = stat_arr[0][4];
    const int after_move_to = stat_arr[2][4];

    ASSERT_EQUAL(rez, comp);
    ASSERT_EQUAL(after_move_from, 0);
    ASSERT_EQUAL(after_move_to, 1);
}
//TEST #15
CTEST(board_arr, board_init) {
    char test_arr[8][8];
    bool stat_arr[8][8];

    CTEST_LOG("CHECK_BOARD_INITIALIZATION");

    init(test_arr, stat_arr);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i > 1 && i < 6) {
                const char comp = '*';
                ASSERT_EQUAL(test_arr[i][j], comp);
            }
            else if (i == 1) {
                const char comp_1 = 'p';
                ASSERT_EQUAL(test_arr[i][j], comp_1);
            }
            else if (i == 6) {
                const char comp_2 = 'P';
                ASSERT_EQUAL(test_arr[i][j], comp_2);
            }
            else if (i == 0) {
                if (j == 0 || j == 7)
                    ASSERT_EQUAL(test_arr[i][j], 'r');
                else if (j == 1 || j == 6)
                    ASSERT_EQUAL(test_arr[i][j], 'n');
                else if (j == 2 || j == 5)
                    ASSERT_EQUAL(test_arr[i][j], 'b');
                else if (j == 3)
                    ASSERT_EQUAL(test_arr[i][j], 'q');
                else if (j == 4)
                    ASSERT_EQUAL(test_arr[i][j], 'k');
            }
            else if (i == 7) {
                if (j == 0 || j == 7)
                    ASSERT_EQUAL(test_arr[i][j], 'R');
                else if (j == 1 || j == 6)
                    ASSERT_EQUAL(test_arr[i][j], 'N');
                else if (j == 2 || j == 5)
                    ASSERT_EQUAL(test_arr[i][j], 'B');
                else if (j == 3)
                    ASSERT_EQUAL(test_arr[i][j], 'Q');
                else if (j == 4)
                    ASSERT_EQUAL(test_arr[i][j], 'K');
            }
        }
    }


}
//TEST #16
CTEST(status_arr, check_init) {
    char test_arr[8][8];
    bool stat_arr[8][8];

    CTEST_LOG("CHECK_STATUS_BOARD_INITIALIZATION");

    init(test_arr, stat_arr);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 || i == 1 || i == 6 || i == 7)
                ASSERT_EQUAL(stat_arr[i][j], 1);
            if (i > 1 && i < 6)
                ASSERT_EQUAL(stat_arr[i][j], 0);
        }
    }
}
//TEST #17
CTEST(check_input, wrong_pos_figure) {
    CTEST_LOG("WRONG_INPUT_FIGURE_CHECK");

    char act[7] = "Ea1-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST #18
CTEST(check_input, wrong_pos_cell_from) {
    CTEST_LOG("WRONG_POSITION_CELL(LETTER)_FROM_CHECK");

    char act[7] = "Ry1-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST #19
CTEST(check_input, wrong_pos_cell_to) {
    CTEST_LOG("WRONG_POSITION_CELL(LETTER)_TO_CHECK");

    char act[7] = "Ra1-z3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST #20
CTEST(check_input, wrong_pos_digit_from) {
    CTEST_LOG("WRONG_POSITION_DIGIT_FROM_CHECK");

    char act[7] = "Ra9-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST #21
CTEST(check_input, wrong_pos_digit_to) {
    CTEST_LOG("WRONG_POSITION_DIGIT_TO_CHECK");

    char act[7] = "Ra1-a9";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST #22
CTEST(check_input, excess_input_data) {
    CTEST_LOG("EXCESS_INPUT_DATA_CHECK");

    char act[11] = "Ry35423-a3";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST#23
CTEST(check_input, not_enough_input_data) {
CTEST_LOG("NOT_ENOUGH_INPUT_DATA_CHECK");

    char act[7] = "Ry1-a";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}
//TEST#24
CTEST(check_input, completely_incorrect_input_data) {
    CTEST_LOG("COMPLETELY_INCORRECT_INPUT_DATA_CHECK");

    char act[7] = "Ryegtk";
    char test_arr[8][8];
    bool stat_arr[8][8];

    init(test_arr, stat_arr);

    const int rez = input_checkout(test_arr, act);
    ASSERT_EQUAL(rez, -1);
}