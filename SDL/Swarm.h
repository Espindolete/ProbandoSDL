#pragma once
#include"Particle.h"

class Swarm
{
public:
	const static int NPARTICLES=5000;
private:
	radian::Particle* m_particles;
	int lastTime;

public:
	Swarm();
	~Swarm();
	void update(int elapsed);
	const radian::Particle* const getParticles() { return m_particles; };
};
