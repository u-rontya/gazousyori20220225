#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
//exit���g���ۂɕK�v
#include <stdlib.h>

//�摜�T�C�Y���`����
#define X_SIZE 640
#define Y_SIZE 480
int h = 640;
int w = 480;
#define high 255;
#define low 0;
//�ǂݍ��݂ƕۑ��p�̃t�@�C���p�X��p��
char read_path[500];
char save_path[500];

//���͂�RGB�l��p��
unsigned char r_in[Y_SIZE][X_SIZE], g_in[Y_SIZE][X_SIZE], b_in[Y_SIZE][X_SIZE];
unsigned char r[Y_SIZE][X_SIZE], g[Y_SIZE][X_SIZE], b[Y_SIZE][X_SIZE];
//�O���C�摜�̏o�͐�̗�
unsigned char gray[Y_SIZE][X_SIZE];
//�摜���H�̒��p�_
unsigned char save[Y_SIZE][X_SIZE];
unsigned char saver[Y_SIZE][X_SIZE];
unsigned char saveg[Y_SIZE][X_SIZE];
unsigned char saveb[Y_SIZE][X_SIZE];


//�֐��̃v���g�^�C�v��錾����
void read_img(char* read_path, unsigned char r_in[Y_SIZE][X_SIZE], unsigned char g_in[Y_SIZE][X_SIZE], unsigned char b_in[Y_SIZE][X_SIZE]);

void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE]);
void hanten_img(unsigned char img[Y_SIZE][X_SIZE]);
void zyouge_img(unsigned char img[Y_SIZE][X_SIZE]);
void kaiten_img(unsigned char img[Y_SIZE][X_SIZE]);
void yokokagami01_img(unsigned char img[Y_SIZE][X_SIZE]);
void yokokagami02_img(unsigned char img[Y_SIZE][X_SIZE]);
void tatekagami01_img(unsigned char img[Y_SIZE][X_SIZE]);
void tatekagami02_img(unsigned char img[Y_SIZE][X_SIZE]);
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE]);
void nitika_img(unsigned char img[Y_SIZE][X_SIZE], int n);
//���C���ƂȂ�֐�
void main(void)
{
	char syori[50];
	char nitika[3];
	int sikii;
	for (int i = 0; i < 1;)
	{
		printf("�O���C�Ȃ�O���C�X�P�\��,�O���C�X�P�[�����]�Ȃ�G���],�O���C�X�P�[���㉺���]�Ȃ�G�㉺���],�O���C�X�P�[���㉺���E���]�Ȃ�G�㉺���E���],�J���[�ۑ��Ȃ�J���[,Exit\n");
		scanf("%s",&syori);
	
		 if (strcmp(syori, "�O���C")==0)
		{
			//���͉摜�̓ǂݍ���
			read_img(read_path, r_in, g_in, b_in);

			//�O���C�X�P�[����
			gray_img(r_in, g_in, b_in, gray);
			printf("2�l�����܂���YES�ANO��");
			scanf("%s", &nitika);
			if(strcmp(nitika, "yes") == 0)
			{
				printf("�������l�����߂Ă�������");
				scanf("%d", &sikii);
				nitika_img(gray, sikii);
				save_img(save_path, gray);
			}
			else
			{
				//�o�͉摜�̕ۑ�
				save_img(save_path, gray);
			}
		}

		 else if (strcmp(syori, "G���]") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //���]����
			 hanten_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�㉺���]") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���]
			 zyouge_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�㉺���E���]") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���E���]
			 kaiten_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�����킹") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���E���]
			 yokokagami01_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�����킹�t") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���E���]
			 yokokagami02_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�����킹�㉺") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���E���]
			 tatekagami01_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G�����킹�㉺�t") == 0)
		 {
			 //���͉摜�̓ǂݍ���
			 read_img(read_path, r_in, g_in, b_in);
			 //�O���C�X�P�[����
			 gray_img(r_in, g_in, b_in, gray);
			 //�㉺���E���]
			 tatekagami02_img(gray);
			 //�o�͉摜�̕ۑ�
			 save_img(save_path, gray);
		 }
		else
		{
			exit(-1);
		}
	}
}

