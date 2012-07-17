#define GC_VARIABLE_STACK ((&scheme_thread_locals)->GC_variable_stack_)
#define GET_GC_VARIABLE_STACK() GC_VARIABLE_STACK
#define SET_GC_VARIABLE_STACK(v) (GC_VARIABLE_STACK = (v))
#define PREPARE_VAR_STACK(size) void *__gc_var_stack__[size+2]; __gc_var_stack__[0] = GET_GC_VARIABLE_STACK(); SET_GC_VARIABLE_STACK(__gc_var_stack__);
#define PREPARE_VAR_STACK_ONCE(size) PREPARE_VAR_STACK(size); __gc_var_stack__[1] = (void *)size;
#define SETUP(x) (__gc_var_stack__[1] = (void *)x)
#ifdef MZ_3M_CHECK_VAR_STACK
static int _bad_var_stack_() { *(long *)0x0 = 1; return 0; }
# define CHECK_GC_V_S ((GC_VARIABLE_STACK == __gc_var_stack__) ? 0 : _bad_var_stack_()),
#else
# define CHECK_GC_V_S /*empty*/
#endif
#define FUNCCALL_each(setup, x) (CHECK_GC_V_S setup, x)
#define FUNCCALL_EMPTY_each(x) (SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), x)
#define FUNCCALL_AGAIN_each(x) (CHECK_GC_V_S x)
#define FUNCCALL_once(setup, x) FUNCCALL_AGAIN_each(x)
#define FUNCCALL_EMPTY_once(x) FUNCCALL_EMPTY_each(x)
#define FUNCCALL_AGAIN_once(x) FUNCCALL_AGAIN_each(x)
#define PUSH(v, x) (__gc_var_stack__[x+2] = (void *)&(v))
#define PUSHARRAY(v, l, x) (__gc_var_stack__[x+2] = (void *)0, __gc_var_stack__[x+3] = (void *)&(v), __gc_var_stack__[x+4] = (void *)l)
#define BLOCK_SETUP_TOP(x) x
#define BLOCK_SETUP_each(x) BLOCK_SETUP_TOP(x)
#define BLOCK_SETUP_once(x) /* no effect */
#define RET_VALUE_START return (__ret__val__ = 
#define RET_VALUE_END , SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), __ret__val__)
#define RET_VALUE_EMPTY_START return
#define RET_VALUE_EMPTY_END 
#define RET_NOTHING { SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]); return; }
#define RET_NOTHING_AT_END RET_NOTHING
#define DECL_RET_SAVE(type) type __ret__val__;
#define NULLED_OUT 0
#define NULL_OUT_ARRAY(a) memset(a, 0, sizeof(a))
#define GC_CAN_IGNORE /**/
#define __xform_nongcing__ /**/
#define HIDE_FROM_XFORM(x) x
#define XFORM_HIDE_EXPR(x) x
#define HIDE_NOTHING_FROM_XFORM() /**/
#define START_XFORM_SKIP /**/
#define END_XFORM_SKIP /**/
#define START_XFORM_SUSPEND /**/
#define END_XFORM_SUSPEND /**/
#define XFORM_START_SKIP /**/
#define XFORM_END_SKIP /**/
#define XFORM_START_SUSPEND /**/
#define XFORM_END_SUSPEND /**/
#define XFORM_SKIP_PROC /**/
#define XFORM_OK_PLUS +
#define XFORM_OK_MINUS -
#define XFORM_TRUST_PLUS +
#define XFORM_TRUST_MINUS -
#define XFORM_OK_ASSIGN /**/

#define NEW_OBJ(t) new (UseGC) t
#define NEW_ARRAY(t, array) (new (UseGC) t array)
#define NEW_ATOM(t) (new (AtomicGC) t)
#define NEW_PTR(t) (new (UseGC) t)
#define NEW_ATOM_ARRAY(t, array) (new (AtomicGC) t array)
#define NEW_PTR_ARRAY(t, array) (new (UseGC) t* array)
#define DELETE(x) (delete x)
#define DELETE_ARRAY(x) (delete[] x)
#define XFORM_RESET_VAR_STACK /* empty */

typedef long unsigned int size_t ; 
typedef int wchar_t ; 
typedef signed char gint8 ; 
typedef unsigned char guint8 ; 
typedef signed short gint16 ; 
typedef unsigned short guint16 ; 
typedef signed int gint32 ; 
typedef unsigned int guint32 ; 
typedef signed long gint64 ; 
typedef unsigned long guint64 ; 
typedef signed long gssize ; 
typedef unsigned long gsize ; 
typedef gint64 goffset ; 
typedef int GPid ; 
typedef unsigned char __u_char ; 
typedef unsigned short int __u_short ; 
typedef unsigned int __u_int ; 
typedef unsigned long int __u_long ; 
typedef unsigned short int __uint16_t ; 
typedef unsigned int __uint32_t ; 
typedef unsigned long int __uint64_t ; 
typedef long int __quad_t ; 
typedef unsigned long int __u_quad_t ; 
typedef unsigned long int __dev_t ; 
typedef unsigned int __uid_t ; 
typedef unsigned int __gid_t ; 
typedef unsigned long int __ino_t ; 
typedef unsigned int __mode_t ; 
typedef unsigned long int __nlink_t ; 
typedef long int __off_t ; 
typedef long int __off64_t ; 
typedef int __pid_t ; 
typedef struct {
  int __val [2 ] ; 
}
__fsid_t ; 
typedef long int __clock_t ; 
typedef unsigned int __id_t ; 
typedef long int __time_t ; 
typedef unsigned int __useconds_t ; 
typedef long int __suseconds_t ; 
typedef int __daddr_t ; 
typedef int __key_t ; 
typedef int __clockid_t ; 
typedef void * __timer_t ; 
typedef long int __blksize_t ; 
typedef long int __blkcnt_t ; 
typedef unsigned long int __fsblkcnt_t ; 
typedef unsigned long int __fsfilcnt_t ; 
typedef long int __ssize_t ; 
typedef __off64_t __loff_t ; 
typedef char * __caddr_t ; 
typedef long int __intptr_t ; 
typedef unsigned int __socklen_t ; 
typedef __clock_t clock_t ; 
typedef __time_t time_t ; 
typedef __clockid_t clockid_t ; 
typedef __timer_t timer_t ; 
struct timespec {
  __time_t tv_sec ; 
  long int tv_nsec ; 
}
; 
struct tm {
  int tm_sec ; 
  int tm_min ; 
  int tm_hour ; 
  int tm_mday ; 
  int tm_mon ; 
  int tm_year ; 
  int tm_wday ; 
  int tm_yday ; 
  int tm_isdst ; 
  long int tm_gmtoff ; 
  __const char * tm_zone ; 
}
; 
struct itimerspec {
  struct timespec it_interval ; 
  struct timespec it_value ; 
}
; 
struct sigevent ; 
typedef __pid_t pid_t ; 
typedef struct __locale_struct {
  struct __locale_data * __locales [13 ] ; 
  const unsigned short int * __ctype_b ; 
  const int * __ctype_tolower ; 
  const int * __ctype_toupper ; 
  const char * __names [13 ] ; 
}
* __locale_t ; 
extern char * __tzname [2 ] ; 
extern char * tzname [2 ] ; 
typedef char gchar ; 
typedef long glong ; 
typedef int gint ; 
typedef gint gboolean ; 
typedef unsigned char guchar ; 
typedef unsigned short gushort ; 
typedef unsigned long gulong ; 
typedef unsigned int guint ; 
typedef float gfloat ; 
typedef double gdouble ; 
typedef void * gpointer ; 
typedef const void * gconstpointer ; 
typedef gint (* GCompareFunc ) (gconstpointer a , gconstpointer b ) ; 
typedef gint (* GCompareDataFunc ) (gconstpointer a , gconstpointer b , gpointer user_data ) ; 
typedef gboolean (* GEqualFunc ) (gconstpointer a , gconstpointer b ) ; 
typedef void (* GDestroyNotify ) (gpointer data ) ; 
typedef void (* GFunc ) (gpointer data , gpointer user_data ) ; 
typedef guint (* GHashFunc ) (gconstpointer key ) ; 
typedef void (* GHFunc ) (gpointer key , gpointer value , gpointer user_data ) ; 
typedef void (* GFreeFunc ) (gpointer data ) ; 
typedef const gchar * (* GTranslateFunc ) (const gchar * str , gpointer data ) ; 
union _GFloatIEEE754 {
  gfloat v_float ; 
  struct {
    guint mantissa : 23 ; 
    guint biased_exponent : 8 ; 
    guint sign : 1 ; 
  }
  mpn ; 
}
; 
union _GDoubleIEEE754 {
  gdouble v_double ; 
  struct {
    guint mantissa_low : 32 ; 
    guint mantissa_high : 20 ; 
    guint biased_exponent : 11 ; 
    guint sign : 1 ; 
  }
  mpn ; 
}
; 
typedef struct _GTimeVal GTimeVal ; 
struct _GTimeVal {
  glong tv_sec ; 
  glong tv_usec ; 
}
; 
typedef struct _GBytes GBytes ; 
typedef struct _GArray GArray ; 
typedef struct _GByteArray GByteArray ; 
typedef struct _GPtrArray GPtrArray ; 
struct _GArray {
  gchar * data ; 
  guint len ; 
}
; 
struct _GByteArray {
  guint8 * data ; 
  guint len ; 
}
; 
struct _GPtrArray {
  gpointer * pdata ; 
  guint len ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_atomic_add" "' instead" ) ) ) gint g_atomic_int_exchange_and_add (volatile gint * atomic , gint val ) ; 
typedef __builtin_va_list __gnuc_va_list ; 
typedef __gnuc_va_list va_list ; 
typedef guint32 GQuark ; 
typedef struct _GError GError ; 
struct _GError {
  GQuark domain ; 
  gint code ; 
  gchar * message ; 
}
; 
typedef enum {
  G_THREAD_ERROR_AGAIN }
GThreadError ; 
typedef gpointer (* GThreadFunc ) (gpointer data ) ; 
typedef struct _GThread GThread ; 
typedef union _GMutex GMutex ; 
typedef struct _GRecMutex GRecMutex ; 
typedef struct _GRWLock GRWLock ; 
typedef struct _GCond GCond ; 
typedef struct _GPrivate GPrivate ; 
typedef struct _GOnce GOnce ; 
union _GMutex {
  gpointer p ; 
  guint i [2 ] ; 
}
; 
struct _GRWLock {
  gpointer p ; 
  guint i [2 ] ; 
}
; 
struct _GCond {
  gpointer p ; 
  guint i [2 ] ; 
}
; 
struct _GRecMutex {
  gpointer p ; 
  guint i [2 ] ; 
}
; 
struct _GPrivate {
  gpointer p ; 
  GDestroyNotify notify ; 
  gpointer future [2 ] ; 
}
; 
typedef enum {
  G_ONCE_STATUS_NOTCALLED , G_ONCE_STATUS_PROGRESS , G_ONCE_STATUS_READY }
GOnceStatus ; 
struct _GOnce {
  volatile GOnceStatus status ; 
  volatile gpointer retval ; 
}
; 
typedef struct _GAsyncQueue GAsyncQueue ; 
__attribute__ ((__deprecated__ ("Use '" "g_async_queue_ref" "' instead" ) ) ) void g_async_queue_ref_unlocked (GAsyncQueue * queue ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_async_queue_unref" "' instead" ) ) ) void g_async_queue_unref_and_unlock (GAsyncQueue * queue ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_async_queue_timeout_pop" "' instead" ) ) ) gpointer g_async_queue_timed_pop (GAsyncQueue * queue , GTimeVal * end_time ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_async_queue_timeout_pop_unlocked" "' instead" ) ) ) gpointer g_async_queue_timed_pop_unlocked (GAsyncQueue * queue , GTimeVal * end_time ) ; 
typedef int __sig_atomic_t ; 
typedef struct {
  unsigned long int __val [(1024 / (8 * sizeof (unsigned long int ) ) ) ] ; 
}
__sigset_t ; 
typedef __sigset_t sigset_t ; 
typedef __uid_t uid_t ; 
typedef union sigval {
  int sival_int ; 
  void * sival_ptr ; 
}
sigval_t ; 
typedef struct siginfo {
  int si_signo ; 
  int si_errno ; 
  int si_code ; 
  union {
    int _pad [((128 / sizeof (int ) ) - 4 ) ] ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
    }
    _kill ; 
    struct {
      int si_tid ; 
      int si_overrun ; 
      sigval_t si_sigval ; 
    }
    _timer ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
      sigval_t si_sigval ; 
    }
    _rt ; 
    struct {
      __pid_t si_pid ; 
      __uid_t si_uid ; 
      int si_status ; 
      __clock_t si_utime ; 
      __clock_t si_stime ; 
    }
    _sigchld ; 
    struct {
      void * si_addr ; 
    }
    _sigfault ; 
    struct {
      long int si_band ; 
      int si_fd ; 
    }
    _sigpoll ; 
  }
  _sifields ; 
}
siginfo_t ; 
enum {
  SI_ASYNCNL = - 60 , SI_TKILL = - 6 , SI_SIGIO , SI_ASYNCIO , SI_MESGQ , SI_TIMER , SI_QUEUE , SI_USER , SI_KERNEL = 0x80 }
; 
enum {
  ILL_ILLOPC = 1 , ILL_ILLOPN , ILL_ILLADR , ILL_ILLTRP , ILL_PRVOPC , ILL_PRVREG , ILL_COPROC , ILL_BADSTK }
; 
enum {
  FPE_INTDIV = 1 , FPE_INTOVF , FPE_FLTDIV , FPE_FLTOVF , FPE_FLTUND , FPE_FLTRES , FPE_FLTINV , FPE_FLTSUB }
; 
enum {
  SEGV_MAPERR = 1 , SEGV_ACCERR }
; 
enum {
  BUS_ADRALN = 1 , BUS_ADRERR , BUS_OBJERR }
; 
enum {
  TRAP_BRKPT = 1 , TRAP_TRACE }
; 
enum {
  CLD_EXITED = 1 , CLD_KILLED , CLD_DUMPED , CLD_TRAPPED , CLD_STOPPED , CLD_CONTINUED }
; 
enum {
  POLL_IN = 1 , POLL_OUT , POLL_MSG , POLL_ERR , POLL_PRI , POLL_HUP }
; 
typedef struct sigevent {
  sigval_t sigev_value ; 
  int sigev_signo ; 
  int sigev_notify ; 
  union {
    int _pad [((64 / sizeof (int ) ) - 4 ) ] ; 
    __pid_t _tid ; 
    struct {
      void (* _function ) (sigval_t ) ; 
      void * _attribute ; 
    }
    _sigev_thread ; 
  }
  _sigev_un ; 
}
sigevent_t ; 
enum {
  SIGEV_SIGNAL = 0 , SIGEV_NONE , SIGEV_THREAD , SIGEV_THREAD_ID = 4 }
