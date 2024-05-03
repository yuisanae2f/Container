#pragma once
#include "Dynamic.h"

#ifdef __cplusplus
#ifndef AE2F_DYNAMIC_CPP
#define AE2F_DYNAMIC_CPP

#ifndef AE2F_IGNORE_MISSINGS
#include <string>
#include <initializer_list>
#endif // !AE2F_IGNORE_MISSINGS

namespace ae2f {
	template<typename T> class fun;

	namespace Container {
		class Dynamic;
		class Linked;
	}

	template<> class fun<Container::Dynamic> {
	public:
		class setter;
		class starter;
		class getter;
	};

	class fun<Container::Dynamic>::getter : public def<struct ae2f_Dynamic> {
	private:
		ptr p;
	public:
		inline ptr_ae2f_Dynamic raw();

		inline bool operator==(Container::Linked a);
		inline bool operator<=(Container::Linked a);
		inline bool operator>=(Container::Linked a);
		inline bool operator<(Container::Linked a);
		inline bool operator>(Container::Linked a);

		/// <param name="a">: pointer</param>
		inline getter(
			ptr a	// pointer
		);

		/// <param name="a">: value to be compared</param>
		inline int8_t weigh(
			Container::Linked a		// value to compare
		);

		/// <param name="a">: value to compare</param>
		inline int8_t weigh(
			Container::Linked* a	// value to compare
		);

		/// <param name="a">: value to be inserted</param>
		/// <param name="b">: length selector</param>
		inline uint64_t puts(
			Container::Linked a,	// value to be inserted
			char b					// length selector
		);

		/// <param name="a">: value to be inserted</param>
		/// <param name="b">: length selector</param>
		inline uint64_t puts(
			Container::Linked* a,	// value to be inserted
			char b					// length selector
		);

		/// <typeparam name="p">: pointer type</typeparam>
		template<typename p>
		inline p* point();

		/// <typeparam name="p">: value type</typeparam>
		/// <param name="a">: index</param>
		template<typename p>	// value type
		inline p& at(
			uint64_t a			// index
		);

		inline uint64_t len();

		/// <typeparam name="p">: counter type</typeparam>
		template<typename p = char>	// counter type
		inline uint64_t count();
	};

	class fun<Container::Dynamic>::setter : public getter {
	public:
		/// <param name="a">: container old</param>
		inline setter(
			struct ae2f_Dynamic* a	// container old
		);

		/// <param name="a">: new length</param>
		inline setter& re(
			uint64_t a	// new length
		);

		/// <typeparam name="v">: array type</typeparam>
		/// <param name="a">: pointer(array)</param>
		/// <param name="b">: pointer length</param>
		template<typename v>	// array type
		inline setter& re(
			v* a,				// pointer(array)
			uint64_t b			// pointer length
		);

		inline setter& re(
			Container::Linked a
		);

		inline fun<Container::Dynamic>::starter free();
	};

	class fun<Container::Dynamic>::starter : public def<struct ae2f_Dynamic> {
	private:
		ptr p;
	public:
		/// <param name="a">: pointer</param>
		inline starter(
			ptr a	// pointer
		);

		/// <param name="len">: length</param>
		inline setter alloc(
			uint64_t a		// length
		);

		/// <typeparam name="v">: array type</typeparam>
		/// <param name="a">: array</param>
		/// <param name="b">: array count</param>
		template<typename v>	// array type
		inline setter alloc(
			v* a,		// array
			uint64_t b	// array count
		);

		/// <param name="a">: source</param>
		inline setter copy(
			getter a		// source
		);

		/// <param name="a">: source pointer</param>
		inline setter copy(
			getter* a		// source pointer
		);

		/// <param name="a">: source</param>
		inline setter copy(
			orig a	// source
		);

		/// <param name="a">: source ptr</param>
		inline setter copy(
			ptr a	// source ptr
		);

		/// <typeparam name="v">: array type</typeparam>
		/// <param name="a">: array pointer</param>
		/// <param name="b">: array count</param>
		template<typename v>	// array type
		inline getter link(
			v* a,				// array pointer
			uint64_t b			// array length
		);
	};

	namespace Container {
		class Dynamic : public fun<Dynamic>::setter {
		private:
			orig obj;
		public:
			/// <param name="a">: length</param>
			inline Dynamic(
				uint64_t a	// length
			);

			/// <param name="a">: string</param>
			inline Dynamic(
				std::string a	// string
			);

			/// <param name="a">: getter</param>
			inline Dynamic(
				getter a	// getter
			);

			/// <param name="a">: getter pointer</param>
			inline Dynamic(
				getter* a	// getter
			);

			/// <typeparam name="v">: array pointer type</typeparam>
			/// <param name="a">: array</param>
			/// <param name="b">: length</param>
			template<typename v>	// array pointer type
			inline Dynamic(
				v* a,		// array
				uint64_t b	// length
			);

