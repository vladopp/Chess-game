#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <QString>

#include "state.h"
#include "coordinate.h"
#include "player.h"
#include "specialmoveshandler.h"
#include "gametype.h"
#include "piece.h"

class Controller {
private:
    State state;

    void initPieces();
    void initPlayers();
    void setPawnPieces(int row, Color color);
    void setMajorPieces(int row, Color color);
    bool isLeftCastle(Piece::PieceType pieceType, Coordinate source, Coordinate target);
    bool isRightCastle(Piece::PieceType pieceType, Coordinate source, Coordinate target);
    void changePlayer();
    void checkAndSetPownPromotion(Piece* sourcePiece, Coordinate& pieceCoordinate);

public:
    Controller();
    void movePiece(Coordinate source, Coordinate target);
    vector<Coordinate> getValidMoves(Coordinate click);
    void initState();
    const State& getState();
    void setFirstPlayer(string name, Color color);
    void setSecondPlayer(string name, Color color);
    void setGameType(TGameType gameType);
    void initStartingPlayer();
    void promotePown(Piece::PieceType pieceType);
    bool isInPownPromotion();
};

#endif // CONTROLLER_H
