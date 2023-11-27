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
		int i, j, linie, coloana;
		citeste >> linie >> coloana;
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
			int primaLinie = linie;
			int ultimaLinie = primaLinie
				          + lungimeDiagonala;
			int primaColoana[lungimeDiagonala+1],
			    ultimaColoana[lungimeDiagonala+1];
			memset(primaColoana,
			       -1,
			       sizeof(primaColoana));
			memset(ultimaColoana,
			       -1,
			       sizeof(ultimaColoana));
			primaColoana[primaLinie] = coloana;
			ultimaColoana[primaLinie] = coloana;
			j = primaLinie+1;
			int liniaDeMijloc = (primaLinie
			                    + ultimaLinie)/2;
			while (j <= liniaDeMijloc)
			{
				primaColoana[j] = primaColoana[j-1]
				                  - 1;
				ultimaColoana[j] = ultimaColoana[j-1]
						   + 1;
				j++;
			}
			while (j <= ultimaLinie)
			{
				primaColoana[j] = primaColoana[j-1]
				                  + 1;
				ultimaColoana[j] = ultimaColoana[j-1]
				                   - 1;
				j++;
			}
			int nrBileInCadru = 0;
			for (j = primaLinie; j <= ultimaLinie; j++)
			{
				nrBileInCadru
					+= sumaBile[j][ultimaColoana[j]]
					   - sumaBile[j][primaColoana[j]-1];
			}
			scrie << nrBileInCadru << endl;
		}
		citeste.close();
		scrie.close();
	}
	return 0;
}

