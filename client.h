#pragma once
#include<vector>
#include "film.h"
#include "admin.h"

using namespace std;

class Client
{
private:
	Repository liste;
	struct Item {
		Film film;
		bool seen;
	};
	vector<Item> watchlist;

public:

	Client();
	~Client();

	void ansehen(Film film, string genre);
	Film add(Film film);
	void remove(Film film);
	Repository opinion(Film film, int i);

};
