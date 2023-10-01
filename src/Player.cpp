#include "Player.h"
#include <chrono>
#include <limits>
#include <climits>
/////////////////////////////////////////
////////////PLAYER BASE CLASS////////////
/////////////////////////////////////////

//initilizes name
Player::Player(std::string name)
    : m_name(name)
{
}

//returns name
std::string Player::name() const
{
    return m_name;
}

//default is bot but it can be overriden
bool Player::isInteractive() const
{
    return false;
}

//deconstructor for data members but its just a built in type
Player::~Player()
{
}

/////////////////////////////////////////
///////HUMAN PLAYER DERIVED CLASS////////
/////////////////////////////////////////

//initilizes name
HumanPlayer::HumanPlayer(std::string name)
    : Player(name)
{
}

// we will use base class name getter

//returns true because it is human
bool HumanPlayer::isInteractive() const
{
    return true;
}

int HumanPlayer::chooseMove(const Board &b, Side s) const
{
    int choice;
    do
    {
        //prompts user to select hole
        cout << "Select a hole, " + name() + ": ";
        cin >> choice;
        //validates the choice
        if (choice <= 0 || choice > b.holes())
        {
            cout << "The hole number must be from 1 to " + to_string(b.holes()) + "." << endl;
        }
        else if (b.beans(s, choice) == 0)
        {
            cout << "There are no beans in that hole." << endl;
        }
    } while (choice <= 0 || choice > b.holes() || b.beans(s, choice) <= 0);
    return choice;
}

/////////////////////////////////////////
////////BAD PLAYER DERIVED CLASS/////////
/////////////////////////////////////////

//initilizes name
BadPlayer::BadPlayer(std::string name)
    : Player(name)
{
}

// we will use base class name getter

// since we will use base class implementation of isInteractive we don't need

//chooses the most right hole
int BadPlayer::chooseMove(const Board &b, Side s) const
{
    for (int i = b.holes(); i != 0; i--)
    {
        if (b.beans(s, i) > 0)
        {
            return i;
        }
    }
    return -1;
}

/////////////////////////////////////////
///////SMART PLAYER DERIVED CLASS////////
/////////////////////////////////////////

//initilizes name
SmartPlayer::SmartPlayer(std::string name)
    : Player(name)
{
}

// we will use base class name getter

// since we will use base class implementation of isInteractive we don't need

//this calls the helper function and returns the actual best hole that the smartplayer chooses
int SmartPlayer::chooseMove(const Board &b, Side s) const
{
    int bestHole;
    int value;
    chooseMoveHelper(b, s, bestHole, value, depth);
    return bestHole;
}

void SmartPlayer::chooseMoveHelper(const Board &b, Side s, int &bestHole, int &value, int depth) const
{
    // Start time
    auto startTime = std::chrono::high_resolution_clock::now();
    // .1 second to wrap up everything
    auto endTime = startTime + std::chrono::milliseconds(4990);

    // if the clock ends 
    //we just evaluate and return
    if (std::chrono::high_resolution_clock::now() >= endTime)
    { 
        value = evaluateBoard(b);
        return;
    }

    //this is so that we can evaluate multple start positions and not go all the way down the game tree
    //setting it so we only have to go through a depth of 5
    //we evaluate the board and just return
    if (depth > 5)
    { 
        value = evaluateBoard(b);
        return;
    }

    //if there is no more beans in play we evaluate and just return
    if (b.beansInPlay(s) == 0)
    {
        value = evaluateBoard(b);
        return;
    }

    //start on the first hole
    int first = 1;
    for (int i = 1; i <= b.holes(); i++)
    {
        //if hole is empty we move onto the next hole
        if (b.beans(s, i) == 0)
        { 
            first++;
            continue;
        }

        //CREATING A TEMP BOARD
        Board temp = b;
        Side endSide;
        int endHole;
        int value2;
        int height2;
        int height3;

        //recursion
        if (doMove(s, i, temp, endSide, endHole))
        { 
            //this changes it so that it sees what the openents next move could be 
            //and increases the depth
            chooseMoveHelper(temp, opponent(s), height2, value2, depth + 1);
        }
        //this is still the same players turn
        else
        { 
            chooseMoveHelper(temp, s, height3, value2, depth);
        }
        
        //this just ensures that there is atleast a move 
        if (i == first)
        { 
            value = value2;
            bestHole = i;
        }
        
        //if the smart player is on SOUTH
        if (s == SOUTH)
        {
            //comparing whcih value is better
            if (value2 > value)
            {
                value = value2;
                bestHole = i;
            }
        }
        //if the smart player is ON NORTH
        else
        { 
            //comparing which value is better
            if (value2 < value)
            {
                value = value2;
                bestHole = i;
            }
        }

        //if time is greater than 5 seconds
        if (std::chrono::high_resolution_clock::now() >= endTime)
        { 

            break;
        }
    }
    return;
}

bool SmartPlayer::doMove(Side s, int hole, Board &b, Side &endSide, int &endHole) const
{
    if (b.sow(s, hole, endSide, endHole))
    {   
        //takes another turn if it ends on a pot
        if (endHole == 0)
        { 
            return false;
        }
        else if (endSide == s)
        {
            //capturing beans from the opponenet
            if (b.beans(s, endHole) == 1 && b.beans(opponent(s), endHole) != 0 && endHole != POT)
            { 
                b.moveToPot(opponent(s), endHole, s);
                b.moveToPot(s, endHole, s);
            }
        }
        return true;
    }
    return false;
}

int SmartPlayer::evaluateBoard(const Board &b) const
{   
    //tells me how many beans are on play on both sides        
    int northbeans = b.beansInPlay(NORTH); 
    int southbeans = b.beansInPlay(SOUTH);
    //tells me how many beans are in pot on both sides
    int northpot = b.beans(NORTH, POT); 
    int southpot = b.beans(SOUTH, POT);

    //if either of them are at 0 we can tell who wins
    if (southbeans == EMPTY || northbeans == EMPTY)
    {
        //if south pot has more beans in pot and on the side, while north having no more beans
        //south will automatically win
        if ( southpot + southbeans >  northpot + northbeans)
        {
            return INT_MAX;
        }
        //if south has less beans in pot and on the side, while north has no more beans
        //south will lose automatically
        else if ( southpot + southbeans <  northpot + northbeans)
        {
            return INT_MIN;
        }
        //else its just a draw automatically
        else
        { 
            return 0;
        }
    }
    //evaluate the score
    return  southpot + southbeans -  northpot - northbeans;
}