#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Par {
	int inicio;
	int fin;
};

int activitySelectionProblem(vector<Par> &actividades)
{
    //aca me ordena la cadena por si acaso la pongo desordenada 
	sort(actividades.begin(), actividades.end(),
		[](Par &x, Par &y) {
			return x.inicio < y.inicio;
		});

	vector<int> L(actividades.size());

    //aca ya recorre todo y ve que actividades se pueden realizar
	for (int i = 0; i < actividades.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (actividades[j].fin < actividades[i].inicio && L[i] < L[j])
			{
				L[i] = L[j];
			}
		}

		L[i]++;
	}

    //retornamos las actividades maximas que se pueden realizar
	return *max_element(L.begin(), L.end());
}

int main()
{
    //cada par ordenado representa: (inicio, fin)
	vector<Par> actividades = {{0, 6}, {1, 4}, {2, 13}, {3, 5}, {3, 8}, {5, 7},{5, 9}, {6, 10}, {8, 11}, {8, 12}, {12, 14}};

	cout << "Actividades que se pueden realizar: " << activitySelectionProblem(actividades);

	return 0;
}

