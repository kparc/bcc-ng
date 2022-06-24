#include"t.h"

#define SZ_NODE SZ(pNODE)
#define SZ_TRIE SZ(pTRIE)
#define SZ sizeof
#define sz size_t

typedef struct node{C key;V*val;struct node*parent;I depth;struct node*children[TRI_RANGE];}pNODE;
typedef pNODE*TN;typedef struct trie{UJ cnt;sz mem;TN root;}pTRIE;typedef pTRIE*T;
typedef V(*TFn)(TN n,V*arg,I depth); //< tri_each function interface

static TN tri_init_node(T t,C key){TN n=(TN)calloc(SZ_NODE,1);
 P(!n,O("trie oom"),NULL)n->key=key;t->mem+=SZ_NODE;R n;}

T tri_init(){T t=(T)malloc(SZ_TRIE);P(!t,O("trie oom\n"),NULL)
	t->mem+=SZ_TRIE,t->cnt=0,t->root=tri_init_node(t,0);R t;}

static TN tri_ins_at(T t,TN at,C key){C idx=key-TRI_RANGE_OFFSET;TN n=at->children[idx];
 if(!n){n=tri_init_node(t,key);P(!n,NULL)n->parent=at;at->children[idx]=n;}R n;}

static TN tri_paste(T t,S key,UJ n,V*val,C overwrite){P(!n,NULL)
	N(n,P(!IN(0,key[i]-TRI_RANGE_OFFSET,TRI_RANGE-1),O("trie out of range\n"),NULL))
	TN curr=t->root;N(n,curr=tri_ins_at(t,curr,key[i]))
	if(overwrite||!curr->val){curr->val=val;t->cnt++;}curr->depth=n;R curr;} //< depth <=> keylen

ZV tri_destroy_node(TN n,V*arg,I depth){free(n);}C tri_is_leaf(TN n){R!!n->val;}

TN tri_insert(T t,S key,sz n,V*val){R tri_paste(t,key,n,val,0);}
//TN tri_upsert(T t,S key,sz n,V*val){R tri_paste(t,key,n,val,1);}

TN tri_get(T t,S key){sz l=sl(key);P(!l,NULL)TN curr=t->root;C c,idx;
 N(l,c=key[i];idx=c-TRI_RANGE_OFFSET;P(!IN(0,idx,TRI_RANGE-1),NULL)P(!curr,NULL)
  curr=curr->children[idx])R curr;}

ZV tri_each_node(T t,TN curr,TFn fn,V*arg,I depth){fn(curr, arg, depth);
 N(TRI_RANGE,TN c=curr->children[i];if(c)tri_each_node(t,c,fn,arg,depth+1))}

ZV tri_each_node_reverse(T t,TN curr,TFn fn,V*arg,I depth){
	N(TRI_RANGE,TN c=curr->children[i];if(c)tri_each_node_reverse(t,c,fn,arg,depth+1))
	fn(curr,arg,depth);}

V tri_each_reverse(T t,TFn fn,V*arg){tri_each_node_reverse(t,t->root,fn,arg,0);}
sz tri_destroy(T t){tri_each_reverse(t,tri_destroy_node,NULL);sz r=t->mem;free(t);R r;}

static T KEYWORDS;
#define KW(x) N(CNT(x),tri_insert(KEYWORDS,(S)x[i],sl((S)x[i]),(V*)(J)c));c++;
V kw_lut_init(){KEYWORDS=tri_init();J c=0;KW(LP)KW(V0)KW(V1)KW(V2)KW(V3);}
K kw_lookup(S x){TN r=tri_get(KEYWORDS,x);R r?(K)r->val:NL;}

#ifdef RUN_TESTS_TRI

V kw_dump(S x){O("kw_dump %s -> %p\n",x,(V*)kw_lookup(x));}
V kw_test(){
 kw_dump("asdf"),kw_dump("W"),kw_dump("within"),
 kw_dump("calloc"),kw_dump("xexp"),kw_dump("mmu");}

V tri_each_from(T t,TN n,TFn fn,V*arg){if(!n)R;tri_each_node(t,n,fn,arg,0);}
V tri_each(T t,TFn fn,V*arg){tri_each_node(t,t->root,fn,arg,0);}
V tri_dump_node(TN n,V*arg,I depth){N(depth,O(" "))O("%c (%d, %d)\n",n->key,tri_is_leaf(n),n->depth);}
V tri_dump(T t){tri_each(t,tri_dump_node,NULL);}
V tri_dump_from(T t,TN n){tri_each_from(t,n,tri_dump_node,NULL);}
V tri_test_each(TN n,V*arg,I depth){O("key=(%c) depth=%d arg=%ld\n",n->key,depth,(J)arg);}

I main() {

	kw_lut_init();
	kw_test();
	exit(0);

	S keys[]={"abbot","abbey","abacus","abolition","abolitions","abortion","abort","zero"};

	T t=tri_init();P(!t,O("init trie oom\n"),1)

	N(8,if(!tri_insert(t,keys[i],sl(keys[i]),(V*)(J)i+42))R O("can't insert\n"),1)
	O("inserted %llu nodes\n",t->cnt);

	tri_dump(t);
	tri_each(t,tri_test_each,(V*)42);

	N(8,TN r=tri_get(t,keys[i]);
		P(!r,O("can't find trie entry\n"),1)
		O("found [%d] %ld\n",i, (J)r->val))

	tri_destroy(t);
	R 0;
}
#endif

//TRIE KEYWORDS = tri_init(); //< KIDW,KV0,KV1,KV2,KV3


//TRIE tri_init();
//NODE tri_insert(TRIE t,S key,UJ n,V*val);
//NODE tri_upsert(TRIE t,S key,UJ n,V*val);
//NODE tri_get(TRIE t,S key);
//C    tri_is_leaf(NODE n);
//V    tri_dump(TRIE t);
//V    tri_dump_from(TRIE t,NODE n);
//V    tri_each(TRIE t,TFn fn,V*arg);
//V    tri_each_from(TRIE t,NODE n,TFn fn,V*arg);
//V    tri_each_reverse(TRIE t, TFn fn, V*arg);
//sz tri_destroy(TRIE t);


//:~