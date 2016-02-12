
#include <stdio.h>
#include <lightning.h>

static jit_state_t *_jit;

typedef int (*pifi)(int);    /* Pointer to Int Function of Int */

int main(int argc, char *argv[])
{
  pifi         incr;

  init_jit(NULL);
  _jit = jit_new_state();

  jit_prolog(); 
  jit_node_t* in = jit_arg();
  jit_getarg(JIT_R0, in);   
  jit_addi(JIT_R0, JIT_R0, 19);
  jit_retr(JIT_R0);           

  incr = jit_emit();
  jit_clear_state();

  /* call the generated code\, passing 5 as an argument */
  printf("%d + 19 = %d\n", 5, incr(5));

  jit_destroy_state();
  finish_jit();
  return 0;
}
