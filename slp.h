#ifndef SLP_H
#define SLP_H
#include"util.h"
typedef struct A_stm_ *A_stm;
typedef struct A_exp_ *A_exp;
typedef struct A_expList_ *A_expList;
typedef enum {A_plus,A_minus,A_times,A_div} A_binop;

struct A_stm_ {enum {A_compoundStm, A_assignStm, A_printStm} kind;
             union {struct {A_stm stm1, stm2;} compound;
                    struct {string id; A_exp exp;} assign;
                    struct {A_expList exps;} print;
                   } u;
            };
A_stm A_CompoundStm(A_stm stm1, A_stm stm2);
A_stm A_AssignStm(string id, A_exp exp);
A_stm A_PrintStm(A_expList exps);

struct A_exp_ {enum {A_idExp, A_numExp, A_opExp, A_eseqExp} kind;
             union {string id;
                    int num;
                    struct {A_exp left; A_binop oper; A_exp right;} op;
                    struct {A_stm stm; A_exp exp;} eseq;
                   } u;
            };
A_exp A_IdExp(string id);
A_exp A_NumExp(int num);
A_exp A_OpExp(A_exp left, A_binop oper, A_exp right);
A_exp A_EseqExp(A_stm stm, A_exp exp);

struct A_expList_ {enum {A_pairExpList, A_lastExpList} kind;
                   union {struct {A_exp head; A_expList tail;} pair;
                          A_exp last;
                         } u;
                  };

A_expList A_PairExpList(A_exp head, A_expList tail);
A_expList A_LastExpList(A_exp last);


Table_ update(Table_ t, string index, int valueble);
int lookup(Table_ t, string key);
Table_ interpStm(A_stm s, Table_ t);

struct IntAndTable {
  int i;
  Table_ t;
};
struct IntAndTable interpExp(A_exp e, Table_ t);
struct IntAndTable interpExps(A_expList el,Table_ t);

/********************************************************
 *stack structure
 *******************************************************/
typedef struct Node{
  int s;
  struct Node * next;
}Node;


typedef struct Stack{
  Node * top;
}Stack;

Stack * creat_stack();
void push(Stack * S,int n);
Node * pop(Stack * S);

/******************end*********************************/
void maxargsExp(A_exp exp,Stack *S);
int maxargsExplist(A_expList el ,Stack *S);
void maxargsStm(A_stm stm,Stack *S);
int maxargs(A_stm);
void interp(A_stm);
#endif
