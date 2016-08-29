#pragma once
#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
	virtual char const * what() const { return "Method not yet implemented."; }
};

class TestNotImplementedException : public NotImplementedException
{
public: 
	virtual char const * what() const { return "Test not yet implemented."; }
};