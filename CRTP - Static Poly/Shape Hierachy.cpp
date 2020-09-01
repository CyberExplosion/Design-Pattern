#include <iostream>
using namespace std;

template <typename Derived>
class BaseShape {
public:
	void draw() {
		static_cast<Derived>(*this)->draw();
	}
	void move() {
		static_cast<Derived>(*this)->move();
	}
};

struct Pos {
	int x{};
	int y{};
};

struct BetterPos {
public:
	Pos x{};
	Pos y{};
};

class Rectangle : public BaseShape<Rectangle> {
public:
	Pos topLeft{};
	Pos botRight{};
public:
	void draw() {
		cout << "Position of the rectangle: Left corner - x: " << topLeft.x << ", y: " << topLeft.y << "\n"
			<< "Right corner - x: " << botRight.x << ", y: " << botRight.y << endl;
	}
};

int main() {
	Pos left{ 0,0 };
	Pos right{ 10,10 };
	Rectangle rec;
	rec.topLeft = left;
	rec.botRight = right;
	rec.draw();
	rec.move();
	cout << endl;
}