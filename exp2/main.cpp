#include "Angel.h"

#pragma comment(lib, "glew32.lib")

const int MENU_CHOICE_WHITE = 0;
const int MENU_CHOICE_BLACK = 1;
const int MENU_CHOICE_RED = 2;
const int MENU_CHOICE_GREEN = 3;
const int MENU_CHOICE_BLUE = 4;
const int MENU_CHOICE_YELLOW = 5;
const int MENU_CHOICE_ORANGE = 6;
const int MENU_CHOICE_PURPLE = 7;

const vec3 WHITE(1.0, 1.0, 1.0);
const vec3 BLACK(0.0, 0.0, 0.0);
const vec3 RED(1.0, 0.0, 0.0);
const vec3 GREEN(0.0, 1.0, 0.0);
const vec3 BLUE(0.0, 0.0, 1.0);
const vec3 YELLOW(1.0, 1.0, 0.0);
const vec3 ORANGE(1.0, 0.65, 0.0);
const vec3 PURPLE(0.8, 0.0, 0.8);

// �����ڱ���
const int SQUARE_NUM = 6;
const int SQUARE_NUM_POINTS = 4 * SQUARE_NUM;
int mainWindow;
int mainWindowMenu;
int mainWindowSubmenu;
int width = 600;    // �����ڿ��
int height = 600;    // �����ڸ߶�
double offsetAngle = 0;    // �Ƕ�ƫ����
double delta = 0.05;    // ÿ�θı�Ƕ�ƫ�Ƶı仯��
vec3 mainWindowSquareColor = WHITE;

// �Ӵ��ڱ���
const int ELLIPSE_NUM_POINTS = 100;
int subWindow;
int subWindowMenu;
vec3 subWindowObjectColor = RED;

// ���Բ�ϵĵ�
vec2 getEllipseVertex(vec2 center, double scale, double verticleScale, double angle)
{
	vec2 vertex(sin(angle), cos(angle));
	vertex += center;
	vertex *= scale;
	vertex.y *= verticleScale;    // �޸Ĵ�ֱ����
	return vertex;
}

// ����Բ�϶��������
void generateEllipsePoints(vec2 vertices[], vec3 colors[], vec3 color, int startVertexIndex, int numPoints,
	vec2 center, double scale, double verticalScale)
{
	double angleIncrement = (2 * M_PI) / numPoints;
	double currentAngle = M_PI / 2;

	for (int i = startVertexIndex; i < startVertexIndex + numPoints; i++) {
		vertices[i] = getEllipseVertex(center, scale, verticalScale, currentAngle);
		colors[i] = color;

		currentAngle += angleIncrement;
	}
}

// ��������ε�ÿ���Ƕ�
double getSquareAngle(int point)
{
    return (M_PI / 4 + (M_PI / 2 * point)) + offsetAngle;
}

// �����������϶��������
void generateSquarePoints(vec2 vertices[], vec3 colors[], int squareNum, int startVertexIndex) {
	double scale = 0.90;
	double scaleAdjust = scale / squareNum;
	vec2 center(0.0, -0.25);

	int vertexIndex = startVertexIndex;

	for (int i = 0; i < squareNum; i++) {
		vec3 currentColor = 0 == i % 2 ? mainWindowSquareColor : BLACK;

		for (int j = 0; j < 4; j++) {
			double currentAngle = getSquareAngle(j);
			vertices[vertexIndex] = vec2(sin(currentAngle), cos(currentAngle)) * scale + center;
			colors[vertexIndex] = currentColor;

			vertexIndex++;
		}

		scale -= scaleAdjust;
	}
}

// ���лص�����
void idleFunction()
{
	// �ı�Ƕȵ�ƫ����
    offsetAngle += delta;
    // ����������ػ�
	glutPostWindowRedisplay(mainWindow);
}


void mainWindowInit()
{
	vec2 vertices[SQUARE_NUM * 4];
	vec3 colors[SQUARE_NUM * 4];

	// �����������ж��������
	generateSquarePoints(vertices, colors, SQUARE_NUM, 0);

	// ���������������
	GLuint vao[1];
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	// ��������ʼ�����㻺�����
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);

	// �ֱ��ȡ����
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

	// ��ȡ��ɫ����ʹ��
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// �Ӷ�����ɫ���г�ʼ�������λ��
	GLuint pLocation = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(pLocation);
	glVertexAttribPointer(pLocation, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	// ��ƬԪ��ɫ���г�ʼ���������ɫ
	GLuint cLocation = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(cLocation);
	glVertexAttribPointer(cLocation, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices)));
	
	// ��ɫ����
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

// �˵��ص�����
void mainWindowMenuEvents(int menuChoice)
{
	switch (menuChoice) {
	case MENU_CHOICE_WHITE:
		mainWindowSquareColor = WHITE;
		break;
	case MENU_CHOICE_BLACK:
		mainWindowSquareColor = BLACK;
		break;
	case MENU_CHOICE_RED:
		mainWindowSquareColor = RED;
		break;
	case MENU_CHOICE_GREEN:
		mainWindowSquareColor = GREEN;
		break;
	case MENU_CHOICE_BLUE:
		mainWindowSquareColor = BLUE;
		break;
	case MENU_CHOICE_YELLOW:
		mainWindowSquareColor = YELLOW;
		break;
	case MENU_CHOICE_ORANGE:
		mainWindowSquareColor = ORANGE;
		break;
	case MENU_CHOICE_PURPLE:
		mainWindowSquareColor = PURPLE;
		break;

    /*�ڴ˴���ӿ�����ת������ʼ��ֹͣ�Ĳ˵�ѡ��*/

	}

    // ���mainWindow�����ڽ����ػ�
	glutPostWindowRedisplay(mainWindow);
}

