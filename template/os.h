#ifdef HPUX
#define export /* */
#include "integer.h"
template integer square<integer>(const integer value);
#endif /* HPUX */

#ifdef GCC
#include "integer.h"
template integer square<integer>(const integer value);
#endif /* GCC */
