#include "pigbutton.h"

// Конструктор класса PigButton
PigButton::PigButton(QWidget* parent)
    : QPushButton(parent)  // Инициализируем базовый класс QPushButton
{
    setText("🐖");  // Устанавливаем текст на кнопке
    // setText("🐀");  // Устанавливаем текст на кнопке


    QFont pfont = font();
    pfont.setPointSizeF(75);  // Устанавливаем размер шрифта
    setFont(pfont);  // Применяем шрифт к кнопке


    connect(this, &QPushButton::clicked, this, &PigButton::onClicked);  // Подключаем сигнал нажатия к слоту
}

//void PigButton::updateCharacter(QString& character) {
//    // Устанавливаем символ в зависимости от выбранного персонажа
//    if (character == "Pig")
//    {
//        setText("🐖");  // Устанавливаем текст для свинки
//    }
//    else if (character == "Rat")
//    {
//        setText("🐀");  // Устанавливаем текст для крысы
//    }
//    else if (character == "Sheep")
//    {
//        setText("🐑");  // Устанавливаем текст для овцы
//    }
//    else if (character == "Cow")
//    {
//        setText("🐄");  // Устанавливаем текст для коровы
//    }
//    else if (character == "Horse")
//    {
//        setText("🐎");  // Устанавливаем текст для лошади
//    }
//
//    // Настраиваем шрифт для символа
//    QFont pfont = font();
//    pfont.setPointSizeF(75);
//    setFont(pfont);
//}


// Реализация слота onClicked
void PigButton::onClicked() {
    emit pigClicked();  // Испускаем сигнал pigClicked, когда кнопка нажата
}


