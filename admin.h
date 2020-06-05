#pragma once
#include "film.h"
#include<vector>

using namespace std;

class Repository
{
private:
	vector<Film> liste;
	vector <Film> client_watchlist;
	Film last_removed; 

public:
	/*
	Konstruktor
	*/
	Repository();

	/*
	Destruktor
	*/
	~Repository();

	/*
	Gibt die ganze Liste zurueck.
	*/
	vector<Film> getlist();

	/*
	Loescht einen Film
	*/
	vector<Film> remove(Film old_film);

	/*
	Fuegt einen Film hinzu
	*/
	vector<Film> add(Film new_film);

	/*
	Ersetzt einen alten Film mit einen neuen
	*/
	Film update(Film old_film, Film new_film);

	/*
	Gibt den watchlist eines users zurueck
	*/
	vector<Film> get_watchlist();


	
	/*
	Zeigt alle Filme aus einer Genre in einem vector
	*/
	vector<Film> show_genre(string genre);

	/*
	Fuegt einen Film zur watchlist der benutzer hinzu
	*/
	vector<Film> add_to_watchlist(Film film);

	/*
	Loescht einen Film von dem watchlist eines users
	*/
	vector<Film> remove_from_watchlist(string title, int year);

	/*
	Macht einen update fuer den Film eines Benutzers.
	*/
	vector<Film> rating(string opinion);
};