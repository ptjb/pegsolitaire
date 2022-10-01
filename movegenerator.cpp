#include "movegenerator.h"

Move MoveGenerator::GenerateNorthMove(Position current_position)
{
    Position new_position{.x=current_position.x, .y=current_position.y+2};
    Position position_to_clear{.x=current_position.x, .y=current_position.y+1};
    Move northmove{.new_position=new_position, .position_to_clear=position_to_clear};
    return northmove;
}

Move MoveGenerator::GenerateEastMove(Position current_position)
{
    Position new_position{.x=current_position.x+2, .y=current_position.y};
    Position position_to_clear{.x=current_position.x+1, .y=current_position.y};
    Move eastmove{.new_position=new_position, .position_to_clear=position_to_clear};
    return eastmove;
}

Move MoveGenerator::GenerateSouthMove(Position current_position)
{
    Position new_position{.x=current_position.x, .y=current_position.y-2};
    Position position_to_clear{.x=current_position.x, .y=current_position.y-1};
    Move southmove{.new_position=new_position, .position_to_clear=position_to_clear};
    return southmove;
}

Move MoveGenerator::GenerateWestMove(Position current_position)
{
    Position new_position{.x=current_position.x-2, .y=current_position.y};
    Position position_to_clear{.x=current_position.x-1, .y=current_position.y};
    Move westmove{.new_position=new_position, .position_to_clear=position_to_clear};
    return westmove;
}
