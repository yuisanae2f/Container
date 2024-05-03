#pragma once
#include "Dynamic.hpp"

#ifdef AE2F_DYNAMIC
#ifndef AE2F_PAIR
#define AE2F_PAIR

typedef struct ae2f_Pair {
	struct ae2f_Dynamic c;
	union ae2f_Unit val;
}* ptr_ae2f_Pair;

#define ae2f_Dynamic_owned ae2f_Dynamic
#define ptr_ae2f_Dynamic_owned ptr_ae2f_Dynamic

#endif // AE2F_PAIR

#ifndef AE2F_PAIR_FUN
#define AE2F_PAIR_FUN
/// <param name="a">: pair</param>
/// <param name="b">: key</param>
/// <param name="c">: value</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair(
	ptr_ae2f_Pair a,	// pair
	ptr_ae2f_Dynamic b,	// key
	ptr_ae2f_Dynamic c	// value
);

/// <param name="a">: pair</param>
/// <param name="b">: key</param>
/// <param name="c">: length key</param>
/// <param name="d">: value</param>
/// <param name="e">: length value</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_(
	ptr_ae2f_Pair a,	// pair
	void* b,				// key
	uint64_t c,				// length key
	void* d,				// value
	uint64_t e				// length value
);

/// <param name="a">: pair to be freed</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_free(
	ptr_ae2f_Pair a		// pair to be freed
);

/// <param name="a">: pair</param>
/// <param name="b">: value to be compared</param>
/// <param name="c">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F int8_t ae2f_Pair_weigh(
	ptr_ae2f_Pair a,	// pair
	ptr_ae2f_Dynamic b,	// value to be compared
	int8_t c				// value on 1 otherwise key
);

/// <param name="a">: pair to be set</param>
/// <param name="b">: value to set</param>
/// <param name="c">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_set(
	ptr_ae2f_Pair a,	// pair to be set
	ptr_ae2f_Dynamic b,	// value to set
	int8_t c				// value on 1 otherwise key
);

/// <param name="a">: pair to get</param>
/// <param name="b">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F struct ae2f_Dynamic_owned ae2f_Pair_get(
	ptr_ae2f_Pair a,	// pair to get
	int8_t b				// value on 1 otherwise key
);

/// <param name="a">: source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_copy(
	ptr_ae2f_Pair a,	// source
	ptr_ae2f_Pair b		// destination
);
#endif // !AE2F_PAIR_FUN
#endif // !AE2F_DYNAMIC
