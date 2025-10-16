#pragma once

struct Position
{
public:
	Position() { X = 0, Y = 0; }
	Position(int InX, int InY) { X = InX, Y = InY; }
	int X;
	int Y;
};

class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void Tick();

	Position GetPosition() const { return Pos; }
	char GetShape() const { return Shape; }
protected:
	void SetPosition(const Position& NewPos);
	void SetShape(const char& InShape) { Shape = InShape; }

private:
	char Shape;
	Position Pos;
};

