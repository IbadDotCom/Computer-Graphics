#include <iostream>
#include <Windows.h>
#include <GL/glut.h>

using namespace std;

void myDisplay(void) // User defined display function
{
	glClear(GL_COLOR_BUFFER_BIT); //clears fb with bg color 
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);// set background color
	glColor3f(1, 0, 0); //set Foreground Color
	glFlush();	//sends buffers pixels to display screen
}

int screenWidth = 640;
int screenHeight = 480;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("Ibad's Program");
	glutDisplayFunc(myDisplay); //register display func. as callback
	PlaySoundW(L"music.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP); // To play music
	glutMainLoop();
	return 0; //quit loop that waits for events to occur
}
