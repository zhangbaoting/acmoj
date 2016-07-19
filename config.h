#define WAITING 0
#define COMPLIERING 10
#define RUNNING 9
#define CE 8
#define WA 5
#define TLE 3
#define OLE 7
#define RE 6
#define PE 2
#define AC 1
#define SYSTEM_ERR 11
#define MLE 4
#define RF 12 
#define STATUS_SIG 7
#define STATUS_AC 8
#define host "localhost"
#define user "root"
#define password ""
#define database "judgeonline"
#define MAXPOSIX 4
#define MAXPROBLEM 2000
//#define MAXTXTSIZE 

#include <sys/syscall.h>

int SYS_J[256]={SYS_ugetrlimit, SYS_rt_sigprocmask, SYS_futex, SYS_read, SYS_mmap2, SYS_stat64, SYS_open, SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_readlink, SYS_munmap, SYS_close, SYS_uname, SYS_clone, SYS_uname, SYS_mprotect, SYS_rt_sigaction, SYS_sigprocmask, SYS_getrlimit, SYS_fstat64, SYS_getuid32, SYS_getgid32, SYS_geteuid32, SYS_getegid32, SYS_set_thread_area, SYS_set_tid_address, SYS_set_robust_list, SYS_exit_group, 0};
int SYS_C[256]={SYS_read, SYS_uname, SYS_write, SYS_open, SYS_close, SYS_execve, SYS_access, SYS_brk, SYS_munmap, SYS_mprotect, SYS_mmap2, SYS_fstat64, SYS_set_thread_area, 252,0};

typedef struct {
	int solution_id;
	char user_id[30];
	int problem_id,contest_id;
    //double time,memory;
	double stime,ntime;
	double run_t,run_m;
	int language,result,num;
}Submits;

//提交的记录分为单个题目还是比赛中的题目
//单个题目用solution_id标识
//比赛中的题目用contest_id代表那场比赛中的哪个题目"A"+num
//num代表哪场比赛中的题目编号
struct probleminfo
{
    double time,memory;
    bool have;//这个problem_id的题目信息是否已经从数据库中获取过了
}pinfo[MAXPROBLEM];

inline void push(Submits *submit);
inline bool get_queue(Submits *submit);
inline void mysql_connection();
inline void stop();
inline void update_status(int getid,int id,int st);
inline void update_result(int getid,Submits *submit);
inline void update_submit_result(int getid,Submits *submit);
inline void update_user_problem_result(int getid,Submits *submit);
inline void update_contest_result(int getid,Submits *submit);
inline char get_letter(FILE *in);
inline bool is_letter(char a);
inline char get_letter(FILE *in);
inline bool check(FILE *in1,FILE *in2);
inline void create_pthread();
void *thread_work(void *arg);
inline bool judger(int getid,Submits *submit);
inline int get_nowmem(int a);
inline bool compile(int getid,Submits *submit);
inline void init();
inline  void get_pinfo(int getid,int problem_id);
