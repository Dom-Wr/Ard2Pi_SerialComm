#include "comm_window.h"
#include "ui_comm_window.h"

Comm_Window::Comm_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Comm_Window)
{
    ui->setupUi(this);
}

Comm_Window::~Comm_Window()
{
    delete ui;
}
