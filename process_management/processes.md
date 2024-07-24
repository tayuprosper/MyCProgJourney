# Process
process is running instance of a program
every process has a pid gotten by pid_t type and getpid()
pid_t is a interger that uniquely identify a running process
"Elevator" algorithm is used to cycle and reuse pid starting from low numbers
If all pid are used then a call to fork() will fail with EAGAIN
maximum pid in linux is 32767 and limit is adjustable at /proc/sys/keenel/pid_max ( up to kernel's PID_MAX_LIMIT constant , typicaly 4*1024*1024)
every process has a parent process( the process that fork() that process) thus the system procesess forms a tree
At root is ninit, PID 1, the ancestor of all processes
'Orphaned' processes are 'adopted' by init
getppid() reuturns PID of caller's parent process (PPID)

# Process memory layout
Virtual memory of a process is divided into segments
# Text: machine-language instructions
- marked read-only to prevent self-modification
- multiple processes can share same code in memory
# Initialised data:
- Global and static variables that are explicitly initialised
- values read from program file when process created
# Uninitailised data
- Global and static variables that are not explicitly initialised (initialised to 0 when process is started )
# Stack:
- storage for function local variables and call linkage info (saved SP and PC )
# Heap:
- an area from which memory can dynamically allocated and deallocated

# CDL arguments
first two arguments of main()
conventionally named argc (integer holding the number of arguments with the program itself beign the first. so argc is always grater than or equal to 1 ) and argv (char* agrv[], array of pointers to arguments (string)).

# Environment list (environ)

Each process has a list of environment variables
- String of form name=value;
- New process inherits copy of parent's environent
    - simple (one-way) interprocess communication
- comonly used to control behavior of programs

E.g - HOME: users home directory (initialised at login )
    - PATH: list of directories to search for executable programs
    - EDITOR: user's preferred editor
getenv("NAME") return char* envon with name "NAME"
env can be modified or created using either putenv("NAME=value"); or setenv("NAME", "value", overwrite) // overwrite flag if env already exits
removing env unsetenv("NAME");
proc/PID/environ can be used (with suitable
permissions) to view environment of another process


# Signals
signal == notification to a process that an event has occured
or software interupt
signals are assynchronous i.e receiver does not know when a signal will occur
- there are 64 signl on linux
- each signal has a unique interger value
- signals are defined inside <signal.h> file named SIGxxx
numbered starting from 1 e.g signal with number 2 is SIGINT ("terminal interupt")
- there are two types of signals
1. standard signals (1 to 31)
    - mostly used for kernel-defined purposes
2. realtime signals (32 to 64)
    - exist for user-defined purposes

signals are sent to a process by
- the kernel (in the common case)
- by another process (process with approprait permissions)
    - e.g kill(pid,sig) and realted APIs
common signals generated by the the kernel
1. SIGSEGV reading nonexisting memory
2. SIGINT terminal interupt was typed (control+C);
3. SIGCHLD child process completed
4. SIGXCPU cpu usage time exceded ( time based process scheduling os)

