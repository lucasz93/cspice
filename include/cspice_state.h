#ifdef __cplusplus
extern "C" {
#endif
void  cspice_init(); /* Readies the library for use in the current thread. */
void* cspice_copy(void* state); /* Deep copy of the given state. */
void* cspice_save(void); /* Makes a copy of the current thread's state, and provides a handle to the caller. */
void  cspice_push(void* state); /* Sets the given state as active. Be sure not to free it while it's active! */
void* cspice_pop(); /* Reverts to the thread's previous state. Returns the popped state. */
void  cspice_free(void* state); /* Releases state memory. */
void  cspice_shutdown(); /* Cleanup any thread specific allocations. */
#ifdef __cplusplus
}
#endif

