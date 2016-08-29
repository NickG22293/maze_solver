#pragma once
#include <stdexcept>

class NotImplementedException : public std::logic_error
{
public:
	NotImplementedException() : std::logic_error("Method not yet implemented.") {}; 
};

class TestNotImplementedException : public std::logic_error
{
public: 
	TestNotImplementedException() : std::logic_error("Test not yet implemented.") {}; 
};