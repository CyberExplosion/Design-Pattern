#include "PIMPL.h"
using namespace std;

//Things change in here won't cause recompilation from the compiler

//Only put in IMPL implementation class "non-virtual private members (both data and functions)". Other things would cause problems later
//Do require implementation function an arguments for the Original header class object. May need it to call other public class in the future

//This will be in another file preferably
class Caller::impl {
private:
	Pos topLeft{};
	Pos botRight{};
	int internal_data{ 0 };
public:
	impl() {};
	~impl() {};
	void draw(const Caller&) const {	//Require a Caller object because just in case
		cout << "This rectangle top left: x - " << topLeft.x << " & y - " << topLeft.y << "\n"
			<< "bottom right: x - " << botRight.x << " & y - " << botRight.y << endl;
	}
};

Caller::Caller() : pimpl{ make_unique<impl>() } {};

Caller::~Caller() = default;

Caller::Caller(Caller&&) = default;

Caller& Caller::operator=(Caller&&) = default;

void Caller::draw() {
	pimpl->draw(*this);
}
