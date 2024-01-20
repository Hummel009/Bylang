#include <cmath>

#include "bel.hpp"

карыстаць вобласць std;

вобласць беларусь
{
	клас лаб0105
	{
	публіч:
		стат пуст выканаць(дроб8 мяжа)
		{
			дроб8 х = 0.1;
			пакуль(х < 1.0)
			{
				цэл к = 1;
				дроб8 ф = 0;
				дроб8 эпс = 1.0;
				пакуль(эпс > мяжа)
				{
					дроб8 час = ф;
					ф += pow(х, 3 * к + 1) / ((4 * к - 1) * (4 * к - 2));
					к += 1;
					эпс = abs(ф - час);
				}
				вывад << "X = " << х << "; K = " << к << "; F =" << ф << абзац;
				х += 0.1;
			}
		}

		стат пуст запуск()
		{
			выканаць(1.0e-5);
			printf("\n");
			выканаць(1.0e-6);
		}
	};
}
