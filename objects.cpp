#include <GL/glut.h>
#include <stdio.h>
#include "gimTruckHeader.h"

using namespace std;

GLuint _textureBatu1;
GLuint _textureGedung1;
GLuint _textureGedung2;
GLuint _texturePasir;
GLuint _textureJalan;

GLuint loadTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	Image* image1 = loadBMP("textures/rock1.bmp");
	_textureBatu1 = loadTexture(image1);
	
	Image* image2 = loadBMP("textures/city1.bmp");
	_textureGedung1 = loadTexture(image2);
	
	Image* image3 = loadBMP("textures/city2.bmp");
	_textureGedung2 = loadTexture(image3);
	
	Image* image4 = loadBMP("textures/sand.bmp");
	_texturePasir = loadTexture(image4);
	
	Image* image5 = loadBMP("textures/road.bmp");
	_textureJalan = loadTexture(image5);
	
	delete image1, image2, image3, image4, image5;
}

void batu1(float size)
{
	glTranslatef(0.0f, size / 2, 0.0f);
	kubusTekstur(size, _textureBatu1);
}

void gedung1(float size)
{
	glTranslatef(-size*1.75, size / 2, -960.0f);
	kubusTekstur(size, _textureGedung1);
	glTranslatef(0.0f, size, 0.0f);
	kubusTekstur(size, _textureGedung1);
}

void gedung2(float size)
{
	glTranslatef(size*1.75, size / 2, -1000.0f);
	kubusTekstur(size, _textureGedung2);
	glTranslatef(0.0f, size, 0.0f);
	kubusTekstur(size, _textureGedung2);
}

void tanahTekstur()
{
	const float BOX_SIZE = 50.0f;
	GLuint _namaTekstur = _texturePasir;
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-1000, 0.0, -1000);
		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE, 0.0, -BOX_SIZE);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-BOX_SIZE, 0.0, BOX_SIZE);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE, 0.0, BOX_SIZE);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(BOX_SIZE, 0.0, -BOX_SIZE);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}

void jalanTekstur()
{
	const float BOX_SIZE = 20.0f;
	GLuint _namaTekstur = _textureJalan;
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(0.0, 0.1, -1000.0);
		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE, 0.0, -BOX_SIZE);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-BOX_SIZE, 0.0, BOX_SIZE);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE, 0.0, BOX_SIZE);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(BOX_SIZE, 0.0, -BOX_SIZE);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}

void kubusTekstur(float size, GLuint _namaTekstur)
{	
	const float BOX_SIZE = size;
	//Sisi atas
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);

		glBegin(GL_QUADS);
			glNormal3f(0.0, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
		glEnd();
  
	//Sisi bawah
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);

		glBegin(GL_QUADS);
			glNormal3f(0.0, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
		glEnd();
	
	//Sisi kiri
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBegin(GL_QUADS);
			glNormal3f(-1.0, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
		glEnd();
	
	//Sisi kanan
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBegin(GL_QUADS);
			glNormal3f(1.0, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
		glEnd();
	
	//Sisi depan
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBegin(GL_QUADS);
			glNormal3f(0.0, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
		glEnd();
	
	//Sisi belakang
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _namaTekstur);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBegin(GL_QUADS);
			glNormal3f(0.0, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
		glEnd();
	
	glDisable(GL_TEXTURE_2D);
}
