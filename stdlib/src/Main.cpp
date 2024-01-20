#include <functional>

#include "Lab0101.cpp"
#include "Lab0102.cpp"
#include "Lab0103.cpp"
#include "Lab0105.cpp"
#include "Lab0106.cpp"
#include "Lab0108.cpp"
#include "Lab0201.cpp"
#include "Lab0208.cpp"
#include "Lab0212.cpp"

карыстаць вобласць std;
карыстаць вобласць беларусь;

цэл уваход()
{
	карта<страка, функцыя<пуст()>> функцыі;
	функцыі["0101"] = лаб0101::запуск;
	функцыі["0102"] = лаб0102::запуск;
	функцыі["0103"] = лаб0103::запуск;
	функцыі["0105"] = лаб0105::запуск;
	функцыі["0106"] = лаб0106::запуск;
	функцыі["0108"] = лаб0108::запуск;
	функцыі["0201"] = лаб0201::запуск;
	функцыі["0208"] = лаб0208::запуск;
	функцыі["0212"] = лаб0212::запуск;

	пакуль(праўда)
	{
		страка каманда;
		вывад << "Enter the number of the lab: ";
		ўвод >> каманда;

		калі(каманда == "exit")
		{
			пераход выхад;
		}

		калі(функцыі.find(каманда) != функцыі.end())
		{
			функцыі[каманда]();
			ўвод.clear();
		}
		інакш
		{
			вывад << "Unknown number!" << абзац;
		}
	}

выхад:
	вярнуць 0;
}
