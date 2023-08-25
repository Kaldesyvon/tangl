#include <GL/glut.h>

float angle = 0.0f;

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
//    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45,ratio,1,100);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	0.0f, 0.0f, 10.0f,
                  0.0f, 0.0f,  0.0f,
                  0.0f, 1.0f,  0.0f);

    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f,-2.0f, 0.0f);
    glVertex3f( 2.0f, 0.0f, 0.0);
    glVertex3f( 0.0f, 2.0f, 0.0);
    glEnd();

    angle+=0.4f;

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("Tangl");

    glutDisplayFunc(render);
    glutReshapeFunc(changeSize);
    glutIdleFunc(render);

    glutMainLoop();

    return 0;
}
