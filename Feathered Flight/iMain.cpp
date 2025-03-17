#include "iGraphics.h"
#include "bitmap_loader.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void drawHomepage();
void drawStartPage();
void drawLevelPage();
void drawHighscorePage();
void drawInstructionPage();
void drawMainGame();
void drawLvl1Page();
void drawLvl2Page();
void drawLvl3Page(); 
void drawBossPage();
void GameOver();
void finished();


void startButtonClickHandeler();
void levelButtonClickHandeler();
void HighscoreButtonClickHandeler();
void instructionButtonHandeler();
void maingameButtonHandeler();
void backButtonHandeler();
void lvl1ButtonHandeler();
void lvl2ButtonHandeler();
void lvl3ButtonHandeler();
void bossButtonHandeler();

int startButtonClick = 0;
int levelButtonClick = 0;
int HighscoreButtonClick = 0;
int InstructionButtonClick = 0;
int MaingameButtonClick = 0;
int Lvl1ButtonClick = 0;
int Lvl2ButtonClick = 0;
int Lvl3ButtonClick = 0;
int bossButtionClick = 0;


int homePage  = 1;
int startPage = 0;
int levelPage = 0;
int highscorePage = 0;
int instructionPage = 0;
int maingamePage = 0;
int lvl1Page = 0;
int lvl2Page = 0;
int lvl3Page = 0;
int boss = 0;
int increment = 13;
int gameOver = 0;
int finish = 0;
int arrow = 0;
int fire = 0;
int bossHealthBarX = 264;
int bossHealthBarY = 20;
//fire(boss)
int fireX;
int fireY;
//arrow(hero)
int arrowX; 
int arrowY;

int speed = 0;
int destroyed = 0;

//boss
int bossX = 900;
int bossY = 530;
int bossindex = 0;

//lvl1
int playerX = 50;//hero
int playerY = 350;//hero
int heroindex = 0;//hero
float villeNx = 1300, villeNy = 470;//v1
float villeNa = 1200, villeNb = 0;//v2
float villeNc = 1190, villeNd = 220;//v3
float villeNe = 1350, villeNf = 0;//v4
float villeNg = 1500, villeNh = 0;//v5
int life = 3;
int bossLife = 6;
char heroMove[8][50] = { "image\\1.bmp", "image\\2.bmp", "image\\3.bmp", "image\\4.bmp", "image\\5.bmp", "image\\6.bmp", "image\\7.bmp", "image\\8.bmp" };//hero
char bossMove[4][11] = { "boss\\1.bmp", "boss\\2.bmp", "boss\\3.bmp" };//boss
//coins

int c1y = 100;
int c2y = 300;
int c3y = 500;
int c4y = 600;
int c5y = 680;
int c1x = 300;
int c2x = 500;
int c3x = 700;
int c4x = 900;
int c5x = 1100;
int c1yspeed = 0;
int c2yspeed = 0;
int c3yspeed = 0;
int c4yspeed = 0;
int c5yspeed = 0;
int coinscore = 0;

int second = 0;
int score = 0;


//collision
void collision()

{
	//v1
	if ((playerX + 99 >= villeNx && playerX <= 99 + villeNx) && (playerY + 92 >= villeNy && playerY <= 92 + villeNy))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 100, playerY = 600;
		}
	}
	//v2
	else if ((playerX + 110 >= villeNa && playerX <= 110 + villeNa) && (playerY + 120 >= villeNb && playerY <= 120 + villeNb))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 100, playerY = 600;
		}
	}
	//v3
	else if ((playerX + 99 >= villeNc && playerX <= 99 + villeNc) && (playerY + 80 >= villeNd && playerY <= 80 + villeNd))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 100, playerY = 600;
		}
	}
	//v4
	else if ((playerX + 110 >= villeNe && playerX <= 110 + villeNe) && (playerY + 120 >= villeNf && playerY <= 120 + villeNf))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 100, playerY = 600;
		}
	}
	//v5
	else if ((playerX + 110 >= villeNg && playerX <= 110 + villeNg) && (playerY + 120 >= villeNh && playerY <= 120 + villeNh))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 100, playerY = 600;
		}
	}
	

}
//for randering
int totalimageCount = 25;
int slice = 26;
int width = 1300 / slice;
char backgroundImagePath[200][250] = { "Background1\\bg1.bmp", "Background1\\bg1_1.bmp", "Background1\\bg1_2.bmp", "Background1\\bg1_3.bmp", "Background1\\bg1_4.bmp", "Background1\\bg1_5.bmp", "Background1\\bg1_6.bmp", "Background1\\bg1_7.bmp", "Background1\\bg1_8.bmp", "Background1\\bg1_9.bmp", "Background1\\bg1_10.bmp", "Background1\\bg1_11.bmp", "Background1\\bg1_12.bmp",
"Background1\\bg1_13.bmp", "Background1\\bg1_14.bmp", "Background1\\bg1_15.bmp", "Background1\\bg1_16.bmp", "Background1\\bg1_17.bmp", "Background1\\bg1_18.bmp", "Background1\\bg1_19.bmp", "Background1\\bg1_20.bmp", "Background1\\bg1_21.bmp", "Background1\\bg1_22.bmp", "Background1\\bg1_23.bmp", "Background1\\bg1_24.bmp", "Background1\\bg1_25.bmp" };
int imagPosition[100];

