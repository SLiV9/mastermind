typedef enum { RANDY, JIMMY, N_AI } AI;

typedef void (*init_func)();
typedef void (*guess_func)(code attempt);
typedef void (*reward_func)(score S);
typedef void (*end_func)();

init_func init[N_AI];
guess_func guess[N_AI];
reward_func reward[N_AI];
end_func end[N_AI];

/* Call this before using any AI. */
void ai_setup();

/* Check (ai_name[ai]) before using an AI. */
char* ai_name[N_AI];

/* Randy */
void random_guess(code attempt);

/* Jimmy */
void init_random_dlist();
void random_listed_guess(code attempt);
