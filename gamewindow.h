#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
/*
#include <QFrame>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
*/
#include <QtGui>

class GameBoard;

class GameWindow : public QWidget {
    Q_OBJECT

public:
    GameWindow();

private:
    QLabel *nextBlockLabel;
    QLabel *playerScoresLabel;
    QLabel *linesLabel;
    QLabel *currentLevelLabel;
    GameBoard *gameBoard;
    QPushButton *startBtn;
    QPushButton *pauseBtn;
    QPushButton *exitBtn;

    QLabel *createLabel(const QString &text);
};

#endif // GAMEWINDOW_H
