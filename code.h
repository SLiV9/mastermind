typedef enum { A, B, C, D, E, F, X } digit;
typedef digit code[4];

#define contains_(a,d) (a[0] == d || a[1] == d || a[2] == d || a[3] == d)
#define contains(a,d) (contains_((a),(d)))

typedef unsigned int score;

#define exacts(s) ((s) / 4)
#define abouts(s) ((s) % 4)

bool fill(code a, const char* str);
bool stringify(const code a, char* str);

score evaluate(const code attempt, const code master);
