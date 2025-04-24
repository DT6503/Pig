#include "mainwindow.h"
//#include <QVBoxLayout>
#include <QRandomGenerator>
//#include <QMediaPlaylist>



GameWindow::GameWindow(QWidget* parent) : QWidget(parent), score(0), timeRemaining(30)
{
    resize(1422,800);

    scoreLabel = new QLabel("Score: 0", this);
    timeLabel = new QLabel("Time Left: 30", this);
    startButton = new QPushButton("Start Game", this);

    startButton->setFixedSize(380, 150);
    startButton->move(545, 350);
    QFont bfont = startButton->font();
    bfont.setPointSizeF(35);
    startButton->setFont(bfont);


    timeLabel->move(270, 29);
    QFont timeFont = timeLabel->font();
    timeFont.setPointSizeF(25);
    timeLabel->setFont(timeFont);
    timeLabel->setFixedSize(230, 90);


    // scoreLabel->setFixedSize(100, 50);
    scoreLabel->move(30, 30);
    QFont font = scoreLabel->font();
    font.setPointSizeF(25);
    scoreLabel->setFont(font);
    scoreLabel->setFixedSize(260, 90);

    //startButton->setGeometry(50, 50, 300, 50);

    gameTimer = new QTimer(this);
    pigTimer = new QTimer(this);  // Таймер для появления свинок

    /*QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(scoreLabel);
    layout->addWidget(startButton);*/

    //Думаю это не понадобиться
    //input = new QLineEdit(this);
    //input->setReadOnly(true);

    Level = new QComboBox(this);

    Level->addItems({ "Easy", "Middle", "Hard" });
    Level->setFixedSize(300, 90);
    Level->move(1100, 30);
    QFont lfont = Level->font();
    lfont.setPointSize(30);
    Level->setFont(lfont);
    Level->setStyleSheet("background-color: brown; color: white;");


    /* characterSelection->addItems({ "Pig", "Rat", "Sheep", "Cow", "Horse" });
    characterSelection->setFixedSize(300, 90);

    QFont comboFont = characterSelection->font();
    comboFont.setPointSize(30);
    characterSelection->setFont(comboFont);
    characterSelection->setStyleSheet("background-color: brown; color: white;");

    connect(characterSelection, &QComboBox::currentTextChanged, this, &GameWindow::updateCharacterSelection);*/
    connect(startButton, &QPushButton::clicked, this, &GameWindow::startGame);
    connect(gameTimer, &QTimer::timeout, this, &GameWindow::updateTime);
    connect(pigTimer, &QTimer::timeout, this, &GameWindow::createPigButton);



    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QPixmap("D:/Newpig/Pig/background.jpg")));
    this->setPalette(palette);


}

GameWindow::~GameWindow()
{
    clearPigs();
}

void GameWindow::startGame()
{
    startButton->hide();
    Level->hide();
    //characterSelection->hide();
    score = 0;
    scoreLabel->setText("Score: " + QString::number(score));
    clearPigs();

    timeRemaining = 30;
    gameTimer->start(1000);
    scheduleNextPig();
}

void GameWindow::createPigButton()
{

    // Удаляем старую кнопку перед созданием новой
    clearPigs();

    PigButton* pigButton = new PigButton(this);
    // pigButton->updateCharacter(selectedCharacter);


    int x = QRandomGenerator::global()->bounded(width() - pigButton->width());
    int y = QRandomGenerator::global()->bounded(height() - pigButton->height());

    pigButton->setFixedSize(130, 110);
    pigButton->move(x, y);
    pigButton->show();
    pigButtons.append(pigButton);

    connect(pigButton, &PigButton::pigClicked, this, &GameWindow::updateScore);

    scheduleNextPig();
}

void GameWindow::scheduleNextPig()
{
    QString time = Level->currentText();
    int interval{0};

    if (time == "Easy")
    {
        interval = QRandomGenerator::global()->bounded(1600, 2000);
        //pigTimer->start(interval);

    }
    else if (time == "Middle")
    {
        interval = QRandomGenerator::global()->bounded(1000, 1400);
        //pigTimer->start(interval);

    }
    else if (time == "Hard")
    {
        interval = QRandomGenerator::global()->bounded(100, 900);
        //pigTimer->start(interval);

    }
    pigTimer->start(interval);
}

void GameWindow::updateScore()
{
    score++;
    scoreLabel->setText("Score: " + QString::number(score));
}

void GameWindow::updateTime()
{
    timeRemaining--;
    timeLabel->setText("Time Left : " + QString::number(timeRemaining));

    if (timeRemaining <= 0) {
        endGame();
        startButton->show();
        startButton->setText("Play again? 🐷");
        Level->show();
        //characterSelection->show();

        QFont sfont = startButton->font();
        sfont.setPointSizeF(25);
        startButton->setFont(sfont);

    }
}

void GameWindow::endGame()
{
    gameTimer->stop();
    pigTimer->stop();
    clearPigs();
    scoreLabel->setText("Game Over!\nFinal Score: " + QString::number(score));
}

void GameWindow::clearPigs()
{
    for (auto pigButton : pigButtons) {
        pigButton->hide();
        pigButton->deleteLater();
    }
    pigButtons.clear();
}

//void GameWindow::updateCharacterSelection() {
//    selectedCharacter = characterSelection->currentText();
//}
