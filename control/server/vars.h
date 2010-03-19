//Spencer Krum + greghaynes for Pdx-rov
//GPL
//March 18, 2010



#include <request.c>
#include <client.h>
#include <hashtable.h>
#include <hashtable.c>

const int table_size;
const int num_motors;

struct key
{
    unsigned int val;
};

struct value
{
    char *id, char* motor_name, unsigned int (*motor_control);
};


DEFINE_HASHTABLE_INSERT(insert_some, struct key, struct value);
DEFINE_HASHTABLE_SEARCH(search_some, struct key, struct value);
DEFINE_HASHTABLE_REMOVE(remove_some, struct key, struct value);


unsigned int DJBHash(const * char str)
{
   unsigned int hash = 5381;
	int i;

   for(i = 0; *str[i]; i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return (hash & 0x7FFFFFFF);
}

static int
equalkeys(void *k1, void *k2)
{
    return (0 == memcmp(k1,k2,sizeof(struct key)));
}

 

void create_table(){
	struct key *k, *kk;
	struct value *v, *found;
    	struct hashtable *vars;
  	int i;


   	vars = create_hashtable(table_size, DJBHash, equalkeys);
   	if (NULL == h) {
       		printf("out of memory allocating hashtable\nor more likely spencer blew it hard");
	}
}

void populate_table(){
	for (i = 0; i < num_motors; ++i){
		k = (struct key *)malloc(sizeof(struct key));
        	if (NULL == k) {
            		printf("ran out of memory allocating a key\n");
            		return 1;
        	}
		k->val = 0xcfccee40 + i;

		v = (struct value *)malloc(sizeof(struct value));
        	v->id = "a value";
		v->motor_name = "a Motor name";
		v->motor_control = a_motor_control_function;
		
		if (!insert_some(h,k,v)) exit(-1); /*oom*/
   		}
   		printf("After insertion, hashtable contains %u items.\n",
           	hashtable_count(h));\
}

void search_table(){
    k = (struct key *)malloc(sizeof(struct key));
    if (NULL == k) {
        printf("ran out of memory allocating a key\n");
        return 1;
    }
    
    for (i = 0; i < num_motors; i++)
    {
   	k->val = 0xcfccee40 + i;
	
	
        if (NULL == (found = search_some(h,k))) {
            printf("BUG: key not found\n");
        }
    }

}

