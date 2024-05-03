#pragma once
#include "Unit.h"

#ifdef __cplusplus
#define AE2F_CPP_PREFIX extern "C"

#ifndef AE2F_DEF_CPP
#define AE2F_DEF_CPP
namespace ae2f {
	template<typename t>
	class def {
	public:
		typedef t orig;
		typedef t* ptr;
	};
}
#endif
#else
#define AE2F_CPP_PREFIX
#define AE2F
#endif