#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<int> tiles;
	while (true) {
		int tile;
		cin >> tile;
		tiles.push_back(tile);

		if (tile == 0)
			break;
	}
	vector<int> diff(tiles.size() - 2);

	for (int i = 0; i < tiles.size() - 2; i++)
		diff.at(i) = tiles.at(i) - tiles.at(i + 1);
	
	int max = tiles.at(0);

	vector<int> modifiedTiles(max, 1);
	int diff_size = diff.size();

	for (int i = 0; i < diff_size; i++) {
		for (int j = 0; j < max - diff.at(i); j++)
			modifiedTiles.at(j)++;
		max -= diff.at(i);
	}

	modifiedTiles.push_back(0);
	for (auto t : modifiedTiles)
		cout << t << " ";
	return 0;
}