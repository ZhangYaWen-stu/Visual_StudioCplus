#pragma once
#define MaxSize 100
#define INFINIT 1000000
#include<iostream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
enum Status { UNVISITED, VISITED, SUCCESS, FAIL, VISITING, LOOPS, EMPTY };
class Error
{
private:
	string error;
public:
	Error(const char* error)
	{
		this->error = error;
	}
	string GetError()
	{
		return error;
	}
};
