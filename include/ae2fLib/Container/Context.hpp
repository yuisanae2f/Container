#pragma once
#include "Context.h"

#ifdef __cplusplus
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
	public:
		typedef def<struct ae2f_Context> _root;

		inline el(_root::ptr a, uint64_t b);
		inline _root::ptr id();
		inline setter del();
		inline el& re(uint64_t a);
		inline el& re(Container::Linked a);

	private:
		_root::ptr p;
	};

	class fun<Container::Context>::setter : public def<struct ae2f_Context> {
	private:
		ptr p;
	public:
		uint64_t
			& _amp,
			& _div;

		inline setter(ptr a);
		inline ptr raw();
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
			orig obj;
		public:
			typedef ptr binder;

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