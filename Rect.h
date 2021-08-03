#pragma once
struct Rect
{
	float l;
	float t;
	float r;
	float b;

	void SetRect(float l, float t, float r, float b) {
		this->l = l;
		this->t = t;
		this->r = r;
		this->b = b;
	}

	bool CheckCollisionWithPoint(Vector2 pos) {
		if (l < pos.x &&
			r > pos.x &&
			t < pos.y &&
			b > pos.y)
		{
			return true;
		}
		return false;
	}
};

