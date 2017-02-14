#include "queen.h"

#define min(a,b) (a<b ? a : b)

Queen::Queen(Color color)
    :Piece(color,ptQueen) {
}

std::vector< std::vector<Coordinate> > Queen::getPossibleMoves(Coordinate currentPosition) {
    std::vector<Coordinate> upLeft;
    std::vector<Coordinate> upRight;
    std::vector<Coordinate> downLeft;
    std::vector<Coordinate> downRight;
    std::vector<Coordinate> up;
    std::vector<Coordinate> down;
    std::vector<Coordinate> left;
    std::vector<Coordinate> right;

    int row = currentPosition.getRow();
    int col = currentPosition.getColumn();

    //lower right diagonal
    for (int j = col + 1, i = row + 1; j < 8 && i < 8; j++, i++) {
        downRight.push_back(Coordinate(i, j));
    }

    // upper right diagonal
    for (int j = col - 1, i = row + 1; j > -1 && i < 8; j--, i++) {
        upRight.push_back(Coordinate(i, j));
    }

    //upper left diagonal
    for (int j = col - 1, i = row - 1; j > -1 && i > -1; j--, i--) {
        upLeft.push_back(Coordinate(i, j));
    }

    //lower left diagonal
    for (int j = col + 1, i = row - 1; j < 8 && i > -1; j++, i--) {
        downLeft.push_back(Coordinate(i, j));
    }

    //moves up
    for (int i = row - 1; i > -1; i--) {
        up.push_back(Coordinate(i, col));
    }

    //moves down
    for (int i = row + 1; i < 8; i++) {
        down.push_back(Coordinate(i, col));
    }

    //moves right
    for (int i = col + 1; i < 8; i++) {
        right.push_back(Coordinate(row, i));
    }

    //moves left
    for (int i = col - 1; i > -1; i--) {
        left.push_back(Coordinate(row, i));
    }

    std::vector< std::vector<Coordinate> > result;

    result.push_back(up);
    result.push_back(down);
    result.push_back(right);
    result.push_back(left);
    result.push_back(upLeft);
    result.push_back(upRight);
    result.push_back(downLeft);
    result.push_back(downRight);

    return result;
}

Piece* Queen::getCopy() const {
    return new Queen(color);
}
