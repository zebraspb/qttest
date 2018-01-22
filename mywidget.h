#ifndef __MYWIDGET_H__
#define __MYWIDGET_H__

#include <QtWidgets>
#include <QPainter>
#include <QColor>
#include <QBasicTimer>

class myWidget : public QWidget {
	Q_OBJECT
public:

	explicit myWidget( QWidget *parent = 0 ) ;
	~myWidget( ) ;

	void refresh( ) ;

	void paintEvent( QPaintEvent* ) override ;
	void timerEvent(QTimerEvent *event) override;

//	void keyPressEvent( QKeyEvent* e );
//	void keyReleaseEvent( QKeyEvent* e );

//	void drawBlock( int xPoints, int yPoints, int type, QPainter* painter );

signals:
	void angleChanged( double angle ) ;

public slots:
	void start();
	void pause();

private:

	const int minCircleRadPixels = 200 ;
	int curwidth ;
	int curheight ;

	double angle ;
	int peakcount ;

	const QColor BACKGROUND_COLOR = Qt::black;
	const QColor DEBUG_GRID_COLOR = Qt::gray;

	const int timeoutTime = 20 ; // ms

	QBasicTimer timer;
};

#endif // MYWIDGET_H

