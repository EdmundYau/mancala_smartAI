#include "Game.h"

//initilizes board, north player, and south player
Game::Game(const Board &b, Player *south, Player *north)
    : m_board(b), m_north(north), m_south(south)
{
}

    // displays the board
    void Game::display() const
{
    int boardSize = m_board.holes();

    // Calculate the width of each hole
    int holeWidth = 3; // Assuming each hole has a width of 3 characters
    int middleSpaces = (boardSize / 2) * holeWidth;

    // Print spaces before north player name
    for (int i = 1; i <= middleSpaces; i++)
    {
        cout << " ";
    }
    cout << m_north->name() << endl;

    cout << "   ";
    for (int i = 1; i <= boardSize; i++)
    {
        cout << " " + to_string(m_board.beans(NORTH, i)) + " ";
    }
    cout << endl;

    cout << " " + to_string(m_board.beans(NORTH, POT)) + " ";
    for (int i = 1; i <= boardSize; i++)
    {
        cout << "   ";
    }
    cout << " " + to_string(m_board.beans(SOUTH, POT)) + " ";
    cout << endl;

    cout << "   ";
    for (int i = 1; i <= boardSize; i++)
    {
        cout << " " + to_string(m_board.beans(SOUTH, i)) + " ";
    }
    cout << endl;

   
    for (int i = 1; i <= middleSpaces; i++)
    {
        cout << " ";
    }
    cout << m_south->name() << endl;
}


void Game::status(bool &over, bool &hasWinner, Side &winner) const
{
    //if there is still ebans in play then the game isnt over
    if (m_board.beansInPlay(NORTH) != 0 && m_board.beansInPlay(SOUTH) != 0)
    { 
        over = false;
        hasWinner = false;
        return;
    }
    over = true;

    //else we check how many beans are in each pot 
    //north win
    if (m_board.beans(NORTH, POT) > m_board.beans(SOUTH, POT))
    { 
        hasWinner = true;
        winner = NORTH;
    }
    //south win
    else if (m_board.beans(SOUTH, POT) > m_board.beans(NORTH, POT))
    { 
        hasWinner = true;
        winner = SOUTH;
    }
    //draw
    else
    { 
        hasWinner = false;
    }

    return;
}

bool Game::move(Side s)
{
    int move;
    Side endside;
    int endhole;
    //south turn
    if (s == SOUTH)
    {
        //keep going if the end hole was the pot
        do
        {
            //hole that south wants to play
            move = m_south->chooseMove(m_board, SOUTH);
            //if it is a bot
            if (!m_south->isInteractive())
            {
                cout << m_south->name() + " chooses hole " + to_string(move) << endl;
            }
            //south turn
            m_board.sow(s, move, endside, endhole);
            
            //capture logic
            if ((endhole != POT) && m_board.beans(SOUTH, endhole) == 1 && m_board.beans(NORTH, endhole) != 0 && endside == SOUTH)
            {
                m_board.moveToPot(NORTH, endhole, SOUTH);
                m_board.moveToPot(SOUTH, endhole, SOUTH);
            }
            display();
        } while ((endhole == POT) && m_board.beansInPlay(SOUTH) != 0);
    }

    //north turn
    else
    {
        // keep going if the end hole was the pot
        do
        {
            //hole that north wants to play
            move = m_north->chooseMove(m_board, NORTH);
            //if it is a bot
            if (!m_north->isInteractive())
            {
                cout << m_north->name() + " chooses hole " + to_string(move) << endl;
            }

            m_board.sow(s, move, endside, endhole);
            //capture logic
            if ((endhole != POT) && m_board.beans(NORTH, endhole) == 1 && m_board.beans(SOUTH, endhole) != 0 && endside == NORTH)
            {
                m_board.moveToPot(SOUTH, endhole, NORTH);
                m_board.moveToPot(NORTH, endhole, NORTH);
            }
            display();
        } while ((endhole == POT) && m_board.beansInPlay(NORTH) != 0);
    }

    //if north has no more beans to play game is over
    if (m_board.beansInPlay(NORTH) == 0)
    { 
        
        cout << "Sweeping remaining beans into " + m_south->name() + "'s pot." << endl;
        
        // moves all the beans into south pot
        for (int i = 1; i <= m_board.holes(); i++)
        { 
            m_board.moveToPot(SOUTH, i, SOUTH);
        }
        display();
        return false;
    }
    //if south has no more beans to play game is over
    else if (m_board.beansInPlay(SOUTH) == 0)
    {
        
        cout << "Sweeping remaining beans into " + m_north->name() + "'s pot." << endl;
        //mnove all the beans into north pot
        for (int i = 1; i <= m_board.holes(); i++)
        { // loop through north's holes
            m_board.moveToPot(NORTH, i, NORTH);
        }
        display();
        return false;
    }
    return true;
}

void Game::play()
{
    bool over, hasWinner;
    Side winner;
   
    display();
    //keep going if game not over
    do
    {
        //south always go first 
        //south turn
        bool gamechecksouth = move(SOUTH);
        //if south has no more beans
        if(gamechecksouth == false)
        {
            status(over, hasWinner, winner);
            break;
        }
        //north turn
        bool gamechecknorth = move(NORTH);
        //if north has no more beans
        if (gamechecknorth == false)
        {
            status(over, hasWinner, winner);
            break;
        }
        //if both players are bots
        if (!m_south->isInteractive() && !m_north->isInteractive())
        {
            cout << endl;
            cout << "Press ENTER to continue." << endl;
            cin.ignore(10000, '\n');
        }

        //check the status of game
        status(over, hasWinner, winner);
    } while (over != true);


    //print winner
    if(hasWinner == false)
    {
        cout << "It's a tie." << endl;
    }
    else
    {
        if (winner == SOUTH)
            cout << "The winner is " + m_south->name() << endl;
        else
            cout << "The winner is " + m_north->name() << endl;
    }
}

int Game::beans(Side s, int hole) const
{
    //returns beans in hole
    return m_board.beans(s, hole);
}