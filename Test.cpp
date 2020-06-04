#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

TEST_CASE("Game-1")
{
    Board *bo = new Board(8, 8);
    Board &board = *bo;
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new SniperCommander(1);
    board[{0, 6}] = new Sniper(1);
    board[{0, 4}] = new ParamedicCommander(1);
    board[{2, 1}] = new Paramedic(1);

    CHECK(board.has_soldiers(1));

    // Add soldiers for player 2:
    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new FootSoldier(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    board[{7, 0}] = new Sniper(2);
    board[{7, 2}] = new SniperCommander(2);
    board[{7, 6}] = new Sniper(2);
    board[{5, 1}] = new Paramedic(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 2}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 3}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1, 2}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 2}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 3}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Game-2")
{
    Board *bo = new Board(8, 8);
    Board &board = *bo;
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new SniperCommander(1);
    board[{0, 6}] = new Sniper(1);
    board[{0, 4}] = new ParamedicCommander(1);
    board[{2, 1}] = new Paramedic(1);

    CHECK(board.has_soldiers(1));

    // Add soldiers for player 2:
    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new FootSoldier(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    board[{7, 0}] = new Sniper(2);
    board[{7, 2}] = new SniperCommander(2);
    board[{7, 6}] = new Sniper(2);
    board[{5, 1}] = new Paramedic(2);
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 1}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 2}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 3}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 4}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 5}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 6}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {5, 1}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 0}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 1}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 2}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 3}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 5}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 6}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {7, 7}, Board::MoveDIR::Left);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {6, 2}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(2, {5, 2}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {2, 1}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1, 4}, Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 5}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 6}, Board::MoveDIR::Right);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {0, 7}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
    board.move(1, {1, 7}, Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 2}, Board::MoveDIR::Up), "ERR: this soldier is dead..");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 1}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 2}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 3}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 5}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 6}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 7}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 6}, Board::MoveDIR::Up), "ERR: no soldier on board");
    CHECK_THROWS_MESSAGE(board.move(1, {7, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {7, 6}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 1}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 2}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 3}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {1, 5}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(2, {0, 0}, Board::MoveDIR::Up), "ERR: the soldier belongs to the other player");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Down), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 0}, Board::MoveDIR::Left), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {0, 5}, Board::MoveDIR::Down), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {7, 6}, Board::MoveDIR::Up), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {7, 0}, Board::MoveDIR::Up), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 0}, Board::MoveDIR::Left), "ERR: you tried to move out of the board");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 1}, Board::MoveDIR::Right), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 2}, Board::MoveDIR::Left), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 2}, Board::MoveDIR::Right), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {1, 2}, Board::MoveDIR::Up), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {2, 2}, Board::MoveDIR::Down), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 0}, Board::MoveDIR::Up), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 0}, Board::MoveDIR::Right), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {7, 0}, Board::MoveDIR::Down), "ERR: targeted location already has a soldier");
    CHECK_THROWS_MESSAGE(board.move(1, {6, 1}, Board::MoveDIR::Left), "ERR: targeted location already has a soldier");
}