# Level 00

Nothing intersting in the current directory.

```sh
$ ls -al
total 12
dr-xr-x---+ 1 level00 level00  100 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-xr-x---+ 1 level00 level00  220 Apr  3  2012 .bash_logout
-r-xr-x---+ 1 level00 level00 3518 Aug 30  2015 .bashrc
-r-xr-x---+ 1 level00 level00  675 Apr  3  2012 .profile
```

Let's look for something containing "flag00".

```sh
$ find / -type f -exec grep -l "flag00" {} \; 2>/dev/null
/etc/group
/etc/passwd
/proc/26394/task/26394/cmdline
/proc/26394/cmdline
/rofs/etc/group
/rofs/etc/passwd
```

Nothing intersting. Let's look for files with `"flag00"` in their name.

```sh
$ find / -name *flag00* 2> /dev/null
$
```

Nothing either. Now let's look for files owned by the user "flag00".

```sh
$ find / -user flag00 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john

$ cat /usr/sbin/john
cdiiddwpgswtgt
```

And it's a match!

The content of the file dosen't work as a key, maybe it's encrypted?

We can use [The Cipher Identifier](https://www.dcode.fr/cipher-identifier) and see that's a ROT Cipher of +15 and get the final password: `nottoohardhere`.

Now we can log as flag00 with `nottoohardhere`.
