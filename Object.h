#pragma once

class Object
{
protected:
	int id;
	string name;

public:
	 string GetName() { return name; }
	 void SetName(string _name) { name = _name; }

	 void SetId(const int _id) { id = _id; }
	 int GetId() const { return id; }
};