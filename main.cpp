#include "brows.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Brows w;
    QIcon wi("brow.jpg");
    w.setWindowIcon(wi);
    w.setMinimumWidth(480);
    w.show();

    return a.exec();
}
