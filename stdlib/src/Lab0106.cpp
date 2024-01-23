#include "bel.hpp"

карыстаць вобласць std;

вобласць беларусь
{
	клас лаб0106
	{
	публіч:
		пералік клас Месяц{СТУ, ЛЮТ, САК, КРА, ТРА, ЧЭР, ЛІП, ЖНІ, ВЕР, КАС, ЛІС, СНЕ};

		пералік клас ДзеньНядзелі{НЯД, ПАН, АЎТ, СЕР, ЧАЦ, ПЯТ, СУБ};

		стат пуст запуск()
		{
			цэл год;
			Месяц месяц;
			цэл дата;
			логіка высакосны;

			карта<Месяц, цэл> днёўПасляНГ = {
				{Месяц::СТУ, 0},
				{Месяц::ЛЮТ, 31},
				{Месяц::САК, 59},
				{Месяц::КРА, 90},
				{Месяц::ТРА, 120},
				{Месяц::ЧЭР, 151},
				{Месяц::ЛІП, 181},
				{Месяц::ЖНІ, 212},
				{Месяц::ВЕР, 243},
				{Месяц::КАС, 273},
				{Месяц::ЛІС, 304},
				{Месяц::СНЕ, 334}};
			карта<Месяц, цэл> днёўУМесяцы = {
				{Месяц::СТУ, 31},
				{Месяц::ЛЮТ, 28},
				{Месяц::САК, 31},
				{Месяц::КРА, 30},
				{Месяц::ТРА, 31},
				{Месяц::ЧЭР, 30},
				{Месяц::ЛІП, 31},
				{Месяц::ЖНІ, 31},
				{Месяц::ВЕР, 30},
				{Месяц::КАС, 31},
				{Месяц::ЛІС, 30},
				{Месяц::СНЕ, 31}};
			вывад << "Enter the date in three steps like, 2002 07 10." << абзац;
			пакуль(праўда)
			{
				спроба
				{
					вывад << "Enter the year: ";
					ўвод >> год;
					калі(год < 1)
					{
						ёсць праблема();
					}

					вывад << "Enter the month number: ";
					цэл нумарМесяца;
					ўвод >> нумарМесяца;
					калі(нумарМесяца < 1 || нумарМесяца > 12)
					{
						ёсць праблема();
					}

					месяц = стат_прывядз<Месяц>(нумарМесяца - 1);
					высакосны = год % 4 == 0 && год % 100 != 0 && год % 400 == 0;
					цэл максДнёўУМесяцы = (месяц == Месяц::ЛЮТ && высакосны) ? 29 : днёўУМесяцы[месяц];

					вывад << "Enter the day: ";
					ўвод >> дата;
					калі (дата < 1 || дата > максДнёўУМесяцы)
					{
						ёсць праблема();
					}
					злом;
				}
				няўдача(праблема & п)
				{
					вывад << "Error! Enter the correct values!" << абзац;
				}
			}

			вывад << дата << " " << стат_прывядз<цэл>(месяц) + 1 << " " << год << абзац;
			аўта рэзультат = дата + днёўПасляНГ[месяц] + (год - 1) * 365;
			аўта дапаўненне = (год - 1) / 4 - (год - 1) / 100 + (год - 1) / 400;
			калі (высакосны && (днёўПасляНГ[месяц]) + дата > 59)
			{
				дапаўненне += 1;
			}
			рэзультат += дапаўненне;
			аўта дзень = рэзультат % 7;
			аўта дзеньНядзелі = стат_прывядз<ДзеньНядзелі>(дзень);
			аўта дзеньНядзеліЦэл = стат_прывядз<цэл>(дзеньНядзелі);
			вывад << дзеньНядзеліЦэл << абзац;
		}
	};
}
