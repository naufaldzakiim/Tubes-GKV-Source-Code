#include <GL/glut.h>
#include <stdio.h>
#include "gimTruckHeader.h"

float angle=0.0, deltaAngle = 0.0;
float angle2=0.0, deltaAngle2 = 0.0; 
int deltaMove = 0;

float trukPosZ = 0.0, trukPosX = 0.0;
float trukMoveZ = 0.0, trukMoveX = 0.0;
float gerbangPosY = 0.0, gerbangPosZ = 200.0f;

int gerbang = 0;

void display()
{ 
 	// Kalau move dan angle tidak nol, gerakkan kamera... 
 	if (deltaMove) 
		 moveMeFlat(deltaMove);	  
 	
	if (deltaAngle){ 
 		angle += deltaAngle; 
 		orientMe(angle);
	} 
 	
	if (deltaAngle2){ 
 		angle2 += deltaAngle2; 
 		orientMe2(angle2);
 	}
 	
 	if (trukMoveX || trukMoveZ){
 		cameraOnTruk(trukMoveX, trukMoveZ);
 		trukMoveX = 0;
 		trukMoveZ = 0;
 	}
 	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 	
 	// Gambar objek real
 	glPushMatrix();
		Land(); // Objek tanah bertekstur pasir
		Road(); // Objek jalan bertekstur aspal
		Bangunan(); // Objek kumpulan gedung bertekstur bangunan pencakar langit
		
		// Objek gerbang
		glPushMatrix();
			pergerakanGerbang();
			glTranslatef(0, gerbangPosY, gerbangPosZ);
			Gerbang();
		glPopMatrix();
	 	
	 	// Objek Truk Gandeng
		glPushMatrix();
			glTranslatef(-2 + trukPosX, 0, trukPosZ);
			trukGandeng();
		glPopMatrix();
	glPopMatrix();
	
	glutSwapBuffers(); 
 	glFlush(); 
}

void pressKey(int key, int x, int y){ 
 	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas 
 	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
 	switch (key) { 
 		case GLUT_KEY_DOWN : deltaAngle2 = -0.01f;break; 
 		case GLUT_KEY_UP : deltaAngle2 = 0.01f;break;
	 	case GLUT_KEY_RIGHT : deltaAngle = -0.01f;break; 
 		case GLUT_KEY_LEFT : deltaAngle = 0.01f;break; 
 		case GLUT_KEY_PAGE_UP : deltaMove = 1;break; 
 		case GLUT_KEY_PAGE_DOWN : deltaMove = -1;break;
 	} 
} 

void releaseKey(int key, int x, int y){ 
 	// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
 	// Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti 
 	switch (key){ 
 		case GLUT_KEY_DOWN : if (deltaAngle2 < 0.0f) 
 			deltaAngle2 = 0.0f; 
			break; 
 		case GLUT_KEY_UP : if (deltaAngle2 > 0.0f) 
 			deltaAngle2 = 0.0f; 
 			break;
		case GLUT_KEY_RIGHT : if (deltaAngle < 0.0f) 
 			deltaAngle = 0.0f; 
			break; 
 		case GLUT_KEY_LEFT : if (deltaAngle > 0.0f) 
 			deltaAngle = 0.0f; 
 			break; 
 		case GLUT_KEY_PAGE_UP : if (deltaMove > 0) 
 			deltaMove = 0; 
 			break; 
 		case GLUT_KEY_PAGE_DOWN : if (deltaMove < 0) 
 			deltaMove = 0; 
 			break; 
 	} 
} 

