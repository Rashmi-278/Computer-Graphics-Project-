
#include <GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); // White display window.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}
int choice = 0;
char line3[100] = { "Dispersion of light: Text is initially displayed , click on window to display animation" };
char line2[100] = { " Right click on mouse to display menu options " };
char line1[100] = { "Computer Graphics project : Dispersion of light and wave superimposition " };
char line4[100] = { "Wave superimposition: Enter wave paramwters " };
char line5[100] = { "Wave number , wavelength , amplitude frequency , phase" };
char line6[100] = { "Click on the window to start animation" };

void keyquit(unsigned char key, int x, int y);
void menu(int id);
void displayText(float x, float y, int r, int g, int b, const char *string) {
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	glFlush();

}

void displayfirst(void) {
	displayText(60, 450, 1, 0, 0, line1);
	displayText(60, 400, 0, 1, 0, line2);
	displayText(60, 200, 0, 0, 1, line3);
	displayText(80, 150, 0, 1, 0, line4);
	displayText(80, 100, 0, 1, 0, line5);
	displayText(80, 50, 0, 1, 0, line6);

}

void keys(unsigned char key, int x, int y)
{

	if (key == '1') {

		glClear(GL_COLOR_BUFFER_BIT);
		displayfirst();
	}

	if (key == '2') {
		glClear(GL_COLOR_BUFFER_BIT);
		displayText(250, 400, 1, 1, 1, line1);

	}


}
// dispersionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

GLfloat dline = 0.0f, dline2 = 0.0f, textinc = 0.0;
GLfloat x_position, y_position;
GLboolean rayflag = false, deviateflag = false, textflag = false;
GLboolean yaflag = false;

char dline1[100] = { "DISPERSION OF LIGHT" };
char dline22[400] = { "In optics,dispersion is the phenomenon in which the phase velocity of a wave depends on its frequency" };
char dline3[400] = { "Dispersion is most easily seen in light, when all the colors inside white light become separated by a prism." };
char dline4[400] = { "Upon passage through the prism, the white light is separated into " };
char dline5[400] = { "its component colors - red, orange, yellow, green, blue and violet. " };
char dline6[400] = { " The separation of visible light into its different colors is known as dispersion" };


void displayfirstdisp(void) {
	displayText(-45, 50, 0, 0, 1, dline1);
	displayText(-180, 40, 1, 1, 1, dline22);
	displayText(-180, 30, 1, 1, 1, dline3);
	displayText(-180, 20, 1, 1, 1, dline4);
	displayText(-180, 10, 1, 1, 1, dline5);
	displayText(-180, 0, 1, 1, 1, dline6);

}
void darkSide(double a, double b, double c, double d, double e, double f, double g, double h) {
	glBegin(GL_POLYGON);
	glVertex3f(a, b, 0);
	glVertex3f(c, d, 0);
	glVertex3f(e, f, 0);
	glVertex3f(g, h, 0);
	glEnd();
}

void displaylight(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//set color as white
	glColor3f(1, 1, 1);


	if (!textflag)
	{

		//if (!yaflag)
		//{
		displayfirstdisp();
		//}

	}


	if (textflag)
	{
		// background color - black
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		//set color as white
		glColor3f(1, 1, 1);

		// draw the main triangle
		glBegin(GL_LINE_LOOP);
		glVertex3f(-40, -40, 0);
		glVertex3f(40, -40, 0);
		glVertex3f(0, 40, 0);
		glEnd();


		// white light 

		x_position = -200;
		y_position = -50;
		glBegin(GL_LINES);
		glPointSize(3.0);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-200, -50, 0);
		dline += 1.0f;
		dline2 += 0.275f;
		x_position += dline;
		y_position += dline2;
		if (x_position < -20) {
			glVertex3f(x_position, y_position, 0.0);
		}
		else
		{
			glVertex3f(-20, 0.0, 0.0);
			rayflag = true;
		}
		glEnd(); //end of white light
		// draw the triangle inside the main triangle
		if (rayflag)
		{
			glColor3f(.9, .9, .9);
			glBegin(GL_TRIANGLES);
			glVertex3f(-20, 0, 0);
			glVertex3f(25, -10, 0);
			glVertex3f(15, 10, 0);
			deviateflag = true;
			glEnd();
		}
		if (deviateflag)
		{
			// set color as red 
			glColor3f(1, 0, 0);
			darkSide(15, 10, (51 / 3), (20 / 3), 200, -(65 / 3), 200, -15);
			// set color as orange    
			glColor3f(1, 0.5, 0);
			darkSide((51 / 3), (20 / 3), (55 / 3), (10 / 3), 200, -(85 / 3), 200, -(65 / 3));
			// set color as yellow 
			glColor3f(1, 1, 0);
			darkSide((55 / 3), (10 / 3), 20, 0, 200, -35, 200, -(85 / 3));
			// set color as green   
			glColor3f(0, 1, 0);
			darkSide(20, 0, (65 / 3), -(10 / 3), 200, -(125 / 3), 200, -35);
			// set color as light blue    
			glColor3f(0, 1, 1);
			darkSide((65 / 3), -(10 / 3), (70 / 3), -(20 / 3), 200, -(145 / 3), 200, -(125 / 3));
			// set color as purple    
			glColor3f(1, 0, 1);
			darkSide((70 / 3), -(20 / 3), 25, -10, 200, -55, 200, -(145 / 3));
		}
		glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
	}//animate

	// show the drawing on screen using OpenGL
	glFlush();
}
/* Called back when timer expired [NEW] */
void timerlight(int value) {
	textinc += 1.0;
	if (textinc > 150)
	{
		textflag = true;
		yaflag = true;

	}//text flag set
	if (textflag)
	{
		glutPostRedisplay();
	}

	// Post re-paint request to activate display()
	glutTimerFunc(10, timerlight, 0); // next timer call milliseconds later


}

