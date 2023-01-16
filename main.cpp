#include <GL/glut.h>
#include <stdio.h>
#include "gimTruckHeader.h"

/*
Nama kelompok :
Naufal Dzaki Imtiyaz	24060121120014
Luciano Rizky Pratama	24060121140156

Praktikum : GKV
Lab : B2
*/

void init(void)
{ 
 	glEnable (GL_DEPTH_TEST); 
 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 

int main(int argc, char **argv)
{ 
 	glutInit(&argc, argv); 
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 	glutInitWindowPosition(100,100); 
 	glutInitWindowSize(640,480); 
 	glutCreateWindow("Gim Truk Gandeng 4K 144fps Ray Tracing"); 
 	glutSpecialFunc(pressKey);
 	glutSpecialUpFunc(releaseKey);
	glutKeyboardFunc(pressKeyboard);
 	glutDisplayFunc(display); 
 	glutIdleFunc(display); // Fungsi display-nya dipanggil terus-menerus 
 	glutReshapeFunc(Reshape);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
 	lighting(); 
 	init(); 
 	initRendering();
 	glutMainLoop(); 
 	return(0); 
}
