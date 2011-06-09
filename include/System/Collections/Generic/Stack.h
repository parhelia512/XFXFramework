#ifndef _SYSTEM_COLLECTIONS_GENERIC_STACK_
#define _SYSTEM_COLLECTIONS_GENERIC_STACK_

#include <System/Object.h>
#include <System/Collections/Generic/Interfaces.h>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <class T>
			class Stack : public ICollection<T>, virtual Object
			{
			private:
				T* _bottom;
				T* _top;
				static const int _defaultCapacity;
				int _size;
				int _version;

			public:
				int Count()
				{
					return _size;
				}

				bool IsSynchronized()
				{
					return false;
				}

				Stack()
				{
					_bottom = new T[_defaultCapacity];
					_size = 0;
					_version = 0;
				}

				Stack(ICollection<T>* col)
				{
					Stack((!col) ? 0x20 : col->Count());

					if (!col)
						throw ArgumentNullException("col");

					for (int i = 0; i < col->Count(); i++)
					{
						// TODO: Push all values in the ICollection into this Stack.
					}
				}

				Stack(int initialCapacity)
				{
					if (initialCapacity < 0)
						throw ArgumentOutOfRangeException("initialCapacity", "Non-negative number required");

					if (initialCapacity < _defaultCapacity)
						initialCapacity = _defaultCapacity;

					_bottom = new T[initialCapacity];
					_size = 0;
					_version = 0;
				}

				virtual ~Stack()
				{
					delete[] _bottom;
				}

				virtual void Clear()
				{
					Array::Clear(_bottom, 0, _size);
					_size = 0;
					_version++;
				}

				virtual bool Contains(T obj);
				virtual void CopyTo(T array[], int index);

				virtual T Peek();
				{
					return *_top;
				}

				virtual T Pop()
				{
					_top--;
					_version++;
					return *_top;
				}

				virtual void Push(T obj)
				{
					*_top = obj; 
					_top++;
					_version++;
				}

				virtual T* ToArray()
				{
				}
			};
		}
	}
}

#endif //_SYSTEM_COLLECTIONS_GENERIC_STACK_