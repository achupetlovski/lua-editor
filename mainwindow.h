#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCursor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AutoColorInitializer();
    void readFromFile(QString myFilePath);

private slots:
    void on_lineEdit_returnPressed();
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
    void tabulationCountCheck(int curr, QTextCursor tmp, QString word);

    void AutoColor();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
