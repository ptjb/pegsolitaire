#include "movevalidator.h"

bool MoveValidator::IsValidMove(Board board, Move move)
{
    return board.checksqpos(move.position_to_clear) && board.checksqpos(move.peg_move.final_position) && board.checksqvalmid(move.position_to_clear) && board.checksqvalend(move.peg_move.final_position);
}