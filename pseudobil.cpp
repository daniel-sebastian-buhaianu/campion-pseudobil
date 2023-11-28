#include <fstream>
#define MAX_N 1502
#define MAX_DIM 2*MAX_N-1
using namespace std;
bool existaBila[MAX_DIM][MAX_DIM];
int sumaPartiala[MAX_DIM][MAX_DIM];
int main()
{
	ifstream citeste("pseudobil.in");
	ofstream scrie("pseudobil.out");
	int cerinta,
	    valoareN,
	    nrBile,
	    lungimeDiagonala;
	citeste >> cerinta
	        >> valoareN
		>> nrBile
		>> lungimeDiagonala;
	if (cerinta == 1)
	{
		citeste.close();
		int x = lungimeDiagonala-1;
		int rezultat = (x*x + 1)/2;
		scrie << rezultat;
		scrie.close();
	}
	else
	{
		int nrLinii = 2*valoareN - 1;
		int i, linie, coloana, lin, col;
		for (i = 0; i < nrBile; i++)
		{
			citeste >> linie >> coloana;	
			// lin = linia in matricea rotita
			lin = linie + coloana - 1;
			// col = coloana in matricea rotita
			col = valoareN - linie + coloana;
			existaBila[lin][col] = 1;
		}
		for (i = 1; i <= nrLinii; i++)
		{
			for (int j = 1; j <= nrLinii; j++)
			{
				sumaPartiala[i][j]
					= sumaPartiala[i-1][j]
					  + sumaPartiala[i][j-1]
					  - sumaPartiala[i-1][j-1]
					  + existaBila[i][j];
			}
		}
		int nrIntrebari;
		citeste >> nrIntrebari;
		for (i = 0; i < nrIntrebari; i++)
		{
			citeste >> linie >> coloana;
			// calculez liniile si coloanele
			// in matricea rotita a patratului
			// (romb rotit = patrat)
			int linieSus = linie + coloana - 1,
			    linieJos = linieSus
			               + lungimeDiagonala,
			    coloanaDreapta = valoareN
					     - linie
					     + coloana,
			    coloanaStanga = coloanaDreapta
			                    - lungimeDiagonala;
		        int nrBileDinPatrat
		        = sumaPartiala[linieJos][coloanaDreapta]
		        - sumaPartiala[linieSus-1][coloanaDreapta]
		        - sumaPartiala[linieJos][coloanaStanga-1]
		        + sumaPartiala[linieSus-1][coloanaStanga-1];
			scrie << nrBileDinPatrat << endl;
		}
		citeste.close();
		scrie.close();
	}
	return 0;
}