void renddering()
{
	iClear();
	int i;
	for (i = 0; i < 26; i++)
	{
		iShowBMP2(imagPosition[i], 0, backgroundImagePath[i], 0);
	}
}
void moveBackground()
{
	int i;
	for (i = 0; i<26; i++)
	{
		imagPosition[i] -= width;
		if (imagPosition[i] < 0)
		{
			imagPosition[i] = 1300 - width;
		}

	}
}
void intializeImagePosition()
{
	int i, j;
	for (i = 0, j = 0; i < slice; i++)
	{
		imagPosition[i] = j;
		j += width;

	}

}
//Background renndering lvl1 (((((END))))))

void coinCollision()
{
	//c1
	if ((playerX + 100 >= c1x && playerX <= c1x + 100) && (playerY + 100 >= c1y && playerY <= c1y + 100))
	{
		mciSendString("play music//coin.wav", NULL, 0, NULL);
		coinscore = coinscore + 5;
		c1yspeed = c1yspeed + 1000;
		c1y = c1y + c1yspeed;

	}
	//c2
	else if ((playerX + 100 >= c2x && playerX <= c2x + 100) && (playerY + 100 >= c2y && playerY <= c2y + 100))
	{
		mciSendString("play music//coin.wav", NULL, 0, NULL);
		coinscore = coinscore + 10;

		c2yspeed = c2yspeed + 1000;
		c2y = c2y + c2yspeed;

	}

	//c3
	else if ((playerX + 100 >= c3x && playerX <= c3x + 100) && (playerY + 100 >= c3y && playerY <= c3y + 100))
	{
		mciSendString("play music//coin.wav", NULL, 0, NULL);
		coinscore = coinscore + 30;

		c3yspeed = c3yspeed + 1000;
		c3y = c3y + c3yspeed;

	}
	//c4
	else if ((playerX + 100 >= c4x && playerX <= c4x + 100) && (playerY + 100 >= c4y && playerY <= c4y + 100))
	{
		mciSendString("play music//coin.wav", NULL, 0, NULL);
		coinscore = coinscore + 40;

		c4yspeed = c4yspeed + 1000;
		c4y = c4y + c4yspeed;

	}
	//c5
	else if ((playerX + 100 >= c5x && playerX <= c5x + 100) && (playerY + 100 >= c5y && playerY <= c5y + 100))
	{
		mciSendString("play music//coin.wav", NULL, 0, NULL);
		coinscore = coinscore + 40;

		c5yspeed = c5yspeed + 1000;
		c5y = c5y + c5yspeed;

	}

	score = second + coinscore;

}
//lvl 2
//obstacle lvl 2
//Moving obstacles
//for background randering === lvl2
int position2[100];
char bg2Path[26][52] = { "Background2\\bg2_1.bmp", "Background2\\bg2_2.bmp", "Background2\\bg2_3.bmp", "Background2\\bg2_4.bmp", "Background2\\bg2_5.bmp", "Background2\\bg2_6.bmp", "Background2\\bg2_7.bmp", "Background2\\bg2_8.bmp", "Background2\\bg2_9.bmp", "Background2\\bg2_10.bmp", "Background2\\bg2_11.bmp", "Background2\\bg2_12.bmp",
"Background2\\bg2_13.bmp", "Background2\\bg2_14.bmp", "Background2\\bg2_15.bmp", "Background2\\bg2_16.bmp", "Background2\\bg2_17.bmp", "Background2\\bg2_18.bmp", "Background2\\bg2_19.bmp", "Background2\\bg2_20.bmp", "Background2\\bg2_21.bmp", "Background2\\bg2_22.bmp", "Background2\\bg2_23.bmp", "Background2\\bg2_24.bmp", "Background2\\bg2_25.bmp", "Background2\\bg2_26.bmp" };
int slice2 = 26;
int width2 = 1300 / slice2;


void renddering2()
{
	iClear();
	int i;
	for (i = 0; i < 26; i++)
	{
		iShowBMP2(position2[i], 0, bg2Path[i], 0);
	}
}
void moveBackground2()
{
	int i;
	for (i = 0; i<26; i++)
	{
		position2[i] -= width2;
		if (position2[i] < 0)
		{
			position2[i] = 1300 - width2;
		}

	}
}
void intializeImagePosition2()
{
	int i, j;
	for (i = 0, j = 0; i < slice; i++)
	{
		position2[i] = j;
		j += width2;

	}

}
//Background renndering lvl1 (((((END))))))

//obstacle lvl 2
//Background renndering lv2 (((((END))))))
//Moving obstacles
int oIndex = 0;
char o[10][100] = { "image2\\1.bmp", "image2\\2.bmp", "image2\\3.bmp", "image2\\4.bmp", "image2\\5.bmp", "image2\\6.bmp", "image2\\7.bmp", "image2\\8.bmp", "image2\\9.bmp", "image2\\10.bmp" };
int ox = 1300;//o1
int oy = 150;//o1

int o2Index = 0;
char o2[10][100] = { "image2\\21.bmp", "image2\\22.bmp", "image2\\23.bmp", "image2\\24.bmp", "image2\\25.bmp", "image2\\26.bmp", "image2\\27.bmp", "image2\\28.bmp", "image2\\29.bmp", "image2\\30.bmp" };
int ox2 = 1100;//o2
int oy2 = 400;//o3
//non moving obstacles
float x2 = 0, y2 = 0;//o3
float a2 = 0, b2 = 620;//o4
float villeNi = 1050, villeNj = 600;//o5

