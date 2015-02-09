#!/bin/sh

openssl rand -out 27.txt -base64 $((2**27 * 3/4))
