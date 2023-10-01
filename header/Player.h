#ifndef PLAYER_H
#define PLAYER_H
#include "Side.h"
#include "Board.h"
#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
    Player(std::string name);
    std::string name() const;
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board &b, Side s) const = 0;
    virtual ~Player();

private:
    std::string m_name;
};

class HumanPlayer : public Player
{
public:
    HumanPlayer(std::string name);
    virtual bool isInteractive() const;
    virtual int chooseMove(const Board &b, Side s) const;
};

class BadPlayer : public Player
{
public:
    BadPlayer(std::string name);
    virtual int chooseMove(const Board &b, Side s) const;
};

class SmartPlayer : public Player
{
public:
    SmartPlayer(std::string name);
    virtual int chooseMove(const Board &b, Side s) const;
private:
    int evaluateBoard(const Board &b) const;
    void chooseMoveHelper(const Board& b, Side s, int& bestHole, int& value, int depth) const;
    bool doMove(Side s, int hole, Board &b, Side &endSide, int &endHole) const;
    int depth = 0;    
};

#endif