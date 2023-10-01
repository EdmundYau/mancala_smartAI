// #include "Side.h"
// #include "Board.h"
// #include "Player.h"
// #include "Game.h"
// using namespace std;
// int main()
// {
//     BadPlayer bp1("Thao");
//     HumanPlayer hp2("Victor");
//     SmartPlayer sp3("Edmund");
//     Side test = NORTH;
//     int holetest = 0;
    // initiliazing board with 3 holes and 2 beans per hole
    // initiliazing board with 3 holes and 2 beans per hole
    // initiliazing board with 3 holes and 2 beans per hole
    // initiliazing board with 3 holes and 2 beans per hole
   // Board b(3, 2);
    // Board b5(3, 2);
    // cout << "true: " << b5.sow(NORTH, 3, test, holetest) << endl; // testing sowing for north side just simple ccw
    // cout << "end side: " << test << endl;                         // testing if returns correct side
    // cout << "end hole: " << holetest << endl;                     // testing if returns correct hole
    // cout << "north pot: " << b5.beans(NORTH, 0) << endl;
    // cout << "beans: " << b5.beans(NORTH, 1) << endl;
    // cout << "beans: " << b5.beans(NORTH, 2) << endl;
    // cout << "beans: " << b5.beans(NORTH, 3) << endl;
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b5.beans(SOUTH, 1) << endl;
    // cout << "beans: " << b5.beans(SOUTH, 2) << endl;
    // cout << "beans: " << b5.beans(SOUTH, 3) << endl;
    // cout << "south pot: " << b5.beans(SOUTH, 0) << endl;

    // Board b6(3, 2);
    // cout << "true: " << b6.sow(NORTH, 1, test, holetest) << endl; // testing sowing for north side ending in pot
    // cout << "end side: " << test << endl;                         // testing if returns correct side should be 0 for NORTH
    // cout << "end hole: " << holetest << endl;                     // testing if returns correct hole should be 0 for POT
    // cout << "north pot: " << b6.beans(NORTH, 0) << endl;          // should be 1
    // cout << "beans: " << b6.beans(NORTH, 1) << endl;              // should be 3
    // cout << "beans: " << b6.beans(NORTH, 2) << endl;              // should be 0
    // cout << "beans: " << b6.beans(NORTH, 3) << endl;              // should be 2
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b6.beans(SOUTH, 1) << endl;     // should be 2
    // cout << "beans: " << b6.beans(SOUTH, 2) << endl;     // should be 2
    // cout << "beans: " << b6.beans(SOUTH, 3) << endl;     // should be 2
    // cout << "south pot: " << b6.beans(SOUTH, 0) << endl; // should be 0

    // Board b7(3, 2);
    // cout << "true: " << b7.sow(NORTH, 1, test, holetest) << endl; // testing sowing for north side switching sides and skipping south pot
    // cout << "end side: " << test << endl;                         // testing if returns correct side should be 1 for SOUTH
    // cout << "end hole: " << holetest << endl;                     // testing if returns correct hole should be 1 for SOUTH HOLE 1
    // cout << "north pot: " << b7.beans(NORTH, 0) << endl;          // should be 1
    // cout << "beans: " << b7.beans(NORTH, 1) << endl;              // should be 0
    // cout << "beans: " << b7.beans(NORTH, 2) << endl;              // should be 2
    // cout << "beans: " << b7.beans(NORTH, 3) << endl;              // should be 2
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b7.beans(SOUTH, 1) << endl;     // should be 3
    // cout << "beans: " << b7.beans(SOUTH, 2) << endl;     // should be 2
    // cout << "beans: " << b7.beans(SOUTH, 3) << endl;     // should be 2
    // cout << "south pot: " << b7.beans(SOUTH, 0) << endl; // should be 0

    // Board b8(3, 2);
    // cout << "true: " << b8.sow(SOUTH, 1, test, holetest) << endl; // testing sowing for south side just simple ccw
    // cout << "end side: " << test << endl;                         // testing if returns correct side should be 1 for SOUTH
    // cout << "end hole: " << holetest << endl;                     // testing if returns correct hole should be 3 for SOUTH HOLE 3
    // cout << "north pot: " << b8.beans(NORTH, 0) << endl;          // should be 0
    // cout << "beans: " << b8.beans(NORTH, 1) << endl;              // should be 2
    // cout << "beans: " << b8.beans(NORTH, 2) << endl;              // should be 2
    // cout << "beans: " << b8.beans(NORTH, 3) << endl;              // should be 2
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b8.beans(SOUTH, 1) << endl;     // should be 0
    // cout << "beans: " << b8.beans(SOUTH, 2) << endl;     // should be 3
    // cout << "beans: " << b8.beans(SOUTH, 3) << endl;     // should be 3
    // cout << "south pot: " << b8.beans(SOUTH, 0) << endl; // should be 0

    // Board b9(3, 2);
    // cout << "true: " << b9.sow(SOUTH, 2, test, holetest) << endl; // testing sowing for south side ending in SOUTH POT
    // cout << "end side: " << test << endl;                         // testing if returns correct side should be 1 for SOUTH
    // cout << "end hole: " << holetest << endl;                     // testing if returns correct hole should be 0 for SOUTH POT
    // cout << "north pot: " << b9.beans(NORTH, 0) << endl;          // should be 0
    // cout << "beans: " << b9.beans(NORTH, 1) << endl;              // should be 2
    // cout << "beans: " << b9.beans(NORTH, 2) << endl;              // should be 2
    // cout << "beans: " << b9.beans(NORTH, 3) << endl;              // should be 2
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b9.beans(SOUTH, 1) << endl;     // should be 2
    // cout << "beans: " << b9.beans(SOUTH, 2) << endl;     // should be 0
    // cout << "beans: " << b9.beans(SOUTH, 3) << endl;     // should be 3
    // cout << "south pot: " << b9.beans(SOUTH, 0) << endl; // should be 1

    // Board b10(3, 2);
    // cout << "true: " << b10.sow(SOUTH, 3, test, holetest) << endl; // testing sowing for south side for switching sides
    // cout << "end side: " << test << endl;                          // testing if returns correct side should be 0 for NORTH
    // cout << "end hole: " << holetest << endl;                      // testing if returns correct hole should be 3 for NORTH HOLE
    // cout << "north pot: " << b10.beans(NORTH, 0) << endl;          // should be 0
    // cout << "beans: " << b10.beans(NORTH, 1) << endl;              // should be 2
    // cout << "beans: " << b10.beans(NORTH, 2) << endl;              // should be 2
    // cout << "beans: " << b10.beans(NORTH, 3) << endl;              // should be 3
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b10.beans(SOUTH, 1) << endl;     // should be 2
    // cout << "beans: " << b10.beans(SOUTH, 2) << endl;     // should be 2
    // cout << "beans: " << b10.beans(SOUTH, 3) << endl;     // should be 0
    // cout << "south pot: " << b10.beans(SOUTH, 0) << endl; // should be 1
    // cout << "holes: " << b1.holes() << endl; // testing hole getter
    // cout << "===========" << endl;
    // cout << "beans: " << b1.beans(SOUTH, 1) << endl;     // seeing if we initilized correctly which should be 2
    // cout << "beans: " << b1.beans(SOUTH, 2) << endl;     // seeing if we initilized correctly which should be 2
    // cout << "beans: " << b1.beans(SOUTH, 3) << endl;     // seeing if we initilized correctly which should be 2
    // cout << "south pot: " << b1.beans(SOUTH, 0) << endl; // seeing if we initilized correctly which should be 0 for pot
    // cout << "===========" << endl;
    // cout << "north pot: " << b1.beans(NORTH, 0) << endl;     // seeing if we initilized correctly which should be 0 for pot
    // cout << "beans: " << b1.beans(NORTH, 1) << endl;         // seeing if we initilized correctly which should be 2
    // cout << "beans: " << b1.beans(NORTH, 2) << endl;         // seeing if we initilized correctly which should be 2
    // cout << "beans: " << b1.beans(NORTH, 3) << endl;         // seeing if we initilized correctly which should be 2
    // cout << "side beans: " << b1.beansInPlay(NORTH) << endl; // testing beansInPlay member function should return 6
    // cout << "side beans: " << b1.beansInPlay(SOUTH) << endl; // testing beansInPlay member function should return 6
    // cout << "total beans: " << b1.totalBeans() << endl;      // testing total beans member function should return 12mber function should return 0// testing total beans member function should return 4
    // // Board b(-1, 2);
    // cout << "holes: " << b.holes() << endl;
    // cout << "===========" << endl;
    // cout << "beans: " << b.beans(SOUTH, 1) << endl;
    // cout << "beans: " << b.beans(SOUTH, 2) << endl;
    // cout << "beans: " << b.beans(SOUTH, 3) << endl;
    // cout << "south pot: " << b.beans(SOUTH, 0) << endl;
    // cout << "===========" << endl;
    // cout << "north pot: " << b.beans(NORTH, 0) << endl;
    // cout << "beans: " << b.beans(NORTH, 1) << endl;
    // cout << "beans: " << b.beans(NORTH, 2) << endl;
    // cout << "beans: " << b.beans(NORTH, 3) << endl;
    // // cout << "beans: " << b.beans(NORTH, 4) << endl;
    // cout << "side beans: " << b.beansInPlay(NORTH) << endl;
    // cout << "side beans: " << b.beansInPlay(SOUTH) << endl;
    // cout << "total beans: " << b.totalBeans() << endl;
    // cout << "move beans" << b.moveToPot(SOUTH, -1, NORTH) << endl;
    // cout << "north pot move: " << b.beans(NORTH, 0) << endl;
    // cout << "north pot move: " << b.beans(SOUTH, 2) << endl;

