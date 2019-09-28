//
// Created by Mark Hsu on 2019-09-25.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int pos[8] = {7, 15, 23, 31, 39, 47, 55, 63};

int getRow(int piece) {
    for (int i = 0; i < 8; i++) {
        if ((pos[i] - piece) < 8 && pos[i] - piece >= 0) {
            return i;
        }
    }
}

int getColumn(int piece) {
    return piece % 8;
}

int isBound(int king) {
    if (king < 8) // top
        return 1;
    else if (king % 8 == 0) // left
        return 2;
    else if ((king + 1) % 8 == 0) // right
        return 3;
    else if (king > 55 && king < 64) // bottom
        return 4;

    return -1;
}

bool isIllegalMove(int king, int queen, int queenMove) {
    int rowKing, colKing, rowQMove, colQMove, rowQueen, colQueen;

    rowKing = getRow(king);
    colKing = getColumn(king);
    rowQMove = getRow(queenMove);
    colQMove = getColumn(queenMove);
    rowQueen = getRow(queen);
    colQueen = getColumn(queen);

    if (king == queenMove)
        return true;
    else if (queen == queenMove)
        return true;

    if (colQueen != colQMove && (rowQueen != rowQMove))
        return true;
    else if (colQueen == colQMove && (rowQueen == rowQMove))
        return true;

    if ((rowKing == rowQMove && rowQMove == rowQueen) || (colKing == colQMove && colQMove == colQueen)) {
        if (queen > king && king > queenMove)
            return true;
        if (queenMove > king && king > queen)
            return true;
    }

    return false;
}

bool isNotAllowed(int king, int queenMove) {
    // check if queen move nearby to king
    if (king - 8 == queenMove && isBound(king) != 1)
        return true;
    else if (king - 1 == queenMove && isBound(king) != 2)
        return true;
    else if (king + 1 == queenMove && isBound(king) != 3)
        return true;
    else if (king + 8 == queenMove && isBound(king) != 4)
        return true;

    return false;
}

bool isCheck(int k, int q) {
    if ((k == 0 && q == 9) ||
        (k == 7 && q == 14) ||
        (k == 56 && q == 49) ||
        (k == 63 && q == 54)) {
        return true;
    }
    return false;
}

int main() {
    const string result[5] = {"Illegal state", "Illegal move", "Move not allowed", "Continue", "Stop"};
    int king, queen, queenMove;

    while (cin >> king >> queen >> queenMove) {
        if (king == queen) {
            cout << result[0] << endl;
        } else if (isCheck(king, queenMove)) {
            cout << result[4] << endl;
        } else if (isIllegalMove(king, queen, queenMove)) {
            cout << result[1] << endl;
        } else if (isNotAllowed(king, queenMove)) {
            cout << result[2] << endl;
        } else {
            cout << result[3] << endl;
        }
    }
}