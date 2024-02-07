# Level 14

Well, last level, it's time to be serious and straightforward.

0. flag14 uid is:

```sh
$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```

1. we upload getflag itself

```sh
$ scp -P 4342 level14@localhost:/bin/getflag .
```

2. revert on dogbolt.com

```c
if (eax_9 != 0xbc6)         //0xbc6 == 3014
{
    goto label_8048e29;
}
fputs(ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrv…"), stdout);
```

idee: set register eax at the right value using gdb but :

```c
 if (ptrace(PTRACE_TRACEME, 0, 1, 0, 0) < 0)
    {
        puts("You should not reverse this");
        eax_3 = 1;
    }
```

getflag is protected against such kind of trick.
(gdb use ptrace to track the program to debug. gdb fork, the child process use ptrace(PTRACE_TRACEME...) to be traced by the parent process (gdb), then run the program to debug. When getflag run (again) ptrace(PTRACE_TRACEME...), the function return an error value as it's already traced.)

idee: set ptrace return value at 0 using gdb ;)

3. lets do the hack
   [Bypass ptrace](https://gist.github.com/poxyran/71a993d292eee10e95b4ff87066ea8f2)

```gdb
catch syscall ptrace
commands 1
set ($eax) = 0
continue
end

b *0x8048b02 (break one step after getuid call)
run
p $eax (= 2014) (user level14)
set $eax=3014 (set to flag14)
continue
```
