#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "boardinit.hpp"
#include "boardprint.hpp"
#include "move.hpp"

enum let_digit {

    A = 97, H = 104, ONE = 49, EIGHT = 56

};

struct Figure {
    char Kw = 'K', Kb = 'k', Qw = 'Q', Qb = 'q', Rw = 'R', Rb = 'r', Nw = 'N', Nb = 'n', Bw = 'B', Bb = 'b', Pw = 'P', Pb = 'p';
};

using namespace std;