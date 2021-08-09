#include <map>
#include <set>
#include <iostream>
using namespace std;

const set <int, greater <int>> coins_nominal {1, 2, 5, 10};
set <int> :: iterator it = coins_nominal.begin();
map <int, int> moneybox;
map <int, int> coins_to_give;
const int price = 5;

int money_to_change (int money)
{
	int x;
	x = money - price;
	return x;
};

void change_to_coins(int change)
{
	set <int> :: iterator it = coins_nominal.begin();
	int k;

	for (int i = 0; it != coins_nominal.end(); it++, i++)
	{
		k = change / *it;
		coins_to_give[*it] = k;
		change -= k* *it;
	}
};


void money_to_coins(int change)
{
	set <int> :: iterator it = coins_nominal.begin();
	int k;

	for (int i = 0; it != coins_nominal.end(); it++, i++)
	{
		k = change / *it;
		moneybox[*it] = k;
		change -= k* *it;
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
	int money;
	int change;
	empty_moneybox();

	for (int i = 0; i <= 1000; i++)
	{
		cin >> money;
		money_to_coins(money);

		change = money_to_change(money);
		change_to_coins (change);
		cout <<"вы получите: "<< change << endl;
		it = coins_nominal.begin();

		for (int i = 0; it != coins_nominal.end(); it++, i++)
		{
			cout << *it << "-рублевых: " << coins_to_give[*it] << endl;
		};
	}
	return 0;
}
