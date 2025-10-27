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


struct FVector3
{
public:
	FVector3() : X(0), Y(0), Z(0) {}
	FVector3(int x, int y, int z) : X(x), Y(y), Z(z) {}
	FVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

	FVector3 operator+(const FVector3& Rhs){ return { X + Rhs.X, Y + Rhs.Y, Z + Rhs.Z }; }
	FVector3 operator-(const FVector3& Rhs){ return { X - Rhs.X, Y - Rhs.Y, Z - Rhs.Z }; }
	FVector3 operator*(const FVector3& Rhs){ return { X * Rhs.X, Y * Rhs.Y, Z * Rhs.Z }; }
	bool operator==(const FVector3& Rhs) { return { X == Rhs.X && Y == Rhs.Y && Z == Rhs.Z }; }

	float Dot(const FVector3& Rhs)
	{
		return { X * Rhs.X + Y * Rhs.Y + Z * Rhs.Z };
	}





	float X;
	float Y;
	float Z;
};