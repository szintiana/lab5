#pragma once
#include <iostream>
#include "client.h"

class Clientcontrol
{
	friend class Client;
private:
	Client cli;
public:

	/*
	Konstructor
	*/
	Clientcontrol(Client c);

	/*
	prints the list with the updated number of likes.
	*/
	void printOpinion(Film film, int i);
};