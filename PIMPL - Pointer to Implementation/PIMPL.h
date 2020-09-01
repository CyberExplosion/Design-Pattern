#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct Pos {
	int x{};
	int y{};
};

//DO NOT provide any implementation in the header files or the PIMPL won't work because the compiler thought the class is not completed

class Caller {
private:
	class impl;
	unique_ptr<impl> pimpl;
public:
	Caller();
	~Caller();
	Caller(Caller&&);
	Caller& operator=(Caller&&);
	void draw();
};
