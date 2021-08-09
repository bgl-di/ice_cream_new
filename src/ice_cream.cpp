#include <map>
#include <set>
#include <iostream>
using namespace std;

const set <short, greater <short>> coins_nominal {1, 2, 5, 10};
set <short> :: iterator it = coins_nominal.begin();
map <short, short> moneybox;
map <short, short> coins_to_give;
const short price = 5;

short money_to_change (short money)
{
	short x;
	x = money - price;
	return x;
};

void change_to_coins(short change)
{
	it = coins_nominal.begin();
	short k;

	for (int i = 0; it != coins_nominal.end(); it++, i++)
	{
		k = change / *it;
		coins_to_give[*it] = k;
		change -= k* *it;
	}
};


void money_to_coins(short money)
{
	it = coins_nominal.begin();
	int k;

	for (short i = 0; it != coins_nominal.end(); it++, i++)
	{
		k = money / *it;
		moneybox[*it] = k;
		money -= k* *it;
	}
};


void empty_moneybox()
{
	it = coins_nominal.begin();
	for (int i = 0; it != coins_nominal.end(); it++, i++)
	{
		moneybox[*it] = 0;
	}
};

int main() {
	short money;
	short change;
	empty_moneybox();

	for (int i = 0; i <= 1000; i++)
	{
		cin >> money;
		money_to_coins(money);

		change = money_to_change(money);
		change_to_coins (change);

		cout <<"вы получите: "<< change << endl;

		for (const int &i : coins_nominal) {
			cout << i << "-рублевых: " << coins_to_give[i] << endl;
		}
	}
	return 0;
}
