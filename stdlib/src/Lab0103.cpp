#include "bel.hpp"

карыстаць вобласць std;

вобласць беларусь
{
	клас лаб0103
	{
	публіч:
		стат пуст запуск()
		{
			цэл н;
			вывад << "Enter the quantity of elements: ";
			ўвод >> н;

			вектар<цэл> мас(н, 0);
			для(цэл і = 0; і < н; і++)
			{
				вывад << "Enter the element: ";
				ўвод >> мас[і];
			}

			мноства<цэл> лічбы;
			для(цэл i = 0; i < н; i++)
			{
				лічбы.insert(мас[i]);
			}

			вывад << "Unique elements:";
			для(цэл i : лічбы)
			{
				вывад << " " << i;
			}
			вывад << абзац;

			вывад << "The quantity of unique elements: " << лічбы.size() << абзац;

			цэл макс = 0;

			для(цэл і = 0; і < н; і++)
			{
				для(цэл ж = 0; ж < н; ж++)
				{
					калі (мас[і] == мас[ж] && і != ж)
					{
						макс = мас[і];
						злом;
					}
				}
			}

			для(цэл і = 0; і < н; і++)
			{
				для(цэл ж = 0; ж < н; ж++)
				{
					калі (мас[і] == мас[ж] && і != ж && макс < мас[і])
					{
						макс = мас[і];
					}
				}
			}

			вывад << "Max duplicate: " << макс << абзац;
		}
	};
}
