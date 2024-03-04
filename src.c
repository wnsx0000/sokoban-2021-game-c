//우분투 gcc 버전

#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <string.h>
#include <stdbool.h>

void StartStage(); // 시작화면 
void HelpPage(char s_sokoban[6][30][31]); // 도움말 화면 
void StartOption(char s_sokoban[6][30][31]); // 레벨별 스테이지 출력
void Name(char s_sokoban[6][30][31]);//이름 입력 
void s_new(char s_sokoban[6][30][31]);// 명령어 n 또는 새로시작 
void s_replay(char s_sokoban[6][30][31]);//리플레이 함수 
void j_save(char s_sokoban[6][30][31]);//세이브
void s_exit(char s_sokoban[6][30][31]);//종
int getch(void);//우분투에서 필요 
void j_file(char s_sokoban[6][30][31]);//로드
void j_rankw(char s_sokoban[6][30][31]);//순위입력함수   
void s_input(char s_sokoban[6][30][31]);
void s_output(char s_sokoban[6][30][31]);
void move_j(char s_sokoban[6][30][31]);//위쪽  
void move_k(char s_sokoban[6][30][31]);//아래쪽  
void move_h(char s_sokoban[6][30][31]);//왼쪽  
void move_l(char s_sokoban[6][30][31]);//오른쪽
void move(char s_map[6][30][31]);//원본 맵 배열
void j_top(char s_sokoban[6][30][31]);//순위 출력 함수 
void J_scanmap(char s_sokoban[6][30][31]);
void s_stage(char s_sokoban[6][30][31], char undo[5][30][31]);
void s_com(char s_sokoban[6][30][31]);
void j_undo_upload(char sokoban[6][30][31], char undo[5][30][31]);
void j_undo_renew(char sokoban[6][30][31], char undo[5][30][31]);
void j_undo_reset(char undo[5][30][31]);
void Help_com(char s_sokoban[6][30][31]);


int main(void)
{
	char sokoban[6][30][31], key;
	char undo[5][30][31];
	int flag;
	int x, y;
	int stage = sokoban[0][0][0];

	j_undo_reset(undo);

	J_scanmap(sokoban);
	StartStage();
	StartOption(sokoban);
	while (1)
	{
		key = getch();
		switch (key)
		{
		case 'h'://왼쪽으로 이동
			j_undo_renew(sokoban, undo);
			move_h(sokoban);
			s_output(sokoban);
			printf("\nLeft");
			s_com(sokoban);
			printf("h");
			break;

		case 'H'://왼쪽으로 이동
			j_undo_renew(sokoban, undo);
			move_h(sokoban);
			s_output(sokoban);
			printf("\nLeft");
			s_com(sokoban);
			printf("H");
			break;

		case 'j'://위쪽으로 이동  
			j_undo_renew(sokoban, undo);
			move_j(sokoban);
			s_output(sokoban);
			printf("\nUp");
			s_com(sokoban);
			printf("j");
			break;

		case 'J'://위쪽으로 이동  
			j_undo_renew(sokoban, undo);
			move_j(sokoban);
			s_output(sokoban);
			printf("\nUp");
			s_com(sokoban);
			printf("J");
			break;

		case 'k'://아래쪽으로 이동
			j_undo_renew(sokoban, undo);
			move_k(sokoban);
			s_output(sokoban);
			printf("\nDown");
			s_com(sokoban);
			printf("k");
			break;

		case 'K'://아래쪽으로 이동  
			j_undo_renew(sokoban, undo);
			move_k(sokoban);
			s_output(sokoban);
			printf("\nDown");
			s_com(sokoban);
			printf("K");
			break;

		case 'l'://오른쪽으로 이동 
			j_undo_renew(sokoban, undo);
			move_l(sokoban);
			s_output(sokoban);
			printf("\nRight");
			s_com(sokoban);
			printf("l");
			break;

		case 'L'://오른쪽으로 이동 
			j_undo_renew(sokoban, undo);
			move_l(sokoban);
			s_output(sokoban);
			printf("\nRight");
			s_com(sokoban);
			printf("L");
			break;

		case 'u'://되돌리기  
			j_undo_upload(sokoban, undo);
			s_output(sokoban);
			printf("\nUndo");
			s_com(sokoban);
			printf("u");

			break;

		case 'U'://되돌리기  
			j_undo_upload(sokoban, undo);
			s_output(sokoban);
			printf("\nUndo");
			s_com(sokoban);
			printf("U");
			break;

		case 'r':
			system("clear");
			s_replay(sokoban);
			printf("\nReplay");
			s_com(sokoban);
			printf("r");
			break;

		case 'R':
			system("clear");
			s_replay(sokoban);
			printf("\nReplay");
			s_com(sokoban);
			printf("R");
			break;

		case 'n':
			sokoban[0][0][0] = 1;
			s_input(sokoban);
			for (int q = 0; q < sokoban[0][2][0]; q++)
			{
				sokoban[0][3][q] = 0;
				sokoban[0][5][q] = 0;
			}
			s_new(sokoban);
			printf("\nReplay from level 1");
			s_com(sokoban);
			printf("n");
			break;

		case 'N':
			sokoban[0][0][0] = 1;
			s_input(sokoban);
			for (int q = 0; q < sokoban[0][2][0]; q++)
			{
				sokoban[0][3][q] = 0;
				sokoban[0][5][q] = 0;
			}
			s_new(sokoban);
			printf("\nReplay from level 1");
			s_com(sokoban);
			printf("N");
			break;

		case 'e':
			printf("\nGood bye!!\n\n");
			abort();
			break;

		case 'E':
			printf("\nGood bye!!\n\n");
			abort();
			break;

		case 's':
			j_save(sokoban);
			printf("\nSaved");
			s_com(sokoban);
			printf("s");
			break;

		case 'S':
			j_save(sokoban);
			printf("\nSaved");
			s_com(sokoban);
			printf("S");
			break;

		case 'f':
			j_file(sokoban);
			system("clear");
			s_output(sokoban);
			printf("\nLoaded");
			s_com(sokoban);
			printf("f");
			break;

		case 'F':
			j_file(sokoban);
			system("clear");
			s_output(sokoban);
			printf("\nLoaded");
			s_com(sokoban);
			printf("F");
			break;

		case 'd':
			system("clear");
			HelpPage(sokoban);
			getch();
			s_output(sokoban);
			s_com(sokoban);
			break;

		case 'D':
			system("clear");
			HelpPage(sokoban);
			getch();
			s_output(sokoban);
			s_com(sokoban);
			break;

		case 't':
			j_top(sokoban);
			printf("t");
			getch();
			s_output(sokoban);
			s_com(sokoban);
			break;

		case 'T':
			j_top(sokoban);
			printf("T");
			getch();
			s_output(sokoban);
			s_com(sokoban);
			break;

		default:
			s_output(sokoban);
			s_com(sokoban);
			break;
		}
		s_stage(sokoban, undo);//스테이지 넘어가는 함수  
	}
}

