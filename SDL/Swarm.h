#pragma once
#include"Particle.h"
namespace mine {
class Swarm
{
public:
	const static int NPARTICLES=5000;
private:
	Particle* m_particles;

public:
	Swarm();
	~Swarm();

	const Particle* const getParticles() { return m_particles; };
};
}