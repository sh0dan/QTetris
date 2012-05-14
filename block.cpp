#include "block.h"
#include <QtGui>

void Block::setRandomBlock() {
    setBlockType(BlockType(qrand() % 7 + 1));
}

void Block::setBlockType(BlockType type) {
    static const int coordsGrid[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
    };

    for (int i(0); i < 4; i++) {
        for (int j(0); j < 2; ++j) {
            coords[i][j] = coordsGrid[type][i][j];
        }
    }

    pieceType = type;
}

Block Block::rotatedLeft() const {
    if (pieceType == SquareBlock) {
        return *this;
    }

    Block result;
    result.pieceType = pieceType;
    for (int i(0); i < 4; ++i) {
        result.setX(i, y(i));
        result.setY(i, -x(i));
    }

    return result;
}

Block Block::rotatedRight() const {
    if (pieceType == SquareBlock) {
        return *this;
    }

    Block result;
    result.pieceType = pieceType;
    for (int i(0); i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }

    return result;
}

int Block::x(int index) const {
    return coords[index][0];
}

int Block::y(int index) const {
    return coords[index][1];
}

int Block::maxX() const {
    int max = coords[0][0];

    for (int i(1); i < 4; ++i) {
        max = qMax(max, coords[i][0]);
    }
    return max;
}

int Block::maxY() const {
    int max = coords[0][1];

    for (int i(1); i < 4; ++i) {
        max = qMax(max, coords[i][1]);
    }
    return max;
}

int Block::minX() const {
    int min = coords[0][0];

    for (int i(1); i < 4; ++i) {
        min = qMin(min, coords[i][0]);
    }

    return min;
}

int Block::minY() const {
    int min = coords[0][1];

    for (int i(1); i < 4; ++i) {
        min = qMin(min, coords[i][1]);
    }
    return min;
}

void Block::setX(int index, int x) {
    coords[index][0] = x;
}

void Block::setY(int index, int y) {
    coords[index][1] = y;
}
