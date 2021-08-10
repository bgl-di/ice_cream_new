#include <map>
#include <set>
#include <iostream>
using namespace std;

const set <short, greater <short>> coins_nominal {1, 2, 5, 10};
map <short, short> moneybox;
map <short, short> coins_to_give;
const short price = 5;

short money_to_change (short money)
{
	short x;
	x = money - price;
	return x;
};

void money_to_coins(short money)
{
	int k;
	for (const int &i : coins_nominal)
	{
		k = money / i;
		moneybox[i] += k;
		money -= k* i;
	}
};

void change_to_coins(short change)
{
	short k;

	for (const int &i : coins_nominal)
	{
		k = change / i;
		change -= min(moneybox[i],k) * i;
		cout << i <<"-рублевых: " << min(moneybox[i],k) <<endl;
		moneybox[i] -= min(moneybox[i],k);
	}
};

void empty_moneybox()
{
	for (const int &i : coins_nominal)
	{
		moneybox[i] = 0;
	}
};

short getvalue()
{
	while (true)
	{
		short money;
		cin >> money;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			cin.ignore(32767, '\n');
			return money;
		}
	}
};


int main() {
	short money = getvalue();
	short change;
	empty_moneybox();

	for (int i = 0; i <= 1000; i++)
	{
		money_to_coins(money);
		if (money < 5 || money < 0)
		{
			cout << "недостаточно денег"<<endl;
			continue;
		}

		change = money_to_change(money);
		cout <<"вы получите: "<< change << endl;
		change_to_coins (change);
	}
	return 0;
}
