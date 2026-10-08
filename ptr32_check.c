/* Matches the actual engine's G32 storage and callback conversion model. */
#include <stdint.h>
#define G32 __ptr32 __uptr
struct GuestRecord { void *G32 value; void (*G32 callback)(void); };
_Static_assert(sizeof(struct GuestRecord)==8, "Guest records require two 4-byte pointers");
_Static_assert(sizeof(void *G32)==4, "G32 must be four bytes");
void StoreGuest(struct GuestRecord *r, void *value, void (*callback)(void)) {
    r->value=value; r->callback=callback;
}
void CallGuest(struct GuestRecord *r) { ((void (*)(void))r->callback)(); }
