#ifndef AE2F_DYNAMIC
#include "Dynamic.h"
#endif // !AE2F_DYNAMIC

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
/// <param name="a">: container</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Context ae2f_Context(
	ptr_ae2f_Context a	// container
);

/// <param name="a">: container</param>
/// <param name="b">: length for new memory allocated</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Dynamic ae2f_Context_malloc(
	ptr_ae2f_Context a,	// container
	uint64_t b			// length for new memory allocated
);

/// <param name="a">: container to be freed</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Context ae2f_Context_free(
	ptr_ae2f_Context a	// container to be freed
);
#endif // !AE2F_CONTEXT_FUN
#endif // AE2F_DYNAMIC