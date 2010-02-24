#include "mainwindowimpl.h"
#include <iostream>
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	timer = new QTimer(this);
	joystick = new Joystick();
	connect( timer, SIGNAL(timeout()), this, SLOT(updateForm()));
	connect( btnConnect, SIGNAL(clicked()), this, SLOT(joyConnect()));
}

void MainWindowImpl::joyConnect() {
	if( joystick->init( joyDevBox->text().toAscii() ) > -1 ) {
		btnConnect->setText("Connected!");
		timer->start();
	}
}

void MainWindowImpl::updateForm() {
	lcdAxis1->display(joystick->getAxis(4));
	lcdAxis2->display(joystick->getAxis(5));
	lcdAxis3->display(joystick->getAxis(2));
	lcdAxis4->display(joystick->getAxis(3));
	if(joystick->getButton(0) > 0) {
		kled1->on();
		std::cout << "Button 1 Pressed" << std::endl;
	} else {
		kled1->off();
	}
	if(joystick->getButton(1) > 0) {
		kled2->on();
		std::cout << "Button 2 Pressed" << std::endl;
	} else {
		kled2->off();
		
	}
	if(joystick->getButton(2) > 0) {
		kled3->on();
		std::cout << "Button 3 Pressed" << std::endl;
	} else {
		kled3->off();
	}
	if(joystick->getButton(3) > 0) {
		kled4->on();
		std::cout << "Button 4 Pressed" << std::endl;
	} else {
		kled4->off();
	}
	if(joystick->getButton(4) > 0) {
		kled5->on();
		std::cout << "Button 5 Pressed" << std::endl;
	} else {
		kled5->off();
	}
	if(joystick->getButton(5) > 0) {
		kled6->on();
		std::cout << "Button 6 Pressed" << std::endl;
	} else {
		kled6->off();
	}
	if(joystick->getButton(6) > 0) {
		kled7->on();
		std::cout << "Button 7 Pressed" << std::endl;
	} else {
		kled7->off();
	}
	if(joystick->getButton(7) > 0) {
		kled8->on();
		std::cout << "Button 8 Pressed" << std::endl;
	} else {
		kled8->off();
	}
	if(joystick->getButton(8) > 0) {
		kled9->on();
		std::cout << "Button 9 Pressed" << std::endl;
	} else {
		kled9->off();
	}
	if(joystick->getButton(9) > 0) {
		kled10->on();
		std::cout << "Button 10 Pressed" << std::endl;
	} else {
		kled10->off();
	}
	if(joystick->getButton(10) > 0) {
		kled11->on();
		std::cout << "Button 11 Pressed" << std::endl;
	} else {
		kled11->off();
	}
	if(joystick->getButton(11) > 0) {
		kled12->on();
		std::cout << "Button 12 Pressed" << std::endl;
	} else {
		kled12->off();
	}
}