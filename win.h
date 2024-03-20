#ifndef WIN_H
#define WIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Win; }
QT_END_NAMESPACE

class Win : public QWidget
{
    Q_OBJECT

public:
    Win(QWidget *parent = nullptr);
    ~Win();

private:
    Ui::Win *ui;
};
#endif // WIN_H
