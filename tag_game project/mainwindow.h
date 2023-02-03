#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

    void openFile();
    void gameIsOver();

private:

    QPushButton * btnNewGame;    
    QPushButton * btnQuit;
    QImage * image;

};

#endif // MAINWINDOW_H