//���͉摜�̓ǂݍ���
void read_img(char* read_path, unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE])
{
	int i, j;

	//�t�@�C�����߂̃t�@�C����p��
	printf("�ǂݍ��ރt�@�C��-->");
	//�W�����͂��o�b�t�@�Ɋi�[����
	scanf("%s", read_path);

	FILE* fp;

	//�t�@�C�����J��
	fp = fopen(read_path, "rb");

	//�����C�t�@�C���������Ƃ��ɏI��������
	if (fp == NULL)
	{
		printf("�t�@�C�������݂��܂���", read_path);
		exit(-1);
	}

	//�摜������RGB�l�̎擾�i���X�^�����j
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			r[j][i] = fgetc(fp);
			g[j][i] = fgetc(fp);
			b[j][i] = fgetc(fp);
		}
	}
	//�t�@�C�������
	fclose(fp);
}

//�O���C��
void gray_img(unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE], unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			img[j][i] = (unsigned char)(0.30 * r[j][i] + 0.59 * g[j][i] + 0.11 * b[j][i]);
		}
	}
}

//�o�͉摜�̕ۑ�(�O���C)
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	FILE* fp;

	printf("�ǂ̃t�@�C���ɕۑ����܂����H-->");
	scanf("%s", save_path);

	//�t�@�C�����J��
	fp = fopen(save_path, "wb");

	////�����C�t�@�C���������Ƃ��ɏI��������
	if (fp == NULL)
	{
		printf("�t�@�C�������݂��܂���", save_path);
		exit(-1);
	}
	//�摜��RGB�l���t�@�C���ɕۑ�����
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			fputc(img[j][i], fp);
		}
	}
	//�t�@�C�������
	fclose(fp);
}

//���]����(�O���C)
void hanten_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	int tem;
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < (X_SIZE/2); i++)
		{
			save[j][i] = img[j][X_SIZE-i];
			img[j][X_SIZE - i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//�㉺���]����(�O���C)
void zyouge_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	for (j = 0; j <( Y_SIZE/2); j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			save[j][i] = img[Y_SIZE-j][i];
			img[Y_SIZE-j][i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//�㉺���E���](�O���C)
void kaiten_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	for (j = 0; j < (Y_SIZE/2); j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			save[j][i] = img[Y_SIZE - j-1][X_SIZE-i];
			img[Y_SIZE - j-1][X_SIZE-i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//�������킹
void yokokagami01_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	int tem;
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < (X_SIZE/2); i++)
		{
			save[j][i] = img[j][X_SIZE - i-1];
			//img[j][X_SIZE - i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//���t
void yokokagami02_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	int tem;
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < (X_SIZE / 2); i++)
		{
			save[j][i] = img[j][i];
			img[j][X_SIZE - i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//���c
void tatekagami01_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	int tem;
	for (j = 0; j < Y_SIZE/2; j++)
	{
		for (i = 0; i < (X_SIZE ); i++)
		{
			save[j][i] = img[Y_SIZE-j][i];
			//img[j][i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//���c�t
void tatekagami02_img(unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;
	int tem;
	for (j = 0; j < Y_SIZE / 2; j++)
	{
		for (i = 0; i < (X_SIZE); i++)
		{
			save[j][i] = img[j][i];
			img[Y_SIZE-j][i] = img[j][i];
			img[j][i] = save[j][i];
		}
	}
}
//2�l��
void nitika_img(unsigned char img[Y_SIZE][X_SIZE], int n)
{
	int i, j;
	for (i = 0; i < Y_SIZE; i++)
	{
		for (j = 0; j < X_SIZE; j++)
		{
			if (img[i][j] == n)
			{
				img[i][j] =high;
			}
			else
			{
				img[i][j] = low;
			}
		}
	}

}
