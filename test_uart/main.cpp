#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
//#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

	char port[] = "/dev/ttyUSB0";

	//int serial_port = open("../../devices70006040.serial/tty/ttyTHS1", O_RDWR | O_NONBLOCK);
	int serial_port = open(port, O_RDWR | O_NONBLOCK);
	
	if(serial_port < 0){
		std::cout << "Couldn't open file" << std::endl;
		return 1;
	}
	
	struct termios tty;
	
	if(tcgetattr(serial_port, &tty) != 0){
		//std::cout << "error from tcgetattr " << tcgetattr(serial_port, &tty) << std::endl;
		
		//printf("Error %i from tcgettattr: %s\n", errno, strerror(errno));
		
		return -1;
	}
	
	tty.c_cflag &= ~PARENB;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CSIZE;
	tty.c_cflag |= CS8;
	tty.c_cflag &= ~CRTSCTS;
	tty.c_cflag |= CREAD | CLOCAL;
	
	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO;
	tty.c_lflag &= ~ECHOE;
	tty.c_lflag &= ~ECHONL;
	tty.c_lflag &= ~ISIG;
	tty.c_lflag &= ~(IXON | IXOFF | IXANY);
	tty.c_lflag &= ~(IGNBRK | BRKINT| PARMRK| ISTRIP| INLCR| IGNCR| ICRNL);
	
	tty.c_oflag &= ~OPOST;
	tty.c_oflag &= ~ONLCR;
	
	tty.c_cc[VTIME] = 10;
	tty.c_cc[VTIME] = 0;
	
	cfsetispeed(&tty, B115200);
	cfsetospeed(&tty, B115200);
	
	if(tcsetattr(serial_port, TCSANOW, &tty) != 0) {
		//std::cout << "Error from tcsetattr " << tcsetattr(serial_port, TCSANOW, &tty) << std::endl;
		
		//printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
		
		return -1;
	}
	
	

	std::fstream UARTArduino;
	
	UARTArduino.open(port, std::ios::out);
	
	if(!UARTArduino.is_open()){
		std::cout << "Port not open" << std::endl;
		return -1;
	}
	
	
	for(int i = 0; i < 100; i++){
		UARTArduino << "Hello Arduino" << std::endl;
		std::cout << "Sent" << std::endl;
	}

	std::cout << "Sent 100 Hello Arduinos" << std::endl;
	
	UARTArduino.close();
		
	close(serial_port);
	
	
	
	
	return 0;
	
}
