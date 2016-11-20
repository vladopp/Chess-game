#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "coordinate.h"
#include "color.h"

class Piece
{
public:

    enum PieceType {
        ptKing,
        ptQueen,
        ptRook,
        ptBishop,
        ptKnight,
        ptPawn
    };

    Piece(Color color,PieceType pieceType);
    virtual std::vector<Coordinate> getPossibleMoves(Coordinate currentPosition) = 0;
    virtual Piece* getCopy() const = 0;
    bool isKilled();
    Color getColor() const;
    PieceType getType() const;

protected:
    Color color;
    bool killed;
    PieceType pieceType;
};

#endif // PIECE_H
