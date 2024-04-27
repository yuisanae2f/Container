#pragma once
#ifndef AE2F_DYNAMIC
#include "Dynamic.h"
#endif // !AE2F_DYNAMIC

#ifdef AE2F_DYNAMIC
#ifndef AE2F_DIMENSION
#define AE2F_DIMENSION
typedef struct ae2f_Dimension {
	struct ae2f_Dynamic c;
	uint64_t depth;
	uint8_t end;
	struct ae2f_Dimension* pre;
}*ptr_ae2f_Dimension;
#endif // !AE2F_DIMENSION

#ifndef AE2F_DIMENSION_FUN
#define AE2F_DIMENSION_FUN
/// <param name="a">: matrix</param>
/// <param name="b">: depth of the matrix</param>
/// <param name="c">: length for every depth level</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension(
	ptr_ae2f_Dimension a,		// matrix
	uint64_t b,					// depth of the matrix
	uint64_t* c					// length for every depth level
);

/// <param name="a">: matrix initialised already</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_free(
	ptr_ae2f_Dimension a	// matrix initialised already
);

/// <param name="a">: matrix initialised</param>
/// <param name="b">: depth of the matrix</param>
/// <param name="c">: position for every depth level</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_point(
	ptr_ae2f_Dimension a,		// matrix initialised
	uint64_t b,					// depth of the matrix
	uint64_t* c					// position for every depth level
);

/// <param name="a">: matrix initialised yet</param>
/// <param name="b">: count of the new depth layer</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_lay(
	ptr_ae2f_Dimension a,		// matrix initialised yet
	uint64_t b					// count of the new depth layer
);

/// <param name="a">: matrix initialised yet</param>
/// <param name="b">: final size of the current depth layer</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_morph(
	ptr_ae2f_Dimension a,		// matrix initialised yet
	uint64_t b					// final size of the current depth layer
);

/// <param name="a">: matrix source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_copy(
	ptr_ae2f_Dimension a,	// matrix source
	ptr_ae2f_Dimension b	// destination
);

/// <param name="a">: matrix</param>
/// <param name="b">: setter value</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dimension ae2f_Dimension_setDepth(
	ptr_ae2f_Dimension a,		// matrix
	uint64_t b					// setter value
);
#endif // !AE2F_DIMENSION_FUN
#endif // AE2F_DYNAMIC