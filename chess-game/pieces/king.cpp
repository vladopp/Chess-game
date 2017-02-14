#include "king.h"

King::King(Color color)
    : Piece(color,ptKing) {
    hasMoved = false;
}

std::vector< std::vector<Coordinate> > King::getPossibleMoves(Coordinate currentPosition) {
    std::vector<Coordinate> moves;
    //add possible moves to vector
    for(int col=currentPosition.getColumn()-1;col<=currentPosition.getColumn()+1;col++) {
        for(int row=currentPosition.getRow()-1;row<=currentPosition.getRow()+1;row++) {

            //if move coincides with king position OR if move is out of bounds -> continue
            if(col==currentPosition.getColumn() && row==currentPosition.getRow() ||
                    col<0 || col>=8 || row<0 || row>=8)
                continue;

            moves.push_back(Coordinate(row,col));
        }
    }

    //add castling moves if king has not been moved
    if(getColor() == cBlack) {
        if (!hasMoved){
            moves.push_back(Coordinate(0, 2)); // left
            moves.push_back(Coordinate(0, 6)); // right
        }
    } else {
        if (!hasMoved){
            moves.push_back(Coordinate(7, 2)); // left
            moves.push_back(Coordinate(7, 6)); // right
        }
    }

    std::vector< std::vector<Coordinate> > result;

    //split every move in a separate vector and add it to the result to be returned
    std::vector<Coordinate>::const_iterator begin = moves.begin();
    for (int i = 0; i < moves.size(); i++) {
        result.push_back(std::vector<Coordinate>(begin + i, begin + i + 1));
    }
    return result;
}

Piece* King::getCopy() const
{
    King* newKing = new King(color);
    newKing->hasMoved=this->hasMoved;
    return newKing;
}
