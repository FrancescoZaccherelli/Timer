#include <QApplication>
#include <QMessageBox>

#include "Data.h"
#include "Gui.h"
#include "Tempo.h"
#include "Timer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

        try {
            Data data(28, 2, 2025);
            Tempo tempo(23, 59, 56);
            Timer timer(0, 0, 10);
            Gui window(data, tempo, timer);
            window.show();
            return app.exec();
        }catch (std::invalid_argument& e) {
            QMessageBox::critical(nullptr, "Errore", e.what());
        }


}