//for background randering === lvl3
int position3[100];
char bg3Path[26][52] = { "Background3\\bg3.bmp", "Background3\\bg3_1.bmp", "Background3\\bg3_2.bmp", "Background3\\bg3_3.bmp", "Background3\\bg3_4.bmp", "Background3\\bg3_5.bmp", "Background3\\bg3_6.bmp", "Background3\\bg3_7.bmp", "Background3\\bg3_8.bmp", "Background3\\bg3_9.bmp", "Background3\\bg3_10.bmp", "Background3\\bg3_11.bmp", "Background3\\bg3_12.bmp",
"Background3\\bg3_13.bmp", "Background3\\bg3_14.bmp", "Background3\\bg3_15.bmp", "Background3\\bg3_16.bmp", "Background3\\bg3_17.bmp", "Background3\\bg3_18.bmp", "Background3\\bg3_19.bmp", "Background3\\bg3_20.bmp", "Background3\\bg3_21.bmp", "Background3\\bg3_22.bmp", "Background3\\bg3_23.bmp", "Background3\\bg3_24.bmp", "Background3\\bg3_25.bmp" };
int slice3 = 26;
int width3 = 1300 / slice3;



void renddering3()
{
	iClear();
	int i;
	for (i = 0; i < 26; i++)
	{
		iShowBMP2(position3[i], 0, bg3Path[i], 0);
	}
}
void moveBackground3()
{
	int i;
	for (i = 0; i<26; i++)
	{
		position3[i] -= width3;
		if (position3[i] < 0)
		{
			position3[i] = 1300 - width3;
		}

	}
}
void intializeImagePosition3()
{
	int i, j;
	for (i = 0, j = 0; i < slice; i++)
	{
		position3[i] = j;
		j += width3;

	}

}
//Background renndering lvl3 (((((END))))))
void collision2()

{
	//o1
	if ((playerX + 99 >= ox && playerX <= 99 + ox) && (playerY + 90 >= oy && playerY <= 90 + oy))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o2
	else if ((playerX + 99 >= ox2 && playerX <= 99 + ox2) && (playerY + 90 >= oy2 && playerY <= 90 + oy2))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o3
	else if ((playerX + 1300 >= x2 && playerX <= 1300 + x2) && (playerY + 124 >= y2 && playerY <= 124 + y2))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o4
	else if ((playerX + 1300 >= a2 && playerX <= 1300 + a2) && (playerY + 85 >= b2 && playerY <= 85 + b2))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o5
	else if ((playerX + 80 >= villeNi && playerX <= 80 + villeNi) && (playerY + 80 >= villeNj && playerY <= 80 + villeNj))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}




}
//obstacle lvl 3
//Moving obstacles
int o3Index = 0;
char o3[10][100] = { "image3\\1.bmp", "image3\\2.bmp", "image3\\3.bmp", "image3\\4.bmp", "image3\\5.bmp", "image3\\6.bmp", "image3\\7.bmp", "image3\\8.bmp", "image3\\9.bmp", "image3\\10.bmp" };
int ox3 = 1300;
int oy3 = 150;

int o23Index = 0;
char o23[10][100] = { "image3\\21.bmp", "image3\\22.bmp", "image3\\23.bmp", "image3\\24.bmp", "image3\\25.bmp", "image3\\26.bmp", "image3\\27.bmp", "image3\\28.bmp", "image3\\29.bmp", "image3\\30.bmp" };
int ox23 = 1100;
int oy23 = 450;


//non moving obstacles
float x3 = 0, y3 = 0;//o2
float a3 = 0, b3 = 620;//o1


void collision3()
{
	//o1
	if ((playerX + 99 >= ox3 && playerX <= ox3 + 99) && (playerY + 90 >= oy3 && playerY <= oy3 + 90))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o2
	if ((playerX + 99 >= ox23 && playerX <= ox23 + 99) && (playerY + 90 >= oy23 && playerY <= oy23 + 90))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o3
	if ((playerX + 1300 >= x3 && playerX <= x3 + 1300) && (playerY + 124 >= y3 && playerY <= y3 + 124))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o4
	if ((playerX + 1300 >= a3 && playerX <= a3 + 1300) && (playerY + 85 >= b3 && playerY <= b3 + 85))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//o5
	else if ((playerX + 80 >= villeNi && playerX <= 80 + villeNi) && (playerY + 80 >= villeNj && playerY <= 80 + villeNj))
	{
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}
	//boss
	if ((playerX + 99 >= bossX && playerX <= bossX + 99) && (playerY + 99 >= bossY && playerY <= bossY + 99))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			boss = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
		}
	}

	//boss
	if ((arrowX + 120 >= bossX && arrowX <= bossX + 120) && (arrowY + 70 >= bossY && arrowY <= bossY + 70))
	{
		mciSendString("stop music//arrow.wav", NULL, 0, NULL);
		mciSendString("play music//roar.wav", NULL, 0, NULL);
		if (bossLife == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			boss = 0;
			gameOver = 0;
			finish = 1;
		}
		else
		{
			mciSendString("play music//roar.wav", NULL, 0, NULL);
			bossLife --;
			arrow = 0;
			if (bossHealthBarX <= 0)
			{
				bossHealthBarX = 0;
				bossHealthBarY = 0;
			}
			bossHealthBarX = bossHealthBarX - 44;
		}
		arrowX = 1400;
		arrowY = 800;
	}

	if ((fireX + 99 >= playerX && fireX <= playerX + 99) && (fireY + 99 >= playerY && fireY <= playerY + 99))
	{
		mciSendString("play music//blast.wav", NULL, 0, NULL);
		if (life == 1)
		{
			lvl1Page = 0;
			lvl2Page = 0;
			lvl3Page = 0;
			boss = 0;
			gameOver = 1;
		}
		else
		{
			mciSendString("play music//blast.wav", NULL, 0, NULL);
			life--;
			playerX = 0, playerY = 300;
			fire = 0;
		}
	}

}

