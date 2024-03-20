#include "win.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Win win(0);
    win.show();
    return app.exec();
}
