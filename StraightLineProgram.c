#include "slp.h"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
  A_stm s = checked_malloc(sizeof *s);
  s->kind = A_compoundStm;
  s->u.compound.stm1 = stm1;
  s->u.compound.stm2 = stm2;
  return s;
}

A_stm A_AssignStm(string id, A_exp exp){
  A_stm s = checked_malloc(sizeof *s);
  s->kind = A_assignStm;
  s->u.assign->id = id;
  s->u.assign->exp = exp;
  return s;
}

A_stm A_PrintStm(A_expList exps){
  A_stm s = checked_malloc(sizeof *s);
  s->kind = A_printStm;
  s->u.print->exps = exps;
}

A_exp A_IdExp(string id){
  A_exp e = checked_malloc(sizeof *e);
  e->kind = A_idExp;
  e->u.id = id;
  return e;
}

A_exp A_NumExp(int num){
  A_exp e = checked_malloc(sizeof *e);
  e->kind = A_numExp;
  e->u.num = num;
  return e;
}

A_exp A_OpExp(A_exp left, A_binop oper, A_exp right){
  A_exp e = checked_malloc(sizeof *e);
  e->kind = A_opExp;
  e->u.op->
}
