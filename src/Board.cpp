#include "Board.h"

Board::Board(int nHoles, int nInitialBeansPerHole)
{
    //checks if it is negative or 0
    if (nHoles <= 0)
    {
        nHoles = 1;
    }
    m_holes = nHoles + 1;
    //checks if it is negative or 0
    if (nInitialBeansPerHole <= 0)
    {
        nInitialBeansPerHole = 0;
    }
    //initilizes the beans per hole
    m_InitialBeansPerHole = nInitialBeansPerHole;
    //initilized the amount of beans
    totalbeans = 2 * (nInitialBeansPerHole * (m_holes - 1));
    //initilizes both pots
    initializePots(nInitialBeansPerHole, southpot);
    initializePots(nInitialBeansPerHole, northpot);
}

int Board::holes() const
{
    //returns the amount of holes
    //since m_holes includes the pots we have to subtract one
    return (m_holes - 1);
}

int Board::beans(Side s, int hole) const
{
    //validates if it is a hole and a valid side
    if (isValidHole(hole) && isValidSide(s))
    {
        //returns the amount of beans in that hole
        switch (s)
        {
        case NORTH:
            return northpot[hole];
            break;
        case SOUTH:
            return southpot[hole];
            break;

        default:
            break;
        }
    }
    return -1;
}

int Board::beansInPlay(Side s) const
{
    int counter = 0;
    //validates if it is a valid side
    if (isValidSide(s))
    {
        switch (s)
        {
            //counts how many beans in each hole and add it up
        case NORTH:
            for (int i = 1; i < m_holes; i++)
            {
                counter += northpot[i];
            }
            return counter;
            break;
        case SOUTH:
            for (int i = 1; i < m_holes; i++)
            {
                counter += southpot[i];
            }
            return counter;
            break;

        default:
            break;
        }
    }
    return counter;
}

int Board::totalBeans() const
{
    //returns the total amount of beans
    return totalbeans;
}


bool Board::sow(Side s, int hole, Side &endSide, int &endHole)
{

    //checks if it  is a valid side, valid hole, if it is empty, or a pot
    if ((!(isValidSide(s))) || !(isValidHole(hole)) || (beans(s, hole) == EMPTY) || isPot(s, hole))
    {
        return false;
    }
    
    int beancounter = 0;
    //starts right after 0
    int southcounter = 1;

    //starts at the end
    int northcounter = (m_holes - 1);
    
    //tells us which side we are on
    Side currentside = s;

    //north move
    if (s == NORTH)
    {

        // tells us how many beans that will go around
        beancounter = northpot[hole];
        // empty out the hole
        northpot[hole] = 0;

        //will finish when there are no more beans
        while (beancounter != 0)
        {
            // decrements the whole because the pot is at 0 and the starts at the last hole
            hole -= 1;

            // if it is the north pot
            if (hole == POT && currentside == NORTH && beancounter != 1)
            {
                // add one to pot
                northpot[hole]++;
                // change the side
                currentside = SOUTH;
                beancounter--;
            }

            //increment the hole for each bean
            if (currentside == NORTH)
            {
                northpot[hole]++;
            }

            //on south side
            if (currentside == SOUTH)
            {
                //starts and adds at the first hole
                southpot[southcounter]++;
                //then increments the hole
                southcounter++;

                // the last bean was already added so need to break out
                if (beancounter == 1)
                {
                    //returns what the last hole was
                    hole = (southcounter - 1);
                    break;
                }

                //if it reaches the southpot 
                if ((s == NORTH) && (southcounter == m_holes))
                {
                    // changes the current side
                    currentside = NORTH;
                    // resets where to start for south pot
                    southcounter = 1;
                    // resets where to start for north pot
                    hole = m_holes;
                }
            }

            beancounter--;
        }
        //returns what side it ended on and what hole it ended on
        endSide = currentside;
        endHole = hole;
        return true;
    }

    //south move
    else
    {
        //tells us how many beans will go around
        beancounter = southpot[hole];
        //empty out the hole
        southpot[hole] = 0;

        //finish sowing when beans are at 0
        while (beancounter != 0)
        {
            //incrementing the hole
            hole += 1;
            
            //if it is the south pot
            if (hole == m_holes && currentside == SOUTH)
            {
                //increment the pot
                southpot[POT]++;
                //change the side
                currentside = NORTH;
                //decrement the beans
                beancounter--;

                //returns the right endside and endhole
                if (beancounter == 0)
                {
                    currentside = SOUTH;
                    hole = 0;
                    break;
                }
            }

            //increment the hole for each bean
            if (currentside == SOUTH)
            {
                southpot[hole]++;
            }

            //if it is on north side for south turn
            if (currentside == NORTH)
            {
                //increment the whole starting for the furthest hole
                northpot[northcounter]++;
                //decrement the hole
                northcounter--;
                //last bean was already added so need to break out
                if (beancounter == 1)
                {
                    hole = northcounter + 1;
                    break;
                }
                //if it reaches the pot of the north need to switch sides
                if ((s == SOUTH) && (northcounter == POT))
                {
                    //switches side
                    currentside = SOUTH;
                    //resets holes
                    northcounter = (m_holes - 1);
                    hole = 0;
                }
            }

            beancounter--;
            // if ((northcounter + 1 == m_holes - 1) && (beancounter == 0))
            // {
            //     hole -= 1;
            // }
        }
        // returns what side it ended on and what hole it ended on
        endSide = currentside;
        endHole = hole;
        return true;
    }

    return false;
}