void s_new(char s_sokoban[6][30][31])
{
	system("clear");
	s_sokoban[0][6][0] = 0; //단계 별 이동횟수 백의자리  초기화 
	s_sokoban[0][6][1] = 0;
	s_sokoban[0][6][2] = 0;
	s_sokoban[0][6][3] = 0;
	s_sokoban[0][6][4] = 0;
	s_output(s_sokoban);
}


void HelpPage(char s_sokoban[6][30][31]) // 도움말 화면 
{


	printf("\n\t\t\t\t\t");
	printf("=========================================");
	printf("\n\t\t\t\t\t");
	printf("    S  O  K  O  B  A  N     H  E  L  P");
	printf("\n\t\t\t\t\t"); 
	printf("=========================================");
	printf("\n\n\t\t\t\t\t");
	printf("h(Left), j(Down), k(Up), l(Right)");
	printf("\n\n\t\t\t\t\t");
	printf("u(undo)");
	printf("\n\n\t\t\t\t\t");
	printf("r(reply)");
	printf("\n\n\t\t\t\t\t");
	printf("n(new)");
	printf("\n\n\t\t\t\t\t");
	printf("e(exit)");
	printf("\n\n\t\t\t\t\t");
	printf("s(save)");
	printf("\n\n\t\t\t\t\t");
	printf("f(file load)");
	printf("\n\n\t\t\t\t\t");
	printf("d(display help)");
	printf("\n\n\t\t\t\t\t");
	printf("t(top)");
	printf("\n\n\t\t\t\t\t");
	printf("enter(redraw)");
	printf("\n\n\t\t\t\t\t");


	Help_com(s_sokoban);
}


void StartStage() // 시작 화면 
{
	system("clear");
	printf("\n\n\t\t\t    ");
	printf("==================================================================");
	printf("\n\n\t\t\t\t");
	printf("   S       O        K       O       B       A       N");
	printf("\n\n\t\t\t    ");
	printf("==================================================================");
	printf("\n\n\n\n\t\t\t");
	printf("    n : New Game\n\n");
	printf("\t\t\t");
	printf("    f : File load\n\n");
	printf("\t\t\t");
	printf("    1~5 : Level Number\n\n");
	printf("\n\n\t\t\t");
}


void StartOption(char s_sokoban[6][30][31]) // 시작 옵션 
{
	char option;
	printf("\n\t\t\t");
	printf("    Input option : ");
	scanf("%c", &option);
	printf("\n");

	if (option - 48 <= s_sokoban[0][2][0] || option == 'n' || option == 'f')
	{
		if (option == 'n' || option == 'N' || option == '1')
		{
			printf("\t\t\t");
			printf("    Input your name : ");
			s_sokoban[0][0][0] = 1;
			s_input(s_sokoban);
			Name(s_sokoban);
			s_new(s_sokoban);

		}
		else if (option == 'f' || option == 'F') //이전 게임 시작
		{
			j_file(s_sokoban);
			system("clear");
			s_output(s_sokoban);//현재 맵 상태 출력 
			printf("\nLoaded");
			s_com(s_sokoban);
		}
		else if (option == '2')
		{
			printf("\n\t\t\t");
			printf("    Input your name : ");
			s_sokoban[0][0][0] = 2;
			s_input(s_sokoban);
			Name(s_sokoban);
			s_new(s_sokoban);
		}
		else if (option == '3')
		{
			printf("\n\t\t\t");
			printf("    Input your name : ");
			s_sokoban[0][0][0] = 3;
			Name(s_sokoban);
			s_input(s_sokoban);
			s_new(s_sokoban);
		}
		else if (option == '4')
		{
			printf("\n\t\t\t");
			printf("    Input your name : ");
			s_sokoban[0][0][0] = 4;
			Name(s_sokoban);
			s_input(s_sokoban);
			s_new(s_sokoban);
		}
		else if (option == '5')
		{
			printf("\n\t\t\t");
			printf("    Input your name : ");
			s_sokoban[0][0][0] = 5;
			Name(s_sokoban);
			s_input(s_sokoban);
			s_new(s_sokoban);
		}
		else
		{
			system("clear");
			StartStage();
			StartOption(s_sokoban);
		}
	}
	else
	{
		system("clear");
		StartStage();
		StartOption(s_sokoban);
	}
}