void newHighScore();
void readScore();
int len = 0;
char str1[100];
bool newscore = true;

struct hscore{

	char name[30];
	int score = 0;

}high_score[5];

void readScore()
{
	FILE *fp;

	fp = fopen("scoree.txt", "r");
	char showName[5][30], showscore[5][5];
	for (int i = 0; i < 5; i++)
	{

		fscanf(fp, "%s %d\n ", high_score[i].name, &high_score[i].score);
	}
	for (int i = 0; i < 5; i++)
	{

		sprintf(showName[i], "%s", high_score[i].name);
		sprintf(showscore[i], "%d", high_score[i].score);
		iSetColor(0, 0, 0);
		iText(500, 510, "NAME:", GLUT_BITMAP_HELVETICA_18);
		iText(600, 510, "SCORE:", GLUT_BITMAP_HELVETICA_18);
		iText(500, 481 - 30 * i, showName[i], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 480 - 30 * i, showscore[i], GLUT_BITMAP_TIMES_ROMAN_24);
	}

	fclose(fp);



}

void newHighScore()
{
	FILE *fp;

	fp = fopen("scoree.txt", "w");

	for (int i = 0; i < 5; i++)
	{

		fscanf(fp, "%s %d\n ", high_score[i].name, &high_score[i].score);
	}
	int t;
	char n[30];

	if (newscore)
	{
		for (int i = 0; i < 5; i++)
		{
			if (high_score[i].score < score)
			{
				high_score[i].score = score;
				strcpy(high_score[i].name, str1);

				for (int j = 0; j < 5; j++)
				{
					for (int k = 5; k>j; k--)
					{
						if (high_score[k].score > high_score[k - 1].score)
						{
							//sorting 
							int t = high_score[k - 1].score;
							high_score[k].score = t;

							char n[50];
							strcpy(n, high_score[k - 1].name);
							strcpy(high_score[k - 1].name, high_score[k].name);
							strcpy(high_score[k].name, n);




						}
					}
				}
				FILE *fp = fopen("scoree.txt", "r");



				for (int i = 0; i < 5; i++)
				{

					fprintf(fp, "%s %d\n ", high_score[i].name, high_score[i].score);
				}

				fclose(fp);

				newscore = false;
				break;

			}
		}
	}
}