//     // cout <<"testing: " << b.setBeans(NORTH, 3, 10) << endl;
//     // cout << "beans: " << b.beans(NORTH, 3) << endl;
//     // cout << "total beans: " << b.totalBeans() << endl;

//     // cout << "testing: " << b.setBeans(SOUTH, 3, 10) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 2) << endl;
//     // cout << "total beans: " << b.totalBeans() << endl;
//     // cout << "===========" << endl;
    // cout << "true: " << b.sow(NORTH, 1, test, holetest) << endl;
    // cout << "end side: " << test << endl;
    // cout << "end hole: " << holetest << endl;
    // cout << "north pot: " << b.beans(NORTH, 0) << endl;
    // cout << "beans: " << b.beans(NORTH, 1) << endl;
    // cout << "beans: " << b.beans(NORTH, 2) << endl;
    // cout << "beans: " << b.beans(NORTH, 3) << endl;
    // cout << "!!!!!!!!!!!" << endl;
    // cout << "beans: " << b.beans(SOUTH, 1) << endl;
    // cout << "beans: " << b.beans(SOUTH, 2) << endl;
    // cout << "beans: " << b.beans(SOUTH, 3) << endl;
    // cout << "south pot: " << b.beans(SOUTH, 0) << endl;
//     // cout << "===========" << endl;
//     // cout << "true" << b.sow(NORTH, 3, test, holetest) << endl;
//     // cout << "end side" << test << endl;
//     // cout << "end hole" << holetest << endl;
//     // cout << "north pot: " << b.beans(NORTH, 0) << endl;
//     // cout << "beans: " << b.beans(NORTH, 1) << endl;
//     // cout << "beans: " << b.beans(NORTH, 2) << endl;
//     // cout << "beans: " << b.beans(NORTH, 3) << endl;
//     // cout << "!!!!!!!!!!!" << endl;
//     // cout << "beans: " << b.beans(SOUTH, 0) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 1) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 2) << endl;
//     // cout << "south pot: " << b.beans(SOUTH, 3) << endl;
//     // cout << "===========" << endl;
//     // cout << "true" << b.sow(NORTH, 1, test, holetest) << endl;
//     // cout << "end side" << test << endl;
//     // cout << "end hole" << holetest << endl;
//     // cout << "north pot: " << b.beans(NORTH, 0) << endl;
//     // cout << "beans: " << b.beans(NORTH, 1) << endl;
//     // cout << "beans: " << b.beans(NORTH, 2) << endl;
//     // cout << "beans: " << b.beans(NORTH, 3) << endl;
//     // cout << "!!!!!!!!!!!" << endl;
//     // cout << "beans: " << b.beans(SOUTH, 0) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 1) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 2) << endl;
//     // cout << "south pot: " << b.beans(SOUTH, 3) << endl;