; 
typedef void (* __sighandler_t ) (int ) ; 
extern __sighandler_t signal (int __sig , __sighandler_t __handler ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
struct sigaction {
  union {
    __sighandler_t sa_handler ; 
    void (* sa_sigaction ) (int , siginfo_t * , void * ) ; 
  }
  __sigaction_handler ; 
  __sigset_t sa_mask ; 
  int sa_flags ; 
  void (* sa_restorer ) (void ) ; 
}
; 
extern int sigaction (int __sig , __const struct sigaction * __restrict __act , struct sigaction * __restrict __oact ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern __const char * __const _sys_siglist [65 ] ; 
extern __const char * __const sys_siglist [65 ] ; 
struct sigvec {
  __sighandler_t sv_handler ; 
  int sv_mask ; 
  int sv_flags ; 
}
; 
extern int sigvec (int __sig , __const struct sigvec * __vec , struct sigvec * __ovec ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
struct _fpreg {
  unsigned short significand [4 ] ; 
  unsigned short exponent ; 
}
; 
struct _fpxreg {
  unsigned short significand [4 ] ; 
  unsigned short exponent ; 
  unsigned short padding [3 ] ; 
}
; 
struct _xmmreg {
  __uint32_t element [4 ] ; 
}
; 
struct _fpstate {
  __uint16_t cwd ; 
  __uint16_t swd ; 
  __uint16_t ftw ; 
  __uint16_t fop ; 
  __uint64_t rip ; 
  __uint64_t rdp ; 
  __uint32_t mxcsr ; 
  __uint32_t mxcr_mask ; 
  struct _fpxreg _st [8 ] ; 
  struct _xmmreg _xmm [16 ] ; 
  __uint32_t padding [24 ] ; 
}
; 
struct sigcontext {
  unsigned long r8 ; 
  unsigned long r9 ; 
  unsigned long r10 ; 
  unsigned long r11 ; 
  unsigned long r12 ; 
  unsigned long r13 ; 
  unsigned long r14 ; 
  unsigned long r15 ; 
  unsigned long rdi ; 
  unsigned long rsi ; 
  unsigned long rbp ; 
  unsigned long rbx ; 
  unsigned long rdx ; 
  unsigned long rax ; 
  unsigned long rcx ; 
  unsigned long rsp ; 
  unsigned long rip ; 
  unsigned long eflags ; 
  unsigned short cs ; 
  unsigned short gs ; 
  unsigned short fs ; 
  unsigned short __pad0 ; 
  unsigned long err ; 
  unsigned long trapno ; 
  unsigned long oldmask ; 
  unsigned long cr2 ; 
  struct _fpstate * fpstate ; 
  unsigned long __reserved1 [8 ] ; 
}
; 
struct sigstack {
  void * ss_sp ; 
  int ss_onstack ; 
}
; 
enum {
  SS_ONSTACK = 1 , SS_DISABLE }
; 
typedef struct sigaltstack {
  void * ss_sp ; 
  int ss_flags ; 
  size_t ss_size ; 
}
stack_t ; 
typedef long int greg_t ; 
typedef greg_t gregset_t [23 ] ; 
struct _libc_fpxreg {
  unsigned short int significand [4 ] ; 
  unsigned short int exponent ; 
  unsigned short int padding [3 ] ; 
}
; 
struct _libc_xmmreg {
  __uint32_t element [4 ] ; 
}
; 
struct _libc_fpstate {
  __uint16_t cwd ; 
  __uint16_t swd ; 
  __uint16_t ftw ; 
  __uint16_t fop ; 
  __uint64_t rip ; 
  __uint64_t rdp ; 
  __uint32_t mxcsr ; 
  __uint32_t mxcr_mask ; 
  struct _libc_fpxreg _st [8 ] ; 
  struct _libc_xmmreg _xmm [16 ] ; 
  __uint32_t padding [24 ] ; 
}
; 
typedef struct _libc_fpstate * fpregset_t ; 
typedef struct {
  gregset_t gregs ; 
  fpregset_t fpregs ; 
  unsigned long __reserved1 [8 ] ; 
}
mcontext_t ; 
typedef struct ucontext {
  unsigned long int uc_flags ; 
  struct ucontext * uc_link ; 
  stack_t uc_stack ; 
  mcontext_t uc_mcontext ; 
  __sigset_t uc_sigmask ; 
  struct _libc_fpstate __fpregs_mem ; 
}
ucontext_t ; 
extern int sigstack (struct sigstack * __ss , struct sigstack * __oss ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__deprecated__ ) ) ; 
extern int sigaltstack (__const struct sigaltstack * __restrict __ss , struct sigaltstack * __restrict __oss ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
typedef unsigned long int pthread_t ; 
typedef union {
  char __size [56 ] ; 
  long int __align ; 
}
pthread_attr_t ; 
typedef struct __pthread_internal_list {
  struct __pthread_internal_list * __prev ; 
  struct __pthread_internal_list * __next ; 
}
__pthread_list_t ; 
typedef union {
  struct __pthread_mutex_s {
    int __lock ; 
    unsigned int __count ; 
    int __owner ; 
    unsigned int __nusers ; 
    int __kind ; 
    int __spins ; 
    __pthread_list_t __list ; 
  }
  __data ; 
  char __size [40 ] ; 
  long int __align ; 
}
pthread_mutex_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_mutexattr_t ; 
typedef union {
  struct {
    int __lock ; 
    unsigned int __futex ; 
    __extension__ unsigned long long int __total_seq ; 
    __extension__ unsigned long long int __wakeup_seq ; 
    __extension__ unsigned long long int __woken_seq ; 
    void * __mutex ; 
    unsigned int __nwaiters ; 
    unsigned int __broadcast_seq ; 
  }
  __data ; 
  char __size [48 ] ; 
  __extension__ long long int __align ; 
}
pthread_cond_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_condattr_t ; 
typedef unsigned int pthread_key_t ; 
typedef int pthread_once_t ; 
typedef union {
  struct {
    int __lock ; 
    unsigned int __nr_readers ; 
    unsigned int __readers_wakeup ; 
    unsigned int __writer_wakeup ; 
    unsigned int __nr_readers_queued ; 
    unsigned int __nr_writers_queued ; 
    int __writer ; 
    int __shared ; 
    unsigned long int __pad1 ; 
    unsigned long int __pad2 ; 
    unsigned int __flags ; 
  }
  __data ; 
  char __size [56 ] ; 
  long int __align ; 
}
pthread_rwlock_t ; 
typedef union {
  char __size [8 ] ; 
  long int __align ; 
}
pthread_rwlockattr_t ; 
typedef volatile int pthread_spinlock_t ; 
typedef union {
  char __size [32 ] ; 
  long int __align ; 
}
pthread_barrier_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_barrierattr_t ; 
typedef enum {
  G_BOOKMARK_FILE_ERROR_INVALID_URI , G_BOOKMARK_FILE_ERROR_INVALID_VALUE , G_BOOKMARK_FILE_ERROR_APP_NOT_REGISTERED , G_BOOKMARK_FILE_ERROR_URI_NOT_FOUND , G_BOOKMARK_FILE_ERROR_READ , G_BOOKMARK_FILE_ERROR_UNKNOWN_ENCODING , G_BOOKMARK_FILE_ERROR_WRITE , G_BOOKMARK_FILE_ERROR_FILE_NOT_FOUND }
GBookmarkFileError ; 
typedef struct _GBookmarkFile GBookmarkFile ; 
typedef enum {
  G_CHECKSUM_MD5 , G_CHECKSUM_SHA1 , G_CHECKSUM_SHA256 }
GChecksumType ; 
typedef struct _GChecksum GChecksum ; 
typedef enum {
  G_CONVERT_ERROR_NO_CONVERSION , G_CONVERT_ERROR_ILLEGAL_SEQUENCE , G_CONVERT_ERROR_FAILED , G_CONVERT_ERROR_PARTIAL_INPUT , G_CONVERT_ERROR_BAD_URI , G_CONVERT_ERROR_NOT_ABSOLUTE_PATH }
GConvertError ; 
typedef struct _GIConv * GIConv ; 
typedef struct _GData GData ; 
typedef void (* GDataForeachFunc ) (GQuark key_id , gpointer data , gpointer user_data ) ; 
typedef gint32 GTime ; 
typedef guint16 GDateYear ; 
typedef guint8 GDateDay ; 
typedef struct _GDate GDate ; 
typedef enum {
  G_DATE_DAY = 0 , G_DATE_MONTH = 1 , G_DATE_YEAR = 2 }
GDateDMY ; 
typedef enum {
  G_DATE_BAD_WEEKDAY = 0 , G_DATE_MONDAY = 1 , G_DATE_TUESDAY = 2 , G_DATE_WEDNESDAY = 3 , G_DATE_THURSDAY = 4 , G_DATE_FRIDAY = 5 , G_DATE_SATURDAY = 6 , G_DATE_SUNDAY = 7 }
GDateWeekday ; 
typedef enum {
  G_DATE_BAD_MONTH = 0 , G_DATE_JANUARY = 1 , G_DATE_FEBRUARY = 2 , G_DATE_MARCH = 3 , G_DATE_APRIL = 4 , G_DATE_MAY = 5 , G_DATE_JUNE = 6 , G_DATE_JULY = 7 , G_DATE_AUGUST = 8 , G_DATE_SEPTEMBER = 9 , G_DATE_OCTOBER = 10 , G_DATE_NOVEMBER = 11 , G_DATE_DECEMBER = 12 }
GDateMonth ; 
struct _GDate {
  guint julian_days : 32 ; 
  guint julian : 1 ; 
  guint dmy : 1 ; 
  guint day : 6 ; 
  guint month : 4 ; 
  guint year : 16 ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_date_set_time_t" "' instead" ) ) ) void g_date_set_time (GDate * date , GTime time_ ) ; 
typedef struct _GTimeZone GTimeZone ; 
typedef enum {
  G_TIME_TYPE_STANDARD , G_TIME_TYPE_DAYLIGHT , G_TIME_TYPE_UNIVERSAL }
GTimeType ; 
typedef gint64 GTimeSpan ; 
typedef struct _GDateTime GDateTime ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add (GDateTime * datetime , GTimeSpan timespan ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_years (GDateTime * datetime , gint years ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_months (GDateTime * datetime , gint months ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_weeks (GDateTime * datetime , gint weeks ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_days (GDateTime * datetime , gint days ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_hours (GDateTime * datetime , gint hours ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_minutes (GDateTime * datetime , gint minutes ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_seconds (GDateTime * datetime , gdouble seconds ) ; 
__attribute__ ((warn_unused_result ) ) GDateTime * g_date_time_add_full (GDateTime * datetime , gint years , gint months , gint days , gint hours , gint minutes , gdouble seconds ) ; 
typedef struct _GDir GDir ; 
typedef enum {
  G_FILE_ERROR_EXIST , G_FILE_ERROR_ISDIR , G_FILE_ERROR_ACCES , G_FILE_ERROR_NAMETOOLONG , G_FILE_ERROR_NOENT , G_FILE_ERROR_NOTDIR , G_FILE_ERROR_NXIO , G_FILE_ERROR_NODEV , G_FILE_ERROR_ROFS , G_FILE_ERROR_TXTBSY , G_FILE_ERROR_FAULT , G_FILE_ERROR_LOOP , G_FILE_ERROR_NOSPC , G_FILE_ERROR_NOMEM , G_FILE_ERROR_MFILE , G_FILE_ERROR_NFILE , G_FILE_ERROR_BADF , G_FILE_ERROR_INVAL , G_FILE_ERROR_PIPE , G_FILE_ERROR_AGAIN , G_FILE_ERROR_INTR , G_FILE_ERROR_IO , G_FILE_ERROR_PERM , G_FILE_ERROR_NOSYS , G_FILE_ERROR_FAILED }
GFileError ; 
typedef enum {
  G_FILE_TEST_IS_REGULAR = 1 << 0 , G_FILE_TEST_IS_SYMLINK = 1 << 1 , G_FILE_TEST_IS_DIR = 1 << 2 , G_FILE_TEST_IS_EXECUTABLE = 1 << 3 , G_FILE_TEST_EXISTS = 1 << 4 }
GFileTest ; 
__attribute__ ((__deprecated__ ("Use '" "g_path_get_basename" "' instead" ) ) ) const gchar * g_basename (const gchar * file_name ) ; 
typedef struct _GMemVTable GMemVTable ; 
struct _GMemVTable {
  gpointer (* malloc ) (gsize n_bytes ) ; 
  gpointer (* realloc ) (gpointer mem , gsize n_bytes ) ; 
  void (* free ) (gpointer mem ) ; 
  gpointer (* calloc ) (gsize n_blocks , gsize n_block_bytes ) ; 
  gpointer (* try_malloc ) (gsize n_bytes ) ; 
  gpointer (* try_realloc ) (gpointer mem , gsize n_bytes ) ; 
}
; 
typedef struct _GList GList ; 
struct _GList {
  gpointer data ; 
  GList * next ; 
  GList * prev ; 
}
; 
typedef struct _GHashTable GHashTable ; 
typedef gboolean (* GHRFunc ) (gpointer key , gpointer value , gpointer user_data ) ; 
typedef struct _GHashTableIter GHashTableIter ; 
struct _GHashTableIter {
  gpointer dummy1 ; 
  gpointer dummy2 ; 
  gpointer dummy3 ; 
  int dummy4 ; 
  gboolean dummy5 ; 
  gpointer dummy6 ; 
}
; 
typedef struct _GHmac GHmac ; 
typedef struct _GHook GHook ; 
typedef struct _GHookList GHookList ; 
typedef gint (* GHookCompareFunc ) (GHook * new_hook , GHook * sibling ) ; 
typedef gboolean (* GHookFindFunc ) (GHook * hook , gpointer data ) ; 
typedef void (* GHookMarshaller ) (GHook * hook , gpointer marshal_data ) ; 
typedef gboolean (* GHookCheckMarshaller ) (GHook * hook , gpointer marshal_data ) ; 
typedef void (* GHookFunc ) (gpointer data ) ; 
typedef gboolean (* GHookCheckFunc ) (gpointer data ) ; 
typedef void (* GHookFinalizeFunc ) (GHookList * hook_list , GHook * hook ) ; 
typedef enum {
  G_HOOK_FLAG_ACTIVE = 1 << 0 , G_HOOK_FLAG_IN_CALL = 1 << 1 , G_HOOK_FLAG_MASK = 0x0f }
GHookFlagMask ; 
struct _GHookList {
  gulong seq_id ; 
  guint hook_size : 16 ; 
  guint is_setup : 1 ; 
  GHook * hooks ; 
  gpointer dummy3 ; 
  GHookFinalizeFunc finalize_hook ; 
  gpointer dummy [2 ] ; 
}
; 
struct _GHook {
  gpointer data ; 
  GHook * next ; 
  GHook * prev ; 
  guint ref_count ; 
  gulong hook_id ; 
  guint flags ; 
  gpointer func ; 
  GDestroyNotify destroy ; 
}
; 
typedef struct _GPollFD GPollFD ; 
typedef gint (* GPollFunc ) (GPollFD * ufds , guint nfsd , gint timeout_ ) ; 
struct _GPollFD {
  gint fd ; 
  gushort events ; 
  gushort revents ; 
}
; 
typedef struct _GSList GSList ; 
struct _GSList {
  gpointer data ; 
  GSList * next ; 
}
; 
typedef struct _GMainContext GMainContext ; 
typedef struct _GMainLoop GMainLoop ; 
typedef struct _GSource GSource ; 
typedef struct _GSourcePrivate GSourcePrivate ; 
typedef struct _GSourceCallbackFuncs GSourceCallbackFuncs ; 
typedef struct _GSourceFuncs GSourceFuncs ; 
typedef gboolean (* GSourceFunc ) (gpointer user_data ) ; 
typedef void (* GChildWatchFunc ) (GPid pid , gint status , gpointer user_data ) ; 
struct _GSource {
  gpointer callback_data ; 
  GSourceCallbackFuncs * callback_funcs ; 
  GSourceFuncs * source_funcs ; 
  guint ref_count ; 
  GMainContext * context ; 
  gint priority ; 
  guint flags ; 
  guint source_id ; 
  GSList * poll_fds ; 
  GSource * prev ; 
  GSource * next ; 
  char * name ; 
  GSourcePrivate * priv ; 
}
; 
struct _GSourceCallbackFuncs {
  void (* ref ) (gpointer cb_data ) ; 
  void (* unref ) (gpointer cb_data ) ; 
  void (* get ) (gpointer cb_data , GSource * source , GSourceFunc * func , gpointer * data ) ; 
}
; 
typedef void (* GSourceDummyMarshal ) (void ) ; 
struct _GSourceFuncs {
  gboolean (* prepare ) (GSource * source , gint * timeout_ ) ; 
  gboolean (* check ) (GSource * source ) ; 
  gboolean (* dispatch ) (GSource * source , GSourceFunc callback , gpointer user_data ) ; 
  void (* finalize ) (GSource * source ) ; 
  GSourceFunc closure_callback ; 
  GSourceDummyMarshal closure_marshal ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_source_get_time" "' instead" ) ) ) void g_source_get_current_time (GSource * source , GTimeVal * timeval ) ; 
typedef guint32 gunichar ; 
typedef guint16 gunichar2 ; 
typedef enum {
  G_UNICODE_CONTROL , G_UNICODE_FORMAT , G_UNICODE_UNASSIGNED , G_UNICODE_PRIVATE_USE , G_UNICODE_SURROGATE , G_UNICODE_LOWERCASE_LETTER , G_UNICODE_MODIFIER_LETTER , G_UNICODE_OTHER_LETTER , G_UNICODE_TITLECASE_LETTER , G_UNICODE_UPPERCASE_LETTER , G_UNICODE_SPACING_MARK , G_UNICODE_ENCLOSING_MARK , G_UNICODE_NON_SPACING_MARK , G_UNICODE_DECIMAL_NUMBER , G_UNICODE_LETTER_NUMBER , G_UNICODE_OTHER_NUMBER , G_UNICODE_CONNECT_PUNCTUATION , G_UNICODE_DASH_PUNCTUATION , G_UNICODE_CLOSE_PUNCTUATION , G_UNICODE_FINAL_PUNCTUATION , G_UNICODE_INITIAL_PUNCTUATION , G_UNICODE_OTHER_PUNCTUATION , G_UNICODE_OPEN_PUNCTUATION , G_UNICODE_CURRENCY_SYMBOL , G_UNICODE_MODIFIER_SYMBOL , G_UNICODE_MATH_SYMBOL , G_UNICODE_OTHER_SYMBOL , G_UNICODE_LINE_SEPARATOR , G_UNICODE_PARAGRAPH_SEPARATOR , G_UNICODE_SPACE_SEPARATOR }
GUnicodeType ; 
typedef enum {
  G_UNICODE_BREAK_MANDATORY , G_UNICODE_BREAK_CARRIAGE_RETURN , G_UNICODE_BREAK_LINE_FEED , G_UNICODE_BREAK_COMBINING_MARK , G_UNICODE_BREAK_SURROGATE , G_UNICODE_BREAK_ZERO_WIDTH_SPACE , G_UNICODE_BREAK_INSEPARABLE , G_UNICODE_BREAK_NON_BREAKING_GLUE , G_UNICODE_BREAK_CONTINGENT , G_UNICODE_BREAK_SPACE , G_UNICODE_BREAK_AFTER , G_UNICODE_BREAK_BEFORE , G_UNICODE_BREAK_BEFORE_AND_AFTER , G_UNICODE_BREAK_HYPHEN , G_UNICODE_BREAK_NON_STARTER , G_UNICODE_BREAK_OPEN_PUNCTUATION , G_UNICODE_BREAK_CLOSE_PUNCTUATION , G_UNICODE_BREAK_QUOTATION , G_UNICODE_BREAK_EXCLAMATION , G_UNICODE_BREAK_IDEOGRAPHIC , G_UNICODE_BREAK_NUMERIC , G_UNICODE_BREAK_INFIX_SEPARATOR , G_UNICODE_BREAK_SYMBOL , G_UNICODE_BREAK_ALPHABETIC , G_UNICODE_BREAK_PREFIX , G_UNICODE_BREAK_POSTFIX , G_UNICODE_BREAK_COMPLEX_CONTEXT , G_UNICODE_BREAK_AMBIGUOUS , G_UNICODE_BREAK_UNKNOWN , G_UNICODE_BREAK_NEXT_LINE , G_UNICODE_BREAK_WORD_JOINER , G_UNICODE_BREAK_HANGUL_L_JAMO , G_UNICODE_BREAK_HANGUL_V_JAMO , G_UNICODE_BREAK_HANGUL_T_JAMO , G_UNICODE_BREAK_HANGUL_LV_SYLLABLE , G_UNICODE_BREAK_HANGUL_LVT_SYLLABLE , G_UNICODE_BREAK_CLOSE_PARANTHESIS , G_UNICODE_BREAK_CONDITIONAL_JAPANESE_STARTER , G_UNICODE_BREAK_HEBREW_LETTER }
GUnicodeBreakType ; 
typedef enum {
  G_UNICODE_SCRIPT_INVALID_CODE = - 1 , G_UNICODE_SCRIPT_COMMON = 0 , G_UNICODE_SCRIPT_INHERITED , G_UNICODE_SCRIPT_ARABIC , G_UNICODE_SCRIPT_ARMENIAN , G_UNICODE_SCRIPT_BENGALI , G_UNICODE_SCRIPT_BOPOMOFO , G_UNICODE_SCRIPT_CHEROKEE , G_UNICODE_SCRIPT_COPTIC , G_UNICODE_SCRIPT_CYRILLIC , G_UNICODE_SCRIPT_DESERET , G_UNICODE_SCRIPT_DEVANAGARI , G_UNICODE_SCRIPT_ETHIOPIC , G_UNICODE_SCRIPT_GEORGIAN , G_UNICODE_SCRIPT_GOTHIC , G_UNICODE_SCRIPT_GREEK , G_UNICODE_SCRIPT_GUJARATI , G_UNICODE_SCRIPT_GURMUKHI , G_UNICODE_SCRIPT_HAN , G_UNICODE_SCRIPT_HANGUL , G_UNICODE_SCRIPT_HEBREW , G_UNICODE_SCRIPT_HIRAGANA , G_UNICODE_SCRIPT_KANNADA , G_UNICODE_SCRIPT_KATAKANA , G_UNICODE_SCRIPT_KHMER , G_UNICODE_SCRIPT_LAO , G_UNICODE_SCRIPT_LATIN , G_UNICODE_SCRIPT_MALAYALAM , G_UNICODE_SCRIPT_MONGOLIAN , G_UNICODE_SCRIPT_MYANMAR , G_UNICODE_SCRIPT_OGHAM , G_UNICODE_SCRIPT_OLD_ITALIC , G_UNICODE_SCRIPT_ORIYA , G_UNICODE_SCRIPT_RUNIC , G_UNICODE_SCRIPT_SINHALA , G_UNICODE_SCRIPT_SYRIAC , G_UNICODE_SCRIPT_TAMIL , G_UNICODE_SCRIPT_TELUGU , G_UNICODE_SCRIPT_THAANA , G_UNICODE_SCRIPT_THAI , G_UNICODE_SCRIPT_TIBETAN , G_UNICODE_SCRIPT_CANADIAN_ABORIGINAL , G_UNICODE_SCRIPT_YI , G_UNICODE_SCRIPT_TAGALOG , G_UNICODE_SCRIPT_HANUNOO , G_UNICODE_SCRIPT_BUHID , G_UNICODE_SCRIPT_TAGBANWA , G_UNICODE_SCRIPT_BRAILLE , G_UNICODE_SCRIPT_CYPRIOT , G_UNICODE_SCRIPT_LIMBU , G_UNICODE_SCRIPT_OSMANYA , G_UNICODE_SCRIPT_SHAVIAN , G_UNICODE_SCRIPT_LINEAR_B , G_UNICODE_SCRIPT_TAI_LE , G_UNICODE_SCRIPT_UGARITIC , G_UNICODE_SCRIPT_NEW_TAI_LUE , G_UNICODE_SCRIPT_BUGINESE , G_UNICODE_SCRIPT_GLAGOLITIC , G_UNICODE_SCRIPT_TIFINAGH , G_UNICODE_SCRIPT_SYLOTI_NAGRI , G_UNICODE_SCRIPT_OLD_PERSIAN , G_UNICODE_SCRIPT_KHAROSHTHI , G_UNICODE_SCRIPT_UNKNOWN , G_UNICODE_SCRIPT_BALINESE , G_UNICODE_SCRIPT_CUNEIFORM , G_UNICODE_SCRIPT_PHOENICIAN , G_UNICODE_SCRIPT_PHAGS_PA , G_UNICODE_SCRIPT_NKO , G_UNICODE_SCRIPT_KAYAH_LI , G_UNICODE_SCRIPT_LEPCHA , G_UNICODE_SCRIPT_REJANG , G_UNICODE_SCRIPT_SUNDANESE , G_UNICODE_SCRIPT_SAURASHTRA , G_UNICODE_SCRIPT_CHAM , G_UNICODE_SCRIPT_OL_CHIKI , G_UNICODE_SCRIPT_VAI , G_UNICODE_SCRIPT_CARIAN , G_UNICODE_SCRIPT_LYCIAN , G_UNICODE_SCRIPT_LYDIAN , G_UNICODE_SCRIPT_AVESTAN , G_UNICODE_SCRIPT_BAMUM , G_UNICODE_SCRIPT_EGYPTIAN_HIEROGLYPHS , G_UNICODE_SCRIPT_IMPERIAL_ARAMAIC , G_UNICODE_SCRIPT_INSCRIPTIONAL_PAHLAVI , G_UNICODE_SCRIPT_INSCRIPTIONAL_PARTHIAN , G_UNICODE_SCRIPT_JAVANESE , G_UNICODE_SCRIPT_KAITHI , G_UNICODE_SCRIPT_LISU , G_UNICODE_SCRIPT_MEETEI_MAYEK , G_UNICODE_SCRIPT_OLD_SOUTH_ARABIAN , G_UNICODE_SCRIPT_OLD_TURKIC , G_UNICODE_SCRIPT_SAMARITAN , G_UNICODE_SCRIPT_TAI_THAM , G_UNICODE_SCRIPT_TAI_VIET , G_UNICODE_SCRIPT_BATAK , G_UNICODE_SCRIPT_BRAHMI , G_UNICODE_SCRIPT_MANDAIC , G_UNICODE_SCRIPT_CHAKMA , G_UNICODE_SCRIPT_MEROITIC_CURSIVE , G_UNICODE_SCRIPT_MEROITIC_HIEROGLYPHS , G_UNICODE_SCRIPT_MIAO , G_UNICODE_SCRIPT_SHARADA , G_UNICODE_SCRIPT_SORA_SOMPENG , G_UNICODE_SCRIPT_TAKRI }
GUnicodeScript ; 
__attribute__ ((__deprecated__ ) ) gunichar * g_unicode_canonical_decomposition (gunichar ch , gsize * result_len ) __attribute__ ((__malloc__ ) ) ; 
typedef enum {
  G_NORMALIZE_DEFAULT , G_NORMALIZE_NFD = G_NORMALIZE_DEFAULT , G_NORMALIZE_DEFAULT_COMPOSE , G_NORMALIZE_NFC = G_NORMALIZE_DEFAULT_COMPOSE , G_NORMALIZE_ALL , G_NORMALIZE_NFKD = G_NORMALIZE_ALL , G_NORMALIZE_ALL_COMPOSE , G_NORMALIZE_NFKC = G_NORMALIZE_ALL_COMPOSE }
GNormalizeMode ; 
typedef enum {
  G_USER_DIRECTORY_DESKTOP , G_USER_DIRECTORY_DOCUMENTS , G_USER_DIRECTORY_DOWNLOAD , G_USER_DIRECTORY_MUSIC , G_USER_DIRECTORY_PICTURES , G_USER_DIRECTORY_PUBLIC_SHARE , G_USER_DIRECTORY_TEMPLATES , G_USER_DIRECTORY_VIDEOS , G_USER_N_DIRECTORIES }
GUserDirectory ; 
typedef struct _GDebugKey GDebugKey ; 
struct _GDebugKey {
  const gchar * key ; 
  guint value ; 
}
; 
typedef enum {
  G_FORMAT_SIZE_DEFAULT = 0 , G_FORMAT_SIZE_LONG_FORMAT = 1 << 0 , G_FORMAT_SIZE_IEC_UNITS = 1 << 1 }
GFormatSizeFlags ; 
__attribute__ ((__deprecated__ ("Use '" "g_format_size" "' instead" ) ) ) gchar * g_format_size_for_display (goffset size ) ; 
typedef void (* GVoidFunc ) (void ) ; 
__attribute__ ((__deprecated__ ) ) void g_atexit (GVoidFunc func ) ; 
static __inline __attribute__ ((unused ) ) gint g_bit_nth_lsf (gulong mask , gint nth_bit ) __attribute__ ((__const__ ) ) ; 
static __inline __attribute__ ((unused ) ) gint g_bit_nth_msf (gulong mask , gint nth_bit ) __attribute__ ((__const__ ) ) ; 
static __inline __attribute__ ((unused ) ) guint g_bit_storage (gulong number ) __attribute__ ((__const__ ) ) ; 
static __inline __attribute__ ((unused ) ) gint g_bit_nth_lsf (gulong mask , gint nth_bit ) {
  if ((nth_bit < - 1 ) )
    nth_bit = - 1 ; 
  while (nth_bit < ((8 * 8 ) - 1 ) ) {
    nth_bit ++ ; 
    if (mask & (1UL << nth_bit ) )
      return nth_bit ; 
  }
  return - 1 ; 
}
static __inline __attribute__ ((unused ) ) gint g_bit_nth_msf (gulong mask , gint nth_bit ) {
  if (nth_bit < 0 || (nth_bit > 8 * 8 ) )
    nth_bit = 8 * 8 ; 
  while (nth_bit > 0 ) {
    nth_bit -- ; 
    if (mask & (1UL << nth_bit ) )
      return nth_bit ; 
  }
  return - 1 ; 
}
static __inline __attribute__ ((unused ) ) guint g_bit_storage (gulong number ) {
  register guint n_bits = 0 ; 
  do {
    n_bits ++ ; 
    number >>= 1 ; 
  }
  while (number ) ; 
  return n_bits ; 
}
typedef struct _GString GString ; 
struct _GString {
  gchar * str ; 
  gsize len ; 
  gsize allocated_len ; 
}
; 
GString * g_string_insert_c (GString * string , gssize pos , gchar c ) ; 
static inline GString * g_string_append_c_inline (GString * gstring , gchar c ) {
  if (gstring -> len + 1 < gstring -> allocated_len ) {
    gstring -> str [gstring -> len ++ ] = c ; 
    gstring -> str [gstring -> len ] = 0 ; 
  }
  else g_string_insert_c (gstring , - 1 , c ) ; 
  return gstring ; 
}
__attribute__ ((__deprecated__ ) ) GString * g_string_down (GString * string ) ; 
__attribute__ ((__deprecated__ ) ) GString * g_string_up (GString * string ) ; 
typedef struct _GIOChannel GIOChannel ; 
typedef struct _GIOFuncs GIOFuncs ; 
typedef enum {
  G_IO_ERROR_NONE , G_IO_ERROR_AGAIN , G_IO_ERROR_INVAL , G_IO_ERROR_UNKNOWN }
GIOError ; 
typedef enum {
  G_IO_CHANNEL_ERROR_FBIG , G_IO_CHANNEL_ERROR_INVAL , G_IO_CHANNEL_ERROR_IO , G_IO_CHANNEL_ERROR_ISDIR , G_IO_CHANNEL_ERROR_NOSPC , G_IO_CHANNEL_ERROR_NXIO , G_IO_CHANNEL_ERROR_OVERFLOW , G_IO_CHANNEL_ERROR_PIPE , G_IO_CHANNEL_ERROR_FAILED }
GIOChannelError ; 
typedef enum {
  G_IO_STATUS_ERROR , G_IO_STATUS_NORMAL , G_IO_STATUS_EOF , G_IO_STATUS_AGAIN }
GIOStatus ; 
typedef enum {
  G_SEEK_CUR , G_SEEK_SET , G_SEEK_END }
GSeekType ; 
typedef enum {
  G_IO_IN = 1 , G_IO_OUT = 4 , G_IO_PRI = 2 , G_IO_ERR = 8 , G_IO_HUP = 16 , G_IO_NVAL = 32 }
GIOCondition ; 
typedef enum {
  G_IO_FLAG_APPEND = 1 << 0 , G_IO_FLAG_NONBLOCK = 1 << 1 , G_IO_FLAG_IS_READABLE = 1 << 2 , G_IO_FLAG_IS_WRITABLE = 1 << 3 , G_IO_FLAG_IS_SEEKABLE = 1 << 4 , G_IO_FLAG_MASK = (1 << 5 ) - 1 , G_IO_FLAG_GET_MASK = G_IO_FLAG_MASK , G_IO_FLAG_SET_MASK = G_IO_FLAG_APPEND | G_IO_FLAG_NONBLOCK }
GIOFlags ; 
struct _GIOChannel {
  gint ref_count ; 
  GIOFuncs * funcs ; 
  gchar * encoding ; 
  GIConv read_cd ; 
  GIConv write_cd ; 
  gchar * line_term ; 
  guint line_term_len ; 
  gsize buf_size ; 
  GString * read_buf ; 
  GString * encoded_read_buf ; 
  GString * write_buf ; 
  gchar partial_write_buf [6 ] ; 
  guint use_buffer : 1 ; 
  guint do_encode : 1 ; 
  guint close_on_unref : 1 ; 
  guint is_readable : 1 ; 
  guint is_writeable : 1 ; 
  guint is_seekable : 1 ; 
  gpointer reserved1 ; 
  gpointer reserved2 ; 
}
; 
typedef gboolean (* GIOFunc ) (GIOChannel * source , GIOCondition condition , gpointer data ) ; 
struct _GIOFuncs {
  GIOStatus (* io_read ) (GIOChannel * channel , gchar * buf , gsize count , gsize * bytes_read , GError * * err ) ; 
  GIOStatus (* io_write ) (GIOChannel * channel , const gchar * buf , gsize count , gsize * bytes_written , GError * * err ) ; 
  GIOStatus (* io_seek ) (GIOChannel * channel , gint64 offset , GSeekType type , GError * * err ) ; 
  GIOStatus (* io_close ) (GIOChannel * channel , GError * * err ) ; 
  GSource * (* io_create_watch ) (GIOChannel * channel , GIOCondition condition ) ; 
  void (* io_free ) (GIOChannel * channel ) ; 
  GIOStatus (* io_set_flags ) (GIOChannel * channel , GIOFlags flags , GError * * err ) ; 
  GIOFlags (* io_get_flags ) (GIOChannel * channel ) ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_io_channel_read_for" "' instead" ) ) ) GIOError g_io_channel_read (GIOChannel * channel , gchar * buf , gsize count , gsize * bytes_read ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_io_channel_write_chars" "' instead" ) ) ) GIOError g_io_channel_write (GIOChannel * channel , const gchar * buf , gsize count , gsize * bytes_written ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_io_channel_seek_position" "' instead" ) ) ) GIOError g_io_channel_seek (GIOChannel * channel , gint64 offset , GSeekType type ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_io_channel_shutdown" "' instead" ) ) ) void g_io_channel_close (GIOChannel * channel ) ; 
typedef enum {
  G_KEY_FILE_ERROR_UNKNOWN_ENCODING , G_KEY_FILE_ERROR_PARSE , G_KEY_FILE_ERROR_NOT_FOUND , G_KEY_FILE_ERROR_KEY_NOT_FOUND , G_KEY_FILE_ERROR_GROUP_NOT_FOUND , G_KEY_FILE_ERROR_INVALID_VALUE }
GKeyFileError ; 
typedef struct _GKeyFile GKeyFile ; 
typedef enum {
  G_KEY_FILE_NONE = 0 , G_KEY_FILE_KEEP_COMMENTS = 1 << 0 , G_KEY_FILE_KEEP_TRANSLATIONS = 1 << 1 }
GKeyFileFlags ; 
typedef struct _GMappedFile GMappedFile ; 
__attribute__ ((__deprecated__ ("Use '" "g_mapped_file_unref" "' instead" ) ) ) void g_mapped_file_free (GMappedFile * file ) ; 
typedef enum {
  G_MARKUP_ERROR_BAD_UTF8 , G_MARKUP_ERROR_EMPTY , G_MARKUP_ERROR_PARSE , G_MARKUP_ERROR_UNKNOWN_ELEMENT , G_MARKUP_ERROR_UNKNOWN_ATTRIBUTE , G_MARKUP_ERROR_INVALID_CONTENT , G_MARKUP_ERROR_MISSING_ATTRIBUTE }
GMarkupError ; 
typedef enum {
  G_MARKUP_DO_NOT_USE_THIS_UNSUPPORTED_FLAG = 1 << 0 , G_MARKUP_TREAT_CDATA_AS_TEXT = 1 << 1 , G_MARKUP_PREFIX_ERROR_POSITION = 1 << 2 }
GMarkupParseFlags ; 
typedef struct _GMarkupParseContext GMarkupParseContext ; 
typedef struct _GMarkupParser GMarkupParser ; 
struct _GMarkupParser {
  void (* start_element ) (GMarkupParseContext * context , const gchar * element_name , const gchar * * attribute_names , const gchar * * attribute_values , gpointer user_data , GError * * error ) ; 
  void (* end_element ) (GMarkupParseContext * context , const gchar * element_name , gpointer user_data , GError * * error ) ; 
  void (* text ) (GMarkupParseContext * context , const gchar * text , gsize text_len , gpointer user_data , GError * * error ) ; 
  void (* passthrough ) (GMarkupParseContext * context , const gchar * passthrough_text , gsize text_len , gpointer user_data , GError * * error ) ; 
  void (* error ) (GMarkupParseContext * context , GError * error , gpointer user_data ) ; 
}
; 
typedef enum {
  G_MARKUP_COLLECT_INVALID , G_MARKUP_COLLECT_STRING , G_MARKUP_COLLECT_STRDUP , G_MARKUP_COLLECT_BOOLEAN , G_MARKUP_COLLECT_TRISTATE , G_MARKUP_COLLECT_OPTIONAL = (1 << 16 ) }
GMarkupCollectType ; 
typedef enum {
  G_LOG_FLAG_RECURSION = 1 << 0 , G_LOG_FLAG_FATAL = 1 << 1 , G_LOG_LEVEL_ERROR = 1 << 2 , G_LOG_LEVEL_CRITICAL = 1 << 3 , G_LOG_LEVEL_WARNING = 1 << 4 , G_LOG_LEVEL_MESSAGE = 1 << 5 , G_LOG_LEVEL_INFO = 1 << 6 , G_LOG_LEVEL_DEBUG = 1 << 7 , G_LOG_LEVEL_MASK = ~ (G_LOG_FLAG_RECURSION | G_LOG_FLAG_FATAL ) }
GLogLevelFlags ; 
typedef void (* GLogFunc ) (const gchar * log_domain , GLogLevelFlags log_level , const gchar * message , gpointer user_data ) ; 
__attribute__ ((visibility ("hidden" ) ) ) void _g_log_fallback_handler (const gchar * log_domain , GLogLevelFlags log_level , const gchar * message , gpointer unused_data ) ; 
__attribute__ ((__deprecated__ ) ) void g_assert_warning (const char * log_domain , const char * file , const int line , const char * pretty_function , const char * expression ) __attribute__ ((__noreturn__ ) ) ; 
typedef void (* GPrintFunc ) (const gchar * string ) ; 
typedef struct _GNode GNode ; 
typedef enum {
  G_TRAVERSE_LEAVES = 1 << 0 , G_TRAVERSE_NON_LEAVES = 1 << 1 , G_TRAVERSE_ALL = G_TRAVERSE_LEAVES | G_TRAVERSE_NON_LEAVES , G_TRAVERSE_MASK = 0x03 , G_TRAVERSE_LEAFS = G_TRAVERSE_LEAVES , G_TRAVERSE_NON_LEAFS = G_TRAVERSE_NON_LEAVES }
GTraverseFlags ; 
typedef enum {
  G_IN_ORDER , G_PRE_ORDER , G_POST_ORDER , G_LEVEL_ORDER }
GTraverseType ; 
typedef gboolean (* GNodeTraverseFunc ) (GNode * node , gpointer data ) ; 
typedef void (* GNodeForeachFunc ) (GNode * node , gpointer data ) ; 
typedef gpointer (* GCopyFunc ) (gconstpointer src , gpointer data ) ; 
struct _GNode {
  gpointer data ; 
  GNode * next ; 
  GNode * prev ; 
  GNode * parent ; 
  GNode * children ; 
}
; 
typedef struct _GOptionContext GOptionContext ; 
typedef struct _GOptionGroup GOptionGroup ; 
typedef struct _GOptionEntry GOptionEntry ; 
typedef enum {
  G_OPTION_FLAG_HIDDEN = 1 << 0 , G_OPTION_FLAG_IN_MAIN = 1 << 1 , G_OPTION_FLAG_REVERSE = 1 << 2 , G_OPTION_FLAG_NO_ARG = 1 << 3 , G_OPTION_FLAG_FILENAME = 1 << 4 , G_OPTION_FLAG_OPTIONAL_ARG = 1 << 5 , G_OPTION_FLAG_NOALIAS = 1 << 6 }
GOptionFlags ; 
typedef enum {
  G_OPTION_ARG_NONE , G_OPTION_ARG_STRING , G_OPTION_ARG_INT , G_OPTION_ARG_CALLBACK , G_OPTION_ARG_FILENAME , G_OPTION_ARG_STRING_ARRAY , G_OPTION_ARG_FILENAME_ARRAY , G_OPTION_ARG_DOUBLE , G_OPTION_ARG_INT64 }
GOptionArg ; 
typedef gboolean (* GOptionArgFunc ) (const gchar * option_name , const gchar * value , gpointer data , GError * * error ) ; 
typedef gboolean (* GOptionParseFunc ) (GOptionContext * context , GOptionGroup * group , gpointer data , GError * * error ) ; 
typedef void (* GOptionErrorFunc ) (GOptionContext * context , GOptionGroup * group , gpointer data , GError * * error ) ; 
typedef enum {
  G_OPTION_ERROR_UNKNOWN_OPTION , G_OPTION_ERROR_BAD_VALUE , G_OPTION_ERROR_FAILED }
GOptionError ; 
struct _GOptionEntry {
  const gchar * long_name ; 
  gchar short_name ; 
  gint flags ; 
  GOptionArg arg ; 
  gpointer arg_data ; 
  const gchar * description ; 
  const gchar * arg_description ; 
}
; 
typedef struct _GPatternSpec GPatternSpec ; 
typedef struct _GQueue GQueue ; 
struct _GQueue {
  GList * head ; 
  GList * tail ; 
  guint length ; 
}
; 
typedef struct _GRand GRand ; 
typedef enum {
  G_REGEX_ERROR_COMPILE , G_REGEX_ERROR_OPTIMIZE , G_REGEX_ERROR_REPLACE , G_REGEX_ERROR_MATCH , G_REGEX_ERROR_INTERNAL , G_REGEX_ERROR_STRAY_BACKSLASH = 101 , G_REGEX_ERROR_MISSING_CONTROL_CHAR = 102 , G_REGEX_ERROR_UNRECOGNIZED_ESCAPE = 103 , G_REGEX_ERROR_QUANTIFIERS_OUT_OF_ORDER = 104 , G_REGEX_ERROR_QUANTIFIER_TOO_BIG = 105 , G_REGEX_ERROR_UNTERMINATED_CHARACTER_CLASS = 106 , G_REGEX_ERROR_INVALID_ESCAPE_IN_CHARACTER_CLASS = 107 , G_REGEX_ERROR_RANGE_OUT_OF_ORDER = 108 , G_REGEX_ERROR_NOTHING_TO_REPEAT = 109 , G_REGEX_ERROR_UNRECOGNIZED_CHARACTER = 112 , G_REGEX_ERROR_POSIX_NAMED_CLASS_OUTSIDE_CLASS = 113 , G_REGEX_ERROR_UNMATCHED_PARENTHESIS = 114 , G_REGEX_ERROR_INEXISTENT_SUBPATTERN_REFERENCE = 115 , G_REGEX_ERROR_UNTERMINATED_COMMENT = 118 , G_REGEX_ERROR_EXPRESSION_TOO_LARGE = 120 , G_REGEX_ERROR_MEMORY_ERROR = 121 , G_REGEX_ERROR_VARIABLE_LENGTH_LOOKBEHIND = 125 , G_REGEX_ERROR_MALFORMED_CONDITION = 126 , G_REGEX_ERROR_TOO_MANY_CONDITIONAL_BRANCHES = 127 , G_REGEX_ERROR_ASSERTION_EXPECTED = 128 , G_REGEX_ERROR_UNKNOWN_POSIX_CLASS_NAME = 130 , G_REGEX_ERROR_POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED = 131 , G_REGEX_ERROR_HEX_CODE_TOO_LARGE = 134 , G_REGEX_ERROR_INVALID_CONDITION = 135 , G_REGEX_ERROR_SINGLE_BYTE_MATCH_IN_LOOKBEHIND = 136 , G_REGEX_ERROR_INFINITE_LOOP = 140 , G_REGEX_ERROR_MISSING_SUBPATTERN_NAME_TERMINATOR = 142 , G_REGEX_ERROR_DUPLICATE_SUBPATTERN_NAME = 143 , G_REGEX_ERROR_MALFORMED_PROPERTY = 146 , G_REGEX_ERROR_UNKNOWN_PROPERTY = 147 , G_REGEX_ERROR_SUBPATTERN_NAME_TOO_LONG = 148 , G_REGEX_ERROR_TOO_MANY_SUBPATTERNS = 149 , G_REGEX_ERROR_INVALID_OCTAL_VALUE = 151 , G_REGEX_ERROR_TOO_MANY_BRANCHES_IN_DEFINE = 154 , G_REGEX_ERROR_DEFINE_REPETION = 155 , G_REGEX_ERROR_INCONSISTENT_NEWLINE_OPTIONS = 156 , G_REGEX_ERROR_MISSING_BACK_REFERENCE = 157 }
GRegexError ; 
typedef enum {
  G_REGEX_CASELESS = 1 << 0 , G_REGEX_MULTILINE = 1 << 1 , G_REGEX_DOTALL = 1 << 2 , G_REGEX_EXTENDED = 1 << 3 , G_REGEX_ANCHORED = 1 << 4 , G_REGEX_DOLLAR_ENDONLY = 1 << 5 , G_REGEX_UNGREEDY = 1 << 9 , G_REGEX_RAW = 1 << 11 , G_REGEX_NO_AUTO_CAPTURE = 1 << 12 , G_REGEX_OPTIMIZE = 1 << 13 , G_REGEX_DUPNAMES = 1 << 19 , G_REGEX_NEWLINE_CR = 1 << 20 , G_REGEX_NEWLINE_LF = 1 << 21 , G_REGEX_NEWLINE_CRLF = G_REGEX_NEWLINE_CR | G_REGEX_NEWLINE_LF }
GRegexCompileFlags ; 
typedef enum {
  G_REGEX_MATCH_ANCHORED = 1 << 4 , G_REGEX_MATCH_NOTBOL = 1 << 7 , G_REGEX_MATCH_NOTEOL = 1 << 8 , G_REGEX_MATCH_NOTEMPTY = 1 << 10 , G_REGEX_MATCH_PARTIAL = 1 << 15 , G_REGEX_MATCH_NEWLINE_CR = 1 << 20 , G_REGEX_MATCH_NEWLINE_LF = 1 << 21 , G_REGEX_MATCH_NEWLINE_CRLF = G_REGEX_MATCH_NEWLINE_CR | G_REGEX_MATCH_NEWLINE_LF , G_REGEX_MATCH_NEWLINE_ANY = 1 << 22 }
GRegexMatchFlags ; 
typedef struct _GRegex GRegex ; 
typedef struct _GMatchInfo GMatchInfo ; 
typedef gboolean (* GRegexEvalCallback ) (const GMatchInfo * match_info , GString * result , gpointer user_data ) ; 
typedef struct _GScanner GScanner ; 
typedef struct _GScannerConfig GScannerConfig ; 
typedef union _GTokenValue GTokenValue ; 
typedef void (* GScannerMsgFunc ) (GScanner * scanner , gchar * message , gboolean error ) ; 
typedef enum {
  G_ERR_UNKNOWN , G_ERR_UNEXP_EOF , G_ERR_UNEXP_EOF_IN_STRING , G_ERR_UNEXP_EOF_IN_COMMENT , G_ERR_NON_DIGIT_IN_CONST , G_ERR_DIGIT_RADIX , G_ERR_FLOAT_RADIX , G_ERR_FLOAT_MALFORMED }
GErrorType ; 
typedef enum {
  G_TOKEN_EOF = 0 , G_TOKEN_LEFT_PAREN = '(' , G_TOKEN_RIGHT_PAREN = ')' , G_TOKEN_LEFT_CURLY = '{' , G_TOKEN_RIGHT_CURLY = '}' , G_TOKEN_LEFT_BRACE = '[' , G_TOKEN_RIGHT_BRACE = ']' , G_TOKEN_EQUAL_SIGN = '=' , G_TOKEN_COMMA = ',' , G_TOKEN_NONE = 256 , G_TOKEN_ERROR , G_TOKEN_CHAR , G_TOKEN_BINARY , G_TOKEN_OCTAL , G_TOKEN_INT , G_TOKEN_HEX , G_TOKEN_FLOAT , G_TOKEN_STRING , G_TOKEN_SYMBOL , G_TOKEN_IDENTIFIER , G_TOKEN_IDENTIFIER_NULL , G_TOKEN_COMMENT_SINGLE , G_TOKEN_COMMENT_MULTI , G_TOKEN_LAST }
GTokenType ; 
union _GTokenValue {
  gpointer v_symbol ; 
  gchar * v_identifier ; 
  gulong v_binary ; 
  gulong v_octal ; 
  gulong v_int ; 
  guint64 v_int64 ; 
  gdouble v_float ; 
  gulong v_hex ; 
  gchar * v_string ; 
  gchar * v_comment ; 
  guchar v_char ; 
  guint v_error ; 
}
; 
struct _GScannerConfig {
  gchar * cset_skip_characters ; 
  gchar * cset_identifier_first ; 
  gchar * cset_identifier_nth ; 
  gchar * cpair_comment_single ; 
  guint case_sensitive : 1 ; 
  guint skip_comment_multi : 1 ; 
  guint skip_comment_single : 1 ; 
  guint scan_comment_multi : 1 ; 
  guint scan_identifier : 1 ; 
  guint scan_identifier_1char : 1 ; 
  guint scan_identifier_NULL : 1 ; 
  guint scan_symbols : 1 ; 
  guint scan_binary : 1 ; 
  guint scan_octal : 1 ; 
  guint scan_float : 1 ; 
  guint scan_hex : 1 ; 
  guint scan_hex_dollar : 1 ; 
  guint scan_string_sq : 1 ; 
  guint scan_string_dq : 1 ; 
  guint numbers_2_int : 1 ; 
  guint int_2_float : 1 ; 
  guint identifier_2_string : 1 ; 
  guint char_2_token : 1 ; 
  guint symbol_2_token : 1 ; 
  guint scope_0_fallback : 1 ; 
  guint store_int64 : 1 ; 
  guint padding_dummy ; 
}
; 
struct _GScanner {
  gpointer user_data ; 
  guint max_parse_errors ; 
  guint parse_errors ; 
  const gchar * input_name ; 
  GData * qdata ; 
  GScannerConfig * config ; 
  GTokenType token ; 
  GTokenValue value ; 
  guint line ; 
  guint position ; 
  GTokenType next_token ; 
  GTokenValue next_value ; 
  guint next_line ; 
  guint next_position ; 
  GHashTable * symbol_table ; 
  gint input_fd ; 
  const gchar * text ; 
  const gchar * text_end ; 
  gchar * buffer ; 
  guint scope_id ; 
  GScannerMsgFunc msg_handler ; 
}
; 
typedef struct _GSequence GSequence ; 
typedef struct _GSequenceNode GSequenceIter ; 
typedef gint (* GSequenceIterCompareFunc ) (GSequenceIter * a , GSequenceIter * b , gpointer data ) ; 
typedef enum {
  G_SHELL_ERROR_BAD_QUOTING , G_SHELL_ERROR_EMPTY_STRING , G_SHELL_ERROR_FAILED }
GShellError ; 
typedef enum {
  G_SLICE_CONFIG_ALWAYS_MALLOC = 1 , G_SLICE_CONFIG_BYPASS_MAGAZINES , G_SLICE_CONFIG_WORKING_SET_MSECS , G_SLICE_CONFIG_COLOR_INCREMENT , G_SLICE_CONFIG_CHUNK_SIZES , G_SLICE_CONFIG_CONTENTION_COUNTER }
GSliceConfig ; 
typedef enum {
  G_SPAWN_ERROR_FORK , G_SPAWN_ERROR_READ , G_SPAWN_ERROR_CHDIR , G_SPAWN_ERROR_ACCES , G_SPAWN_ERROR_PERM , G_SPAWN_ERROR_TOO_BIG , G_SPAWN_ERROR_2BIG = G_SPAWN_ERROR_TOO_BIG , G_SPAWN_ERROR_NOEXEC , G_SPAWN_ERROR_NAMETOOLONG , G_SPAWN_ERROR_NOENT , G_SPAWN_ERROR_NOMEM , G_SPAWN_ERROR_NOTDIR , G_SPAWN_ERROR_LOOP , G_SPAWN_ERROR_TXTBUSY , G_SPAWN_ERROR_IO , G_SPAWN_ERROR_NFILE , G_SPAWN_ERROR_MFILE , G_SPAWN_ERROR_INVAL , G_SPAWN_ERROR_ISDIR , G_SPAWN_ERROR_LIBBAD , G_SPAWN_ERROR_FAILED }
GSpawnError ; 
typedef void (* GSpawnChildSetupFunc ) (gpointer user_data ) ; 
typedef enum {
  G_SPAWN_LEAVE_DESCRIPTORS_OPEN = 1 << 0 , G_SPAWN_DO_NOT_REAP_CHILD = 1 << 1 , G_SPAWN_SEARCH_PATH = 1 << 2 , G_SPAWN_STDOUT_TO_DEV_NULL = 1 << 3 , G_SPAWN_STDERR_TO_DEV_NULL = 1 << 4 , G_SPAWN_CHILD_INHERITS_STDIN = 1 << 5 , G_SPAWN_FILE_AND_ARGV_ZERO = 1 << 6 }
GSpawnFlags ; 
typedef enum {
  G_ASCII_ALNUM = 1 << 0 , G_ASCII_ALPHA = 1 << 1 , G_ASCII_CNTRL = 1 << 2 , G_ASCII_DIGIT = 1 << 3 , G_ASCII_GRAPH = 1 << 4 , G_ASCII_LOWER = 1 << 5 , G_ASCII_PRINT = 1 << 6 , G_ASCII_PUNCT = 1 << 7 , G_ASCII_SPACE = 1 << 8 , G_ASCII_UPPER = 1 << 9 , G_ASCII_XDIGIT = 1 << 10 }
GAsciiType ; 
__attribute__ ((__deprecated__ ) ) gint g_strcasecmp (const gchar * s1 , const gchar * s2 ) ; 
__attribute__ ((__deprecated__ ) ) gint g_strncasecmp (const gchar * s1 , const gchar * s2 , guint n ) ; 
__attribute__ ((__deprecated__ ) ) gchar * g_strdown (gchar * string ) ; 
__attribute__ ((__deprecated__ ) ) gchar * g_strup (gchar * string ) ; 
typedef struct _GStringChunk GStringChunk ; 
typedef struct GTestCase GTestCase ; 
typedef struct GTestSuite GTestSuite ; 
typedef void (* GTestFunc ) (void ) ; 
typedef void (* GTestDataFunc ) (gconstpointer user_data ) ; 
typedef void (* GTestFixtureFunc ) (gpointer fixture , gconstpointer user_data ) ; 
typedef enum {
  G_TEST_TRAP_SILENCE_STDOUT = 1 << 7 , G_TEST_TRAP_SILENCE_STDERR = 1 << 8 , G_TEST_TRAP_INHERIT_STDIN = 1 << 9 }
GTestTrapFlags ; 
typedef struct {
  gboolean test_initialized ; 
  gboolean test_quick ; 
  gboolean test_perf ; 
  gboolean test_verbose ; 
  gboolean test_quiet ; 
  gboolean test_undefined ; 
}
GTestConfig ; 
typedef enum {
  G_TEST_LOG_NONE , G_TEST_LOG_ERROR , G_TEST_LOG_START_BINARY , G_TEST_LOG_LIST_CASE , G_TEST_LOG_SKIP_CASE , G_TEST_LOG_START_CASE , G_TEST_LOG_STOP_CASE , G_TEST_LOG_MIN_RESULT , G_TEST_LOG_MAX_RESULT , G_TEST_LOG_MESSAGE }
GTestLogType ; 
typedef struct {
  GTestLogType log_type ; 
  guint n_strings ; 
  gchar * * strings ; 
  guint n_nums ; 
  long double * nums ; 
}
GTestLogMsg ; 
typedef struct {
  GString * data ; 
  GSList * msgs ; 
}
GTestLogBuffer ; 
typedef gboolean (* GTestLogFatalFunc ) (const gchar * log_domain , GLogLevelFlags log_level , const gchar * message , gpointer user_data ) ; 
typedef struct _GThreadPool GThreadPool ; 
struct _GThreadPool {
  GFunc func ; 
  gpointer user_data ; 
  gboolean exclusive ; 
}
; 
typedef struct _GTimer GTimer ; 
typedef struct _GTrashStack GTrashStack ; 
struct _GTrashStack {
  GTrashStack * next ; 
}
; 
static __inline __attribute__ ((unused ) ) void g_trash_stack_push (GTrashStack * * stack_p , gpointer data_p ) ; 
static __inline __attribute__ ((unused ) ) gpointer g_trash_stack_pop (GTrashStack * * stack_p ) ; 
static __inline __attribute__ ((unused ) ) gpointer g_trash_stack_peek (GTrashStack * * stack_p ) ; 
static __inline __attribute__ ((unused ) ) guint g_trash_stack_height (GTrashStack * * stack_p ) ; 
static __inline __attribute__ ((unused ) ) void g_trash_stack_push (GTrashStack * * stack_p , gpointer data_p ) {
  GTrashStack * data = (GTrashStack * ) data_p ; 
  data -> next = * stack_p ; 
  * stack_p = data ; 
}
static __inline __attribute__ ((unused ) ) gpointer g_trash_stack_pop (GTrashStack * * stack_p ) {
  GTrashStack * data ; 
  data = * stack_p ; 
  if (data ) {
    * stack_p = data -> next ; 
    data -> next = ((void * ) 0 ) ; 
  }
  return data ; 
}
static __inline __attribute__ ((unused ) ) gpointer g_trash_stack_peek (GTrashStack * * stack_p ) {
  GTrashStack * data ; 
  data = * stack_p ; 
  return data ; 
}
static __inline __attribute__ ((unused ) ) guint g_trash_stack_height (GTrashStack * * stack_p ) {
  GTrashStack * data ; 
  guint i = 0 ; 
  for (data = * stack_p ; data ; data = data -> next ) i ++ ; 
  return i ; 
}
typedef struct _GTree GTree ; 
typedef gboolean (* GTraverseFunc ) (gpointer key , gpointer value , gpointer data ) ; 
__attribute__ ((__deprecated__ ) ) void g_tree_traverse (GTree * tree , GTraverseFunc traverse_func , GTraverseType traverse_type , gpointer user_data ) ; 
typedef struct _GVariantType GVariantType ; 
typedef struct _GVariant GVariant ; 
typedef enum {
  G_VARIANT_CLASS_BOOLEAN = 'b' , G_VARIANT_CLASS_BYTE = 'y' , G_VARIANT_CLASS_INT16 = 'n' , G_VARIANT_CLASS_UINT16 = 'q' , G_VARIANT_CLASS_INT32 = 'i' , G_VARIANT_CLASS_UINT32 = 'u' , G_VARIANT_CLASS_INT64 = 'x' , G_VARIANT_CLASS_UINT64 = 't' , G_VARIANT_CLASS_HANDLE = 'h' , G_VARIANT_CLASS_DOUBLE = 'd' , G_VARIANT_CLASS_STRING = 's' , G_VARIANT_CLASS_OBJECT_PATH = 'o' , G_VARIANT_CLASS_SIGNATURE = 'g' , G_VARIANT_CLASS_VARIANT = 'v' , G_VARIANT_CLASS_MAYBE = 'm' , G_VARIANT_CLASS_ARRAY = 'a' , G_VARIANT_CLASS_TUPLE = '(' , G_VARIANT_CLASS_DICT_ENTRY = '{' }
GVariantClass ; 
gboolean g_variant_is_of_type (GVariant * value , const GVariantType * type ) ; 
GVariant * g_variant_new_int32 (gint32 value ) ; 
GVariant * g_variant_new_double (gdouble value ) ; 
GVariant * g_variant_new_string (const gchar * string ) ; 
gint32 g_variant_get_int32 (GVariant * value ) ; 
const gchar * g_variant_get_string (GVariant * value , gsize * length ) ; 
gsize g_variant_get_size (GVariant * value ) ; 
typedef struct _GVariantIter GVariantIter ; 
struct _GVariantIter {
  gsize x [16 ] ; 
}
; 
typedef struct _GVariantBuilder GVariantBuilder ; 
struct _GVariantBuilder {
  gsize x [16 ] ; 
}
; 
typedef enum {
  G_VARIANT_PARSE_ERROR_FAILED , G_VARIANT_PARSE_ERROR_BASIC_TYPE_EXPECTED , G_VARIANT_PARSE_ERROR_CANNOT_INFER_TYPE , G_VARIANT_PARSE_ERROR_DEFINITE_TYPE_EXPECTED , G_VARIANT_PARSE_ERROR_INPUT_NOT_AT_END , G_VARIANT_PARSE_ERROR_INVALID_CHARACTER , G_VARIANT_PARSE_ERROR_INVALID_FORMAT_STRING , G_VARIANT_PARSE_ERROR_INVALID_OBJECT_PATH , G_VARIANT_PARSE_ERROR_INVALID_SIGNATURE , G_VARIANT_PARSE_ERROR_INVALID_TYPE_STRING , G_VARIANT_PARSE_ERROR_NO_COMMON_TYPE , G_VARIANT_PARSE_ERROR_NUMBER_OUT_OF_RANGE , G_VARIANT_PARSE_ERROR_NUMBER_TOO_BIG , G_VARIANT_PARSE_ERROR_TYPE_ERROR , G_VARIANT_PARSE_ERROR_UNEXPECTED_TOKEN , G_VARIANT_PARSE_ERROR_UNKNOWN_KEYWORD , G_VARIANT_PARSE_ERROR_UNTERMINATED_STRING_CONSTANT , G_VARIANT_PARSE_ERROR_VALUE_EXPECTED }
GVariantParseError ; 
typedef struct _GAllocator GAllocator ; 
typedef struct _GMemChunk GMemChunk ; 
__attribute__ ((__deprecated__ ) ) GMemChunk * g_mem_chunk_new (const gchar * name , gint atom_size , gsize area_size , gint type ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_destroy (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) gpointer g_mem_chunk_alloc (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) gpointer g_mem_chunk_alloc0 (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_free (GMemChunk * mem_chunk , gpointer mem ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_clean (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_reset (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_print (GMemChunk * mem_chunk ) ; 
__attribute__ ((__deprecated__ ) ) void g_mem_chunk_info (void ) ; 
__attribute__ ((__deprecated__ ) ) void g_blow_chunks (void ) ; 
__attribute__ ((__deprecated__ ) ) GAllocator * g_allocator_new (const gchar * name , guint n_preallocs ) ; 
__attribute__ ((__deprecated__ ) ) void g_allocator_free (GAllocator * allocator ) ; 
__attribute__ ((__deprecated__ ) ) void g_list_push_allocator (GAllocator * allocator ) ; 
__attribute__ ((__deprecated__ ) ) void g_list_pop_allocator (void ) ; 
__attribute__ ((__deprecated__ ) ) void g_slist_push_allocator (GAllocator * allocator ) ; 
__attribute__ ((__deprecated__ ) ) void g_slist_pop_allocator (void ) ; 
__attribute__ ((__deprecated__ ) ) void g_node_push_allocator (GAllocator * allocator ) ; 
__attribute__ ((__deprecated__ ) ) void g_node_pop_allocator (void ) ; 
typedef struct _GCache GCache ; 
typedef gpointer (* GCacheNewFunc ) (gpointer key ) ; 
typedef gpointer (* GCacheDupFunc ) (gpointer value ) ; 
typedef void (* GCacheDestroyFunc ) (gpointer value ) ; 
__attribute__ ((__deprecated__ ) ) GCache * g_cache_new (GCacheNewFunc value_new_func , GCacheDestroyFunc value_destroy_func , GCacheDupFunc key_dup_func , GCacheDestroyFunc key_destroy_func , GHashFunc hash_key_func , GHashFunc hash_value_func , GEqualFunc key_equal_func ) ; 
__attribute__ ((__deprecated__ ) ) void g_cache_destroy (GCache * cache ) ; 
__attribute__ ((__deprecated__ ) ) gpointer g_cache_insert (GCache * cache , gpointer key ) ; 
__attribute__ ((__deprecated__ ) ) void g_cache_remove (GCache * cache , gconstpointer value ) ; 
__attribute__ ((__deprecated__ ) ) void g_cache_key_foreach (GCache * cache , GHFunc func , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ) ) void g_cache_value_foreach (GCache * cache , GHFunc func , gpointer user_data ) ; 
typedef struct _GCompletion GCompletion ; 
typedef gchar * (* GCompletionFunc ) (gpointer ) ; 
typedef gint (* GCompletionStrncmpFunc ) (const gchar * s1 , const gchar * s2 , gsize n ) ; 
struct _GCompletion {
  GList * items ; 
  GCompletionFunc func ; 
  gchar * prefix ; 
  GList * cache ; 
  GCompletionStrncmpFunc strncmp_func ; 
}
; 
__attribute__ ((__deprecated__ ) ) GCompletion * g_completion_new (GCompletionFunc func ) ; 
__attribute__ ((__deprecated__ ) ) void g_completion_add_items (GCompletion * cmp , GList * items ) ; 
__attribute__ ((__deprecated__ ) ) void g_completion_remove_items (GCompletion * cmp , GList * items ) ; 
__attribute__ ((__deprecated__ ) ) void g_completion_clear_items (GCompletion * cmp ) ; 
__attribute__ ((__deprecated__ ) ) GList * g_completion_complete (GCompletion * cmp , const gchar * prefix , gchar * * new_prefix ) ; 
__attribute__ ((__deprecated__ ) ) GList * g_completion_complete_utf8 (GCompletion * cmp , const gchar * prefix , gchar * * new_prefix ) ; 
__attribute__ ((__deprecated__ ) ) void g_completion_set_compare (GCompletion * cmp , GCompletionStrncmpFunc strncmp_func ) ; 
__attribute__ ((__deprecated__ ) ) void g_completion_free (GCompletion * cmp ) ; 
typedef struct _GRelation GRelation ; 
typedef struct _GTuples GTuples ; 
struct _GTuples {
  guint len ; 
}
; 
__attribute__ ((__deprecated__ ) ) GRelation * g_relation_new (gint fields ) ; 
__attribute__ ((__deprecated__ ) ) void g_relation_destroy (GRelation * relation ) ; 
__attribute__ ((__deprecated__ ) ) void g_relation_index (GRelation * relation , gint field , GHashFunc hash_func , GEqualFunc key_equal_func ) ; 
__attribute__ ((__deprecated__ ) ) void g_relation_insert (GRelation * relation , ... ) ; 
__attribute__ ((__deprecated__ ) ) gint g_relation_delete (GRelation * relation , gconstpointer key , gint field ) ; 
__attribute__ ((__deprecated__ ) ) GTuples * g_relation_select (GRelation * relation , gconstpointer key , gint field ) ; 
__attribute__ ((__deprecated__ ) ) gint g_relation_count (GRelation * relation , gconstpointer key , gint field ) ; 
__attribute__ ((__deprecated__ ) ) gboolean g_relation_exists (GRelation * relation , ... ) ; 
__attribute__ ((__deprecated__ ) ) void g_relation_print (GRelation * relation ) ; 
__attribute__ ((__deprecated__ ) ) void g_tuples_destroy (GTuples * tuples ) ; 
__attribute__ ((__deprecated__ ) ) gpointer g_tuples_index (GTuples * tuples , gint index_ , gint field ) ; 
typedef enum {
  G_THREAD_PRIORITY_LOW , G_THREAD_PRIORITY_NORMAL , G_THREAD_PRIORITY_HIGH , G_THREAD_PRIORITY_URGENT }
GThreadPriority ; 
struct _GThread {
  GThreadFunc func ; 
  gpointer data ; 
  gboolean joinable ; 
  GThreadPriority priority ; 
}
; 
typedef struct _GThreadFunctions GThreadFunctions ; 
struct _GThreadFunctions {
  GMutex * (* mutex_new ) (void ) ; 
  void (* mutex_lock ) (GMutex * mutex ) ; 
  gboolean (* mutex_trylock ) (GMutex * mutex ) ; 
  void (* mutex_unlock ) (GMutex * mutex ) ; 
  void (* mutex_free ) (GMutex * mutex ) ; 
  GCond * (* cond_new ) (void ) ; 
  void (* cond_signal ) (GCond * cond ) ; 
  void (* cond_broadcast ) (GCond * cond ) ; 
  void (* cond_wait ) (GCond * cond , GMutex * mutex ) ; 
  gboolean (* cond_timed_wait ) (GCond * cond , GMutex * mutex , GTimeVal * end_time ) ; 
  void (* cond_free ) (GCond * cond ) ; 
  GPrivate * (* private_new ) (GDestroyNotify destructor ) ; 
  gpointer (* private_get ) (GPrivate * private_key ) ; 
  void (* private_set ) (GPrivate * private_key , gpointer data ) ; 
  void (* thread_create ) (GThreadFunc func , gpointer data , gulong stack_size , gboolean joinable , gboolean bound , GThreadPriority priority , gpointer thread , GError * * error ) ; 
  void (* thread_yield ) (void ) ; 
  void (* thread_join ) (gpointer thread ) ; 
  void (* thread_exit ) (void ) ; 
  void (* thread_set_priority ) (gpointer thread , GThreadPriority priority ) ; 
  void (* thread_self ) (gpointer thread ) ; 
  gboolean (* thread_equal ) (gpointer thread1 , gpointer thread2 ) ; 
}
; 
extern guint64 (* g_thread_gettime ) (void ) ; 
struct sched_param {
  int __sched_priority ; 
}
; 
struct __sched_param {
  int __sched_priority ; 
}
; 
typedef unsigned long int __cpu_mask ; 
typedef struct {
  __cpu_mask __bits [1024 / (8 * sizeof (__cpu_mask ) ) ] ; 
}
cpu_set_t ; 
typedef long int __jmp_buf [8 ] ; 
enum {
  PTHREAD_CREATE_JOINABLE , PTHREAD_CREATE_DETACHED }
; 
enum {
  PTHREAD_MUTEX_TIMED_NP , PTHREAD_MUTEX_RECURSIVE_NP , PTHREAD_MUTEX_ERRORCHECK_NP , PTHREAD_MUTEX_ADAPTIVE_NP , PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP , PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP , PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP , PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL }
; 
enum {
  PTHREAD_MUTEX_STALLED , PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED , PTHREAD_MUTEX_ROBUST , PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST }
; 
enum {
  PTHREAD_RWLOCK_PREFER_READER_NP , PTHREAD_RWLOCK_PREFER_WRITER_NP , PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP , PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP }
; 
enum {
  PTHREAD_INHERIT_SCHED , PTHREAD_EXPLICIT_SCHED }
; 
enum {
  PTHREAD_SCOPE_SYSTEM , PTHREAD_SCOPE_PROCESS }
; 
enum {
  PTHREAD_PROCESS_PRIVATE , PTHREAD_PROCESS_SHARED }
; 
struct _pthread_cleanup_buffer {
  void (* __routine ) (void * ) ; 
  void * __arg ; 
  int __canceltype ; 
  struct _pthread_cleanup_buffer * __prev ; 
}
; 
enum {
  PTHREAD_CANCEL_ENABLE , PTHREAD_CANCEL_DISABLE }
; 
enum {
  PTHREAD_CANCEL_DEFERRED , PTHREAD_CANCEL_ASYNCHRONOUS }
; 
typedef struct {
  struct {
    __jmp_buf __cancel_jmp_buf ; 
    int __mask_was_saved ; 
  }
  __cancel_jmp_buf [1 ] ; 
  void * __pad [4 ] ; 
}
__pthread_unwind_buf_t __attribute__ ((__aligned__ ) ) ; 
struct __pthread_cleanup_frame {
  void (* __cancel_routine ) (void * ) ; 
  void * __cancel_arg ; 
  int __do_it ; 
  int __cancel_type ; 
}
; 
struct __jmp_buf_tag ; 
extern int __sigsetjmp (struct __jmp_buf_tag * __env , int __savemask ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern void * pthread_getspecific (pthread_key_t __key ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
typedef struct {
  GMutex * mutex ; 
  pthread_mutex_t unused ; 
}
GStaticMutex ; 
typedef struct _GStaticRecMutex GStaticRecMutex ; 
struct _GStaticRecMutex {
  GStaticMutex mutex ; 
  guint depth ; 
  union {
    pthread_t owner ; 
    gdouble dummy ; 
  }
  unused ; 
}
; 
typedef struct _GStaticRWLock GStaticRWLock ; 
struct _GStaticRWLock {
  GStaticMutex mutex ; 
  GCond * read_cond ; 
  GCond * write_cond ; 
  guint read_counter ; 
  gboolean have_writer ; 
  guint want_to_read ; 
  guint want_to_write ; 
}
; 
typedef struct _GStaticPrivate GStaticPrivate ; 
struct _GStaticPrivate {
  guint index ; 
}
; 
typedef gsize GType ; 
typedef struct _GValue GValue ; 
typedef union _GTypeCValue GTypeCValue ; 
typedef struct _GTypePlugin GTypePlugin ; 
typedef struct _GTypeClass GTypeClass ; 
typedef struct _GTypeInterface GTypeInterface ; 
typedef struct _GTypeInstance GTypeInstance ; 
typedef struct _GTypeInfo GTypeInfo ; 
typedef struct _GTypeFundamentalInfo GTypeFundamentalInfo ; 
typedef struct _GInterfaceInfo GInterfaceInfo ; 
typedef struct _GTypeValueTable GTypeValueTable ; 
typedef struct _GTypeQuery GTypeQuery ; 
struct _GTypeClass {
  GType g_type ; 
}
; 
struct _GTypeInstance {
  GTypeClass * g_class ; 
}
; 
struct _GTypeInterface {
  GType g_type ; 
  GType g_instance_type ; 
}
; 
struct _GTypeQuery {
  GType type ; 
  const gchar * type_name ; 
  guint class_size ; 
  guint instance_size ; 
}
; 
typedef enum {
  G_TYPE_DEBUG_NONE = 0 , G_TYPE_DEBUG_OBJECTS = 1 << 0 , G_TYPE_DEBUG_SIGNALS = 1 << 1 , G_TYPE_DEBUG_MASK = 0x03 }
GTypeDebugFlags ; 
void g_type_init (void ) ; 
typedef void (* GBaseInitFunc ) (gpointer g_class ) ; 
typedef void (* GBaseFinalizeFunc ) (gpointer g_class ) ; 
typedef void (* GClassInitFunc ) (gpointer g_class , gpointer class_data ) ; 
typedef void (* GClassFinalizeFunc ) (gpointer g_class , gpointer class_data ) ; 
typedef void (* GInstanceInitFunc ) (GTypeInstance * instance , gpointer g_class ) ; 
typedef void (* GInterfaceInitFunc ) (gpointer g_iface , gpointer iface_data ) ; 
typedef void (* GInterfaceFinalizeFunc ) (gpointer g_iface , gpointer iface_data ) ; 
typedef gboolean (* GTypeClassCacheFunc ) (gpointer cache_data , GTypeClass * g_class ) ; 
typedef void (* GTypeInterfaceCheckFunc ) (gpointer check_data , gpointer g_iface ) ; 
typedef enum {
  G_TYPE_FLAG_CLASSED = (1 << 0 ) , G_TYPE_FLAG_INSTANTIATABLE = (1 << 1 ) , G_TYPE_FLAG_DERIVABLE = (1 << 2 ) , G_TYPE_FLAG_DEEP_DERIVABLE = (1 << 3 ) }
GTypeFundamentalFlags ; 
typedef enum {
  G_TYPE_FLAG_ABSTRACT = (1 << 4 ) , G_TYPE_FLAG_VALUE_ABSTRACT = (1 << 5 ) }
GTypeFlags ; 
struct _GTypeInfo {
  guint16 class_size ; 
  GBaseInitFunc base_init ; 
  GBaseFinalizeFunc base_finalize ; 
  GClassInitFunc class_init ; 
  GClassFinalizeFunc class_finalize ; 
  gconstpointer class_data ; 
  guint16 instance_size ; 
  guint16 n_preallocs ; 
  GInstanceInitFunc instance_init ; 
  const GTypeValueTable * value_table ; 
}
; 
struct _GTypeFundamentalInfo {
  GTypeFundamentalFlags type_flags ; 
}
; 
struct _GInterfaceInfo {
  GInterfaceInitFunc interface_init ; 
  GInterfaceFinalizeFunc interface_finalize ; 
  gpointer interface_data ; 
}
; 
struct _GTypeValueTable {
  void (* value_init ) (GValue * value ) ; 
  void (* value_free ) (GValue * value ) ; 
  void (* value_copy ) (const GValue * src_value , GValue * dest_value ) ; 
  gpointer (* value_peek_pointer ) (const GValue * value ) ; 
  gchar * collect_format ; 
  gchar * (* collect_value ) (GValue * value , guint n_collect_values , GTypeCValue * collect_values , guint collect_flags ) ; 
  gchar * lcopy_format ; 
  gchar * (* lcopy_value ) (const GValue * value , guint n_collect_values , GTypeCValue * collect_values , guint collect_flags ) ; 
}
; 
typedef void (* GValueTransform ) (const GValue * src_value , GValue * dest_value ) ; 
struct _GValue {
  GType g_type ; 
  union {
    gint v_int ; 
    guint v_uint ; 
    glong v_long ; 
    gulong v_ulong ; 
    gint64 v_int64 ; 
    guint64 v_uint64 ; 
    gfloat v_float ; 
    gdouble v_double ; 
    gpointer v_pointer ; 
  }
  data [2 ] ; 
}
; 
typedef enum {
  G_PARAM_READABLE = 1 << 0 , G_PARAM_WRITABLE = 1 << 1 , G_PARAM_CONSTRUCT = 1 << 2 , G_PARAM_CONSTRUCT_ONLY = 1 << 3 , G_PARAM_LAX_VALIDATION = 1 << 4 , G_PARAM_STATIC_NAME = 1 << 5 , G_PARAM_PRIVATE = G_PARAM_STATIC_NAME , G_PARAM_STATIC_NICK = 1 << 6 , G_PARAM_STATIC_BLURB = 1 << 7 , G_PARAM_DEPRECATED = 1 << 31 }
GParamFlags ; 
typedef struct _GParamSpec GParamSpec ; 
typedef struct _GParameter GParameter ; 
typedef struct _GParamSpecPool GParamSpecPool ; 
struct _GParamSpec {
  GTypeInstance g_type_instance ; 
  const gchar * name ; 
  GParamFlags flags ; 
  GType value_type ; 
  GType owner_type ; 
  gchar * _nick ; 
  gchar * _blurb ; 
  GData * qdata ; 
  guint ref_count ; 
  guint param_id ; 
}
; 
struct _GParamSpecClass {
  GTypeClass g_type_class ; 
  GType value_type ; 
  void (* finalize ) (GParamSpec * pspec ) ; 
  void (* value_set_default ) (GParamSpec * pspec , GValue * value ) ; 
  gboolean (* value_validate ) (GParamSpec * pspec , GValue * value ) ; 
  gint (* values_cmp ) (GParamSpec * pspec , const GValue * value1 , const GValue * value2 ) ; 
  gpointer dummy [4 ] ; 
}
; 
struct _GParameter {
  const gchar * name ; 
  GValue value ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_value_take_param" "' instead" ) ) ) void g_value_set_param_take_ownership (GValue * value , GParamSpec * param ) ; 
typedef struct _GParamSpecTypeInfo GParamSpecTypeInfo ; 
struct _GParamSpecTypeInfo {
  guint16 instance_size ; 
  guint16 n_preallocs ; 
  void (* instance_init ) (GParamSpec * pspec ) ; 
  GType value_type ; 
  void (* finalize ) (GParamSpec * pspec ) ; 
  void (* value_set_default ) (GParamSpec * pspec , GValue * value ) ; 
  gboolean (* value_validate ) (GParamSpec * pspec , GValue * value ) ; 
  gint (* values_cmp ) (GParamSpec * pspec , const GValue * value1 , const GValue * value2 ) ; 
}
; 
typedef struct _GClosure GClosure ; 
typedef struct _GClosureNotifyData GClosureNotifyData ; 
typedef void (* GCallback ) (void ) ; 
typedef void (* GClosureNotify ) (gpointer data , GClosure * closure ) ; 
typedef void (* GClosureMarshal ) (GClosure * closure , GValue * return_value , guint n_param_values , const GValue * param_values , gpointer invocation_hint , gpointer marshal_data ) ; 
typedef void (* GVaClosureMarshal ) (GClosure * closure , GValue * return_value , gpointer instance , va_list args , gpointer marshal_data , int n_params , GType * param_types ) ; 
struct _GClosureNotifyData {
  gpointer data ; 
  GClosureNotify notify ; 
}
; 
struct _GClosure {
  volatile guint ref_count : 15 ; 
  volatile guint meta_marshal_nouse : 1 ; 
  volatile guint n_guards : 1 ; 
  volatile guint n_fnotifiers : 2 ; 
  volatile guint n_inotifiers : 8 ; 
  volatile guint in_inotify : 1 ; 
  volatile guint floating : 1 ; 
  volatile guint derivative_flag : 1 ; 
  volatile guint in_marshal : 1 ; 
  volatile guint is_invalid : 1 ; 
  void (* marshal ) (GClosure * closure , GValue * return_value , guint n_param_values , const GValue * param_values , gpointer invocation_hint , gpointer marshal_data ) ; 
  gpointer data ; 
  GClosureNotifyData * notifiers ; 
}
; 
struct _GCClosure {
  GClosure closure ; 
  gpointer callback ; 
}
; 
typedef struct _GSignalQuery GSignalQuery ; 
typedef struct _GSignalInvocationHint GSignalInvocationHint ; 
typedef GClosureMarshal GSignalCMarshaller ; 
typedef GVaClosureMarshal GSignalCVaMarshaller ; 
typedef gboolean (* GSignalEmissionHook ) (GSignalInvocationHint * ihint , guint n_param_values , const GValue * param_values , gpointer data ) ; 
typedef gboolean (* GSignalAccumulator ) (GSignalInvocationHint * ihint , GValue * return_accu , const GValue * handler_return , gpointer data ) ; 
typedef enum {
  G_SIGNAL_RUN_FIRST = 1 << 0 , G_SIGNAL_RUN_LAST = 1 << 1 , G_SIGNAL_RUN_CLEANUP = 1 << 2 , G_SIGNAL_NO_RECURSE = 1 << 3 , G_SIGNAL_DETAILED = 1 << 4 , G_SIGNAL_ACTION = 1 << 5 , G_SIGNAL_NO_HOOKS = 1 << 6 , G_SIGNAL_MUST_COLLECT = 1 << 7 , G_SIGNAL_DEPRECATED = 1 << 8 }
GSignalFlags ; 
typedef enum {
  G_CONNECT_AFTER = 1 << 0 , G_CONNECT_SWAPPED = 1 << 1 }
GConnectFlags ; 
typedef enum {
  G_SIGNAL_MATCH_ID = 1 << 0 , G_SIGNAL_MATCH_DETAIL = 1 << 1 , G_SIGNAL_MATCH_CLOSURE = 1 << 2 , G_SIGNAL_MATCH_FUNC = 1 << 3 , G_SIGNAL_MATCH_DATA = 1 << 4 , G_SIGNAL_MATCH_UNBLOCKED = 1 << 5 }
GSignalMatchType ; 
struct _GSignalInvocationHint {
  guint signal_id ; 
  GQuark detail ; 
  GSignalFlags run_type ; 
}
; 
struct _GSignalQuery {
  guint signal_id ; 
  const gchar * signal_name ; 
  GType itype ; 
  GSignalFlags signal_flags ; 
  GType return_type ; 
  guint n_params ; 
  const GType * param_types ; 
}
; 
typedef struct _GObject GObject ; 
typedef struct _GObjectClass GObjectClass ; 
typedef struct _GObjectConstructParam GObjectConstructParam ; 
typedef void (* GObjectGetPropertyFunc ) (GObject * object , guint property_id , GValue * value , GParamSpec * pspec ) ; 
typedef void (* GObjectSetPropertyFunc ) (GObject * object , guint property_id , const GValue * value , GParamSpec * pspec ) ; 
typedef void (* GObjectFinalizeFunc ) (GObject * object ) ; 
typedef void (* GWeakNotify ) (gpointer data , GObject * where_the_object_was ) ; 
struct _GObject {
  GTypeInstance g_type_instance ; 
  volatile guint ref_count ; 
  GData * qdata ; 
}
; 
struct _GObjectClass {
  GTypeClass g_type_class ; 
  GSList * construct_properties ; 
  GObject * (* constructor ) (GType type , guint n_construct_properties , GObjectConstructParam * construct_properties ) ; 
  void (* set_property ) (GObject * object , guint property_id , const GValue * value , GParamSpec * pspec ) ; 
  void (* get_property ) (GObject * object , guint property_id , GValue * value , GParamSpec * pspec ) ; 
  void (* dispose ) (GObject * object ) ; 
  void (* finalize ) (GObject * object ) ; 
  void (* dispatch_properties_changed ) (GObject * object , guint n_pspecs , GParamSpec * * pspecs ) ; 
  void (* notify ) (GObject * object , GParamSpec * pspec ) ; 
  void (* constructed ) (GObject * object ) ; 
  gsize flags ; 
  gpointer pdummy [6 ] ; 
}
; 
struct _GObjectConstructParam {
  GParamSpec * pspec ; 
  GValue * value ; 
}
; 
typedef void (* GToggleNotify ) (gpointer data , GObject * object , gboolean is_last_ref ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_value_take_object" "' instead" ) ) ) void g_value_set_object_take_ownership (GValue * value , gpointer v_object ) ; 
__attribute__ ((__deprecated__ ) ) gsize g_object_compat_control (gsize what , gpointer data ) ; 
typedef struct {
  union {
    gpointer p ; 
  }
  priv ; 
}
GWeakRef ; 
typedef struct _GBinding GBinding ; 
typedef gboolean (* GBindingTransformFunc ) (GBinding * binding , const GValue * source_value , GValue * target_value , gpointer user_data ) ; 
typedef enum {
  G_BINDING_DEFAULT = 0 , G_BINDING_BIDIRECTIONAL = 1 << 0 , G_BINDING_SYNC_CREATE = 1 << 1 , G_BINDING_INVERT_BOOLEAN = 1 << 2 }
GBindingFlags ; 
__attribute__ ((__deprecated__ ("Use '" "'G_TYPE_VARIANT'" "' instead" ) ) ) GType g_variant_get_gtype (void ) __attribute__ ((__const__ ) ) ; 
typedef gpointer (* GBoxedCopyFunc ) (gpointer boxed ) ; 
typedef void (* GBoxedFreeFunc ) (gpointer boxed ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_value_take_boxed" "' instead" ) ) ) void g_value_set_boxed_take_ownership (GValue * value , gconstpointer v_boxed ) ; 
typedef struct _GEnumClass GEnumClass ; 
typedef struct _GFlagsClass GFlagsClass ; 
typedef struct _GEnumValue GEnumValue ; 
typedef struct _GFlagsValue GFlagsValue ; 
struct _GEnumClass {
  GTypeClass g_type_class ; 
  gint minimum ; 
  gint maximum ; 
  guint n_values ; 
  GEnumValue * values ; 
}
; 
struct _GFlagsClass {
  GTypeClass g_type_class ; 
  guint mask ; 
  guint n_values ; 
  GFlagsValue * values ; 
}
; 
struct _GEnumValue {
  gint value ; 
  const gchar * value_name ; 
  const gchar * value_nick ; 
}
; 
struct _GFlagsValue {
  guint value ; 
  const gchar * value_name ; 
  const gchar * value_nick ; 
}
; 
struct _GParamSpecChar {
  GParamSpec parent_instance ; 
  gint8 minimum ; 
  gint8 maximum ; 
  gint8 default_value ; 
}
; 
struct _GParamSpecUChar {
  GParamSpec parent_instance ; 
  guint8 minimum ; 
  guint8 maximum ; 
  guint8 default_value ; 
}
; 
struct _GParamSpecBoolean {
  GParamSpec parent_instance ; 
  gboolean default_value ; 
}
; 
struct _GParamSpecInt {
  GParamSpec parent_instance ; 
  gint minimum ; 
  gint maximum ; 
  gint default_value ; 
}
; 
struct _GParamSpecUInt {
  GParamSpec parent_instance ; 
  guint minimum ; 
  guint maximum ; 
  guint default_value ; 
}
; 
struct _GParamSpecLong {
  GParamSpec parent_instance ; 
  glong minimum ; 
  glong maximum ; 
  glong default_value ; 
}
; 
struct _GParamSpecULong {
  GParamSpec parent_instance ; 
  gulong minimum ; 
  gulong maximum ; 
  gulong default_value ; 
}
; 
struct _GParamSpecInt64 {
  GParamSpec parent_instance ; 
  gint64 minimum ; 
  gint64 maximum ; 
  gint64 default_value ; 
}
; 
struct _GParamSpecUInt64 {
  GParamSpec parent_instance ; 
  guint64 minimum ; 
  guint64 maximum ; 
  guint64 default_value ; 
}
; 
struct _GParamSpecUnichar {
  GParamSpec parent_instance ; 
  gunichar default_value ; 
}
; 
struct _GParamSpecEnum {
  GParamSpec parent_instance ; 
  GEnumClass * enum_class ; 
  gint default_value ; 
}
; 
struct _GParamSpecFlags {
  GParamSpec parent_instance ; 
  GFlagsClass * flags_class ; 
  guint default_value ; 
}
; 
struct _GParamSpecFloat {
  GParamSpec parent_instance ; 
  gfloat minimum ; 
  gfloat maximum ; 
  gfloat default_value ; 
  gfloat epsilon ; 
}
; 
struct _GParamSpecDouble {
  GParamSpec parent_instance ; 
  gdouble minimum ; 
  gdouble maximum ; 
  gdouble default_value ; 
  gdouble epsilon ; 
}
; 
struct _GParamSpecString {
  GParamSpec parent_instance ; 
  gchar * default_value ; 
  gchar * cset_first ; 
  gchar * cset_nth ; 
  gchar substitutor ; 
  guint null_fold_if_empty : 1 ; 
  guint ensure_non_null : 1 ; 
}
; 
struct _GParamSpecParam {
  GParamSpec parent_instance ; 
}
; 
struct _GParamSpecBoxed {
  GParamSpec parent_instance ; 
}
; 
struct _GParamSpecPointer {
  GParamSpec parent_instance ; 
}
; 
struct _GParamSpecValueArray {
  GParamSpec parent_instance ; 
  GParamSpec * element_spec ; 
  guint fixed_n_elements ; 
}
; 
struct _GParamSpecObject {
  GParamSpec parent_instance ; 
}
; 
struct _GParamSpecOverride {
  GParamSpec parent_instance ; 
  GParamSpec * overridden ; 
}
; 
struct _GParamSpecGType {
  GParamSpec parent_instance ; 
  GType is_a_type ; 
}
; 
struct _GParamSpecVariant {
  GParamSpec parent_instance ; 
  GVariantType * type ; 
  GVariant * default_value ; 
  gpointer padding [4 ] ; 
}
; 
typedef struct _GTypeModule GTypeModule ; 
struct _GTypeModule {
  GObject parent_instance ; 
  guint use_count ; 
  GSList * type_infos ; 
  GSList * interface_infos ; 
  gchar * name ; 
}
; 
struct _GTypeModuleClass {
  GObjectClass parent_class ; 
  gboolean (* load ) (GTypeModule * module ) ; 
  void (* unload ) (GTypeModule * module ) ; 
  void (* reserved1 ) (void ) ; 
  void (* reserved2 ) (void ) ; 
  void (* reserved3 ) (void ) ; 
  void (* reserved4 ) (void ) ; 
}
; 
typedef void (* GTypePluginUse ) (GTypePlugin * plugin ) ; 
typedef void (* GTypePluginUnuse ) (GTypePlugin * plugin ) ; 
typedef void (* GTypePluginCompleteTypeInfo ) (GTypePlugin * plugin , GType g_type , GTypeInfo * info , GTypeValueTable * value_table ) ; 
typedef void (* GTypePluginCompleteInterfaceInfo ) (GTypePlugin * plugin , GType instance_type , GType interface_type , GInterfaceInfo * info ) ; 
struct _GTypePluginClass {
  GTypeInterface base_iface ; 
  GTypePluginUse use_plugin ; 
  GTypePluginUnuse unuse_plugin ; 
  GTypePluginCompleteTypeInfo complete_type_info ; 
  GTypePluginCompleteInterfaceInfo complete_interface_info ; 
}
; 
typedef struct _GValueArray GValueArray ; 
struct _GValueArray {
  guint n_values ; 
  GValue * values ; 
  guint n_prealloced ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_value_take_string" "' instead" ) ) ) void g_value_set_string_take_ownership (GValue * value , gchar * v_string ) ; 
typedef enum {
  G_APP_INFO_CREATE_NONE = 0 , G_APP_INFO_CREATE_NEEDS_TERMINAL = (1 << 0 ) , G_APP_INFO_CREATE_SUPPORTS_URIS = (1 << 1 ) , G_APP_INFO_CREATE_SUPPORTS_STARTUP_NOTIFICATION = (1 << 2 ) }
GAppInfoCreateFlags ; 
typedef enum {
  G_CONVERTER_NO_FLAGS = 0 , G_CONVERTER_INPUT_AT_END = (1 << 0 ) , G_CONVERTER_FLUSH = (1 << 1 ) }
GConverterFlags ; 
typedef enum {
  G_CONVERTER_ERROR = 0 , G_CONVERTER_CONVERTED = 1 , G_CONVERTER_FINISHED = 2 , G_CONVERTER_FLUSHED = 3 }
GConverterResult ; 
typedef enum {
  G_DATA_STREAM_BYTE_ORDER_BIG_ENDIAN , G_DATA_STREAM_BYTE_ORDER_LITTLE_ENDIAN , G_DATA_STREAM_BYTE_ORDER_HOST_ENDIAN }
GDataStreamByteOrder ; 
typedef enum {
  G_DATA_STREAM_NEWLINE_TYPE_LF , G_DATA_STREAM_NEWLINE_TYPE_CR , G_DATA_STREAM_NEWLINE_TYPE_CR_LF , G_DATA_STREAM_NEWLINE_TYPE_ANY }
GDataStreamNewlineType ; 
typedef enum {
  G_FILE_ATTRIBUTE_TYPE_INVALID = 0 , G_FILE_ATTRIBUTE_TYPE_STRING , G_FILE_ATTRIBUTE_TYPE_BYTE_STRING , G_FILE_ATTRIBUTE_TYPE_BOOLEAN , G_FILE_ATTRIBUTE_TYPE_UINT32 , G_FILE_ATTRIBUTE_TYPE_INT32 , G_FILE_ATTRIBUTE_TYPE_UINT64 , G_FILE_ATTRIBUTE_TYPE_INT64 , G_FILE_ATTRIBUTE_TYPE_OBJECT , G_FILE_ATTRIBUTE_TYPE_STRINGV }
GFileAttributeType ; 
typedef enum {
  G_FILE_ATTRIBUTE_INFO_NONE = 0 , G_FILE_ATTRIBUTE_INFO_COPY_WITH_FILE = (1 << 0 ) , G_FILE_ATTRIBUTE_INFO_COPY_WHEN_MOVED = (1 << 1 ) }
GFileAttributeInfoFlags ; 
typedef enum {
  G_FILE_ATTRIBUTE_STATUS_UNSET = 0 , G_FILE_ATTRIBUTE_STATUS_SET , G_FILE_ATTRIBUTE_STATUS_ERROR_SETTING }
GFileAttributeStatus ; 
typedef enum {
  G_FILE_QUERY_INFO_NONE = 0 , G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS = (1 << 0 ) }
GFileQueryInfoFlags ; 
typedef enum {
  G_FILE_CREATE_NONE = 0 , G_FILE_CREATE_PRIVATE = (1 << 0 ) , G_FILE_CREATE_REPLACE_DESTINATION = (1 << 1 ) }
GFileCreateFlags ; 
typedef enum {
  G_MOUNT_MOUNT_NONE = 0 }
GMountMountFlags ; 
typedef enum {
  G_MOUNT_UNMOUNT_NONE = 0 , G_MOUNT_UNMOUNT_FORCE = (1 << 0 ) }
GMountUnmountFlags ; 
typedef enum {
  G_DRIVE_START_NONE = 0 }
GDriveStartFlags ; 
typedef enum {
  G_DRIVE_START_STOP_TYPE_UNKNOWN , G_DRIVE_START_STOP_TYPE_SHUTDOWN , G_DRIVE_START_STOP_TYPE_NETWORK , G_DRIVE_START_STOP_TYPE_MULTIDISK , G_DRIVE_START_STOP_TYPE_PASSWORD }
GDriveStartStopType ; 
typedef enum {
  G_FILE_COPY_NONE = 0 , G_FILE_COPY_OVERWRITE = (1 << 0 ) , G_FILE_COPY_BACKUP = (1 << 1 ) , G_FILE_COPY_NOFOLLOW_SYMLINKS = (1 << 2 ) , G_FILE_COPY_ALL_METADATA = (1 << 3 ) , G_FILE_COPY_NO_FALLBACK_FOR_MOVE = (1 << 4 ) , G_FILE_COPY_TARGET_DEFAULT_PERMS = (1 << 5 ) }
GFileCopyFlags ; 
typedef enum {
  G_FILE_MONITOR_NONE = 0 , G_FILE_MONITOR_WATCH_MOUNTS = (1 << 0 ) , G_FILE_MONITOR_SEND_MOVED = (1 << 1 ) }
GFileMonitorFlags ; 
typedef enum {
  G_FILE_TYPE_UNKNOWN = 0 , G_FILE_TYPE_REGULAR , G_FILE_TYPE_DIRECTORY , G_FILE_TYPE_SYMBOLIC_LINK , G_FILE_TYPE_SPECIAL , G_FILE_TYPE_SHORTCUT , G_FILE_TYPE_MOUNTABLE }
GFileType ; 
typedef enum {
  G_FILESYSTEM_PREVIEW_TYPE_IF_ALWAYS = 0 , G_FILESYSTEM_PREVIEW_TYPE_IF_LOCAL , G_FILESYSTEM_PREVIEW_TYPE_NEVER }
GFilesystemPreviewType ; 
typedef enum {
  G_FILE_MONITOR_EVENT_CHANGED , G_FILE_MONITOR_EVENT_CHANGES_DONE_HINT , G_FILE_MONITOR_EVENT_DELETED , G_FILE_MONITOR_EVENT_CREATED , G_FILE_MONITOR_EVENT_ATTRIBUTE_CHANGED , G_FILE_MONITOR_EVENT_PRE_UNMOUNT , G_FILE_MONITOR_EVENT_UNMOUNTED , G_FILE_MONITOR_EVENT_MOVED }
GFileMonitorEvent ; 
typedef enum {
  G_IO_ERROR_FAILED , G_IO_ERROR_NOT_FOUND , G_IO_ERROR_EXISTS , G_IO_ERROR_IS_DIRECTORY , G_IO_ERROR_NOT_DIRECTORY , G_IO_ERROR_NOT_EMPTY , G_IO_ERROR_NOT_REGULAR_FILE , G_IO_ERROR_NOT_SYMBOLIC_LINK , G_IO_ERROR_NOT_MOUNTABLE_FILE , G_IO_ERROR_FILENAME_TOO_LONG , G_IO_ERROR_INVALID_FILENAME , G_IO_ERROR_TOO_MANY_LINKS , G_IO_ERROR_NO_SPACE , G_IO_ERROR_INVALID_ARGUMENT , G_IO_ERROR_PERMISSION_DENIED , G_IO_ERROR_NOT_SUPPORTED , G_IO_ERROR_NOT_MOUNTED , G_IO_ERROR_ALREADY_MOUNTED , G_IO_ERROR_CLOSED , G_IO_ERROR_CANCELLED , G_IO_ERROR_PENDING , G_IO_ERROR_READ_ONLY , G_IO_ERROR_CANT_CREATE_BACKUP , G_IO_ERROR_WRONG_ETAG , G_IO_ERROR_TIMED_OUT , G_IO_ERROR_WOULD_RECURSE , G_IO_ERROR_BUSY , G_IO_ERROR_WOULD_BLOCK , G_IO_ERROR_HOST_NOT_FOUND , G_IO_ERROR_WOULD_MERGE , G_IO_ERROR_FAILED_HANDLED , G_IO_ERROR_TOO_MANY_OPEN_FILES , G_IO_ERROR_NOT_INITIALIZED , G_IO_ERROR_ADDRESS_IN_USE , G_IO_ERROR_PARTIAL_INPUT , G_IO_ERROR_INVALID_DATA , G_IO_ERROR_DBUS_ERROR , G_IO_ERROR_HOST_UNREACHABLE , G_IO_ERROR_NETWORK_UNREACHABLE , G_IO_ERROR_CONNECTION_REFUSED , G_IO_ERROR_PROXY_FAILED , G_IO_ERROR_PROXY_AUTH_FAILED , G_IO_ERROR_PROXY_NEED_AUTH , G_IO_ERROR_PROXY_NOT_ALLOWED }
GIOErrorEnum ; 
typedef enum {
  G_ASK_PASSWORD_NEED_PASSWORD = (1 << 0 ) , G_ASK_PASSWORD_NEED_USERNAME = (1 << 1 ) , G_ASK_PASSWORD_NEED_DOMAIN = (1 << 2 ) , G_ASK_PASSWORD_SAVING_SUPPORTED = (1 << 3 ) , G_ASK_PASSWORD_ANONYMOUS_SUPPORTED = (1 << 4 ) }
GAskPasswordFlags ; 
typedef enum {
  G_PASSWORD_SAVE_NEVER , G_PASSWORD_SAVE_FOR_SESSION , G_PASSWORD_SAVE_PERMANENTLY }
GPasswordSave ; 
typedef enum {
  G_MOUNT_OPERATION_HANDLED , G_MOUNT_OPERATION_ABORTED , G_MOUNT_OPERATION_UNHANDLED }
GMountOperationResult ; 
typedef enum {
  G_OUTPUT_STREAM_SPLICE_NONE = 0 , G_OUTPUT_STREAM_SPLICE_CLOSE_SOURCE = (1 << 0 ) , G_OUTPUT_STREAM_SPLICE_CLOSE_TARGET = (1 << 1 ) }
GOutputStreamSpliceFlags ; 
typedef enum {
  G_IO_STREAM_SPLICE_NONE = 0 , G_IO_STREAM_SPLICE_CLOSE_STREAM1 = (1 << 0 ) , G_IO_STREAM_SPLICE_CLOSE_STREAM2 = (1 << 1 ) , G_IO_STREAM_SPLICE_WAIT_FOR_BOTH = (1 << 2 ) }
GIOStreamSpliceFlags ; 
typedef enum {
  G_EMBLEM_ORIGIN_UNKNOWN , G_EMBLEM_ORIGIN_DEVICE , G_EMBLEM_ORIGIN_LIVEMETADATA , G_EMBLEM_ORIGIN_TAG }
GEmblemOrigin ; 
typedef enum {
  G_RESOLVER_ERROR_NOT_FOUND , G_RESOLVER_ERROR_TEMPORARY_FAILURE , G_RESOLVER_ERROR_INTERNAL }
GResolverError ; 
typedef enum {
  G_RESOURCE_ERROR_NOT_FOUND , G_RESOURCE_ERROR_INTERNAL }
GResourceError ; 
typedef enum {
  G_RESOURCE_FLAGS_NONE = 0 , G_RESOURCE_FLAGS_COMPRESSED = (1 << 0 ) }
GResourceFlags ; 
typedef enum {
  G_RESOURCE_LOOKUP_FLAGS_NONE = 0 }
GResourceLookupFlags ; 
typedef enum {
  G_SOCKET_FAMILY_INVALID , G_SOCKET_FAMILY_UNIX = 1 , G_SOCKET_FAMILY_IPV4 = 2 , G_SOCKET_FAMILY_IPV6 = 10 }
GSocketFamily ; 
typedef enum {
  G_SOCKET_TYPE_INVALID , G_SOCKET_TYPE_STREAM , G_SOCKET_TYPE_DATAGRAM , G_SOCKET_TYPE_SEQPACKET }
GSocketType ; 
typedef enum {
  G_SOCKET_MSG_NONE , G_SOCKET_MSG_OOB = 1 , G_SOCKET_MSG_PEEK = 2 , G_SOCKET_MSG_DONTROUTE = 4 }
GSocketMsgFlags ; 
typedef enum {
  G_SOCKET_PROTOCOL_UNKNOWN = - 1 , G_SOCKET_PROTOCOL_DEFAULT = 0 , G_SOCKET_PROTOCOL_TCP = 6 , G_SOCKET_PROTOCOL_UDP = 17 , G_SOCKET_PROTOCOL_SCTP = 132 }
GSocketProtocol ; 
typedef enum {
  G_ZLIB_COMPRESSOR_FORMAT_ZLIB , G_ZLIB_COMPRESSOR_FORMAT_GZIP , G_ZLIB_COMPRESSOR_FORMAT_RAW }
GZlibCompressorFormat ; 
typedef enum {
  G_UNIX_SOCKET_ADDRESS_INVALID , G_UNIX_SOCKET_ADDRESS_ANONYMOUS , G_UNIX_SOCKET_ADDRESS_PATH , G_UNIX_SOCKET_ADDRESS_ABSTRACT , G_UNIX_SOCKET_ADDRESS_ABSTRACT_PADDED }
GUnixSocketAddressType ; 
typedef enum {
  G_BUS_TYPE_STARTER = - 1 , G_BUS_TYPE_NONE = 0 , G_BUS_TYPE_SYSTEM = 1 , G_BUS_TYPE_SESSION = 2 }
GBusType ; 
typedef enum {
  G_BUS_NAME_OWNER_FLAGS_NONE = 0 , G_BUS_NAME_OWNER_FLAGS_ALLOW_REPLACEMENT = (1 << 0 ) , G_BUS_NAME_OWNER_FLAGS_REPLACE = (1 << 1 ) }
GBusNameOwnerFlags ; 
typedef enum {
  G_BUS_NAME_WATCHER_FLAGS_NONE = 0 , G_BUS_NAME_WATCHER_FLAGS_AUTO_START = (1 << 0 ) }
GBusNameWatcherFlags ; 
typedef enum {
  G_DBUS_PROXY_FLAGS_NONE = 0 , G_DBUS_PROXY_FLAGS_DO_NOT_LOAD_PROPERTIES = (1 << 0 ) , G_DBUS_PROXY_FLAGS_DO_NOT_CONNECT_SIGNALS = (1 << 1 ) , G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START = (1 << 2 ) , G_DBUS_PROXY_FLAGS_GET_INVALIDATED_PROPERTIES = (1 << 3 ) }
GDBusProxyFlags ; 
typedef enum {
  G_DBUS_ERROR_FAILED , G_DBUS_ERROR_NO_MEMORY , G_DBUS_ERROR_SERVICE_UNKNOWN , G_DBUS_ERROR_NAME_HAS_NO_OWNER , G_DBUS_ERROR_NO_REPLY , G_DBUS_ERROR_IO_ERROR , G_DBUS_ERROR_BAD_ADDRESS , G_DBUS_ERROR_NOT_SUPPORTED , G_DBUS_ERROR_LIMITS_EXCEEDED , G_DBUS_ERROR_ACCESS_DENIED , G_DBUS_ERROR_AUTH_FAILED , G_DBUS_ERROR_NO_SERVER , G_DBUS_ERROR_TIMEOUT , G_DBUS_ERROR_NO_NETWORK , G_DBUS_ERROR_ADDRESS_IN_USE , G_DBUS_ERROR_DISCONNECTED , G_DBUS_ERROR_INVALID_ARGS , G_DBUS_ERROR_FILE_NOT_FOUND , G_DBUS_ERROR_FILE_EXISTS , G_DBUS_ERROR_UNKNOWN_METHOD , G_DBUS_ERROR_TIMED_OUT , G_DBUS_ERROR_MATCH_RULE_NOT_FOUND , G_DBUS_ERROR_MATCH_RULE_INVALID , G_DBUS_ERROR_SPAWN_EXEC_FAILED , G_DBUS_ERROR_SPAWN_FORK_FAILED , G_DBUS_ERROR_SPAWN_CHILD_EXITED , G_DBUS_ERROR_SPAWN_CHILD_SIGNALED , G_DBUS_ERROR_SPAWN_FAILED , G_DBUS_ERROR_SPAWN_SETUP_FAILED , G_DBUS_ERROR_SPAWN_CONFIG_INVALID , G_DBUS_ERROR_SPAWN_SERVICE_INVALID , G_DBUS_ERROR_SPAWN_SERVICE_NOT_FOUND , G_DBUS_ERROR_SPAWN_PERMISSIONS_INVALID , G_DBUS_ERROR_SPAWN_FILE_INVALID , G_DBUS_ERROR_SPAWN_NO_MEMORY , G_DBUS_ERROR_UNIX_PROCESS_ID_UNKNOWN , G_DBUS_ERROR_INVALID_SIGNATURE , G_DBUS_ERROR_INVALID_FILE_CONTENT , G_DBUS_ERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN , G_DBUS_ERROR_ADT_AUDIT_DATA_UNKNOWN , G_DBUS_ERROR_OBJECT_PATH_IN_USE }
GDBusError ; 
typedef enum {
  G_DBUS_CONNECTION_FLAGS_NONE = 0 , G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT = (1 << 0 ) , G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_SERVER = (1 << 1 ) , G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS = (1 << 2 ) , G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION = (1 << 3 ) , G_DBUS_CONNECTION_FLAGS_DELAY_MESSAGE_PROCESSING = (1 << 4 ) }
GDBusConnectionFlags ; 
typedef enum {
  G_DBUS_CAPABILITY_FLAGS_NONE = 0 , G_DBUS_CAPABILITY_FLAGS_UNIX_FD_PASSING = (1 << 0 ) }
GDBusCapabilityFlags ; 
typedef enum {
  G_DBUS_CALL_FLAGS_NONE = 0 , G_DBUS_CALL_FLAGS_NO_AUTO_START = (1 << 0 ) }
GDBusCallFlags ; 
typedef enum {
  G_DBUS_MESSAGE_TYPE_INVALID , G_DBUS_MESSAGE_TYPE_METHOD_CALL , G_DBUS_MESSAGE_TYPE_METHOD_RETURN , G_DBUS_MESSAGE_TYPE_ERROR , G_DBUS_MESSAGE_TYPE_SIGNAL }
GDBusMessageType ; 
typedef enum {
  G_DBUS_MESSAGE_FLAGS_NONE = 0 , G_DBUS_MESSAGE_FLAGS_NO_REPLY_EXPECTED = (1 << 0 ) , G_DBUS_MESSAGE_FLAGS_NO_AUTO_START = (1 << 1 ) }
GDBusMessageFlags ; 
typedef enum {
  G_DBUS_MESSAGE_HEADER_FIELD_INVALID , G_DBUS_MESSAGE_HEADER_FIELD_PATH , G_DBUS_MESSAGE_HEADER_FIELD_INTERFACE , G_DBUS_MESSAGE_HEADER_FIELD_MEMBER , G_DBUS_MESSAGE_HEADER_FIELD_ERROR_NAME , G_DBUS_MESSAGE_HEADER_FIELD_REPLY_SERIAL , G_DBUS_MESSAGE_HEADER_FIELD_DESTINATION , G_DBUS_MESSAGE_HEADER_FIELD_SENDER , G_DBUS_MESSAGE_HEADER_FIELD_SIGNATURE , G_DBUS_MESSAGE_HEADER_FIELD_NUM_UNIX_FDS }
GDBusMessageHeaderField ; 
typedef enum {
  G_DBUS_PROPERTY_INFO_FLAGS_NONE = 0 , G_DBUS_PROPERTY_INFO_FLAGS_READABLE = (1 << 0 ) , G_DBUS_PROPERTY_INFO_FLAGS_WRITABLE = (1 << 1 ) }
GDBusPropertyInfoFlags ; 
typedef enum {
  G_DBUS_SUBTREE_FLAGS_NONE = 0 , G_DBUS_SUBTREE_FLAGS_DISPATCH_TO_UNENUMERATED_NODES = (1 << 0 ) }
GDBusSubtreeFlags ; 
typedef enum {
  G_DBUS_SERVER_FLAGS_NONE = 0 , G_DBUS_SERVER_FLAGS_RUN_IN_THREAD = (1 << 0 ) , G_DBUS_SERVER_FLAGS_AUTHENTICATION_ALLOW_ANONYMOUS = (1 << 1 ) }
GDBusServerFlags ; 
typedef enum {
  G_DBUS_SIGNAL_FLAGS_NONE = 0 , G_DBUS_SIGNAL_FLAGS_NO_MATCH_RULE = (1 << 0 ) }
GDBusSignalFlags ; 
typedef enum {
  G_DBUS_SEND_MESSAGE_FLAGS_NONE = 0 , G_DBUS_SEND_MESSAGE_FLAGS_PRESERVE_SERIAL = (1 << 0 ) }
GDBusSendMessageFlags ; 
typedef enum {
  G_CREDENTIALS_TYPE_INVALID , G_CREDENTIALS_TYPE_LINUX_UCRED , G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED , G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED }
GCredentialsType ; 
typedef enum {
  G_DBUS_MESSAGE_BYTE_ORDER_BIG_ENDIAN = 'B' , G_DBUS_MESSAGE_BYTE_ORDER_LITTLE_ENDIAN = 'l' }
GDBusMessageByteOrder ; 
typedef enum {
  G_APPLICATION_FLAGS_NONE , G_APPLICATION_IS_SERVICE = (1 << 0 ) , G_APPLICATION_IS_LAUNCHER = (1 << 1 ) , G_APPLICATION_HANDLES_OPEN = (1 << 2 ) , G_APPLICATION_HANDLES_COMMAND_LINE = (1 << 3 ) , G_APPLICATION_SEND_ENVIRONMENT = (1 << 4 ) , G_APPLICATION_NON_UNIQUE = (1 << 5 ) }
GApplicationFlags ; 
typedef enum {
  G_TLS_ERROR_UNAVAILABLE , G_TLS_ERROR_MISC , G_TLS_ERROR_BAD_CERTIFICATE , G_TLS_ERROR_NOT_TLS , G_TLS_ERROR_HANDSHAKE , G_TLS_ERROR_CERTIFICATE_REQUIRED , G_TLS_ERROR_EOF }
GTlsError ; 
typedef enum {
  G_TLS_CERTIFICATE_UNKNOWN_CA = (1 << 0 ) , G_TLS_CERTIFICATE_BAD_IDENTITY = (1 << 1 ) , G_TLS_CERTIFICATE_NOT_ACTIVATED = (1 << 2 ) , G_TLS_CERTIFICATE_EXPIRED = (1 << 3 ) , G_TLS_CERTIFICATE_REVOKED = (1 << 4 ) , G_TLS_CERTIFICATE_INSECURE = (1 << 5 ) , G_TLS_CERTIFICATE_GENERIC_ERROR = (1 << 6 ) , G_TLS_CERTIFICATE_VALIDATE_ALL = 0x007f }
GTlsCertificateFlags ; 
typedef enum {
  G_TLS_AUTHENTICATION_NONE , G_TLS_AUTHENTICATION_REQUESTED , G_TLS_AUTHENTICATION_REQUIRED }
GTlsAuthenticationMode ; 
typedef enum {
  G_TLS_REHANDSHAKE_NEVER , G_TLS_REHANDSHAKE_SAFELY , G_TLS_REHANDSHAKE_UNSAFELY }
GTlsRehandshakeMode ; 
typedef enum _GTlsPasswordFlags {
  G_TLS_PASSWORD_NONE = 0 , G_TLS_PASSWORD_RETRY = 1 << 1 , G_TLS_PASSWORD_MANY_TRIES = 1 << 2 , G_TLS_PASSWORD_FINAL_TRY = 1 << 3 }
GTlsPasswordFlags ; 
typedef enum {
  G_TLS_INTERACTION_UNHANDLED , G_TLS_INTERACTION_HANDLED , G_TLS_INTERACTION_FAILED }
GTlsInteractionResult ; 
typedef enum {
  G_DBUS_INTERFACE_SKELETON_FLAGS_NONE = 0 , G_DBUS_INTERFACE_SKELETON_FLAGS_HANDLE_METHOD_INVOCATIONS_IN_THREAD = (1 << 0 ) }
GDBusInterfaceSkeletonFlags ; 
typedef enum {
  G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_NONE = 0 , G_DBUS_OBJECT_MANAGER_CLIENT_FLAGS_DO_NOT_AUTO_START = (1 << 0 ) }
GDBusObjectManagerClientFlags ; 
typedef enum {
  G_TLS_DATABASE_VERIFY_NONE = 0 }
GTlsDatabaseVerifyFlags ; 
typedef enum {
  G_TLS_DATABASE_LOOKUP_NONE = 0 , G_TLS_DATABASE_LOOKUP_KEYPAIR = 1 }
GTlsDatabaseLookupFlags ; 
typedef enum {
  G_IO_MODULE_SCOPE_NONE , G_IO_MODULE_SCOPE_BLOCK_DUPLICATES }
GIOModuleScopeFlags ; 
typedef enum {
  G_SOCKET_CLIENT_RESOLVING , G_SOCKET_CLIENT_RESOLVED , G_SOCKET_CLIENT_CONNECTING , G_SOCKET_CLIENT_CONNECTED , G_SOCKET_CLIENT_PROXY_NEGOTIATING , G_SOCKET_CLIENT_PROXY_NEGOTIATED , G_SOCKET_CLIENT_TLS_HANDSHAKING , G_SOCKET_CLIENT_TLS_HANDSHAKED , G_SOCKET_CLIENT_COMPLETE }
GSocketClientEvent ; 
typedef struct _GAppLaunchContext GAppLaunchContext ; 
typedef struct _GAppInfo GAppInfo ; 
typedef struct _GAsyncResult GAsyncResult ; 
typedef struct _GAsyncInitable GAsyncInitable ; 
typedef struct _GBufferedInputStream GBufferedInputStream ; 
typedef struct _GBufferedOutputStream GBufferedOutputStream ; 
typedef struct _GCancellable GCancellable ; 
typedef struct _GCharsetConverter GCharsetConverter ; 
typedef struct _GConverter GConverter ; 
typedef struct _GConverterInputStream GConverterInputStream ; 
typedef struct _GConverterOutputStream GConverterOutputStream ; 
typedef struct _GDataInputStream GDataInputStream ; 
typedef struct _GZlibCompressor GZlibCompressor ; 
typedef struct _GZlibDecompressor GZlibDecompressor ; 
typedef struct _GSimpleActionGroup GSimpleActionGroup ; 
typedef struct _GRemoteActionGroup GRemoteActionGroup ; 
typedef struct _GDBusActionGroup GDBusActionGroup ; 
typedef struct _GActionMap GActionMap ; 
typedef struct _GActionGroup GActionGroup ; 
typedef struct _GSimpleAction GSimpleAction ; 
typedef struct _GAction GAction ; 
typedef struct _GApplication GApplication ; 
typedef struct _GApplicationCommandLine GApplicationCommandLine ; 
typedef struct _GSettingsBackend GSettingsBackend ; 
typedef struct _GSettings GSettings ; 
typedef struct _GPermission GPermission ; 
typedef struct _GMenuModel GMenuModel ; 
typedef struct _GDrive GDrive ; 
typedef struct _GFileEnumerator GFileEnumerator ; 
typedef struct _GFileMonitor GFileMonitor ; 
typedef struct _GFilterInputStream GFilterInputStream ; 
typedef struct _GFilterOutputStream GFilterOutputStream ; 
typedef struct _GFile GFile ; 
typedef struct _GFileInfo GFileInfo ; 
typedef struct _GFileAttributeMatcher GFileAttributeMatcher ; 
typedef struct _GFileAttributeInfo GFileAttributeInfo ; 
typedef struct _GFileAttributeInfoList GFileAttributeInfoList ; 
typedef struct _GFileInputStream GFileInputStream ; 
typedef struct _GFileOutputStream GFileOutputStream ; 
typedef struct _GFileIOStream GFileIOStream ; 
typedef struct _GFileIcon GFileIcon ; 
typedef struct _GFilenameCompleter GFilenameCompleter ; 
typedef struct _GIcon GIcon ; 
typedef struct _GInetAddress GInetAddress ; 
typedef struct _GInetAddressMask GInetAddressMask ; 
typedef struct _GInetSocketAddress GInetSocketAddress ; 
typedef struct _GInputStream GInputStream ; 
typedef struct _GInitable GInitable ; 
typedef struct _GIOModule GIOModule ; 
typedef struct _GIOExtensionPoint GIOExtensionPoint ; 
typedef struct _GIOExtension GIOExtension ; 
typedef struct _GIOSchedulerJob GIOSchedulerJob ; 
typedef struct _GLoadableIcon GLoadableIcon ; 
typedef struct _GMemoryInputStream GMemoryInputStream ; 
typedef struct _GMemoryOutputStream GMemoryOutputStream ; 
typedef struct _GMount GMount ; 
typedef struct _GMountOperation GMountOperation ; 
typedef struct _GNetworkAddress GNetworkAddress ; 
typedef struct _GNetworkMonitor GNetworkMonitor ; 
typedef struct _GNetworkService GNetworkService ; 
typedef struct _GOutputStream GOutputStream ; 
typedef struct _GIOStream GIOStream ; 
typedef struct _GPollableInputStream GPollableInputStream ; 
typedef struct _GPollableOutputStream GPollableOutputStream ; 
typedef struct _GResolver GResolver ; 
typedef struct _GResource GResource ; 
typedef struct _GSeekable GSeekable ; 
typedef struct _GSimpleAsyncResult GSimpleAsyncResult ; 
typedef struct _GSocket GSocket ; 
typedef struct _GSocketControlMessage GSocketControlMessage ; 
typedef struct _GSocketClient GSocketClient ; 
typedef struct _GSocketConnection GSocketConnection ; 
typedef struct _GSocketListener GSocketListener ; 
typedef struct _GSocketService GSocketService ; 
typedef struct _GSocketAddress GSocketAddress ; 
typedef struct _GSocketAddressEnumerator GSocketAddressEnumerator ; 
typedef struct _GSocketConnectable GSocketConnectable ; 
typedef struct _GSrvTarget GSrvTarget ; 
typedef struct _GTcpConnection GTcpConnection ; 
typedef struct _GTcpWrapperConnection GTcpWrapperConnection ; 
typedef struct _GThreadedSocketService GThreadedSocketService ; 
typedef struct _GThemedIcon GThemedIcon ; 
typedef struct _GTlsCertificate GTlsCertificate ; 
typedef struct _GTlsClientConnection GTlsClientConnection ; 
typedef struct _GTlsConnection GTlsConnection ; 
typedef struct _GTlsDatabase GTlsDatabase ; 
typedef struct _GTlsInteraction GTlsInteraction ; 
typedef struct _GTlsPassword GTlsPassword ; 
typedef struct _GVfs GVfs ; 
typedef struct _GProxyResolver GProxyResolver ; 
typedef struct _GProxy GProxy ; 
typedef struct _GProxyAddress GProxyAddress ; 
typedef struct _GVolume GVolume ; 
typedef struct _GVolumeMonitor GVolumeMonitor ; 
typedef void (* GAsyncReadyCallback ) (GObject * source_object , GAsyncResult * res , gpointer user_data ) ; 
typedef void (* GFileProgressCallback ) (goffset current_num_bytes , goffset total_num_bytes , gpointer user_data ) ; 
typedef gboolean (* GFileReadMoreCallback ) (const char * file_contents , goffset file_size , gpointer callback_data ) ; 
typedef gboolean (* GIOSchedulerJobFunc ) (GIOSchedulerJob * job , GCancellable * cancellable , gpointer user_data ) ; 
typedef void (* GSimpleAsyncThreadFunc ) (GSimpleAsyncResult * res , GObject * object , GCancellable * cancellable ) ; 
typedef gboolean (* GSocketSourceFunc ) (GSocket * socket , GIOCondition condition , gpointer user_data ) ; 
typedef struct _GInputVector GInputVector ; 
struct _GInputVector {
  gpointer buffer ; 
  gsize size ; 
}
; 
typedef struct _GOutputVector GOutputVector ; 
struct _GOutputVector {
  gconstpointer buffer ; 
  gsize size ; 
}
; 
typedef struct _GCredentials GCredentials ; 
typedef struct _GUnixFDList GUnixFDList ; 
typedef struct _GDBusMessage GDBusMessage ; 
typedef struct _GDBusConnection GDBusConnection ; 
typedef struct _GDBusProxy GDBusProxy ; 
typedef struct _GDBusMethodInvocation GDBusMethodInvocation ; 
typedef struct _GDBusServer GDBusServer ; 
typedef struct _GDBusAuthObserver GDBusAuthObserver ; 
typedef struct _GDBusErrorEntry GDBusErrorEntry ; 
typedef struct _GDBusInterfaceVTable GDBusInterfaceVTable ; 
typedef struct _GDBusSubtreeVTable GDBusSubtreeVTable ; 
typedef struct _GDBusAnnotationInfo GDBusAnnotationInfo ; 
typedef struct _GDBusArgInfo GDBusArgInfo ; 
typedef struct _GDBusMethodInfo GDBusMethodInfo ; 
typedef struct _GDBusSignalInfo GDBusSignalInfo ; 
typedef struct _GDBusPropertyInfo GDBusPropertyInfo ; 
typedef struct _GDBusInterfaceInfo GDBusInterfaceInfo ; 
typedef struct _GDBusNodeInfo GDBusNodeInfo ; 
typedef gboolean (* GCancellableSourceFunc ) (GCancellable * cancellable , gpointer user_data ) ; 
typedef gboolean (* GPollableSourceFunc ) (GObject * pollable_stream , gpointer user_data ) ; 
typedef struct _GDBusInterface GDBusInterface ; 
typedef struct _GDBusInterfaceSkeleton GDBusInterfaceSkeleton ; 
typedef struct _GDBusObject GDBusObject ; 
typedef struct _GDBusObjectSkeleton GDBusObjectSkeleton ; 
typedef struct _GDBusObjectProxy GDBusObjectProxy ; 
typedef struct _GDBusObjectManager GDBusObjectManager ; 
typedef struct _GDBusObjectManagerClient GDBusObjectManagerClient ; 
typedef struct _GDBusObjectManagerServer GDBusObjectManagerServer ; 
typedef GType (* GDBusProxyTypeFunc ) (GDBusObjectManagerClient * manager , const gchar * object_path , const gchar * interface_name , gpointer user_data ) ; 
struct _GActionInterface {
  GTypeInterface g_iface ; 
  const gchar * (* get_name ) (GAction * action ) ; 
  const GVariantType * (* get_parameter_type ) (GAction * action ) ; 
  const GVariantType * (* get_state_type ) (GAction * action ) ; 
  GVariant * (* get_state_hint ) (GAction * action ) ; 
  gboolean (* get_enabled ) (GAction * action ) ; 
  GVariant * (* get_state ) (GAction * action ) ; 
  void (* change_state ) (GAction * action , GVariant * value ) ; 
  void (* activate ) (GAction * action , GVariant * parameter ) ; 
}
; 
struct _GActionGroupInterface {
  GTypeInterface g_iface ; 
  gboolean (* has_action ) (GActionGroup * action_group , const gchar * action_name ) ; 
  gchar * * (* list_actions ) (GActionGroup * action_group ) ; 
  gboolean (* get_action_enabled ) (GActionGroup * action_group , const gchar * action_name ) ; 
  const GVariantType * (* get_action_parameter_type ) (GActionGroup * action_group , const gchar * action_name ) ; 
  const GVariantType * (* get_action_state_type ) (GActionGroup * action_group , const gchar * action_name ) ; 
  GVariant * (* get_action_state_hint ) (GActionGroup * action_group , const gchar * action_name ) ; 
  GVariant * (* get_action_state ) (GActionGroup * action_group , const gchar * action_name ) ; 
  void (* change_action_state ) (GActionGroup * action_group , const gchar * action_name , GVariant * value ) ; 
  void (* activate_action ) (GActionGroup * action_group , const gchar * action_name , GVariant * parameter ) ; 
  void (* action_added ) (GActionGroup * action_group , const gchar * action_name ) ; 
  void (* action_removed ) (GActionGroup * action_group , const gchar * action_name ) ; 
  void (* action_enabled_changed ) (GActionGroup * action_group , const gchar * action_name , gboolean enabled ) ; 
  void (* action_state_changed ) (GActionGroup * action_group , const gchar * action_name , GVariant * state ) ; 
  gboolean (* query_action ) (GActionGroup * action_group , const gchar * action_name , gboolean * enabled , const GVariantType * * parameter_type , const GVariantType * * state_type , GVariant * * state_hint , GVariant * * state ) ; 
}
; 
typedef struct _GActionEntry GActionEntry ; 
struct _GActionMapInterface {
  GTypeInterface g_iface ; 
  GAction * (* lookup_action ) (GActionMap * action_map , const gchar * action_name ) ; 
  void (* add_action ) (GActionMap * action_map , GAction * action ) ; 
  void (* remove_action ) (GActionMap * action_map , const gchar * action_name ) ; 
}
; 
struct _GActionEntry {
  const gchar * name ; 
  void (* activate ) (GSimpleAction * action , GVariant * parameter , gpointer user_data ) ; 
  const gchar * parameter_type ; 
  const gchar * state ; 
  void (* change_state ) (GSimpleAction * action , GVariant * value , gpointer user_data ) ; 
  gsize padding [3 ] ; 
}
; 
typedef struct _GAppLaunchContextPrivate GAppLaunchContextPrivate ; 
struct _GAppInfoIface {
  GTypeInterface g_iface ; 
  GAppInfo * (* dup ) (GAppInfo * appinfo ) ; 
  gboolean (* equal ) (GAppInfo * appinfo1 , GAppInfo * appinfo2 ) ; 
  const char * (* get_id ) (GAppInfo * appinfo ) ; 
  const char * (* get_name ) (GAppInfo * appinfo ) ; 
  const char * (* get_description ) (GAppInfo * appinfo ) ; 
  const char * (* get_executable ) (GAppInfo * appinfo ) ; 
  GIcon * (* get_icon ) (GAppInfo * appinfo ) ; 
  gboolean (* launch ) (GAppInfo * appinfo , GList * files , GAppLaunchContext * launch_context , GError * * error ) ; 
  gboolean (* supports_uris ) (GAppInfo * appinfo ) ; 
  gboolean (* supports_files ) (GAppInfo * appinfo ) ; 
  gboolean (* launch_uris ) (GAppInfo * appinfo , GList * uris , GAppLaunchContext * launch_context , GError * * error ) ; 
  gboolean (* should_show ) (GAppInfo * appinfo ) ; 
  gboolean (* set_as_default_for_type ) (GAppInfo * appinfo , const char * content_type , GError * * error ) ; 
  gboolean (* set_as_default_for_extension ) (GAppInfo * appinfo , const char * extension , GError * * error ) ; 
  gboolean (* add_supports_type ) (GAppInfo * appinfo , const char * content_type , GError * * error ) ; 
  gboolean (* can_remove_supports_type ) (GAppInfo * appinfo ) ; 
  gboolean (* remove_supports_type ) (GAppInfo * appinfo , const char * content_type , GError * * error ) ; 
  gboolean (* can_delete ) (GAppInfo * appinfo ) ; 
  gboolean (* do_delete ) (GAppInfo * appinfo ) ; 
  const char * (* get_commandline ) (GAppInfo * appinfo ) ; 
  const char * (* get_display_name ) (GAppInfo * appinfo ) ; 
  gboolean (* set_as_last_used_for_type ) (GAppInfo * appinfo , const char * content_type , GError * * error ) ; 
}
; 
struct _GAppLaunchContext {
  GObject parent_instance ; 
  GAppLaunchContextPrivate * priv ; 
}
; 
struct _GAppLaunchContextClass {
  GObjectClass parent_class ; 
  char * (* get_display ) (GAppLaunchContext * context , GAppInfo * info , GList * files ) ; 
  char * (* get_startup_notify_id ) (GAppLaunchContext * context , GAppInfo * info , GList * files ) ; 
  void (* launch_failed ) (GAppLaunchContext * context , const char * startup_notify_id ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GApplicationPrivate GApplicationPrivate ; 
struct _GApplication {
  GObject parent_instance ; 
  GApplicationPrivate * priv ; 
}
; 
struct _GApplicationClass {
  GObjectClass parent_class ; 
  void (* startup ) (GApplication * application ) ; 
  void (* activate ) (GApplication * application ) ; 
  void (* open ) (GApplication * application , GFile * * files , gint n_files , const gchar * hint ) ; 
  int (* command_line ) (GApplication * application , GApplicationCommandLine * command_line ) ; 
  gboolean (* local_command_line ) (GApplication * application , gchar * * * arguments , int * exit_status ) ; 
  void (* before_emit ) (GApplication * application , GVariant * platform_data ) ; 
  void (* after_emit ) (GApplication * application , GVariant * platform_data ) ; 
  void (* add_platform_data ) (GApplication * application , GVariantBuilder * builder ) ; 
  void (* quit_mainloop ) (GApplication * application ) ; 
  void (* run_mainloop ) (GApplication * application ) ; 
  void (* shutdown ) (GApplication * application ) ; 
  gpointer padding [11 ] ; 
}
; 
__attribute__ ((__deprecated__ ) ) void g_application_set_action_group (GApplication * application , GActionGroup * action_group ) ; 
typedef struct _GApplicationCommandLinePrivate GApplicationCommandLinePrivate ; 
struct _GApplicationCommandLine {
  GObject parent_instance ; 
  GApplicationCommandLinePrivate * priv ; 
}
; 
struct _GApplicationCommandLineClass {
  GObjectClass parent_class ; 
  void (* print_literal ) (GApplicationCommandLine * cmdline , const gchar * message ) ; 
  void (* printerr_literal ) (GApplicationCommandLine * cmdline , const gchar * message ) ; 
  gpointer padding [12 ] ; 
}
; 
struct _GInitableIface {
  GTypeInterface g_iface ; 
  gboolean (* init ) (GInitable * initable , GCancellable * cancellable , GError * * error ) ; 
}
; 
struct _GAsyncInitableIface {
  GTypeInterface g_iface ; 
  void (* init_async ) (GAsyncInitable * initable , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* init_finish ) (GAsyncInitable * initable , GAsyncResult * res , GError * * error ) ; 
}
; 
struct _GAsyncResultIface {
  GTypeInterface g_iface ; 
  gpointer (* get_user_data ) (GAsyncResult * res ) ; 
  GObject * (* get_source_object ) (GAsyncResult * res ) ; 
}
; 
typedef struct _GInputStreamClass GInputStreamClass ; 
typedef struct _GInputStreamPrivate GInputStreamPrivate ; 
struct _GInputStream {
  GObject parent_instance ; 
  GInputStreamPrivate * priv ; 
}
; 
struct _GInputStreamClass {
  GObjectClass parent_class ; 
  gssize (* read_fn ) (GInputStream * stream , void * buffer , gsize count , GCancellable * cancellable , GError * * error ) ; 
  gssize (* skip ) (GInputStream * stream , gsize count , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* close_fn ) (GInputStream * stream , GCancellable * cancellable , GError * * error ) ; 
  void (* read_async ) (GInputStream * stream , void * buffer , gsize count , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gssize (* read_finish ) (GInputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* skip_async ) (GInputStream * stream , gsize count , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gssize (* skip_finish ) (GInputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* close_async ) (GInputStream * stream , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* close_finish ) (GInputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GFilterInputStreamClass GFilterInputStreamClass ; 
struct _GFilterInputStream {
  GInputStream parent_instance ; 
  GInputStream * base_stream ; 
}
; 
struct _GFilterInputStreamClass {
  GInputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
}
; 
typedef struct _GBufferedInputStreamClass GBufferedInputStreamClass ; 
typedef struct _GBufferedInputStreamPrivate GBufferedInputStreamPrivate ; 
struct _GBufferedInputStream {
  GFilterInputStream parent_instance ; 
  GBufferedInputStreamPrivate * priv ; 
}
; 
struct _GBufferedInputStreamClass {
  GFilterInputStreamClass parent_class ; 
  gssize (* fill ) (GBufferedInputStream * stream , gssize count , GCancellable * cancellable , GError * * error ) ; 
  void (* fill_async ) (GBufferedInputStream * stream , gssize count , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gssize (* fill_finish ) (GBufferedInputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GOutputStreamClass GOutputStreamClass ; 
typedef struct _GOutputStreamPrivate GOutputStreamPrivate ; 
struct _GOutputStream {
  GObject parent_instance ; 
  GOutputStreamPrivate * priv ; 
}
; 
struct _GOutputStreamClass {
  GObjectClass parent_class ; 
  gssize (* write_fn ) (GOutputStream * stream , const void * buffer , gsize count , GCancellable * cancellable , GError * * error ) ; 
  gssize (* splice ) (GOutputStream * stream , GInputStream * source , GOutputStreamSpliceFlags flags , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* flush ) (GOutputStream * stream , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* close_fn ) (GOutputStream * stream , GCancellable * cancellable , GError * * error ) ; 
  void (* write_async ) (GOutputStream * stream , const void * buffer , gsize count , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gssize (* write_finish ) (GOutputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* splice_async ) (GOutputStream * stream , GInputStream * source , GOutputStreamSpliceFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gssize (* splice_finish ) (GOutputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* flush_async ) (GOutputStream * stream , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* flush_finish ) (GOutputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* close_async ) (GOutputStream * stream , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* close_finish ) (GOutputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
  void (* _g_reserved8 ) (void ) ; 
}
; 
typedef struct _GFilterOutputStreamClass GFilterOutputStreamClass ; 
struct _GFilterOutputStream {
  GOutputStream parent_instance ; 
  GOutputStream * base_stream ; 
}
; 
struct _GFilterOutputStreamClass {
  GOutputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
}
; 
typedef struct _GBufferedOutputStreamPrivate GBufferedOutputStreamPrivate ; 
struct _GBufferedOutputStream {
  GFilterOutputStream parent_instance ; 
  GBufferedOutputStreamPrivate * priv ; 
}
; 
struct _GBufferedOutputStreamClass {
  GFilterOutputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
}
; 
typedef struct _GCancellablePrivate GCancellablePrivate ; 
struct _GCancellable {
  GObject parent_instance ; 
  GCancellablePrivate * priv ; 
}
; 
struct _GCancellableClass {
  GObjectClass parent_class ; 
  void (* cancelled ) (GCancellable * cancellable ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
struct _GConverterIface {
  GTypeInterface g_iface ; 
  GConverterResult (* convert ) (GConverter * converter , const void * inbuf , gsize inbuf_size , void * outbuf , gsize outbuf_size , GConverterFlags flags , gsize * bytes_read , gsize * bytes_written , GError * * error ) ; 
  void (* reset ) (GConverter * converter ) ; 
}
; 
struct _GCharsetConverterClass {
  GObjectClass parent_class ; 
}
; 
typedef struct _GConverterInputStreamPrivate GConverterInputStreamPrivate ; 
struct _GConverterInputStream {
  GFilterInputStream parent_instance ; 
  GConverterInputStreamPrivate * priv ; 
}
; 
struct _GConverterInputStreamClass {
  GFilterInputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GConverterOutputStreamPrivate GConverterOutputStreamPrivate ; 
struct _GConverterOutputStream {
  GFilterOutputStream parent_instance ; 
  GConverterOutputStreamPrivate * priv ; 
}
; 
struct _GConverterOutputStreamClass {
  GFilterOutputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef __ssize_t ssize_t ; 
typedef __intptr_t intptr_t ; 
extern ssize_t read (int __fd , void * __buf , size_t __nbytes ) ; 
extern ssize_t write (int __fd , __const void * __buf , size_t __n ) ; 
extern int dup (int __fd ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
enum {
  _PC_LINK_MAX , _PC_MAX_CANON , _PC_MAX_INPUT , _PC_NAME_MAX , _PC_PATH_MAX , _PC_PIPE_BUF , _PC_CHOWN_RESTRICTED , _PC_NO_TRUNC , _PC_VDISABLE , _PC_SYNC_IO , _PC_ASYNC_IO , _PC_PRIO_IO , _PC_SOCK_MAXBUF , _PC_FILESIZEBITS , _PC_REC_INCR_XFER_SIZE , _PC_REC_MAX_XFER_SIZE , _PC_REC_MIN_XFER_SIZE , _PC_REC_XFER_ALIGN , _PC_ALLOC_SIZE_MIN , _PC_SYMLINK_MAX , _PC_2_SYMLINKS }
; 
enum {
  _SC_ARG_MAX , _SC_CHILD_MAX , _SC_CLK_TCK , _SC_NGROUPS_MAX , _SC_OPEN_MAX , _SC_STREAM_MAX , _SC_TZNAME_MAX , _SC_JOB_CONTROL , _SC_SAVED_IDS , _SC_REALTIME_SIGNALS , _SC_PRIORITY_SCHEDULING , _SC_TIMERS , _SC_ASYNCHRONOUS_IO , _SC_PRIORITIZED_IO , _SC_SYNCHRONIZED_IO , _SC_FSYNC , _SC_MAPPED_FILES , _SC_MEMLOCK , _SC_MEMLOCK_RANGE , _SC_MEMORY_PROTECTION , _SC_MESSAGE_PASSING , _SC_SEMAPHORES , _SC_SHARED_MEMORY_OBJECTS , _SC_AIO_LISTIO_MAX , _SC_AIO_MAX , _SC_AIO_PRIO_DELTA_MAX , _SC_DELAYTIMER_MAX , _SC_MQ_OPEN_MAX , _SC_MQ_PRIO_MAX , _SC_VERSION , _SC_PAGESIZE , _SC_RTSIG_MAX , _SC_SEM_NSEMS_MAX , _SC_SEM_VALUE_MAX , _SC_SIGQUEUE_MAX , _SC_TIMER_MAX , _SC_BC_BASE_MAX , _SC_BC_DIM_MAX , _SC_BC_SCALE_MAX , _SC_BC_STRING_MAX , _SC_COLL_WEIGHTS_MAX , _SC_EQUIV_CLASS_MAX , _SC_EXPR_NEST_MAX , _SC_LINE_MAX , _SC_RE_DUP_MAX , _SC_CHARCLASS_NAME_MAX , _SC_2_VERSION , _SC_2_C_BIND , _SC_2_C_DEV , _SC_2_FORT_DEV , _SC_2_FORT_RUN , _SC_2_SW_DEV , _SC_2_LOCALEDEF , _SC_PII , _SC_PII_XTI , _SC_PII_SOCKET , _SC_PII_INTERNET , _SC_PII_OSI , _SC_POLL , _SC_SELECT , _SC_UIO_MAXIOV , _SC_IOV_MAX = _SC_UIO_MAXIOV , _SC_PII_INTERNET_STREAM , _SC_PII_INTERNET_DGRAM , _SC_PII_OSI_COTS , _SC_PII_OSI_CLTS , _SC_PII_OSI_M , _SC_T_IOV_MAX , _SC_THREADS , _SC_THREAD_SAFE_FUNCTIONS , _SC_GETGR_R_SIZE_MAX , _SC_GETPW_R_SIZE_MAX , _SC_LOGIN_NAME_MAX , _SC_TTY_NAME_MAX , _SC_THREAD_DESTRUCTOR_ITERATIONS , _SC_THREAD_KEYS_MAX , _SC_THREAD_STACK_MIN , _SC_THREAD_THREADS_MAX , _SC_THREAD_ATTR_STACKADDR , _SC_THREAD_ATTR_STACKSIZE , _SC_THREAD_PRIORITY_SCHEDULING , _SC_THREAD_PRIO_INHERIT , _SC_THREAD_PRIO_PROTECT , _SC_THREAD_PROCESS_SHARED , _SC_NPROCESSORS_CONF , _SC_NPROCESSORS_ONLN , _SC_PHYS_PAGES , _SC_AVPHYS_PAGES , _SC_ATEXIT_MAX , _SC_PASS_MAX , _SC_XOPEN_VERSION , _SC_XOPEN_XCU_VERSION , _SC_XOPEN_UNIX , _SC_XOPEN_CRYPT , _SC_XOPEN_ENH_I18N , _SC_XOPEN_SHM , _SC_2_CHAR_TERM , _SC_2_C_VERSION , _SC_2_UPE , _SC_XOPEN_XPG2 , _SC_XOPEN_XPG3 , _SC_XOPEN_XPG4 , _SC_CHAR_BIT , _SC_CHAR_MAX , _SC_CHAR_MIN , _SC_INT_MAX , _SC_INT_MIN , _SC_LONG_BIT , _SC_WORD_BIT , _SC_MB_LEN_MAX , _SC_NZERO , _SC_SSIZE_MAX , _SC_SCHAR_MAX , _SC_SCHAR_MIN , _SC_SHRT_MAX , _SC_SHRT_MIN , _SC_UCHAR_MAX , _SC_UINT_MAX , _SC_ULONG_MAX , _SC_USHRT_MAX , _SC_NL_ARGMAX , _SC_NL_LANGMAX , _SC_NL_MSGMAX , _SC_NL_NMAX , _SC_NL_SETMAX , _SC_NL_TEXTMAX , _SC_XBS5_ILP32_OFF32 , _SC_XBS5_ILP32_OFFBIG , _SC_XBS5_LP64_OFF64 , _SC_XBS5_LPBIG_OFFBIG , _SC_XOPEN_LEGACY , _SC_XOPEN_REALTIME , _SC_XOPEN_REALTIME_THREADS , _SC_ADVISORY_INFO , _SC_BARRIERS , _SC_BASE , _SC_C_LANG_SUPPORT , _SC_C_LANG_SUPPORT_R , _SC_CLOCK_SELECTION , _SC_CPUTIME , _SC_THREAD_CPUTIME , _SC_DEVICE_IO , _SC_DEVICE_SPECIFIC , _SC_DEVICE_SPECIFIC_R , _SC_FD_MGMT , _SC_FIFO , _SC_PIPE , _SC_FILE_ATTRIBUTES , _SC_FILE_LOCKING , _SC_FILE_SYSTEM , _SC_MONOTONIC_CLOCK , _SC_MULTI_PROCESS , _SC_SINGLE_PROCESS , _SC_NETWORKING , _SC_READER_WRITER_LOCKS , _SC_SPIN_LOCKS , _SC_REGEXP , _SC_REGEX_VERSION , _SC_SHELL , _SC_SIGNALS , _SC_SPAWN , _SC_SPORADIC_SERVER , _SC_THREAD_SPORADIC_SERVER , _SC_SYSTEM_DATABASE , _SC_SYSTEM_DATABASE_R , _SC_TIMEOUTS , _SC_TYPED_MEMORY_OBJECTS , _SC_USER_GROUPS , _SC_USER_GROUPS_R , _SC_2_PBS , _SC_2_PBS_ACCOUNTING , _SC_2_PBS_LOCATE , _SC_2_PBS_MESSAGE , _SC_2_PBS_TRACK , _SC_SYMLOOP_MAX , _SC_STREAMS , _SC_2_PBS_CHECKPOINT , _SC_V6_ILP32_OFF32 , _SC_V6_ILP32_OFFBIG , _SC_V6_LP64_OFF64 , _SC_V6_LPBIG_OFFBIG , _SC_HOST_NAME_MAX , _SC_TRACE , _SC_TRACE_EVENT_FILTER , _SC_TRACE_INHERIT , _SC_TRACE_LOG , _SC_LEVEL1_ICACHE_SIZE , _SC_LEVEL1_ICACHE_ASSOC , _SC_LEVEL1_ICACHE_LINESIZE , _SC_LEVEL1_DCACHE_SIZE , _SC_LEVEL1_DCACHE_ASSOC , _SC_LEVEL1_DCACHE_LINESIZE , _SC_LEVEL2_CACHE_SIZE , _SC_LEVEL2_CACHE_ASSOC , _SC_LEVEL2_CACHE_LINESIZE , _SC_LEVEL3_CACHE_SIZE , _SC_LEVEL3_CACHE_ASSOC , _SC_LEVEL3_CACHE_LINESIZE , _SC_LEVEL4_CACHE_SIZE , _SC_LEVEL4_CACHE_ASSOC , _SC_LEVEL4_CACHE_LINESIZE , _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50 , _SC_RAW_SOCKETS , _SC_V7_ILP32_OFF32 , _SC_V7_ILP32_OFFBIG , _SC_V7_LP64_OFF64 , _SC_V7_LPBIG_OFFBIG , _SC_SS_REPL_MAX , _SC_TRACE_EVENT_NAME_MAX , _SC_TRACE_NAME_MAX , _SC_TRACE_SYS_MAX , _SC_TRACE_USER_EVENT_MAX , _SC_XOPEN_STREAMS , _SC_THREAD_ROBUST_PRIO_INHERIT , _SC_THREAD_ROBUST_PRIO_PROTECT }
; 
enum {
  _CS_PATH , _CS_V6_WIDTH_RESTRICTED_ENVS , _CS_GNU_LIBC_VERSION , _CS_GNU_LIBPTHREAD_VERSION , _CS_V5_WIDTH_RESTRICTED_ENVS , _CS_V7_WIDTH_RESTRICTED_ENVS , _CS_LFS_CFLAGS = 1000 , _CS_LFS_LDFLAGS , _CS_LFS_LIBS , _CS_LFS_LINTFLAGS , _CS_LFS64_CFLAGS , _CS_LFS64_LDFLAGS , _CS_LFS64_LIBS , _CS_LFS64_LINTFLAGS , _CS_XBS5_ILP32_OFF32_CFLAGS = 1100 , _CS_XBS5_ILP32_OFF32_LDFLAGS , _CS_XBS5_ILP32_OFF32_LIBS , _CS_XBS5_ILP32_OFF32_LINTFLAGS , _CS_XBS5_ILP32_OFFBIG_CFLAGS , _CS_XBS5_ILP32_OFFBIG_LDFLAGS , _CS_XBS5_ILP32_OFFBIG_LIBS , _CS_XBS5_ILP32_OFFBIG_LINTFLAGS , _CS_XBS5_LP64_OFF64_CFLAGS , _CS_XBS5_LP64_OFF64_LDFLAGS , _CS_XBS5_LP64_OFF64_LIBS , _CS_XBS5_LP64_OFF64_LINTFLAGS , _CS_XBS5_LPBIG_OFFBIG_CFLAGS , _CS_XBS5_LPBIG_OFFBIG_LDFLAGS , _CS_XBS5_LPBIG_OFFBIG_LIBS , _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS , _CS_POSIX_V6_ILP32_OFF32_CFLAGS , _CS_POSIX_V6_ILP32_OFF32_LDFLAGS , _CS_POSIX_V6_ILP32_OFF32_LIBS , _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS , _CS_POSIX_V6_ILP32_OFFBIG_LIBS , _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS , _CS_POSIX_V6_LP64_OFF64_CFLAGS , _CS_POSIX_V6_LP64_OFF64_LDFLAGS , _CS_POSIX_V6_LP64_OFF64_LIBS , _CS_POSIX_V6_LP64_OFF64_LINTFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS , _CS_POSIX_V6_LPBIG_OFFBIG_LIBS , _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS , _CS_POSIX_V7_ILP32_OFF32_CFLAGS , _CS_POSIX_V7_ILP32_OFF32_LDFLAGS , _CS_POSIX_V7_ILP32_OFF32_LIBS , _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS , _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS , _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS , _CS_POSIX_V7_ILP32_OFFBIG_LIBS , _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS , _CS_POSIX_V7_LP64_OFF64_CFLAGS , _CS_POSIX_V7_LP64_OFF64_LDFLAGS , _CS_POSIX_V7_LP64_OFF64_LIBS , _CS_POSIX_V7_LP64_OFF64_LINTFLAGS , _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS , _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS , _CS_POSIX_V7_LPBIG_OFFBIG_LIBS , _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS , _CS_V6_ENV , _CS_V7_ENV }
; 
extern int link (__const char * __from , __const char * __to ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__nonnull__ (1 , 2 ) ) ) ; 
extern char * ctermid (char * __s ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
typedef int int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef int int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef int int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef int int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef int register_t __attribute__ ((__mode__ (__word__ ) ) ) ; 
struct timeval {
  __time_t tv_sec ; 
  __suseconds_t tv_usec ; 
}
; 
typedef long int __fd_mask ; 
typedef struct {
  __fd_mask __fds_bits [1024 / (8 * (int ) sizeof (__fd_mask ) ) ] ; 
}
fd_set ; 
typedef struct _GDataInputStreamPrivate GDataInputStreamPrivate ; 
struct _GDataInputStream {
  GBufferedInputStream parent_instance ; 
  GDataInputStreamPrivate * priv ; 
}
; 
struct _GDataInputStreamClass {
  GBufferedInputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GDataOutputStream GDataOutputStream ; 
typedef struct _GDataOutputStreamPrivate GDataOutputStreamPrivate ; 
struct _GDataOutputStream {
  GFilterOutputStream parent_instance ; 
  GDataOutputStreamPrivate * priv ; 
}
; 
struct _GDataOutputStreamClass {
  GFilterOutputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef void (* GDBusInterfaceMethodCallFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , const gchar * interface_name , const gchar * method_name , GVariant * parameters , GDBusMethodInvocation * invocation , gpointer user_data ) ; 
typedef GVariant * (* GDBusInterfaceGetPropertyFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , const gchar * interface_name , const gchar * property_name , GError * * error , gpointer user_data ) ; 
typedef gboolean (* GDBusInterfaceSetPropertyFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , const gchar * interface_name , const gchar * property_name , GVariant * value , GError * * error , gpointer user_data ) ; 
struct _GDBusInterfaceVTable {
  GDBusInterfaceMethodCallFunc method_call ; 
  GDBusInterfaceGetPropertyFunc get_property ; 
  GDBusInterfaceSetPropertyFunc set_property ; 
  gpointer padding [8 ] ; 
}
; 
typedef gchar * * (* GDBusSubtreeEnumerateFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , gpointer user_data ) ; 
typedef GDBusInterfaceInfo * * (* GDBusSubtreeIntrospectFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , const gchar * node , gpointer user_data ) ; 
typedef const GDBusInterfaceVTable * (* GDBusSubtreeDispatchFunc ) (GDBusConnection * connection , const gchar * sender , const gchar * object_path , const gchar * interface_name , const gchar * node , gpointer * out_user_data , gpointer user_data ) ; 
struct _GDBusSubtreeVTable {
  GDBusSubtreeEnumerateFunc enumerate ; 
  GDBusSubtreeIntrospectFunc introspect ; 
  GDBusSubtreeDispatchFunc dispatch ; 
  gpointer padding [8 ] ; 
}
; 
typedef void (* GDBusSignalCallback ) (GDBusConnection * connection , const gchar * sender_name , const gchar * object_path , const gchar * interface_name , const gchar * signal_name , GVariant * parameters , gpointer user_data ) ; 
typedef GDBusMessage * (* GDBusMessageFilterFunction ) (GDBusConnection * connection , GDBusMessage * message , gboolean incoming , gpointer user_data ) ; 
struct _GDBusErrorEntry {
  gint error_code ; 
  const gchar * dbus_error_name ; 
}
; 
struct _GDBusAnnotationInfo {
  volatile gint ref_count ; 
  gchar * key ; 
  gchar * value ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusArgInfo {
  volatile gint ref_count ; 
  gchar * name ; 
  gchar * signature ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusMethodInfo {
  volatile gint ref_count ; 
  gchar * name ; 
  GDBusArgInfo * * in_args ; 
  GDBusArgInfo * * out_args ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusSignalInfo {
  volatile gint ref_count ; 
  gchar * name ; 
  GDBusArgInfo * * args ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusPropertyInfo {
  volatile gint ref_count ; 
  gchar * name ; 
  gchar * signature ; 
  GDBusPropertyInfoFlags flags ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusInterfaceInfo {
  volatile gint ref_count ; 
  gchar * name ; 
  GDBusMethodInfo * * methods ; 
  GDBusSignalInfo * * signals ; 
  GDBusPropertyInfo * * properties ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
struct _GDBusNodeInfo {
  volatile gint ref_count ; 
  gchar * path ; 
  GDBusInterfaceInfo * * interfaces ; 
  GDBusNodeInfo * * nodes ; 
  GDBusAnnotationInfo * * annotations ; 
}
; 
typedef void (* GBusAcquiredCallback ) (GDBusConnection * connection , const gchar * name , gpointer user_data ) ; 
typedef void (* GBusNameAcquiredCallback ) (GDBusConnection * connection , const gchar * name , gpointer user_data ) ; 
typedef void (* GBusNameLostCallback ) (GDBusConnection * connection , const gchar * name , gpointer user_data ) ; 
typedef void (* GBusNameAppearedCallback ) (GDBusConnection * connection , const gchar * name , const gchar * name_owner , gpointer user_data ) ; 
typedef void (* GBusNameVanishedCallback ) (GDBusConnection * connection , const gchar * name , gpointer user_data ) ; 
typedef struct _GDBusProxyPrivate GDBusProxyPrivate ; 
struct _GDBusProxy {
  GObject parent_instance ; 
  GDBusProxyPrivate * priv ; 
}
; 
struct _GDBusProxyClass {
  GObjectClass parent_class ; 
  void (* g_properties_changed ) (GDBusProxy * proxy , GVariant * changed_properties , const gchar * const * invalidated_properties ) ; 
  void (* g_signal ) (GDBusProxy * proxy , const gchar * sender_name , const gchar * signal_name , GVariant * parameters ) ; 
  gpointer padding [32 ] ; 
}
; 
GDBusProxy * g_dbus_proxy_new_for_bus_sync (GBusType bus_type , GDBusProxyFlags flags , GDBusInterfaceInfo * info , const gchar * name , const gchar * object_path , const gchar * interface_name , GCancellable * cancellable , GError * * error ) ; 
GVariant * g_dbus_proxy_call_sync (GDBusProxy * proxy , const gchar * method_name , GVariant * parameters , GDBusCallFlags flags , gint timeout_msec , GCancellable * cancellable , GError * * error ) ; 
struct _GDriveIface {
  GTypeInterface g_iface ; 
  void (* changed ) (GDrive * drive ) ; 
  void (* disconnected ) (GDrive * drive ) ; 
  void (* eject_button ) (GDrive * drive ) ; 
  char * (* get_name ) (GDrive * drive ) ; 
  GIcon * (* get_icon ) (GDrive * drive ) ; 
  gboolean (* has_volumes ) (GDrive * drive ) ; 
  GList * (* get_volumes ) (GDrive * drive ) ; 
  gboolean (* is_media_removable ) (GDrive * drive ) ; 
  gboolean (* has_media ) (GDrive * drive ) ; 
  gboolean (* is_media_check_automatic ) (GDrive * drive ) ; 
  gboolean (* can_eject ) (GDrive * drive ) ; 
  gboolean (* can_poll_for_media ) (GDrive * drive ) ; 
  void (* eject ) (GDrive * drive , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_finish ) (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
  void (* poll_for_media ) (GDrive * drive , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* poll_for_media_finish ) (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
  char * (* get_identifier ) (GDrive * drive , const char * kind ) ; 
  char * * (* enumerate_identifiers ) (GDrive * drive ) ; 
  GDriveStartStopType (* get_start_stop_type ) (GDrive * drive ) ; 
  gboolean (* can_start ) (GDrive * drive ) ; 
  gboolean (* can_start_degraded ) (GDrive * drive ) ; 
  void (* start ) (GDrive * drive , GDriveStartFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* start_finish ) (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
  gboolean (* can_stop ) (GDrive * drive ) ; 
  void (* stop ) (GDrive * drive , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* stop_finish ) (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
  void (* stop_button ) (GDrive * drive ) ; 
  void (* eject_with_operation ) (GDrive * drive , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_with_operation_finish ) (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
  const gchar * (* get_sort_key ) (GDrive * drive ) ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_drive_eject_with_operation" "' instead" ) ) ) void g_drive_eject (GDrive * drive , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_drive_eject_with_operation_finish" "' instead" ) ) ) gboolean g_drive_eject_finish (GDrive * drive , GAsyncResult * result , GError * * error ) ; 
struct _GIconIface {
  GTypeInterface g_iface ; 
  guint (* hash ) (GIcon * icon ) ; 
  gboolean (* equal ) (GIcon * icon1 , GIcon * icon2 ) ; 
  gboolean (* to_tokens ) (GIcon * icon , GPtrArray * tokens , gint * out_version ) ; 
  GIcon * (* from_tokens ) (gchar * * tokens , gint num_tokens , gint version , GError * * error ) ; 
}
; 
typedef struct _GEmblem GEmblem ; 
typedef struct _GEmblemedIcon GEmblemedIcon ; 
typedef struct _GEmblemedIconPrivate GEmblemedIconPrivate ; 
struct _GEmblemedIcon {
  GObject parent_instance ; 
  GEmblemedIconPrivate * priv ; 
}
; 
struct _GEmblemedIconClass {
  GObjectClass parent_class ; 
}
; 
struct _GFileAttributeInfo {
  char * name ; 
  GFileAttributeType type ; 
  GFileAttributeInfoFlags flags ; 
}
; 
struct _GFileAttributeInfoList {
  GFileAttributeInfo * infos ; 
  int n_infos ; 
}
; 
typedef struct _GFileEnumeratorPrivate GFileEnumeratorPrivate ; 
struct _GFileEnumerator {
  GObject parent_instance ; 
  GFileEnumeratorPrivate * priv ; 
}
; 
struct _GFileEnumeratorClass {
  GObjectClass parent_class ; 
  GFileInfo * (* next_file ) (GFileEnumerator * enumerator , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* close_fn ) (GFileEnumerator * enumerator , GCancellable * cancellable , GError * * error ) ; 
  void (* next_files_async ) (GFileEnumerator * enumerator , int num_files , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GList * (* next_files_finish ) (GFileEnumerator * enumerator , GAsyncResult * result , GError * * error ) ; 
  void (* close_async ) (GFileEnumerator * enumerator , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* close_finish ) (GFileEnumerator * enumerator , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
}
; 
struct _GFileIface {
  GTypeInterface g_iface ; 
  GFile * (* dup ) (GFile * file ) ; 
  guint (* hash ) (GFile * file ) ; 
  gboolean (* equal ) (GFile * file1 , GFile * file2 ) ; 
  gboolean (* is_native ) (GFile * file ) ; 
  gboolean (* has_uri_scheme ) (GFile * file , const char * uri_scheme ) ; 
  char * (* get_uri_scheme ) (GFile * file ) ; 
  char * (* get_basename ) (GFile * file ) ; 
  char * (* get_path ) (GFile * file ) ; 
  char * (* get_uri ) (GFile * file ) ; 
  char * (* get_parse_name ) (GFile * file ) ; 
  GFile * (* get_parent ) (GFile * file ) ; 
  gboolean (* prefix_matches ) (GFile * prefix , GFile * file ) ; 
  char * (* get_relative_path ) (GFile * parent , GFile * descendant ) ; 
  GFile * (* resolve_relative_path ) (GFile * file , const char * relative_path ) ; 
  GFile * (* get_child_for_display_name ) (GFile * file , const char * display_name , GError * * error ) ; 
  GFileEnumerator * (* enumerate_children ) (GFile * file , const char * attributes , GFileQueryInfoFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* enumerate_children_async ) (GFile * file , const char * attributes , GFileQueryInfoFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileEnumerator * (* enumerate_children_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileInfo * (* query_info ) (GFile * file , const char * attributes , GFileQueryInfoFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* query_info_async ) (GFile * file , const char * attributes , GFileQueryInfoFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInfo * (* query_info_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileInfo * (* query_filesystem_info ) (GFile * file , const char * attributes , GCancellable * cancellable , GError * * error ) ; 
  void (* query_filesystem_info_async ) (GFile * file , const char * attributes , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInfo * (* query_filesystem_info_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GMount * (* find_enclosing_mount ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* find_enclosing_mount_async ) (GFile * file , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GMount * (* find_enclosing_mount_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFile * (* set_display_name ) (GFile * file , const char * display_name , GCancellable * cancellable , GError * * error ) ; 
  void (* set_display_name_async ) (GFile * file , const char * display_name , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFile * (* set_display_name_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileAttributeInfoList * (* query_settable_attributes ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* _query_settable_attributes_async ) (void ) ; 
  void (* _query_settable_attributes_finish ) (void ) ; 
  GFileAttributeInfoList * (* query_writable_namespaces ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* _query_writable_namespaces_async ) (void ) ; 
  void (* _query_writable_namespaces_finish ) (void ) ; 
  gboolean (* set_attribute ) (GFile * file , const char * attribute , GFileAttributeType type , gpointer value_p , GFileQueryInfoFlags flags , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* set_attributes_from_info ) (GFile * file , GFileInfo * info , GFileQueryInfoFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* set_attributes_async ) (GFile * file , GFileInfo * info , GFileQueryInfoFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* set_attributes_finish ) (GFile * file , GAsyncResult * result , GFileInfo * * info , GError * * error ) ; 
  GFileInputStream * (* read_fn ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* read_async ) (GFile * file , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInputStream * (* read_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileOutputStream * (* append_to ) (GFile * file , GFileCreateFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* append_to_async ) (GFile * file , GFileCreateFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileOutputStream * (* append_to_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileOutputStream * (* create ) (GFile * file , GFileCreateFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* create_async ) (GFile * file , GFileCreateFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileOutputStream * (* create_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileOutputStream * (* replace ) (GFile * file , const char * etag , gboolean make_backup , GFileCreateFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* replace_async ) (GFile * file , const char * etag , gboolean make_backup , GFileCreateFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileOutputStream * (* replace_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  gboolean (* delete_file ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* _delete_file_async ) (void ) ; 
  void (* _delete_file_finish ) (void ) ; 
  gboolean (* trash ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* _trash_async ) (void ) ; 
  void (* _trash_finish ) (void ) ; 
  gboolean (* make_directory ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* _make_directory_async ) (void ) ; 
  void (* _make_directory_finish ) (void ) ; 
  gboolean (* make_symbolic_link ) (GFile * file , const char * symlink_value , GCancellable * cancellable , GError * * error ) ; 
  void (* _make_symbolic_link_async ) (void ) ; 
  void (* _make_symbolic_link_finish ) (void ) ; 
  gboolean (* copy ) (GFile * source , GFile * destination , GFileCopyFlags flags , GCancellable * cancellable , GFileProgressCallback progress_callback , gpointer progress_callback_data , GError * * error ) ; 
  void (* copy_async ) (GFile * source , GFile * destination , GFileCopyFlags flags , int io_priority , GCancellable * cancellable , GFileProgressCallback progress_callback , gpointer progress_callback_data , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* copy_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  gboolean (* move ) (GFile * source , GFile * destination , GFileCopyFlags flags , GCancellable * cancellable , GFileProgressCallback progress_callback , gpointer progress_callback_data , GError * * error ) ; 
  void (* _move_async ) (void ) ; 
  void (* _move_finish ) (void ) ; 
  void (* mount_mountable ) (GFile * file , GMountMountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFile * (* mount_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* unmount_mountable ) (GFile * file , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* unmount_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* eject_mountable ) (GFile * file , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* mount_enclosing_volume ) (GFile * location , GMountMountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* mount_enclosing_volume_finish ) (GFile * location , GAsyncResult * result , GError * * error ) ; 
  GFileMonitor * (* monitor_dir ) (GFile * file , GFileMonitorFlags flags , GCancellable * cancellable , GError * * error ) ; 
  GFileMonitor * (* monitor_file ) (GFile * file , GFileMonitorFlags flags , GCancellable * cancellable , GError * * error ) ; 
  GFileIOStream * (* open_readwrite ) (GFile * file , GCancellable * cancellable , GError * * error ) ; 
  void (* open_readwrite_async ) (GFile * file , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileIOStream * (* open_readwrite_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileIOStream * (* create_readwrite ) (GFile * file , GFileCreateFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* create_readwrite_async ) (GFile * file , GFileCreateFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileIOStream * (* create_readwrite_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  GFileIOStream * (* replace_readwrite ) (GFile * file , const char * etag , gboolean make_backup , GFileCreateFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* replace_readwrite_async ) (GFile * file , const char * etag , gboolean make_backup , GFileCreateFlags flags , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileIOStream * (* replace_readwrite_finish ) (GFile * file , GAsyncResult * res , GError * * error ) ; 
  void (* start_mountable ) (GFile * file , GDriveStartFlags flags , GMountOperation * start_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* start_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* stop_mountable ) (GFile * file , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* stop_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  gboolean supports_thread_contexts ; 
  void (* unmount_mountable_with_operation ) (GFile * file , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* unmount_mountable_with_operation_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* eject_mountable_with_operation ) (GFile * file , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_mountable_with_operation_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
  void (* poll_mountable ) (GFile * file , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* poll_mountable_finish ) (GFile * file , GAsyncResult * result , GError * * error ) ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_file_unmount_mountable_with_operation" "' instead" ) ) ) void g_file_unmount_mountable (GFile * file , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_file_unmount_mountable_with_operation_finish" "' instead" ) ) ) gboolean g_file_unmount_mountable_finish (GFile * file , GAsyncResult * result , GError * * error ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_file_eject_mountable_with_operation" "' instead" ) ) ) void g_file_eject_mountable (GFile * file , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_file_eject_mountable_with_operation_finish" "' instead" ) ) ) gboolean g_file_eject_mountable_finish (GFile * file , GAsyncResult * result , GError * * error ) ; 
typedef struct _GFileInputStreamPrivate GFileInputStreamPrivate ; 
struct _GFileInputStream {
  GInputStream parent_instance ; 
  GFileInputStreamPrivate * priv ; 
}
; 
struct _GFileInputStreamClass {
  GInputStreamClass parent_class ; 
  goffset (* tell ) (GFileInputStream * stream ) ; 
  gboolean (* can_seek ) (GFileInputStream * stream ) ; 
  gboolean (* seek ) (GFileInputStream * stream , goffset offset , GSeekType type , GCancellable * cancellable , GError * * error ) ; 
  GFileInfo * (* query_info ) (GFileInputStream * stream , const char * attributes , GCancellable * cancellable , GError * * error ) ; 
  void (* query_info_async ) (GFileInputStream * stream , const char * attributes , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInfo * (* query_info_finish ) (GFileInputStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GIOStreamPrivate GIOStreamPrivate ; 
typedef struct _GIOStreamClass GIOStreamClass ; 
struct _GIOStream {
  GObject parent_instance ; 
  GIOStreamPrivate * priv ; 
}
; 
struct _GIOStreamClass {
  GObjectClass parent_class ; 
  GInputStream * (* get_input_stream ) (GIOStream * stream ) ; 
  GOutputStream * (* get_output_stream ) (GIOStream * stream ) ; 
  gboolean (* close_fn ) (GIOStream * stream , GCancellable * cancellable , GError * * error ) ; 
  void (* close_async ) (GIOStream * stream , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* close_finish ) (GIOStream * stream , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
  void (* _g_reserved8 ) (void ) ; 
  void (* _g_reserved9 ) (void ) ; 
  void (* _g_reserved10 ) (void ) ; 
}
; 
typedef struct _GFileIOStreamPrivate GFileIOStreamPrivate ; 
struct _GFileIOStream {
  GIOStream parent_instance ; 
  GFileIOStreamPrivate * priv ; 
}
; 
struct _GFileIOStreamClass {
  GIOStreamClass parent_class ; 
  goffset (* tell ) (GFileIOStream * stream ) ; 
  gboolean (* can_seek ) (GFileIOStream * stream ) ; 
  gboolean (* seek ) (GFileIOStream * stream , goffset offset , GSeekType type , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* can_truncate ) (GFileIOStream * stream ) ; 
  gboolean (* truncate_fn ) (GFileIOStream * stream , goffset size , GCancellable * cancellable , GError * * error ) ; 
  GFileInfo * (* query_info ) (GFileIOStream * stream , const char * attributes , GCancellable * cancellable , GError * * error ) ; 
  void (* query_info_async ) (GFileIOStream * stream , const char * attributes , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInfo * (* query_info_finish ) (GFileIOStream * stream , GAsyncResult * result , GError * * error ) ; 
  char * (* get_etag ) (GFileIOStream * stream ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GFileMonitorPrivate GFileMonitorPrivate ; 
struct _GFileMonitor {
  GObject parent_instance ; 
  GFileMonitorPrivate * priv ; 
}
; 
struct _GFileMonitorClass {
  GObjectClass parent_class ; 
  void (* changed ) (GFileMonitor * monitor , GFile * file , GFile * other_file , GFileMonitorEvent event_type ) ; 
  gboolean (* cancel ) (GFileMonitor * monitor ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
struct _GFilenameCompleterClass {
  GObjectClass parent_class ; 
  void (* got_completion_data ) (GFilenameCompleter * filename_completer ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
}
; 
typedef struct _GFileOutputStreamPrivate GFileOutputStreamPrivate ; 
struct _GFileOutputStream {
  GOutputStream parent_instance ; 
  GFileOutputStreamPrivate * priv ; 
}
; 
struct _GFileOutputStreamClass {
  GOutputStreamClass parent_class ; 
  goffset (* tell ) (GFileOutputStream * stream ) ; 
  gboolean (* can_seek ) (GFileOutputStream * stream ) ; 
  gboolean (* seek ) (GFileOutputStream * stream , goffset offset , GSeekType type , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* can_truncate ) (GFileOutputStream * stream ) ; 
  gboolean (* truncate_fn ) (GFileOutputStream * stream , goffset size , GCancellable * cancellable , GError * * error ) ; 
  GFileInfo * (* query_info ) (GFileOutputStream * stream , const char * attributes , GCancellable * cancellable , GError * * error ) ; 
  void (* query_info_async ) (GFileOutputStream * stream , const char * attributes , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GFileInfo * (* query_info_finish ) (GFileOutputStream * stream , GAsyncResult * result , GError * * error ) ; 
  char * (* get_etag ) (GFileOutputStream * stream ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GInetAddressPrivate GInetAddressPrivate ; 
struct _GInetAddress {
  GObject parent_instance ; 
  GInetAddressPrivate * priv ; 
}
; 
struct _GInetAddressClass {
  GObjectClass parent_class ; 
  gchar * (* to_string ) (GInetAddress * address ) ; 
  const guint8 * (* to_bytes ) (GInetAddress * address ) ; 
}
; 
typedef struct _GInetAddressMaskPrivate GInetAddressMaskPrivate ; 
struct _GInetAddressMask {
  GObject parent_instance ; 
  GInetAddressMaskPrivate * priv ; 
}
; 
struct _GInetAddressMaskClass {
  GObjectClass parent_class ; 
}
; 
typedef struct _GSocketAddressClass GSocketAddressClass ; 
struct _GSocketAddress {
  GObject parent_instance ; 
}
; 
struct _GSocketAddressClass {
  GObjectClass parent_class ; 
  GSocketFamily (* get_family ) (GSocketAddress * address ) ; 
  gssize (* get_native_size ) (GSocketAddress * address ) ; 
  gboolean (* to_native ) (GSocketAddress * address , gpointer dest , gsize destlen , GError * * error ) ; 
}
; 
typedef struct _GInetSocketAddressClass GInetSocketAddressClass ; 
typedef struct _GInetSocketAddressPrivate GInetSocketAddressPrivate ; 
struct _GInetSocketAddress {
  GSocketAddress parent_instance ; 
  GInetSocketAddressPrivate * priv ; 
}
; 
struct _GInetSocketAddressClass {
  GSocketAddressClass parent_class ; 
}
; 
typedef enum {
  G_MODULE_BIND_LAZY = 1 << 0 , G_MODULE_BIND_LOCAL = 1 << 1 , G_MODULE_BIND_MASK = 0x03 }
GModuleFlags ; 
typedef struct _GModule GModule ; 
typedef const gchar * (* GModuleCheckInit ) (GModule * module ) ; 
typedef void (* GModuleUnload ) (GModule * module ) ; 
typedef struct _GIOModuleScope GIOModuleScope ; 
struct _GLoadableIconIface {
  GTypeInterface g_iface ; 
  GInputStream * (* load ) (GLoadableIcon * icon , int size , char * * type , GCancellable * cancellable , GError * * error ) ; 
  void (* load_async ) (GLoadableIcon * icon , int size , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GInputStream * (* load_finish ) (GLoadableIcon * icon , GAsyncResult * res , char * * type , GError * * error ) ; 
}
; 
typedef struct _GMemoryInputStreamPrivate GMemoryInputStreamPrivate ; 
struct _GMemoryInputStream {
  GInputStream parent_instance ; 
  GMemoryInputStreamPrivate * priv ; 
}
; 
struct _GMemoryInputStreamClass {
  GInputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef struct _GMemoryOutputStreamPrivate GMemoryOutputStreamPrivate ; 
struct _GMemoryOutputStream {
  GOutputStream parent_instance ; 
  GMemoryOutputStreamPrivate * priv ; 
}
; 
struct _GMemoryOutputStreamClass {
  GOutputStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
typedef gpointer (* GReallocFunc ) (gpointer data , gsize size ) ; 
struct _GMountIface {
  GTypeInterface g_iface ; 
  void (* changed ) (GMount * mount ) ; 
  void (* unmounted ) (GMount * mount ) ; 
  GFile * (* get_root ) (GMount * mount ) ; 
  char * (* get_name ) (GMount * mount ) ; 
  GIcon * (* get_icon ) (GMount * mount ) ; 
  char * (* get_uuid ) (GMount * mount ) ; 
  GVolume * (* get_volume ) (GMount * mount ) ; 
  GDrive * (* get_drive ) (GMount * mount ) ; 
  gboolean (* can_unmount ) (GMount * mount ) ; 
  gboolean (* can_eject ) (GMount * mount ) ; 
  void (* unmount ) (GMount * mount , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* unmount_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  void (* eject ) (GMount * mount , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  void (* remount ) (GMount * mount , GMountMountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* remount_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  void (* guess_content_type ) (GMount * mount , gboolean force_rescan , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gchar * * (* guess_content_type_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  gchar * * (* guess_content_type_sync ) (GMount * mount , gboolean force_rescan , GCancellable * cancellable , GError * * error ) ; 
  void (* pre_unmount ) (GMount * mount ) ; 
  void (* unmount_with_operation ) (GMount * mount , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* unmount_with_operation_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  void (* eject_with_operation ) (GMount * mount , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_with_operation_finish ) (GMount * mount , GAsyncResult * result , GError * * error ) ; 
  GFile * (* get_default_location ) (GMount * mount ) ; 
  const gchar * (* get_sort_key ) (GMount * mount ) ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_mount_unmount_with_operation" "' instead" ) ) ) void g_mount_unmount (GMount * mount , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_mount_unmount_with_operation_finish" "' instead" ) ) ) gboolean g_mount_unmount_finish (GMount * mount , GAsyncResult * result , GError * * error ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_mount_eject_with_operation" "' instead" ) ) ) void g_mount_eject (GMount * mount , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_mount_eject_with_operation_finish" "' instead" ) ) ) gboolean g_mount_eject_finish (GMount * mount , GAsyncResult * result , GError * * error ) ; 
typedef struct _GMountOperationPrivate GMountOperationPrivate ; 
struct _GMountOperation {
  GObject parent_instance ; 
  GMountOperationPrivate * priv ; 
}
; 
struct _GMountOperationClass {
  GObjectClass parent_class ; 
  void (* ask_password ) (GMountOperation * op , const char * message , const char * default_user , const char * default_domain , GAskPasswordFlags flags ) ; 
  void (* ask_question ) (GMountOperation * op , const char * message , const char * choices [] ) ; 
  void (* reply ) (GMountOperation * op , GMountOperationResult result ) ; 
  void (* aborted ) (GMountOperation * op ) ; 
  void (* show_processes ) (GMountOperation * op , const gchar * message , GArray * processes , const gchar * choices [] ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
  void (* _g_reserved8 ) (void ) ; 
  void (* _g_reserved9 ) (void ) ; 
  void (* _g_reserved10 ) (void ) ; 
}
; 
typedef struct _GVolumeMonitorClass GVolumeMonitorClass ; 
struct _GVolumeMonitor {
  GObject parent_instance ; 
  gpointer priv ; 
}
; 
struct _GVolumeMonitorClass {
  GObjectClass parent_class ; 
  void (* volume_added ) (GVolumeMonitor * volume_monitor , GVolume * volume ) ; 
  void (* volume_removed ) (GVolumeMonitor * volume_monitor , GVolume * volume ) ; 
  void (* volume_changed ) (GVolumeMonitor * volume_monitor , GVolume * volume ) ; 
  void (* mount_added ) (GVolumeMonitor * volume_monitor , GMount * mount ) ; 
  void (* mount_removed ) (GVolumeMonitor * volume_monitor , GMount * mount ) ; 
  void (* mount_pre_unmount ) (GVolumeMonitor * volume_monitor , GMount * mount ) ; 
  void (* mount_changed ) (GVolumeMonitor * volume_monitor , GMount * mount ) ; 
  void (* drive_connected ) (GVolumeMonitor * volume_monitor , GDrive * drive ) ; 
  void (* drive_disconnected ) (GVolumeMonitor * volume_monitor , GDrive * drive ) ; 
  void (* drive_changed ) (GVolumeMonitor * volume_monitor , GDrive * drive ) ; 
  gboolean (* is_supported ) (void ) ; 
  GList * (* get_connected_drives ) (GVolumeMonitor * volume_monitor ) ; 
  GList * (* get_volumes ) (GVolumeMonitor * volume_monitor ) ; 
  GList * (* get_mounts ) (GVolumeMonitor * volume_monitor ) ; 
  GVolume * (* get_volume_for_uuid ) (GVolumeMonitor * volume_monitor , const char * uuid ) ; 
  GMount * (* get_mount_for_uuid ) (GVolumeMonitor * volume_monitor , const char * uuid ) ; 
  GVolume * (* adopt_orphan_mount ) (GMount * mount , GVolumeMonitor * volume_monitor ) ; 
  void (* drive_eject_button ) (GVolumeMonitor * volume_monitor , GDrive * drive ) ; 
  void (* drive_stop_button ) (GVolumeMonitor * volume_monitor , GDrive * drive ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
}
; 
__attribute__ ((__deprecated__ ) ) GVolume * g_volume_monitor_adopt_orphan_mount (GMount * mount ) ; 
struct _GNativeVolumeMonitor {
  GVolumeMonitor parent_instance ; 
}
; 
struct _GNativeVolumeMonitorClass {
  GVolumeMonitorClass parent_class ; 
  GMount * (* get_mount_for_mount_path ) (const char * mount_path , GCancellable * cancellable ) ; 
}
; 
typedef struct _GNetworkAddressPrivate GNetworkAddressPrivate ; 
struct _GNetworkAddress {
  GObject parent_instance ; 
  GNetworkAddressPrivate * priv ; 
}
; 
struct _GNetworkAddressClass {
  GObjectClass parent_class ; 
}
; 
struct _GNetworkMonitorInterface {
  GTypeInterface g_iface ; 
  void (* network_changed ) (GNetworkMonitor * monitor , gboolean available ) ; 
  gboolean (* can_reach ) (GNetworkMonitor * monitor , GSocketConnectable * connectable , GCancellable * cancellable , GError * * error ) ; 
  void (* can_reach_async ) (GNetworkMonitor * monitor , GSocketConnectable * connectable , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* can_reach_finish ) (GNetworkMonitor * monitor , GAsyncResult * result , GError * * error ) ; 
}
; 
typedef struct _GNetworkServicePrivate GNetworkServicePrivate ; 
struct _GNetworkService {
  GObject parent_instance ; 
  GNetworkServicePrivate * priv ; 
}
; 
struct _GNetworkServiceClass {
  GObjectClass parent_class ; 
}
; 
typedef struct _GPermissionPrivate GPermissionPrivate ; 
struct _GPermission {
  GObject parent_instance ; 
  GPermissionPrivate * priv ; 
}
; 
struct _GPermissionClass {
  GObjectClass parent_class ; 
  gboolean (* acquire ) (GPermission * permission , GCancellable * cancellable , GError * * error ) ; 
  void (* acquire_async ) (GPermission * permission , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* acquire_finish ) (GPermission * permission , GAsyncResult * result , GError * * error ) ; 
  gboolean (* release ) (GPermission * permission , GCancellable * cancellable , GError * * error ) ; 
  void (* release_async ) (GPermission * permission , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* release_finish ) (GPermission * permission , GAsyncResult * result , GError * * error ) ; 
  gpointer reserved [16 ] ; 
}
; 
struct _GPollableInputStreamInterface {
  GTypeInterface g_iface ; 
  gboolean (* can_poll ) (GPollableInputStream * stream ) ; 
  gboolean (* is_readable ) (GPollableInputStream * stream ) ; 
  GSource * (* create_source ) (GPollableInputStream * stream , GCancellable * cancellable ) ; 
  gssize (* read_nonblocking ) (GPollableInputStream * stream , void * buffer , gsize size , GError * * error ) ; 
}
; 
struct _GPollableOutputStreamInterface {
  GTypeInterface g_iface ; 
  gboolean (* can_poll ) (GPollableOutputStream * stream ) ; 
  gboolean (* is_writable ) (GPollableOutputStream * stream ) ; 
  GSource * (* create_source ) (GPollableOutputStream * stream , GCancellable * cancellable ) ; 
  gssize (* write_nonblocking ) (GPollableOutputStream * stream , const void * buffer , gsize size , GError * * error ) ; 
}
; 
struct _GProxyInterface {
  GTypeInterface g_iface ; 
  GIOStream * (* connect ) (GProxy * proxy , GIOStream * connection , GProxyAddress * proxy_address , GCancellable * cancellable , GError * * error ) ; 
  void (* connect_async ) (GProxy * proxy , GIOStream * connection , GProxyAddress * proxy_address , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GIOStream * (* connect_finish ) (GProxy * proxy , GAsyncResult * result , GError * * error ) ; 
  gboolean (* supports_hostname ) (GProxy * proxy ) ; 
}
; 
typedef struct _GProxyAddressPrivate GProxyAddressPrivate ; 
struct _GProxyAddress {
  GInetSocketAddress parent_instance ; 
  GProxyAddressPrivate * priv ; 
}
; 
struct _GProxyAddressClass {
  GInetSocketAddressClass parent_class ; 
}
; 
typedef struct _GSocketAddressEnumeratorClass GSocketAddressEnumeratorClass ; 
struct _GSocketAddressEnumerator {
  GObject parent_instance ; 
}
; 
struct _GSocketAddressEnumeratorClass {
  GObjectClass parent_class ; 
  GSocketAddress * (* next ) (GSocketAddressEnumerator * enumerator , GCancellable * cancellable , GError * * error ) ; 
  void (* next_async ) (GSocketAddressEnumerator * enumerator , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GSocketAddress * (* next_finish ) (GSocketAddressEnumerator * enumerator , GAsyncResult * result , GError * * error ) ; 
}
; 
typedef struct _GProxyAddressEnumeratorPrivate GProxyAddressEnumeratorPrivate ; 
struct _GProxyAddressEnumerator {
  GSocketAddressEnumerator parent_instance ; 
  GProxyAddressEnumeratorPrivate * priv ; 
}
; 
struct _GProxyAddressEnumeratorClass {
  GSocketAddressEnumeratorClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
}
; 
struct _GProxyResolverInterface {
  GTypeInterface g_iface ; 
  gboolean (* is_supported ) (GProxyResolver * resolver ) ; 
  gchar * * (* lookup ) (GProxyResolver * resolver , const gchar * uri , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_async ) (GProxyResolver * resolver , const gchar * uri , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gchar * * (* lookup_finish ) (GProxyResolver * resolver , GAsyncResult * result , GError * * error ) ; 
}
; 
typedef struct _GResolverPrivate GResolverPrivate ; 
struct _GResolver {
  GObject parent_instance ; 
  GResolverPrivate * priv ; 
}
; 
struct _GResolverClass {
  GObjectClass parent_class ; 
  void (* reload ) (GResolver * resolver ) ; 
  GList * (* lookup_by_name ) (GResolver * resolver , const gchar * hostname , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_by_name_async ) (GResolver * resolver , const gchar * hostname , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GList * (* lookup_by_name_finish ) (GResolver * resolver , GAsyncResult * result , GError * * error ) ; 
  gchar * (* lookup_by_address ) (GResolver * resolver , GInetAddress * address , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_by_address_async ) (GResolver * resolver , GInetAddress * address , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gchar * (* lookup_by_address_finish ) (GResolver * resolver , GAsyncResult * result , GError * * error ) ; 
  GList * (* lookup_service ) (GResolver * resolver , const gchar * rrname , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_service_async ) (GResolver * resolver , const gchar * rrname , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GList * (* lookup_service_finish ) (GResolver * resolver , GAsyncResult * result , GError * * error ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
}
; 
typedef struct _GStaticResource GStaticResource ; 
struct _GStaticResource {
  const guint8 * data ; 
  gsize data_len ; 
  GResource * resource ; 
  GStaticResource * next ; 
  gpointer padding ; 
}
; 
struct _GSeekableIface {
  GTypeInterface g_iface ; 
  goffset (* tell ) (GSeekable * seekable ) ; 
  gboolean (* can_seek ) (GSeekable * seekable ) ; 
  gboolean (* seek ) (GSeekable * seekable , goffset offset , GSeekType type , GCancellable * cancellable , GError * * error ) ; 
  gboolean (* can_truncate ) (GSeekable * seekable ) ; 
  gboolean (* truncate_fn ) (GSeekable * seekable , goffset offset , GCancellable * cancellable , GError * * error ) ; 
}
; 
typedef struct _GSettingsSchemaSource GSettingsSchemaSource ; 
typedef struct _GSettingsSchema GSettingsSchema ; 
typedef struct _GSettingsPrivate GSettingsPrivate ; 
struct _GSettingsClass {
  GObjectClass parent_class ; 
  void (* writable_changed ) (GSettings * settings , const gchar * key ) ; 
  void (* changed ) (GSettings * settings , const gchar * key ) ; 
  gboolean (* writable_change_event ) (GSettings * settings , GQuark key ) ; 
  gboolean (* change_event ) (GSettings * settings , const GQuark * keys , gint n_keys ) ; 
  gpointer padding [20 ] ; 
}
; 
struct _GSettings {
  GObject parent_instance ; 
  GSettingsPrivate * priv ; 
}
; 
typedef GVariant * (* GSettingsBindSetMapping ) (const GValue * value , const GVariantType * expected_type , gpointer user_data ) ; 
typedef gboolean (* GSettingsBindGetMapping ) (GValue * value , GVariant * variant , gpointer user_data ) ; 
typedef gboolean (* GSettingsGetMapping ) (GVariant * value , gpointer * result , gpointer user_data ) ; 
typedef enum {
  G_SETTINGS_BIND_DEFAULT , G_SETTINGS_BIND_GET = (1 << 0 ) , G_SETTINGS_BIND_SET = (1 << 1 ) , G_SETTINGS_BIND_NO_SENSITIVITY = (1 << 2 ) , G_SETTINGS_BIND_GET_NO_CHANGES = (1 << 3 ) , G_SETTINGS_BIND_INVERT_BOOLEAN = (1 << 4 ) }
GSettingsBindFlags ; 
typedef struct _GSimpleActionGroupPrivate GSimpleActionGroupPrivate ; 
struct _GSimpleActionGroup {
  GObject parent_instance ; 
  GSimpleActionGroupPrivate * priv ; 
}
; 
struct _GSimpleActionGroupClass {
  GObjectClass parent_class ; 
  gpointer padding [12 ] ; 
}
; 
typedef struct _GSocketClientPrivate GSocketClientPrivate ; 
struct _GSocketClientClass {
  GObjectClass parent_class ; 
  void (* event ) (GSocketClient * client , GSocketClientEvent event , GSocketConnectable * connectable , GIOStream * connection ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
}
; 
struct _GSocketClient {
  GObject parent_instance ; 
  GSocketClientPrivate * priv ; 
}
; 
struct _GSocketConnectableIface {
  GTypeInterface g_iface ; 
  GSocketAddressEnumerator * (* enumerate ) (GSocketConnectable * connectable ) ; 
  GSocketAddressEnumerator * (* proxy_enumerate ) (GSocketConnectable * connectable ) ; 
}
; 
typedef struct _GSocketPrivate GSocketPrivate ; 
struct _GSocketClass {
  GObjectClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
  void (* _g_reserved8 ) (void ) ; 
  void (* _g_reserved9 ) (void ) ; 
  void (* _g_reserved10 ) (void ) ; 
}
; 
struct _GSocket {
  GObject parent_instance ; 
  GSocketPrivate * priv ; 
}
; 
typedef struct _GSocketConnectionPrivate GSocketConnectionPrivate ; 
typedef struct _GSocketConnectionClass GSocketConnectionClass ; 
struct _GSocketConnectionClass {
  GIOStreamClass parent_class ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
}
; 
struct _GSocketConnection {
  GIOStream parent_instance ; 
  GSocketConnectionPrivate * priv ; 
}
; 
typedef struct _GSocketControlMessagePrivate GSocketControlMessagePrivate ; 
struct _GSocketControlMessageClass {
  GObjectClass parent_class ; 
  gsize (* get_size ) (GSocketControlMessage * message ) ; 
  int (* get_level ) (GSocketControlMessage * message ) ; 
  int (* get_type ) (GSocketControlMessage * message ) ; 
  void (* serialize ) (GSocketControlMessage * message , gpointer data ) ; 
  GSocketControlMessage * (* deserialize ) (int level , int type , gsize size , gpointer data ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
struct _GSocketControlMessage {
  GObject parent_instance ; 
  GSocketControlMessagePrivate * priv ; 
}
; 
typedef struct _GSocketListenerPrivate GSocketListenerPrivate ; 
typedef struct _GSocketListenerClass GSocketListenerClass ; 
struct _GSocketListenerClass {
  GObjectClass parent_class ; 
  void (* changed ) (GSocketListener * listener ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
}
; 
struct _GSocketListener {
  GObject parent_instance ; 
  GSocketListenerPrivate * priv ; 
}
; 
typedef struct _GSocketServicePrivate GSocketServicePrivate ; 
typedef struct _GSocketServiceClass GSocketServiceClass ; 
struct _GSocketServiceClass {
  GSocketListenerClass parent_class ; 
  gboolean (* incoming ) (GSocketService * service , GSocketConnection * connection , GObject * source_object ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
}
; 
struct _GSocketService {
  GSocketListener parent_instance ; 
  GSocketServicePrivate * priv ; 
}
; 
typedef struct _GTcpConnectionPrivate GTcpConnectionPrivate ; 
typedef struct _GTcpConnectionClass GTcpConnectionClass ; 
struct _GTcpConnectionClass {
  GSocketConnectionClass parent_class ; 
}
; 
struct _GTcpConnection {
  GSocketConnection parent_instance ; 
  GTcpConnectionPrivate * priv ; 
}
; 
typedef struct _GTcpWrapperConnectionPrivate GTcpWrapperConnectionPrivate ; 
struct _GTcpWrapperConnectionClass {
  GTcpConnectionClass parent_class ; 
}
; 
struct _GTcpWrapperConnection {
  GTcpConnection parent_instance ; 
  GTcpWrapperConnectionPrivate * priv ; 
}
; 
typedef struct _GThreadedSocketServicePrivate GThreadedSocketServicePrivate ; 
struct _GThreadedSocketServiceClass {
  GSocketServiceClass parent_class ; 
  gboolean (* run ) (GThreadedSocketService * service , GSocketConnection * connection , GObject * source_object ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
}
; 
struct _GThreadedSocketService {
  GSocketService parent_instance ; 
  GThreadedSocketServicePrivate * priv ; 
}
; 
typedef struct _GTlsBackend GTlsBackend ; 
struct _GTlsBackendInterface {
  GTypeInterface g_iface ; 
  gboolean (* supports_tls ) (GTlsBackend * backend ) ; 
  GType (* get_certificate_type ) (void ) ; 
  GType (* get_client_connection_type ) (void ) ; 
  GType (* get_server_connection_type ) (void ) ; 
  GType (* get_file_database_type ) (void ) ; 
  GTlsDatabase * (* get_default_database ) (GTlsBackend * backend ) ; 
}
; 
typedef struct _GTlsCertificatePrivate GTlsCertificatePrivate ; 
struct _GTlsCertificate {
  GObject parent_instance ; 
  GTlsCertificatePrivate * priv ; 
}
; 
struct _GTlsCertificateClass {
  GObjectClass parent_class ; 
  GTlsCertificateFlags (* verify ) (GTlsCertificate * cert , GSocketConnectable * identity , GTlsCertificate * trusted_ca ) ; 
  gpointer padding [8 ] ; 
}
; 
typedef struct _GTlsConnectionPrivate GTlsConnectionPrivate ; 
struct _GTlsConnection {
  GIOStream parent_instance ; 
  GTlsConnectionPrivate * priv ; 
}
; 
struct _GTlsConnectionClass {
  GIOStreamClass parent_class ; 
  gboolean (* accept_certificate ) (GTlsConnection * connection , GTlsCertificate * peer_cert , GTlsCertificateFlags errors ) ; 
  gboolean (* handshake ) (GTlsConnection * conn , GCancellable * cancellable , GError * * error ) ; 
  void (* handshake_async ) (GTlsConnection * conn , int io_priority , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* handshake_finish ) (GTlsConnection * conn , GAsyncResult * result , GError * * error ) ; 
  gpointer padding [8 ] ; 
}
; 
__attribute__ ((__deprecated__ ) ) void g_tls_connection_set_use_system_certdb (GTlsConnection * conn , gboolean use_system_certdb ) ; 
__attribute__ ((__deprecated__ ) ) gboolean g_tls_connection_get_use_system_certdb (GTlsConnection * conn ) ; 
struct _GTlsClientConnectionInterface {
  GTypeInterface g_iface ; 
}
; 
typedef struct _GTlsDatabasePrivate GTlsDatabasePrivate ; 
struct _GTlsDatabase {
  GObject parent_instance ; 
  GTlsDatabasePrivate * priv ; 
}
; 
struct _GTlsDatabaseClass {
  GObjectClass parent_class ; 
  GTlsCertificateFlags (* verify_chain ) (GTlsDatabase * self , GTlsCertificate * chain , const gchar * purpose , GSocketConnectable * identity , GTlsInteraction * interaction , GTlsDatabaseVerifyFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* verify_chain_async ) (GTlsDatabase * self , GTlsCertificate * chain , const gchar * purpose , GSocketConnectable * identity , GTlsInteraction * interaction , GTlsDatabaseVerifyFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GTlsCertificateFlags (* verify_chain_finish ) (GTlsDatabase * self , GAsyncResult * result , GError * * error ) ; 
  gchar * (* create_certificate_handle ) (GTlsDatabase * self , GTlsCertificate * certificate ) ; 
  GTlsCertificate * (* lookup_certificate_for_handle ) (GTlsDatabase * self , const gchar * handle , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_certificate_for_handle_async ) (GTlsDatabase * self , const gchar * handle , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GTlsCertificate * (* lookup_certificate_for_handle_finish ) (GTlsDatabase * self , GAsyncResult * result , GError * * error ) ; 
  GTlsCertificate * (* lookup_certificate_issuer ) (GTlsDatabase * self , GTlsCertificate * certificate , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_certificate_issuer_async ) (GTlsDatabase * self , GTlsCertificate * certificate , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GTlsCertificate * (* lookup_certificate_issuer_finish ) (GTlsDatabase * self , GAsyncResult * result , GError * * error ) ; 
  GList * (* lookup_certificates_issued_by ) (GTlsDatabase * self , GByteArray * issuer_raw_dn , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* lookup_certificates_issued_by_async ) (GTlsDatabase * self , GByteArray * issuer_raw_dn , GTlsInteraction * interaction , GTlsDatabaseLookupFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GList * (* lookup_certificates_issued_by_finish ) (GTlsDatabase * self , GAsyncResult * result , GError * * error ) ; 
  gpointer padding [16 ] ; 
}
; 
struct _GTlsFileDatabaseInterface {
  GTypeInterface g_iface ; 
  gpointer padding [8 ] ; 
}
; 
typedef struct _GTlsInteractionPrivate GTlsInteractionPrivate ; 
struct _GTlsInteraction {
  GObject parent_instance ; 
  GTlsInteractionPrivate * priv ; 
}
; 
struct _GTlsInteractionClass {
  GObjectClass parent_class ; 
  GTlsInteractionResult (* ask_password ) (GTlsInteraction * interaction , GTlsPassword * password , GCancellable * cancellable , GError * * error ) ; 
  void (* ask_password_async ) (GTlsInteraction * interaction , GTlsPassword * password , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  GTlsInteractionResult (* ask_password_finish ) (GTlsInteraction * interaction , GAsyncResult * result , GError * * error ) ; 
  gpointer padding [24 ] ; 
}
; 
struct _GTlsServerConnectionInterface {
  GTypeInterface g_iface ; 
}
; 
typedef struct _GTlsPasswordPrivate GTlsPasswordPrivate ; 
struct _GTlsPassword {
  GObject parent_instance ; 
  GTlsPasswordPrivate * priv ; 
}
; 
struct _GTlsPasswordClass {
  GObjectClass parent_class ; 
  const guchar * (* get_value ) (GTlsPassword * password , gsize * length ) ; 
  void (* set_value ) (GTlsPassword * password , guchar * value , gssize length , GDestroyNotify destroy ) ; 
  const gchar * (* get_default_warning ) (GTlsPassword * password ) ; 
  gpointer padding [4 ] ; 
}
; 
struct _GVfs {
  GObject parent_instance ; 
}
; 
struct _GVfsClass {
  GObjectClass parent_class ; 
  gboolean (* is_active ) (GVfs * vfs ) ; 
  GFile * (* get_file_for_path ) (GVfs * vfs , const char * path ) ; 
  GFile * (* get_file_for_uri ) (GVfs * vfs , const char * uri ) ; 
  const gchar * const * (* get_supported_uri_schemes ) (GVfs * vfs ) ; 
  GFile * (* parse_name ) (GVfs * vfs , const char * parse_name ) ; 
  void (* local_file_add_info ) (GVfs * vfs , const char * filename , guint64 device , GFileAttributeMatcher * attribute_matcher , GFileInfo * info , GCancellable * cancellable , gpointer * extra_data , GDestroyNotify * free_extra_data ) ; 
  void (* add_writable_namespaces ) (GVfs * vfs , GFileAttributeInfoList * list ) ; 
  gboolean (* local_file_set_attributes ) (GVfs * vfs , const char * filename , GFileInfo * info , GFileQueryInfoFlags flags , GCancellable * cancellable , GError * * error ) ; 
  void (* local_file_removed ) (GVfs * vfs , const char * filename ) ; 
  void (* local_file_moved ) (GVfs * vfs , const char * source , const char * dest ) ; 
  void (* _g_reserved1 ) (void ) ; 
  void (* _g_reserved2 ) (void ) ; 
  void (* _g_reserved3 ) (void ) ; 
  void (* _g_reserved4 ) (void ) ; 
  void (* _g_reserved5 ) (void ) ; 
  void (* _g_reserved6 ) (void ) ; 
  void (* _g_reserved7 ) (void ) ; 
}
; 
struct _GVolumeIface {
  GTypeInterface g_iface ; 
  void (* changed ) (GVolume * volume ) ; 
  void (* removed ) (GVolume * volume ) ; 
  char * (* get_name ) (GVolume * volume ) ; 
  GIcon * (* get_icon ) (GVolume * volume ) ; 
  char * (* get_uuid ) (GVolume * volume ) ; 
  GDrive * (* get_drive ) (GVolume * volume ) ; 
  GMount * (* get_mount ) (GVolume * volume ) ; 
  gboolean (* can_mount ) (GVolume * volume ) ; 
  gboolean (* can_eject ) (GVolume * volume ) ; 
  void (* mount_fn ) (GVolume * volume , GMountMountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* mount_finish ) (GVolume * volume , GAsyncResult * result , GError * * error ) ; 
  void (* eject ) (GVolume * volume , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_finish ) (GVolume * volume , GAsyncResult * result , GError * * error ) ; 
  char * (* get_identifier ) (GVolume * volume , const char * kind ) ; 
  char * * (* enumerate_identifiers ) (GVolume * volume ) ; 
  gboolean (* should_automount ) (GVolume * volume ) ; 
  GFile * (* get_activation_root ) (GVolume * volume ) ; 
  void (* eject_with_operation ) (GVolume * volume , GMountUnmountFlags flags , GMountOperation * mount_operation , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
  gboolean (* eject_with_operation_finish ) (GVolume * volume , GAsyncResult * result , GError * * error ) ; 
  const gchar * (* get_sort_key ) (GVolume * volume ) ; 
}
; 
__attribute__ ((__deprecated__ ("Use '" "g_volume_eject_with_operation" "' instead" ) ) ) void g_volume_eject (GVolume * volume , GMountUnmountFlags flags , GCancellable * cancellable , GAsyncReadyCallback callback , gpointer user_data ) ; 
__attribute__ ((__deprecated__ ("Use '" "g_volume_eject_with_operation_finish" "' instead" ) ) ) gboolean g_volume_eject_finish (GVolume * volume , GAsyncResult * result , GError * * error ) ; 
struct _GZlibCompressorClass {
  GObjectClass parent_class ; 
}
; 
struct _GZlibDecompressorClass {
  GObjectClass parent_class ; 
}
; 
struct _GDBusInterfaceIface {
  GTypeInterface parent_iface ; 
  GDBusInterfaceInfo * (* get_info ) (GDBusInterface * interface_ ) ; 
  GDBusObject * (* get_object ) (GDBusInterface * interface_ ) ; 
  void (* set_object ) (GDBusInterface * interface_ , GDBusObject * object ) ; 
  GDBusObject * (* dup_object ) (GDBusInterface * interface_ ) ; 
}
; 
typedef struct _GDBusInterfaceSkeletonPrivate GDBusInterfaceSkeletonPrivate ; 
struct _GDBusInterfaceSkeleton {
  GObject parent_instance ; 
  GDBusInterfaceSkeletonPrivate * priv ; 
}
; 
struct _GDBusInterfaceSkeletonClass {
  GObjectClass parent_class ; 
  GDBusInterfaceInfo * (* get_info ) (GDBusInterfaceSkeleton * interface_ ) ; 
  GDBusInterfaceVTable * (* get_vtable ) (GDBusInterfaceSkeleton * interface_ ) ; 
  GVariant * (* get_properties ) (GDBusInterfaceSkeleton * interface_ ) ; 
  void (* flush ) (GDBusInterfaceSkeleton * interface_ ) ; 
  gpointer vfunc_padding [8 ] ; 
  gboolean (* g_authorize_method ) (GDBusInterfaceSkeleton * interface_ , GDBusMethodInvocation * invocation ) ; 
  gpointer signal_padding [8 ] ; 
}
; 
struct _GDBusObjectIface {
  GTypeInterface parent_iface ; 
  const gchar * (* get_object_path ) (GDBusObject * object ) ; 
  GList * (* get_interfaces ) (GDBusObject * object ) ; 
  GDBusInterface * (* get_interface ) (GDBusObject * object , const gchar * interface_name ) ; 
  void (* interface_added ) (GDBusObject * object , GDBusInterface * interface_ ) ; 
  void (* interface_removed ) (GDBusObject * object , GDBusInterface * interface_ ) ; 
}
; 
typedef struct _GDBusObjectSkeletonPrivate GDBusObjectSkeletonPrivate ; 
struct _GDBusObjectSkeleton {
  GObject parent_instance ; 
  GDBusObjectSkeletonPrivate * priv ; 
}
; 
struct _GDBusObjectSkeletonClass {
  GObjectClass parent_class ; 
  gboolean (* authorize_method ) (GDBusObjectSkeleton * object , GDBusInterfaceSkeleton * interface_ , GDBusMethodInvocation * invocation ) ; 
  gpointer padding [8 ] ; 
}
; 
typedef struct _GDBusObjectProxyPrivate GDBusObjectProxyPrivate ; 
struct _GDBusObjectProxy {
  GObject parent_instance ; 
  GDBusObjectProxyPrivate * priv ; 
}
; 
struct _GDBusObjectProxyClass {
  GObjectClass parent_class ; 
  gpointer padding [8 ] ; 
}
; 
struct _GDBusObjectManagerIface {
  GTypeInterface parent_iface ; 
  const gchar * (* get_object_path ) (GDBusObjectManager * manager ) ; 
  GList * (* get_objects ) (GDBusObjectManager * manager ) ; 
  GDBusObject * (* get_object ) (GDBusObjectManager * manager , const gchar * object_path ) ; 
  GDBusInterface * (* get_interface ) (GDBusObjectManager * manager , const gchar * object_path , const gchar * interface_name ) ; 
  void (* object_added ) (GDBusObjectManager * manager , GDBusObject * object ) ; 
  void (* object_removed ) (GDBusObjectManager * manager , GDBusObject * object ) ; 
  void (* interface_added ) (GDBusObjectManager * manager , GDBusObject * object , GDBusInterface * interface_ ) ; 
  void (* interface_removed ) (GDBusObjectManager * manager , GDBusObject * object , GDBusInterface * interface_ ) ; 
}
; 
typedef struct _GDBusObjectManagerClientPrivate GDBusObjectManagerClientPrivate ; 
struct _GDBusObjectManagerClient {
  GObject parent_instance ; 
  GDBusObjectManagerClientPrivate * priv ; 
}
; 
struct _GDBusObjectManagerClientClass {
  GObjectClass parent_class ; 
  void (* interface_proxy_signal ) (GDBusObjectManagerClient * manager , GDBusObjectProxy * object_proxy , GDBusProxy * interface_proxy , const gchar * sender_name , const gchar * signal_name , GVariant * parameters ) ; 
  void (* interface_proxy_properties_changed ) (GDBusObjectManagerClient * manager , GDBusObjectProxy * object_proxy , GDBusProxy * interface_proxy , GVariant * changed_properties , const gchar * const * invalidated_properties ) ; 
  gpointer padding [8 ] ; 
}
; 
typedef struct _GDBusObjectManagerServerPrivate GDBusObjectManagerServerPrivate ; 
struct _GDBusObjectManagerServer {
  GObject parent_instance ; 
  GDBusObjectManagerServerPrivate * priv ; 
}
; 
struct _GDBusObjectManagerServerClass {
  GObjectClass parent_class ; 
  gpointer padding [8 ] ; 
}
; 
struct _GRemoteActionGroupInterface {
  GTypeInterface g_iface ; 
  void (* activate_action_full ) (GRemoteActionGroup * remote , const gchar * action_name , GVariant * parameter , GVariant * platform_data ) ; 
  void (* change_action_state_full ) (GRemoteActionGroup * remote , const gchar * action_name , GVariant * value , GVariant * platform_data ) ; 
}
; 
typedef struct _GMenuModelPrivate GMenuModelPrivate ; 
typedef struct _GMenuAttributeIterPrivate GMenuAttributeIterPrivate ; 
typedef struct _GMenuAttributeIter GMenuAttributeIter ; 
typedef struct _GMenuLinkIterPrivate GMenuLinkIterPrivate ; 
typedef struct _GMenuLinkIter GMenuLinkIter ; 
struct _GMenuModel {
  GObject parent_instance ; 
  GMenuModelPrivate * priv ; 
}
; 
struct _GMenuModelClass {
  GObjectClass parent_class ; 
  gboolean (* is_mutable ) (GMenuModel * model ) ; 
  gint (* get_n_items ) (GMenuModel * model ) ; 
  void (* get_item_attributes ) (GMenuModel * model , gint item_index , GHashTable * * attributes ) ; 
  GMenuAttributeIter * (* iterate_item_attributes ) (GMenuModel * model , gint item_index ) ; 
  GVariant * (* get_item_attribute_value ) (GMenuModel * model , gint item_index , const gchar * attribute , const GVariantType * expected_type ) ; 
  void (* get_item_links ) (GMenuModel * model , gint item_index , GHashTable * * links ) ; 
  GMenuLinkIter * (* iterate_item_links ) (GMenuModel * model , gint item_index ) ; 
  GMenuModel * (* get_item_link ) (GMenuModel * model , gint item_index , const gchar * link ) ; 
}
; 
struct _GMenuAttributeIter {
  GObject parent_instance ; 
  GMenuAttributeIterPrivate * priv ; 
}
; 
struct _GMenuAttributeIterClass {
  GObjectClass parent_class ; 
  gboolean (* get_next ) (GMenuAttributeIter * iter , const gchar * * out_type , GVariant * * value ) ; 
}
; 
struct _GMenuLinkIter {
  GObject parent_instance ; 
  GMenuLinkIterPrivate * priv ; 
}
; 
struct _GMenuLinkIterClass {
  GObjectClass parent_class ; 
  gboolean (* get_next ) (GMenuLinkIter * iter , const gchar * * out_name , GMenuModel * * value ) ; 
}
; 
typedef struct _GMenuItem GMenuItem ; 
typedef struct _GMenu GMenu ; 
typedef struct _GDBusMenuModel GDBusMenuModel ; 
typedef unsigned long int uintptr_t ; 
typedef long int intmax_t ; 
typedef unsigned long int uintmax_t ; 
typedef int __gwchar_t ; 
typedef struct {
  long int quot ; 
  long int rem ; 
}
imaxdiv_t ; 
struct _IO_FILE ; 
typedef struct _IO_FILE FILE ; 
typedef struct {
  int __count ; 
  union {
    unsigned int __wch ; 
    char __wchb [4 ] ; 
  }
  __value ; 
}
__mbstate_t ; 
typedef struct {
  __off_t __pos ; 
  __mbstate_t __state ; 
}
_G_fpos_t ; 
typedef struct {
  __off64_t __pos ; 
  __mbstate_t __state ; 
}
_G_fpos64_t ; 
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
struct _IO_FILE ; 
typedef void _IO_lock_t ; 
struct _IO_marker {
  struct _IO_marker * _next ; 
  struct _IO_FILE * _sbuf ; 
  int _pos ; 
}
; 
enum __codecvt_result {
  __codecvt_ok , __codecvt_partial , __codecvt_error , __codecvt_noconv }
; 
struct _IO_FILE {
  int _flags ; 
  char * _IO_read_ptr ; 
  char * _IO_read_end ; 
  char * _IO_read_base ; 
  char * _IO_write_base ; 
  char * _IO_write_ptr ; 
  char * _IO_write_end ; 
  char * _IO_buf_base ; 
  char * _IO_buf_end ; 
  char * _IO_save_base ; 
  char * _IO_backup_base ; 
  char * _IO_save_end ; 
  struct _IO_marker * _markers ; 
  struct _IO_FILE * _chain ; 
  int _fileno ; 
  int _flags2 ; 
  __off_t _old_offset ; 
  unsigned short _cur_column ; 
  signed char _vtable_offset ; 
  char _shortbuf [1 ] ; 
  _IO_lock_t * _lock ; 
  __off64_t _offset ; 
  void * __pad1 ; 
  void * __pad2 ; 
  void * __pad3 ; 
  void * __pad4 ; 
  size_t __pad5 ; 
  int _mode ; 
  char _unused2 [15 * sizeof (int ) - 4 * sizeof (void * ) - sizeof (size_t ) ] ; 
}
; 
typedef struct _IO_FILE _IO_FILE ; 
struct _IO_FILE_plus ; 
typedef __ssize_t __io_read_fn (void * __cookie , char * __buf , size_t __nbytes ) ; 
typedef __ssize_t __io_write_fn (void * __cookie , __const char * __buf , size_t __n ) ; 
typedef int __io_seek_fn (void * __cookie , __off64_t * __pos , int __w ) ; 
typedef int __io_close_fn (void * __cookie ) ; 
typedef _G_fpos_t fpos_t ; 
extern struct _IO_FILE * stderr ; 
extern int fprintf (FILE * __restrict __stream , __const char * __restrict __format , ... ) ; 
extern int fscanf (FILE * __restrict __stream , __const char * __restrict __format , ... ) ; 
extern int scanf (__const char * __restrict __format , ... ) ; 
extern int sscanf (__const char * __restrict __s , __const char * __restrict __format , ... ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern int fscanf (FILE * __restrict __stream , __const char * __restrict __format , ... ) __asm__ ("" "__isoc99_fscanf" ) ; 
extern int scanf (__const char * __restrict __format , ... ) __asm__ ("" "__isoc99_scanf" ) ; 
extern int sscanf (__const char * __restrict __s , __const char * __restrict __format , ... ) __asm__ ("" "__isoc99_sscanf" ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern int vfscanf (FILE * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vscanf (__const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__format__ (__scanf__ , 1 , 0 ) ) ) ; 
extern int vsscanf (__const char * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vfscanf (FILE * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vfscanf" ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vscanf (__const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vscanf" ) __attribute__ ((__format__ (__scanf__ , 1 , 0 ) ) ) ; 
extern int vsscanf (__const char * __restrict __s , __const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vsscanf" ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern __const char * __const sys_errlist [] ; 
extern char * ctermid (char * __s ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
struct __jmp_buf_tag {
  __jmp_buf __jmpbuf ; 
  int __mask_was_saved ; 
  __sigset_t __saved_mask ; 
}
; 
typedef struct __jmp_buf_tag jmp_buf [1 ] ; 
extern int __sigsetjmp (struct __jmp_buf_tag __env [1 ] , int __savemask ) __attribute__ ((__nothrow__ ) ) ; 
typedef struct __jmp_buf_tag sigjmp_buf [1 ] ; 
union wait {
  int w_status ; 
  struct {
    unsigned int __w_termsig : 7 ; 
    unsigned int __w_coredump : 1 ; 
    unsigned int __w_retcode : 8 ; 
    unsigned int : 16 ; 
  }
  __wait_terminated ; 
  struct {
    unsigned int __w_stopval : 8 ; 
    unsigned int __w_stopsig : 8 ; 
    unsigned int : 16 ; 
  }
  __wait_stopped ; 
}
; 
typedef union {
  union wait * __uptr ; 
  int * __iptr ; 
}
__WAIT_STATUS __attribute__ ((__transparent_union__ ) ) ; 
typedef struct {
  int quot ; 
  int rem ; 
}
div_t ; 
typedef struct {
  long int quot ; 
  long int rem ; 
}
ldiv_t ; 
__extension__ typedef struct {
  long long int quot ; 
  long long int rem ; 
}
lldiv_t ; 
struct random_data {
  int32_t * fptr ; 
  int32_t * rptr ; 
  int32_t * state ; 
  int rand_type ; 
  int rand_deg ; 
  int rand_sep ; 
  int32_t * end_ptr ; 
}
; 
struct drand48_data {
  unsigned short int __x [3 ] ; 
  unsigned short int __old_x [3 ] ; 
  unsigned short int __c ; 
  unsigned short int __init ; 
  unsigned long long int __a ; 
}
; 
extern void * malloc (size_t __size ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern void * calloc (size_t __nmemb , size_t __size ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__malloc__ ) ) ; 
extern void * realloc (void * __ptr , size_t __size ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__warn_unused_result__ ) ) ; 
extern void free (void * __ptr ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
typedef int (* __compar_fn_t ) (__const void * , __const void * ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
extern char * index (__const char * __s , int __c ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__pure__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
typedef short Scheme_Type ; 
typedef int mzshort ; 
typedef unsigned int mzchar ; 
typedef long long mzlonglong ; 
typedef unsigned long long umzlonglong ; 
typedef struct Scheme_Object {
  Scheme_Type type ; 
  short keyex ; 
}
Scheme_Object ; 
typedef struct Scheme_Inclhash_Object {
  Scheme_Object so ; 
}
Scheme_Inclhash_Object ; 
typedef struct Scheme_Simple_Object {
  Scheme_Inclhash_Object iso ; 
  union {
    struct {
      mzchar * string_val ; 
      intptr_t tag_val ; 
    }
    char_str_val ; 
    struct {
      char * string_val ; 
      intptr_t tag_val ; 
    }
    byte_str_val ; 
    struct {
      void * ptr1 , * ptr2 ; 
    }
    two_ptr_val ; 
    struct {
      int int1 ; 
      int int2 ; 
    }
    two_int_val ; 
    struct {
      void * ptr ; 
      int pint ; 
    }
    ptr_int_val ; 
    struct {
      void * ptr ; 
      intptr_t pint ; 
    }
    ptr_long_val ; 
    struct {
      struct Scheme_Object * car , * cdr ; 
    }
    pair_val ; 
    struct {
      mzshort len ; 
      mzshort * vec ; 
    }
    svector_val ; 
    struct {
      void * val ; 
      Scheme_Object * type ; 
    }
    cptr_val ; 
  }
  u ; 
}
Scheme_Simple_Object ; 
typedef struct Scheme_Object * (* Scheme_Closure_Func ) (struct Scheme_Object * ) ; 
typedef struct {
  Scheme_Inclhash_Object iso ; 
  union {
    mzchar char_val ; 
    Scheme_Object * ptr_value ; 
    intptr_t int_val ; 
    Scheme_Object * ptr_val ; 
  }
  u ; 
}
Scheme_Small_Object ; 
typedef struct {
  Scheme_Object so ; 
  double double_val ; 
}
Scheme_Double ; 
typedef struct {
  Scheme_Object so ; 
  float float_val ; 
}
Scheme_Float ; 
typedef struct Scheme_Symbol {
  Scheme_Inclhash_Object iso ; 
  intptr_t len ; 
  char s [4 ] ; 
}
Scheme_Symbol ; 
typedef struct Scheme_Vector {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  Scheme_Object * els [1 ] ; 
}
Scheme_Vector ; 
typedef struct Scheme_Double_Vector {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  double els [1 ] ; 
}
Scheme_Double_Vector ; 
typedef struct Scheme_Print_Params Scheme_Print_Params ; 
typedef void (* Scheme_Type_Printer ) (Scheme_Object * v , int for_display , Scheme_Print_Params * pp ) ; 
typedef int (* Scheme_Equal_Proc ) (Scheme_Object * obj1 , Scheme_Object * obj2 , void * cycle_data ) ; 
typedef intptr_t (* Scheme_Primary_Hash_Proc ) (Scheme_Object * obj , intptr_t base , void * cycle_data ) ; 
typedef intptr_t (* Scheme_Secondary_Hash_Proc ) (Scheme_Object * obj , void * cycle_data ) ; 
enum {
  scheme_toplevel_type , scheme_local_type , scheme_local_unbox_type , scheme_application_type , scheme_application2_type , scheme_application3_type , scheme_sequence_type , scheme_branch_type , scheme_unclosed_procedure_type , scheme_let_value_type , scheme_let_void_type , scheme_letrec_type , scheme_let_one_type , scheme_with_cont_mark_type , scheme_quote_syntax_type , scheme_define_values_type , scheme_define_syntaxes_type , scheme_define_for_syntax_type , scheme_set_bang_type , scheme_boxenv_type , scheme_begin0_sequence_type , scheme_splice_sequence_type , scheme_require_form_type , scheme_varref_form_type , scheme_apply_values_type , scheme_case_lambda_sequence_type , scheme_module_type , _scheme_values_types_ , scheme_compiled_unclosed_procedure_type , scheme_compiled_let_value_type , scheme_compiled_let_void_type , scheme_compiled_toplevel_type , scheme_compiled_quote_syntax_type , scheme_quote_compilation_type , scheme_variable_type , scheme_module_variable_type , _scheme_compiled_values_types_ , scheme_prim_type , scheme_closed_prim_type , scheme_closure_type , scheme_case_closure_type , scheme_cont_type , scheme_escaping_cont_type , scheme_proc_struct_type , scheme_native_closure_type , scheme_proc_chaperone_type , scheme_chaperone_type , scheme_structure_type , scheme_char_type , scheme_integer_type , scheme_bignum_type , scheme_rational_type , scheme_float_type , scheme_double_type , scheme_complex_type , scheme_char_string_type , scheme_byte_string_type , scheme_unix_path_type , scheme_windows_path_type , scheme_symbol_type , scheme_keyword_type , scheme_null_type , scheme_pair_type , scheme_mutable_pair_type , scheme_vector_type , scheme_inspector_type , scheme_input_port_type , scheme_output_port_type , scheme_eof_type , scheme_true_type , scheme_false_type , scheme_void_type , scheme_syntax_compiler_type , scheme_macro_type , scheme_box_type , scheme_thread_type , scheme_stx_offset_type , scheme_cont_mark_set_type , scheme_sema_type , scheme_hash_table_type , scheme_hash_tree_type , scheme_cpointer_type , scheme_prefix_type , scheme_weak_box_type , scheme_ephemeron_type , scheme_struct_type_type , scheme_module_index_type , scheme_set_macro_type , scheme_listener_type , scheme_namespace_type , scheme_config_type , scheme_stx_type , scheme_will_executor_type , scheme_custodian_type , scheme_random_state_type , scheme_regexp_type , scheme_bucket_type , scheme_bucket_table_type , scheme_subprocess_type , scheme_compilation_top_type , scheme_wrap_chunk_type , scheme_eval_waiting_type , scheme_tail_call_waiting_type , scheme_undefined_type , scheme_struct_property_type , scheme_chaperone_property_type , scheme_multiple_values_type , scheme_placeholder_type , scheme_table_placeholder_type , scheme_rename_table_type , scheme_rename_table_set_type , scheme_svector_type , scheme_resolve_prefix_type , scheme_security_guard_type , scheme_indent_type , scheme_udp_type , scheme_udp_evt_type , scheme_tcp_accept_evt_type , scheme_id_macro_type , scheme_evt_set_type , scheme_wrap_evt_type , scheme_handle_evt_type , scheme_nack_guard_evt_type , scheme_semaphore_repost_type , scheme_channel_type , scheme_channel_put_type , scheme_thread_resume_type , scheme_thread_suspend_type , scheme_thread_dead_type , scheme_poll_evt_type , scheme_nack_evt_type , scheme_module_registry_type , scheme_thread_set_type , scheme_string_converter_type , scheme_alarm_type , scheme_thread_recv_evt_type , scheme_thread_cell_type , scheme_channel_syncer_type , scheme_special_comment_type , scheme_write_evt_type , scheme_always_evt_type , scheme_never_evt_type , scheme_progress_evt_type , scheme_place_dead_type , scheme_already_comp_type , scheme_readtable_type , scheme_intdef_context_type , scheme_lexical_rib_type , scheme_thread_cell_values_type , scheme_global_ref_type , scheme_cont_mark_chain_type , scheme_raw_pair_type , scheme_prompt_type , scheme_prompt_tag_type , scheme_expanded_syntax_type , scheme_delay_syntax_type , scheme_cust_box_type , scheme_resolved_module_path_type , scheme_module_phase_exports_type , scheme_logger_type , scheme_log_reader_type , scheme_free_id_info_type , scheme_rib_delimiter_type , scheme_noninline_proc_type , scheme_prune_context_type , scheme_future_type , scheme_flvector_type , scheme_fxvector_type , scheme_place_type , scheme_place_object_type , scheme_place_async_channel_type , scheme_place_bi_channel_type , scheme_once_used_type , scheme_serialized_symbol_type , scheme_serialized_structure_type , _scheme_last_normal_type_ , scheme_rt_weak_array , scheme_rt_comp_env , scheme_rt_constant_binding , scheme_rt_resolve_info , scheme_rt_optimize_info , scheme_rt_compile_info , scheme_rt_cont_mark , scheme_rt_saved_stack , scheme_rt_reply_item , scheme_rt_closure_info , scheme_rt_overflow , scheme_rt_overflow_jmp , scheme_rt_meta_cont , scheme_rt_dyn_wind_cell , scheme_rt_dyn_wind_info , scheme_rt_dyn_wind , scheme_rt_dup_check , scheme_rt_thread_memory , scheme_rt_input_file , scheme_rt_input_fd , scheme_rt_oskit_console_input , scheme_rt_tested_input_file , scheme_rt_tested_output_file , scheme_rt_indexed_string , scheme_rt_output_file , scheme_rt_load_handler_data , scheme_rt_pipe , scheme_rt_beos_process , scheme_rt_system_child , scheme_rt_tcp , scheme_rt_write_data , scheme_rt_tcp_select_info , scheme_rt_param_data , scheme_rt_will , scheme_rt_struct_proc_info , scheme_rt_linker_name , scheme_rt_param_map , scheme_rt_finalization , scheme_rt_finalizations , scheme_rt_cpp_object , scheme_rt_cpp_array_object , scheme_rt_stack_object , scheme_rt_preallocated_object , scheme_thread_hop_type , scheme_rt_srcloc , scheme_rt_evt , scheme_rt_syncing , scheme_rt_comp_prefix , scheme_rt_user_input , scheme_rt_user_output , scheme_rt_compact_port , scheme_rt_read_special_dw , scheme_rt_regwork , scheme_rt_buf_holder , scheme_rt_parameterization , scheme_rt_print_params , scheme_rt_read_params , scheme_rt_native_code , scheme_rt_native_code_plus_case , scheme_rt_jitter_data , scheme_rt_module_exports , scheme_rt_delay_load_info , scheme_rt_marshal_info , scheme_rt_unmarshal_info , scheme_rt_runstack , scheme_rt_sfs_info , scheme_rt_validate_clearing , scheme_rt_rb_node , scheme_rt_lightweight_cont , scheme_fsemaphore_type , _scheme_last_type_ }
; 
typedef struct Scheme_Cptr {
  Scheme_Inclhash_Object so ; 
  void * val ; 
  Scheme_Object * type ; 
}
Scheme_Cptr ; 
typedef struct Scheme_Offset_Cptr {
  Scheme_Cptr cptr ; 
  intptr_t offset ; 
}
Scheme_Offset_Cptr ; 
typedef struct Scheme_Object * (Scheme_Prim ) (int argc , Scheme_Object * argv [] ) ; 
typedef struct Scheme_Object * (Scheme_Primitive_Closure_Proc ) (int argc , struct Scheme_Object * argv [] , Scheme_Object * p ) ; 
typedef struct {
  Scheme_Object so ; 
  unsigned short flags ; 
}
Scheme_Prim_Proc_Header ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Primitive_Closure_Proc * prim_val ; 
  const char * name ; 
  mzshort mina ; 
  union {
    mzshort * cases ; 
    mzshort maxa ; 
  }
  mu ; 
}
Scheme_Primitive_Proc ; 
typedef struct {
  Scheme_Primitive_Proc pp ; 
  mzshort minr , maxr ; 
}
Scheme_Prim_W_Result_Arity ; 
typedef struct Scheme_Primitive_Closure {
  Scheme_Primitive_Proc p ; 
  mzshort count ; 
  Scheme_Object * val [1 ] ; 
}
Scheme_Primitive_Closure ; 
typedef struct Scheme_Object * (Scheme_Closed_Prim ) (void * d , int argc , struct Scheme_Object * argv [] ) ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Closed_Prim * prim_val ; 
  void * data ; 
  const char * name ; 
  mzshort mina , maxa ; 
}
Scheme_Closed_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort * cases ; 
}
Scheme_Closed_Case_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort minr , maxr ; 
}
Scheme_Closed_Prim_W_Result_Arity ; 
typedef struct Scheme_Hash_Table {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  intptr_t count ; 
  Scheme_Object * * keys ; 
  Scheme_Object * * vals ; 
  void (* make_hash_indices ) (void * v , intptr_t * h1 , intptr_t * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
  intptr_t mcount ; 
}
Scheme_Hash_Table ; 
typedef struct Scheme_Hash_Tree Scheme_Hash_Tree ; 
typedef struct Scheme_Bucket {
  Scheme_Object so ; 
  void * val ; 
  char * key ; 
}
Scheme_Bucket ; 
typedef struct Scheme_Bucket_Table {
  Scheme_Object so ; 
  intptr_t size ; 
  intptr_t count ; 
  Scheme_Bucket * * buckets ; 
  char weak ; 
  char with_home ; 
  void (* make_hash_indices ) (void * v , intptr_t * h1 , intptr_t * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
}
Scheme_Bucket_Table ; 
enum {
  SCHEME_hash_string , SCHEME_hash_ptr , SCHEME_hash_bound_id , SCHEME_hash_weak_ptr , SCHEME_hash_late_weak_ptr }
; 
typedef struct Scheme_Env Scheme_Env ; 
typedef struct {
  jmp_buf jb ; 
  uintptr_t stack_frame ; 
}
mz_one_jit_jmp_buf ; 
typedef mz_one_jit_jmp_buf mz_jit_jmp_buf [1 ] ; 
typedef struct {
  mz_jit_jmp_buf jb ; 
  intptr_t gcvs ; 
  intptr_t gcvs_cnt ; 
}
mz_jmp_buf ; 
typedef struct Scheme_Jumpup_Buf {
  void * stack_from , * stack_copy ; 
  intptr_t stack_size , stack_max_size ; 
  struct Scheme_Cont * cont ; 
  mz_jmp_buf buf ; 
  void * gc_var_stack ; 
  void * external_stack ; 
}
Scheme_Jumpup_Buf ; 
typedef struct Scheme_Jumpup_Buf_Holder {
  Scheme_Type type ; 
  Scheme_Jumpup_Buf buf ; 
}
Scheme_Jumpup_Buf_Holder ; 
typedef struct Scheme_Continuation_Jump_State {
  struct Scheme_Object * jumping_to_continuation ; 
  struct Scheme_Object * alt_full_continuation ; 
  Scheme_Object * val ; 
  mzshort num_vals ; 
  char is_kill , is_escape , skip_dws ; 
}
Scheme_Continuation_Jump_State ; 
typedef struct Scheme_Cont_Frame_Data {
  intptr_t cont_mark_pos ; 
  intptr_t cont_mark_stack ; 
  void * cache ; 
}
Scheme_Cont_Frame_Data ; 
typedef struct objhead {
  uintptr_t hash : ((8 * sizeof (intptr_t ) ) - (4 + 3 + 14 ) ) ; 
  uintptr_t type : 3 ; 
  uintptr_t mark : 1 ; 
  uintptr_t btc_mark : 1 ; 
  uintptr_t moved : 1 ; 
  uintptr_t dead : 1 ; 
  uintptr_t size : 14 ; 
}
objhead ; 
typedef void (Scheme_Close_Custodian_Client ) (Scheme_Object * o , void * data ) ; 
typedef void (* Scheme_Exit_Closer_Func ) (Scheme_Object * , Scheme_Close_Custodian_Client * , void * ) ; 
typedef Scheme_Object * (* Scheme_Custodian_Extractor ) (Scheme_Object * o ) ; 
typedef struct Scheme_Object Scheme_Custodian_Reference ; 
typedef struct Scheme_Custodian Scheme_Custodian ; 
typedef Scheme_Bucket_Table Scheme_Thread_Cell_Table ; 
typedef struct Scheme_Config Scheme_Config ; 
typedef int (* Scheme_Ready_Fun ) (Scheme_Object * o ) ; 
typedef void (* Scheme_Needs_Wakeup_Fun ) (Scheme_Object * , void * ) ; 
typedef Scheme_Object * (* Scheme_Sync_Sema_Fun ) (Scheme_Object * , int * repost ) ; 
typedef int (* Scheme_Sync_Filter_Fun ) (Scheme_Object * ) ; 
typedef struct Scheme_Thread {
  Scheme_Object so ; 
  struct Scheme_Thread * next ; 
  struct Scheme_Thread * prev ; 
  struct Scheme_Thread_Set * t_set_parent ; 
  Scheme_Object * t_set_next ; 
  Scheme_Object * t_set_prev ; 
  mz_jmp_buf * error_buf ; 
  Scheme_Continuation_Jump_State cjs ; 
  struct Scheme_Meta_Continuation * decompose_mc ; 
  Scheme_Thread_Cell_Table * cell_values ; 
  Scheme_Config * init_config ; 
  Scheme_Object * init_break_cell ; 
  int can_break_at_swap ; 
  Scheme_Object * * runstack ; 
  Scheme_Object * * runstack_start ; 
  intptr_t runstack_size ; 
  struct Scheme_Saved_Stack * runstack_saved ; 
  Scheme_Object * * runstack_tmp_keep ; 
  Scheme_Object * * spare_runstack ; 
  intptr_t spare_runstack_size ; 
  struct Scheme_Thread * * runstack_owner ; 
  struct Scheme_Saved_Stack * runstack_swapped ; 
  intptr_t cont_mark_pos ; 
  intptr_t cont_mark_stack ; 
  struct Scheme_Cont_Mark * * cont_mark_stack_segments ; 
  intptr_t cont_mark_seg_count ; 
  intptr_t cont_mark_stack_bottom ; 
  intptr_t cont_mark_pos_bottom ; 
  struct Scheme_Thread * * cont_mark_stack_owner ; 
  struct Scheme_Cont_Mark * cont_mark_stack_swapped ; 
  struct Scheme_Prompt * meta_prompt ; 
  struct Scheme_Meta_Continuation * meta_continuation ; 
  struct Scheme_Prompt * acting_barrier_prompt ; 
  intptr_t engine_weight ; 
  void * stack_start ; 
  void * stack_end ; 
  Scheme_Jumpup_Buf jmpup_buf ; 
  struct Scheme_Dynamic_Wind * dw ; 
  int next_meta ; 
  int running ; 
  Scheme_Object * suspended_box ; 
  Scheme_Object * resumed_box ; 
  Scheme_Object * dead_box ; 
  Scheme_Object * running_box ; 
  struct Scheme_Thread * nester , * nestee ; 
  struct future_t * current_ft ; 
  double sleep_end ; 
  int block_descriptor ; 
  Scheme_Object * blocker ; 
  Scheme_Ready_Fun block_check ; 
  Scheme_Needs_Wakeup_Fun block_needs_wakeup ; 
  char ran_some ; 
  char suspend_to_kill ; 
  struct Scheme_Thread * return_marks_to ; 
  Scheme_Object * returned_marks ; 
  struct Scheme_Overflow * overflow ; 
  struct Scheme_Comp_Env * current_local_env ; 
  Scheme_Object * current_local_mark ; 
  Scheme_Object * current_local_name ; 
  Scheme_Object * current_local_modidx ; 
  Scheme_Env * current_local_menv ; 
  Scheme_Object * current_local_bindings ; 
  intptr_t current_phase_shift ; 
  struct Scheme_Marshal_Tables * current_mt ; 
  Scheme_Object * constant_folding ; 
  Scheme_Object * reading_delayed ; 
  Scheme_Object * (* overflow_k ) (void ) ; 
  Scheme_Object * overflow_reply ; 
  Scheme_Object * * tail_buffer ; 
  int tail_buffer_size ; 
  Scheme_Object * * values_buffer ; 
  int values_buffer_size ; 
  struct {
    struct {
      Scheme_Object * wait_expr ; 
    }
    eval ; 
    struct {
      Scheme_Object * tail_rator ; 
      Scheme_Object * * tail_rands ; 
      intptr_t tail_num_rands ; 
    }
    apply ; 
    struct {
      Scheme_Object * * array ; 
      intptr_t count ; 
    }
    multiple ; 
    struct {
      void * p1 , * p2 , * p3 , * p4 , * p5 ; 
      intptr_t i1 , i2 , i3 , i4 ; 
    }
    k ; 
  }
  ku ; 
  short suspend_break ; 
  short external_break ; 
  Scheme_Simple_Object * list_stack ; 
  int list_stack_pos ; 
  void (* on_kill ) (struct Scheme_Thread * p ) ; 
  void * kill_data ; 
  void (* private_on_kill ) (void * ) ; 
  void * private_kill_data ; 
  void * * private_kill_next ; 
  void * * user_tls ; 
  int user_tls_size ; 
  intptr_t gmp_tls [6 ] ; 
  void * gmp_tls_data ; 
  intptr_t accum_process_msec ; 
  intptr_t current_start_process_msec ; 
  struct Scheme_Thread_Custodian_Hop * mr_hop ; 
  Scheme_Custodian_Reference * mref ; 
  Scheme_Object * extra_mrefs ; 
  Scheme_Object * transitive_resumes ; 
  Scheme_Object * name ; 
  Scheme_Object * mbox_first ; 
  Scheme_Object * mbox_last ; 
  Scheme_Object * mbox_sema ; 
  long saved_errno ; 
  struct GC_Thread_Info * gc_info ; 
}
Scheme_Thread ; 
typedef struct {
  void * orig_return_address ; 
  void * stack_frame ; 
  struct Scheme_Object * cache ; 
  void * orig_result ; 
}
Stack_Cache_Elem ; 
typedef intptr_t rxpos ; 
struct gmp_tmp_stack {
  void * end ; 
  void * alloc_point ; 
  struct gmp_tmp_stack * prev ; 
}
; 
typedef void (* Scheme_Sleep_Proc ) (float seconds , void * fds ) ; 
typedef struct Thread_Local_Variables {
  int scheme_current_place_id_ ; 
  void * * GC_variable_stack_ ; 
  struct NewGC * GC_instance_ ; 
  uintptr_t GC_gen0_alloc_page_ptr_ ; 
  uintptr_t GC_gen0_alloc_page_end_ ; 
  int GC_gen0_alloc_only_ ; 
  void * bignum_cache_ [16 ] ; 
  int cache_count_ ; 
  struct Scheme_Hash_Table * toplevels_ht_ ; 
  struct Scheme_Hash_Table * locals_ht_ [2 ] ; 
  volatile int scheme_fuel_counter_ ; 
  uintptr_t scheme_stack_boundary_ ; 
  uintptr_t volatile scheme_jit_stack_boundary_ ; 
  volatile int scheme_future_need_gc_pause_ ; 
  int scheme_use_rtcall_ ; 
  int in_jit_critical_section_ ; 
  void * jit_buffer_cache_ ; 
  intptr_t jit_buffer_cache_size_ ; 
  int jit_buffer_cache_registered_ ; 
  struct Scheme_Object * quick_stx_ ; 
  int scheme_continuation_application_count_ ; 
  int scheme_cont_capture_count_ ; 
  int scheme_prompt_capture_count_ ; 
  struct Scheme_Prompt * available_prompt_ ; 
  struct Scheme_Prompt * available_cws_prompt_ ; 
  struct Scheme_Prompt * available_regular_prompt_ ; 
  struct Scheme_Dynamic_Wind * available_prompt_dw_ ; 
  struct Scheme_Meta_Continuation * available_prompt_mc_ ; 
  struct Scheme_Object * cached_beg_stx_ ; 
  struct Scheme_Object * cached_mod_stx_ ; 
  struct Scheme_Object * cached_mod_beg_stx_ ; 
  struct Scheme_Object * cached_dv_stx_ ; 
  struct Scheme_Object * cached_ds_stx_ ; 
  struct Scheme_Object * cached_dvs_stx_ ; 
  int cached_stx_phase_ ; 
  struct Scheme_Object * cwv_stx_ ; 
  int cwv_stx_phase_ ; 
  struct Scheme_Cont * offstack_cont_ ; 
  struct Scheme_Overflow * offstack_overflow_ ; 
  struct Scheme_Overflow_Jmp * scheme_overflow_jmp_ ; 
  void * scheme_overflow_stack_start_ ; 
  void * * codetab_tree_ ; 
  int during_set_ ; 
  Stack_Cache_Elem stack_cache_stack_ [32 ] ; 
  intptr_t stack_cache_stack_pos_ ; 
  struct Scheme_Object * * fixup_runstack_base_ ; 
  int fixup_already_in_place_ ; 
  void * retry_alloc_r1_ ; 
  double scheme_jit_save_fp_ ; 
  struct Scheme_Bucket_Table * starts_table_ ; 
  struct Scheme_Modidx * modidx_caching_chain_ ; 
  struct Scheme_Object * global_shift_cache_ ; 
  struct mz_proc_thread * proc_thread_self_ ; 
  struct Scheme_Object * scheme_orig_stdout_port_ ; 
  struct Scheme_Object * scheme_orig_stderr_port_ ; 
  struct Scheme_Object * scheme_orig_stdin_port_ ; 
  struct mz_fd_set * scheme_fd_set_ ; 
  struct Scheme_Custodian * new_port_cust_ ; 
  int external_event_fd_ ; 
  int put_external_event_fd_ ; 
  char * read_string_byte_buffer_ ; 
  struct ITimer_Data * itimerdata_ ; 
  char * quick_buffer_ ; 
  char * quick_encode_buffer_ ; 
  struct Scheme_Hash_Table * cache_ht_ ; 
  char * regstr_ ; 
  char * regparsestr_ ; 
  int regmatchmin_ ; 
  int regmatchmax_ ; 
  int regmaxbackposn_ ; 
  int regsavepos_ ; 
  struct Scheme_Hash_Table * regbackknown_ ; 
  struct Scheme_Hash_Table * regbackdepends_ ; 
  rxpos regparse_ ; 
  rxpos regparse_end_ ; 
  int regnpar_ ; 
  int regncounter_ ; 
  rxpos regcode_ ; 
  rxpos regcodesize_ ; 
  rxpos regcodemax_ ; 
  intptr_t regmaxlookback_ ; 
  intptr_t rx_buffer_size_ ; 
  rxpos * startp_buffer_cache_ ; 
  rxpos * endp_buffer_cache_ ; 
  rxpos * maybep_buffer_cache_ ; 
  rxpos * match_stack_buffer_cache_ ; 
  uintptr_t scheme_os_thread_stack_base_ ; 
  int traversers_registered_ ; 
  struct Finalizations * * save_fns_ptr_ ; 
  struct Scheme_Object * scheme_system_idle_channel_ ; 
  struct Scheme_Object * system_idle_put_evt_ ; 
  void * stack_copy_cache_ [10 ] ; 
  intptr_t stack_copy_size_cache_ [10 ] ; 
  int scc_pos_ ; 
  struct Scheme_Object * nominal_ipair_cache_ ; 
  struct Scheme_Object * mark_id_ ; 
  struct Scheme_Object * current_rib_timestamp_ ; 
  struct Scheme_Hash_Table * quick_hash_table_ ; 
  struct Scheme_Object * last_phase_shift_ ; 
  struct Scheme_Object * unsealed_dependencies_ ; 
  struct Scheme_Hash_Table * id_marks_ht_ ; 
  struct Scheme_Hash_Table * than_id_marks_ht_ ; 
  struct Scheme_Bucket_Table * interned_skip_ribs_ ; 
  struct Scheme_Thread * scheme_current_thread_ ; 
  struct Scheme_Thread * scheme_main_thread_ ; 
  struct Scheme_Thread * scheme_first_thread_ ; 
  struct Scheme_Thread_Set * scheme_thread_set_top_ ; 
  struct Scheme_Current_LWC * scheme_current_lwc_ ; 
  int num_running_threads_ ; 
  int swap_no_setjmp_ ; 
  int thread_swap_count_ ; 
  int scheme_did_gc_count_ ; 
  struct Scheme_Future_State * scheme_future_state_ ; 
  struct Scheme_Future_Thread_State * scheme_future_thread_state_ ; 
  void * jit_future_storage_ [2 ] ; 
  struct Scheme_Object * * scheme_current_runstack_start_ ; 
  struct Scheme_Object * * scheme_current_runstack_ ; 
  intptr_t scheme_current_cont_mark_stack_ ; 
  intptr_t scheme_current_cont_mark_pos_ ; 
  struct Scheme_Custodian * main_custodian_ ; 
  struct Scheme_Custodian * last_custodian_ ; 
  struct Scheme_Hash_Table * limited_custodians_ ; 
  struct Scheme_Thread * swap_target_ ; 
  struct Scheme_Object * scheduled_kills_ ; 
  int do_atomic_ ; 
  int missed_context_switch_ ; 
  int all_breaks_disabled_ ; 
  int have_activity_ ; 
  int scheme_active_but_sleeping_ ; 
  int thread_ended_with_activity_ ; 
  int scheme_no_stack_overflow_ ; 
  int needs_sleep_cancelled_ ; 
  double needs_sleep_time_end_ ; 
  int tls_pos_ ; 
  struct Scheme_Object * the_nested_exn_handler_ ; 
  struct Scheme_Object * cust_closers_ ; 
  struct Scheme_Object * thread_swap_callbacks_ ; 
  struct Scheme_Object * thread_swap_out_callbacks_ ; 
  struct Scheme_Object * recycle_cell_ ; 
  struct Scheme_Object * maybe_recycle_cell_ ; 
  int recycle_cc_count_ ; 
  void * gmp_mem_pool_ ; 
  uintptr_t max_total_allocation_ ; 
  uintptr_t current_total_allocation_ ; 
  struct gmp_tmp_stack gmp_tmp_xxx_ ; 
  struct gmp_tmp_stack * gmp_tmp_current_ ; 
  struct Scheme_Logger * scheme_main_logger_ ; 
  int intdef_counter_ ; 
  int builtin_ref_counter_ ; 
  int env_uid_counter_ ; 
  int scheme_overflow_count_ ; 
  struct Scheme_Object * original_pwd_ ; 
  void * file_path_wc_buffer_ ; 
  intptr_t scheme_hash_request_count_ ; 
  intptr_t scheme_hash_iteration_count_ ; 
  struct Scheme_Env * initial_modules_env_ ; 
  int num_initial_modules_ ; 
  struct Scheme_Object * * initial_modules_ ; 
  struct Scheme_Object * initial_renames_ ; 
  struct Scheme_Bucket_Table * initial_toplevel_ ; 
  int generate_lifts_count_ ; 
  int special_is_ok_ ; 
  int scheme_force_port_closed_ ; 
  int fd_reserved_ ; 
  int the_fd_ ; 
  int scheme_num_read_syntax_objects_ ; 
  struct Scheme_Load_Delay * clear_bytes_chain_ ; 
  const char * failure_msg_for_read_ ; 
  void * * dgc_array_ ; 
  int * dgc_count_ ; 
  int dgc_size_ ; 
  void (* save_oom_ ) (void ) ; 
  int current_lifetime_ ; 
  int scheme_main_was_once_suspended_ ; 
  int buffer_init_size_ ; 
  intptr_t scheme_total_gc_time_ ; 
  intptr_t start_this_gc_time_ ; 
  intptr_t end_this_gc_time_ ; 
  volatile short delayed_break_ready_ ; 
  struct Scheme_Thread * main_break_target_thread_ ; 
  intptr_t scheme_code_page_total_ ; 
  int locale_on_ ; 
  void * current_locale_name_ptr_ ; 
  int gensym_counter_ ; 
  struct Scheme_Object * dummy_input_port_ ; 
  struct Scheme_Object * dummy_output_port_ ; 
  struct Scheme_Bucket_Table * place_local_modpath_table_ ; 
  struct Scheme_Hash_Table * opened_libs_ ; 
  struct mzrt_mutex * jit_lock_ ; 
  struct free_list_entry * free_list_ ; 
  int free_list_bucket_count_ ; 
  void * code_allocation_page_list_ ; 
  struct Scheme_Bucket_Table * prefab_table_ ; 
  struct Scheme_Hash_Table * place_local_symbol_table_ ; 
  struct Scheme_Hash_Table * place_local_keyword_table_ ; 
  struct Scheme_Hash_Table * place_local_parallel_symbol_table_ ; 
  struct FFI_Sync_Queue * ffi_sync_queue_ ; 
  struct Scheme_GC_Pre_Post_Callback_Desc * gc_prepost_callback_descs_ ; 
  struct Scheme_Hash_Table * place_local_misc_table_ ; 
  int place_evts_array_size_ ; 
  struct Evt * * place_evts_ ; 
  struct Scheme_Place_Object * place_object_ ; 
  struct Scheme_Object * empty_self_shift_cache_ ; 
  struct Scheme_Bucket_Table * scheme_module_code_cache_ ; 
  struct Scheme_Object * group_member_cache_ ; 
  struct Scheme_Prefix * scheme_prefix_finalize_ ; 
  struct Scheme_Hash_Table * loaded_extensions_ ; 
  struct Scheme_Hash_Table * fullpath_loaded_extensions_ ; 
  Scheme_Sleep_Proc scheme_place_sleep_ ; 
  struct Scheme_Bucket_Table * taint_intern_table_ ; 
}
Thread_Local_Variables ; 
extern __thread Thread_Local_Variables scheme_thread_locals ; 
typedef void (* Scheme_Kill_Action_Func ) (void * ) ; 
typedef int (* Scheme_Frozen_Stack_Proc ) (void * ) ; 
enum {
  MZCONFIG_ENV , MZCONFIG_INPUT_PORT , MZCONFIG_OUTPUT_PORT , MZCONFIG_ERROR_PORT , MZCONFIG_ERROR_DISPLAY_HANDLER , MZCONFIG_ERROR_PRINT_VALUE_HANDLER , MZCONFIG_EXIT_HANDLER , MZCONFIG_INIT_EXN_HANDLER , MZCONFIG_EVAL_HANDLER , MZCONFIG_COMPILE_HANDLER , MZCONFIG_LOAD_HANDLER , MZCONFIG_LOAD_COMPILED_HANDLER , MZCONFIG_PRINT_HANDLER , MZCONFIG_PROMPT_READ_HANDLER , MZCONFIG_READ_HANDLER , MZCONFIG_READ_INPUT_PORT_HANDLER , MZCONFIG_READTABLE , MZCONFIG_READER_GUARD , MZCONFIG_CAN_READ_GRAPH , MZCONFIG_CAN_READ_COMPILED , MZCONFIG_CAN_READ_BOX , MZCONFIG_CAN_READ_PIPE_QUOTE , MZCONFIG_CAN_READ_DOT , MZCONFIG_CAN_READ_INFIX_DOT , MZCONFIG_CAN_READ_QUASI , MZCONFIG_CAN_READ_READER , MZCONFIG_CAN_READ_LANG , MZCONFIG_READ_DECIMAL_INEXACT , MZCONFIG_PRINT_GRAPH , MZCONFIG_PRINT_STRUCT , MZCONFIG_PRINT_BOX , MZCONFIG_PRINT_VEC_SHORTHAND , MZCONFIG_PRINT_HASH_TABLE , MZCONFIG_PRINT_UNREADABLE , MZCONFIG_PRINT_PAIR_CURLY , MZCONFIG_PRINT_MPAIR_CURLY , MZCONFIG_PRINT_SYNTAX_WIDTH , MZCONFIG_PRINT_READER , MZCONFIG_PRINT_LONG_BOOLEAN , MZCONFIG_PRINT_AS_QQ , MZCONFIG_CASE_SENS , MZCONFIG_SQUARE_BRACKETS_ARE_PARENS , MZCONFIG_CURLY_BRACES_ARE_PARENS , MZCONFIG_HONU_MODE , MZCONFIG_ERROR_PRINT_WIDTH , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH , MZCONFIG_ERROR_ESCAPE_HANDLER , MZCONFIG_EXE_YIELD_HANDLER , MZCONFIG_ALLOW_SET_UNDEFINED , MZCONFIG_COMPILE_MODULE_CONSTS , MZCONFIG_USE_JIT , MZCONFIG_DISALLOW_INLINE , MZCONFIG_CUSTODIAN , MZCONFIG_INSPECTOR , MZCONFIG_CODE_INSPECTOR , MZCONFIG_USE_COMPILED_KIND , MZCONFIG_USE_USER_PATHS , MZCONFIG_LOAD_DIRECTORY , MZCONFIG_WRITE_DIRECTORY , MZCONFIG_COLLECTION_PATHS , MZCONFIG_PORT_PRINT_HANDLER , MZCONFIG_LOAD_EXTENSION_HANDLER , MZCONFIG_CURRENT_DIRECTORY , MZCONFIG_RANDOM_STATE , MZCONFIG_CURRENT_MODULE_RESOLVER , MZCONFIG_CURRENT_MODULE_NAME , MZCONFIG_CURRENT_MODULE_SRC , MZCONFIG_ERROR_PRINT_SRCLOC , MZCONFIG_CMDLINE_ARGS , MZCONFIG_LOCALE , MZCONFIG_SECURITY_GUARD , MZCONFIG_PORT_COUNT_LINES , MZCONFIG_SCHEDULER_RANDOM_STATE , MZCONFIG_THREAD_SET , MZCONFIG_THREAD_INIT_STACK_SIZE , MZCONFIG_SUBPROC_CUSTODIAN_MODE , MZCONFIG_SUBPROC_GROUP_ENABLED , MZCONFIG_LOAD_DELAY_ENABLED , MZCONFIG_DELAY_LOAD_INFO , MZCONFIG_EXPAND_OBSERVE , MZCONFIG_LOGGER , __MZCONFIG_BUILTIN_COUNT__ }
; 
typedef struct Scheme_Input_Port Scheme_Input_Port ; 
typedef struct Scheme_Output_Port Scheme_Output_Port ; 
typedef struct Scheme_Port Scheme_Port ; 
typedef intptr_t (* Scheme_Get_String_Fun ) (Scheme_Input_Port * port , char * buffer , intptr_t offset , intptr_t size , int nonblock , Scheme_Object * unless ) ; 
typedef intptr_t (* Scheme_Peek_String_Fun ) (Scheme_Input_Port * port , char * buffer , intptr_t offset , intptr_t size , Scheme_Object * skip , int nonblock , Scheme_Object * unless ) ; 
typedef Scheme_Object * (* Scheme_Progress_Evt_Fun ) (Scheme_Input_Port * port ) ; 
typedef int (* Scheme_Peeked_Read_Fun ) (Scheme_Input_Port * port , intptr_t amount , Scheme_Object * unless_evt , Scheme_Object * target_ch ) ; 
typedef int (* Scheme_In_Ready_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Close_Input_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Input_Fun ) (Scheme_Input_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Location_Fun ) (Scheme_Port * ) ; 
typedef void (* Scheme_Count_Lines_Fun ) (Scheme_Port * ) ; 
typedef int (* Scheme_Buffer_Mode_Fun ) (Scheme_Port * , int m ) ; 
typedef Scheme_Object * (* Scheme_Write_String_Evt_Fun ) (Scheme_Output_Port * , const char * str , intptr_t offset , intptr_t size ) ; 
typedef intptr_t (* Scheme_Write_String_Fun ) (Scheme_Output_Port * , const char * str , intptr_t offset , intptr_t size , int rarely_block , int enable_break ) ; 
typedef int (* Scheme_Out_Ready_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Close_Output_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Output_Fun ) (Scheme_Output_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Write_Special_Evt_Fun ) (Scheme_Output_Port * , Scheme_Object * ) ; 
typedef int (* Scheme_Write_Special_Fun ) (Scheme_Output_Port * , Scheme_Object * , int nonblock ) ; 
struct Scheme_Port {
  Scheme_Object so ; 
  char count_lines , was_cr ; 
  intptr_t position , readpos , lineNumber , charsSinceNewline ; 
  intptr_t column , oldColumn ; 
  int utf8state ; 
  Scheme_Location_Fun location_fun ; 
  Scheme_Count_Lines_Fun count_lines_fun ; 
  Scheme_Buffer_Mode_Fun buffer_mode_fun ; 
}
; 
struct Scheme_Input_Port {
  struct Scheme_Port p ; 
  char closed , pending_eof ; 
  Scheme_Object * sub_type ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Get_String_Fun get_string_fun ; 
  Scheme_Peek_String_Fun peek_string_fun ; 
  Scheme_Progress_Evt_Fun progress_evt_fun ; 
  Scheme_Peeked_Read_Fun peeked_read_fun ; 
  Scheme_In_Ready_Fun byte_ready_fun ; 
  Scheme_Close_Input_Fun close_fun ; 
  Scheme_Need_Wakeup_Input_Fun need_wakeup_fun ; 
  Scheme_Object * read_handler ; 
  Scheme_Object * name ; 
  Scheme_Object * peeked_read , * peeked_write ; 
  Scheme_Object * progress_evt , * input_lock , * input_giveup , * input_extras , * input_extras_ready ; 
  unsigned char ungotten [24 ] ; 
  int ungotten_count ; 
  Scheme_Object * special , * ungotten_special ; 
  Scheme_Object * unless , * unless_cache ; 
  struct Scheme_Output_Port * output_half ; 
}
; 
struct Scheme_Output_Port {
  struct Scheme_Port p ; 
  short closed ; 
  Scheme_Object * sub_type ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Write_String_Evt_Fun write_string_evt_fun ; 
  Scheme_Write_String_Fun write_string_fun ; 
  Scheme_Close_Output_Fun close_fun ; 
  Scheme_Out_Ready_Fun ready_fun ; 
  Scheme_Need_Wakeup_Output_Fun need_wakeup_fun ; 
  Scheme_Write_Special_Evt_Fun write_special_evt_fun ; 
  Scheme_Write_Special_Fun write_special_fun ; 
  intptr_t pos ; 
  Scheme_Object * name ; 
  Scheme_Object * display_handler ; 
  Scheme_Object * write_handler ; 
  Scheme_Object * print_handler ; 
  struct Scheme_Input_Port * input_half ; 
}
; 
enum {
  MZEXN , MZEXN_FAIL , MZEXN_FAIL_CONTRACT , MZEXN_FAIL_CONTRACT_ARITY , MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , MZEXN_FAIL_CONTRACT_NON_FIXNUM_RESULT , MZEXN_FAIL_CONTRACT_CONTINUATION , MZEXN_FAIL_CONTRACT_VARIABLE , MZEXN_FAIL_SYNTAX , MZEXN_FAIL_READ , MZEXN_FAIL_READ_EOF , MZEXN_FAIL_READ_NON_CHAR , MZEXN_FAIL_FILESYSTEM , MZEXN_FAIL_FILESYSTEM_EXISTS , MZEXN_FAIL_FILESYSTEM_VERSION , MZEXN_FAIL_NETWORK , MZEXN_FAIL_OUT_OF_MEMORY , MZEXN_FAIL_UNSUPPORTED , MZEXN_FAIL_USER , MZEXN_BREAK , MZEXN_OTHER }
; 
typedef struct Scheme_Logger Scheme_Logger ; 
typedef void (* Scheme_Invoke_Proc ) (Scheme_Env * env , intptr_t phase_shift , Scheme_Object * self_modidx , void * data ) ; 
struct NewGC ; 
typedef int (* Size_Proc ) (void * obj ) ; 
typedef int (* Size2_Proc ) (void * obj , struct NewGC * ) ; 
typedef int (* Mark_Proc ) (void * obj ) ; 
typedef int (* Mark2_Proc ) (void * obj , struct NewGC * ) ; 
typedef int (* Fixup_Proc ) (void * obj ) ; 
typedef int (* Fixup2_Proc ) (void * obj , struct NewGC * ) ; 
typedef void (* GC_collect_start_callback_Proc ) (void ) ; 
typedef void (* GC_collect_end_callback_Proc ) (void ) ; 
typedef void (* GC_collect_inform_callback_Proc ) (int master_gc , int major_gc , intptr_t pre_used , intptr_t post_used , intptr_t pre_admin , intptr_t post_admin ) ; 
typedef uintptr_t (* GC_get_thread_stack_base_Proc ) (void ) ; 
typedef void (* GC_Post_Propagate_Hook_Proc ) (struct NewGC * ) ; 
typedef void (* Scheme_On_Atomic_Timeout_Proc ) (int must_give_up ) ; 
extern void scheme_signal_error (const char * msg , ... ) ; 
extern Scheme_Object scheme_eof [1 ] ; 
extern Scheme_Object scheme_null [1 ] ; 
extern Scheme_Object scheme_true [1 ] ; 
extern Scheme_Object scheme_false [1 ] ; 
extern Scheme_Object scheme_void [1 ] ; 
extern Scheme_Object scheme_undefined [1 ] ; 
extern unsigned short * scheme_uchar_table [] ; 
extern unsigned char * scheme_uchar_cases_table [] ; 
extern unsigned char * scheme_uchar_cats_table [] ; 
extern int scheme_uchar_ups [] ; 
extern int scheme_uchar_downs [] ; 
extern int scheme_uchar_titles [] ; 
extern int scheme_uchar_folds [] ; 
extern unsigned char scheme_uchar_combining_classes [] ; 
extern Scheme_Object * scheme_make_prim_w_arity (Scheme_Prim * prim , const char * name , mzshort mina , mzshort maxa ) ; 
extern Scheme_Object * scheme_make_pair (Scheme_Object * car , Scheme_Object * cdr ) ; 
extern Scheme_Object * scheme_make_utf8_string (const char * chars ) ; 
extern Scheme_Object * scheme_char_string_to_byte_string (Scheme_Object * s ) ; 
extern Scheme_Object * scheme_make_integer_value (intptr_t i ) ; 
__xform_nongcing__ extern int scheme_get_int_val (Scheme_Object * o , intptr_t * v ) ; 
__xform_nongcing__ extern double scheme_real_to_double (Scheme_Object * r ) ; 
extern void scheme_add_global (const char * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
extern int scheme_list_length (Scheme_Object * list ) ; 
extern Scheme_Object * scheme_car (Scheme_Object * pair ) ; 
extern Scheme_Object * scheme_initialize (Scheme_Env * global_env ) ; 
extern Scheme_Object * scheme_reload (Scheme_Env * global_env ) ; 
extern Scheme_Object * scheme_module_name (void ) ; 
GDBusProxy * Proxyobj = ((void * ) 0 ) ; 
char * tostring (Scheme_Object * obj ) ; 
void rdbus_init (void ) {
  /* No conversion */
  g_type_init () ; 
}
int rdbus_get_object (const gchar * name , const gchar * object_path , const gchar * interface_name ) {
  const GDBusProxy * objects [128 ] ; 
  const int latest_object = 0 ; 
  GError * error ; 
  DECL_RET_SAVE (int ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(error, 0), PUSHARRAY(objects, 128, 1)));
# define XfOrM2_COUNT (4)
# define SETUP_XfOrM2(x) SETUP(XfOrM2_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  NULL_OUT_ARRAY (objects ) ; 
  error = NULLED_OUT ; 
  error = ((void * ) 0 ) ; 
  Proxyobj = FUNCCALL(SETUP_XfOrM2(_), g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SESSION , G_DBUS_PROXY_FLAGS_NONE , ((void * ) 0 ) , name , object_path , interface_name , ((void * ) 0 ) , & error ) ); 
  if ((Proxyobj == ((void * ) 0 ) ) || (error != ((void * ) 0 ) ) ) {
    RET_VALUE_START (- 1 ) RET_VALUE_END ; 
  }
  RET_VALUE_START (0 ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
GVariant * scheme_obj_to_gvariant (Scheme_Object * list ) {
  GVariant * rvalue ; 
  Scheme_Object * firstelement ; 
  int length ; 
  long i ; 
  char * rstring ; 
  double rdouble ; 
  DECL_RET_SAVE (GVariant * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(rstring, 0), PUSH(firstelement, 1), PUSH(rvalue, 2), PUSH(list, 3)));
# define XfOrM4_COUNT (4)
# define SETUP_XfOrM4(x) SETUP(XfOrM4_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  rvalue = NULLED_OUT ; 
  firstelement = NULLED_OUT ; 
  rstring = NULLED_OUT ; 
  rvalue = ((void * ) 0 ) ; 
  length = FUNCCALL(SETUP_XfOrM4(_), scheme_list_length (list ) ); 
  if (length == 0 ) {
    RET_VALUE_START (rvalue ) RET_VALUE_END ; 
  }
  else if (length == 1 ) {
#   define XfOrM5_COUNT (0+XfOrM4_COUNT)
#   define SETUP_XfOrM5(x) SETUP_XfOrM4(x)
    firstelement = FUNCCALL(SETUP_XfOrM5(_), scheme_car (list ) ); 
    if (((((intptr_t ) (firstelement ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (firstelement ) ) -> type ) == scheme_integer_type ) {
#     define XfOrM8_COUNT (0+XfOrM5_COUNT)
#     define SETUP_XfOrM8(x) SETUP_XfOrM5(x)
      (scheme_get_int_val (list , & i ) ) ; 
      rvalue = FUNCCALL(SETUP_XfOrM8(_), g_variant_new_int32 (i ) ); 
      RET_VALUE_START (rvalue ) RET_VALUE_END ; 
    }
    else if (((((intptr_t ) (firstelement ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (firstelement ) ) -> type ) == scheme_char_type ) {
#     define XfOrM7_COUNT (0+XfOrM5_COUNT)
#     define SETUP_XfOrM7(x) SETUP_XfOrM5(x)
      rstring = (((Scheme_Simple_Object * ) (list ) ) -> u . byte_str_val . string_val ) ; 
      rvalue = FUNCCALL(SETUP_XfOrM7(_), g_variant_new_string (rstring ) ); 
      RET_VALUE_START (rvalue ) RET_VALUE_END ; 
    }
    else if (((((intptr_t ) (firstelement ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (firstelement ) ) -> type ) == scheme_double_type ) {
#     define XfOrM6_COUNT (0+XfOrM5_COUNT)
#     define SETUP_XfOrM6(x) SETUP_XfOrM5(x)
      rdouble = (scheme_real_to_double (list ) ) ; 
      rvalue = FUNCCALL(SETUP_XfOrM6(_), g_variant_new_double (rdouble ) ); 
      RET_VALUE_START (rvalue ) RET_VALUE_END ; 
    }
  }
  RET_VALUE_START (rvalue ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * gvariant_to_schemeobj (GVariant * ivalue ) {
  Scheme_Object * fvalue = ((void * ) 0 ) ; 
  const gchar * fstring ; 
  gsize length ; 
  gsize * plength ; 
  gint32 r1 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(plength, 0), PUSH(fstring, 1), PUSH(fvalue, 2), PUSH(ivalue, 3)));
# define XfOrM10_COUNT (4)
# define SETUP_XfOrM10(x) SETUP(XfOrM10_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  fstring = NULLED_OUT ; 
  plength = NULLED_OUT ; 
  length = FUNCCALL(SETUP_XfOrM10(_), g_variant_get_size (ivalue ) ); 
  plength = & length ; 
  if (FUNCCALL(SETUP_XfOrM10(_), g_variant_is_of_type (ivalue , ((const GVariantType * ) "i" ) ) )) {
#   define XfOrM12_COUNT (0+XfOrM10_COUNT)
#   define SETUP_XfOrM12(x) SETUP_XfOrM10(x)
    r1 = FUNCCALL(SETUP_XfOrM12(_), g_variant_get_int32 (ivalue ) ); 
    fvalue = FUNCCALL(SETUP_XfOrM12(_), scheme_make_integer_value (r1 ) ); 
    RET_VALUE_START (fvalue ) RET_VALUE_END ; 
  }
  else if (FUNCCALL(SETUP_XfOrM10(_), g_variant_is_of_type (ivalue , ((const GVariantType * ) "s" ) ) )) {
#   define XfOrM11_COUNT (0+XfOrM10_COUNT)
#   define SETUP_XfOrM11(x) SETUP_XfOrM10(x)
    fstring = FUNCCALL(SETUP_XfOrM11(_), g_variant_get_string (ivalue , plength ) ); 
    fvalue = FUNCCALL(SETUP_XfOrM11(_), scheme_make_utf8_string (fstring ) ); 
    RET_VALUE_START (fvalue ) RET_VALUE_END ; 
  }
  RET_VALUE_START (fvalue ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * make_object_list (int n , Scheme_Object * values [] ) {
  Scheme_Object * result ; 
  int i ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(values, 0), PUSH(result, 1)));
# define XfOrM13_COUNT (2)
# define SETUP_XfOrM13(x) SETUP(XfOrM13_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  result = NULLED_OUT ; 
  result = scheme_null ; 
  for (i = n - 1 ; i >= 0 ; i -- ) {
#   define XfOrM15_COUNT (0+XfOrM13_COUNT)
#   define SETUP_XfOrM15(x) SETUP_XfOrM13(x)
    result = FUNCCALL(SETUP_XfOrM15(_), scheme_make_pair (values [i ] , result ) ); 
  }
  RET_VALUE_START (result ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * rdbus_call_method (int i , Scheme_Object * proc , Scheme_Object * list ) {
  GVariant * frvalue ; 
  GVariant * ivalue ; 
  const char * methodname ; 
  GError * error ; 
  Scheme_Object * fobject ; 
  GDBusProxy * proxy ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(7);
  BLOCK_SETUP_TOP((PUSH(ivalue, 0), PUSH(error, 1), PUSH(methodname, 2), PUSH(frvalue, 3), PUSH(fobject, 4), PUSH(proxy, 5), PUSH(proc, 6)));
# define XfOrM16_COUNT (7)
# define SETUP_XfOrM16(x) SETUP(XfOrM16_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  frvalue = NULLED_OUT ; 
  ivalue = NULLED_OUT ; 
  methodname = NULLED_OUT ; 
  error = NULLED_OUT ; 
  fobject = NULLED_OUT ; 
  proxy = NULLED_OUT ; 
  if (i == 0 ) {
#   define XfOrM18_COUNT (0+XfOrM16_COUNT)
#   define SETUP_XfOrM18(x) SETUP_XfOrM16(x)
    proxy = Proxyobj ; 
    ivalue = FUNCCALL(SETUP_XfOrM18(_), scheme_obj_to_gvariant (list ) ); 
    methodname = FUNCCALL_AGAIN(tostring (proc ) ); 
    FUNCCALL_AGAIN(fprintf (stderr , "Calling %s\n" , methodname ) ); 
    frvalue = FUNCCALL_AGAIN(g_dbus_proxy_call_sync (proxy , methodname , ivalue , 0 , - 1 , ((void * ) 0 ) , & error ) ); 
    fobject = FUNCCALL_AGAIN(gvariant_to_schemeobj (frvalue ) ); 
    RET_VALUE_START (fobject ) RET_VALUE_END ; 
  }
  else {
#   define XfOrM17_COUNT (0+XfOrM16_COUNT)
#   define SETUP_XfOrM17(x) SETUP_XfOrM16(x)
    RET_VALUE_START (FUNCCALL(SETUP_XfOrM17(_), scheme_make_utf8_string ("There is sth wrong with the Proxy Object" ) )) RET_VALUE_END ; 
  }
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * pardbus_call_method (int argc , Scheme_Object * argv [] ) {
  Scheme_Object * __funcarg66 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(1);
  BLOCK_SETUP_TOP((PUSH(argv, 0)));
# define XfOrM19_COUNT (1)
# define SETUP_XfOrM19(x) SETUP(XfOrM19_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  if (argc < 2 ) {
#   define XfOrM20_COUNT (0+XfOrM19_COUNT)
#   define SETUP_XfOrM20(x) SETUP_XfOrM19(x)
    FUNCCALL_EMPTY(scheme_signal_error ("Call method needs at least two parameters." ) ); 
    RET_VALUE_START (((void * ) 0 ) ) RET_VALUE_END ; 
  }
  RET_VALUE_START ((__funcarg66 = FUNCCALL(SETUP_XfOrM19(_), make_object_list (argc - 2 , argv + 2 ) ), FUNCCALL_EMPTY(rdbus_call_method ((((intptr_t ) (argv [0 ] ) ) >> 1 ) , argv [1 ] , __funcarg66 ) )) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
int stringp (Scheme_Object * obj ) {
  /* No conversion */
  return ((Scheme_Type ) (((((intptr_t ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) || ((Scheme_Type ) (((((intptr_t ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) ; 
}
char * tostring (Scheme_Object * obj ) {
  /* No conversion */
  if (((Scheme_Type ) (((((intptr_t ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_byte_string_type ) ) )
    return (((Scheme_Simple_Object * ) (obj ) ) -> u . byte_str_val . string_val ) ; 
  else if (((Scheme_Type ) (((((intptr_t ) (obj ) ) & 0x1 ) ? (Scheme_Type ) scheme_integer_type : ((Scheme_Object * ) (obj ) ) -> type ) ) == (Scheme_Type ) (scheme_char_string_type ) ) )
    return (((Scheme_Simple_Object * ) (scheme_char_string_to_byte_string (obj ) ) ) -> u . byte_str_val . string_val ) ; 
  else return ((void * ) 0 ) ; 
}
Scheme_Object * pardbus_get_object (int argc , Scheme_Object * argv [] ) {
  char * service ; 
  char * path ; 
  char * interface ; 
  int object ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(interface, 0), PUSH(service, 1), PUSH(argv, 2), PUSH(path, 3)));
# define XfOrM23_COUNT (4)
# define SETUP_XfOrM23(x) SETUP(XfOrM23_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  service = NULLED_OUT ; 
  path = NULLED_OUT ; 
  interface = NULLED_OUT ; 
  if (argc != 3 ) {
#   define XfOrM26_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM26(x) SETUP_XfOrM23(x)
    FUNCCALL_EMPTY(scheme_signal_error ("rdbus-get-object: Requires exactly three parameters.\n" ) ); 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  if ((! FUNCCALL(SETUP_XfOrM23(_), stringp (argv [0 ] ) )) || (! FUNCCALL(SETUP_XfOrM23(_), stringp (argv [1 ] ) )) || (! FUNCCALL(SETUP_XfOrM23(_), stringp (argv [2 ] ) )) ) {
#   define XfOrM25_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM25(x) SETUP_XfOrM23(x)
    FUNCCALL_EMPTY(scheme_signal_error ("rdbus-get-object: All three parameters must be strings" ) ); 
  }
  service = FUNCCALL(SETUP_XfOrM23(_), tostring (argv [0 ] ) ); 
  path = FUNCCALL(SETUP_XfOrM23(_), tostring (argv [1 ] ) ); 
  interface = FUNCCALL_AGAIN(tostring (argv [2 ] ) ); 
  object = FUNCCALL_EMPTY(rdbus_get_object (service , path , interface ) ); 
  if (object < 0 ) {
#   define XfOrM24_COUNT (0+XfOrM23_COUNT)
#   define SETUP_XfOrM24(x) SETUP_XfOrM23(x)
    FUNCCALL_EMPTY(scheme_signal_error ("Could not create bus object." ) ); 
    RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
  }
  RET_VALUE_START (((Scheme_Object * ) (void * ) (intptr_t ) ((((intptr_t ) (object ) ) << 1 ) | 0x1 ) ) ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * pardbus_init (int argc , Scheme_Object * argv [] ) {
  /* No conversion */
  rdbus_init () ; 
  return scheme_void ; 
}
Scheme_Object * scheme_reload (Scheme_Env * env ) {
  Scheme_Env * menv ; 
  Scheme_Object * proc1 ; 
  Scheme_Object * proc2 ; 
  Scheme_Object * proc3 ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(4);
  BLOCK_SETUP_TOP((PUSH(proc3, 0), PUSH(proc2, 1), PUSH(proc1, 2), PUSH(env, 3)));
# define XfOrM28_COUNT (4)
# define SETUP_XfOrM28(x) SETUP(XfOrM28_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  menv = NULLED_OUT ; 
  proc1 = NULLED_OUT ; 
  proc2 = NULLED_OUT ; 
  proc3 = NULLED_OUT ; 
  proc1 = FUNCCALL(SETUP_XfOrM28(_), scheme_make_prim_w_arity (pardbus_get_object , "rdbus-get-object" , 3 , - 1 ) ); 
  proc2 = FUNCCALL_AGAIN(scheme_make_prim_w_arity (pardbus_call_method , "rdbus-call-method" , 3 , - 1 ) ); 
  proc3 = FUNCCALL_AGAIN(scheme_make_prim_w_arity (pardbus_init , "rdbus_init" , 0 , 0 ) ); 
  FUNCCALL_AGAIN(scheme_add_global ("rdbus-get-object" , proc1 , env ) ); 
  FUNCCALL_AGAIN(scheme_add_global ("rdbus-call-method" , proc2 , env ) ); 
  FUNCCALL_EMPTY(scheme_add_global ("rdbus_init" , proc3 , env ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_initialize (Scheme_Env * env ) {
  /* No conversion */
  return scheme_reload (env ) ; 
}
Scheme_Object * scheme_module_name () {
  /* No conversion */
  return scheme_intern_symbol ("idmodule" ) ; 
}
