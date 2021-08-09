#include <map>
#include <set>
#include <iostream>
using namespace std;

const set <int, greater <int>> coins_nominal {5, 10};
map <int, int> coins_to_give;
const int price = 5;

int money_to_change (int money)
{
	int x;
	x = money - price;
	return x;
};

void change_in_coins(int change)
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

void empty_moneybox()
{
	set <int> :: iterator it = coins_nominal.begin();
	for (int i = 0; it != coins_nominal.end(); it++, i++)
	{
		coins_to_give[*it] = 0;
	}
};

int main() {
	int money;
	int change;
	empty_moneybox();

	for (int i = 0; i <= 1000; i++)
	{
		cin >> money;
		if (money >= 5)
		{
			change = money_to_change(money);
			change_in_coins (change);
			cout <<"вы получите: "<< change << endl;
			cout << "пятирублевых: " << coins_to_give[5] << endl;
			cout << "десятирублевых: " << coins_to_give[10] << endl;
		}
		else cout << "error";
	}
	return 0;
}
