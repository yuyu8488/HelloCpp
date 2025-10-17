#pragma once

struct Vector2
{
public:
	Vector2() { X = 0; Y = 0; }
	Vector2(int InX, int InY) { X = InX, Y = InY; }
	
	void operator+=(const Vector2& Value) { X += Value.X; Y += Value.Y; }
	void operator-=(const Vector2& Value) { X -= Value.X; Y -= Value.Y; }
	Vector2 operator+(const Vector2& Value) const { return { X + Value.X, Y + Value.Y }; }
	Vector2 operator-(const Vector2& Value) const { return {X - Value.X, Y + Value.Y}; }
	
	int X;
	int Y;
};

class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void Tick();

	Vector2 GetActorLocation() const { return Pos; }
	char GetShape() const { return Shape; }
	void SetActorLocation(const int& X, const int& Y);
	void SetActorLocation(const Vector2& NewPos);
	void SetShape(const char& InShape) { Shape = InShape; }

private:
	char Shape;
	Vector2 Pos;
};

