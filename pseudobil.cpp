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
		int x = lungimeDiagonala - 1;
		int rezultat = (x*x + 1)/2;
		scrie << rezultat;
		scrie.close();
	}
	else
	{
		int existaBila[nrLinii + 1][nrLinii + 1];
		memset(existaBila,
		       0,
		       sizeof(existaBila));
		int i;
		for (i = 0; i < nrBile; i++)
		{
			int linie, coloana;
			citeste >> linie >> coloana;
			existaBila[linie][coloana] = 1;
		}
		int nrIntrebari;
		citeste >> nrIntrebari;
		for (i = 0; i < nrIntrebari; i++)
		{
			int linie, coloana;
			citeste >> linie >> coloana;
			int primaLinie = linie;
			int ultimaLinie = primaLinie
				          + lungimeDiagonala;
			int primaColoana[lungimeDiagonala + 1],
			    ultimaColoana[lungimeDiagonala + 1];
			memset(primaColoana,
			       -1,
			       sizeof(primaColoana));
			memset(ultimaColoana,
			       -1,
			       sizeof(ultimaColoana));
			primaColoana[primaLinie] = coloana;
			ultimaColoana[primaLinie] = coloana;
			int j = primaLinie + 1,
			    liniaDeMijloc = (primaLinie
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
				for (int k = primaColoana[j];
				     k <= ultimaColoana[j]; k++)
				{
					if (existaBila[j][k])
					{
						nrBileInCadru++;
					}
				}
			}
			scrie << nrBileInCadru << endl;
		}
		citeste.close();
		scrie.close();
	}
	return 0;
}

