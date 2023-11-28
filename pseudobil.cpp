#include <fstream>
#include <cstring>
using namespace std;
int main()
{
	ifstream citeste("pseudobil.in");
	ofstream scrie("pseudobil.out");
	int cerinta,
	    nrLinii,
	    nrBile,
	    lungimeDiagonala;
	citeste >> cerinta
	        >> nrLinii
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
		int sumaBile[nrLinii+1][nrLinii+1];
		memset(sumaBile,
		       0,
		       sizeof(sumaBile));
		int linie, coloana;
		citeste >> linie >> coloana;
		int i, j;
		for (i = coloana; i <= nrLinii; i++)
		{
			sumaBile[linie][i] = 1;
		}
		for (i = 1; i < nrBile; i++)
		{
			citeste >> linie >> coloana;
			sumaBile[linie][coloana]
				= sumaBile[linie][coloana-1]
				  + 1;
			for (j = coloana+1; j <= nrLinii; j++)
			{
				sumaBile[linie][j] += 1;
			}
		}
		int nrIntrebari;
		citeste >> nrIntrebari;
		for (i = 0; i < nrIntrebari; i++)
		{
			citeste >> linie >> coloana;
			int primaLinie = linie,
			    ultimaLinie = primaLinie
			                  + lungimeDiagonala,
			    liniaDeMijloc = (primaLinie
			                     + ultimaLinie)/2,
			    primaColoana = coloana,
			    ultimaColoana = coloana,
			    nrBileInCadru = 0;
			for (j = primaLinie; j <= ultimaLinie; j++)
			{
				nrBileInCadru +=
					sumaBile[j][ultimaColoana]
					- sumaBile[j][primaColoana-1];
				if (j < liniaDeMijloc)
				{
					primaColoana -= 1;
					ultimaColoana += 1;
				}
				else
				{
					primaColoana += 1;
					ultimaColoana -= 1;
				}
			}
			scrie << nrBileInCadru << endl;
		}
		citeste.close();
		scrie.close();
	}
	return 0;
}

