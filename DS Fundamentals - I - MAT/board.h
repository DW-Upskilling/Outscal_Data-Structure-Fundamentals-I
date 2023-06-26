#include <iostream>
#include <string>
#include <vector>

#include "board.h"

#ifndef GAME_H
#define GAME_H

class Game {
  Board *board;

  void session() {
    int currentPlayer = -1;
    bool gameOver = false;

    while (!gameOver) {
      currentPlayer = (currentPlayer + 1) % Constants::totalPlayers;
      updatePlayerMoveOnBoard(currentPlayer);
      board->print();
      if (board->isCompleted() || board->isFull())
        gameOver = true;
    }

    if (board->isFull()) {
      std::cout << "Draw!" << std::endl;
    } else {
      std::cout << "Player - " << (currentPlayer + 1) << "("
                << Board::Constants::getColorChar(currentPlayer) << ")"
                << " won!" << std::endl;
    }
  }

  void updatePlayerMoveOnBoard(int currentPlayer) {
    int choice;
    std::cout << "Player - " << (currentPlayer + 1) << "("
              << Board::Constants::getColorChar(currentPlayer) << ")"
              << "!\nPlease provide column(1-" << board->getColumns()
              << ") to drop the coin?";
    std::cin >> choice;

    if (!board->add(choice - 1, currentPlayer)) {
      std::cout << "Bad Choice! Please re-enter the column" << std::endl;
      updatePlayerMoveOnBoard(currentPlayer);
    }
  }

public:
  class Constants {
  public:
    static const int totalPlayers = 2;

    static const std::string welcomeHeader;
    static const std::string rulesString;
    static const std::string howToPlayString;
  };

  Game(int rows, int columns) { board = new Board(rows, columns); }

  void start() {
    std::cout << Constants::welcomeHeader << std::endl;
    std::cout << Constants::rulesString << std::endl;
    std::cout << Constants::howToPlayString << std::endl;

    session();
  }

  ~Game() { delete board; }
};

const std::string Game::Constants::welcomeHeader = R"(
---------------------------------------------------
|                                                 |
|              Welcome to CONNECT-4!              |
|                                                 |
---------------------------------------------------
)";

const std::string Game::Constants::rulesString = R"(
###################################################
                        Rules
###################################################
1. The size of the board is 6x7
2. Total no. of players are 2
3. First Player represented with (R)
4. Second Player represented with (G)
)";

const std::string Game::Constants::howToPlayString = R"(
###################################################
                    How to Play
###################################################
1. Game always starts with Player-1
2. During each chance player drops the coin
3. Get four coins either in horizontal, vertical or diagonal to win
4. It's a draw if enter board gets filled before the connect-4
)";

#endif /*GAME_H*/