//
//  gameClass.h
//  Battleship Project
//
//  Created by Aaron Bloomfield on 10/10/18.
//  CPSC 340 Section 1

#ifndef boardH
#define boardH
#include "list.h"
const int SIZE = 10; //Board size in the x and y directions (between 10 and 20)
class gameClass{
public:
    //Default constructor, initializes both boards to either a BLANK or NOBOMB
    gameClass() ;
    
    //Declare what a blank is
    const char BLANK = ' '; 
    //for final output & stored array
    const char SHIP = 'S';  
    //Miss
    const char MISS = 'o';  
    //Hit
    const char HIT = 'X';   
    //Not bombed for user display
    const char NOBOMB = '.'; 

    //Prints out the rules for the game
    void rules();
    
    //Fills the Cheat board with Blanks and fills the User board with periods (no bombs)
    void fillBoard(char boardFill, char userFill);
    
    //Places the Ship of 4 spaces (S's) randomly throughout the board
    void placeShip(int& targetsOpen);
    
    //If the option to not cheat is selected in main, this drops bombs for only
    //the user board and then displays only the user board
    void dropBomb(int& targetsOpen);
    
    //If the option to cheat is selected in main, this drops bombs for both the user board and
    //the cheat board then displays both boards
    void dropBombCheat(int& targetsOpen);
    
    //Displays the cheat board and location of only Ships
    void dispBoardCheat();
    
    //Displays the board that the user can see displaying if they hit or miss a ship
    void dispBoard();
    
    //Creates a count of how many times an S (or ship) is on a board at a time. It is then called in
    //both dropBomb functions
    int Winner();
private:
        List<char> board[SIZE];         //init main play board
        List<char> userView[SIZE];      //User view, only shows bombs dropped
};

#endif /* board_hpp */