void Name(char s_sokoban[6][30][31])
{
	char name[100] = { 0 };

	while (1)
	{
		scanf("%s", name);
		if (strlen(name) > 3)
		{
			system("clear");
			StartOption(s_sokoban);
			break;
		}

		for (int n = 0; n < strlen(name); n++)
		{
			if ('a' <= name[n] && name[n] <= 'z' || 'A' <= name[n] && name[n] <= 'Z')
			{
				system("clear");
				for (int m = 0; m <= strlen(name); m++) //이름 배열에 저장  
				{
					s_sokoban[0][1][m] = name[m];
				}
			}

			else
			{
				system("clear");
				StartOption(s_sokoban);
				break;
			}
		}
		break;
	}



}


void s_replay(char s_sokoban[6][30][31])//리플레이 함수 
{
	system("clear");
	s_input(s_sokoban);
	s_output(s_sokoban);
}


void j_file(char s_sokoban[6][30][31])
{
	FILE* SOKO;
	SOKO = fopen("soko.txt", "r");

	//실행 단계
	s_sokoban[0][0][0] = (getc(SOKO) - 48);
	getc(SOKO);

	//플레이어 이름
	for (int n = 0; ; n++)
	{
		s_sokoban[0][1][n] = getc(SOKO);
		if (s_sokoban[0][1][n] == 0)
		{
			break;
		}
	}
	getc(SOKO);

	//단계 개수
	s_sokoban[0][2][0] = (getc(SOKO) - 48);
	getc(SOKO);

	//이동한 횟수
	char word[3];
	for (int n = 0; n < 3; n++)
	{
		word[n] = ' ';
	}

	int value2;
	for (int n = 0; n < 5; n++) //(n+1)번째 단계
	{
		for (int k = 0; k < 4; k++)
		{
			value2 = getc(SOKO);
			if (value2 == '\n')
			{
				s_sokoban[0][5][n] = atoi(word) / 100;
				s_sokoban[0][3][n] = atoi(word) % 100;
				break;
			}
			else
			{
				word[k] = value2;
			}
		}
	}

	//맵
	//맵 개수를 저장할 변수
	int stage_num = 0;

	//문자 단위로 읽어서 검토한 후 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			//getc() 함수로 입력받은 문자를 word 변수에 저장해서 사용
			char word = getc(SOKO);

			//입력받은 문자가 s인 경우
			if (word == 's')
			{
				stage_num++;
				char trash_1 = getc(SOKO); //버리는 값
				j = (-1);
				break;
			}
			//입력받은 문자가 e인 경우 (이 부분에서 함수 종료)
			else if (word == 'e')
			{
				//파일 닫기
				fclose(SOKO);
				return;
			}
			//입력받은 문자가 \n인 경우
			else if (word == '\n')
			{
				s_sokoban[stage_num][j][k] = word;
				break;
			}
			//입력받은 문자가 $인 경우
			else if (word == '$')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 O인 경우
			else if (word == 'O')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 @, #, . 인 경우
			else if (word == '@')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '#')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '.')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 NULL인 경우
			else if (word == 0)
			{
				s_sokoban[stage_num][j][k] = word;
			}
		}
	}
	return;
}

void j_save(char s_sokoban[6][30][31])
{
	system("rm soko.txt");
	system("touch soko.txt");

	//파일 열기
	FILE* SOKO;
	SOKO = fopen("soko.txt", "w");

	//작성하기
	//실행 단계
	putc(s_sokoban[0][0][0] + 48, SOKO);
	putc('\n', SOKO);

	//플레이어 이름
	int k = 0; //k는 플레이어명의 총 자릿수
	for (; ; k++)
	{
		if (s_sokoban[0][1][k] == 0)
		{
			break;
		}
	}
	for (int n = 0; n < k; n++)
	{
		putc(s_sokoban[0][1][n], SOKO);
	}
	putc(0, SOKO);
	putc('\n', SOKO);

	//단계의 개수
	putc(s_sokoban[0][2][0] + 48, SOKO);
	putc('\n', SOKO);

	//이동한 횟수
	char ntow[3];
	for (int j = 0; j < 5; j++)
	{
		int player = s_sokoban[0][3][j] + (s_sokoban[0][5][j] * 100);

		int bak, ship, ill;
		bak = (player / 100); //player의 백의 자리 숫자
		ship = ((player - ((player / 100) * 100)) / 10); //player의 십의 자리 숫자
		ill = (player % 10); //player의 일의 자리 숫자

		if (player >= 100) //세 자리 수인 경우
		{
			putc(bak + 48, SOKO);
			putc(ship + 48, SOKO);
			putc(ill + 48, SOKO);
		}
		else if (player >= 10) //두 자리 수인 경우
		{
			putc(ship + 48, SOKO);
			putc(ill + 48, SOKO);
		}
		else //한 자리 수인 경우
		{
			putc(ill + 48, SOKO);
		}
		putc('\n', SOKO);
	}

	//맵
	for (int q = 1; q <= s_sokoban[0][2][0]; q++)
	{
		char word;
		putc('s', SOKO);
		putc('\n', SOKO);

		int flag = 0;

		for (int w = 0; w < 30; w++)
		{
			for (int e = 0; e < 31; e++)
			{
				word = s_sokoban[q][w][e];
				if (word == '\n')
				{
					putc(word, SOKO);
					break;
				}
				if (word == '0')
				{
					flag++;
					break;
				}
				putc(word, SOKO);
			}

			if (flag == 1)
			{
				break;
			}
		}
	}
	putc('e', SOKO);

	//파일 닫기
	fclose(SOKO);
	system("clear");
	s_output(s_sokoban);

	return;
}


