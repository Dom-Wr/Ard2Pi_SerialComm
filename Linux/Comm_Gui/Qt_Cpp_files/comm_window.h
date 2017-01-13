#ifndef COMM_WINDOW_H
#define COMM_WINDOW_H

#include <QMainWindow>

namespace Ui {
class Comm_Window;
}

class Comm_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Comm_Window(QWidget *parent = 0);
    ~Comm_Window();

private:
    Ui::Comm_Window *ui;
};

#endif // COMM_WINDOW_H
