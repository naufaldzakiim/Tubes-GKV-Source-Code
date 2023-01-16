#ifndef truckGemingHeader_H
#define truckGemingHeader_H

// Display
void display();

// Keyboard
void pressKeyboard(unsigned char key, int x, int y);
void pressKey(int key, int x, int y);
void releaseKey(int key, int x, int y);

// Truk gandeng
void trukGandeng();

// Interaksi Objek
void pergerakanGerbang();
int isMenabrak(float batasBawahZ, float batasAtasZ, float batasBawahX, float batasAtasX);

// Dunia
void Land();
void Road();
void Bangunan();
void Gerbang();

// Objects textures
void batu1(float size);
void gedung1(float size);
void gedung2(float size);
void kubusTekstur(float size, GLuint _namaTekstur);
void tanahTekstur();
void jalanTekstur();

// Pencahayaan
void lighting();

// Pergerakan Kamera
void Reshape(int w1, int h1);
void orientMe(float ang);
void orientMe2(float ang);
void moveMeFlat(int i);
void cameraOnTruk(int trukMoveX, int trukMoveZ);

// Class untuk imageLoader
class Image
{
	public:
		Image(char* ps, int w, int h);
		~Image();

	char* pixels;
	int width;
	int height;
};
//Reads a bitmap image from file.
Image* loadBMP(const char* filename);
void initRendering();

#endif