void j_rankw(char s_sokoban[6][30][31])
{
	//ranking 파일 읽어서 배열에 저장
	char rkw[5][6][8]; //이 배열에 순위 파일 정보 저장

	FILE* RANK; //파일 열기
	RANK = fopen("ranking.txt", "r");

	for (int i = 0; i < 5; i++) //(i+1)번째 단계
	{
		for (int k = 0; k < 5; k++) //(k+1)번째 사람
		{
			for (int j = 0; j < 8; j++) //이름과 횟수
			{
				rkw[i][k][j] = getc(RANK);
			}

		}
	}

	fclose(RANK);

	//현재 플레이어의 성적 순위에 반영
	for (int i = 0; i < 5; i++) //(i+1)번째 단계
	{
		int na = s_sokoban[0][3][i]; //나머지
		int x = s_sokoban[0][5][i]; //몫
		int player = 100 * x + na; //(i+1)번째 단계에서 현재 플레이어가 이동한 횟수

		//ranking 파일의 이동횟수들을 정수 상수로 저장
		int load[5]; //ranking 파일의 이동횟수들을 저장할 배열. 인덱스가 작은 쪽이 높은 순위의 이동횟수
		for (int j = 0; j < 5; j++) //ranking 파일의 이동횟수들을 저장
		{
			char w[3];
			w[0] = rkw[i][j][4];
			w[1] = rkw[i][j][5];
			w[2] = rkw[i][j][6];

			load[j] = atoi(w);
		}

		//해당 단계의 5개의 이동횟수와 player를 비교
		int k = 0;
		int z = 0;
		if (player == 0)
		{
			continue;
		}

		for (int w = 0; w < 5; w++) //0으로 기록되어 있는 것들의 개수
		{
			if (load[w] == 0)
			{
				z++;
			}
		}

		if (z != 0) //0으로 기록된 것이 있는 경우
		{
			k = 5 - z;
			for (int num = 0; num < (5 - z); num++) //플레이어의 이동횟수와 랭킹 비교
			{
				if (player < load[num])
				{
					k = num;

					break;
				}
			}
		}
		else //0으로 기록된 것이 없는 경우
		{
			if (player >= load[4]) //등수에 들어가지 못하는 경우
			{
				continue;
			}
			else //등수에 들어가는 경우
			{
				for (; k < 5; k++) //플레이어의 이동횟수와 랭킹 비교
				{
					if (player < load[k])
					{
						break;
					}
				}

			}
		}

		//player가 (k+1)등이 됨

		//player가 들어갈 자리 마련하기(player가 들어갈 자리부터 랭크 하나씩 뒤로 밀기)
		for (int room = 4; room >= k; room--)
		{
			for (int ei = 0; ei < 8; ei++)
			{
				rkw[i][room + 1][ei] = rkw[i][room][ei];
			}
		}


		//횟수를 문자로 바꾼 후 rkw 배열에 저장 (각 자리의 숫자를 구해서 문자로 전환)
		int bak, ship, ill;
		bak = (player / 100); //player의 백의 자리 숫자
		ship = ((player - ((player / 100) * 100)) / 10); //player의 십의 자리 숫자
		ill = (player % 10); //player의 일의 자리 숫자

		if (player >= 100)
		{
			rkw[i][k][4] = bak + 48; //'0'의 아스키 코드 값은 48
			rkw[i][k][5] = ship + 48;
			rkw[i][k][6] = ill + 48;
		}
		else if (player >= 10)
		{
			rkw[i][k][4] = ship + 48;
			rkw[i][k][5] = ill + 48; //'0'의 아스키 코드 값은 48
			rkw[i][k][6] = ' ';
		}
		else
		{
			rkw[i][k][4] = ill + 48;
			rkw[i][k][5] = ' ';
			rkw[i][k][6] = ' ';
		}

		//플레이어명을 rkw 배열에 저장
		int c_n = 0;
		for (; c_n < 3; c_n++)
		{
			if (s_sokoban[0][1][c_n] == 0)
			{
				rkw[i][k][c_n] = ' ';
			}
			else if (s_sokoban[0][1][c_n] == '0')
			{
				rkw[i][k][c_n] = ' ';
			}
			else
			{
				rkw[i][k][c_n] = s_sokoban[0][1][c_n];
			}
		}
	}

	//배열을 ranking 파일에 출력(저장)
	FILE* RANK2;
	RANK2 = fopen("ranking.txt", "w");

	for (int i = 0; i < 5; i++) //i번째 단계
	{
		for (int k = 0; k < 5; k++) //k번째 사람
		{
			for (int j = 0; j < 8; j++) //이름과 횟수
			{
				fprintf(RANK2, "%c", rkw[i][k][j]);
			}

		}
	}

	fclose(RANK2);
	return;
}


void s_input(char s_sokoban[6][30][31])
{
	FILE* MAP = fopen("map.txt", "r");// 맵 열기  
	if (MAP == NULL)
	{
		printf("cant open map.txt");
	}

	//맵 개수를 저장할 변수
	int stage_num = 0;

	//문자 단위로 읽어서 검토한 후 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			//getc() 함수로 입력받은 문자를 word 변수에 저장해서 사용
			char word = getc(MAP);

			//입력받은 문자가 s인 경우
			if (word == 's')
			{
				stage_num++;
				char trash_1 = getc(MAP); //버리는 값
				j = (-1);
				break;
			}
			//입력받은 문자가 e인 경우 (이 부분에서 함수 종료)
			else if (word == 'e')
			{
				//파일 닫기
				fclose(MAP);

				return;
			}
			//입력받은 문자가 \n인 경우
			else if (word == '\n')
			{
				s_sokoban[stage_num][j][k] = word;
				break;
			}
			//입력받은 문자가 $인 경우
			else if (word == '$')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 O인 경우
			else if (word == 'O')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 @, #, . 인 경우
			else if (word == '@')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '#')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '.')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 NULL인 경우
			else if (word == 0)
			{
				s_sokoban[stage_num][j][k] = word;
			}
		}
	}

	/*
	char tmp;
	for (int m = 1; m <= 5; m++)//파일 입력받기
	{
		fscanf(MAP, "%c\n", &tmp);
		for (int i = 0; i < 11; i++)
		{
			fscanf(MAP, "%s\n", s_sokoban[m][i]);
		}
	}
	*/
}