void showChar()
{

	iSetColor(0, 0, 0);

	iText(1072, 695, "Enter Your Name:", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iRectangle(1072, 624, 200, 50);
	iFilledRectangle(1072, 624, 200, 50);

	iSetColor(0, 0, 255);
	iText(1080, 640, str1, GLUT_BITMAP_TIMES_ROMAN_24);
}

void takeinput(unsigned key)
{
	if (key == '\r')
	{
		mciSendString("stop music//GameOver.wav", NULL, 0, NULL);
		mciSendString("play music//Dungeon1.wav", NULL, 0, NULL);
		homePage = 1;
		newHighScore();

	}
	else if (key == '\b')// remove the letter with backspace
	{
		if (len <= 0)
			len = 0;

		else
			len--;

		str1[len] = '\0';

	}
	else{

		str1[len] = key;
		len++;

		if (len > 15)
			len = 15;

		str1[len] = '\0';

	}
}

char sec[10000];
int minute = 0;
int hour = 0;
char hr[10000];
int totalSecond = 0;
char point[10000];

void changeTimer()
{
	if (lvl1Page == 1 || lvl2Page == 1 || lvl3Page == 1 || boss == 1 )
	{
		totalSecond = (second++) + (60 * minute) + (60 * 60 * hour);
		score = score + second;
	}

	if (lvl1Page == 1)
	{
		
		if (second % 120 == 0)
		{
			playerX = 50;//hero
		    playerY = 350;//hero
			mciSendString("stop music//gameMusic.wav", NULL, 0, NULL);
			lvl2ButtonHandeler();
		}
	}
	else if (lvl2Page == 1)
	{

		if (second % 120 == 0)
		{
			playerX = 50;//hero
		    playerY = 350;//hero
			mciSendString("stop music//Dungeon2.wav", NULL, 0, NULL);
			lvl3ButtonHandeler();
		}
	}
	else if (lvl3Page == 1)
	{

		if (second % 120 == 0)
		{
			playerX = 50;//hero
			playerY = 350;//hero
			mciSendString("stop music//Dungeon2.wav", NULL, 0, NULL);
			bossButtonHandeler();
		}
	}
}



void drawTimer()
{

	if (lvl1Page == 1 || lvl2Page == 1 || lvl3Page == 1 || boss == 1)
	{
		iSetColor(255, 204, 203);
		/*iShowBMP2(1100, 560, "level1\\OIP.bmp", 0);*/
		

		iSetColor(255, 0, 0);
		sprintf_s(sec, "%d", second);
		iText(1220, 620, sec, GLUT_BITMAP_HELVETICA_18);

		iText(1140, 620, "TIMER:", GLUT_BITMAP_HELVETICA_18);

		iSetColor(168, 50, 50);
		
		iSetColor(0, 0, 0);
		sprintf_s(point, "%d", score);
		iText(1220, 600, point, GLUT_BITMAP_HELVETICA_18);
		iText(1140, 600, "SCORE:", GLUT_BITMAP_HELVETICA_18);

	}
}

bool musicOn = true;

void iDraw()
{
	iClear();
	if (homePage == 1)
	{
        drawHomepage();
	}
	else if (startPage == 1)
	{
		drawStartPage();
	}
	else if (levelPage == 1)
	{
		drawLevelPage();
	}
	else if (highscorePage == 1)
	{
		drawHighscorePage();
	}
	else if (instructionPage == 1)
	{
		drawInstructionPage();
	}
	else if (maingamePage == 1)
	{
		drawMainGame();
	}
	else if (lvl1Page == 1)
	{
		drawLvl1Page();
	}
	else if (lvl2Page == 1)
	{
		drawLvl2Page();
	}
	else if (lvl3Page == 1)
	{
		drawLvl3Page();
	}
	else if (boss == 1)
	{
		drawBossPage();
	}
	else if (gameOver == 1)
	{
		GameOver();
		showChar();

	}
	else if (finish == 1)
	{

		finished();
		showChar();

	}

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		printf("x=%d,y=%d", mx, my);

		if (homePage == 1 && (mx >= 554 && mx <= 716) && (my >= 429 && my <= 600))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}
			startButtonClickHandeler();
		}

		else if (homePage == 1 && ((mx >= 553 && mx <= 722) && (my >= 341 && my <= 404)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			levelButtonClickHandeler();

		}
		else if (homePage == 1 && ((mx >= 557 && mx <= 727) && (my >= 267 && my <= 323)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			HighscoreButtonClickHandeler();

		}
		else if (homePage == 1 && ((mx >= 558 && mx <= 717) && (my >= 180 && my <= 234)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}
			instructionButtonHandeler();

		}
		else if (startPage == 1 && ((mx >= 1058 && mx <= 1252) && (my >= 615 && my <= 654)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			maingameButtonHandeler();
		}
		else if (lvl3Page == 1 | lvl2Page == 1 | lvl1Page == 1 | maingamePage == 1 | startPage == 1 | levelPage == 1 | boss == 1 | highscorePage == 1 | instructionPage == 1 | gameOver == 1 && ((mx >= 41 && mx <= 235) && (my >= 91 && my <= 133)))
		{
			
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}
		

			backButtonHandeler();
		}
		else if (levelPage == 1 | maingamePage == 1 && ((mx >= 430 && mx <= 582) && (my >= 440 && my <= 552)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			lvl1ButtonHandeler();
		}
		else if (levelPage == 1 | maingamePage == 1 && ((mx >= 737 && mx <= 879) && (my >= 443 && my <= 521)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			lvl2ButtonHandeler();
		}
		else if (levelPage == 1 | maingamePage == 1 && ((mx >= 579 && mx <= 726) && (my >= 243 && my <= 321)))
		{
			if (musicOn)
			{

				PlaySound("music\\click1.wav", NULL, SND_ASYNC);
			}

			lvl3ButtonHandeler();
		}
	}
	else if (homePage == 1 && ((mx >= 1201 && mx <= 1244) && (my >= 682 && my <= 726)))
	{
		exit(0);

	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (gameOver == 1 || finish == 1 )
	{
		takeinput(key);
	}
	if (key == 'f' || "F")
	{

		mciSendString("play music//arrow.wav", NULL, 0, NULL);
		arrow = 1;
		arrowX = playerX;
		arrowY = playerY;

	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		heroindex++;
		if (heroindex == 8)
		{
			heroindex = 0;
		}

		playerX += 18;
		if (playerX > 1300)
		{
			playerX = 0;
		}

	}
	if (key == GLUT_KEY_LEFT)
	{
		heroindex++;
		if (heroindex == 8)
		{
			heroindex = 0;
		}
		playerX -= 18;

		if (playerX < 0)
		{
			playerX = 0;
		}

	}
	else if (key == GLUT_KEY_UP)
	{
		heroindex++;
		if (heroindex == 8)
		{
			heroindex = 0;
		}

		playerY += 15;
		if (playerY>750)
		{
			playerY = 0;
		}
	}
	else if (key == GLUT_KEY_DOWN)
	{
		heroindex++;
		if (heroindex == 8)
		{
			heroindex = 0;
		}

		playerY -= 15;
		if (playerY<0)
		{
			playerY = 750;
		}
	}
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}

void drawHomepage()
{
	mciSendString("stop music//win.wav", NULL, 0, NULL);
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 1300, 750);
      
	iShowBMP2(0, 0, "image\\Home page360.bmp", 0);
	iShowBMP2(1180, 660, "image\\quit.bmp", 0);


	iSetColor(0, 0, 0);

	
}

void drawStartPage()
{
	bool musicOn = true;
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "image\\Story1.bmp", 0);
	iShowBMP2(1050,600, "image\\Button.bmp", 0);
	startButtonClickHandeler();
	mciSendString("stop music//Dungeon1.wav", NULL, 0, NULL);
	mciSendString("play music//StoryTelling.wav", NULL, 0, NULL);
	iText(1115, 625, "continue", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);

	
}

void drawLevelPage()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "image\\lvl.bmp", 0);
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iShowBMP2(420, 370, "image\\lvl1Button.bmp", 0);
	iShowBMP2(720, 370, "image\\lvl2Button.bmp", 0);
	iShowBMP2(565, 170, "image\\lvl3Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawHighscorePage()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "image\\ScorePage.bmp", 0);
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
	readScore();
	gameOver = 1;
	readScore();
}
void drawInstructionPage()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "image\\Instructions.bmp", 0);
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawMainGame()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "image\\lvl.bmp", 0);
	iShowBMP2(420, 370, "image\\lvl1Button.bmp", 0);
	iShowBMP2(720, 370, "image\\lvl2Button.bmp", 0);
	iShowBMP2(565, 170, "image\\lvl3Button.bmp", 0);
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);

}
void drawLvl1Page()
{

	mciSendString("stop music//StoryTelling.wav", NULL, 0, NULL);
	mciSendString("play music//gameMusic.wav", NULL, 0, NULL);
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "level1\\Backgroung1.bmp", 0);
	renddering();
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
	/*iShowBMP2(playerX, playerY, "level1\\1.bmp", 0);//hero*/
	iShowBMP2(playerX, playerY, heroMove[heroindex], 0);
	iShowBMP2(villeNx, villeNy, "level1\\obstacle2.bmp", 0);
	iShowBMP2(villeNa, villeNb, "level1\\obstacle3.bmp", 0);
	iShowBMP2(villeNc, villeNd, "level1\\obstacle4.bmp", 0);
	iShowBMP2(villeNe, villeNf, "level1\\obstacle5.bmp", 0);
	iShowBMP2(villeNg, villeNh, "level1\\obstacle6.bmp", 0);
	/*iShowBMP2(villeNi, villeNj, "level1\\obstacle7.bmp", 0);*/

	if (life == 3)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
		iShowBMP2(1000, 640, "image\\Life.bmp", 0);
	}
	else if (life == 2)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100,640,"image\\Life.bmp", 0);
	}
	else if (life == 1)
	{
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}

	//o1
	villeNx = villeNx - 12;
	if (villeNx <= 0)
	{
		villeNx = 1300;
		villeNy = 300 + rand() % 250;
	}


	//o2
	villeNa = villeNa - 12;
	if (villeNa <= 0)
	{
		villeNa = 1200 + rand() % 250;
		villeNb = 0;
	}

	//o3
	villeNc = villeNc - 12;
	if (villeNc <= 0)
	{
		villeNc = 1190;
		villeNd = 220 + rand() % 200;
	}
	
	//o4
	villeNe = villeNe - 11.89;
	if (villeNe <= 0)
	{
		villeNe = 1350 + rand() % 220;
		villeNf = 0;
	}
	
	//o5
	villeNg = villeNg - 11;
	if (villeNg <= 0)
	{
		villeNg = 1500 + rand() % 200;
		villeNh = 0;
	}
	collision();
	
	// COINS COLLISION
	iShowBMP2(c1x, c1y, "level1\\coin1.bmp", 0);
	iShowBMP2(c2x, c2y, "level1\\coin2.bmp", 0);
	iShowBMP2(c3x, c3y, "level1\\coin3.bmp", 0);
	iShowBMP2(c4x, c4y, "level1\\coin4.bmp", 0);

	
	c1x = c1x - 12;
	if (c1x <= 0)
	{
		c1x = 1300;
		c1y = 200 + rand() % 550;


	}



	c2x = c2x - 12;
	if (c2x <= 0)
	{
		c2x = 1300;
		c2y = 150 + rand() % 350;


	}



	c3x = c3x - 12;
	if (c3x <= 0)
	{
		c3x = 1300;
		c3y = 240 + rand() % 400;


	}


	c4x = c4x - 12;
	if (c4x <= 0)
	{
		c4x = 1300;
		c4y = 150 + rand() % 200;


	}coinCollision();

	drawTimer();
	

	

	
}
void drawLvl2Page()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "level2\\Background2.bmp", 0);
	mciSendString("stop music//StoryTelling.wav", NULL, 0, NULL);
	mciSendString("play music//Dungeon2.wav", NULL, 0, NULL);
	renddering2();
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(playerX, playerY, heroMove[heroindex], 0);

	if (life == 3)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
		iShowBMP2(1000, 640, "image\\Life.bmp", 0);
	}
	else if (life == 2)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}
	else if (life == 1)
	{
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}

	//obstacle moving one
	iSetColor(0, 0, 0);
	iShowBMP2(ox, oy, o[oIndex], 0);
	oIndex++;
	if (oIndex >= 10)
	{
		oIndex = 0;
	}


	//ob1
	ox = ox - 10;
	if (ox <= 0)
	{
		ox = 1300;
		oy = 150 + rand() % 350;
	}

	//obstacle animation
	iSetColor(0, 0, 0);
	iShowBMP2(ox2, oy2, o2[o2Index], 0);
	o2Index++;
	if (o2Index >= 10)
	{
		o2Index = 0;
	}


	//ob2
	ox2 = ox2 - 10;
	if (ox2 <= 0)
	{
		ox2 = 1300;
		oy2 = 350 + rand() % 350;
	}

	//non moving obstacles o3 o4
	iShowBMP2(x2, y2, "image2\\obstacle2.bmp", 0);
	iShowBMP2(a2, b2, "image2\\obstacle1.bmp", 0);
	iShowBMP2(villeNi, villeNj, "level1\\obstacle7.bmp", 0);

	//o3
	x2 = x2 - 20;
	if (x2 <= 0)
	{
		x2 = 0;
		y2 = 0;
	}

	//o4
	a2 = a2 - 20;
	if (a2 <= 0)
	{
		a2 = 0;
		b2 = 620;
	}

	//spike
	villeNj = villeNj - 14.35;
	if (villeNj <= 0)
	{
		villeNj = 751;
		villeNi = 200 + rand() % 485;
	}
	collision2();

	// COINS COLLISION
	iShowBMP2(c1x, c1y, "level2\\coin1.bmp", 0);
	iShowBMP2(c2x, c2y, "level2\\coin2.bmp", 0);
	iShowBMP2(c3x, c3y, "level2\\coin3.bmp", 0);
	iShowBMP2(c4x, c4y, "level2\\coin4.bmp", 0);


	c1x = c1x - 12;
	if (c1x <= 0)
	{
		c1x = 1300;
		c1y = 200 + rand() % 250;


	}



	c2x = c2x - 12;
	if (c2x <= 0)
	{
		c2x = 1300;
		c2y = 150 + rand() % 350;


	}



	c3x = c3x - 12;
	if (c3x <= 0)
	{
		c3x = 1300;
		c3y = 240 + rand() % 400;


	}


	c4x = c4x - 12;
	if (c4x <= 0)
	{
		c4x = 1300;
		c4y = 150 + rand() % 200;


	}coinCollision();


	drawTimer();




}
void drawLvl3Page()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "level3\\Background3.bmp", 0);
	mciSendString("stop music//StoryTelling.wav", NULL, 0, NULL);
	mciSendString("play music//Dungeon3.wav", NULL, 0, NULL);
	renddering3();
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(playerX, playerY, heroMove[heroindex], 0);
	if (life == 3)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
		iShowBMP2(1000, 640, "image\\Life.bmp", 0);
	}
	else if (life == 2)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}
	else if (life == 1)
	{
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}
	//spike
	iShowBMP2(villeNi, villeNj, "level1\\obstacle7.bmp", 0);

	//obstacle moving one
	iSetColor(0, 0, 0);
	iShowBMP2(ox3, oy3, o3[o3Index], 0);
	o3Index++;
	if (o3Index >= 10)
	{
		o3Index = 0;
	}



	ox3 = ox3 - 33;
	if (ox3 <= 0)
	{
		ox3 = 1300;
		oy3 = 150 + rand() % 350;
	}


	//obstacle moving one 2
	iSetColor(0, 0, 0);
	iShowBMP2(ox23, oy23, o23[o23Index], 0);
	o23Index++;
	if (o23Index >= 10)
	{
		o23Index = 0;
	}



	ox23 = ox23 - 13;
	if (ox23 <= 0)
	{
		ox23 = 1300;
		oy23 = 350 + rand() % 350;
	}

	//spike
	villeNj = villeNj - 14.35;
	if (villeNj <= 0)
	{
		villeNj = 751;
		villeNi = 200 + rand() % 485;
	}
	collision2();



	//non moving obstacles
	iShowBMP2(x3, y3, "image3\\obstacle2.bmp", 0);
	iShowBMP2(a2, b2, "image3\\obstacle1.bmp", 0);

	//o1
	x3 = x3 - 10;
	if (x3 <= 0)
	{
		x3 = 0;
		y3 = 0;
	}

	//o2
	a3 = a3 - 10;
	if (a3 <= 0)
	{
		a3 = 0;
		b3 = 620;
	}
	collision3();


	// COINS COLLISION
	iShowBMP2(c1x, c1y, "image3\\c1.bmp", 0);
	iShowBMP2(c2x, c2y, "image3\\c2.bmp", 0);
	iShowBMP2(c3x, c3y, "image3\\c3.bmp", 0);
	iShowBMP2(c4x, c4y, "image3\\c4.bmp", 0);
	iShowBMP2(c5x, c5y, "image3\\c5.bmp", 0);



	c1x = c1x - 10;
	if (c1x <= 0)
	{
		c1x = 1300;
		c1y = 430 + rand() % 350;


	}



	c2x = c2x - 10;
	if (c2x <= 0)
	{
		c2x = 1300;
		c2y = 350 + rand() % 350;


	}



	c3x = c3x - 10;
	if (c3x <= 0)
	{
		c3x = 1300;
		c3y = 345 + rand() % 200;


	}


	c4x = c4x - 10;
	if (c4x <= 0)
	{
		c4x = 1300;
		c4y = 230 + rand() % 200;


	}

	c5x = c5x - 10;
	if (c5x <= 0)
	{
		c5x = 1300;
		c5y = 115 + rand() % 200;


	}coinCollision();

	drawTimer();
}

