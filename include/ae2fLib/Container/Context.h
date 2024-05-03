#include "Dynamic.h"

#ifdef AE2F_DYNAMIC
#ifndef AE2F_CONTEXT
#define AE2F_CONTEXT
typedef struct ae2f_Context {
	struct ae2f_Dynamic c;
	uint64_t len, _amp, _div;
}*ptr_ae2f_Context;
#endif // !AE2F_CONTEXT

#ifndef AE2F_CONTEXT_FUN
#define AE2F_CONTEXT_FUN

#define ae2f_Context_point(a) ((ptr_ae2f_Dynamic)a.c.c.raw)

/// <param name="a">: container</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Context ae2f_Context(
	ptr_ae2f_Context a	// container
);

/// <param name="a">: container</param>
/// <param name="b">: length for new memory allocated</param>
AE2F_CPP_PREFIX AE2F uint64_t ae2f_Context_malloc(
	ptr_ae2f_Context a,	// container
	uint64_t b			// length for new memory allocated
);

/// <param name="a">: container to be freed</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Context ae2f_Context_free(
	ptr_ae2f_Context a	// container to be freed
);

/// <param name="a">: container</param>
/// <param name="b">: index to kill</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Context ae2f_Context_del(
	ptr_ae2f_Context a,
	uint64_t b
);

/// <param name="a">: source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F void ae2f_Context_copy(
	ptr_ae2f_Context a,
	ptr_ae2f_Context b
);
#endif // !AE2F_CONTEXT_FUN
#endif // AE2F_DYNAMIC