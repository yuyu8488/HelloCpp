#pragma once

struct FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) : X(InX), Y(InY) {}

	virtual ~FVector2D() = default;

	FVector2D operator+(const FVector2D& Other) { return { X + Other.X, Y + Other.Y }; }
	FVector2D operator-(const FVector2D& Other) { return { X - Other.X, Y - Other.Y }; }

	int X;
	int Y;
};
