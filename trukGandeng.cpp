#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "gimTruckHeader.h"

//Objek Truk Gandeng
void trukGandeng()
{
	// Kepala truk	
	glPushMatrix();		
		// Kepala bagian bawah
		glPushMatrix();	
			// depan
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glTranslatef(2.0f, 4.0f, 0.5f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-4.0f, 2.0f, 0.0f);
				glEnd();
				
				// kap truk
				glPushMatrix();
					// kap depan 1
					glScalef(0.7f, 0.625f, 0.5f);
					glTranslatef(0.0f, -0.5f, 0.01f);
					glColor3ub(31, 26, 28);
					glBegin(GL_QUADS);
						glVertex3f(-3.0f, 0.0f, 0.0f);
						glVertex3f(3.0f, 0.0f, 0.0f);
						glVertex3f(4.0f, 2.0f, 0.0f);
						glVertex3f(-4.0f, 2.0f, 0.0f);
					glEnd();
					
					// kap depan 2
					glTranslatef(0.0f, -2.25f, 0.0f);
					glColor3ub(31, 26, 28);
					glBegin(GL_QUADS);
						glVertex3f(-3.0f, 0.0f, 0.0f);
						glVertex3f(3.0f, 0.0f, 0.0f);
						glVertex3f(4.0f, 2.0f, 0.0f);
						glVertex3f(-4.0f, 2.0f, 0.0f);
					glEnd();
				glPopMatrix();
				
				// lampu kiri
				glPushMatrix();
					glScalef(0.7f, 0.625f, 0.5f);
					glTranslatef(0.25f, -0.5f, 0.01f);
					glColor3ub(255, 249, 1);
					glBegin(GL_QUADS);
						glVertex3f(5.0f, 0.0f, 0.0f);
						glVertex3f(3.0f, 0.0f, 0.0f);
						glVertex3f(4.0f, 2.0f, 0.0f);
						glVertex3f(5.0f, 2.0f, 0.0f);
					glEnd();
					
					glTranslatef(0.0f, -2.25f, 0.0f);
					glColor3ub(255, 255, 255);
					glBegin(GL_QUADS);
						glVertex3f(5.0f, 0.0f, 0.0f);
						glVertex3f(3.0f, 0.0f, 0.0f);
						glVertex3f(4.0f, 2.0f, 0.0f);
						glVertex3f(5.0f, 2.0f, 0.0f);
					glEnd();
				glPopMatrix();
				
				// lampu kanan
				glPushMatrix();
					glScalef(0.7f, 0.625f, 0.5f);
					glTranslatef(-0.25f, -0.5f, 0.01f);
					glColor3ub(255, 249, 1);
					glBegin(GL_QUADS);
						glVertex3f(-5.0f, 0.0f, 0.0f);
						glVertex3f(-3.0f, 0.0f, 0.0f);
						glVertex3f(-4.0f, 2.0f, 0.0f);
						glVertex3f(-5.0f, 2.0f, 0.0f);
					glEnd();
					
					glTranslatef(0.0f, -2.25f, 0.0f);
					glColor3ub(255, 255, 255);
					glBegin(GL_QUADS);
						glVertex3f(-5.0f, 0.0f, 0.0f);
						glVertex3f(-3.0f, 0.0f, 0.0f);
						glVertex3f(-4.0f, 2.0f, 0.0f);
						glVertex3f(-5.0f, 2.0f, 0.0f);
					glEnd();
				glPopMatrix();
			glPopMatrix();
			
			// belakang
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glTranslatef(2.0f, 4.0f, -6.5f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-4.0f, 2.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// bawah
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 1, 0, 0);
				glTranslatef(2.0f, -2.5f, -1.0f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -4.0f, 0.0f);
					glVertex3f(4.0f, -4.0f, 0.0f);
					glVertex3f(4.0f, 3.0f, 0.0f);
					glVertex3f(-4.0f, 3.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// kiri
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 0, 1, 0);
				glTranslatef(2.5f, 4.0f, 6.0f);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-3.0f, 2.0f, 0.0f);
				glEnd();
				
				// pintu kiri
				glScalef(0.6f, 0.95f, 0.7f);
				glTranslatef(0.16f, 0.6f, 0.01f);
				glColor3ub(255, 98, 0);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-3.0f, 2.0f, 0.0f);
				glEnd();
				
				// gagang pintu kiri
				glColor3ub(21, 18, 14);
				glTranslatef(2.3f, 0.9f, 0.01f);
				glScalef(0.2f, 0.2f, 0.0f);
				glBegin(GL_QUADS);
					glVertex3f(-5.0f, 0.0f, 0.0f);
					glVertex3f(5.0f, 0.0f, 0.0f);
					glVertex3f(5.0f, 2.0f, 0.0f);
					glVertex3f(-5.0f, 2.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// kanan
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 0, 1, 0);
				glTranslatef(2.5f, 4.0f, -2.0f);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-3.0f, 2.0f, 0.0f);
				glEnd();
				
				// pintu kanan
				glScalef(0.6f, 0.95f, 0.7f);
				glTranslatef(0.16f, 0.6f, -0.01f);
				glColor3ub(255, 98, 0);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 2.0f, 0.0f);
					glVertex3f(-3.0f, 2.0f, 0.0f);
				glEnd();
				
				// gagang pintu kanan
				glColor3ub(21, 18, 14);
				glTranslatef(2.3f, 0.9f, -0.01f);
				glScalef(0.2f, 0.2f, 0.0f);
				glBegin(GL_QUADS);
					glVertex3f(-5.0f, 0.0f, 0.0f);
					glVertex3f(5.0f, 0.0f, 0.0f);
					glVertex3f(5.0f, 2.0f, 0.0f);
					glVertex3f(-5.0f, 2.0f, 0.0f);
				glEnd();
			glPopMatrix();	
		glPopMatrix();
	
		
		// Kepala bagian atas
		glPushMatrix();
		glTranslatef(0.0f, 5.0f, 0.0f);	
			// depan
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glTranslatef(2.0f, 4.0f, 0.5f);
				glRotated(-30, 1, 0, 0);
				glTranslatef(0.0f, 0.4f, -1.5f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.6f, 0.0f);
					glVertex3f(-4.0f, 1.6f, 0.0f);
				glEnd();
				
				// kaca depan
				glScalef(0.85f, 0.8f, 0.8f);
				glTranslatef(0.0f, 0.0f, 0.01f);
				glColor3ub(88, 88, 88);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.6f, 0.0f);
					glVertex3f(-4.0f, 1.6f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// atas
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 1, 0, 0);
				glTranslatef(2.0f, -2.5f, -5.0f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -4.0f, 0.0f);
					glVertex3f(4.0f, -4.0f, 0.0f);
					glVertex3f(4.0f, 0.715f, 0.0f);
					glVertex3f(-4.0f, 0.715f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// belakang
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glTranslatef(2.0f, 4.0f, -6.5f);
				glBegin(GL_QUADS);
					glVertex3f(-4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.0f, 0.0f);
					glVertex3f(-4.0f, 1.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// kiri
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 0, 1, 0);
				glTranslatef(2.5f, 4.0f, 6.0f);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.0f, 0.0f);
					glVertex3f(-0.7f, 1.0f, 0.0f);
				glEnd();
				
				// kaca kiri
				glScalef(0.6f, 0.8f, 0.7f);
				glTranslatef(0.16f, -0.2f, 0.01f);
				glColor3ub(88, 88, 88);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.0f, 0.0f);
					glVertex3f(-0.7f, 1.0f, 0.0f);
				glEnd();
			glPopMatrix();
			
			// kanan
			glPushMatrix();
				glColor3ub(255, 27, 30);
				glRotated(90, 0, 1, 0);
				glTranslatef(2.5f, 4.0f, -2.0f);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.0f, 0.0f);
					glVertex3f(-0.7f, 1.0f, 0.0f);
				glEnd();
				
				// kaca kanan
				glScalef(0.6f, 0.8f, 0.7f);
				glTranslatef(0.16f, -0.2f, -0.01f);
				glColor3ub(88, 88, 88);
				glBegin(GL_QUADS);
					glVertex3f(-3.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, -3.0f, 0.0f);
					glVertex3f(4.0f, 1.0f, 0.0f);
					glVertex3f(-0.7f, 1.0f, 0.0f);
				glEnd();
			glPopMatrix();
		
		glPopMatrix();
	
	glPopMatrix();