void s_output(char s_sokoban[6][30][31])//맵 출력  
{
	system("clear");
	printf("======================\n");
	printf("    %s in Level %d\n", s_sokoban[0][1], s_sokoban[0][0][0]);
	printf("======================\n");

	int m = s_sokoban[0][0][0];

	int kk = 0;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (s_sokoban[m][i][j] == '\n')
			{
				printf("%c", s_sokoban[m][i][j]);
				break;
			}
			else if (s_sokoban[m][i][j] == '0')
			{
				kk++;
				break;
			}
			else
			{
				printf("%c", s_sokoban[m][i][j]);
			}
		}
		if (kk == 1)
		{
			break;
		}
	}
}

void move_j(char s_sokoban[6][30][31])//위쪽  
{
	int m = s_sokoban[0][0][0];
	int n_stage = s_sokoban[0][0][0];
	int x, y;
	char map[6][30][31];
	move(map);

	int flag = 0;
	for (y = 0; y < 30; y++)// 위치 확인   
	{
		for (x = 0; x < 31; x++)
		{
			if (s_sokoban[n_stage][y][x] == '@')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (map[n_stage][y][x] == 'O')//보관장소 관련  
	{
		if (s_sokoban[n_stage][y][x] == '@' && s_sokoban[n_stage][y - 1][x] != '#')
		{
			if (s_sokoban[n_stage][y - 1][x] == '$' && s_sokoban[n_stage][y - 2][x] == 'O')
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y - 1][x] = '@';
				s_sokoban[n_stage][y - 2][x] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else if (s_sokoban[n_stage][y - 1][x] == '$' && s_sokoban[n_stage][y - 2][x] == '#')//벽에 막힐때  
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y - 1][x] = '$';
				s_sokoban[n_stage][y - 2][x] = '#';
			}
			else if (s_sokoban[n_stage][y + 1][x] == '$' && s_sokoban[n_stage][y + 2][x] == '$')
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y - 1][x] = '$';
				s_sokoban[n_stage][y - 2][x] = '$';
			}
			else if (s_sokoban[n_stage][y - 1][x] == '$' && s_sokoban[n_stage][y - 2][x] == '.')//보관장소가 맵 중앙에 있을때  
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y - 1][x] = '@';
				s_sokoban[n_stage][y - 2][x] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else
			{
				s_sokoban[n_stage][y - 1][x] = '@';
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[0][3][m - 1]++;
			}
		}
	}

	if (s_sokoban[n_stage][y - 1][x] == '.' || s_sokoban[n_stage][y - 1][x] == 'O')//왼쪽 1칸이 .일때  
	{
		s_sokoban[n_stage][y][x] = '.';
		s_sokoban[n_stage][y - 1][x] = '@';
		s_sokoban[0][3][m - 1]++;
	}
	else if (s_sokoban[n_stage][y - 1][x] == '$')//왼쪽 1칸이 상자일때  
	{
		if (s_sokoban[n_stage][y - 2][x] == '.')
		{
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[n_stage][y - 1][x] = '@';
			s_sokoban[n_stage][y - 2][x] = '$';
			s_sokoban[0][3][m - 1]++;
		}

		else if (s_sokoban[n_stage][y - 2][x] == 'O')
		{
			s_sokoban[n_stage][y - 2][x] = '$';
			s_sokoban[n_stage][y - 1][x] = '@';
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[0][3][m - 1]++;
		}
	}
}


void move_l(char s_sokoban[6][30][31])//오른쪽  
{
	int x, y;
	int m = s_sokoban[0][0][0];
	int n_stage = s_sokoban[0][0][0];
	char map[6][30][31];
	move(map);

	int flag = 0;
	for (y = 0; y < 30; y++)// 위치 확인   
	{
		for (x = 0; x < 31; x++)
		{
			if (s_sokoban[n_stage][y][x] == '@')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (map[n_stage][y][x] == 'O')//보관장소 관련  
	{
		if (s_sokoban[n_stage][y][x] == '@' && s_sokoban[n_stage][y][x + 1] != '#')
		{
			if (s_sokoban[n_stage][y][x + 1] == '$' && s_sokoban[n_stage][y][x + 2] == 'O')
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y][x + 1] = '@';
				s_sokoban[n_stage][y][x + 2] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else if (s_sokoban[n_stage][y][x + 1] == '$' && s_sokoban[n_stage][y][x + 2] == '#')//벽에 막힐때  
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y][x + 1] = '$';
				s_sokoban[n_stage][y][x + 2] = '#';
			}
			else if (s_sokoban[n_stage][y][x + 1] == '$' && s_sokoban[n_stage][y][x + 2] == '$')
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y][x + 1] = '$';
				s_sokoban[n_stage][y][x + 2] = '$';
			}
			else if (s_sokoban[n_stage][y][x + 1] == '$' && s_sokoban[n_stage][y][x + 2] == '.')//보관장소가 맵 중앙에 있을때  
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y][x + 1] = '@';
				s_sokoban[n_stage][y][x + 2] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else
			{
				s_sokoban[n_stage][y][x + 1] = '@';
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[0][3][m - 1]++;
			}
		}
	}

	if (s_sokoban[n_stage][y][x + 1] == '.' || s_sokoban[n_stage][y][x + 1] == 'O')//왼쪽 1칸이 .일때  
	{
		s_sokoban[n_stage][y][x] = '.';
		s_sokoban[n_stage][y][x + 1] = '@';
		s_sokoban[0][3][m - 1]++;

	}
	else if (s_sokoban[n_stage][y][x + 1] == '$')//왼쪽 1칸이 상자일때  
	{
		if (s_sokoban[n_stage][y][x + 2] == '.')
		{
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[n_stage][y][x + 1] = '@';
			s_sokoban[n_stage][y][x + 2] = '$';
			s_sokoban[0][3][m - 1]++;
		}

		else if (s_sokoban[n_stage][y][x + 2] == 'O')
		{
			s_sokoban[n_stage][y][x + 2] = '$';
			s_sokoban[n_stage][y][x + 1] = '@';
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[0][3][m - 1]++;
		}
	}
}

