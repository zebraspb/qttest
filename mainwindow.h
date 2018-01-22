#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QLabel>


class myWidget ;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLabel *createLabel(const QString &text) ;

public slots:
    void handleButton( ) ;

private:
    QLabel 		*nextPieceLabel;
	QLCDNumber 	*angleLcd;
    QLCDNumber 	*levelLcd;
    QLCDNumber 	*linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;

    myWidget *widget ;

};

#endif // MAINWINDOW_H
