#include <map>
#include <set>
#include <iostream>

using namespace std;

const set<short, greater<short>> coins_nominal{ 5, 10, 15 };
map<short, short> moneybox;
const short price = 5;

short money_to_change(short money) {
	short x;
	x = money - price;
	return x;
}


void money_to_coins(short money) {
	int k;
	for (const int &i : coins_nominal) {
		k = money / i;
		moneybox[i] += k;
		money -= k * i;
	}
}


void change_to_coins(short change) {
	short k = 0;
	short y = change;

	for (const int &i : coins_nominal) {
		if (y >= i) {
			k = change / i;
			y -= (min(moneybox[i], k) * i);
		} else
			continue;
	}

	if (y > 0) {
		short mon = change + price;
		cout << "Ќедостаточно денег в автомате, вы получите: " << mon << endl;
		for (const int &i : coins_nominal) {
			k = mon / i;
			mon -= min(moneybox[i], k) * i;
			moneybox[i] -= min(moneybox[i], k);
		}
		return;
	}

	cout << "¬ы получите мороженое и сдачу в размере: " << change << " рублей"
			<< endl;
	for (const int &i : coins_nominal) {
		k = change / i;
		change -= min(moneybox[i], k) * i;
		cout << i << "-рублевых: " << min(moneybox[i], k) << endl;
		moneybox[i] -= min(moneybox[i], k);
	}
}


void empty_moneybox() {
	for (const int &i : coins_nominal) {
		moneybox[i] = 0;
	}
}


short getvalue() {
	short money;
	while (!(cin >> money) || (cin.peek() != '\n') || money < 5) {
		cin.clear();
		while (cin.get() != '\n')
			;
		cout << "Input error!" << endl;
	}
	return money;
}


int main() {
	short change;
	short money;
	empty_moneybox();

	for (int i = 0; i <= 1000; i++) {
		money = getvalue();
		money_to_coins(money);

		change = money_to_change(money);
		change_to_coins(change);
		for (const int &i : coins_nominal) {
			cout << i << " - " << moneybox[i] << endl;
		}
	}
	return 0;
}
