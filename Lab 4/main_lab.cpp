

/////////////////////////       Golden Rectangles       /////////////////////////////


//#include <GL/glut.h>
//
//// Function to draw the golden rectangle with a specified color
//void drawGoldenRectangle(float centerX, float centerY, float rectWidth, float rectHeight, float r, float g, float b)
//{
//    glColor3f(r, g, b);
//    glBegin(GL_TRIANGLE_STRIP);
//    glVertex2f(centerX - rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX - rectWidth / 2, centerY + rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY + rectHeight / 2);
//    glEnd();
//}
//
//// Display callback function
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    // Calculate initial center and size for the golden rectangle
//    float centerX = 0.0f;
//    float centerY = 0.0f;
//    float rectWidth = 0.5f;
//    float rectHeight = 0.5f;
//
//    // Draw the regression of golden rectangles with different colors
//    for (int i = 0; i < 10; ++i)
//    {
//        float r = (i / 10.0f);      // Varies from 0.0 to 1.0
//        float g = (1.0f - r);       // Varies from 1.0 to 0.0
//        float b = (0.5f + r / 2);   // Varies from 0.5 to 1.0
//
//        drawGoldenRectangle(centerX, centerY, rectWidth, rectHeight, r, g, b);
//
//        // Update center and size for the next rectangle
//        centerX *= 0.9f;
//        centerY *= 0.9f;
//        rectWidth *= 0.9f;
//        rectHeight *= 0.9f;
//    }
//
//    glFlush();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 400);
//    glutCreateWindow("Golden Rectangles");
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}



///////////////////////////         Maze         //////////////////////////////



//#include <GL/glut.h>
//#include <iostream>
//#include <vector>
//#include <random>
//#include <ctime>
//#include <stack>
//
//const int ROWS = 20;
//const int COLS = 30;
//const int CELL_SIZE = 50;
//
//struct Cell {
//    bool visited;
//    bool wallTop, wallRight, wallBottom, wallLeft;
//};
//
//std::vector<Cell> maze(ROWS* COLS);
//int startRow, startCol, endRow, endCol;
//
//bool isValid(int row, int col) {
//    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
//}
//
//void generateMaze() {
//    for (int row = 0; row < ROWS; ++row) {
//        for (int col = 0; col < COLS; ++col) {
//            maze[row * COLS + col].visited = false;
//            maze[row * COLS + col].wallTop = true;
//            maze[row * COLS + col].wallRight = true;
//            maze[row * COLS + col].wallBottom = true;
//            maze[row * COLS + col].wallLeft = true;
//        }
//    }
//
//    std::stack<std::pair<int, int>> stack;
//    startRow = std::rand() % ROWS;
//    startCol = std::rand() % COLS;
//    stack.push(std::make_pair(startRow, startCol));
//    maze[startRow * COLS + startCol].visited = true;
//
//    while (!stack.empty()) {
//        int currentRow = stack.top().first;
//        int currentCol = stack.top().second;
//        stack.pop();
//
//        std::vector<int> neighbors = { 0, 1, 2, 3 };
//        std::shuffle(neighbors.begin(), neighbors.end(), std::mt19937(std::random_device()()));
//
//        for (int dir : neighbors) {
//            int newRow = currentRow;
//            int newCol = currentCol;
//            switch (dir) {
//            case 0: newRow--; break; // Up
//            case 1: newCol++; break; // Right
//            case 2: newRow++; break; // Down
//            case 3: newCol--; break; // Left
//            }
//
//            if (isValid(newRow, newCol) && !maze[newRow * COLS + newCol].visited) {
//                if (dir == 0) {
//                    maze[currentRow * COLS + currentCol].wallTop = false;
//                    maze[newRow * COLS + newCol].wallBottom = false;
//                }
//                if (dir == 1) {
//                    maze[currentRow * COLS + currentCol].wallRight = false;
//                    maze[newRow * COLS + newCol].wallLeft = false;
//                }
//                if (dir == 2) {
//                    maze[newRow * COLS + newCol].wallTop = false;
//                    maze[currentRow * COLS + currentCol].wallBottom = false;
//                }
//                if (dir == 3) {
//                    maze[newRow * COLS + newCol].wallRight = false;
//                    maze[currentRow * COLS + currentCol].wallLeft = false;
//                }
//
//                stack.push(std::make_pair(newRow, newCol));
//                maze[newRow * COLS + newCol].visited = true;
//            }
//        }
//    }
//
//    endRow = ROWS - 1;
//    endCol = COLS - 1;
//    int currentRow = 0;
//    int currentCol = 0;
//    while (currentRow != endRow || currentCol != endCol) {
//        if (currentRow < endRow) {
//            maze[currentRow * COLS + currentCol].wallBottom = false;
//            maze[(currentRow + 1) * COLS + currentCol].wallTop = false;
//            currentRow++;
//        }
//        else if (currentCol < endCol) {
//            maze[currentRow * COLS + currentCol].wallRight = false;
//            maze[currentRow * COLS + currentCol + 1].wallLeft = false;
//            currentCol++;
//        }
//    }
//}
//
//void drawMaze() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    for (int row = 0; row < ROWS; ++row) {
//        for (int col = 0; col < COLS; ++col) {
//            const Cell& cell = maze[row * COLS + col];
//            int x = col * CELL_SIZE;
//            int y = row * CELL_SIZE;
//
//            glColor3f(1.0f, 1.0f, 1.0f);
//            if (cell.wallTop) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y);
//                glVertex2i(x + CELL_SIZE, y);
//                glEnd();
//            }
//            if (cell.wallRight) {
//                glBegin(GL_LINES);
//                glVertex2i(x + CELL_SIZE, y);
//                glVertex2i(x + CELL_SIZE, y + CELL_SIZE);
//                glEnd();
//            }
//            if (cell.wallBottom) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y + CELL_SIZE);
//                glVertex2i(x + CELL_SIZE, y + CELL_SIZE);
//                glEnd();
//            }
//            if (cell.wallLeft) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y);
//                glVertex2i(x, y + CELL_SIZE);
//                glEnd();
//            }
//        }
//    }
//
//    glutSwapBuffers();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, COLS * CELL_SIZE, 0, ROWS * CELL_SIZE);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    std::srand(static_cast<unsigned int>(std::time(nullptr)));
//
//    generateMaze();
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
//    glutCreateWindow("My Maze Generator");
//    glutDisplayFunc(drawMaze);
//    glutReshapeFunc(reshape);
//
//    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
//
//    glutMainLoop();
//
//    return 0;
//}



