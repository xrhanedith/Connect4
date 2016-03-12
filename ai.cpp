#include "ai.h"
#include "board.h"
#include <cstdlib>
#include <time.h>

int connect4AI(const Board& board){
    // This is the Easy AI. It returns a random column.
    // You need to delete this and write your own AI.
    return rand() % NUM_COLS;
}