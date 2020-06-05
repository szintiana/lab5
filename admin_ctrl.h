#pragma once
#include <iostream>
#include<stdio.h>
#include <string>
#include <iostream>
#include<Windows.h>
#include "admin.h"

class Admincontrol
{
	friend class Repository;

private:
	Repository adm;

public:

	/*
	Konztruktor
	*/
	Admincontrol(Repository r);

	/*
	Spielt den trailer eines Filmes
	*/
	bool play_trailer(Film);

	/*
	Gibt die Liste der Admins an.
	*/
	void printAdminGetlist();

	/*
	Zeigt die Admins nach einer add
	*/
	void printAdminAdd(Film newfilm);

	/*
	Zeigt die Filme nach der Durchfuehrung eines remove Operations
	*/
	void printAdminRemove(Film target);

	/*
	Printet die updatete Liste
	*/
	void printAdminUpdate(Film target, Film newfilm);

	/*
	Zeigt die Filme nach genre
	*/
	void print_by_genre(string genre);

	/*
	adds a movie to the watchlist
	*/
	void print_add_to_watchlist(Film film);

	/*
	removes a movie from the watchlist
	*/
	void print_remove_from_watchlist(string title, int year);

	/*
	updates a movie's rating
	*/
	void print_rating(string opinion);
};