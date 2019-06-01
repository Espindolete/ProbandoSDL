#include "Screen.h"
#include<iostream>
namespace mine {
	Screen::Screen():
		m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL) {

	}
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

		SDL_memset(m_buffer, 0, screenWidth * screenHeight * sizeof(Uint32));


		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer, screenWidth * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		/*
		if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight) {
			return;
		}*/

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
			if (event.type == SDL_QUIT) {
				return false;
			}
		
		return true;
	}
	void Screen::close() {
		delete[] m_buffer;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();


	}

}
