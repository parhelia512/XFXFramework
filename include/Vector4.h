/*****************************************************************************
 *	Vector4.h																 *
 *																			 *
 *	XFX::Vector4 structure definition file  								 *
 *	Copyright (c) XFX Team. All Rights Reserved 							 *
 *****************************************************************************/
#ifndef _XFX_VECTOR4_
#define _XFX_VECTOR4_

#include <System/Interfaces.h>
#include <System/Object.h>

using namespace System;

namespace XFX
{
	struct Matrix;
	struct Quaternion;
	struct Vector2;
	struct Vector3;
	
	/**
	 * Defines a vector with four components.
	 */
	struct Vector4 : IEquatable<Vector4>, Object
	{
		float X;
		float Y;
		float Z;
		float W;
		static const Vector4 One;
		static const Vector4 UnitW;
		static const Vector4 UnitX;
		static const Vector4 UnitY;
		static const Vector4 UnitZ;
		static const Vector4 Zero;

		Vector4(float value);
		Vector4(float x, float y, float z, float w);
		Vector4(Vector2 value, float z, float w);
		Vector4(Vector3 value, float w);
		Vector4(const Vector4 &obj);
		Vector4();
			
		static Vector4 Add(Vector4 vector1, Vector4 vector2);
		static void Add(Vector4 vector1, Vector4 vector2, out Vector4& result);
		static Vector4 Baricentric(Vector4 value1, Vector4 value2, Vector4 value3, float amount1, float amount2);
		static void Baricentric(Vector4 value1, Vector4 value2, Vector4 value3, float amount1, float amount2, out Vector4& result);
		static Vector4 CatmullRom(Vector4 value1, Vector4 value2, Vector4 value3, Vector4 value4, float amount);
		static void CatmullRom(Vector4 value1, Vector4 value2, Vector4 value3, Vector4 value4, float amount, out Vector4& result);
		static Vector4 Clamp(Vector4 value1, Vector4 min, Vector4 max);
		static void Clamp(Vector4 value1, Vector4 min, Vector4 max, out Vector4& result);
		static float Distance(Vector4 value1, Vector4 value2);
		static void Distance(Vector4 value1, Vector4 value2, out float& result);
		static float DistanceSquared(Vector4 value1, Vector4 value2);
		static void DistanceSquared(Vector4 value1, Vector4 value2, out float& result);
		static Vector4 Divide(Vector4 value, float scale);
		static void Divide(Vector4 value, float scale, out Vector4& result);
		static Vector4 Divide(Vector4 vector1, Vector4 vector2);
		static void Divide(Vector4 vector1, Vector4 vector2, out Vector4& result);
		bool Equals(Object const * const obj) const;
		bool Equals(const Vector4 other) const;
		int GetHashCode() const;
		static const Type& GetType();
		static Vector4 Hermite(Vector4 value1, Vector4 tangent1, Vector4 value2, Vector4 tangent2, float amount);
		static void Hermite(Vector4 value1, Vector4 tangent1, Vector4 value2, Vector4 tangent2, float amount, out Vector4& result);
		float Length();
		float LengthSquared();
		static Vector4 Lerp(Vector4 value1, Vector4 value2, float amount);
		static void Lerp(Vector4 value1, Vector4 value2, float amount, out Vector4& result);
		static Vector4 Max(Vector4 value1, Vector4 value2);
		static void Max(Vector4 value1, Vector4 value2, out Vector4& result);
		static Vector4 Min(Vector4 value1, Vector4 value2);
		static void Min(Vector4 value1, Vector4 value2, out Vector4& result);
		static Vector4 Multiply(Vector4 value1, float scaleFactor);
		static void Multiply(Vector4 value1, float scaleFactor, out Vector4& result);
		static Vector4 Multiply(Vector4 value1, Vector4 value2);
		static void Multiply(Vector4 value1, Vector4 value2, out Vector4& result);
		static Vector4 Negate(Vector4 value);
		static void Negate(Vector4 value, out Vector4& result);
		void Normalize();
		static Vector4 Normalize(Vector4 value);
		static void Normalize(Vector4 value, out Vector4& result);
		static Vector4 SmoothStep(Vector4 value1, Vector4 value2, float amount);
		static void SmoothStep(Vector4 value1, Vector4 value2, float amount, out Vector4& result);
		static Vector4 Subtract(Vector4 value1, Vector4 value2);
		static void Subtract(Vector4 value1, Vector4 value2, out Vector4& result);
		const String ToString() const;
		static void Transform(Vector4 sourceArray[], Quaternion rotation, Vector4 destinationArray[]);
		static void Transform(Vector4 sourceArray[], int sourceIndex, Quaternion rotation, Vector4 destinationArray[], int destinationIndex, int length);
		static void Transform(Vector4 sourceArray[], Matrix matrix, Vector4 destinationArray[]);
		static void Transform(Vector4 sourceArray[], int sourceIndex, Matrix matrix, Vector4 destinationArray[], int destinationIndex, int length);
		static Vector4 Transform(Vector4 vector, Quaternion rotation);
		static void Transform(Vector4 vector, Quaternion rotation, out Vector4& result);
		static Vector4 Transform(Vector3 vector, Quaternion rotation);
		static void Transform(Vector3 vector, Quaternion rotation, out Vector4& result);
		static Vector4 Transform(Vector2 vector, Quaternion rotation);
		static void Transform(Vector2 vector, Quaternion rotation, out Vector4& result);
		static Vector4 Transform(Vector4 vector, Matrix matrix);
		static void Transform(Vector4 vector, Matrix matrix, out Vector4& result);
		static Vector4 Transform(Vector3 position, Matrix matrix);
		static void Transform(Vector3 position, Matrix matrix, out Vector4& result);
		static Vector4 Transform(Vector2 vector, Matrix matrix);
		static void Transform(Vector2 vector, Matrix matrix, out Vector4& result);

		Vector4 operator-(const Vector4& other);
		Vector4 operator-();
		bool operator!=(const Vector4& other) const;
		Vector4 operator *(const float scaleFactor);
		Vector4 operator *(const Vector4& other);
		Vector4 operator /(const float divider);
		Vector4 operator /(const Vector4& other);
		Vector4 operator +(const Vector4& other);
		bool operator==(const Vector4& other) const;
	} ALIGNED16;
}

#endif //_XFX_VECTOR4_