bool Board::moveToPot(Side s, int hole, Side potOwner)
{

    //checks if it is valid hole, pot, and side
    if (!(isValidHole(hole)) || isPot(s, hole) || !isValidSide(s))
    {
        return false;
    }

    //south turn
    if (s == SOUTH)
    {
        //move everything to NORTH pot
        if (potOwner == NORTH)
        {
            northpot[POT] += southpot[hole];
            southpot[hole] = 0;
            return true;
        }
        //else move everything to SOUTH pot
        else
        {
            southpot[POT] += southpot[hole];
            southpot[hole] = 0;
            return true;
        }
    }
    //north turn
    else
    {
        //move everything to NORTH pot
        if (potOwner == NORTH)
        {
            northpot[POT] += northpot[hole];
            northpot[hole] = 0;
            return true;
        }
        //move everything to SOUTH pot
        else
        {
            southpot[POT] += northpot[hole];
            northpot[hole] = 0;
            return true;
        }
    }
    return false;
}

bool Board::setBeans(Side s, int hole, int beans)
{
    //checks if it is valid hole, pot, side, and beans positive
    if (!(isValidHole(hole)) || isPot(s, hole) || !isValidSide(s) || beans < 0)
    {
        return false;
    }
    int previous = 0;
    //changes beans in the hole for north
    if (s == NORTH)
    {
        previous = northpot[hole];
        northpot[hole] = beans;
    }
    //changes beans in the hole for south
    if (s == SOUTH)
    {
        previous = southpot[hole];
        southpot[hole] = beans;
    }

    //changes the total beans
    totalbeans = totalbeans - previous + beans;
    return true;
}

void Board::initializePots(int initialBeans, vector<int> &pot)
{
    //pot starts on zero
    pot.push_back(0);
    for (int i = 1; i < m_holes; i++)
    {
        //holes
        pot.push_back(initialBeans);
    }
}

bool Board::isValidHole(int hole) const
{
    //checks for valid hole
    if ((hole < 0) || (hole > (m_holes - 1)))
    {
        return false;
    }
    return true;
}

bool Board::isValidSide(Side s) const
{
    //checks for valid side
    if (s != NORTH && s != SOUTH)
    {
        return false;
    }
    return true;
}

bool Board::isPot(Side s, int hole) const
{
    //checks if it is valid side
    if (isValidSide(s))
    {
        switch (s)
        {
        case NORTH:
        case SOUTH:
            if (hole == POT)
                return true;
            return false;
            break;
        default:
            break;
        }
    }
    return false;
}