// ���������������ڲ˵�
void mainWindowSetupMenu()
{
	// �����Ӳ˵�����ע��˵��ص�����mainWindowMenuEvents
    mainWindowSubmenu = glutCreateMenu(mainWindowMenuEvents);
	glutAddMenuEntry("Yellow", MENU_CHOICE_YELLOW);
	glutAddMenuEntry("Orange", MENU_CHOICE_ORANGE);
	glutAddMenuEntry("Purple", MENU_CHOICE_PURPLE);
	glutAddMenuEntry("Black", MENU_CHOICE_BLACK);

    // �������˵�
	mainWindowMenu = glutCreateMenu(mainWindowMenuEvents);
	glutAddMenuEntry("Red", MENU_CHOICE_RED);
	glutAddMenuEntry("Green", MENU_CHOICE_GREEN);
	glutAddMenuEntry("Blue", MENU_CHOICE_BLUE);
	glutAddMenuEntry("White", MENU_CHOICE_WHITE);
    
    // �����˵�������Ӳ˵�
	glutAddSubMenu("Other Square Colors", mainWindowSubmenu);
    
    // ��������Ҽ�����˵�
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void mainWindowDisplay()
{
	mainWindowInit();    // �ػ�ʱд���µ���ɫ����
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < SQUARE_NUM; i++) {
		glDrawArrays(GL_TRIANGLE_FAN, (i * 4), 4);
	}

	glutSwapBuffers();
}

// �����ڼ��̻ص�����
void mainWindowKeyboard(unsigned char key, int x, int y)
{
	/*�ڴ���Ӱ���Esc�����˳��Ĵ���*/
}

// ���������ص�����
void mainWindowMouse(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		// ��������м���ָ����û�������¼�����ʱ��ȥ����idleFunction()�������
		glutIdleFunc(idleFunction);
	} else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
		// �ͷ�����м����������
		glutIdleFunc(NULL);
	}
}


void subWindowInit()
{
	vec2 vertices[ELLIPSE_NUM_POINTS];
	vec3 colors[ELLIPSE_NUM_POINTS];

	// �����Ӵ����е���Բ
	generateEllipsePoints(vertices, colors, subWindowObjectColor, 0, ELLIPSE_NUM_POINTS,
		vec2(0.0, 0.0), 0.7, 0.5);

	// ���������������
	GLuint vao[1];
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	// ��������ʼ�����㻺�����
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);

	// �ֱ��ȡ����
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

	// ��ȡ��ɫ��������
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// �Ӷ�����ɫ���г�ʼ�������λ��
	GLuint pLocation = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(pLocation);
	glVertexAttribPointer(pLocation, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	// ��ƬԪ��ɫ���г�ʼ���������ɫ
	GLuint cLocation = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(cLocation);
	glVertexAttribPointer(cLocation, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices)));

	// �����Ӵ��ڱ�����ɫΪ��ɫ
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void subWindowDisplay()
{
	subWindowInit();    // �ػ�ʱд���µ���ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLE_FAN, 0, ELLIPSE_NUM_POINTS);
	glutSwapBuffers();
}

// �Ӵ��ڼ��̻ص�����
void subWindowKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'r':
		subWindowObjectColor = RED;
		break;
	case 'g':
		subWindowObjectColor = GREEN;
		break;
	case 'b':
		subWindowObjectColor = BLUE;
		break;
	case 'y':
		subWindowObjectColor = YELLOW;
		break;
	case 'o':
		subWindowObjectColor = ORANGE;
		break;
	case 'p':
		subWindowObjectColor = PURPLE;
		break;
	case 'w':
		subWindowObjectColor = WHITE;
		break;
	}

    // ���subWindow�Ӵ��ڽ����ػ�
	glutPostWindowRedisplay(subWindow);
}


void printHelp() {
	printf("%s\n\n", "Interaction and Submenu");
	printf("Keys to update the background color in sub window:\n");
	printf("'r' - red\n'g' - green\n'b' - blue\n'y' - yellow\n'o' - orange\n'p' - purple\n'w' - white\n");
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);    // ����˫�ػ���
	glutInitWindowSize(width, height);
	mainWindow = glutCreateWindow("Interaction and Submenu");

	glewExperimental = GL_TRUE;
	glewInit();
	
	mainWindowInit();
	mainWindowSetupMenu();
	glutDisplayFunc(mainWindowDisplay);
    // ����������ָ������mainWindowMouse������갴�»��ͷ�ʱ���ᱻ����
	glutMouseFunc(mainWindowMouse);

	// �����Ӵ���
	subWindow = glutCreateSubWindow(mainWindow, 0, 0, width / 4, height / 4);
	subWindowInit();
	glutDisplayFunc(subWindowDisplay);
    // ���Ӵ�����ָ������subWindowKeyboard����һ���ܹ�����ASCII�ַ��ļ��ͷ�ʱ�ᱻ����
	glutKeyboardFunc(subWindowKeyboard);

	// ���������Ϣ
	printHelp();

	glutMainLoop();
	return 0;
}
