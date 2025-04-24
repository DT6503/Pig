#pragma once  // Защита от двойного включения

#ifndef PIGBUTTON_H
#define PIGBUTTON_H

#include <QPushButton>
#include <QComboBox>


// Класс для кнопки-свинки
class PigButton : public QPushButton {
    Q_OBJECT  // Макрос для использования сигналов и слотов

public:
    // Конструктор
    explicit PigButton(QWidget* parent = nullptr);
    // void updateCharacter(QString& character);

signals:
    // Сигнал, который будет испускаться при клике на кнопку
    void pigClicked();

private slots:
    // Слот, который будет вызываться при клике на кнопку
    void onClicked();
};

#endif // PIGBUTTON_H