void drawBossPage()
{
	iFilledRectangle(0, 0, 1300, 750);
	iShowBMP2(0, 0, "level3\\Background3.bmp", 0);
	mciSendString("stop music//StoryTelling.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon3.wav", NULL, 0, NULL);
	mciSendString("play music//boss.wav", NULL, 0, NULL);
	renddering3();
	iShowBMP2(30, 80, "image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(playerX, playerY, heroMove[heroindex], 0);
	if (arrow)
	{
		iShowBMP2(arrowX, arrowY, "boss\\arrow.bmp", 0);
		arrowX = arrowX + 40;
		if (arrowX == 1300)
		{
			arrow = 0;
		}
	}
	if (fire)
	{
		iShowBMP2(fireX, fireY, "boss\\fireball1.bmp", 0);
		fireX = fireX - 40;
		if (fireX == 0)
		{
			fire = 0;
		}
	}
	if (life == 3)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
		iShowBMP2(1000, 640, "image\\Life.bmp", 0);
	}
	else if (life == 2)
	{
		iShowBMP2(1200, 640, "image\\Life.bmp", 0);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
	}
	else if (life == 1)
	{
		mciSendString("stop music//blast.wav", NULL, 0, NULL);
		iShowBMP2(1100, 640, "image\\Life.bmp", 0);
		iText(73, 716, "Super Mode is Activited", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	//boss health bar
	iSetColor(255, 255, 51);
	iFilledRectangle(bossX + 70, bossY + 320, bossHealthBarX, bossHealthBarY);

	

	//boss movement
	iShowBMP2(bossX, bossY, bossMove[bossindex], 0);
	/*if (bossLife)
	{
		iShowBMP2(bossX, bossY, bossMove[bossindex], 0);
	}*/

	bossY = bossY - increment ;
	if (bossY <= 0)
	{
		increment = increment * (-1);
	}
	else if (bossY >= 530)
	{
		increment = increment * (-1);
	}

	//obstacle moving one
	iSetColor(0, 0, 0);
	iShowBMP2(ox3, oy3, o3[o3Index], 0);
	o3Index++;
	if (o3Index >= 10)
	{
		o3Index = 0;
	}



	ox3 = ox3 - 13;
	if (ox3 <= 0)
	{
		ox3 = 1300;
		oy3 = 150 + rand() % 350;
	}collision3();

	//spike
	iShowBMP2(villeNi, villeNj, "level1\\obstacle7.bmp", 0);

	//spike
	villeNj = villeNj - 14.35;
	if (villeNj <= 0)
	{
		villeNj = 751;
		villeNi = 200 + rand() % 285;
	}
	collision2();

    //non moving obstacles
	iShowBMP2(x3, y3, "image3\\obstacle2.bmp", 0);
	iShowBMP2(a2, b2, "image3\\obstacle1.bmp", 0);

	//o1
	x3 = x3 - 10;
	if (x3 <= 0)
	{
		x3 = 0;
		y3 = 0;
	}collision3();

	drawTimer();
}

void startButtonClickHandeler()
{
	homePage = 0;
	startPage = 1;
}
void  levelButtonClickHandeler()
{
	homePage = 0;
	startPage = 0;
    levelPage = 1;
}
void  HighscoreButtonClickHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage =0;
	highscorePage = 1;
}

void  instructionButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage =1;
}