// --------------------------------------------------------------------------------------------------------------------
	
	// Badan truk utama
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -4.0f);
	glColor3ub(0, 0, 0);
		// depan
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -2.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// atas
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// belakang
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -20.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// bawah
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -1.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kiri
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, 6.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kanan
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();

// --------------------------------------------------------------------------------------------------------------------

	// Sambungan
	glPushMatrix();
	glTranslatef(2.0f, 0.0f, -20.0f);
	glColor3ub(0, 0, 0);
		// atas
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(0.5f, -6.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-0.5f, -1.0f, 0.0f);
				glVertex3f(0.0f, -1.0f, 0.0f);
				glVertex3f(0.0f, 2.5f, 0.0f);
				glVertex3f(-0.5f, 2.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// bawah
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(0.5f, -6.5f, -1.0f);
			glBegin(GL_QUADS);
				glVertex3f(-0.5f, -1.0f, 0.0f);
				glVertex3f(0.0f, -1.0f, 0.0f);
				glVertex3f(0.0f, 2.5f, 0.0f);
				glVertex3f(-0.5f, 2.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kiri
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(5.0f, 1.5f, 0.5f);
			glBegin(GL_QUADS);
				glVertex3f(-1.0f, -0.5f, 0.0f);
				glVertex3f(2.5f, -0.5f, 0.0f);
				glVertex3f(2.5f, 0.5f, 0.0f);
				glVertex3f(-1.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kanan
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(5.0f, 1.5f, 0.0f);
			glBegin(GL_QUADS);
				glVertex3f(-1.0f, -0.5f, 0.0f);
				glVertex3f(2.5f, -0.5f, 0.0f);
				glVertex3f(2.5f, 0.5f, 0.0f);
				glVertex3f(-1.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();

// --------------------------------------------------------------------------------------------------------------------

	// Badan truk gandengan
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -25.0f);
	glColor3ub(0, 0, 0);
		// depan
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -2.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// atas
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// belakang
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -20.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// bawah
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -1.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kiri
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, 6.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kanan
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 0.5f, 0.0f);
				glVertex3f(-4.0f, 0.5f, 0.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();	
	
// --------------------------------------------------------------------------------------------------------------------

	// Container pertama
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -4.0f);
	glColor3ub(58, 0, 178);
		// depan
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -2.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// atas
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -11.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// belakang
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -20.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// bawah
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -1.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kiri
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, 6.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kanan
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();

// --------------------------------------------------------------------------------------------------------------------
	
	// Container kedua
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -25.0f);
	glColor3ub(58, 0, 178);
		// depan
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -2.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// atas
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -11.5f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// belakang
		glPushMatrix();
			glTranslatef(2.0f, 1.5f, -20.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// bawah
		glPushMatrix();
			glRotated(90, 1, 0, 0);
			glTranslatef(2.0f, -19.5f, -1.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, -0.5f, 0.0f);
				glVertex3f(4.0f, 17.0f, 0.0f);
				glVertex3f(-4.0f, 17.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kiri
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, 6.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
		// kanan
		glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslatef(6.5f, 1.5f, -2.0f);
			glBegin(GL_QUADS);
				glVertex3f(-4.0f, -0.5f, 0.0f);
				glVertex3f(13.5f, -0.5f, 0.0f);
				glVertex3f(13.5f, 10.0f, 0.0f);
				glVertex3f(-4.0f, 10.0f, 0.0f);
			glEnd();
		glPopMatrix();
		
	glPopMatrix();
	
// --------------------------------------------------------------------------------------------------------------------	
	
	// Roda
	int a;
	int b;
	
	// Roda badan utama depan
	glPushMatrix();	
	glTranslatef(0.0f, 0.0f, -1.0f);
	glColor3ub(30, 30, 32);
	glScalef(1.5f, 1.5f, 1.5f);
		
		// Roda Kanan
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -0.375f, -2.3f);
				
			// Sisi roda
			
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
		// Roda kiri
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -5.25f, -2.3f);
				
			// Sisi roda
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
	glPopMatrix();
	
	//.......................................................................................
	
	// Roda badan utama belakang
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -18.0f);
	glColor3ub(30, 30, 32);
	glScalef(1.5f, 1.5f, 1.5f);
		
		// Roda Kanan
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -0.375f, -2.3f);
				
			// Sisi roda
			
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
		// Roda kiri
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -5.25f, -2.3f);
				
			// Sisi roda
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
	glPopMatrix();
	
	//.......................................................................................
	
	// Roda badan sambungan depan
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -26.5f);	
	glColor3ub(30, 30, 32);
	glScalef(1.5f, 1.5f, 1.5f);
		
		// Roda Kanan
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -0.375f, -2.3f);
				
			// Sisi roda
			
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
		// Roda kiri
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -5.25f, -2.3f);
				
			// Sisi roda
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
	glPopMatrix();
	
	//.......................................................................................
	
	// Roda badan sambungan belakang
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -39.0f);
	glColor3ub(30, 30, 32);
	glScalef(1.5f, 1.5f, 1.5f);
		
		// Roda Kanan
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -0.375f, -2.3f);
				
			// Sisi roda
			
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
		// Roda kiri
		glPushMatrix();
			glRotated(90, 0, 0, 1);
			glTranslatef(1.0f, -5.25f, -2.3f);
				
			// Sisi roda
			glPushMatrix();
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			glPushMatrix();
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_TRIANGLE_FAN);
				for (a = 0; a <= 360; a+=1){
					glVertex3f(cos(a), 1, sin(a));
				}
				glEnd();
			glPopMatrix();
				
			// Selubung roda
			glPushMatrix();	
				glTranslatef(0.0f, 1.0f, 0.0f);
				glBegin(GL_QUAD_STRIP);
				for (b=0; b<=360; b+=1){
					glVertex3f(cos(b), +1, sin(b));
					glVertex3f(cos(b), 0, sin(b));
				}
				glEnd();
			glPopMatrix();
			
		glPopMatrix();
	
	glPopMatrix();
	
}
