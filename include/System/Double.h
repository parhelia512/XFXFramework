/*****************************************************************************
 *	Double.h																 *
 *																			 *
 *	XFX System::Double structure definition file							 *
 *	Copyright (c) XFX Team. All Rights Reserved 							 *
 *****************************************************************************/
#ifndef _SYSTEM_DOUBLE_
#define _SYSTEM_DOUBLE_

#include <System/Interfaces.h>
#include <System/Object.h>

namespace System
{
	class String;

	/**
	 * Represents a double precision floating point value.
	 */
	struct Double : IComparable<Double>, IEquatable<Double>, Object
	{
	private:
		double value;

	public:
		static const double Epsilon;
		static const double MaxValue;
		static const double MinValue;
		static const double NaN;
		static const double NegativeInfinity;
		static const double PositiveInfinity;

		Double(const double &obj);
		Double(const Double &obj);

		int CompareTo(const Double other) const;
		bool Equals(const Double other) const;
		int GetHashCode() const;
		static bool IsNaN(const Double& d);
		static bool IsNegativeInfinity(const Double& d);
		static bool IsPositiveInfinity(const Double& d);
		static const Type& GetType();
		const String ToString() const;
		static const String ToString(const double value);
		static bool TryParse(const String& str, out double* result);

		operator double() const;
		bool operator !=(const Double& right) const;
		bool operator ==(const Double& right) const;
	};
}

#endif //_SYSTEM_DOUBLE_
