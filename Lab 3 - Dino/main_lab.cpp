

////////////////////////////////////       Dino       ///////////////////////////////////////


//#include <iostream>
//#include <fstream>
//#include <GL/glut.h>
//
//using std::cout;
//using std::ifstream;
//
//const int screenWidth = 680;       // Width of the screen window in pixels
//const int screenHeight = 500;      // Height of the screen window in pixels
//
//void drawPolyLineFile(const char* fileName) {
//    std::ifstream inStream(fileName); // Use ifstream for file reading
//
//    if (!inStream) {
//        cout << "Can't open the file: " << fileName << "\n";
//        return;
//    }
//
//    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
//
//    int numPolys, numPoints;
//    float x, y;
//
//    inStream >> numPolys; // Read the number of polylines
//    if (inStream.fail()) {
//        cout << "Error reading number of polylines.\n";
//        return;
//    }
//
//    for (int j = 0; j < numPolys; j++) { // Read each polyline
//        inStream >> numPoints; // Number of points in this polyline
//        if (inStream.fail()) {
//            cout << "Error reading number of points for polyline " << j + 1 << ".\n";
//            return;
//        }
//
//        glBegin(GL_LINE_STRIP); // Draw the next polyline
//        for (int i = 0; i < numPoints; i++) {
//            inStream >> x >> y; // Read the next x, y pair
//            if (inStream.fail()) {
//                cout << "Error reading coordinates for point " << i + 1 << " of polyline " << j + 1 << ".\n";
//                glEnd(); // End the line strip before exiting
//                return;
//            }
//            glVertex2f(x, y);
//        }
//        glEnd();
//    }
//
//    inStream.close();
//}
//
//void myInit(void) {
//    glClearColor(1.0, 1.0, 1.0, 0.0); // Background color is white
//    glColor3f(0.0f, 0.0f, 0.0f);      // Drawing color is black
//    glPointSize(2.0);                 // A 'dot' is 2 by 2 pixels
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-100.0, (GLdouble)screenWidth, -100.0, (GLdouble)screenHeight); // Set up coordinate system
//    //glViewport(0, 0, screenWidth, screenHeight);
//}
//
//void myDisplay(void) {
//    drawPolyLineFile("dino.dat"); // Send all output to display
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // Initialize GLUT
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode
//    glutInitWindowSize(screenWidth, screenHeight); // Set window size
//    glutInitWindowPosition(10, 10); // Set window position on screen
//    glutCreateWindow("Dino Line Drawing"); // Open the screen window
//    glutDisplayFunc(myDisplay); // Register redraw function
//    myInit();
//    glutMainLoop(); // Go into a perpetual loop
//    return 0;
//}




///////////////////////////////////        DinoTiles       //////////////////////////////////////



