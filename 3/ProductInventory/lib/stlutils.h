#ifndef STLUTILS_H
#define STLUTILS_H

class delete_ptr
{
	public:
		template <typename Type>
		void operator ()(const Type* ptr)const{delete ptr;}
};


class compare_ptr_by_value
{
	public:
		template <typename Type>
		bool operator()(const Type* ptr1, const Type* ptr2)const 
		{
		   return *ptr1 < *ptr2;
		}
};


#endif
