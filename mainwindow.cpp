#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QStringList>
#include <QChar>

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
        int tempInt = ui->textEdit->textCursor().position();

        //qDebug()<< "tempInt:" << tempInt;

        int newTempInt = ui->textEdit->textCursor().position()-1;

        //char myChar = ui->textEdit->textCursor().
        //QChar currentChar = lineEdit->text().at(lineEdit->cursorPosition());

        if(newTempInt>0)
        {
            QChar myChar = ui->textEdit->toPlainText().at(newTempInt);


            qDebug() << "myChar is:" << myChar;


            if(myChar == '\t')
            {
                qDebug() << "myChar is equal to tab";

                tmp.select(QTextCursor::WordUnderCursor);
                QString word = tmp.selectedText();

                QString tabulation1 = "&nbsp;";
                QChar tabulation2 = '\t';


                //word = "&nbsp;" + word;
                //word = tabulation + word;
                qDebug() << "Word is: "<< word;
                qDebug() << "tabulation1 is: "<< tabulation1;
                qDebug() << "tabulation2 is: "<< tabulation2;

                tmp.setPosition(newTempInt);


                tmp.insertHtml(tabulation1);
                tmp.insertHtml(tabulation2);
            }
        }
        //int tempInt2 = tempInt-1;

        tmp.select(QTextCursor::WordUnderCursor);
        QString word = tmp.selectedText();

        word = word + "<br>";

        tmp.insertHtml(word);
        //qDebug("Word inserted...");

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
