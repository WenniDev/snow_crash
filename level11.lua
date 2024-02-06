#!/usr/bin/env lua
pass = arg[1]

prog = io.popen("echo "..pass, "r")
data = prog:read("*all")
prog:close()
print("trying " .. data)