void inicializa(void)
{
	// background color - black
	glClearColor(0, 0, 0, 0);
}

// auto-rezise callback
void redimensiona(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200, 200, -100, 100, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void maininitdisp(int)
{

	// Start Glut Window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1100, 500);
	glutInitWindowPosition(100, 100);
	// create and open the window
	glutCreateWindow("Dispersion of light");
	glutCreateMenu(menu);
	glutAddMenuEntry("INTRO", 1);
	glutAddMenuEntry("DISPERSION OF LIGHT", 2);
	glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	// register the callbacks
	glutDisplayFunc(displaylight);
	glutReshapeFunc(redimensiona);
	glutKeyboardFunc(keyquit);
	inicializa();
	glutTimerFunc(0, timerlight, 0);
	//glutTimerFunc(0, maininitdisp, 0);


}
// waavvvvvvvvveeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

float wave_ordinate(float, float, float, float, float);

struct wave
{
	float k, w, A, phi;
}w1, w2;

float time = 0.0;

void waveinit()
{
	glLineWidth(3.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void wavereshape(int w, int h)
{
	glViewport(0, 0, 16 * 30, 9 * 30);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 160, 0, 90);
	glMatrixMode(GL_MODELVIEW);
}


void wavedisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.0, 0.0, 1.0);

	glTranslatef(0.0, 75.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (float x = 0; x < 160; x += 0.5)
	{
		float y = wave_ordinate(w1.k, w1.w, w1.A, w1.phi, x);
		glVertex2d(x, y);
	}
	glEnd();

	glTranslatef(0.0, -30.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (float x = 0; x < 160; x += 0.5)
	{
		float y = wave_ordinate(w2.k, w2.w, w2.A, w2.phi, x);
		glVertex2d(x, y);
	}

	glEnd();

	glColor3f(1.0, 0.0, 0.0);

	glTranslatef(0.0, -30.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (float x = 0; x < 160; x += 0.5)
	{
		float y = wave_ordinate(w1.k, w1.w, w1.A, w1.phi, x) + wave_ordinate(w2.k, w2.w, w2.A, w2.phi, x);
		glVertex2d(x, y);
	}

	glEnd();


	glutSwapBuffers();
}

void wavetimer(int)
{
	glutPostRedisplay();
	time += 0.5;
	glutTimerFunc(1000.0 / 60.0, wavetimer, 0);
}

float wave_ordinate(float k, float w, float A, float phi, float x)
{
	return A * sin((k*x) - (w*time) + phi);
}

void maininitwave()
{
	int a;
	std::cout << "\t[*] Enter the parameters 'k', 'w', 'A' and phase(phi) for two waves:\n";

	//wave 1
	std::cout << "\t[*]Wave 1 :\n\t\tk = "; std::cin >> w1.k;
	std::cout << "\t\tw = "; std::cin >> w1.w;
	std::cout << "\t\tA = "; std::cin >> w1.A;
	std::cout << "\t\tphi = "; std::cin >> w1.phi;
	std::cout << "\n\t[*] w1 = " << w1.A << "sin( " << w1.k << "x - " << w1.w << "t )\n\n";

	//wave 2
	std::cout << "\t[*]Wave 2 :\n\t\tk = "; std::cin >> w2.k;
	std::cout << "\t\tw = "; std::cin >> w2.w;
	std::cout << "\t\tA = "; std::cin >> w2.A;
	std::cout << "\t\tphi = "; std::cin >> w2.phi;
	std::cout << "\n\t[*] w2 = " << w2.A << "sin( " << w2.k << "x - " << w2.w << "t )\n\n";

	std::cout << "\t=>The third wave on your screen\n\t  will be the superimposed wave";



	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(16 * 30, 9 * 30);
	glutCreateWindow("Wave Superposition ");
	glutCreateMenu(menu);
	glutAddMenuEntry("INTRO", 1);
	glutAddMenuEntry("DISPERSION OF LIGHT", 2);
	glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	waveinit();
	glutReshapeFunc(wavereshape);
	glutDisplayFunc(wavedisplay);
	glutKeyboardFunc(keyquit);
	glutTimerFunc(10, wavetimer, 0);
}
// keyboard event callback
void keyquit(unsigned char key, int x, int y)
{
	switch (key)
	{
		// ESC
	case 27:
		exit(0); // quit
		break;
	default:
		break;
	}
}
void menu(int id)
{
	switch (id)
	{
	case 1: choice = 1;
		glClear(GL_COLOR_BUFFER_BIT);

		displayfirst();
		break;
	case 2: // Dispersion of light 
		choice = 2;

		maininitdisp(0);

		break;
	case 3: // wave superimposition
		choice = 3;

		maininitwave();

	default:
		break;
	}


}
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	glClear(GL_COLOR_BUFFER_BIT);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	switch (choice)


	{
	case 0:
	case 1:
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(1000, 500);
		glutCreateWindow("FRONT PAGE");
		init();
		glutDisplayFunc(displayfirst);
		glutCreateMenu(menu);
		glutAddMenuEntry("INTRO", 1);
		glutAddMenuEntry("DISPERSION OF LIGHT", 2);
		glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutKeyboardFunc(keyquit);
		glutReshapeFunc(winReshapeFcn);
		break;

	case 2:
		// Start Glut Window
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
		glutInitWindowSize(1100, 500);
		glutInitWindowPosition(100, 100);

		// create and open the window
		glutCreateWindow("Dispersion of light");

		// register the callbacks
		glutDisplayFunc(displaylight);
		glutReshapeFunc(redimensiona);
		glutKeyboardFunc(keyquit);
		glutCreateMenu(menu);
		glutAddMenuEntry("INTRO", 1);
		glutAddMenuEntry("DISPERSION OF LIGHT", 2);
		glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		inicializa();
		glutTimerFunc(0, timerlight, 0);
		// start glut loop

		break;
	case 3:

		int a;
		std::cout << "\t[*] Enter the parameters 'k', 'w', 'A' and phase(phi) for two waves:\n";

		//wave 1
		std::cout << "\t[*]Wave 1 :\n\t\tk = "; std::cin >> w1.k;
		std::cout << "\t\tw = "; std::cin >> w1.w;
		std::cout << "\t\tA = "; std::cin >> w1.A;
		std::cout << "\t\tphi = "; std::cin >> w1.phi;
		std::cout << "\n\t[*] w1 = " << w1.A << "sin( " << w1.k << "x - " << w1.w << "t )\n\n";

		//wave 2
		std::cout << "\t[*]Wave 2 :\n\t\tk = "; std::cin >> w2.k;
		std::cout << "\t\tw = "; std::cin >> w2.w;
		std::cout << "\t\tA = "; std::cin >> w2.A;
		std::cout << "\t\tphi = "; std::cin >> w2.phi;
		std::cout << "\n\t[*] w2 = " << w2.A << "sin( " << w2.k << "x - " << w2.w << "t )\n\n";

		std::cout << "\t=>The third wave on your screen\n\t  will be the superimposed wave";


		glutInit(&argc, argv);



		glutInitDisplayMode(GLUT_DOUBLE);
		glutInitWindowSize(16 * 30, 9 * 30);
		glutCreateWindow("Wave Superposition ");

		waveinit();
		glutCreateMenu(menu);
		glutAddMenuEntry("INTRO", 1);
		glutAddMenuEntry("DISPERSION OF LIGHT", 2);
		glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutReshapeFunc(wavereshape);
		glutKeyboardFunc(keyquit);
		glutDisplayFunc(wavedisplay);
		glutTimerFunc(10, wavetimer, 0);
		break;
	}
	glutCreateMenu(menu);
	glutAddMenuEntry("INTRO", 1);
	glutAddMenuEntry("DISPERSION OF LIGHT", 2);
	glutAddMenuEntry("WAVE SUPERIMPOSITION", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(keyquit);
	glutMainLoop();
}