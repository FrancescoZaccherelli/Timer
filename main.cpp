#include "Data.h"
#include "Tempo.h"
#include "Timer.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QString>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("App");
    window.resize(200, 100);
    window.show();

    QLabel label(&window);
    label.setText("00:00:00");
    label.move(100, 50);
    label.show();

    return app.exec();
}