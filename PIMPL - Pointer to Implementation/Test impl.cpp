#include "PIMPL.h"

//Use PIMPL when there's many files "include" your header files. Due to any change to header files causing recompilation, it's faster to use PIMPL

int main() {
	Caller rec;
	rec.draw();
}