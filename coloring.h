//#include "mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QString>

#ifndef COLOR_H
#define COLOR_H

class color{
public:
    void setName(QString name) { keyword_name = name; }
    void setColor(QString color) { keyword_color = color; }
    QString getKeyWordName() { return keyword_name;}
    QString getKeyWordColor() { return keyword_color; }

private:
    QString keyword_name;
    QString keyword_color;
};

#endif // COLOR_H
