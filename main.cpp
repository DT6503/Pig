#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    GameWindow window;
    window.show();  // Отображаем главное окно

    return app.exec();  // Запускаем главный цикл приложения
}
