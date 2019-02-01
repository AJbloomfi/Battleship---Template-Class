//
//  gameClass.cpp
//  Battleship Project
//
//  Created by Aaron Bloomfield on 10/10/18.
//  CPSC 340 Section 1

#ifndef GAMECLASSCPP
#define GAMECLASSCPP
#include "gameClass.h"
#include "list.h"

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;


//Default constructor, initializes both boards to either a BLANK character or NOBOMB character
gameClass :: gameClass(){
    fillBoard(BLANK, NOBOMB);
}

//Prints out the rules for the game
void gameClass :: rules(){
    cout << "340 Battleship is a guessing game for one person."<< endl;
    cout << "The board is created by a 10 by 10 grid.  The " << endl;
    cout << "locations of the fleets are concealed from the" << endl;
    cout << "player.  The columns of the grid are numbered" << endl;
    cout << "and the rows are numbers.  The user must enter " << endl;
    cout << "the desired target as a coordinate pair separated" << endl;
    cout << "by a space or a newline." << endl;
    cout << endl;
}

//Fills the Cheat board with Blanks and fills the User board with periods (no bombs) using the insert function from list.cpp
void gameClass :: fillBoard(char boardFill, char userFill){
    for(int row = 0; row <SIZE; row++){
        for(int col=0; col < SIZE; col++){
            
            board[col].insert(boardFill);
            userView[col].insert(userFill);
            
        }
    }
    
}

//Places the Ship of 4 spaces (S's) randomly throughout the board
void gameClass :: placeShip(int& targetsOpen){
   
    targetsOpen = targetsOpen + 4;   
    char boardPiece;
    
    int Xfactor; 
    int Yfactor;
    int xmin;
    int ymin;
    bool flag;
    int row = rand()%SIZE; //Randomly generated row
    int col = rand()%SIZE; //Randomly generated column
    int newrow = 0;
    int newcol = 0;
    
    
    do{
    
        do{
        
            do{
            
                Xfactor = rand()%3 - 1; //Generates X direction of ship placement
                Yfactor = rand()%3 - 1; //Generates Y direction of ship placement
            
            }while(Xfactor == 0 && Yfactor == 0);
        
            xmin = row + 3 * Xfactor; //Determines valid x position
            ymin = col + 3 * Yfactor; //Determines valid y position
        
        }while((xmin >= SIZE || ymin >= SIZE || xmin < 0 || ymin < 0)); //makes sure they are in 
                                                                        //bounds of the list size
    
        for(int i=0; i<4; i++){ // Determines if the pieces at position i are a valid BLANK piece
            newrow = row + (i * Xfactor);
            newcol = col + (i * Yfactor);
        
            if(board[newcol].retrieve(newrow,boardPiece)){
                if(boardPiece == BLANK){
                    flag = true; 
                }
                else{
                    flag = false;
                }
            }
        }
        
        if(flag == true){ //Places a ship since the piece at position i is a valid piece
            
            for(int i=0; i<4; i++){
                newrow = row + (i * Xfactor);
                newcol = col + (i * Yfactor);
                board[newrow].replace(SHIP,newcol);
                
            }
        }
    }while(flag != true);
}

//If the option to not cheat is selected in main, this drops bombs for only
//the user board and then displays only the user board
void gameClass :: dropBomb(int& targetsOpen){
    int row; //row
    int col; //column
    int count = 0;
    
    cout << "You have " << targetsOpen << " bombs.Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
    cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
    while(targetsOpen != 0){
        
        
        
    
    cin >> row;
    
    cin >> col;
    
    char boardPiece; //board piece and position i
    
    
    if(board[row].retrieve(col,boardPiece)){ //determines if piece is valid
        if(boardPiece == BLANK || boardPiece == NOBOMB){
            targetsOpen--; //decrements the amount of bombs left
            
            cout << "Miss You have " << targetsOpen << " bombs left." << endl;
            
            userView[row].replace(MISS,col); //if there is no ship, places a miss character
            
            dispBoard(); //prints out the user board
            
            if(targetsOpen == 0){ //targets open is the passed in variable of how many bombs are left
                cout << "You LOSE.....loser!" << endl;
            }
            cout << "Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
            cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
        }
        if(boardPiece == SHIP){
            targetsOpen--; //decrements amount of bombs left
            
            cout << "HIT! You have " << targetsOpen << " bombs left." << endl;
            
            userView[row].replace(HIT,col); //replaces an S from a ship with an X for hit in the user board
            board[row].replace(HIT, col); //replaces an S from a ship with an X for hit in the cheat board
            
            dispBoard(); //displays the user board
            
            
            if(Winner() == 0){ //calls the winner function to see if the user has won or not yet by checking                         whether or not the amount of S's on a board is 0
                
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "End Game   0 1 2 3 4 5 6 7 8 9"<< endl;
                cout << "  ---------------------" << endl;
                for(int row = 0; row < SIZE; row++){ //prints out the winning board one last time
                    cout << row << "| ";
                    int count = 0;
                    for(int col=0; col < SIZE; col++){
                        char temp;
            
                        userView[col].retrieve(row,temp);
                        cout<<temp<<" ";
                        count ++;
                        if(count == SIZE){
                            cout << "|" << endl;
                        }
            
                    }
                }
                cout << "  ---------------------" << endl;
                cout << "Key : \"X\"=Hit, \"o\"=Miss, \" \"=Not bombed" << endl;
                
                cout << "You Won!!  To bad, you blew all the ships up." << endl; //prints they won, ends function
                exit(0);
            }
            cout << "Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
            
            
            cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
    
            
            
        }
    
    
    }
    }
}

