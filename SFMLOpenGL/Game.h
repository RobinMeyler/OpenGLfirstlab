#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "MyVector3.h"

using namespace std;
using namespace sf;

enum class m_shape
{
	triangle,
	trianlgeStrip,
	triangleFan,
	quad,
	quadStrip,
	line,
	lineStrip,
	lineLoop,
	poly
};

class Game
{
public:
	Game();
	~Game();
	void run();
	void checkInput();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	MyVector3 M_triangleTurner[3];
	 // Uncomment for Part 2
	 // ********************
	 const int primatives;
	
	m_shape gameShapes = m_shape::triangle;
	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	 // ********************
};