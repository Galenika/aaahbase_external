#pragma once

class Misc {
public:
	static void Bhop();
}; 
class Visuals {
public:
	static void Chams();
	static void noFlash();
};
struct Color {
	int r;
	int g;
	int b;
	int a;
};

extern Visuals *pVisuals;
extern Misc *pMisc;