void move_h(char s_sokoban[6][30][31])//왼쪽  
{
	int x, y;
	int m = s_sokoban[0][0][0];
	int n_stage = s_sokoban[0][0][0];
	char map[6][30][31];
	move(map);

	int flag = 0;
	for (y = 0; y < 30; y++)// 위치 확인   
	{
		for (x = 0; x < 31; x++)
		{
			if (s_sokoban[n_stage][y][x] == '@')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (map[n_stage][y][x] == 'O')//보관장소 관련  
	{
		if (s_sokoban[n_stage][y][x] == '@' && s_sokoban[n_stage][y][x - 1] != '#')
		{
			if (s_sokoban[n_stage][y][x - 1] == '$' && s_sokoban[n_stage][y][x - 2] == 'O')//보관장소가 연달아 있을때  
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y][x - 1] = '@';
				s_sokoban[n_stage][y][x - 2] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else if (s_sokoban[n_stage][y][x - 1] == '$' && s_sokoban[n_stage][y][x - 2] == '#')//벽에 막힐때  
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y][x - 1] = '$';
				s_sokoban[n_stage][y][x - 2] = '#';
			}
			else if (s_sokoban[n_stage][y][x - 1] == '$' && s_sokoban[n_stage][y][x - 2] == '$')//상자에 막힐때  
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y][x - 1] = '$';
				s_sokoban[n_stage][y][x - 2] = '$';
			}
			else if (s_sokoban[n_stage][y][x - 1] == '$' && s_sokoban[n_stage][y][x - 2] == '.')//보관장소가 맵 중앙에 있을때  
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y][x - 1] = '@';
				s_sokoban[n_stage][y][x - 2] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else
			{
				s_sokoban[n_stage][y][x - 1] = '@';
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[0][3][m - 1]++;
			}
		}
	}

	if (s_sokoban[n_stage][y][x - 1] == '.' || s_sokoban[n_stage][y][x - 1] == 'O')//왼쪽 1칸이 .일때  
	{
		s_sokoban[n_stage][y][x] = '.';
		s_sokoban[n_stage][y][x - 1] = '@';
		s_sokoban[0][3][m - 1]++;

	}
	else if (s_sokoban[n_stage][y][x - 1] == '$')//왼쪽 1칸이 상자일때  
	{
		if (s_sokoban[n_stage][y][x - 2] == '.')
		{
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[n_stage][y][x - 1] = '@';
			s_sokoban[n_stage][y][x - 2] = '$';
			s_sokoban[0][3][m - 1]++;
		}

		else if (s_sokoban[n_stage][y][x - 2] == 'O')
		{
			s_sokoban[n_stage][y][x - 2] = '$';
			s_sokoban[n_stage][y][x - 1] = '@';
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[0][3][m - 1]++;
		}
	}
}


void move_k(char s_sokoban[6][30][31])//아래쪽  
{
	int x, y;
	int m = s_sokoban[0][0][0];
	int n_stage = s_sokoban[0][0][0];
	char map[6][30][31];
	move(map);

	int flag = 0;
	for (y = 0; y < 30; y++)// 위치 확인   
	{
		for (x = 0; x < 31; x++)
		{
			if (s_sokoban[n_stage][y][x] == '@')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	if (map[n_stage][y][x] == 'O')//보관장소 관련  
	{
		if (s_sokoban[n_stage][y][x] == '@' && s_sokoban[n_stage][y + 1][x] != '#')
		{
			if (s_sokoban[n_stage][y + 1][x] == '$' && s_sokoban[n_stage][y + 2][x] == 'O')
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y + 1][x] = '@';
				s_sokoban[n_stage][y + 2][x] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else if (s_sokoban[n_stage][y + 1][x] == '$' && s_sokoban[n_stage][y + 2][x] == '#')//벽에 막힐때  
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y + 1][x] = '$';
				s_sokoban[n_stage][y + 2][x] = '#';
			}
			else if (s_sokoban[n_stage][y + 1][x] == '$' && s_sokoban[n_stage][y + 2][x] == '$')
			{
				s_sokoban[n_stage][y][x] = '@';
				s_sokoban[n_stage][y + 1][x] = '$';
				s_sokoban[n_stage][y + 2][x] = '$';
			}
			else if (s_sokoban[n_stage][y + 1][x] == '$' && s_sokoban[n_stage][y + 2][x] == '.')//보관장소가 맵 중앙에 있을때  
			{
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[n_stage][y + 1][x] = '@';
				s_sokoban[n_stage][y + 2][x] = '$';
				s_sokoban[0][3][m - 1]++;
			}
			else
			{
				s_sokoban[n_stage][y + 1][x] = '@';
				s_sokoban[n_stage][y][x] = 'O';
				s_sokoban[0][3][m - 1]++;
			}
		}
	}

	if (s_sokoban[n_stage][y + 1][x] == '.' || s_sokoban[n_stage][y + 1][x] == 'O')//왼쪽 1칸이 .일때  
	{
		s_sokoban[n_stage][y][x] = '.';
		s_sokoban[n_stage][y + 1][x] = '@';
		s_sokoban[0][3][m - 1]++;

	}
	else if (s_sokoban[n_stage][y + 1][x] == '$')//왼쪽 1칸이 상자일때  
	{
		if (s_sokoban[n_stage][y + 2][x] == '.')
		{
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[n_stage][y + 1][x] = '@';
			s_sokoban[n_stage][y + 2][x] = '$';
			s_sokoban[0][3][m - 1]++;
		}

		else if (s_sokoban[n_stage][y + 2][x] == 'O')
		{
			s_sokoban[n_stage][y + 2][x] = '$';
			s_sokoban[n_stage][y + 1][x] = '@';
			s_sokoban[n_stage][y][x] = '.';
			s_sokoban[0][3][m - 1]++;
		}
	}
}


