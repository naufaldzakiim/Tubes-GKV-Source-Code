#include <GL/glut.h>
#include <stdio.h>
#include "gimTruckHeader.h"

void Gerbang()
{
	// Fungsi untuk membuat gerbang batu  
 	const float Y_MIN = 0, Y_MAX = 14; 
 	const float X_MIN = -20, X_MAX = 20;
 	const float gap = 2;
 	double batuPointX;
 	double batuPointY;
 	
	glPushMatrix();
	glTranslatef(-19.0f, 0.0f, 1.6f);
	for(batuPointY = Y_MIN; batuPointY < Y_MAX; batuPointY += gap){
		glPushMatrix();
		for(batuPointX = X_MIN; batuPointX < X_MAX; batuPointX += gap){
			glPushMatrix();
			batu1(2.0);
			glPopMatrix();
			glTranslatef(gap, 0.0, 0.0);
 		}
		glPopMatrix();
		glTranslatef(0.0, gap, 0.0);
 	}
 	glPopMatrix();
 	glEnd();
}

void Bangunan()
{	
	// Fungsi untuk membuat barisan gedung tingkat
	const float Z_MIN = -1000, Z_MAX = 1000;
	double gedungPointZ; 
 	const float gapGedung = 80;
 	
	glPushMatrix();
 	for(gedungPointZ = Z_MIN; gedungPointZ < Z_MAX; gedungPointZ += gapGedung){
		glPushMatrix();
		gedung2(40.0);
		glPopMatrix();
		glTranslatef(0.0, 0.0, gapGedung);
 	}
 	glPopMatrix();
 	
 	glPushMatrix();
 	for(gedungPointZ = Z_MIN; gedungPointZ < Z_MAX; gedungPointZ += gapGedung){
		glPushMatrix();
		gedung1(40.0);
		glPopMatrix();
		glTranslatef(0.0, 0.0, gapGedung);
 	}
 	glPopMatrix();
	glEnd();
}

void Land()
{ 
 	// Fungsi untuk membuat lantai berupa tanah  
 	const float Z_MIN = -1000, Z_MAX = 1000; 
 	const float X_MIN = -1000, X_MAX = 1000;
 	const float gap = 100;
 	double tilePointX;
 	double tilePointZ;
 	
 	//Tanah pasir
	glPushMatrix();
	for(tilePointZ = Z_MIN; tilePointZ < Z_MAX; tilePointZ += gap){
		glPushMatrix();
		for(tilePointX = X_MIN; tilePointX < X_MAX; tilePointX += gap){
			glPushMatrix();
			tanahTekstur();
			glPopMatrix();
			glTranslatef(gap, 0.0, 0.0);
 		}
		glPopMatrix();
		glTranslatef(0.0, 0.0, gap);
 	}
 	glPopMatrix();
 	glEnd(); 
}

void Road()
{ 
 	// Fungsi untuk membuat jalan 
 	double loopRoadLines; 
 	const float Z_MIN = -1000, Z_MAX = 1000; 
 	const float X_MIN = -25, X_MAX = 25;
 	const float gapLines = 35;
 	const float gapRoad = 40;
 	double tilePointZ;
 	
 	//Aspal
 	glPushMatrix();
 	for(tilePointZ = Z_MIN; tilePointZ < Z_MAX; tilePointZ += gapRoad){
		glPushMatrix();
		jalanTekstur();
		glPopMatrix();
		glTranslatef(0.0, 0.0, gapRoad);
 	}
 	glPopMatrix();
 	
 	//Garis jalan
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		for(loopRoadLines = Z_MIN; loopRoadLines < Z_MAX; loopRoadLines += gapLines){
			glVertex3f(1.0, 0.2, loopRoadLines+15.0);
		 	glVertex3f(-1.0, 0.2, loopRoadLines+15.0);
		 	glVertex3f(-1.0, 0.2, loopRoadLines);
		 	glVertex3f(1.0, 0.2, loopRoadLines);
	 	}
 	glEnd();
}
