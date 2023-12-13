#pragma once

struct Vertex {
	int priority = 0;
	int id;
	int color;
	bool colored = false;

};

struct Edge3 {
	int start;
	int stop;
	int id;
};