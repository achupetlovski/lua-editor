#include "tabulation.h"
#include "QtDebug"
#include "QtEvents"
#include "QKeyEvent"
#include "QApplication"

tabulation::tabulation(QWidget *parent) : QWidget(parent)
{

}

void tabulation::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Enter)
    {
    }
}

void tabulation::keyReleaseEvent(QKeyEvent *event)
{
    if(event -> key() == Qt::Key_Enter)
    {
    }
}
