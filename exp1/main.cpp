#include "Angel.h"

#pragma comment(lib, "glew32.lib")

const int NUM_POINTS = 3;

void init()
{
	// ���������ε�������
	vec2 vertices[3] = {
		vec2(-0.75, -0.75), vec2(0.0, 0.75), vec2(0.75, -0.75)
	};

	// ���������������
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// ��������ʼ�����㻺�����
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ��ȡ��ɫ����ʹ��
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);

	// �Ӷ�����ɫ���г�ʼ�������λ��
	GLuint location = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	// ��ɫ����
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display(void)
{
	// ������
	glClear(GL_COLOR_BUFFER_BIT);
	// �������е�
	glDrawArrays(GL_TRIANGLES, 0, NUM_POINTS);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);

	// ����Ƿ�ʹ����freeglut��������Ƿ�ʹ�õ���OpenGL 3.3
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutCreateWindow("Red Triangle");

	glewExperimental = GL_TRUE;
	glewInit();

	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
