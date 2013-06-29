typedef enum { RANDY, N_AI } AI;

typedef void (*init_func)();
typedef void (*guess_func)(code attempt);
typedef void (*reward_func)(score S);
typedef void (*end_func)();

init_func init[N_AI];
guess_func guess[N_AI];
reward_func reward[N_AI];
end_func end[N_AI];

char* ai_name[N_AI];
