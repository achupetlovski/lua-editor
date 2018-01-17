#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QStringList>
#include <QChar>
#include <QTextCursor>

///the below works daniele bot takuv :D QJ KUR
///
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return)
        {
        // Special tab handling
        //qDebug("\nEnter Key Pressed...");

        QTextCursor tmp = ui->textEdit->textCursor();
        //int tempInt = ui->textEdit->textCursor().position();


        tmp.select(QTextCursor::WordUnderCursor);
        QString word = tmp.selectedText();

        //word = word + "<br>";
        //tmp.insertHtml(word);


        QString tabulation1 = "&nbsp;";

        //QString myTextString = ui->textEdit->toPlainText();

        //qDebug() << "My text so far:\n" << myTextString;


        //QStringList stringList = myTextString.split(",",QString::SkipEmptyParts);

        /*
         for (int i = 0; i < stringList.size(); i++){

                    qDebug() << stringList.at(i);
        }*/


        //qDebug()<< "tempInt:" << tempInt;

        //newTempInt gets position of the cursor minus one
        int newTempInt = ui->textEdit->textCursor().position()-1;



        //char myChar = ui->textEdit->textCursor().
        //QChar currentChar = lineEdit->text().at(lineEdit->cursorPosition());


        /*qDebug() << "First level: " << endl <<
                    "newTempInt: " << newTempInt << endl;*/


        //This check lets us know if
        if(newTempInt>=0)
        {
            QChar myChar = ui->textEdit->toPlainText().at(newTempInt);
            /*
            if(myChar == '\n')
            {
                newTempInt--;
                myChar = ui->textEdit->toPlainText().at(newTempInt);
            }*/

            /*qDebug() << "Second level: " << endl <<
                        "newTempInt: " << newTempInt << endl <<
                        "myChar: " << myChar << endl;*/

            /*if(myChar == ')')
            {
                tmp.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor,1);
                tmp.movePosition(QTextCursor::Right,QTextCursor::MoveAnchor, 200);

                /// THIS ON THE TOP SHOULD BE WORKING BUT IT"S NOT DOING WhAT IM ASKING IT
                //QTextCursor tmp;
                //tmp.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor, 4);
                //setCursor(tmp);


                qDebug() << "I entered" << myChar;

            }*/


            if(myChar == '\t')
            {
                //qDebug() << "myChar is equal to tab";
                /// THE TAB HERE IS BEING DETECTED BUT WTF
                //tmp.select(QTextCursor::WordUnderCursor);
                //QString word = tmp.selectedText();


                //QChar tabulation2 = '\t';


                MainWindow::tabulationCountCheck(newTempInt, tmp, word);


                //word = "&nbsp;" + word;
                //word = tabulation + word;
                //qDebug() << "Word is: "<< word;
                //qDebug() << "tabulation1 is: "<< tabulation1;
                //qDebug() << "tabulation2 is: "<< tabulation2;

                //tmp.setPosition(newTempInt);


                /////// IMPLEMENT A CHECK HERE if the
                /// char before that is again a tab, if it is
                /// tab until the char before that is not a tab

                //tmp.insertHtml(tabulation1);

                //int tempInt2 = ui->textEdit->textCursor().position()-1;
                //int tempInt2 = ui->textEdit->textCursor().atStart();
                //QChar myChar2 = ui->textEdit->toPlainText().at(tempInt2);
                //qDebug() << "What did I insert just now?\n-" << myChar2;


                //tmp.insertHtml(tabulation2);
                //word = word + "<br>";
                //mp.insertHtml(word);

            }

            /*else if(myChar == '{')
            {
                word =  "<br>" + word;
                tmp.insertHtml(word);
                //tmp.insertHtml("<br>");

                tmp.select(QTextCursor::WordUnderCursor);
                //QString word = tmp.selectedText();

                tmp.insertHtml(tabulation1);

                int tempInt2 = ui->textEdit->textCursor().position();
                QChar myChar2 = ui->textEdit->toPlainText().at(tempInt2);
                qDebug() << "What did I insert just now?\n-" << myChar2;

                /*
                tmp.setPosition(tempInt);
                qDebug() << "My Pos = " << tempInt;
                qDebug() << "tabulation1 is: "<< tabulation1;
                tmp.insertHtml(tabulation1);
                qDebug() << "Word inserted: " << word;
            }
            */
            else
            {
                word = word + "<br>";
                tmp.insertHtml(word);
            }
        }
        else
        {
            word = word + "<br>";
            tmp.insertHtml(word);
        }

        //int tempInt2 = tempInt-1;



        ///
        /// the below adds a newline
        ///
        /*
        tmp.select(QTextCursor::WordUnderCursor);
        QString word = tmp.selectedText();

        word = word + "<br>";
        tmp.insertHtml(word);
        */
        ///
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

    AutoColorInitializer();
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(AutoColor()));


}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
}

void MainWindow::tabulationCountCheck(int curr, QTextCursor tmp, QString word)
{
    QChar myChar = ui->textEdit->toPlainText().at(curr);

    tmp.setPosition(curr);
    tmp.insertHtml("&nbsp;");

    word = word + "<br>";
    tmp.insertHtml(word);

    qDebug() << "Third level: " << endl <<
                "curr: " << curr << endl <<
                "myChar: " << myChar << endl;


    if(curr=='\t')
    {
        MainWindow::tabulationCountCheck(curr-1, tmp, word);
    }
    else return;
}
