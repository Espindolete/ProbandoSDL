#include<iostream>
//#include<SDL.h>
//#include<math.h>
//#include<stdlib.h>
//#include<iomanip>
////#include"Screen.h"
////#include"Swarm.h"
using namespace std;
//using namespace mine;

int main(int argc, char* argv[]) {

	//srand(time(NULL));

	//mine::Screen screen;
	//if (screen.init() == false) {
		//std::cout << "Error iniatalizing SDL" << std::endl;
	//}
/*
	mine::Swarm swarm;

	while (true)
	{

		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char green = red;
		unsigned char blue = red;
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x+1)*Screen::screenWidth/2;
			int y = (particle.m_y + 1) * Screen::screenHeight/2;
			screen.setPixel(x, y, red,green,blue);
		}

		//screen.update();
		/*
		if (screen.processEvent()==false) {
			break;
		}
	}
	*/

	//screen.close();
	return 0;

}