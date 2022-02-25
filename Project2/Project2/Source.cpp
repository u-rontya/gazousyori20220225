#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
//exitを使う際に必要
#include <stdlib.h>

//画像サイズを定義する
#define X_SIZE 640
#define Y_SIZE 480
int h = 640;
int w = 480;
#define high 255;
#define low 0;
//読み込みと保存用のファイルパスを用意
char read_path[500];
char save_path[500];

//入力のRGB値を用意
unsigned char r_in[Y_SIZE][X_SIZE], g_in[Y_SIZE][X_SIZE], b_in[Y_SIZE][X_SIZE];
unsigned char r[Y_SIZE][X_SIZE], g[Y_SIZE][X_SIZE], b[Y_SIZE][X_SIZE];
//グレイ画像の出力先の列
unsigned char gray[Y_SIZE][X_SIZE];
//画像加工の中継点
unsigned char save[Y_SIZE][X_SIZE];
unsigned char saver[Y_SIZE][X_SIZE];
unsigned char saveg[Y_SIZE][X_SIZE];
unsigned char saveb[Y_SIZE][X_SIZE];


//関数のプロトタイプを宣言する
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
//メインとなる関数
void main(void)
{
	char syori[50];
	char nitika[3];
	int sikii;
	for (int i = 0; i < 1;)
	{
		printf("グレイならグレイスケ―ル,グレイスケール反転ならG反転,グレイスケール上下反転ならG上下反転,グレイスケール上下左右反転ならG上下左右反転,カラー保存ならカラー,Exit\n");
		scanf("%s",&syori);
	
		 if (strcmp(syori, "グレイ")==0)
		{
			//入力画像の読み込み
			read_img(read_path, r_in, g_in, b_in);

			//グレイスケール化
			gray_img(r_in, g_in, b_in, gray);
			printf("2値化しますかYES、NOで");
			scanf("%s", &nitika);
			if(strcmp(nitika, "yes") == 0)
			{
				printf("しきい値を決めてください");
				scanf("%d", &sikii);
				nitika_img(gray, sikii);
				save_img(save_path, gray);
			}
			else
			{
				//出力画像の保存
				save_img(save_path, gray);
			}
		}

		 else if (strcmp(syori, "G反転") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //反転処理
			 hanten_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G上下反転") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下反転
			 zyouge_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G上下左右反転") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下左右反転
			 kaiten_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G鏡合わせ") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下左右反転
			 yokokagami01_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G鏡合わせ逆") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下左右反転
			 yokokagami02_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G鏡合わせ上下") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下左右反転
			 tatekagami01_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		 else if (strcmp(syori, "G鏡合わせ上下逆") == 0)
		 {
			 //入力画像の読み込み
			 read_img(read_path, r_in, g_in, b_in);
			 //グレイスケール化
			 gray_img(r_in, g_in, b_in, gray);
			 //上下左右反転
			 tatekagami02_img(gray);
			 //出力画像の保存
			 save_img(save_path, gray);
		 }
		else
		{
			exit(-1);
		}
	}
}

//入力画像の読み込み
void read_img(char* read_path, unsigned char r[Y_SIZE][X_SIZE], unsigned char g[Y_SIZE][X_SIZE], unsigned char b[Y_SIZE][X_SIZE])
{
	int i, j;

	//ファイルためのファイルを用意
	printf("読み込むファイル-->");
	//標準入力をバッファに格納する
	scanf("%s", read_path);

	FILE* fp;

	//ファイルを開く
	fp = fopen(read_path, "rb");

	//もし，ファイルが無いときに終了させる
	if (fp == NULL)
	{
		printf("ファイルが存在しません", read_path);
		exit(-1);
	}

	//画像内からRGB値の取得（ラスタ走査）
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			r[j][i] = fgetc(fp);
			g[j][i] = fgetc(fp);
			b[j][i] = fgetc(fp);
		}
	}
	//ファイルを閉じる
	fclose(fp);
}

//グレイ化
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

//出力画像の保存(グレイ)
void save_img(char* save_path, unsigned char img[Y_SIZE][X_SIZE])
{
	int i, j;

	FILE* fp;

	printf("どのファイルに保存しますか？-->");
	scanf("%s", save_path);

	//ファイルを開く
	fp = fopen(save_path, "wb");

	////もし，ファイルが無いときに終了させる
	if (fp == NULL)
	{
		printf("ファイルが存在しません", save_path);
		exit(-1);
	}
	//画像のRGB値をファイルに保存する
	for (j = 0; j < Y_SIZE; j++)
	{
		for (i = 0; i < X_SIZE; i++)
		{
			fputc(img[j][i], fp);
		}
	}
	//ファイルを閉じる
	fclose(fp);
}

//反転処理(グレイ)
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
//上下反転処理(グレイ)
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
//上下左右反転(グレイ)
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
//横鏡あわせ
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
//鏡逆
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
//鏡縦
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
//鏡縦逆
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
//2値化
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
