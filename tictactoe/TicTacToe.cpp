#include <iostream>
#include "TicTacToe.h"
/*
Upon entry of an incorrect row number by the user, the game shall report that the row
number is incorrect and prompt the user to reenter it.

Upon entry of an incorrect column number by the user, the game shall report that the
column number is incorrect and prompt the user to reenter it.

Upon entry of a row and column by the user corresponding to an occupied grid square
(one already containing an X or an O), the game shall report the error and prompt the
user to enter a new row and column.
*/
TicTacToe::TicTacToe(){
gameBoard = new char* [3];
 
gameBoard[0] = new char[3];
gameBoard[1] = new char[3];
gameBoard[2] = new char[3];
    initializeGrid();
}

std::tuple<int,int> TicTacToe::cpuPlay(){
    for (int row = 0 ; row < 3 ; row++){
        for (int col = 0; col < 3 ; col++){
            if (gameBoard[row][col] == '~'){
                std::tuple<int,int> unOccupied(row,col);
                return unOccupied;
            }
        }
    }
    std::tuple<int,int> nonetype(-1,-1);
    return nonetype;
}

std::tuple<int, int> TicTacToe::promptForGridCoord(){
    int iRow = 0;
    int iColumn = 0;

    std::cout<< "What row do you want to place at?: " << std::endl;
    std::cin >> iRow;
        
    std::cout<< "What column do you want to place at?: " << std::endl;
    std::cin >> iColumn;
    while (!(iRow <= 2 && iRow >= 0 && iColumn <= 2 && iColumn >= 0)){
        std::cout<< "What row do you want to place at?: " << std::endl;
        std::cin >> iRow;
            
        std::cout<< "What column do you want to place at?: " << std::endl;
        std::cin >> iColumn;
    }
    // Create a tuple holding the iRow and iColumn integer values and return the tuple.
    std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);

    return tupleCoord;
}

void TicTacToe::initializeGrid(){
    for (int row = 0; row < 3 ; row++ ){
        for (int col = 0 ; col < 3 ; col++){
            gameBoard[row][col] = '~';
        }
    }
}

void TicTacToe::displayGrid(){
    for (int row = 0; row < 3 ; row++ ){
        for (int col = 0 ; col < 3 ; col++){
            std::cout << this->gameBoard[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " " << std::endl;
}

bool TicTacToe::checkForWinner(){
    for (int row = 0; row < 3 ; row++ ){
       if (this->gameBoard[row][0] == this->gameBoard[row][1] &&  this->gameBoard[row][1] == this->gameBoard[row][2] &&
           this->gameBoard[row][1] != '~'){
           return true;
       }
    }
    for (int col = 0; col < 3 ; col++ ){
       if (this->gameBoard[0][col] == this->gameBoard[1][col] &&  this->gameBoard[1][col] == this->gameBoard[2][col] &&
           this->gameBoard[1][col] != '~'){
           return true;
       }
    }
    
    if (this->gameBoard[0][0] == this->gameBoard[1][1] &&  this->gameBoard[1][1] == this->gameBoard[2][2] &&
        this->gameBoard[1][1] != '~'){
        return true;
    }
    if (this->gameBoard[0][2] == this->gameBoard[1][1] &&  this->gameBoard[1][1] == this->gameBoard[2][0] &&
        this->gameBoard[1][1] != '~'){
        return true;
    }
    return false;
    
    
}


bool TicTacToe::checkForDraw(){
    for (int row = 0; row < 3 ; row++ ){
        for (int col =0 ; col <  3; col++){
            if (gameBoard[row][col] == '~'){
                return false;
            }
        }
    }
    return true;
    
}

void TicTacToe::play(){
    bool ifDraw = false;
    bool isWin = false;
    displayGrid();
    while (!ifDraw && !isWin){
        
        //player turn
        int iRow = 0;
        int iCol = 0;
        std::tie(iRow,iCol) = promptForGridCoord();
        this->gameBoard[iRow][iCol] = 'X';
        displayGrid();
        isWin = checkForWinner();
        if (isWin){
            std::cout << "X wins " << std::endl;
        }
        ifDraw = checkForDraw();
       
        //CPU turn
        if (!ifDraw && !isWin){
        iRow = 0;
        iCol = 0;
        std::tie(iRow,iCol) = cpuPlay();
        this->gameBoard[iRow][iCol] = 'O';
        displayGrid();
        isWin = checkForWinner();
            if (isWin){
                std::cout << "O wins " << std::endl;
            }
        ifDraw = checkForDraw();
        }
        
        if (ifDraw){
            std::cout << "Draw" << std::endl;
        }
    }

    
};

int main(){
    TicTacToe* p_game = new TicTacToe();
    p_game->play();
    return 0;
}