void  maingameButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 1;
}

void backButtonHandeler()
{
	mciSendString("stop music//StoryTelling.wav", NULL, 0, NULL);
	mciSendString("stop music//GameOver.wav", NULL, 0, NULL);
	mciSendString("play music//Dungeon1.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon2.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon3.wav", NULL, 0, NULL);
	mciSendString("stop music//gameMusic.wav", NULL, 0, NULL);
	mciSendString("stop music//boss.wav", NULL, 0, NULL);

	homePage = 1;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 0;
	gameOver = 0;
	boss = 0;
}

void lvl1ButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 0;
	lvl1Page = 1;
}

void lvl2ButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 0;
	lvl1Page = 0;
	lvl2Page = 1;
}

void lvl3ButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 0;
	lvl1Page = 0;
	lvl2Page = 0;
	lvl3Page = 1;
}

void bossButtonHandeler()
{
	homePage = 0;
	startPage = 0;
	levelPage = 0;
	highscorePage = 0;
	instructionPage = 0;
	maingamePage = 0;
	lvl1Page = 0;
	lvl2Page = 0;
	lvl3Page = 0;
	boss = 1;
}

void changeHeroMove(){

	heroindex++;

	if (heroindex >= 8)
	{
		heroindex = 0;
	}

}

void changeBossMove()
{
	bossindex++;
	if (bossindex == 3)
	{
		bossindex = 0;
	}

}

