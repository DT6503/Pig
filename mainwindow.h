#pragma once

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QComboBox>
#include "pigbutton.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);
    ~GameWindow();

private slots:
    void startGame();
    void updateScore();
    void updateTime();
    void endGame();
    void clearPigs();
    void scheduleNextPig(); // Запланировать появление следующей свинки
    void createPigButton(); // Создание новой свинки
    // void updateCharacterSelection();

private:
    int score;
    int timeRemaining;

    QLabel* scoreLabel;
    QPushButton* startButton;
    QLabel* timeLabel;

    QTimer* gameTimer;  // Таймер для общего времени игры
    QTimer* pigTimer;   // Таймер для появления свинок

    QList<PigButton*> pigButtons;

    QLineEdit* input;
    QComboBox* Level;

    // QComboBox* characterSelection;
    // QString selectedCharacter;

};

#endif // GAMEWINDOW_H

