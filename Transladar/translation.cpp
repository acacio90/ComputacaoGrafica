#include <stdio.h>
#include <GL/glut.h>

class wcPt2D{
    public: GLfloat x, y;
};

void translatePolygon (wcPt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty){
    for(int i = 0; i < nVerts; i++){
        verts[i].x += tx;
        verts[i].y += ty;
    }
};

int init (void) {
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display (void) {
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    int nVerts = 3;
    wcPt2D verts[nVerts];

    verts[0].x = 50;
    verts[0].y = 20;

    verts[1].x = 150;
    verts[1].y = 20;
    
    verts[2].x = 100;
    verts[2].y = 120;

    glPointSize(11.0);
    glBegin(GL_TRIANGLES);
        glColor3ub(255, 0, 0);
            glVertex2i(verts[0].x, verts[0].y);
        glColor3ub(0, 255, 0);
            glVertex2i(verts[1].x, verts[1].y);
        glColor3ub(0, 0, 255);
            glVertex2i(verts[2].x, verts[2].y);
    glEnd();
    glFlush();

    translatePolygon (verts, nVerts, 30, 30);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(11.0);
    glBegin(GL_TRIANGLES);
        glColor3ub(255, 0, 0);
            glVertex2i(verts[0].x, verts[0].y);
        glColor3ub(0, 255, 0);
            glVertex2i(verts[1].x, verts[1].y);
        glColor3ub(0, 0, 255);
            glVertex2i(verts[2].x, verts[2].y);
}

int main (int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(400,300);

    glutCreateWindow("Exemplo de programa OpenGL");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}