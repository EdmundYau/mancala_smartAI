#ifndef BOARD_H
#define BOARD_H
#include "Side.h"
#include <vector>
using namespace std;

class Board
{
public:
    Board(int nHoles, int nInitialBeansPerHole);
    int holes() const;
    int beans(Side s, int hole) const;
    int beansInPlay(Side s) const;
    int totalBeans() const;
    bool sow(Side s, int hole, Side &endSide, int &endHole);
    bool moveToPot(Side s, int hole, Side potOwner);
    bool setBeans(Side s, int hole, int beans);

private:
    vector<int> northpot;
    vector<int> southpot;
    int m_holes;
    int m_InitialBeansPerHole;
    int totalbeans;

    // helper functions
    void initializePots(int initialBeans, vector<int> &pot);
    bool isValidHole(int hole) const;
    bool isValidSide(Side s) const;
    bool isPot(Side s, int hole) const;
};

#endif