// bslstl_badweakptr.h                                                -*-C++-*-
#ifndef INCLUDED_BSLSTL_BADWEAKPTR
#define INCLUDED_BSLSTL_BADWEAKPTR

#include <bsls_ident.h>
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide an exception class to indicate a weak_ptr has expired.
//
//@CLASSES:
//  bslstl::BadWeakPtr: exception class derived from 'native_std' classes
//  bsl::bad_weak_ptr: alias to an exception type thrown by the 'bsl' library
//
//@CANONICAL_HEADER: bsl_memory.h
//
//@SEE_ALSO: bslstl_sharedptr, bslstl_stdexceptionutil
//
//@DESCRIPTION: This component provides ...
//
///Usage
///-----
// This section illustrates intended use of this component.
//
///Example 1: TBD
/// - - - - - - -

// Prevent 'bslstl' headers from being included directly in 'BSL_OVERRIDES_STD'
// mode.  Doing so is unsupported, and is likely to cause compilation errors.
#if defined(BSL_OVERRIDES_STD) && !defined(BOS_STDHDRS_PROLOGUE_IN_EFFECT)
#error "include <bsl_memory.h> instead of <bslstl_badweakptr.h> in \
BSL_OVERRIDES_STD mode"
#endif
#include <bslscm_version.h>

#include <bsls_exceptionutil.h>
#include <bsls_keyword.h>
#include <bsls_nativestd.h>

#include <exception>

#include <memory>                // 'std::bad_weak_ptr' if defined

namespace BloombergLP {
namespace bslstl { class BadWeakPtr; }
}  // close enterprise namespace

namespace bsl {
#if 0
typedef native_std::bad_weak_ptr bad_weak_ptr;
#else
typedef ::BloombergLP::bslstl::BadWeakPtr bad_weak_ptr;
#endif

}  // close namespace bsl


namespace BloombergLP {
namespace bslstl {

                       // ================
                       // class BadWeakPtr
                       // ================

class BadWeakPtr : public native_std::exception {
  public:
    BadWeakPtr() BSLS_KEYWORD_NOEXCEPT;
        // Create a 'BadWeakPtr' object.  Note that this function is explicitly
        // user-declared, to make it simple to declare 'const' objects of this
        // type.

    // ACCESSORS
    const char *what() const BSLS_EXCEPTION_WHAT_NOTHROW BSLS_KEYWORD_OVERRIDE;
        // Return a pointer to the string literal "bad_weak_ptr", with a
        // storage duration of the lifetime of the program.  Note that the
        // caller should *not* attempt to free this memory.  Note that the
        // 'bsls_exceptionutil' macro 'BSLS_NOTHROW_SPEC' is deliberately not
        // used here, as a number of standard libraries declare 'what' in the
        // base 'exception' class explicitly with the no-throw specification,
        // even in a build that may not recognize exceptions.
};

// ============================================================================
//                           INLINE DEFINITIONS
// ============================================================================

                       // ----------------
                       // class BadWeakPtr
                       // ----------------

inline
BadWeakPtr::BadWeakPtr() BSLS_KEYWORD_NOEXCEPT
: native_std::exception()
{
}

inline
const char *BadWeakPtr::what() const BSLS_EXCEPTION_WHAT_NOTHROW
{
    return "bad_weak_ptr";
}

}  // close package namespace
}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
