#pragma once


namespace radian {
	struct Particle {
		double m_x;
		double m_y;

	private:
		double m_direccion;
		double m_speed;

	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	private:
		void init();
	};

}


namespace cartesian{

	struct Particle {
		double m_x;
		double m_y;
		double m_xspeed;
		double m_yspeed;

	public:
		Particle();
		virtual ~Particle();
		void update();
	};
}
