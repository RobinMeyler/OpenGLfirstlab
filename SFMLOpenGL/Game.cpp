#include <Game.h>

 // Uncomment for Part 2
 // ********************
bool flip = false;
int current = 1;
// // ********************
//Game::Game() : window(VideoMode(800, 600), "OpenGL") 
//{
//
//	index = glGenLists(primatives);
//}


Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(1)
{
	 // Uncomment for Part 2
	 // ********************
	 index = glGenLists(primatives);
	


	 // ********************
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			
		}
		update();
		draw();
	}

}



void Game::initialize()
{
	isRunning = true;

	 // Uncomment for Part 2
	 // ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	M_triangleTurner[0] = { 0.0, 2.0, -5.0 };
	M_triangleTurner[1] = { -2.0, -2.0, -5.0 };
	M_triangleTurner[2] = { 2.0, -2.0, -5.0 };
	
	
	
	



	 // Uncomment for Part 2
	 // ********************
}

void Game::update()
{

	 // Uncomment for Part 2
	 // ********************
	elapsed = clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 3; i++)
		{
			(M_triangleTurner[i].x) = (M_triangleTurner[i].x) - 0.01;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 3; i++)
		{
			(M_triangleTurner[i].x) = (M_triangleTurner[i].x) + 0.01;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 3; i++)
		{
			(M_triangleTurner[i].z) = (M_triangleTurner[i].z) - 0.01;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 3; i++)
		{
			(M_triangleTurner[i].z) = (M_triangleTurner[i].z) + 0.01;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
			for (int i = 0; i < 3; i++)
			{
				(M_triangleTurner[i].y) = (M_triangleTurner[i].z) + 0.01;
			}
	}
	

	checkInput();

	if (gameShapes == m_shape::triangle)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		{

			glVertex3f(M_triangleTurner[0].x, M_triangleTurner[0].y, M_triangleTurner[0].z);
			glVertex3f(M_triangleTurner[1].x, M_triangleTurner[1].y, M_triangleTurner[1].z);
			glVertex3f(M_triangleTurner[2].x, M_triangleTurner[2].y, M_triangleTurner[2].z);
			glColor3f(0.0f, 0.0f, 1.0f);

		}
		glEnd();
		glEndList();

		glNewList(index + 1, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.2, 0.0, -2.0);
			glVertex3f(-2.0, -2.0, -2.0);
			glVertex3f(2.0, -2.0, -2.0);
		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::trianlgeStrip)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_TRIANGLE_STRIP);
		{
			glColor3f(0.0f, 2.0f, 0.0f);
			glVertex3f(-1.5, 4.0, -10.0);
			glVertex3f(-3.0, 1.0, -10.0);
			glVertex3f(0.0, 1.0, -10.0);
			glVertex3f(0.5, -0.5, -10.0);
			glVertex3f(3.5, -1.0, -10.0);
			glVertex3f(-3.5, -3.0, -10.0);
		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::triangleFan)
	{

		glNewList(index, GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
		{
			glColor3f(0.0f, 2.0f, 0.0f);
			glVertex3f(0.0, -3.0, -10.0);
			glVertex3f(-3.0, 1.7, -10.0);
			glVertex3f(-2.2, 2.4, -10.0);
			glVertex3f(-1.2, 2.8, -10.0);
			glVertex3f(0.0, 3.0, -10.0);
			glVertex3f(1.2, 2.8, -10.0);
			glVertex3f(2.0, 2.4, -10.0);
			glVertex3f(3.0, 1.7, -10.0);

		}
		glEnd();
		glEndList();


	}
	else if (gameShapes == m_shape::line)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_LINES);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.2, 0.0, -2.0);
			glVertex3f(-2.0, -2.0, -2.0);

		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::lineLoop)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_LINE_LOOP);
		{
			glColor3f(0.0f, 2.0f, 0.0f);
			glVertex3f(-2.0, -2.0, -10.0);
			glVertex3f(0.2, -1.0, -10.0);
			glVertex3f(1.5, 1.0, -10.0);
			glVertex3f(-0.5, 1.0, -10.0);
			glVertex3f(-0.5, -2.0, -10.0);
		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::lineStrip)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_LINE_STRIP);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-2.0, -2.0, -10.0);
			glVertex3f(0.2, -1.0, -10.0);
			glVertex3f(1.5, 1.0, -10.0);
			glVertex3f(-0.5, 1.0, -10.0);
			glVertex3f(-0.5, -2.5, -10.0);
		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::quad)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_QUADS);
		{
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0, -3.0, -10.0);
			glVertex3f(-3.0, 0.3, -10.0);
			glVertex3f(-2.2, 2.4, -10.0);
			glVertex3f(1.2, 0.0, -10.0);

		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::quadStrip)
	{

		glNewList(index, GL_COMPILE);
		glBegin(GL_QUAD_STRIP);
		{
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0, -3.0, -10.0);
			glVertex3f(-1.0, -2.0, -10.0);

			glVertex3f(1.0, -2.0, -10.0);
			glVertex3f(0.0, -1.0, -10.0);

			glVertex3f(1.0, -1.0, -10.0);
			glVertex3f(0.0, 0.0, -10.0);

			glVertex3f(2.0, -1.0, -10.0);
			glVertex3f(1.0, 0.0, -10.0);

			glVertex3f(2.0, 0.0, -10.0);
			glVertex3f(1.0, 1.0, -10.0);

			glVertex3f(3.0, 0.5, -10.0);
			glVertex3f(1.5, 3.0, -10.0);

		}
		glEnd();
		glEndList();
	}
	else if (gameShapes == m_shape::poly)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_POLYGON);
		{
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.0, -3.0, -10.0);
			glVertex3f(-3.0, 0.3, -10.0);
			glVertex3f(-2.2, 2.4, -10.0);
			glVertex3f(1.2, 3.0, -10.0);
			glVertex3f(2.2, 0.0, -10.0);
		}
		glEnd();
		glEndList();
	}
	

		

	if (elapsed.asMilliseconds() >= 500.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	 // ********************

	cout << "Update up" << endl;
}

void Game::draw()
{

	 // Uncomment for Part 2
	 // ********************
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Investigate Here!!!!!

	cout << "Drawing Primative " << current << endl;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	//glTranslatef(0, 0, -0.01);
	if (gameShapes == m_shape::triangle)
	{
		
		glTranslatef(0, 0, 0);
		glRotatef(rotationAngle, 0, 0, 1);
		glScalef(1, 1, 1);
	}
	glCallList(current);
	 // Uncomment for Part 2
	 // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::checkInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		gameShapes = m_shape::triangle;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		gameShapes = m_shape::triangleFan;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		gameShapes = m_shape::trianlgeStrip;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		gameShapes = m_shape::line;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		gameShapes = m_shape::lineLoop;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		gameShapes = m_shape::lineStrip;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		gameShapes = m_shape::quad;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		gameShapes = m_shape::quadStrip;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		gameShapes = m_shape::poly;
	}

}