//     // cout << "===========" << endl;
//     cout << "true: " << b.sow(SOUTH, 3, test, holetest) << endl;
//     cout << "end side: " << test << endl;
//     cout << "end hole: " << holetest << endl;
//     cout << "north pot: " << b.beans(NORTH, POT) << endl;
//     cout << "beans: " << b.beans(NORTH, 1) << endl;
//     cout << "beans: " << b.beans(NORTH, 2) << endl;
//     cout << "beans: " << b.beans(NORTH, 3) << endl;
//     cout << "!!!!!!!!!!!" << endl;
//     cout << "beans: " << b.beans(SOUTH, 1) << endl;
//     cout << "beans: " << b.beans(SOUTH, 2) << endl;
//     cout << "beans: " << b.beans(SOUTH, 3) << endl;
//     cout << "south pot: " << b.beans(SOUTH, POT) << endl;
//     Game g(b, &bp1, &bp2);
//     g.play();
//     std::cout << "passed all test!" << std::endl;
//}

// #include "Board.h"
// #include "Side.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// void doBoardTests()
// {
//     Board b(3, 2);
//     assert(b.holes() == 3 && b.totalBeans() == 12 &&
//            b.beans(SOUTH, POT) == 0 && b.beansInPlay(SOUTH) == 6);
//     b.setBeans(SOUTH, 1, 1);
//     b.moveToPot(SOUTH, 2, SOUTH);
//     // cout << "total beans: " << b.totalBeans() << endl;
//     // cout << "beans: " << b.beans(SOUTH, 1) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 2) << endl;
//     // cout << "beans: " << b.beans(SOUTH, 3) << endl;
//     // cout << "in play: " << b.beansInPlay(SOUTH) << endl;
//     assert(b.totalBeans() == 11 && b.beans(SOUTH, 1) == 1 &&
//            b.beans(SOUTH, 2) == 0 && b.beans(SOUTH, POT) == 2 &&
//            b.beansInPlay(SOUTH) == 3);
//     Side es;
//     int eh;
//     b.sow(SOUTH, 3, es, eh);
//     assert(es == NORTH && eh == 3 && b.beans(SOUTH, 3) == 0 &&
//            b.beans(NORTH, 3) == 3 && b.beans(SOUTH, POT) == 3 &&
//            b.beansInPlay(SOUTH) == 1 && b.beansInPlay(NORTH) == 7);
// }