//#include <fstream>
//#include <iostream>
//#include <GL/glut.h>
//using namespace std;
//const int screenWidth = 650;	   // width of screen window in pixels 
//const int screenHeight = 450;	   // height of screen window in pixels
//double rotate_x = 0.5;
//void setWindow(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
//}
//void drawPolyLineFile(const char* fileName)
//{
//	fstream inStream;
//	inStream.open(fileName, ios::in);	// open the file
//	if (inStream.fail())
//	{
//		cout << "can't open it!"; return;
//	}
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	inStream.close();
//}
//void myInit(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
//	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
//	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);      //dino window
//	glViewport(0, 0, screenWidth, screenHeight);
//}
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	setWindow(0, 640, 0, 480);
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 20; j++) {
//			glViewport(i * 64, j * 44, 64, 44);
//			drawPolyLineFile("dino.dat");
//
//		}
//	}
//	glFlush();
//	glutSwapBuffers();
//}
//int main(int argc, char** argv)
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Dino Tiles Drawing"); // open the screen window
//	glutDisplayFunc(myDisplay);     // register redraw function
//	myInit();
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 1;
//}




///////////////////////////////        Dino Invert Tiles       ///////////////////////////



//#include <fstream>
//#include <iostream>
//#include <GL/glut.h>
//using namespace std;
//const int screenWidth = 650;	   // width of screen window in pixels 
//const int screenHeight = 450;	   // height of screen window in pixels
//double rotate_x = 0.5;
//
//void setWindow(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
//}
//void drawPolyLineFile(const char* fileName)
//{
//	fstream inStream;
//	inStream.open(fileName, ios::in);	// open the file
//	if (inStream.fail())
//	{
//		cout << "can't open it!"; return;
//	}
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	inStream.close();
//}
//void myInit(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
//	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
//	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);      //dino window
//	glViewport(0, 0, screenWidth, screenHeight);
//}
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	setWindow(0, 640, 0, 480);
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			if ((i + j) % 2 == 0) setWindow(0, 640, 0, 480);
//			else setWindow(0, 640, 480, 0);
//			glViewport(i * 64, j * 44, 64, 44);
//			drawPolyLineFile("dino.dat");
//		}
//	}
//	glFlush();
//	glutSwapBuffers();
//}
//int main(int argc, char** argv)
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Dino Tiles Drawing"); // open the screen window
//	glutDisplayFunc(myDisplay);     // register redraw function
//	myInit();
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 1;
//}




////////////////////////////     Dino Zoom     /////////////////////////////////



//#include <gl/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using std::cout;
//using std::fstream;
//using std::ios;
//
//const int screenWidth = 640;	   // width of screen window in pixels 
//const int screenHeight = 480;	   // height of screen window in pixels
//double rotate_x = 1;
//
//void setWindow(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D((GLint)xs, (GLint)xe, (GLint)ys, (GLint)ye);
//}
//
//void drawPolyLineFile(const char* fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!"; return;
//	}
//	// clear the screen
//	//GLint numpolys, numPoints, x ,y;
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	glScalef(rotate_x, rotate_x, 1.0f);
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	inStream.close();
//}
//
//void keyPress(int key, int x, int y)
//{
//	if (key == 27)
//		exit(0);
//	if (key == GLUT_KEY_UP) {
//
//		rotate_x += .05;
//		glutPostRedisplay();
//	}
//	if (key == GLUT_KEY_DOWN) {
//		rotate_x -= .05;
//		glutPostRedisplay();
//	}
//}
//
//void myInit(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);       // background color is white
//	glColor3f(0.0f, 0.0f, 0.0f);         // drawing color is black
//	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);//dino window
//	glViewport(0, 0, screenWidth, screenHeight);
//
//}
//
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawPolyLineFile("dino.dat");
//	glFlush();
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv)
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Dino Zoom in & out"); // open the screen window
//	glutDisplayFunc(myDisplay);     // register redraw function
//	glutSpecialFunc(keyPress);
//	myInit();
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 0;
//}



///////////////////////////////        DrawArc       ////////////////////////////////



//#include <iostream>
//#include <cstdlib>
//#include <stdlib.h>
//#include <GL/glut.h>
// 
//const double PI = 3.14159265358979323846;
// 
//class Point2 {
//public:
//    float x, y;
//    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {}
//    float getX() const {
//        return x;
//    }
//    float getY() const {
//        return y;
//    }
//};
// 
//void moveTo(const Point2& p) {
//    glBegin(GL_LINES);
//    glVertex2f(p.x, p.y);
//}
// 
//void lineTo(const Point2& p) {
//    glVertex2f(p.x, p.y);
//}
// 
//void drawArc(const Point2& center, float radius, float startAngle, float sweep) {
//    const int n = 100; // number of intermediate segments in arc
//    float angle = startAngle * PI / 180; // initial angle in radians
//    float angleInc = sweep * PI / (180 * n); // angle increment
//    float cx = center.getX(), cy = center.getY();
//    moveTo(Point2(cx + radius * cos(angle), cy + radius * sin(angle)));
//    for (int k = 1; k < n; ++k, angle += angleInc) {
//        lineTo(Point2(cx + radius * cos(angle), cy + radius * sin(angle)));
//    }
//    glEnd();
//}
// 
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.1, 0.0, 0.0); // Set color to red
//    Point2 center(0.0, 0.0);  // Center of the arc
//    float radius = 0.5;       // Radius of the arc
//    float startAngle = 45.0;  // Starting angle in degrees
//    float sweepAngle = 180.0; // Sweep angle in degrees
//    drawArc(center, radius, startAngle, sweepAngle);
//    glFlush();
//}
// 
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(640, 480);
//    glutInitWindowPosition(30, 30);
//    glutCreateWindow("Lab 3 - ngon and Arc");
//    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}