void move(char s_sokoban[6][30][31])//원본 맵 배열  
{
	FILE* MAP = fopen("map.txt", "r");// 맵 열기  
	//맵 개수를 저장할 변수
	int stage_num = 0;

	//문자 단위로 읽어서 검토한 후 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			//getc() 함수로 입력받은 문자를 word 변수에 저장해서 사용
			char word = getc(MAP);

			//입력받은 문자가 s인 경우
			if (word == 's')
			{
				stage_num++;
				char trash_1 = getc(MAP); //버리는 값
				j = (-1);
				break;
			}
			//입력받은 문자가 e인 경우 (이 부분에서 함수 종료)
			else if (word == 'e')
			{
				//파일 닫기
				fclose(MAP);

				return;
			}
			//입력받은 문자가 \n인 경우
			else if (word == '\n')
			{
				s_sokoban[stage_num][j][k] = word;
				break;
			}
			//입력받은 문자가 $인 경우
			else if (word == '$')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 O인 경우
			else if (word == 'O')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 @, #, . 인 경우
			else if (word == '@')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '#')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '.')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 NULL인 경우
			else if (word == 0)
			{
				s_sokoban[stage_num][j][k] = word;
			}
		}
	}

}

void j_top(char s_sokoban[6][30][31])
{


	//순위 파일 읽어서 배열에 저장
	char rkw[5][5][8] = { 0 }; //이 배열에 순위 파일 정보 저장. 0(NULL 문자)으로 초기화

	FILE* RANK; //파일 열기
	RANK = fopen("ranking.txt", "r"); //ranking.txt 파일에서 읽음

	int stage_num = 0; //맵 넘버를 저장할 변수

	for (int i = 0; i < 5; i++) //i번째 단계
	{
		for (int k = 0; k < 5; k++) //k번째 사람
		{
			for (int j = 0; j < 8; j++) //이름과 횟수
			{
				rkw[i][k][j] = getc(RANK);
			}

		}
	}

	//배열을 형식에 맞춰 출력
	system("clear");
	printf("===============\n"); //15개
	printf(" R A N K I N G \n");
	printf("===============\n"); //15개
	for (int n = 0; n < 5; n++) //n번째 단계
	{
		printf("*** LEVEL %d ***\n", (n + 1));
		for (int k = 0; k < 5; k++) //k번째 사람
		{
			if (rkw[n][0][0] == ' ')
			{
				printf("NONE\n");
				break;
			}

			if (rkw[n][k][0] == ' ') //이름과 횟수
			{
				break;
			}

			printf("%c%c%c ", rkw[n][k][0], rkw[n][k][1], rkw[n][k][2]);
			printf("%c%c%c", rkw[n][k][4], rkw[n][k][5], rkw[n][k][6]);
			printf("\n");
		}
	}

	s_com(s_sokoban);
}


void J_scanmap(char s_sokoban[6][30][31])
{
	//배열 초기화, 특정 값 배정
	for (int h = 0; h < 6; h++)
	{
		for (int j = 0; j < 30; j++)
		{
			for (int k = 0; k < 31; k++)
			{
				s_sokoban[h][j][k] = '0';
			}
		}
	}
	for (int n = 0; n < 5; n++)
	{
		s_sokoban[0][3][n] = 0;
	}
	for (int n = 0; n < 5; n++)
	{
		s_sokoban[0][5][n] = 0;
	}
	s_sokoban[0][0][0] = 1;

	//파일 열기
	FILE* MAP;
	MAP = fopen("map.txt", "r");

	//맵 개수를 저장할 변수
	int stage_num = 0;

	//$(박스)와 O(보관장소)의 개수가 같은지 검토하기 위한 변수
	int box = 0;
	int room = 0;

	//문자 단위로 읽어서 검토한 후 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			//getc() 함수로 입력받은 문자를 word 변수에 저장해서 사용
			char word = getc(MAP);

			//입력받은 문자가 s인 경우
			if (word == 's')
			{
				//$(박스)와 O(보관장소)의 개수가 같은지 검토
				if (box != room)
				{
					printf("Wrong level %d map\n", stage_num);
					abort();
				}

				stage_num++;
				char trash_1 = getc(MAP); //버리는 값
				j = (-1);

				break;
			}
			//입력받은 문자가 e인 경우 (이 부분에서 함수 종료)
			else if (word == 'e')
			{
				//파일 닫기
				fclose(MAP);

				//배열에 단계 개수 저장
				s_sokoban[0][2][0] = stage_num;

				return;
			}
			//입력받은 문자가 \n인 경우
			else if (word == '\n')
			{
				s_sokoban[stage_num][j][k] = word;
				break;
			}
			//입력받은 문자가 $인 경우
			else if (word == '$')
			{
				box++;
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 O인 경우
			else if (word == 'O')
			{
				room++;
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 @, #, . 인 경우
			else if (word == '@')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '#')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			else if (word == '.')
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//입력받은 문자가 NULL인 경우
			else if (word == 0)
			{
				s_sokoban[stage_num][j][k] = word;
			}
			//지정된 문자 외의 문자인 경우
			else
			{
				printf("Wrong level %d map\n", stage_num);
				fclose(MAP);
				abort();
			}
		}
	}
}


int getch(void) {
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}


