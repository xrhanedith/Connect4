#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;

void test_board();

int main(int argc, const char * argv[]) {
    
    test_board();
}


void test_board() {
    //test default constructor
    cout << "Test Board default constructor" << endl;
    Board aa;
    aa.prettyPrintBoard(cout);
    cout << "aa is: " << endl;
    aa.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << aa.toMove();
    cout << endl;
    
    //test non default constructor
    cout << "Test Board non-default constructor" << endl;
    Board a("2xo3/7/7/7/7/7 o");
    a.prettyPrintBoard(cout);
    cout << "a is: " << endl;
    a.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << a.toMove();
    cout << endl;
    
    Board b("2x1oo1/2x4/7/7/7/7 x");
    b.prettyPrintBoard(cout);
    cout << "b is: " << endl;
    b.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << b.toMove();
    cout << endl;
    
    //make move need to be fix
    //mave move on col[n] would add on col[n+1]
    Board c("2x1oo1/2x4/x6/o5o/7/7 x");
    c.prettyPrintBoard(cout);
    cout << "c is: " << endl;
    c.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << b.toMove();
    
    cout << "Make move..";
    c.makeMove(2);
    c.prettyPrintBoard(cout);
    cout << "c is: " << endl;
    c.printBoard_as_FENstring(cout);
    cout << endl;
    
    Board d("xoxxoox/oxxxoxo/xoooo2/2x4/7/7 x");
    d.prettyPrintBoard(cout);
    cout << "d is: " << endl;
    d.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << d.toMove();
    
    //test make move
    cout << "Make move..";
    d.makeMove(4);
    cout << endl;
    d.prettyPrintBoard(cout);
    d.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << d.toMove();
    
    cout << "Make move..";
    d.makeMove(4);
    cout << endl;
    d.prettyPrintBoard(cout);
    d.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << d.toMove();
    
    cout << "Make move..";
    d.makeMove(8);
    cout << endl;
    d.prettyPrintBoard(cout);
    d.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << d.toMove();
    
    cout << "Make move..";
    d.makeMove(-5);
    cout << endl;
    d.prettyPrintBoard(cout);
    d.printBoard_as_FENstring(cout);
    cout << "The next one to move is player " << d.toMove();

}
