#include<iostream>
#include<SDL.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include"Screen.h"
#include"Swarm.h"
using namespace std;


int main(int argc, char* argv[]) {

	srand(time(NULL));

	Screen screen;
	if (screen.init() == false) {
		std::cout << "Error iniatalizing SDL" << std::endl;
	}

	Swarm swarm;

	while (true)
	{
		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		unsigned char green = (unsigned char)((1 + cos(elapsed * 0.001)) * 128);
		unsigned char blue = (unsigned char)((1 + sin((elapsed * 0.001)-M_PI/2) * 128));
		const radian::Particle* const pParticles = swarm.getParticles();

		//screen.clear();


		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			radian::Particle particle = pParticles[i];
			int x = (particle.m_x+1)*Screen::screenWidth/2;
			int y = particle.m_y  * Screen::screenWidth/2+Screen::screenHeight/2;
			screen.setPixel(x, y, red,green,blue);
		}
		screen.boxBlur();

		screen.update();

		if (screen.processEvent()==false) {
			break;
		}
	}


	screen.close();
	return 0;

}