#include <QtGui>
#include "gameboard.h"
#include "gamewindow.h"

GameWindow::GameWindow() {
    //main tetris game board
    gameBoard = new GameBoard;

    //main controls initialization
    nextBlockLabel = new QLabel;
    nextBlockLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextBlockLabel->setAlignment(Qt::AlignCenter);
    gameBoard->setNextBlockLabel(nextBlockLabel);

    startBtn = new QPushButton("Start");
    pauseBtn = new QPushButton("Pause");
    exitBtn = new QPushButton("Exit");

    //game indicators
    playerScoresLabel = new QLabel;
    playerScoresLabel->setNum(0);
    currentLevelLabel = new QLabel;
    currentLevelLabel->setNum(0);
    linesLabel = new QLabel;
    linesLabel->setNum(0);

    //setup main controls
    startBtn->setFocusPolicy(Qt::NoFocus);
    pauseBtn->setFocusPolicy(Qt::NoFocus);
    exitBtn->setFocusPolicy(Qt::NoFocus);

    //slot/signal connections,
    QObject::connect(startBtn, SIGNAL(clicked()), gameBoard, SLOT(start()));
    QObject::connect(pauseBtn, SIGNAL(clicked()), gameBoard, SLOT(pause()));
    QObject::connect(exitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(gameBoard, SIGNAL(playerScoreChanged(int)), playerScoresLabel, SLOT(setNum(int)));
    QObject::connect(gameBoard, SIGNAL(currentLevelChanged(int)), currentLevelLabel, SLOT(setNum(int)));
    QObject::connect(gameBoard, SIGNAL(linesRemovedChanged(int)), linesLabel, SLOT(setNum(int)));

    //main window layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel("Next block"), 0, 0);
    layout->addWidget(nextBlockLabel, 1, 0);
    layout->addWidget(createLabel("Level:"), 2, 0);
    layout->addWidget(currentLevelLabel, 3, 0);
    layout->addWidget(startBtn, 4, 0);
    layout->addWidget(gameBoard, 0, 1, 6, 1);
    layout->addWidget(createLabel("Scores:"), 0, 2);
    layout->addWidget(playerScoresLabel, 1, 2);
    layout->addWidget(createLabel("Lines removed:"), 2, 2);
    layout->addWidget(linesLabel, 3, 2);
    layout->addWidget(exitBtn, 4, 2);
    layout->addWidget(pauseBtn, 5, 2);
    setLayout(layout);
    setWindowTitle("QTetris");
    resize(550, 370);
}

QLabel *GameWindow::createLabel(const QString &text) {
    QLabel *label = new QLabel(text);
    QFont font = label->font();
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}
