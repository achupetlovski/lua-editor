#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>


class keyEnterReceiver : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event)
    {
        if (event->type()==QEvent::KeyPress) {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
                //Enter or return was pressed

                qDebug() << "I pressed ENTER!\n";

            } else {
                return QObject::eventFilter(obj, event);
            }
            return true;
        } else {
            return QObject::eventFilter(obj, event);
        }
        return false;
    }
};


///the below works daniele bot takuv :D QJ KUR
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return)
    {
        // Special tab handling
        qDebug("Enter Key Pressed...");
        return true;
    }
    else
    {

    }
    }
    else
    {
        return QMainWindow::eventFilter(object, event);
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);

    ui->textEdit->installEventFilter(this);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Return:
            qDebug() << "I pressed enter\n" ;
            break;

        case Qt::Key_Enter:
            qDebug() << "I pressed enter\n" ;
            break;
        case Qt::Key_Up:
            qDebug() << "I pressed up key\n" ;
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::on_lineEdit_returnPressed()
{
    if(event -> key == Qt::Key_Enter)
    {

    }
}*/