void s_stage(char s_sokoban[6][30][31], char undo[5][30][31])
{
	int m = s_sokoban[0][0][0];
	int x, y;
	int room = 0;
	int clear = 0;
	char answer;
	char map[6][30][31];
	move(map);
	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			if (map[m][j][k] == 'O')
			{
				clear++;
			}
		}
	}

	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 31; k++)
		{
			if (map[m][j][k] == 'O')
			{
				if (s_sokoban[m][j][k] == '$')
					room++;
			}
		}
	}

	if (room == clear)
	{
		j_rankw(s_sokoban); //플레이어의 기록 순위에 반영
		j_undo_reset(undo);

		printf("\nGood job! Continue (N/Y) ");

		while (1)
		{
			answer = getch();

			if (((answer == 'n' || answer == 'N') || answer == 'y') || answer == 'Y')
			{
				break;
			}
		}

		switch (answer)
		{
		case 'n':
			printf("\nGood bye!!\n\n");
			abort();

		case 'N':
			printf("\nGood bye!!\n\n");
			abort();

		case 'y':

			s_sokoban[0][0][0]++;
			if (s_sokoban[0][0][0] > s_sokoban[0][2][0])
			{
				printf("\nGood bye!!\n\n");
				abort();
			}
			s_output(s_sokoban);
			printf("\nYou are in the level %d, now", s_sokoban[0][0][0]);
			s_com(s_sokoban);
			break;

		case 'Y':

			s_sokoban[0][0][0]++;
			if (s_sokoban[0][0][0] > s_sokoban[0][2][0])
			{
				printf("\nGood bye!!\n\n");
				abort();
			}
			s_output(s_sokoban);
			printf("\nYou are in the level %d, now", s_sokoban[0][0][0]);
			s_com(s_sokoban);
			break;
		}
	}
}


void s_com(char s_sokoban[6][30][31])
{
	int m = s_sokoban[0][0][0];
	int k = s_sokoban[0][3][m - 1];
	int l = s_sokoban[0][5][m - 1];
	int j = s_sokoban[0][6][m - 1];
	if (s_sokoban[0][3][m - 1] < 100)
	{
		j = 100 * l + k;
	}
	else if (s_sokoban[0][3][m - 1] == 100)
	{
		s_sokoban[0][3][m - 1] = 0;
		s_sokoban[0][5][m - 1]++;
		j = 100 * l + k;
	}
	printf("\n");
	printf("(Moves) %04d\n", j);
	printf("(Command) ");
}


void Help_com(char s_sokoban[6][30][31])
{
	int m = s_sokoban[0][0][0];
	int k = s_sokoban[0][3][m - 1];
	int l = s_sokoban[0][5][m - 1];
	int j = s_sokoban[0][6][m - 1];
	if (s_sokoban[0][3][m - 1] < 100)
	{
		j = 100 * l + k;
	}
	else if (s_sokoban[0][3][m - 1] == 100)
	{
		s_sokoban[0][3][m - 1] = 0;
		s_sokoban[0][5][m - 1]++;
		j = 100 * l + k;
	}
	printf("\n");
	printf("\t\t\t\t\t(Moves) %04d\n", j);
	printf("\t\t\t\t\t(Command) ");
}



//undo 명령을 사용했을 때 적용될 함수. undo용 배열에 있는 내용을 현재 실행 단계에 해당하는 배열에 저장
void j_undo_upload(char sokoban[6][30][31], char undo[5][30][31])
{
	int stage_num = sokoban[0][0][0]; //현재 실행 단계

	if (undo[0][0][0] == '0')
	{
		return;
	}

	//undo는 각 stage에서 최대 5번씩 할 수 있는 것으로.
	static int use_num[5] = { 5, 5, 5, 5, 5 }; //각 단계별로 실행 가능한 undo 명령 개수
	if (use_num[stage_num - 1] == 0)
	{
		return;
	}
	else
	{
		use_num[stage_num - 1] -= 1; //각 단계별로 실행 가능한 undo 명령 개수에 반영
	}

	//undo용 배열에 들어 있는 기록을 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int i = 0; i < 31; i++)
		{
			sokoban[stage_num][j][i] = undo[0][j][i];
		}
	}

	for (int q = 0; q < 4; q++)
	{
		for (int j = 0; j < 30; j++)
		{
			for (int i = 0; i < 31; i++)
			{
				undo[q][j][i] = undo[q + 1][j][i];
			}
		}
	}

	for (int j = 0; j < 30; j++)
	{
		for (int i = 0; i < 31; i++)
		{
			undo[4][j][i] = '0';
		}
	}

	//움직인 횟수에 반영
	sokoban[0][3][stage_num - 1] += 1;

	return;
}

//움직이기 전 기록을 undo용 배열에 저장. (hjkl 명령 사용 직전에 넣을 함수)
void j_undo_renew(char sokoban[6][30][31], char undo[5][30][31])
{
	int stage_num = sokoban[0][0][0]; //현재 실행 단계

	//undo용 배열에 저장된 맵 밀기
	for (int n = 4; n > 0; n--)
	{
		for (int j = 0; j < 30; j++)
		{
			for (int i = 0; i < 31; i++)
			{
				undo[n][j][i] = undo[n - 1][j][i];
			}
		}
	}

	//배열에 들어 있는 현재 맵을 undo용 배열에 저장
	for (int j = 0; j < 30; j++)
	{
		for (int i = 0; i < 31; i++)
		{
			undo[0][j][i] = sokoban[stage_num][j][i];
		}
	}

}

//undo용 배열을 '0'으로 초기화.각 단계가 시작할 때마다 초기화 해줘야 함
void j_undo_reset(char undo[5][30][31])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			for (int k = 0; k < 31; k++)
			{
				undo[i][j][k] = '0';
			}
		}
	}
}