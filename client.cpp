#include "client.h"
#include "film.h"
#include <iostream>
#include<stdio.h>
using namespace std;

Client::Client() {};

Film Client::add(Film film) {

	watchlist.push_back({ film, false });
	return film;
}

void Client::remove(Film film) {

	int p = -1;
	vector<Film> list = liste.getlist();

	for (int i = 0; i < list.size(); i++) {
		if (list[i].get_titel() == film.get_titel())
			p = i;
	}

	if (-1 < p) {
		watchlist.erase(watchlist.begin() + p);
	}

}

Repository Client::opinion(Film film, int i) {
	Film x(film.get_titel(), film.get_genre(), film.get_jahr(), film.get_likes() + 1, film.get_trailer());
	liste.update(film, x);
	return liste;
}

Client::~Client() {};