//Displays the cheat board and location of only Ships
void gameClass :: dispBoardCheat(){
    cout << "Cheat Board" << endl;
    cout << "   0 1 2 3 4 5 6 7 8 9"<< endl;
    cout << "  ---------------------" << endl;
    for(int row = 0; row < SIZE; row++){
        cout << row << "| ";
        int count = 0;
        for(int col=0; col < SIZE; col++){
            char temp;
            
            board[col].retrieve(row,temp); //retrieves the character and position i in variable temp
            cout<<temp<<" ";
            count ++;
            if(count == SIZE){
                cout << "|" << endl;
            }
            
        }
    }
    cout << "  ---------------------" << endl;
}

//Displays the board that the user can see displaying if they hit or miss a ship
void gameClass :: dispBoard(){
    cout << "User Board" << endl;
    cout << "   0 1 2 3 4 5 6 7 8 9"<< endl;
    cout << "  ---------------------" << endl;
    for(int row = 0; row < SIZE; row++){
        cout << row << "| ";
        int count = 0;
        for(int col=0; col < SIZE; col++){
            char temp;
            
            userView[col].retrieve(row,temp); //retrieves the character and position i in variable temp
            cout<<temp<<" ";
            count ++;
            if(count == SIZE){
                cout << "|" << endl;
            }
            
        }
    }
    cout << "  ---------------------" << endl;
}

//If the option to cheat is selected in main, this drops bombs for both the user board and
//the cheat board then displays both boards
void gameClass :: dropBombCheat(int& targetsOpen){
    int row;
    int col;
    int count = 0;
    //int num = 0;
    cout << "You have " << targetsOpen << " bombs.Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
    cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
    while(targetsOpen != 0){
        
        
        
    
    cin >> row;
    
    cin >> col;
    
    char boardPiece; //variable for the character to be retrieved at position (row, col)
    
    
    if(board[row].retrieve(col,boardPiece)){ //retrieves board piece
        if(boardPiece == BLANK || boardPiece == NOBOMB){ //checks if that piece is a blank or no bomb
            targetsOpen--; //decrements amount of bombs the user has
            
            cout << "Miss You have " << targetsOpen << " bombs left." << endl;
            
            userView[row].replace(MISS,col); //replaces a spot hit with a bomb that wasnt a ship with a miss
            dispBoardCheat(); //prints out the cheat board
            dispBoard(); //prints out the user board
            
            if(targetsOpen == 0){ //if bombs are gone, end of game
                cout << "You LOSE.....loser!" << endl;
            }
            cout << "Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
            cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
        }
        if(boardPiece == SHIP){ //checks to see if the piece is a ship
            targetsOpen--; //decrements the amount of bombs a user has
            
            cout << "HIT! You have " << targetsOpen << " bombs left." << endl;
            
            userView[row].replace(HIT,col); //replaces ship piece hit with a HIT character
            board[row].replace(HIT, col); //replaces ship piece hit with a HIT character
            dispBoardCheat(); //prints out the cheat board
            dispBoard(); //prints out the user board
            
            
            if(Winner() == 0){ //calls the winner function to see if the user has won or not yet by checking                         whether or not the amount of S's on a board is 0
                
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "End Game   0 1 2 3 4 5 6 7 8 9"<< endl;
                cout << "  ---------------------" << endl;
                for(int row = 0; row < SIZE; row++){ //prints a final game board
                    cout << row << "| ";
                    int count = 0;
                    for(int col=0; col < SIZE; col++){
                        char temp;
            
                        userView[col].retrieve(row,temp);
                        cout<<temp<<" ";
                        count ++;
                        if(count == SIZE){
                            cout << "|" << endl;
                        }
            
                    }
                }
                cout << "  ---------------------" << endl;
                cout << "Key : \"X\"=Hit, \"o\"=Miss, \" \"=Not bombed" << endl;
                
                cout << "You Won!!  To bad, you blew all the ships up." << endl; //if the player wins, the                                                                       function ends
                exit(0);
            }
            cout << "Key : \"X\"=Hit, \"o\"=Miss, \".\"=Not bombed" << endl;
            
            cout << "Please enter coord pair to drop bomb (Col,Row): " << endl;
            
            
            
            
        }
    
    
    }
    }
}

//Creates a count of how many times an S (or ship) is on a board at a time. It is then called in
    //both dropBomb functions and during those functions, the amount of S's will be decremented, ultimately
    //bringing the "count" in the winner function to 0
int gameClass :: Winner(){
    int count = 0;
    for (int row=0; row<SIZE; row++){
        for(int col=0; col<SIZE; col++){
            char temp;
            
            board[col].retrieve(row,temp);
            if(temp == SHIP){
                count++;
            }
        }
    }
    return count;
}

#endif