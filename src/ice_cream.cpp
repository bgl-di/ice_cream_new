#include <map>
#include <set>
#include <iostream>

using namespace std;

const set<short, greater<short>> coins_nominal{ 5, 10, 15 };
map<short, short> moneybox;
const short price = 5;

void money_to_coins(short money) {
	int number_of_coins;
	for (const int &i : coins_nominal) {
		number_of_coins = money / i;
		moneybox[i] += number_of_coins;
		money -= number_of_coins * i;
	}
}

void change_to_coins(short change) {
	short number_of_coins = 0;
	short y = change;

	for (const int &i : coins_nominal) {
		if (y >= i) {
			number_of_coins = change / i;
			y -= (min(moneybox[i], number_of_coins) * i);
		} else
			continue;
	}

	if (y > 0) {
		short money = change + price;
		cout << "Not enough coins in the machine: " << money << endl;
		for (const int &i : coins_nominal) {
			number_of_coins = money / i;
			money -= min(moneybox[i], number_of_coins) * i;
			moneybox[i] -= min(moneybox[i], number_of_coins);
		}
		return;
	}

	cout << "You will get an ice cream and " << change << " dollars change"
			<< endl;
	for (const int &i : coins_nominal) {
		number_of_coins = change / i;
		change -= min(moneybox[i], number_of_coins) * i;
		cout << i << "-dollar: " << min(moneybox[i], number_of_coins) << endl;
		moneybox[i] -= min(moneybox[i], number_of_coins);
	}
}


void moneybox_initialization() {
	for (const int &i : coins_nominal) {
		moneybox[i] = 0;
	}
}


short getvalue() {
	short money;
	while (!(cin >> money) || (cin.peek() != '\n') || (money < 5 && money != 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Input error!" << endl;
	}
	return money;
}


int main() {
	short change;
	short money;
	moneybox_initialization();

	while (true) {
		cout << "Enter the amount of money, to exit enter zero:" << endl;
		money = getvalue();
		if (money == 0)
			return 0;
		money_to_coins(money);

		change = money - price;
		change_to_coins(change);
		for (const int &i : coins_nominal) {
			cout << i << " - " << moneybox[i] << endl;
		}
	}
	return 0;
}
