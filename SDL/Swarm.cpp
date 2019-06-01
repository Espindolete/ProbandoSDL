#include "Swarm.h"


	Swarm::Swarm() {
		m_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_particles;
	}

