#include <iostream>
#include <ctime>
#include <iomanip>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include <clocale>
using namespace std;

	
	// Заполнение матрицы уникальными числами

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	const int m = 5;
	const int n = 5;
	int arr[m][n];

  for (int i= 0;i < m; i++)
  {
	for (int j = 0;j < n;)
	{ 
		bool aTh = false;
		int newVal = rand()%26;
    	for (int k = 0; k < m; k++)
    	{
    		for (int l = 0; l < n; l++)
    		{
    			if (newVal == arr[k][l])
    			{
    				aTh = true;
    				break;
    			}
    		}
    		if (aTh)
    		break;
    	}
    	if (!aTh)
    	{
    		arr[i][j] = newVal;
    		j++;
    	}
	}
  }

 // Вывод на экран
	
  cout << endl << "     Матрица  " << endl << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << arr[i][j] << "  ";
		}
		cout << "\n\n";
	}
	  cout << "\n\n";
	  int b = 0;
 	  int sortArr;
	   cout << "      Введите метод сортировки :  1. Bubble  2. Insert  3. Choice" << endl << endl;
	cin >> sortArr;
	switch (sortArr) 
	{
	
	  case 1:
		  // Сортировка пузырьком

		int tmp;
		
		for (int k = 0; ; )
		{
			if (m * n - b == 1)
			{
				break;
			}
			for (int l = 0; l < m * n - 1; l++)
			{
				if (arr[k][l] > arr[k][l + 1])
				{
					tmp = arr[k][l + 1];
					arr[k][l + 1] = arr[k][l];
					arr[k][l] = tmp;
				}
			}
			b++;
		}
		break;

		

	 case 2:
		 // Сортировка вставками

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; )
			{
				int a = 0;
				int first = arr[i][j + 1];
				while (arr[i][j] >= 0 && arr[i][j] > arr[i][j + 1])
				{
					arr[i][j + 1] = arr[i][j];
					arr[i][j] = first;
					j--;
					a++;
				}
				j = ++j + a;
				if (i == m - 1 && j == n - 1)
				{
					++j;
				}
			}
		}
		break;

		
	 case 3:
		 // Сортировка матрицы выбором
		tmp = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bool fl = false;
				int min_ind = arr[i][j];
				if (min_ind > arr[i][j])
				{
					min_ind = arr[i][j];
					fl = true;
				}
				if (fl == true)
				{
					tmp = arr[i][j];
					arr[i][j] = arr[i][min_ind];
					arr[i][min_ind] = tmp;
				}
			}
		}
		break;
	}

	cout << "Вот что получилось" << endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(3) << arr[i][j] << "  ";
			}
			cout << "\n\n";
		}


	
		_getch();
	return 0;
}