void pressKeyboard(unsigned char key, int x, int y){
	switch (key){
		case 'w': // Gerak maju
			// Kondisi jika gerbang terbuka
			if (gerbang != 0)
			{
				if (trukPosZ < 1000){
					trukPosZ += 1;
					trukMoveZ = 1;
				}
				else{
					trukPosZ = 1000;
					trukMoveZ = 0;
				}
			}
			
			// Kondisi jika gerbang menutup
			else{
				if (trukPosZ < 1000){
					trukPosZ += 1;
					trukMoveZ = 1;
				}
				else{
					trukPosZ = 1000;
					trukMoveZ = 0;
				}
				
				if (isMenabrak(gerbangPosZ, gerbangPosZ+1.1, -25, 25) == 1){
					trukPosZ = gerbangPosZ;
					trukMoveZ = 0;
				}
			}
			
		break; 
		
		
		case 's': // Gerak mundur
			// Kondisi jika gerbang terbuka
			if (gerbang != 0)
			{
				if (trukPosZ > -1000){
					trukPosZ -= 1;
					trukMoveZ = -1;
				}
				else{
					trukPosZ = -1000;
					trukMoveZ = 0;
				}
			}
			
			// Kondisi jika gerbang menutup
			else{
				if (trukPosZ > -1000){
					trukPosZ -= 1;
					trukMoveZ = -1;
				}
				else{
					trukPosZ = -1000;
					trukMoveZ = 0;
				}
				
				if (isMenabrak(gerbangPosZ, gerbangPosZ + 47.6, -25, 25) == 1){
					trukPosZ = gerbangPosZ + 47.6;
					trukMoveZ = 0;
				}
			}
			
		break;
		
		
		case 'a': // Gerak kiri
			// Kondisi jika gerbang terbuka
			if (gerbang != 0)
			{
				if (trukPosX < 45){
					trukPosX += 5;
					trukMoveX = 1;
				}
				else{
					trukPosX = 45;
					trukMoveX = 0;
				}
			}
			
			// Kondisi jika gerbang menutup
			else{
				if (trukPosX < 45){
					trukPosX += 5;
					trukMoveX = 1;
				}
				else{
					trukPosX = 45;
					trukMoveX = 0;
				}
				
				if (isMenabrak(gerbangPosZ, gerbangPosZ + 47.6, -25, -19) == 1){
					trukPosX = -25;	
					trukMoveX = 0;
				}
			}
			
		break; 
		
		
		case 'd': // Gerak kanan
			// Kondisi jika gerbang terbuka
			if (gerbang != 0)
			{
				if (trukPosX > -45){
					trukPosX -= 5;
					trukMoveX = -1;
				}
				else{
					trukPosX = -45;
					trukMoveX = 0;
				}
			}
			
			// Kondisi jika gerbang menutup
			else{
				if (trukPosX > -45){
					trukPosX -= 5;
					trukMoveX = -1;
				}
				else{
					trukPosX = -45;
					trukMoveX = 0;
				}
				
				if (isMenabrak(gerbangPosZ, gerbangPosZ + 47.6, 19, 25) == 1){
					trukPosX = 25;
					trukMoveX = 0;
				}
			}
			
		break;
		
		
		case 'q': // Membuka gerbang
			gerbang = 1;
		break; 
		
		
		case 'e': // Menutup gerbang
			gerbang = 3;
		break; 
		 
	 
	 	case 27: 
	 	exit(0);
	}
	
}

void pergerakanGerbang()
{
	if (gerbang == 1){
		if (gerbangPosY <= 15){
			gerbangPosY += 0.1;
		}
		
		if (gerbangPosY > 15){
			gerbang = 2;
		}
	}
	
	if (gerbang == 3){
		if (isMenabrak(gerbangPosZ, gerbangPosZ + 47.6, -25, 25) == 1){
			if (gerbangPosY > 12.6){
				gerbangPosY -= 0.1;
			}
			
			if (gerbangPosY <= 12.6){
				gerbang = 2;
			}	
		}
		
		else{
			if (gerbangPosY > 0){
				gerbangPosY -= 0.1;
			}
			
			if (gerbangPosY <= 0){
				gerbang = 0;
			}	
		}
	}
}

int isMenabrak(float batasBawahZ, float batasAtasZ, float batasBawahX, float batasAtasX)
{
	if ((trukPosZ > batasBawahZ && trukPosZ < batasAtasZ) && (trukPosX > batasBawahX && trukPosX < batasAtasX)){ // true jika truk menabrak objek
		return 1;
	}
	else{
		return 0;
	}
}
