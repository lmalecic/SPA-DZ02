#include "game_of_life.h"
#include <iostream>

bool game_of_life::slucajna_vrijednost()
{
	return rand() % (100) <= 25;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i > REDAKA || j > STUPACA || i < 0 || j < 0) { return 0; }
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
			_sljedeca_generacija[i][j] = 0;
		}
	}
}

int game_of_life::brojSusjeda(int i, int j)
{
	int broj = 0;

	if (celija_zauzeta(i - 1, j - 1))
	{
		broj++;
	}
	
	if (celija_zauzeta(i - 1, j))
	{
		broj++;
	}

	if (celija_zauzeta(i - 1, j + 1))
	{
		broj++;
	}

	if (celija_zauzeta(i, j - 1))
	{
		broj++;
	}

	if (celija_zauzeta(i, j + 1))
	{
		broj++;
	}

	if (celija_zauzeta(i + 1, j - 1))
	{
		broj++;
	}

	if (celija_zauzeta(i + 1, j))
	{
		broj++;
	}

	if (celija_zauzeta(i + 1, j + 1))
	{
		broj++;
	}

	return broj;
}

/*

1. Zivi organizam u celiji prezivljava u sljedecoj generaciji ukoliko je broj njegovih susjeda dva ili
tri.
2. Zivi organizam u celiji umire u sljedecoj generaciji ukoliko je broj njegovih susjeda manji od dva
(zbog usamljenosti) ili veci od tri (zbog prenaseljenosti).
3. U praznoj celiji se radja novi organizam ukoliko se u tocno tri njene susjedne celije nalaze zivi
organizmi

*/

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int brSusjeda = brojSusjeda(i, j);

			if (celija_zauzeta(i, j))
			{
				_sljedeca_generacija[i][j] = brSusjeda == 2 || brSusjeda == 3;
			}
			else
			{
				_sljedeca_generacija[i][j] = brSusjeda == 3;
			}
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (celija_zauzeta(i, j))
			{
				cout << '*';
			}
			else {
				cout << '_';
			}
		}

		cout << endl;
	}
}