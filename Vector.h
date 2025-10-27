#pragma once

// Vector 내적 외적

struct FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) : X(InX), Y(InY) {}

	virtual ~FVector2D() = default;

	FVector2D(const FVector2D& Rhs)
	{
		X = Rhs.X;
		Y = Rhs.Y;
	}
	FVector2D& operator=(const FVector2D& RHS) 
	{  
		X = RHS.X;
		Y = RHS.Y;
		return *this;
	}
	FVector2D operator+(const FVector2D& RHS) { return {this->X + RHS.X, this->Y + RHS.Y }; }
	FVector2D operator-(const FVector2D& RHS) { return {this->X - RHS.X, this->Y - RHS.Y }; }
	bool operator==(const FVector2D& RHS) { return { this->X == RHS.X && this->Y == RHS.Y }; }
	

	int X;
	int Y;
};