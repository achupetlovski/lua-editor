#ifndef TABULATION_H
#define TABULATION_H

#include <QWidget>
#include <QtGui>

class tabulation : public QWidget
{
    Q_OBJECT
public:
    tabulation(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    //QLabel *myLabel;
    //QVBoxLayout *mainLayout;
};

#endif // TABULATION_H
