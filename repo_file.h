#pragma once
#include "film.h"
#include <iostream>
#include <fstream>

using namespace std;

class Repo_File
{
private:
	ofstream file;

public:
	Repo_File();
	~Repo_File();

	void add(Film new_film);
	void remove(Film new_film);
	void update(Film old_film, Film new_film);
};