#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coloring.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>

QList<color> myList;

void MainWindow::readFromFile(QString myFilePath)
{
    QFile myFile(myFilePath);
    if(!myFile.open(QFile::ReadOnly | QFile::Text))
    {
            qDebug() << "Could not open file for reading at " << myFilePath;
            return;
    }

    QTextStream in(&myFile);

    QString mFileString = in.readAll();
    QStringList myStringList = mFileString.split(QRegExp("\n| "), QString::SkipEmptyParts);//.split(" |\n");

    ///so here every second word in the list is a color, and every first one is a keyword
    /// now to make a list from those

    int myStringList_count = myStringList.count();

    //qDebug() << "My STR list count: " << myStringList_count;
    int pen = 0;
    for(int i = 0; i < myStringList_count/2; i++)
    {
        //list.push_back(new color("asd","dsa"));  // myStringList[i],myStringList[i+1]
        color *mycolor = new color();
        //qDebug() << "\nmycolor->setName(myStringList[i]); gets value:" << myStringList[i];
        mycolor->setName(myStringList[pen]); pen++;
        //qDebug() << "mycolor->setColor(myStringList[i+1]); gets value:" << myStringList[i+1];
        mycolor->setColor(myStringList[pen]); pen++;
        myList.push_back(*mycolor);
    }
    myFile.close();
    //here we now have the contents of the file keywords.conf into the QString mFileString.
    // and we must fill the table with it's contents
}

void MainWindow::AutoColorInitializer()
{
    //ask to read conf file or use default conf idk
    /*
    QString myPath = qApp->applicationDirPath() + "/conf";

    if(!QDir(myPath).exists())
    {
        //create
        QDir(myPath).mkpath(myPath);


        myPath = myPath + "/keywords.conf";

        if (QFileInfo(myPath).exists())
        {

            readFromFile(myPath);

        }
        else //if keywords file does not exist, create one
        {
            QFile mFile(myPath);
            if(!mFile.open(QFile::WriteOnly | QFile::Text))
            {
                    return;
            }

            if(default_coloring == true)
            {
                default lua coloring

            }

            mFile.flush();
            mFile.close();
            readFromFile(myPath);
        }
    }*/

    color *words1 = new color;
    words1->setColor("red"); words1->setName("or");

    color *words2 = new color;
    words2->setColor("green"); words2->setName("function");

    color *words3 = new color;
    words3->setColor("purple"); words3->setName("true");

    color *words4 = new color;
    words4->setColor("aqua"); words4->setName("then");

    color *words5 = new color;
    words5->setColor("blue"); words5->setName("repeat");

    color *words6 = new color;
    words6->setColor("orange"); words6->setName("while");

    color *words7 = new color;
    words7->setColor("yellow"); words7->setName("for");

    color *words8 = new color;
    words8->setColor("brown"); words8->setName("if");

    color *words9 = new color;
    words9->setColor("white"); words9->setName("function");

    color *words10 = new color;
    words10->setColor("teal"); words10->setName("elseif");

    color *words11 = new color;
    words11->setColor("green"); words11->setName("else");

    color *words12 = new color;
    words12->setColor("magenta"); words12->setName("do");

    color *words13 = new color;
    words13->setColor("cyan"); words13->setName("break");

    color *words14 = new color;
    words14->setColor("purple"); words14->setName("and");

    color *words15 = new color;
    words15->setColor("#ff9966"); words15->setName("until");

    color *words16 = new color;
    words16->setColor("#cd7f32"); words16->setName("not");

    color *words17 = new color;
    words17->setColor("#f4c2c2"); words17->setName("local");

    color *words18 = new color;
    words18->setColor("#fe6f5e"); words18->setName("end");

    color *words19 = new color;
    words19->setColor("#8a2be2"); words19->setName("in");

    color *words20 = new color;
    words20->setColor("#cb4154"); words20->setName("return");

    color *words21 = new color;
    words21->setColor("#8a2be2"); words21->setName("nil");

    color *words22 = new color;
    words22->setColor("#cb4154"); words22->setName("false");


    myList.push_back(*words1);
    myList.push_back(*words2);
    myList.push_back(*words3);
    myList.push_back(*words4);
    myList.push_back(*words5);
    myList.push_back(*words6);
    myList.push_back(*words7);
    myList.push_back(*words8);
    myList.push_back(*words9);
    myList.push_back(*words10);
    myList.push_back(*words11);
    myList.push_back(*words12);
    myList.push_back(*words13);
    myList.push_back(*words14);
    myList.push_back(*words15);
    myList.push_back(*words16);
    myList.push_back(*words17);
    myList.push_back(*words18);
    myList.push_back(*words19);
    myList.push_back(*words20);
    myList.push_back(*words21);
    myList.push_back(*words22);
}

void MainWindow::AutoColor()
{
    disconnect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(AutoColor()));

    QTextCursor tmp = ui->textEdit->textCursor();
    int tempInt = ui->textEdit->textCursor().position();

    tmp.select(QTextCursor::WordUnderCursor);
    QString word = tmp.selectedText();

    for (int i = 0; i < myList.count(); i++)
    {
        if(word==myList[i].getKeyWordName())
        {
           word="<font color="+ myList[i].getKeyWordColor() +">" + word + "</font>" + " ";
        }
    }

    //qDebug() << "What is being inserted? " << word << endl;

    ///Append the colorful things to the word
    tmp.insertHtml(word);
    tmp.setPosition(tempInt);

    ui->textEdit->setTextCursor(tmp);

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(AutoColor()));
}
