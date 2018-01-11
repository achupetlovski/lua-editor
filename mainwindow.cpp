#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QStringList>

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

        QString myTextString = ui->textEdit->toPlainText();

        //qDebug() << "My text so far:\n" << myTextString;


        QStringList stringList = myTextString.split(",",QString::SkipEmptyParts);

        /*
         for (int i = 0; i < stringList.size(); i++){

                    qDebug() << stringList.at(i);
        }*/

        QTextCursor tmp = ui->textEdit->textCursor();
        //int tempInt = ui->textEdit->textCursor().position();

        //int tempInt2 = tempInt-1;

        tmp.select(QTextCursor::WordUnderCursor);
        QString word = tmp.selectedText();

        word = word + "<br>";

        tmp.insertHtml(word);
        qDebug("Word inserted...");

        //qDebug() << word;


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



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
}
