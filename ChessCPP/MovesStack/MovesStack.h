#pragma once
#include <stack>
#include "../Move/Move.h"

// Extend the std::stack class and expose its internal container
class MovesStack : public std::stack<Move*> {
public:
	using std::stack<Move*>::c; // expose the container
};
