#pragma once

#include "Unit.hpp"

#ifdef AE2F_UNIT
#ifndef AE2F_DYNAMIC
#define AE2F_DYNAMIC

typedef struct ae2f_Dynamic {
	union ae2f_Unit c;
	uint64_t len;
}* ptr_ae2f_Dynamic;

#endif // !AE2F_CONTAINER_ARRAY

#ifndef AE2F_DYNAMIC_FUN
#define AE2F_DYNAMIC_FUN
/// <param name="a">: memory pointer</param>
/// <param name="b">: new memory length</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic(
	ptr_ae2f_Dynamic a,		// memory pointer
	uint64_t b				// new memory length
);

/// <param name="a">: memory pointer</param>
/// <param name="b">: memory source</param>
/// <param name="c">: memory source length</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic_(
	ptr_ae2f_Dynamic a,	// memory pointer
	void* b,				// memory source
	uint64_t c				// memory source length
);

/// <param name="a">: memory source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic_copy(
	ptr_ae2f_Dynamic a,	// memory source
	ptr_ae2f_Dynamic b	// destination
);

/// <param name="a">: existing memory</param>
/// <param name="b">: new memory length</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic_re(
	ptr_ae2f_Dynamic a,	// existing memory
	uint64_t b				// new memory length
);

/// <param name="a">: exeisting memory</param>
/// <param name="b">: memory source</param>
/// <param name="c">: memory source length</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic_re_(
	ptr_ae2f_Dynamic a,	// exeisting memory
	void* b,				// memory source
	uint64_t c				// memory source length
);

/// <param name="a">: memory to be freed</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Dynamic_free(
	ptr_ae2f_Dynamic a	// memory to be freed
);

/// <param name="a">: value source</param>
/// <param name="b">: value wanted</param>
/// <param name="c">: count to ignore</param>
AE2F_CPP_PREFIX AE2F union ae2f_Unit ae2f_Dynamic_find(
	ptr_ae2f_Dynamic a,	// value source
	ptr_ae2f_Dynamic b,	// value wanted
	uint64_t c				// count to ignore
);

/// <param name="a">: value compared left</param>
/// <param name="b">: value compared right</param>
AE2F_CPP_PREFIX AE2F int8_t ae2f_Dynamic_weigh(
	ptr_ae2f_Dynamic a,	// value compared left
	ptr_ae2f_Dynamic b	// value compared right
);

/// <param name="a">: memory buffer</param>
/// <param name="b">: source</param>
/// <param name="c">: length selector</param>
AE2F_CPP_PREFIX AE2F uint64_t ae2f_Dynamic_puts(
	ptr_ae2f_Dynamic a,	// memory buffer
	ptr_ae2f_Dynamic b,	// source
	uint8_t c			// length selector
);

/// <param name="a">: a value</param>
/// <param name="b">: another value</param>
AE2F_CPP_PREFIX AE2F uint64_t ae2f_Dynamic_countEqual(
	ptr_ae2f_Dynamic a,
	ptr_ae2f_Dynamic b
);
#endif // !AE2F_DYNAMIC_FUN
#endif // AE2F_UNIT