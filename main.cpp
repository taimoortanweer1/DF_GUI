#include "df_gui_version_1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    df_gui_version_1 w;
    w.show();
    return a.exec();
}
