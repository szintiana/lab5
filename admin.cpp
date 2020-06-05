#include "admin.h"

Repository::Repository() {
};

vector<Film> Repository::getlist() {
	return liste;
};

vector<Film> Repository::add(Film new_film) {
	bool exists = true;
	for (int i = 0; i < liste.size(); i++) {
		if (liste[i].get_titel() == new_film.get_titel())
			exists = false;
	}
	if (exists)
		liste.push_back(new_film);

	return liste;
}

Film Repository::update(Film old_film, Film new_film) {
	int p = -1;
	for (int i = 0; i < liste.size(); i++) {
		if (liste[i].get_titel() == old_film.get_titel()) {
			p = i;
		}
	}
	if (p < 0) {
		return Film("", "", 0, 0, "");
	}
	else {
		liste[p] = new_film;
		return liste[p];
	}

};

vector<Film> Repository::remove(Film film) {
	int p = -1;

	for (int i = 0; i < liste.size(); i++) {
		if (liste[i].get_titel() == film.get_titel()) {
			p = i;
		}
	}

	if (p > -1)
		liste.erase(liste.begin() + p);

	return liste;
}

vector<Film> Repository::show_genre(string genre)
{
	if (genre == "\0")
		return liste;

	vector<Film> newlist;

	for (int i = 0; i < liste.size(); i++)
	{
		if (genre == liste[i].get_genre())
			newlist.push_back(liste[i]);
	}
	return newlist;
}

vector<Film> Repository::add_to_watchlist(Film film)
{
	client_watchlist.push_back(film);
	return client_watchlist;
}

vector<Film> Repository::remove_from_watchlist(string title, int year)
{
	if (title != "invalid title" && year != 9999)
	{
		for (int i = 0; i < client_watchlist.size(); i++)
		{
			if (title == client_watchlist[i].get_titel() && year == client_watchlist[i].get_jahr())
			{
				last_removed = client_watchlist[i];
				client_watchlist.erase(client_watchlist.begin() + i);
				return client_watchlist;
			}
		}
	}

	return client_watchlist;
}

vector<Film> Repository::rating(string opinion)
{
	for (int i = 0; i < liste.size(); i++)
	{
		if (liste[i].get_titel() == last_removed.get_titel() && liste[i].get_jahr() == last_removed.get_jahr())
		{
			int likes = liste[i].get_likes();
			if (opinion == "Y")
				liste[i].set_likes(likes + 1);
			else
				if (opinion == "N")
					liste[i].set_likes(likes - 1);
		}
	}
	return liste;
}

vector<Film> Repository::get_watchlist() {
	return client_watchlist;
};

Repository::~Repository() {};