#include "movevalidator.h"

bool MoveValidator::IsValidMove(Board board, Move move)
{
    return board.IsOccupiedSpace(move.position_to_clear) && board.IsEmptySpace(move.peg_move.final_position);
}