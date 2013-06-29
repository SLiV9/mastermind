typedef enum { A, B, C, D, E, F } digit;

typedef digit code[4];

#define contains_(a,d) (a[0] == d || a[1] == d || a[2] == d || a[3] == d)
#define contains(a,d) (contains_((a),(d)))

void fill(code a, char* str);
void stringify(code a, char* str);
