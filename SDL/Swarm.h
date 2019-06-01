#pragma once
#include"Particle.h"

class Swarm
{
public:
	const static int NPARTICLES=10000;
private:
	Particle* m_particles;

public:
	Swarm();
	~Swarm();

	const Particle* const getParticles() { return m_particles; };
};