			/// <typeparam name="v">: array type</typeparam>
			/// <param name="a">: initialiser array</param>
			template<typename v>			// array type
			inline Dynamic(
				std::initializer_list<v> a	// initialiser array
			);

			/// <typeparam name="v">: array type</typeparam>
			/// <param name="a">: initialiser array</param>
			template<typename v>			// array type
			inline setter& re(
				std::initializer_list<v> a	// initialiser array
			);

			/// <param name="a">: string</param>
			inline setter& re(
				std::string a	// string
			);

			inline ~Dynamic();
		};
		class Linked : public fun<Dynamic>::getter {
		private:
			orig obj;
		public:

			/// <typeparam name="v">: array pointer type</typeparam>
			/// <param name="a">: array</param>
			/// <param name="b">: length</param>
			template<typename v>	// array pointer type
			inline Linked(
				v* a,		// array
				uint64_t b	// length
			);

			/// <typeparam name="v">: array pointer type</typeparam>
			/// <param name="a">: array</param>
			template<typename v>	// array pointer type
			inline Linked(
				std::initializer_list<v>& a	// array
			);

			/// <param name="a">: string</param>
			inline Linked(
				std::string& a	// string
			);

			/// <param name="a">: getter</param>
			inline Linked(
				getter a	// getter
			);

			/// <param name="a">: getter</param>
			inline Linked(
				getter* a	// getter
			);

			/// <param name="a">: value source</param>
			inline Linked(
				orig a	// value source
			);
		};
	}
}

#define ae2f_ffun ae2f::fun<ae2f::Container::Dynamic>

#pragma region getter
inline ae2f_ffun::getter::getter(ptr_ae2f_Dynamic a) : p(a) {}

inline ptr_ae2f_Dynamic ae2f_ffun::getter::raw() {
	return this->p;
}

template<typename p>
inline uint64_t ae2f_ffun::getter::count() {
	return this->p->len / sizeof(p);
}

inline uint64_t ae2f_ffun::getter::len() {
	return this->p->len;
}

inline int8_t ae2f_ffun::getter::weigh(Container::Linked a) {
	return ae2f_Dynamic_weigh(this->raw(), a.raw());
}

inline int8_t ae2f_ffun::getter::weigh(Container::Linked* a) {
	return ae2f_Dynamic_weigh(this->raw(), a->raw());
}

inline uint64_t ae2f_ffun::getter::puts(Container::Linked a, char b) {
	return ae2f_Dynamic_puts(this->raw(), a.raw(), b);
}

inline uint64_t ae2f_ffun::getter::puts(Container::Linked* a, char b) {
	return ae2f_Dynamic_puts(this->raw(), a->raw(), b);
}

template<typename pdp>
inline pdp* ae2f_ffun::getter::point() { return (pdp*)this->p->c.raw; }

template<typename asd>
inline asd& ae2f_ffun::getter::at(
	uint64_t a
) {
	switch (this->p->len < a * sizeof(asd)) {
	case 0: return this->point<asd>()[a];
	case 1: return this->point<asd>()[0];
	}
}

inline bool ae2f_ffun::getter::operator==(Container::Linked a) {
	return !(ae2f_Dynamic_weigh(a.raw(), this->p));
}
inline bool ae2f_ffun::getter::operator<(Container::Linked a) {
	return ae2f_Dynamic_weigh(a.raw(), this->p) == -1;
}
inline bool ae2f_ffun::getter::operator<=(Container::Linked a) {
	switch (ae2f_Dynamic_weigh(a.raw(), this->p)) {
	case 0: case -1:
		return 1;
	default: return 0;
	}
}
inline bool ae2f_ffun::getter::operator>(Container::Linked a) {
	return !(*this <= a);
}
inline bool ae2f_ffun::getter::operator>=(Container::Linked a) {
	return !(*this < a);
}

#pragma endregion
#pragma region setter
inline ae2f_ffun::setter::setter(
	struct ae2f_Dynamic* a	// container old
) : getter(a) {}

inline ae2f_ffun::setter& ae2f_ffun::setter::re(
	uint64_t a
) {
	ae2f_Dynamic_re(this->raw(), a);
	return *this;
}

template<>
inline ae2f_ffun::setter& ae2f_ffun::setter::re(
	void* a,
	uint64_t b
) {
	ae2f_Dynamic_re_(this->raw(), a, b);
	return *this;
}

template<typename v>	// array type
inline ae2f_ffun::setter& ae2f_ffun::setter::re(
	v* a,				// pointer(array)
	uint64_t b			// pointer length
) {
	return this->re((void*)a, b * sizeof(v));
}

inline ae2f_ffun::setter& ae2f_ffun::setter::re(
	ae2f::Container::Linked a
) {
	return this->re(a.point<char>(), a.len());
}

