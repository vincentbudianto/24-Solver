/* NIM/Nama  : 13517137/Vincent Budianto
 * Nama file : 24 Game.cpp
 * Topik     : Tugas Kecil I IF2211 - Strategi Algoritma / Penyelesaian 24 Game dengan Algoritma Brute Force
 * Tanggal   : 23 Januari 2019
 * Deskripsi : Source code permainan 24 Game menggunakan strategi algoritma brute force */

#include <iostream>
#include <ctime>
using namespace std;

//Definisi Fungsi + Prosedur
bool valid(float a, float b, float c, float d);
// mengecek apakah a, b, c, dan d merupakan bilangan positif atau bukan
void swap(int x, float *a, float *b, float *c, float *d, float p, float q, float r, float s);
// mengubah urutan posisi a b c d
void calculate1(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... b ... c ... d
void calculate2(int x, int y, float a, float b, float c, float d, int *e);
// menghitung (a ... b) ... c ... d
void calculate3(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... (b ... c) ... d
void calculate4(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... b ... (c ... d)
void calculate5(int x, int y, float a, float b, float c, float d, int *e);
// menghitung (a ... b ... c) ... d
void calculate6(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... (b ... c ... d)
void calculate7(int x, int y, float a, float b, float c, float d, int *e);
// menghitung (a ... b) ... (c ... d)
void calculate8(int x, int y, float a, float b, float c, float d, int *e);
// menghitung ((a ... b) ... c) ... d
void calculate9(int x, int y, float a, float b, float c, float d, int *e);
// menghitung (a ... (b ... c)) ... d
void calculate10(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... ((b ... c) ... d)
void calculate11(int x, int y, float a, float b, float c, float d, int *e);
// menghitung a ... (b ... (c ... d))

int main()
{
	//Kamus
	bool cek;				//variabel untuk mengecek input merupakan bilangan positif
	int i;					//variabel untuk menentukan kombinasi bilangan
	int x;					//variabel untuk menentukan operator pertama
	int y;					//variabel untuk menentukan operator kedua
	int count;				//variabel untuk menghitung jumlah kombinasi yang bernilai 24
	float a, b, c, d;		//variabel yang digunakan dalam perhitungan
	float p, q, r, s;		//variabel yang digunakan untuk mengubah kombinasi variabel yang digunakan dalam perhitungan
	float timer;			//variabel untuk menentukan waktu eksekusi program setelah program menerima input

	//Algoritma
	cek = false;
	count = 0;

	while (!cek)
	{
		printf(" ____________________________________________________________________________________________________\n");
		printf("| __          __  _                            _          ___  _  _      _____                       |\n");
		printf("| \\ \\        / / | |                          | |        |__ \\| || |    / ____|                      |\n");
		printf("|  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___      ) | || |_  | |  __  __ _ _ __ ___   ___  |\n");
		printf("|   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\    / /|__   _| | | |_ |/ _` | '_ ` _ \\ / _ \\ |\n");
		printf("|    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |  / /_   | |   | |__| | (_| | | | | | |  __/ |\n");
		printf("|     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |____|  |_|    \\_____|\\__,_|_| |_| |_|\\___| |\n");
		printf("|____________________________________________________________________________________________________|\n");
		printf("\n   input 4 numbers : ");
		scanf("%f %f %f %f", &a, &b, &c, &d);
		cek = valid(a, b, c, d);

		if (!cek)
		{
			printf("\n ------------------------------------------- invalid input ------------------------------------------");
			printf("\n -------------------------------------- press enter to continue -------------------------------------\n ");
			cin.get();
			cin.get();
			system("cls");
		}
	}

	printf("   Result :\n");
	p = a;
	q = b;
	r = c;
	s = d;
	timer = clock();

	for (i = 0; i <= 24; i++)
	{
		for (x = 1; x <= 4; x++)
		{
			for (y = 1; y <= 4; y++)
			{
				// calculate1 a ... b ... c ... d
				calculate1(x, y, a, b, c, d, &count);
				// calculate2 (a ... b) ... c ... d
				calculate2(x, y, a, b, c, d, &count);
				// calculate3 a ... (b ... c) ... d
				calculate3(x, y, a, b, c, d, &count);
				// calculate4 a ... b ... (c ... d)
				calculate4(x, y, a, b, c, d, &count);
				// calculate5 (a ... b ... c) ... d
				calculate5(x, y, a, b, c, d, &count);
				// calculate6 a ... (b ... c ... d)
				calculate6(x, y, a, b, c, d, &count);
				// calculate7 (a ... b) ... (c ... d)
				calculate7(x, y, a, b, c, d, &count);
				// calculate8 ((a ... b) ... c) ... d
				calculate8(x, y, a, b, c, d, &count);
				// calculate9 (a ... (b ... c)) ... d
				calculate9(x, y, a, b, c, d, &count);
				// calculate10 a ... ((b ... c) ... d)
				calculate10(x, y, a, b, c, d, &count);
				// calculate11 a ... (b ... (c ... d))
				calculate11(x, y, a, b, c, d, &count);
			}
		}

		swap(i, &a, &b, &c, &d, p ,q, r, s);
	}

	timer = (clock() - timer) / CLOCKS_PER_SEC;
	printf("\n   ------------------------------------------------------------------------------------------------\n");

	if (count == 0)
	{
		printf("\n   no solution found\n");
	}
	else
	{
		printf("\n   %d solutions found\n", count);
	}

	printf("   execution time = %.5f seconds\n", timer);
	return 0;
}

//Realisasi Fungsi + Prosedur
bool valid(float a, float b, float c, float d)
// mengecek apakah a, b, c, dan d merupakan bilangan positif atau bukan
{
	//Kamus Lokal
	bool v;

	// Algoritma
	v = true;
	if ((a < 0) || (b < 0) || (c < 0) || (d < 0))
	{
		v = false;
	}
	return v;
}

void swap(int x, float *a, float *b, float *c, float *d, float p, float q, float r, float s)
// mengubah urutan posisi a b c d
{
	//Kamus Lokal

	// Algoritma
	switch (x)
	{
		case 1:
		{
			*a = p;
			*b = q;
			*c = s;
			*d = r;
			break;
		}
		case 2:
		{
			*a = p;
			*b = r;
			*c = q;
			*d = s;
			break;
		}
		case 3:
		{
			*a = p;
			*b = r;
			*c = s;
			*d = q;
			break;
		}
		case 4:
		{
			*a = p;
			*b = s;
			*c = q;
			*d = r;
			break;
		}
		case 5:
		{
			*a = p;
			*b = s;
			*c = r;
			*d = q;
			break;
		}
		case 6:
		{
			*a = q;
			*b = p;
			*c = r;
			*d = s;
			break;
		}
		case 7:
		{
			*a = q;
			*b = p;
			*c = s;
			*d = r;
			break;
		}
		case 8:
		{
			*a = q;
			*b = r;
			*c = p;
			*d = s;
			break;
		}
		case 9:
		{
			*a = q;
			*b = r;
			*c = s;
			*d = p;
			break;
		}
		case 10:
		{
			*a = q;
			*b = s;
			*c = p;
			*d = r;
			break;
		}
		case 11:
		{
			*a = q;
			*b = s;
			*c = r;
			*d = p;
			break;
		}
		case 12:
		{
			*a = r;
			*b = p;
			*c = q;
			*d = s;
			break;
		}
		case 13:
		{
			*a = r;
			*b = p;
			*c = s;
			*d = q;
			break;
		}
		case 14:
		{
			*a = r;
			*b = q;
			*c = p;
			*d = s;
			break;
		}
		case 15:
		{
			*a = r;
			*b = q;
			*c = s;
			*d = p;
			break;
		}
		case 16:
		{
			*a = r;
			*b = s;
			*c = p;
			*d = q;
			break;
		}
		case 17:
		{
			*a = r;
			*b = s;
			*c = q;
			*d = p;
			break;
		}
		case 18:
		{
			*a = s;
			*b = p;
			*c = q;
			*d = r;
			break;
		}
		case 19:
		{
			*a = s;
			*b = p;
			*c = r;
			*d = q;
			break;
		}
		case 20:
		{
			*a = s;
			*b = q;
			*c = p;
			*d = r;
			break;
		}
		case 21:
		{
			*a = s;
			*b = q;
			*c = r;
			*d = p;
			break;
		}
		case 22:
		{
			*a = s;
			*b = r;
			*c = p;
			*d = q;
			break;
		}
		case 23:
		{
			*a = s;
			*b = r;
			*c = q;
			*d = p;
			break;
		}
	}
}

void calculate1(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... b ... c ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + b + c + d;
					result2 = a + b + c - d;
					result3 = a + b + c * d;
					result4 = a + b + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + b - c + d;
					result2 = a + b - c - d;
					result3 = a + b - c * d;
					result4 = a + b - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + b * c + d;
					result2 = a + b * c - d;
					result3 = a + b * c * d;
					result4 = a + b * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + b / c + d;
					result2 = a + b / c - d;
					result3 = a + b / c * d;
					result4 = a + b / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - b + c + d;
					result2 = a - b + c - d;
					result3 = a - b + c * d;
					result4 = a - b + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - b - c + d;
					result2 = a - b - c - d;
					result3 = a - b - c * d;
					result4 = a - b - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - b * c + d;
					result2 = a - b * c - d;
					result3 = a - b * c * d;
					result4 = a - b * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - b / c + d;
					result2 = a - b / c - d;
					result3 = a - b / c * d;
					result4 = a - b / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * b + c + d;
					result2 = a * b + c - d;
					result3 = a * b + c * d;
					result4 = a * b + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * b - c + d;
					result2 = a * b - c - d;
					result3 = a * b - c * d;
					result4 = a * b - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * b * c + d;
					result2 = a * b * c - d;
					result3 = a * b * c * d;
					result4 = a * b * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * b / c + d;
					result2 = a * b / c - d;
					result3 = a * b / c * d;
					result4 = a * b / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / b + c + d;
					result2 = a / b + c - d;
					result3 = a / b + c * d;
					result4 = a / b + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / b - c + d;
					result2 = a / b - c - d;
					result3 = a / b - c * d;
					result4 = a / b - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / b * c + d;
					result2 = a / b * c - d;
					result3 = a / b * c * d;
					result4 = a / b * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / b / c + d;
					result2 = a / b / c - d;
					result3 = a / b / c * d;
					result4 = a / b / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate2(int x, int y, float a, float b, float c, float d, int *e)
// menghitung (a ... b) ... c ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a + b) + c + d;
					result2 = (a + b) + c - d;
					result3 = (a + b) + c * d;
					result4 = (a + b) + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a + b) - c + d;
					result2 = (a + b) - c - d;
					result3 = (a + b) - c * d;
					result4 = (a + b) - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a + b) * c + d;
					result2 = (a + b) * c - d;
					result3 = (a + b) * c * d;
					result4 = (a + b) * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a + b) / c + d;
					result2 = (a + b) / c - d;
					result3 = (a + b) / c * d;
					result4 = (a + b) / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a - b) + c + d;
					result2 = (a - b) + c - d;
					result3 = (a - b) + c * d;
					result4 = (a - b) + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a - b) - c + d;
					result2 = (a - b) - c - d;
					result3 = (a - b) - c * d;
					result4 = (a - b) - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a - b) * c + d;
					result2 = (a - b) * c - d;
					result3 = (a - b) * c * d;
					result4 = (a - b) * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a - b) / c + d;
					result2 = (a - b) / c - d;
					result3 = (a - b) / c * d;
					result4 = (a - b) / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a * b) + c + d;
					result2 = (a * b) + c - d;
					result3 = (a * b) + c * d;
					result4 = (a * b) + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a * b) - c + d;
					result2 = (a * b) - c - d;
					result3 = (a * b) - c * d;
					result4 = (a * b) - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a * b) * c + d;
					result2 = (a * b) * c - d;
					result3 = (a * b) * c * d;
					result4 = (a * b) * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a * b) / c + d;
					result2 = (a * b) / c - d;
					result3 = (a * b) / c * d;
					result4 = (a * b) / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a / b) + c + d;
					result2 = (a / b) + c - d;
					result3 = (a / b) + c * d;
					result4 = (a / b) + c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a / b) - c + d;
					result2 = (a / b) - c - d;
					result3 = (a / b) - c * d;
					result4 = (a / b) - c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a / b) * c + d;
					result2 = (a / b) * c - d;
					result3 = (a / b) * c * d;
					result4 = (a / b) * c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a / b) / c + d;
					result2 = (a / b) / c - d;
					result3 = (a / b) / c * d;
					result4 = (a / b) / c / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / %.0f + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / %.0f - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / %.0f * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / %.0f / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate3(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... (b ... c) ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + (b + c) + d;
					result2 = a + (b + c) - d;
					result3 = a + (b + c) * d;
					result4 = a + (b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + (b - c) + d;
					result2 = a + (b - c) - d;
					result3 = a + (b - c) * d;
					result4 = a + (b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + (b * c) + d;
					result2 = a + (b * c) - d;
					result3 = a + (b * c) * d;
					result4 = a + (b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + (b / c) + d;
					result2 = a + (b / c) - d;
					result3 = a + (b / c) * d;
					result4 = a + (b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - (b + c) + d;
					result2 = a - (b + c) - d;
					result3 = a - (b + c) * d;
					result4 = a - (b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - (b - c) + d;
					result2 = a - (b - c) - d;
					result3 = a - (b - c) * d;
					result4 = a - (b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - (b * c) + d;
					result2 = a - (b * c) - d;
					result3 = a - (b * c) * d;
					result4 = a - (b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - (b / c) + d;
					result2 = a - (b / c) - d;
					result3 = a - (b / c) * d;
					result4 = a - (b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * (b + c) + d;
					result2 = a * (b + c) - d;
					result3 = a * (b + c) * d;
					result4 = a * (b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * (b - c) + d;
					result2 = a * (b - c) - d;
					result3 = a * (b - c) * d;
					result4 = a * (b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * (b * c) + d;
					result2 = a * (b * c) - d;
					result3 = a * (b * c) * d;
					result4 = a * (b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * (b / c) + d;
					result2 = a * (b / c) - d;
					result3 = a * (b / c) * d;
					result4 = a * (b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / (b + c) + d;
					result2 = a / (b + c) - d;
					result3 = a / (b + c) * d;
					result4 = a / (b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / (b - c) + d;
					result2 = a / (b - c) - d;
					result3 = a / (b - c) * d;
					result4 = a / (b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / (b * c) + d;
					result2 = a / (b * c) - d;
					result3 = a / (b * c) * d;
					result4 = a / (b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / (b / c) + d;
					result2 = a / (b / c) - d;
					result3 = a / (b / c) * d;
					result4 = a / (b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate4(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... b ... (c ... d)
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + b + (c + d);
					result2 = a + b + (c - d);
					result3 = a + b + (c * d);
					result4 = a + b + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + b - (c + d);
					result2 = a + b - (c - d);
					result3 = a + b - (c * d);
					result4 = a + b - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + b * (c + d);
					result2 = a + b * (c - d);
					result3 = a + b * (c * d);
					result4 = a + b * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + b / (c + d);
					result2 = a + b / (c - d);
					result3 = a + b / (c * d);
					result4 = a + b / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + %.0f / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - b + (c + d);
					result2 = a - b + (c - d);
					result3 = a - b + (c * d);
					result4 = a - b + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - b - (c + d);
					result2 = a - b - (c - d);
					result3 = a - b - (c * d);
					result4 = a - b - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - b * (c + d);
					result2 = a - b * (c - d);
					result3 = a - b * (c * d);
					result4 = a - b * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - b / (c + d);
					result2 = a - b / (c - d);
					result3 = a - b / (c * d);
					result4 = a - b / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - %.0f / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * b + (c + d);
					result2 = a * b + (c - d);
					result3 = a * b + (c * d);
					result4 = a * b + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * b - (c + d);
					result2 = a * b - (c - d);
					result3 = a * b - (c * d);
					result4 = a * b - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * b * (c + d);
					result2 = a * b * (c - d);
					result3 = a * b * (c * d);
					result4 = a * b * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * b / (c + d);
					result2 = a * b / (c - d);
					result3 = a * b / (c * d);
					result4 = a * b / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * %.0f / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / b + (c + d);
					result2 = a / b + (c - d);
					result3 = a / b + (c * d);
					result4 = a / b + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / b - (c + d);
					result2 = a / b - (c - d);
					result3 = a / b - (c * d);
					result4 = a / b - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / b * (c + d);
					result2 = a / b * (c - d);
					result3 = a / b * (c * d);
					result4 = a / b * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / b / (c + d);
					result2 = a / b / (c - d);
					result3 = a / b / (c * d);
					result4 = a / b / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / %.0f / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate5(int x, int y, float a, float b, float c, float d, int *e)
// menghitung (a ... b ... c) ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a + b + c) + d;
					result2 = (a + b + c) - d;
					result3 = (a + b + c) * d;
					result4 = (a + b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a + b - c) + d;
					result2 = (a + b - c) - d;
					result3 = (a + b - c) * d;
					result4 = (a + b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a + b * c) + d;
					result2 = (a + b * c) - d;
					result3 = (a + b * c) * d;
					result4 = (a + b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a + b / c) + d;
					result2 = (a + b / c) - d;
					result3 = (a + b / c) * d;
					result4 = (a + b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a - b + c) + d;
					result2 = (a - b + c) - d;
					result3 = (a - b + c) * d;
					result4 = (a - b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a - b - c) + d;
					result2 = (a - b - c) - d;
					result3 = (a - b - c) * d;
					result4 = (a - b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a - b * c) + d;
					result2 = (a - b * c) - d;
					result3 = (a - b * c) * d;
					result4 = (a - b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a - b / c) + d;
					result2 = (a - b / c) - d;
					result3 = (a - b / c) * d;
					result4 = (a - b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a * b + c) + d;
					result2 = (a * b + c) - d;
					result3 = (a * b + c) * d;
					result4 = (a * b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a * b - c) + d;
					result2 = (a * b - c) - d;
					result3 = (a * b - c) * d;
					result4 = (a * b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a * b * c) + d;
					result2 = (a * b * c) - d;
					result3 = (a * b * c) * d;
					result4 = (a * b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a * b / c) + d;
					result2 = (a * b / c) - d;
					result3 = (a * b / c) * d;
					result4 = (a * b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a / b + c) + d;
					result2 = (a / b + c) - d;
					result3 = (a / b + c) * d;
					result4 = (a / b + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a / b - c) + d;
					result2 = (a / b - c) - d;
					result3 = (a / b - c) * d;
					result4 = (a / b - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a / b * c) + d;
					result2 = (a / b * c) - d;
					result3 = (a / b * c) * d;
					result4 = (a / b * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a / b / c) + d;
					result2 = (a / b / c) - d;
					result3 = (a / b / c) * d;
					result4 = (a / b / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate6(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... (b ... c ... d)
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + (b + c + d);
					result2 = a + (b + c - d);
					result3 = a + (b + c * d);
					result4 = a + (b + c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + (b - c + d);
					result2 = a + (b - c - d);
					result3 = a + (b - c * d);
					result4 = a + (b - c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + (b * c + d);
					result2 = a + (b * c - d);
					result3 = a + (b * c * d);
					result4 = a + (b * c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + (b / c + d);
					result2 = a + (b / c - d);
					result3 = a + (b / c * d);
					result4 = a + (b / c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - (b + c + d);
					result2 = a - (b + c - d);
					result3 = a - (b + c * d);
					result4 = a - (b + c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - (b - c + d);
					result2 = a - (b - c - d);
					result3 = a - (b - c * d);
					result4 = a - (b - c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - (b * c + d);
					result2 = a - (b * c - d);
					result3 = a - (b * c * d);
					result4 = a - (b * c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - (b / c + d);
					result2 = a - (b / c - d);
					result3 = a - (b / c * d);
					result4 = a - (b / c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * (b + c + d);
					result2 = a * (b + c - d);
					result3 = a * (b + c * d);
					result4 = a * (b + c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * (b - c + d);
					result2 = a * (b - c - d);
					result3 = a * (b - c * d);
					result4 = a * (b - c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * (b * c + d);
					result2 = a * (b * c - d);
					result3 = a * (b * c * d);
					result4 = a * (b * c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * (b / c + d);
					result2 = a * (b / c - d);
					result3 = a * (b / c * d);
					result4 = a * (b / c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / (b + c + d);
					result2 = a / (b + c - d);
					result3 = a / (b + c * d);
					result4 = a / (b + c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / (b - c + d);
					result2 = a / (b - c - d);
					result3 = a / (b - c * d);
					result4 = a / (b - c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / (b * c + d);
					result2 = a / (b * c - d);
					result3 = a / (b * c * d);
					result4 = a / (b * c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / (b / c + d);
					result2 = a / (b / c - d);
					result3 = a / (b / c * d);
					result4 = a / (b / c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / %.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate7(int x, int y, float a, float b, float c, float d, int *e)
// menghitung (a ... b) ... (c ... d)
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a + b) + (c + d);
					result2 = (a + b) + (c - d);
					result3 = (a + b) + (c * d);
					result4 = (a + b) + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a + b) - (c + d);
					result2 = (a + b) - (c - d);
					result3 = (a + b) - (c * d);
					result4 = (a + b) - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a + b) * (c + d);
					result2 = (a + b) * (c - d);
					result3 = (a + b) * (c * d);
					result4 = (a + b) * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a + b) / (c + d);
					result2 = (a + b) / (c - d);
					result3 = (a + b) / (c * d);
					result4 = (a + b) / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + %.0f) / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a - b) + (c + d);
					result2 = (a - b) + (c - d);
					result3 = (a - b) + (c * d);
					result4 = (a - b) + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a - b) - (c + d);
					result2 = (a - b) - (c - d);
					result3 = (a - b) - (c * d);
					result4 = (a - b) - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a - b) * (c + d);
					result2 = (a - b) * (c - d);
					result3 = (a - b) * (c * d);
					result4 = (a - b) * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a - b) / (c + d);
					result2 = (a - b) / (c - d);
					result3 = (a - b) / (c * d);
					result4 = (a - b) / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - %.0f) / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a * b) + (c + d);
					result2 = (a * b) + (c - d);
					result3 = (a * b) + (c * d);
					result4 = (a * b) + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a * b) - (c + d);
					result2 = (a * b) - (c - d);
					result3 = (a * b) - (c * d);
					result4 = (a * b) - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a * b) * (c + d);
					result2 = (a * b) * (c - d);
					result3 = (a * b) * (c * d);
					result4 = (a * b) * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a * b) / (c + d);
					result2 = (a * b) / (c - d);
					result3 = (a * b) / (c * d);
					result4 = (a * b) / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * %.0f) / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a / b) + (c + d);
					result2 = (a / b) + (c - d);
					result3 = (a / b) + (c * d);
					result4 = (a / b) + (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) + (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a / b) - (c + d);
					result2 = (a / b) - (c - d);
					result3 = (a / b) - (c * d);
					result4 = (a / b) - (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) - (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a / b) * (c + d);
					result2 = (a / b) * (c - d);
					result3 = (a / b) * (c * d);
					result4 = (a / b) * (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) * (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a / b) / (c + d);
					result2 = (a / b) / (c - d);
					result3 = (a / b) / (c * d);
					result4 = (a / b) / (c / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / (%.0f + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / (%.0f - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / (%.0f * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / %.0f) / (%.0f / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate8(int x, int y, float a, float b, float c, float d, int *e)
// menghitung ((a ... b) ... c) ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = ((a + b) + c) + d;
					result2 = ((a + b) + c) - d;
					result3 = ((a + b) + c) * d;
					result4 = ((a + b) + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = ((a + b) - c) + d;
					result2 = ((a + b) - c) - d;
					result3 = ((a + b) - c) * d;
					result4 = ((a + b) - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = ((a + b) * c) + d;
					result2 = ((a + b) * c) - d;
					result3 = ((a + b) * c) * d;
					result4 = ((a + b) * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = ((a + b) / c) + d;
					result2 = ((a + b) / c) - d;
					result3 = ((a + b) / c) * d;
					result4 = ((a + b) / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f + %.0f) / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = ((a - b) + c) + d;
					result2 = ((a - b) + c) - d;
					result3 = ((a - b) + c) * d;
					result4 = ((a - b) + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = ((a - b) - c) + d;
					result2 = ((a - b) - c) - d;
					result3 = ((a - b) - c) * d;
					result4 = ((a - b) - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = ((a - b) * c) + d;
					result2 = ((a - b) * c) - d;
					result3 = ((a - b) * c) * d;
					result4 = ((a - b) * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = ((a - b) / c) + d;
					result2 = ((a - b) / c) - d;
					result3 = ((a - b) / c) * d;
					result4 = ((a - b) / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f - %.0f) / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = ((a * b) + c) + d;
					result2 = ((a * b) + c) - d;
					result3 = ((a * b) + c) * d;
					result4 = ((a * b) + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = ((a * b) - c) + d;
					result2 = ((a * b) - c) - d;
					result3 = ((a * b) - c) * d;
					result4 = ((a * b) - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = ((a * b) * c) + d;
					result2 = ((a * b) * c) - d;
					result3 = ((a * b) * c) * d;
					result4 = ((a * b) * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = ((a * b) / c) + d;
					result2 = ((a * b) / c) - d;
					result3 = ((a * b) / c) * d;
					result4 = ((a * b) / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f * %.0f) / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = ((a / b) + c) + d;
					result2 = ((a / b) + c) - d;
					result3 = ((a / b) + c) * d;
					result4 = ((a / b) + c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) + %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = ((a / b) - c) + d;
					result2 = ((a / b) - c) - d;
					result3 = ((a / b) - c) * d;
					result4 = ((a / b) - c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) - %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = ((a / b) * c) + d;
					result2 = ((a / b) * c) - d;
					result3 = ((a / b) * c) * d;
					result4 = ((a / b) * c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) * %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = ((a / b) / c) + d;
					result2 = ((a / b) / c) - d;
					result3 = ((a / b) / c) * d;
					result4 = ((a / b) / c) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) / %.0f) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) / %.0f) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) / %.0f) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. ((%.0f / %.0f) / %.0f) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate9(int x, int y, float a, float b, float c, float d, int *e)
// menghitung (a ... (b ... c)) ... d
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a + (b + c)) + d;
					result2 = (a + (b + c)) - d;
					result3 = (a + (b + c)) * d;
					result4 = (a + (b + c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f + %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a + (b - c)) + d;
					result2 = (a + (b - c)) - d;
					result3 = (a + (b - c)) * d;
					result4 = (a + (b - c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f - %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a + (b * c)) + d;
					result2 = (a + (b * c)) - d;
					result3 = (a + (b * c)) * d;
					result4 = (a + (b * c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f * %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a + (b / c)) + d;
					result2 = (a + (b / c)) - d;
					result3 = (a + (b / c)) * d;
					result4 = (a + (b / c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f + (%.0f / %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a - (b + c)) + d;
					result2 = (a - (b + c)) - d;
					result3 = (a - (b + c)) * d;
					result4 = (a - (b + c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f + %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a - (b - c)) + d;
					result2 = (a - (b - c)) - d;
					result3 = (a - (b - c)) * d;
					result4 = (a - (b - c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f - %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a - (b * c)) + d;
					result2 = (a - (b * c)) - d;
					result3 = (a - (b * c)) * d;
					result4 = (a - (b * c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f * %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a - (b / c)) + d;
					result2 = (a - (b / c)) - d;
					result3 = (a - (b / c)) * d;
					result4 = (a - (b / c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f - (%.0f / %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a * (b + c)) + d;
					result2 = (a * (b + c)) - d;
					result3 = (a * (b + c)) * d;
					result4 = (a * (b + c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f + %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a * (b - c)) + d;
					result2 = (a * (b - c)) - d;
					result3 = (a * (b - c)) * d;
					result4 = (a * (b - c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f - %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a * (b * c)) + d;
					result2 = (a * (b * c)) - d;
					result3 = (a * (b * c)) * d;
					result4 = (a * (b * c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f * %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a * (b / c)) + d;
					result2 = (a * (b / c)) - d;
					result3 = (a * (b / c)) * d;
					result4 = (a * (b / c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f * (%.0f / %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = (a / (b + c)) + d;
					result2 = (a / (b + c)) - d;
					result3 = (a / (b + c)) * d;
					result4 = (a / (b + c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f + %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = (a / (b - c)) + d;
					result2 = (a / (b - c)) - d;
					result3 = (a / (b - c)) * d;
					result4 = (a / (b - c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f - %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = (a / (b * c)) + d;
					result2 = (a / (b * c)) - d;
					result3 = (a / (b * c)) * d;
					result4 = (a / (b * c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f * %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = (a / (b / c)) + d;
					result2 = (a / (b / c)) - d;
					result3 = (a / (b / c)) * d;
					result4 = (a / (b / c)) / d;
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) + %.0f\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) - %.0f\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) * %.0f\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. (%.0f / (%.0f / %.0f)) / %.0f\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate10(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... ((b ... c) ... d)
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + ((b + c) + d);
					result2 = a + ((b + c) - d);
					result3 = a + ((b + c) * d);
					result4 = a + ((b + c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f + %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f + %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f + %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f + %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + ((b - c) + d);
					result2 = a + ((b - c) - d);
					result3 = a + ((b - c) * d);
					result4 = a + ((b - c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f - %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f - %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f - %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f - %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + ((b * c) + d);
					result2 = a + ((b * c) - d);
					result3 = a + ((b * c) * d);
					result4 = a + ((b * c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f * %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f * %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f * %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f * %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + ((b / c) + d);
					result2 = a + ((b / c) - d);
					result3 = a + ((b / c) * d);
					result4 = a + ((b / c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f / %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f / %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f / %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + ((%.0f / %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - ((b + c) + d);
					result2 = a - ((b + c) - d);
					result3 = a - ((b + c) * d);
					result4 = a - ((b + c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f + %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f + %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f + %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f + %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - ((b - c) + d);
					result2 = a - ((b - c) - d);
					result3 = a - ((b - c) * d);
					result4 = a - ((b - c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f - %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f - %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f - %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f - %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - ((b * c) + d);
					result2 = a - ((b * c) - d);
					result3 = a - ((b * c) * d);
					result4 = a - ((b * c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f * %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f * %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f * %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f * %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - ((b / c) + d);
					result2 = a - ((b / c) - d);
					result3 = a - ((b / c) * d);
					result4 = a - ((b / c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f / %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f / %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f / %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - ((%.0f / %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * ((b + c) + d);
					result2 = a * ((b + c) - d);
					result3 = a * ((b + c) * d);
					result4 = a * ((b + c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f + %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f + %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f + %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f + %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * ((b - c) + d);
					result2 = a * ((b - c) - d);
					result3 = a * ((b - c) * d);
					result4 = a * ((b - c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f - %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f - %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f - %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f - %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * ((b * c) + d);
					result2 = a * ((b * c) - d);
					result3 = a * ((b * c) * d);
					result4 = a * ((b * c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f * %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f * %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f * %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f * %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * ((b / c) + d);
					result2 = a * ((b / c) - d);
					result3 = a * ((b / c) * d);
					result4 = a * ((b / c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f / %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f / %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f / %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * ((%.0f / %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / ((b + c) + d);
					result2 = a / ((b + c) - d);
					result3 = a / ((b + c) * d);
					result4 = a / ((b + c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f + %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f + %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f + %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f + %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / ((b - c) + d);
					result2 = a / ((b - c) - d);
					result3 = a / ((b - c) * d);
					result4 = a / ((b - c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f - %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f - %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f - %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f - %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / ((b * c) + d);
					result2 = a / ((b * c) - d);
					result3 = a / ((b * c) * d);
					result4 = a / ((b * c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f * %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f * %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f * %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f * %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / ((b / c) + d);
					result2 = a / ((b / c) - d);
					result3 = a / ((b / c) * d);
					result4 = a / ((b / c) / d);
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f / %.0f) + %.0f)\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f / %.0f) - %.0f)\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f / %.0f) * %.0f)\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / ((%.0f / %.0f) / %.0f)\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}

void calculate11(int x, int y, float a, float b, float c, float d, int *e)
// menghitung a ... (b ... (c ... d))
{
	//Kamus Lokal
	float result1, result2, result3, result4;

	//Algoritma
	switch (x)
	{
		case 1:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a + (b + (c + d));
					result2 = a + (b + (c - d));
					result3 = a + (b + (c * d));
					result4 = a + (b + (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f + (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a + (b - (c + d));
					result2 = a + (b - (c - d));
					result3 = a + (b - (c * d));
					result4 = a + (b - (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f - (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a + (b * (c + d));
					result2 = a + (b * (c - d));
					result3 = a + (b * (c * d));
					result4 = a + (b * (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f * (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a + (b / (c + d));
					result2 = a + (b / (c - d));
					result3 = a + (b / (c * d));
					result4 = a + (b / (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f + (%.0f / (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 2:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a - (b + (c + d));
					result2 = a - (b + (c - d));
					result3 = a - (b + (c * d));
					result4 = a - (b + (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f + (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a - (b - (c + d));
					result2 = a - (b - (c - d));
					result3 = a - (b - (c * d));
					result4 = a - (b - (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f - (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a - (b * (c + d));
					result2 = a - (b * (c - d));
					result3 = a - (b * (c * d));
					result4 = a - (b * (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f * (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a - (b / (c + d));
					result2 = a - (b / (c - d));
					result3 = a - (b / (c * d));
					result4 = a - (b / (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f - (%.0f / (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 3:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a * (b + (c + d));
					result2 = a * (b + (c - d));
					result3 = a * (b + (c * d));
					result4 = a * (b + (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f + (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a * (b - (c + d));
					result2 = a * (b - (c - d));
					result3 = a * (b - (c * d));
					result4 = a * (b - (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f - (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a * (b * (c + d));
					result2 = a * (b * (c - d));
					result3 = a * (b * (c * d));
					result4 = a * (b * (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f * (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a * (b / (c + d));
					result2 = a * (b / (c - d));
					result3 = a * (b / (c * d));
					result4 = a * (b / (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f * (%.0f / (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			switch (y)
			{
				case 1:
				{
					result1 = a / (b + (c + d));
					result2 = a / (b + (c - d));
					result3 = a / (b + (c * d));
					result4 = a / (b + (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f + (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 2:
				{
					result1 = a / (b - (c + d));
					result2 = a / (b - (c - d));
					result3 = a / (b - (c * d));
					result4 = a / (b - (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f - (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 3:
				{
					result1 = a / (b * (c + d));
					result2 = a / (b * (c - d));
					result3 = a / (b * (c * d));
					result4 = a / (b * (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f * (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
				case 4:
				{
					result1 = a / (b / (c + d));
					result2 = a / (b / (c - d));
					result3 = a / (b / (c * d));
					result4 = a / (b / (c / d));
					if (((result1 - 24) >= -0.00001) && ((result1 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / (%.0f + %.0f))\n", (*e), a, b, c, d);
					}
					if (((result2 - 24) >= -0.00001) && ((result2 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / (%.0f - %.0f))\n", (*e), a, b, c, d);
					}
					if (((result3 - 24) >= -0.00001) && ((result3 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / (%.0f * %.0f))\n", (*e), a, b, c, d);
					}
					if (((result4 - 24) >= -0.00001) && ((result4 - 24) <= 0.00001))
					{
						(*e)++;
						printf("%7d. %.0f / (%.0f / (%.0f / %.0f))\n", (*e), a, b, c, d);
					}
					break;
				}
			}
			break;
		}
	}
}
