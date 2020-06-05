#include "admin_ctrl.h"

using namespace std;

Admincontrol::Admincontrol(Repository a)
{
	adm = a;
}

bool Admincontrol::play_trailer(Film film) {
	cout << "\n" << film.get_titel() << " ";
	cout << film.get_genre() << " ";
	cout << film.get_jahr() << " ";
	cout << film.get_likes() << " ";
	wstring beta(film.get_trailer().begin(), film.get_trailer().end());
	LPCWSTR trailer = beta.c_str();
	string alpha = "open";
	wstring alph(alpha.begin(), alpha.end());
	LPCWSTR status = alph.c_str();
	ShellExecute(NULL, status, trailer, NULL, NULL, SW_SHOWNORMAL);

	return true;
}


void Admincontrol::printAdminGetlist()
{
	vector<Film> v = adm.getlist();
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::printAdminAdd(Film newfilm)
{
	vector<Film> v = adm.add(newfilm);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::printAdminRemove(Film target)
{
	vector<Film> v = adm.remove(target);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::printAdminUpdate(Film target, Film newfilm)
{
	Film f = adm.update(target, newfilm);
	cout << f.get_titel() << " " << f.get_genre() << " " << f.get_jahr() << " " << f.get_likes() << " " << f.get_trailer() << endl;
}

void Admincontrol::print_by_genre(string genre)
{
	vector<Film> v = adm.show_genre(genre);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::print_add_to_watchlist(Film film)
{
	vector<Film> v = adm.add_to_watchlist(film);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::print_remove_from_watchlist(string title, int year)
{
	vector<Film> v = adm.remove_from_watchlist(title, year);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}

void Admincontrol::print_rating(string opinion)
{
	vector<Film> v = adm.rating(opinion);
	for (auto it : v)
		cout << it.get_titel() << " " << it.get_genre() << " " << it.get_jahr() << " " << it.get_likes() << " " << it.get_trailer() << endl;
}