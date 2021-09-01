#ifdef __cplusplus
extern "C" {
#endif
void* cspice_alloc(); /* Readies the library for use in the current thread. */
void* cspice_copy(void* state); /* Deep copy of the given state. */
void  cspice_free(void* state); /* Releases state memory. */
#ifdef __cplusplus
}
#endif

