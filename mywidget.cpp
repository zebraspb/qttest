#include "mywidget.h"

#include <QPointF>
#include <QLineF>

#include <iostream>
#include <utility>

namespace {
	static inline double toRad( double phi ) {
		return phi / 180 * M_PI ;
	}
}


myWidget::myWidget( QWidget *parent )
	: QWidget( parent ), angle( 0 ), peakcount( 5 )
{

	curheight = curwidth = minCircleRadPixels * 2 + minCircleRadPixels / 10 ;

//	resize( curwidth, curheight ) ;

	setMinimumSize( curwidth, curheight ) ;
	setMaximumSize ( 1000000, 1000000 ) ;


//	curheight = this->geometry().height() ;
//	curwidth = this->geometry().width() ;

//	QRect screenGeometry = QApplication::desktop()->screenGeometry();
//	int x = (screenGeometry.width() - width) / 2;
//	int y = (screenGeometry.height() - height) / 2;
//	move(x, y);
}


myWidget::~myWidget( ) {

}

void myWidget::refresh( ) {
	repaint( ) ;
}

void myWidget::timerEvent(QTimerEvent *event) {
	angle += 1 ;
	if( angle >= 360 ) angle -= 360 ;
	emit angleChanged( angle ) ;
	update( ) ;
}

void myWidget::start( ) {
	timer.start( timeoutTime, this ) ;
}

void myWidget::pause( ) {
	timer.stop( ) ;
}

void myWidget::paintEvent( QPaintEvent* ) {
	QPainter painter( this );
	//painter.fillRect( 0, 0, width, height, BACKGROUND_COLOR );
	std::pair<double, double>center( this->width()/2, this->height()/2 ) ;

	painter.fillRect( center.first -this->width() / 2, center.second - this->height() / 2, this->width(), this->height(), BACKGROUND_COLOR ) ;
	painter.setPen( Qt::red ) ;

	QPointF pointC( center.first, center.second ) ;
	painter.drawEllipse( pointC, this->width( ) / 2, this->height( ) / 2 ) ;

//	painter.rotate( angle );

	double step = 360.0 / peakcount ;
	double phi = -90 + angle ;

	QVector<QPointF> peaks_coord ;
	peaks_coord.reserve( peakcount ) ;
	for( auto i = 0; i < peakcount; ++i ) {
		double x = this->width( ) / 2 * cos( toRad( phi ) ) ;
		double y = this->height( ) / 2 * sin( toRad( phi ) ) ;
		QPointF point( x + center.first,
					   y + center.second ) ;
		peaks_coord.push_back( point ) ;
		phi += step ;
	}

	QVector<QLineF> peaks ;
	peaks.reserve( peakcount ) ;

	auto second = 2 ;
	for( auto first = 0; first < peakcount; ) {
		QLineF line( peaks_coord.at( first ), peaks_coord.at( second ) ) ;

		peaks.push_back( line );

		++first ;
		++second ;
		if( second == peakcount ) second = 0 ;
	}

	painter.drawLines( peaks ) ;



}

//void myWidget::keyPressEvent( QKeyEvent* e ) {

//}

//void myWidget::keyReleaseEvent( QKeyEvent* e ) {

//}

//void myWidget::drawBlock( int xPoints, int yPoints, int type, QPainter* painter ) {

//}


