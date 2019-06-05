#include "Screen.h"
#include<iostream>

	Screen::Screen():
		m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL),
		m_buffer2(NULL) {
	}

	void Screen::boxBlur() {
		Uint32* temp = m_buffer;
		m_buffer = m_buffer2;
		m_buffer2 = temp;

		for (int i = 0; i < screenWidth; i++)
		{
			for (int j = 0; j < screenHeight; j++)
			{
				int redTotal = 0;
				int blueTotal = 0;
				int greenTotal = 0;
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++)
					{
						int currentX = i + x;
						int currentY = j + y;
						if (currentX > 0 && currentX < screenWidth && currentY>0 && currentY < screenHeight) {
							Uint32 color = m_buffer2[currentX + currentY * screenWidth];
							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;
							redTotal += red;
							greenTotal += green;
							blueTotal += blue;
						}

					}
				}

				setPixel(i, j, redTotal / 9, greenTotal / 9, blueTotal / 9);
			}

		}
	}

	/*
	void Screen::clear() {
		SDL_memset(m_buffer, 0, screenWidth * screenHeight * sizeof(Uint32));
		SDL_memset(m_buffer2, 0, screenWidth * screenHeight * sizeof(Uint32));
	}
	*/

	bool Screen::init() {
		const int screenWidth = 800;
		const int screenHeight = 600;
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}
		m_window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, screenWidth, screenHeight);

		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		m_buffer = new Uint32[screenWidth * screenHeight];
		m_buffer2 = new Uint32[screenWidth * screenHeight];
		SDL_memset(m_buffer, 0, screenWidth * screenHeight * sizeof(Uint32));
		SDL_memset(m_buffer2, 0, screenWidth * screenHeight * sizeof(Uint32));
		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer, screenWidth * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		
		if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight) {
			return;
		}

		Uint32 color = red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;
		m_buffer[x + (y * screenWidth)] = color;
	}


	bool Screen::processEvent() {
		SDL_Event event;
		while(SDL_PollEvent(&event))
			if (event.type == SDL_QUIT) {
				return false;
			}
		
		return true;
	}
	void Screen::close() {
		delete[] m_buffer;
		delete[] m_buffer2;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();


	}