/////////////////////////      Menu Test       ///////////////////////////




//#include <gl/glut.h>
//#include<gl/glu.h> 
//#include<gl/gl.h>
//
//#define RED 1 
//#define GREEN 2
//#define BLUE 3  
//#define WHITE 4 
//float angle = 0.0;// for rotating the triangle 
//float red = 1.0,
//blue = 1.0,
//green = 1.0; // possible triangle colors. 
//void renderScene(void) {
//    // the callback to draw the triangle
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glRotatef(angle, 0.0, 1.0, 0.0); // rotate the triangle a little more 
//    glColor3f(red, green, blue);// change its color
//
//    glBegin(GL_TRIANGLES); // draw the triangle 
//    glVertex3f(-0.5, -0.5, 0.0);
//
//    glVertex3f(0.5, 0.0, 0.0);
//    glVertex3f(0.0, 0.5, 0.0);
//
//    glEnd();
//    angle++;
//
//    glutSwapBuffers();
//
//}
//
//void processMenuEvents(int option) {
//
//    //mouse choice chooses color 
//    switch (option) {
//
//    case RED:
//        red = 1.0;
//        green = 0.0;
//        blue = 0.0;
//        break;
//
//    case GREEN:
//        red = 0.0;
//        green = 1.0;
//        blue = 0.0;
//        break;
//
//    case BLUE:
//        red = 0.0;
//        green = 0.0;
//        blue = 1.0;
//        break;
//
//    case WHITE:
//        red = 1.0;
//        green = 1.0;
//        blue = 1.0;
//        break;
//    }
//}
//
//void main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(320, 320);
//
//    glutCreateWindow("Menu Test"); // open an OpenGL window 
//    glutDisplayFunc(renderScene); // register display function
//
//    glutIdleFunc(renderScene); // calls to functions to create
//
//
//    glutCreateMenu(processMenuEvents);
//
//    glutAddMenuEntry("Red", RED);
//
//    glutAddMenuEntry("Blue", BLUE);
//    glutAddMenuEntry("Green", GREEN);
//
//    glutAddMenuEntry("White", WHITE); glutAttachMenu(GLUT_RIGHT_BUTTON); // attach right mouse button
//
//
//
//    glutMainLoop();
//}




///////////////////////////        Arrow        /////////////////////////////



#include <gl/glut.h>
#include <iostream>
using namespace std;

class Canvas {
public:
    float x, y;
    Canvas() {
        this->x = 180;
        this->y = 200;
    }

    void moveTo(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void lineToRel(float dx, float dy) {
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(x, y);
        x += dx;
        y += dy;
        glVertex2f(x, y);
        glEnd();
    }

    void drawMarker() {
        // Draw a marker at the current position (x, y)
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(x - 2, y - 2);
        glVertex2f(x + 2, y - 2);
        glVertex2f(x + 2, y + 2);
        glVertex2f(x - 2, y + 2);
        glEnd();
    }

    void arrow(float f, float h, float t, float w) {
        lineToRel(-w - t / 2, -f); // down the left side
        lineToRel(w, 0);
        lineToRel(0, -h);
        lineToRel(t, 0); // across
        lineToRel(0, h); // back up
        lineToRel(w, 0);
        lineToRel(-w - t / 2, f);
    }
};

int screenWidth = 640;
int screenHeight = 440;
Canvas CP;

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    CP.moveTo(100, 200); // Move to the first data point

    // Draw an arrow at the current position (x, y)
    CP.arrow(60, 40, 40, 20);

    CP.moveTo(300, 300);
    // Draw a marker at the CP
    CP.drawMarker();

    CP.lineToRel(-60, -80);
    CP.drawMarker();

    CP.lineToRel(50, 0);
    CP.drawMarker();

    CP.lineToRel(0, -50);
    CP.drawMarker();

    CP.lineToRel(30, 0);
    CP.drawMarker();

    CP.lineToRel(0, 50);
    CP.drawMarker();

    CP.lineToRel(40, 0);
    CP.drawMarker();

    CP.lineToRel(-60, 80);
    CP.drawMarker();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arrow Lab - 4");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);

    init();
    glutMainLoop();
    return 0;
}









