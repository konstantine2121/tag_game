#include "mainwindow.h"
#include "gamefieldwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(380,400);
    setWindowTitle(QString::fromUtf8("  Пятнашки"));

    btnNewGame= new QPushButton(QString::fromUtf8("Новая игра"));
    btnQuit= new QPushButton(QString::fromUtf8("Выход"));

    gameFieldWidget * gameWidget = new gameFieldWidget();
    gameWidget->setStyleSheet("gameFieldWidget { background-color : red; color : blue; }");
    gameWidget->setFixedSize(360,360);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    QHBoxLayout * buttonsLayout = new QHBoxLayout;

    buttonsLayout->addWidget(btnNewGame);
    buttonsLayout->addWidget(btnQuit);

    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(gameWidget);

    setLayout(mainLayout);

    connect(btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(btnNewGame,SIGNAL(clicked(bool)),gameWidget,SLOT(startNewGame()));
    connect(gameWidget,SIGNAL(gameOver()),this,SLOT(gameIsOver()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,   tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    image =new QImage(fileName);
}

void MainWindow::gameIsOver()
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromUtf8( "Победа!"));
    msgBox.setWindowTitle(" ");
    msgBox.exec();
}