inline ae2f_ffun::starter ae2f_ffun::setter::free() {
	ae2f_Dynamic_free(this->raw());
	return this->raw();
}
#pragma endregion
#pragma region starter
inline ae2f_ffun::starter::starter(
	struct ae2f_Dynamic* a	// pointer
) : p(a) {}

inline ae2f_ffun::setter ae2f_ffun::starter::alloc(
	uint64_t a		// length
) {
	ae2f_Dynamic(this->p, a);
	return this->p;
}

template<>
inline ae2f_ffun::setter ae2f_ffun::starter::alloc<void>(
	void* a,		// array
	uint64_t b		// array length
) {
	ae2f_Dynamic_(this->p, a, b);
	return this->p;
}

template<typename v>	// array type
inline ae2f_ffun::setter ae2f_ffun::starter::alloc(
	v* a,		// array
	uint64_t b	// array count
) {
	return this->alloc<void>((void*)a, b * sizeof(v));
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(
	getter a		// source
) {
	return this->copy(a.raw());
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(
	getter* a		// source
) {
	return this->copy(a->raw());
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(
	struct ae2f_Dynamic a
) {
	return this->copy(&a);
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(
	struct ae2f_Dynamic* a
) {
	ae2f_Dynamic_copy(a, this->p);
	return this->p;
}

template<>
inline ae2f_ffun::getter ae2f_ffun::starter::link(
	void* a,
	uint64_t b
) {
	switch ((uint64_t)a) {
	case 0: throw 3;
	default: break;
	}

	this->p->c.raw = (void*)a;
	this->p->len = b;

	return this->p;
}

template<typename v>	// array type
inline ae2f_ffun::getter ae2f_ffun::starter::link(
	v* a,				// array pointer
	uint64_t b			// array length
) {
	return this->link((void*)a, b * sizeof(v));
}


#pragma endregion
#pragma region Dynamic
#define ae2f_name ae2f::Container
inline ae2f_name::Dynamic::Dynamic(uint64_t a)
	: setter(fun<Dynamic>::starter(&obj).alloc(a)) {}

inline ae2f_name::Dynamic::Dynamic(std::string a)
	: setter(fun<Dynamic>::starter(&obj).alloc(a.c_str(), a.size())) {}

inline ae2f_name::Dynamic::Dynamic(getter a)
	: setter(fun<Dynamic>::starter(&obj).copy(a.raw())) {}

inline ae2f_name::Dynamic::Dynamic(getter* a)
	: setter(fun<Dynamic>::starter(&obj).copy(a->raw())) {}

template<typename v>
inline ae2f_name::Dynamic::Dynamic(v* a, uint64_t b)
	: setter(fun<Dynamic>::starter(&obj).alloc<v>(a, b)) {}

template<typename v>
inline ae2f_name::Dynamic::Dynamic(std::initializer_list<v> a)
	: setter(fun<Dynamic>::starter(&obj).alloc<v>((v*)a.begin(), a.size())) {}

template<typename v>
inline ae2f_ffun::setter& ae2f_name::Dynamic::re(std::initializer_list<v> a) {
	return ((setter*)this)->re<v>((v*)a.begin(), a.size());
}

inline ae2f_ffun::setter& ae2f_name::Dynamic::re(std::string a) {

	return ((setter*)this)->re(a.c_str(), a.size());;
}
inline ae2f_name::Dynamic::~Dynamic() {
	this->free();
}

#pragma endregion
#pragma region Linked
template<typename v>	// array pointer type
inline ae2f_name::Linked::Linked(
	v* a,		// array
	uint64_t b	// length
) : getter(ae2f_ffun::starter(&obj).link<v>(a, b)) {}

/// <typeparam name="v">: array pointer type</typeparam>
/// <param name="a">: array</param>
template<typename v>	// array pointer type
inline ae2f_name::Linked::Linked(
	std::initializer_list<v>& a	// array
) : getter(ae2f_ffun::starter(&obj).link<v>(a.begin(), a.size())) {}

inline ae2f_name::Linked::Linked(
	std::string& a	// string
) : getter(ae2f_ffun::starter(&obj).link(a.c_str(), a.size())) {}

inline ae2f_name::Linked::Linked(
	struct ae2f_Dynamic a	// value source
) : obj(a), getter(&obj) {}

/// <param name="a">: getter</param>
inline ae2f_name::Linked::Linked(
	getter a	// getter
) : getter(a) {}

/// <param name="a">: getter</param>
inline ae2f_name::Linked::Linked(
	getter* a	// getter
) : getter(a->raw()) {}
#pragma endregion

#undef ae2f_name
#undef ae2f_ffun
#endif // !AE2F_DYNAMIC_CPP
#endif // AE2F_CPP