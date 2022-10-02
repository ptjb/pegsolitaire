#include "movegenerator.h"

Move MoveGenerator::GenerateNorthMove(Position current_position)
{
    Position new_position{.x=current_position.x, .y=current_position.y+2};
    PegMove peg_move{.initial_position=current_position,.final_position=new_position};
    Position position_to_clear{.x=current_position.x, .y=current_position.y+1};
    Move northmove{.peg_move=peg_move, .position_to_clear=position_to_clear};
    return northmove;
}

Move MoveGenerator::GenerateEastMove(Position current_position)
{
    Position new_position{.x=current_position.x+2, .y=current_position.y};
    PegMove peg_move{.initial_position=current_position,.final_position=new_position};
    Position position_to_clear{.x=current_position.x+1, .y=current_position.y};
    Move eastmove{.peg_move=peg_move, .position_to_clear=position_to_clear};
    return eastmove;
}

Move MoveGenerator::GenerateSouthMove(Position current_position)
{
    Position new_position{.x=current_position.x, .y=current_position.y-2};
    PegMove peg_move{.initial_position=current_position,.final_position=new_position};
    Position position_to_clear{.x=current_position.x, .y=current_position.y-1};
    Move southmove{.peg_move=peg_move, .position_to_clear=position_to_clear};
    return southmove;
}

Move MoveGenerator::GenerateWestMove(Position current_position)
{
    Position new_position{.x=current_position.x-2, .y=current_position.y};
    PegMove peg_move{.initial_position=current_position,.final_position=new_position};
    Position position_to_clear{.x=current_position.x-1, .y=current_position.y};
    Move westmove{.peg_move=peg_move, .position_to_clear=position_to_clear};
    return westmove;
}
