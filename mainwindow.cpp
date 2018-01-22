#include "mainwindow.h"
#include "mywidget.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
	angleLcd = new QLCDNumber(5);
	angleLcd->setSegmentStyle(QLCDNumber::Filled);
    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    linesLcd = new QLCDNumber(5);
    linesLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);

    widget = new myWidget( this ) ;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
	layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
	layout->addWidget(widget, 0, 1, 6, 1);
	layout->addWidget(createLabel(tr("ANGLE")), 0, 2);
	layout->addWidget(angleLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);

	layout->setColumnStretch(0, 10);
	layout->setColumnStretch(1, 80);
	layout->setColumnStretch(2, 10);

    setLayout(layout);

	connect(pauseButton, SIGNAL (clicked()), widget, SLOT (pause()));
	connect(startButton, SIGNAL(clicked()), widget, SLOT(start()));
	connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));

	connect(widget, SIGNAL(angleChanged(double)), angleLcd, SLOT(display(double))) ;
}

void MainWindow::handleButton()
{
	std::cerr << "handle Button" << std::endl ;

}

MainWindow::~MainWindow()
{
}

QLabel *MainWindow::createLabel(const QString &text) {
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
