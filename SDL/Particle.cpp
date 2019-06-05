#include "Particle.h"
#include <math.h>
#include <stdlib.h>
#include <SDL_keycode.h>




namespace radian {

	void Particle::init(){
		m_x = 0;
		m_y = 0;
		m_direccion = 2 * M_PI * rand() / RAND_MAX;
		m_speed = (0.02 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}

	Particle::Particle():m_x(0),m_y(0) {
		init();
	}
	Particle::~Particle() {

	}

	void Particle::update(int interval) {
		m_direccion += interval *0.0002;
		double xspeed = m_speed * cos(m_direccion);
		double yspeed = m_speed * sin(m_direccion);
		m_x += xspeed*interval;
		m_y += yspeed*interval;


		if (m_x < -1 || m_x>1||m_y<-1||m_y>1) {
			init();
		}
		if (rand() < RAND_MAX / 100) {
			init();
		}
	}
}




namespace cartesian {

	Particle::Particle() :m_x(0), m_y(0) {

		m_xspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
		m_yspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
	}
	Particle::~Particle() {

	}

	void Particle::update() {
		

		m_x += m_xspeed;
		m_y += m_yspeed;
		if (m_x <= -1.0 || m_x >= 1.0) {
			m_xspeed = -m_xspeed;
		}
		if (m_y <= -1.0 || m_y >= 1.0) {
			m_yspeed = -m_yspeed;
		}
	}
}

