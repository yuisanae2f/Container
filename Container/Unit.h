#ifndef AE2F
#ifdef AE2F_EXPORT
#define AE2F __declspec(dllexport)
#else
#define AE2F __declspec(dllimport)
#endif // AE2F_EXPORT
#endif // !AE2F
#ifndef AE2F_UNIT
#define AE2F_UNIT

#ifndef AE2F_CPP_PREFIX
#ifdef AE2F_CPP
#define AE2F_CPP_PREFIX extern "C"
#else
#define AE2F_CPP_PREFIX
#endif // AE2F_CPP
#endif // !AE2F_CPP_PREFIX

#include <stdint.h>

union ae2f_Unit {
#define ae2f_Unit_param \
	void* raw; \
	int8_t* bt1; \
	uint8_t* ubt1; \
	int16_t* bt2; \
	uint16_t* ubt2; \
	int32_t* bt4; \
	uint32_t* ubt4; \
	int64_t* bt8; \
	uint64_t* ubt8; \
	int64_t num; \
	uint64_t unum; \
	float* rFloat; \
	double* rDouble; \

	ae2f_Unit_param
};

/// <param name="a">: pretype (const/struct/union/unsigned)</param>
/// <param name="b">: type name</param>
#define ae2f_Unit_v(a, b) union virtual_##b { a b##* p; ae2f_Unit_param }
#endif // !AE2F_UNIT