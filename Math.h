#pragma once

namespace Math
{
struct Matrix4x4
{
public:
    _forceinline Matrix4x4()
    {
        M[0][0] = 0; M[0][1] = 0; M[0][2] = 0; M[0][3] = 0;
        M[1][0] = 0; M[1][1] = 0; M[1][2] = 0; M[1][3] = 0;
        M[2][0] = 0; M[2][1] = 0; M[2][2] = 0; M[2][3] = 0;
        M[3][0] = 0; M[3][1] = 0; M[3][2] = 0; M[3][3] = 0;
    }

    _forceinline Matrix4x4(float m00, float m01, float m02, float m03,
                           float m10, float m11, float m12, float m13,
                           float m20, float m21, float m22, float m23,
                           float m30, float m31, float m32, float m33)
    {
        M[0][0] = m00; M[0][1] = m01; M[0][2] = m02; M[0][3] = m03;
        M[1][0] = m10; M[1][1] = m11; M[1][2] = m12; M[1][3] = m13;
        M[2][0] = m20; M[2][1] = m21; M[2][2] = m22; M[2][3] = m23;
        M[3][0] = m30; M[3][1] = m31; M[3][2] = m32; M[3][3] = m33;
    }

    

private:
    float M[4][4];
};

}
