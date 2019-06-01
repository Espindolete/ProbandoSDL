#include "Swarm.h"
namespace mine {

	Swarm::Swarm() {
		m_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_particles;
	}

}