// int main()
// {
//     doBoardTests();
//     cout << "Passed all tests" << endl;
// }

// #include "Game.h"
// #include "Player.h"
// #include "Board.h"
// #include "Side.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// void doGameTests()
// {
//     BadPlayer bp1("Bart");
//     BadPlayer bp2("Homer");
//     Board b(3, 0);
//     b.setBeans(SOUTH, 1, 2);
//     b.setBeans(NORTH, 2, 1);
//     b.setBeans(NORTH, 3, 2);
//     Game g(b, &bp1, &bp2);
//     bool over;
//     bool hasWinner;
//     Side winner;
//     //    Homer
//     //   0  1  2
//     // 0         0
//     //   2  0  0
//     //    Bart
//     g.display();
//     g.status(over, hasWinner, winner);
//     assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 0 &&
//            g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 2 &&
//            g.beans(SOUTH, 1) == 2 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);

//     g.move(SOUTH);
//     //   0  1  0
//     // 0         3
//     //   0  1  0
//     g.status(over, hasWinner, winner);
//     assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//            g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 1 && g.beans(NORTH, 3) == 0 &&
//            g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);

//     g.move(NORTH);
//     //   1  0  0
//     // 0         3
//     //   0  1  0
//     g.status(over, hasWinner, winner);
//     assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//            g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//            g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 1 && g.beans(SOUTH, 3) == 0);

