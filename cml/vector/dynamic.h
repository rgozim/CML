/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 *  @brief Specialization for resizeable, dynamic-memory vector.
 */

#ifndef dynamic_vector_h
#define dynamic_vector_h

#include <cml/core/common.h>
#include <cml/core/dynamic_1D.h>
#include <cml/vector/vector_expr.h>
#include <cml/vector/class_ops.h>
#include <cml/vector/vector_unroller.h>
#include <cml/vector/vector_ops.h>
#include <cml/vector/vector_products.h>

namespace cml {

/** Resizeable, dynamic-memory vector. */
template<typename Element, typename Alloc>
class vector< Element, dynamic<Alloc> >
: public dynamic_1D<Element,Alloc>
{
  public:

    /* Shorthand for the generator: */
    typedef dynamic<Alloc> generator_type;

    /* Shorthand for the array type: */
    typedef dynamic_1D<Element,Alloc> array_type;

    /* Shorthand for the type of this vector: */
    typedef vector<Element,generator_type> vector_type;

    /* For integration into the expression template code: */
    typedef vector_type expr_type;

    /* For integration into the expression template code: */
    typedef vector_type temporary_type;

    /* Standard: */
    typedef typename array_type::value_type value_type;
    typedef typename array_type::reference reference;
    typedef typename array_type::const_reference const_reference;

    /* For integration into the expression templates code: */
    typedef vector_type& expr_reference;
    typedef const vector_type& expr_const_reference;

    /* For matching by storage type: */
    typedef typename array_type::memory_tag memory_tag;

    /* For matching by size type: */
    typedef typename array_type::size_tag size_tag;

    /* For matching by result-type: */
    typedef cml::et::vector_result_tag result_tag;


  public:

    /** Default constructor. */
    vector() : array_type() {}

    /** Construct given array size. */
    vector(size_t N) : array_type(N) {}


  public:

    /* Define common class operators: */
    CML_VEC_COPY_FROM_VECTYPE(: array_type())
    CML_VEC_COPY_FROM_VEC
    CML_VEC_COPY_FROM_VECXPR

    CML_VEC_ASSIGN_FROM_VECTYPE

    CML_VEC_ASSIGN_FROM_VEC(=, cml::et::OpAssign)
    CML_VEC_ASSIGN_FROM_VEC(+=, cml::et::OpAddAssign)
    CML_VEC_ASSIGN_FROM_VEC(-=, cml::et::OpSubAssign)

    CML_VEC_ASSIGN_FROM_VECXPR(=, cml::et::OpAssign)
    CML_VEC_ASSIGN_FROM_VECXPR(+=, cml::et::OpAddAssign)
    CML_VEC_ASSIGN_FROM_VECXPR(-=, cml::et::OpSubAssign)

    CML_VEC_ASSIGN_FROM_SCALAR(*=, cml::et::OpMulAssign)
    CML_VEC_ASSIGN_FROM_SCALAR(/=, cml::et::OpDivAssign)
};

} // namespace cml

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp