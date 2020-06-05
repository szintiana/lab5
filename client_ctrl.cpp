#include "client_ctrl.h"

void Clientcontrol::printOpinion(Film film, int i)
{
	vector<Film> v = cli.opinion(film, i).getlist();
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer();
}