//     g.move(SOUTH);
//     //   1  0  0
//     // 0         3
//     //   0  0  1
//     g.status(over, hasWinner, winner);
//     assert(!over && g.beans(NORTH, POT) == 0 && g.beans(SOUTH, POT) == 3 &&
//            g.beans(NORTH, 1) == 1 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//            g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 1);

//     g.move(NORTH);
//     //   0  0  0
//     // 1         4
//     //   0  0  0
//     g.status(over, hasWinner, winner);
//     assert(over && g.beans(NORTH, POT) == 1 && g.beans(SOUTH, POT) == 4 &&
//            g.beans(NORTH, 1) == 0 && g.beans(NORTH, 2) == 0 && g.beans(NORTH, 3) == 0 &&
//            g.beans(SOUTH, 1) == 0 && g.beans(SOUTH, 2) == 0 && g.beans(SOUTH, 3) == 0);
//     assert(hasWinner && winner == SOUTH);
// }

// int main()
// {
//     doGameTests();
//     cout << "Passed all tests" << endl;
// }

#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "Side.h"
#include <iostream>
#include <cassert>

using namespace std;

void doPlayerTests()
{
    HumanPlayer hp("Marge");
    assert(hp.name() == "Marge" && hp.isInteractive());
    BadPlayer bp("Homer");
    assert(bp.name() == "Homer" && !bp.isInteractive());
    SmartPlayer sp("Lisa");
    assert(sp.name() == "Lisa" && !sp.isInteractive());
    Board b(3, 2);
    b.setBeans(SOUTH, 2, 0);
    cout << "=========" << endl;
    int n = hp.chooseMove(b, SOUTH);
    cout << "=========" << endl;
    assert(n == 1 || n == 3);
    n = bp.chooseMove(b, SOUTH);
    assert(n == 1 || n == 3);
    n = sp.chooseMove(b, SOUTH);
    assert(n == 1 || n == 3);
}

int main()
{
    // HumanPlayer hp1("dummy");
    // SmartPlayer sp1("smarty");
    // Board b(6, 4);
    // Game g(b, &hp1, &sp1);
    // // g.display();
    // // g.move(SOUTH);
    // // g.display();
    // // g.move(SOUTH);
    // // g.display();
    // // bool test = g.move(SOUTH);
    // // g.display();
    // // cout << "test: " << test << endl;
    // g.play();
    // doPlayerTests();
    // cout << "Passed all tests" << endl;

    // HumanPlayer hp("Marge");
    // BadPlayer bp("Homer");
    // Board b(3, 2);
    // Game g(b, &hp, &bp); // testing constructing the game
    // g.display();          // testing the display

    // HumanPlayer hp("Marge");
    // HumanPlayer hp1("Homer");
    // Board b13(3, 1);
    // Game g(b13, &hp, &hp1);
    // g.display();
    // g.move(SOUTH); // testing the game for two human players
    //           // and if i choose 3 it should prompt me again to choose another move like 2 it should test capture
    // HumanPlayer hp("Marge");
    // BadPlayer bp1("Homer");
    // Board b14(3, 2);
    // Game g(b14, &hp, &bp1);
    // g.play(); // testing the game for one human player and one bad player and should only prompt one person
    // BadPlayer bp("Marge");
    // BadPlayer bp1("Homer");
    // Board b15(3, 2);
    // Game g(b15, &bp, &bp1);
    // g.play(); // testing the game for two bad players and should only prompt the viewer to click enter and we would see that it will always
    //           //  choose the right most value
    // HumanPlayer hp("Marge");
    // SmartPlayer sp1("Homer");
    // Board b16(3, 2);
    // Game g(b16, &hp, &sp1);
    // g.play(); // testing smart player vs human checking if smart player takes longer than 5 seconds to compute a play
    // SmartPlayer sp("Marge");
    // SmartPlayer sp1("Homer");
    // Board b17(3, 2);
    // Game g(b17, &sp, &sp1);
    // g.play(); // testing smart player vs human checking if smart player takes longer than 5 seconds to compute a play

    HumanPlayer hp("HumanPlayer 1");
    SmartPlayer hp1("SmartPlayer 2");
    Board b18(6, 4);
    Game g(b18, &hp, &hp1);
    g.play(); // testing the whole game with friend to see who could win it also tests the status function
}