////////////////////////////////          DrawAxis            /////////////////////////////////



//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <GL/glut.h>
// 
//class Dot {
//public:
//	int x = -1;
//	int y = -1;
//	Dot(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	Dot() = default;
//};
// 
//int screenWidth = 640;
//int screenHeight = 480;
//int dot_x = -1;
//int dot_y = -1;
//float minX = -1.0, minY = -1.0, maxX = 1.0, maxY = 1.0;
//int VPBottom = 0, VPLeft = 0, VPWidth = 640, VPHeight = 480;
//std::vector<Dot> dotsVector = {};
// 
//void initGL() {
//	glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
//	glColor3f(1, 0, 0);
//}
// 
//void drawDot(int x, int y) {
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glPointSize(10.0);
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//}
// 
//void drawAxis() {
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex2f(minX, 0);
//	glVertex2f(maxX, 0);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2f(0, minY);
//	glVertex2f(0, maxX);
//	glEnd();
//}
// 
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (dot_x != -1 && dot_y != -1) {}
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	for (int i = 0; i < dotsVector.size(); i++) {
//		drawDot(dotsVector[i].x, dotsVector[i].y);
//	}
//	glViewport(VPBottom, VPLeft, VPWidth, VPHeight);
//	drawAxis();
//	glFlush();
//}
// 
//void reshape(int width, int height) {
//	screenWidth = width;
//	screenHeight = height;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
// 
//void keyboardHandler(unsigned char key, int x, int y) {
//	switch (key)
//	{
//	case 'q':
//		exit(0);
//	case 's':
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
// 
//void mouseHandler(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		dot_x = x;
//		dot_y = screenHeight - y;
//		Dot newDot = Dot(x, screenHeight - y);
//		dotsVector.push_back(newDot);
//	}
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//		glClear(GL_COLOR_BUFFER_BIT);
//	}
//	glutPostRedisplay();
//}
// 
//void motionHandler(int x, int y) {
//	dot_x = x;
//	dot_y = screenHeight - y;
//	Dot newDot = Dot(x, screenHeight - y);
//	dotsVector.push_back(newDot);
//	glutPostRedisplay();
//}
// 
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutCreateWindow("Lab 03 - Axis ");
//	initGL();
//	glutDisplayFunc(display); // Set the display callback function
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboardHandler);
//	glutMouseFunc(mouseHandler);
//	glutMotionFunc(motionHandler);
//	glutMainLoop(); // Start the main GLUT loop
//	return 0;
//}




///////////////////////////////        FatPaintBrush        ///////////////////////////////////



