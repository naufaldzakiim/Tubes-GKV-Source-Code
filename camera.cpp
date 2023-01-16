#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "gimTruckHeader.h"

float x=0.0f, y=25.0f, z=-70.0f; // posisi awal kamera 
float lx=0.0f, ly=-0.5f, lz=1.0f; 
float ratio;
int h, w;

void Reshape(int w1, int h1)
{ 
 	// Fungsi reshape 
 	if(h1 == 0) h1 = 1; 
 	w = w1; 
 	h = h1; 
 	ratio = 1.0f * w / h; 
 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity(); 
 	glViewport(0, 0, w, h); 
 	gluPerspective(45,ratio,0.1,1000); 
 	glMatrixMode(GL_MODELVIEW); 
 	glLoadIdentity(); 
 	gluLookAt(
 		x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void orientMe(float ang)
{ 
 	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
 	lx = sin(ang); 
 	lz = cos(ang);
 	glLoadIdentity();
 	gluLookAt(x, y, z, 
 		x + lx, y + ly, z + lz, 
 		0.0f , 1.0f, 0.0f); 
}

void orientMe2(float ang)
{ 
 	// Fungsi ini untuk memutar arah kamera (tengok atas/bawah) 
 	ly = sin(ang); 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx, y + ly, z + lz, 
 		0.0f,1.0f,0.0f); 
}

void moveMeFlat(int i)
{ 
 	// Fungsi ini untuk maju mundur kamera 
 	x = x + i*(lx)*0.1; 
 	z = z + i*(lz)*0.1; 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx, y + ly, z + lz, 
 		0.0f,1.0f,0.0f); 
} 


void cameraOnTruk(int trukMoveX, int trukMoveZ)
{
	// Fungsi untuk kamera bergerak sesuai dengan pergerakan truk
	x = x + trukMoveX*5.0; 
 	z = z + trukMoveZ*1.0; 
 	glLoadIdentity();
	gluLookAt(
 		x , y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f);
}
