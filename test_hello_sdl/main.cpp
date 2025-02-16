#include <iostream>
#include <cmath>
#include <fstream>
#include <SDL2/SDL.h>



int main(int argc, char* argv[]){

//	fstream UART_port;
//	UART_port.open(port_name, ios::out);
	
	

	if(SDL_Init(SDL_INIT_JOYSTICK) < 0){
		std::cout << "SDL could not be initialized" << std::endl;
	}else{
		std::cout << "SDL joystick is ready to go \n";
	}

	SDL_Joystick* jsPlayer = nullptr;

	if(SDL_NumJoysticks() < 1){
		std::cout << "No js avail" << std::endl;
	}else{
		std::cout << SDL_NumJoysticks() << " js avail" << std::endl;
		jsPlayer = SDL_JoystickOpen(0);
	}

	int deadzone = 8000;
	
	int xValLeftJS = 0;
	int yValLeftJS = 0;
	int radius = 0;
	int angleDeg = 0;

	while(true){
		SDL_Delay(8);
		SDL_Event event;
		int i = 0;
		while(SDL_PollEvent(&event)){
			i++;
			if(i % 2 != 0){
				//std::cout << i << ": skipped" << std::endl;
				continue;
			}
			
			if(event.type == SDL_JOYAXISMOTION){
				if(event.jaxis.which == 0){
					
					if(event.jaxis.axis == 0){
						std::cout << "xAxis of Left JS: " << event.jaxis.value << std::endl;
						xValLeftJS = event.jaxis.value;
					}
					if(event.jaxis.axis == 1){
						std::cout << "yAxis of Left JS: " << event.jaxis.value << std::endl;
						yValLeftJS = -event.jaxis.value;
					}
					if(event.jaxis.axis == 2){
						std::cout << "xAxis of Right JS: " << event.jaxis.value << std::endl;
					}
					if(event.jaxis.axis == 3){
						std::cout << "yAxis of Right JS: " << event.jaxis.value << std::endl;
					}
					if(event.jaxis.axis == 4){
						std::cout << "Trigger assigned to axis 4: " << event.jaxis.value << std::endl;
					}
					if(event.jaxis.axis == 5){
						std::cout << "Trigger assigned to axis 5: " << event.jaxis.value << std::endl;
					}
					
					radius = sqrt(pow(xValLeftJS, 2) + pow(yValLeftJS, 2));
					//std::cout << "Radius = " << radius << std::endl;
					
					angleDeg = 180 / M_PI * atan2(yValLeftJS, xValLeftJS);
					//std::cout << "Angle in Degrees: " << angleDeg << std::endl;
					
				}

				//std::cout << event.jaxis.which << " js moved\n";
			}else if(event.type == SDL_JOYBUTTONDOWN){
				
				//XBOX CTRLR
				if(event.jbutton.which == 0){
					if(event.jbutton.button == 0){
						std::cout << "A" << std::endl;
					}
					if(event.jbutton.button == 1){
						std::cout << "B" << std::endl;
					}
					if(event.jbutton.button == 2){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 3){
						std::cout << "X" << std::endl;
					}
					if(event.jbutton.button == 4){
						std::cout << "Y" << std::endl;
					}
					if(event.jbutton.button == 5){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 6){
						std::cout << "Left Bumper" << std::endl;
					}
					if(event.jbutton.button == 7){
						std::cout << "Right Bumper" << std::endl;
					}
					if(event.jbutton.button == 8){
						std::cout << "cbutton 8" << std::endl;
					}
					if(event.jbutton.button == 9){
						std::cout << "cbutton 9" << std::endl;
					}
					if(event.jbutton.button == 10){
						std::cout << "Two Squares" << std::endl;
					}
					if(event.jbutton.button == 11){
						std::cout << "Menu" << std::endl;
					}
					if(event.jbutton.button == 12){
						std::cout << "XBOX Button" << std::endl;
					}
					if(event.jbutton.button == 13){
						std::cout << "Left Joystick Button" << std::endl;
					}
					if(event.jbutton.button == 14){
						std::cout << "Right Joystick Button" << std::endl;
					}
					if(event.jbutton.button == 15){
						std::cout << "Upload" << std::endl;
					}
					if(event.jbutton.button == 16){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 17){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 18){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 19){
						std::cout << "unknown" << std::endl;
					}
					if(event.jbutton.button == 20){
						std::cout << "unknown" << std::endl;
					}
				}
			}	
		}
	}

//	SDL_QUIT();
	return 0;
}