//#include <iostream>
//#include <fstream>
//#include <string>
//#include <GL/glut.h>
//#include <vector>
// 
//class Dot {
//public:
//	int x = -1, y = -1;
//	Dot(int x, int y) {
//		this->x = x; this->y = y;
//	}
//	Dot() = default;
//};
// 
//int screenWidth = 640, screenHeight = 480, dot_x = -1, dot_y = -1;
//float minX = -1.0, minY = -1.0, maxX = 1.0, maxY = 1.0;
//int VPBottom = 0, VPLeft = 0, VPWidth = 640, VPHeight = 480;
//std::vector<Dot> dotsVector = {};
// 
//void initGL() {
//	glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
//	glColor3f(1, 0, 0);
//}
//void drawDot(int x, int y) {
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glPointSize(5.0);
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (dot_x != -1 && dot_y != -1) {
//	}
//	for (int i = 0; i < dotsVector.size(); i++) {
//		drawDot(dotsVector[i].x, dotsVector[i].y);
//	}
//	glFlush();
//}
//void reshape(int width, int height) {
//	screenWidth = width;
//	screenHeight = height;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//void keyboardHandler(unsigned char key, int x, int y) {
//	switch (key)
//	{
//	case 'q':
//		exit(0);
//	case 's':
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//void mouseHandler(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		dot_x = x;
//		dot_y = screenHeight - y;
//		Dot newDot = Dot(x, screenHeight - y);
//		dotsVector.push_back(newDot);
//	}
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//		glClear(GL_COLOR_BUFFER_BIT);
//	}
//	glutPostRedisplay();
//}
//void motionHandler(int x, int y) {
//	dot_x = x;
//	dot_y = screenHeight - y;
//	Dot newDot = Dot(x, screenHeight - y);
//	dotsVector.push_back(newDot);
//	glutPostRedisplay();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutCreateWindow("Lab 03- Drawing with Brush");
//	glutInitWindowPosition(30, 30);
//	initGL();
//	glutDisplayFunc(myDisplay); // Set the display callback function
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboardHandler);
//	glutMouseFunc(mouseHandler);
//	glutMotionFunc(motionHandler);
//	glutMainLoop(); // Start the main GLUT loop
//	return 0;
//}





//////////////////////////////    ParametricCurve    //////////////////////////////////




//#include <cmath>
//#include <iostream>
//#include <cstdlib>
//#include <stdlib.h>
//#include <GL/glut.h>
//const double PI = 3.14159265358979323846;
//// Function to draw the rose curve
//void drawRoseCurve(int k) {
//    glColor3f(0.0, 0.0, 0.0); // Set color to black
//    glBegin(GL_LINE_STRIP);
//    for (double angle = 0; angle <= 2 * PI; angle += 0.01) {
//        //double radius = sin(k * angle);            //Rose Cuves
//        //double radius = k * angle;                 //Archimedian Spiral
//        double radius = k * (1 + cos(angle));        //Cardioid
//        double x = radius * cos(angle);
//        double y = radius * sin(angle);
//        glVertex2d(x, y);
//    }
//    glEnd();
//}
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//    glLoadIdentity();
//    // Translate to the center of the window
//    glTranslatef(0.0, 0.0, 0.0);
//    // Scale the curve
//    glScalef(1.0, 1.0, 1.0);
//    drawRoseCurve(5); // You can adjust the value of 'k' here
//    glFlush();
//}
//// Reshape callback function
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//}
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(640, 400);
//    glutCreateWindow("Lab 3 - Rose Curve using GLUT");
//    glutInitWindowPosition(30, 30);
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
//    glutMainLoop();
//    return 0;
//}



//////////////////////////         Rosette           ///////////////////////////



#include <GL/glut.h>
#include <cmath> 
#include <iostream>
#include <vector>

const int numVertices = 5; // Change this value to draw a polygon with a different number of vertices
const GLfloat radius = 0.7;
const GLfloat centerX = 0.0;
const GLfloat centerY = 0.0;
const GLfloat pi = 3.14159265358979323846;

void drawPolygonWithLines() {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numVertices; ++i) {
		GLfloat angle = 2.0 * pi * static_cast<GLfloat>(i) / numVertices;
		GLfloat x = centerX + radius * cos(angle);
		GLfloat y = centerY + radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i < numVertices; ++i) {
		GLfloat angle1 = 2.0 * pi * static_cast<GLfloat>(i) / numVertices;
		GLfloat x1 = centerX + radius * cos(angle1);
		GLfloat y1 = centerY + radius * sin(angle1);

		for (int j = i + 1; j < numVertices; ++j) {
			GLfloat angle2 = 2.0 * pi * static_cast<GLfloat>(j) / numVertices;
			GLfloat x2 = centerX + radius * cos(angle2);
			GLfloat y2 = centerY + radius * sin(angle2);

			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
		}
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);  // Set color to white

	drawPolygonWithLines();

	glFlush();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Polygon with All Lines");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}