void autoFire ()
{
	fire = 1;
	fireX = bossX;
	fireY = bossY;

}

void GameOver()
{
	PlaySound(0, 0, 0);
	mciSendString("stop music//gameMusic.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon2.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon3.wav", NULL, 0, NULL);
	mciSendString("stop music//boss.wav", NULL, 0, NULL);
	mciSendString("play music//GameOver.wav", NULL, 0, NULL);
	iSetColor(0, 0, 0);
	iFilledRectangle(0, 0, 1300, 750);


	iShowBMP2(0, 0, "image\\gameover.bmp", 0);
	iShowBMP2(30, 80,"image\\Button.bmp", 0);
	iText(112, 102, "back", GLUT_BITMAP_TIMES_ROMAN_24);

	showChar();
	gameOver = 1;

	playerX = 0, playerY = 300;
	life = 3;


}

void finished()
{
	mciSendString("play music//win.wav", NULL, 0, NULL);
	mciSendString("stop music//Dungeon3.wav", NULL, 0, NULL);
	mciSendString("stop music//boss.wav", NULL, 0, NULL);
	mciSendString("stop music//arrow.wav", NULL, 0, NULL);
	showChar();
	finish = 1;
	iShowBMP2(0, 0, "boss\\finishhh.bmp", 0);

	playerX = 0, playerY = 300;
	life = 3;
	bossHealthBarX = 264;

}


int main()
{
	///srand((unsigned)time(NULL));
	//hero
	iSetTimer(150, changeHeroMove);
	//boss
	iSetTimer(150, changeBossMove);
	iSetTimer(8000, autoFire);
	//lvl1
	iSetTimer(1000, changeTimer);
	intializeImagePosition();
	iSetTimer(90, moveBackground);
	//lvl2
	intializeImagePosition2();
	iSetTimer(110, moveBackground2);
	iSetTimer(1000, changeTimer);
	//lvl3
	intializeImagePosition3();
	iSetTimer(150, moveBackground3);
	iSetTimer(1000, changeTimer);
	//boss
	intializeImagePosition3();
	iSetTimer(150, moveBackground3);
	iSetTimer(1000, changeTimer);
	if (musicOn)
	{
		PlaySound("music\\click1.wav", NULL, SND_ASYNC);
	}
	mciSendString("play music//Dungeon1.wav", NULL, 0, NULL);

	iInitialize(1300, 750, "Feathered Flight: Aerial Messenger Adventure");
	///updated see the documentations
	iStart();
	return 0;
}