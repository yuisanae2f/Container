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
	uint64_t b				// length for new memory allocated
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

#ifdef AE2F_CPP
#ifndef AE2F_CONTEXT_CPP
#define AE2F_CONTEXT_CPP
#define ffun fun<Container::Context>
namespace ae2f {
	namespace Container {
		class Context;
	}

	template<>
	class fun<Container::Context> {
	public:
		class el;
		class setter;
		class starter;
	};

	class fun<Container::Context>::el : public Container::Dynamic::getter {
	private:
		ptr_ae2f_Context p;
	public:
		inline el(ptr_ae2f_Context a, uint64_t b);
		inline ptr_ae2f_Context id();
		inline setter del();
		inline el& re(uint64_t a);
		inline el& re(Container::Linked a);
	};

	class fun<Container::Context>::setter {
	private:
		ptr_ae2f_Context p;
	public:
		uint64_t
			& _amp,
			& _div;

		inline setter(ptr_ae2f_Context a);
		inline ptr_ae2f_Context raw();
		inline starter free();
		inline el malloc(uint64_t a);
	};

#pragma region el
	inline ffun::el::el(ptr_ae2f_Context a, uint64_t b)
		: p(a), getter(ae2f_Context_point(a[0]) + b) {}

	inline ffun::setter ffun::el::del() {
		ae2f_Context_del(this->p, this->raw() - ae2f_Context_point(this->p[0]));
		return this->p;
	}

	inline ptr_ae2f_Context ffun::el::id() {
		return this->p;
	}

	inline ffun::el& ffun::el::re(uint64_t a) {
		Container::Dynamic::setter(this->raw()).re(a);
		return this[0];
	}

	inline ffun::el& ffun::el::re(Container::Linked a) {
		Container::Dynamic::setter(this->raw()).re(a);
		return this[0];
	}
#pragma endregion

	class fun<Container::Context>::starter {
	private:
		ptr_ae2f_Context p;
	public:
		inline starter(ptr_ae2f_Context a);
		inline setter alloc();
		inline setter copy(setter a);
	};

#pragma region setter
	inline ffun::setter::setter(ptr_ae2f_Context a)
		: p(a), _amp(a->_amp), _div(a->_div) {}

	inline ffun::starter ffun::setter::free() {
		ae2f_Context_free(this->p);
		return this->p;
	}

	inline ffun::el ffun::setter::malloc(uint64_t a) {
		return { this->p, ae2f_Context_malloc(this->p, a) };
	}
#pragma endregion
#pragma region starter
	inline ffun::starter::starter(ptr_ae2f_Context a)
		: p(a) {}

	inline ffun::setter ffun::starter::alloc() {
		ae2f_Context(this->p);
		return this->p;
	}

	inline ffun::setter ffun::starter::copy(setter a) {
		ae2f_Context_copy(a.raw(), this->p);

		return this->p;
	}
#pragma endregion


	namespace Container {
		class Context : public fun<Container::Context>::setter {
		private:
			struct ae2f_Context obj;
		public:
			typedef ptr_ae2f_Context ptr;

			inline Context();
			inline Context(setter a);
		};

#pragma region context
		inline Context::Context()
			: setter(ffun::starter(&obj).alloc()) {}

		inline Context::Context(setter a)
			: setter(ffun::starter(&obj).copy(a)) {}
#pragma endregion
	}

}
#endif // !AE2F_CONTEXT_CPP
#endif // AE2F_CPP
#endif // AE2F_DYNAMIC